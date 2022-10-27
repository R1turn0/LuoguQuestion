#define _CRT_SECURE_NO_WARNINGS //����sdl���

#include <windows.h>
#include "strsafe.h"
#include "sysmets.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("MyWindows");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadCursor(NULL, IDI_QUESTION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("���������Ҫ��windows nt������"), szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName,
        TEXT("������"),
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    TEXTMETRIC tm;
    TCHAR szBuffer[10];
    static int cxChar, cxCaps, cyChar;
    static int cxClient, cyClient;
    size_t iTarget;
    int i;

    switch (message)
    {
    case WM_CREATE:
        hdc = GetDC(hwnd);

        GetTextMetrics(hdc, &tm);
        cxChar = tm.tmAveCharWidth;
        cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;
        cyChar = tm.tmHeight + tm.tmExternalLeading;

        ReleaseDC(hwnd, hdc);
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        for (i = 0; i < NUMLINES; i++)
        {
            StringCchLength(sysmetrics[i].szLabel, 1024, &iTarget);
            TextOut(hdc, 0, cyChar * i, sysmetrics[i].szLabel, iTarget);

            StringCchLength(sysmetrics[i].szDesc, 1024, &iTarget);
            TextOut(hdc, 22 * cxCaps, cyChar * i, sysmetrics[i].szDesc, iTarget);

            SetTextAlign(hdc, TA_RIGHT | TA_TOP);   // �����Ҷ���

            StringCchPrintf(szBuffer, 10, TEXT("%5d"), GetSystemMetrics(sysmetrics[i].iIndex));
            StringCchLength(szBuffer, 10, &iTarget);
            TextOut(hdc, 22 * cxCaps + 40 * cxChar, cyChar * i, szBuffer, iTarget);

            StringCchPrintf(szBuffer, 10, TEXT("%5d"), i + 1);
            TextOut(hdc, 22 * cxCaps + 40 * cxChar + 15 * cxChar, cyChar * i, szBuffer, iTarget);

            SetTextAlign(hdc, TA_LEFT | TA_TOP);    // ���������
        }
        EndPaint(hwnd, &ps);
        return 0;

    case WM_SIZE:
        cxClient = LOWORD(lParam);
        cyClient = HIWORD(lParam);

    case WM_VSCROLL:
        hdc = GetDC(hwnd);
        SetTextAlign(hdc, TA_TOP | TA_RIGHT);

        switch (LOWORD(wParam))
        {
        case SB_LINEUP:
            TextOut(hdc, cxClient - 10, 10, TEXT("���Ϲ���һ��..."), 9);
            break;
            
        case SB_LINEDOWN:
            TextOut(hdc, cxClient - 10, 10, TEXT("���¹���һ��..."), 9);
            break;

        case SB_PAGEUP:
            TextOut(hdc, cxClient - 10, 10, TEXT("���Ϲ���һҳ..."), 9);
            break;

        case SB_PAGEDOWN:
            TextOut(hdc, cxClient - 10, 10, TEXT("���¹���һҳ..."), 9);
            break;

        case SB_THUMBTRACK:
            TextOut(hdc, cxClient - 10, 10, TEXT("��ץ���Ҳ���..."), 9);
            break;
        }
        ReleaseDC(hwnd, hdc);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    }
    return DefWindowProc(hwnd, message, wParam, lParam);

}