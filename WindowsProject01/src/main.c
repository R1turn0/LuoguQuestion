#include <windows.h>
#include <strsafe.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("MyWindows");
    HWND hwnd;  // ���ھ��
    MSG msg;
    WNDCLASS wndclass = { 0 };

    wndclass.style = CS_HREDRAW | CS_VREDRAW;                       // ������ȸ߶����»��ƴ���
    wndclass.lpfnWndProc = WndProc;                                 // ָ�����ڹ��̣������ǻص�����
    wndclass.cbClsExtra = 0;                                        // ����ռ䣬һ��Ϊ0
    wndclass.cbWndExtra = 0;                                        // ����ռ䣬һ��Ϊ0
    wndclass.hInstance = hInstance;                                 // Ӧ�ó����ʵ�����
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);               // ���л��ڸô�����Ĵ����趨��ͼ��
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 // ���л��ڸô�����Ĵ����趨�����ָ��
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   // ����
    wndclass.lpszMenuName = NULL;                                   // �˵�
    wndclass.lpszClassName = szAppName;                             // ����������

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("���������Ҫ��Windows NT�����У�"), szAppName, MB_ICONERROR);
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
    HDC hdc;        // �豸�������
    PAINTSTRUCT ps;
    RECT rect;
    TCHAR szBuffer[128];
    int i = 0;
    size_t iTarget;
    TEXTMETRIC tm;
    static int cxChar, cyChar;      // ��ȡ�ı����
    static int cxClient, cyClient;  // ��ȡ

    switch (message)
    {
    case WM_CREATE: //���Ƕ�����Ϣ
        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        cxChar = tm.tmAveCharWidth;                     // ��ȡ�ı��ַ���
        cyChar = tm.tmHeight + tm.tmExternalLeading;    // ��ȡ�ı��и�
        ReleaseDC(hwnd, hdc);

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);    // �滭�ĳ�ʼ��
        //GetClientRect(hwnd, &rect);
        //DrawText(hdc, TEXT("This is my first Windows! YES!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);   // ��ʾ��һ���ڣ���ֱ���У�ˮƽ����
        
        //TextOut(hdc, 400, 300, TEXT("���ɶ���"),4); // �ַ�������ģʽȡ���ڵ�ǰ���ı�����ģʽ��ͨ��GetTextAlign�ɻ�ȡ��ͨ��SetTextAlign���޸�
        //EndPaint(hwnd, &ps);

        //for (i = 0; i < 10; i++)
        //{
        //    //wsprintf(szBuffer, TEXT("%2d: %s"), i + 1, TEXT("A String!"));  // ����ȫ���������������
        //    StringCchPrintf(szBuffer, 128, TEXT("%2d: %s"), i + 1, TEXT("A String!"));
        //    StringCchLength(szBuffer, sizeof(szBuffer), &iTarget);
        //    TextOut(hdc, cxChar, i * cyChar, szBuffer, iTarget);
        //}

        GetClientRect(hwnd, &rect);
        cxClient = GetSystemMetrics(SM_CXSCREEN);       // GetSystemMetrics��������Windows�и���ͼ���ͼ�ꡢ���ָ�롢�������͹������ȣ��ĳߴ���Ϣ
        cyClient = GetSystemMetrics(SM_CYSCREEN);
        StringCchPrintf(szBuffer, 128, TEXT("��ǰ��ʾ���ķֱ�����:%d * %d px"), cxClient, cyClient);
        DrawText(hdc, szBuffer, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);   // ��ʾ��һ���ڣ���ֱ���У�ˮƽ����

        return 0;

    //case WM_LBUTTONDOWN:    // WM_LBUTTONUP
    //    MessageBox(hwnd, TEXT("�ͻ���"), TEXT("�����ģ�"), MB_OK);
    //    return 0;
    
    //case WM_NCLBUTTONDOWN:    // WM_NCLBUTTONUP
    //    MessageBox(hwnd, TEXT("�ǿͻ���"), TEXT("�����ģ�"), MB_OK);
    //    return 0;

    case WM_CLOSE:      // ����Ϊ���ڻ�Ӧ�ó���Ӧ��ֹ���ź�
        if (MessageBox(hwnd, TEXT("�Ƿ��˳�"), TEXT("�˳�"), MB_YESNO) == IDYES)
            DestroyWindow(hwnd);
        else
            return 0;

    case WM_DESTROY:    // �����ڱ�����ʱ
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}
