#pragma once

int showBitMap(HWND hwnd, HANDLE hBit, int x, int y);
int ClientToBmp (HWND hWnd, CString filename, RECT r);


void MyLine(CDC* dc, int x1, int x2, int y1, int y2, COLORREF color);
void LineX(CDC * dc, int x1, int y1, int dx, int dy, int dir, COLORREF color);
void LineY(CDC * dc, int x1, int y1, int dx, int dy, int dir, COLORREF color);


void MyCircle(CDC& dc, CPoint p1, int r, COLORREF color);
void CirclePoint(CDC &dc, int x, int y, CPoint &p, COLORREF color);
