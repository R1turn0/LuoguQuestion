#include <windows.h>
#include <strsafe.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("MyWindows");
    HWND hwnd;  // 窗口句柄
    MSG msg;
    WNDCLASS wndclass = { 0 };

    wndclass.style = CS_HREDRAW | CS_VREDRAW;                       // 调整宽度高度重新绘制窗口
    wndclass.lpfnWndProc = WndProc;                                 // 指定窗口过程（必须是回调函数
    wndclass.cbClsExtra = 0;                                        // 额外空间，一般为0
    wndclass.cbWndExtra = 0;                                        // 额外空间，一般为0
    wndclass.hInstance = hInstance;                                 // 应用程序的实例句柄
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);               // 所有基于该窗口类的窗口设定的图标
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 // 所有基于该窗口类的窗口设定的鼠标指针
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   // 背景
    wndclass.lpszMenuName = NULL;                                   // 菜单
    wndclass.lpszClassName = szAppName;                             // 窗口类名字

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("这个程序需要在Windows NT上运行！"), szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(
        szAppName,
        TEXT("Windows Test!"),
        WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

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
    HDC hdc;        // 设备环境句柄
    PAINTSTRUCT ps;
    RECT rect;
    TCHAR szBuffer[128];
    int i = 0;
    size_t iTarget;
    TEXTMETRIC tm;
    static int cxChar, cyChar;      // 获取文本宽高
    static int cxClient, cyClient;  // 获取

    switch (message)
    {
    case WM_CREATE: //？非队列消息
        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        cxChar = tm.tmAveCharWidth;                     // 获取文本字符宽
        cyChar = tm.tmHeight + tm.tmExternalLeading;    // 获取文本行高
        ReleaseDC(hwnd, hdc);

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);    // 绘画的初始化
        //GetClientRect(hwnd, &rect);
        //DrawText(hdc, TEXT("This is my first Windows! YES!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);   // 显示在一行内，垂直居中，水平居中
        
        //TextOut(hdc, 400, 300, TEXT("勾股定理"),4); // 字符串对其模式取决于当前的文本对其模式，通过GetTextAlign可获取，通过SetTextAlign可修改
        //EndPaint(hwnd, &ps);

        //for (i = 0; i < 10; i++)
        //{
        //    //wsprintf(szBuffer, TEXT("%2d: %s"), i + 1, TEXT("A String!"));  // 不安全（缓冲区溢出攻击
        //    StringCchPrintf(szBuffer, 128, TEXT("%2d: %s"), i + 1, TEXT("A String!"));
        //    StringCchLength(szBuffer, sizeof(szBuffer), &iTarget);
        //    TextOut(hdc, cxChar, i * cyChar, szBuffer, iTarget);
        //}

        GetClientRect(hwnd, &rect);
        cxClient = GetSystemMetrics(SM_CXSCREEN);       // GetSystemMetrics函数返回Windows中各种图形项（图标、鼠标指针、标题栏和滚动条等）的尺寸信息
        cyClient = GetSystemMetrics(SM_CYSCREEN);
        StringCchPrintf(szBuffer, 128, TEXT("当前显示器的分辨率是:%d * %d px"), cxClient, cyClient);
        DrawText(hdc, szBuffer, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);   // 显示在一行内，垂直居中，水平居中

        return 0;

    //case WM_LBUTTONDOWN:    // WM_LBUTTONUP
    //    MessageBox(hwnd, TEXT("客户区"), TEXT("这是哪？"), MB_OK);
    //    return 0;
    
    //case WM_NCLBUTTONDOWN:    // WM_NCLBUTTONUP
    //    MessageBox(hwnd, TEXT("非客户区"), TEXT("这是哪？"), MB_OK);
    //    return 0;

    case WM_CLOSE:      // 发送为窗口或应用程序应终止的信号
        if (MessageBox(hwnd, TEXT("是否退出"), TEXT("退出"), MB_YESNO) == IDYES)
            DestroyWindow(hwnd);
        else
            return 0;

    case WM_DESTROY:    // 当窗口被销毁时
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}
