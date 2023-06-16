#include <Windows.h>

// DLL入口点函数
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    // 在DLL被加载时执行的代码
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        // 执行您希望在注入时进行的操作
        MessageBox(NULL, L"DLL注入成功！", L"注入示例", MB_OK);
    }

    return TRUE;
}