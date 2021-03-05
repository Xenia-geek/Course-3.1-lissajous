
#include "stdafx.h"
#include "2.h"
#include "ChildView.h"
#include "myImage.h"
#include "math.h"

int showBitMap(HWND hwnd, HANDLE hBit, int x, int y)
 {
  BITMAP BitMap;
  GetObject(hBit, sizeof(BITMAP), &BitMap);

  //размеры для окон
  int height = BitMap.bmHeight;
  int width = BitMap.bmWidth;
  
  //получаем контекст изображения
  HDC hdc = GetDC(hwnd);
  //создаём контекст памяти
  HDC hdcMem = CreateCompatibleDC(hdc);
  //в данный контекст памяти заносим дескриптор битовой картыы
  HBITMAP oldBitMap = (HBITMAP)SelectObject(hdcMem, hBit);

  BitBlt(hdc, x, y, width, height, hdcMem, 0, 0, SRCCOPY);

  SelectObject(hdcMem, oldBitMap);


  ReleaseDC(hwnd, hdc);
  DeleteDC(hdcMem);
  return 0;
}
int ClientToBmp (HWND hWnd, CString filename, RECT r)
{
    HANDLE fh = CreateFile (filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if (fh == INVALID_HANDLE_VALUE)
        return 2;
    BITMAPINFOHEADER bi;
	//заполняем заголовок нулями
        ZeroMemory (&bi, sizeof (BITMAPINFOHEADER));

    bi.biSize = sizeof (BITMAPINFOHEADER);
    bi.biWidth = r.right - r.left; //
    bi.biHeight = r.bottom - r.top;//
    bi.biPlanes = 1;
    bi.biBitCount = 32; //16;
    bi.biSizeImage = (bi.biWidth * bi.biBitCount + 31)/32*4*bi.biHeight;
 
    BITMAPFILEHEADER bmfHdr;
        ZeroMemory (&bmfHdr, sizeof (BITMAPFILEHEADER));

    bmfHdr.bfType = ('M'<<8)|'B'; //заполняем дисковый заголовок
    bmfHdr.bfSize = bi.biSizeImage + sizeof (BITMAPFILEHEADER) + bi.biSize;//размер файла
    bmfHdr.bfReserved1 = bmfHdr.bfReserved2 = 0;
    bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)bi.biSize; //смещение до начала данных
 
    HDC hDC = GetDC (hWnd);
    HDC hDCMem = CreateCompatibleDC (hDC);
    HBITMAP hBitmap = CreateCompatibleBitmap (hDC, bi.biWidth, bi.biHeight);
    HBITMAP oldBitmap = (HBITMAP)SelectObject (hDCMem, hBitmap);
    BitBlt (hDCMem, 0,0, bi.biWidth, bi.biHeight, hDC, r.left, r.top, SRCCOPY);
    hBitmap = (HBITMAP)SelectObject (hDCMem, oldBitmap);
 
    HANDLE hDIB = GlobalAlloc (GHND /*GMEM_FIXED*/, bi.biSizeImage);

    char* lp = (char*)GlobalLock (hDIB);//выделяем место
    GetDIBits (hDC, hBitmap, 0, bi.biHeight, lp, (LPBITMAPINFO)&bi, DIB_RGB_COLORS);   
    DWORD dwWritten = sizeof (BITMAPFILEHEADER);
        WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
    dwWritten = sizeof (BITMAPINFOHEADER);
        WriteFile (fh, (LPSTR)&bi, sizeof (BITMAPINFOHEADER), &dwWritten, NULL);
    dwWritten = bi.biSizeImage;
        WriteFile (fh, lp, bi.biSizeImage, &dwWritten, NULL);
 
    GlobalUnlock(hDIB);   
    GlobalFree(hDIB);
 
    DeleteObject(hBitmap);
    lp = NULL;
    CloseHandle (fh);
    ReleaseDC (hWnd, hDCMem);
    ReleaseDC (hWnd, hDC);
    DeleteDC (hDCMem);
    DeleteDC (hDC);
    if (dwWritten == 2) return 2;
    return 0;
} 

void MyLine(CDC* dc, int x1, int x2, int y1, int y2, COLORREF color)
{
	//если рисуется линия снизу вверх 
	if(y1 > y2)		
	{		
		//меняем координаты местами
		int temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	int dx = x2 - x1;		
	int dy = y2 - y1;

	if(dx > 0)
	{
		if(dx > dy)//рисуем слева направо
		{
			LineX(dc, x1, y1, dx, dy, 1, color );
		}
		else
		{
			LineY(dc, x1, y1, dx, dy, 1, color);
		}
	}
	else //рисуем справа налево
	{
		dx = -dx;
		if(dx > dy)
		{
			LineX(dc, x1, y1, dx, dy,-1, color);
		}
		else
		{
			LineY(dc, x2, y2, dx, dy,-1, color);
		}
	}
}

void LineX(CDC * dc, int x1, int y1, int dx, int dy, int dir, COLORREF color) //рисуем по х
{
	int d1 = 2 * dy;
	int d2 = 2 * (dy - dx);
	int d = 2 * dy - dx;

	
	dc->SetPixel(x1,y1,color);

	while(dx--)
	{
		if(d < 0) 
			d += d1;
		else
		{
			y1++;
			d += d2;
		}
		x1 += dir;
		dc->SetPixel(x1,y1,color);

	}
}

void LineY(CDC * dc, int x1, int y1, int dx, int dy, int dir,COLORREF color) //рисуем по у
{
	int d1 = 2 * dx;
	int d2 = 2 * (dx - dy);
	int d = 2 * dx - dy;

	
	dc->SetPixel(x1,y1,color);

	while(dy--)
	{
		if(d < 0) 
			d += d1;
		else
		{
			x1++;
			d += d2;
		}
		y1 += dir;
		dc->SetPixel(x1,y1,color);

	}
}
		
void CirclePoints(CDC &dc, int x, int y, CPoint &p, COLORREF color)
{
	dc.SetPixel(p.x + x, p.y - y, color);
	dc.SetPixel(p.x + x, p.y + y, color);
	dc.SetPixel(p.x - x, p.y - y, color);
	dc.SetPixel(p.x - x, p.y + y, color);

	dc.SetPixel(p.x + y, p.y - x, color);
	dc.SetPixel(p.x + y, p.y + x, color);
	dc.SetPixel(p.x - y, p.y - x, color);
	dc.SetPixel(p.x - y, p.y + x, color);
}

void MyCircle(CDC& dc, CPoint p, int r, COLORREF color)
{
	double d = 5/4 - r;
	int p1 = 3, 
		q = p1 - 2 * r + 2;
	int x0 = 0, y0 = r;

	CirclePoints(dc, 0, r, p, color);
	while(x0 <= r/sqrt((double)2))
	{
		if(d < 0)
		{
			CirclePoints(dc, ++x0, y0, p, color);
			d = d + p1;
			p1 = p1 + 2;
			q = q + 2;			
		}
		else
		{
			CirclePoints(dc, ++x0, --y0, p, color);
			d = d + q;
			p1 = p1 + 2;
			q = q + 4;
		}
	}
}

