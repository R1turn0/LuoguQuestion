#include <Windows.h>
#include <iostream>

int main()
{
    // 目标进程ID
    DWORD targetProcessId = 1234; // 替换为目标进程的实际ID

    // 加载DLL的路径
    LPCWSTR dllPath = L"C:\\Path\\To\\YourDLL.dll"; // 替换为您DLL的实际路径

    // 获取目标进程句柄
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, targetProcessId);
    if (hProcess == NULL)
    {
        std::cout << "无法打开目标进程" << std::endl;
        return 1;
    }

    // 在目标进程中分配内存
    LPVOID dllPathAddress = VirtualAllocEx(hProcess, NULL, wcslen(dllPath) * sizeof(wchar_t), MEM_COMMIT, PAGE_READWRITE);
    if (dllPathAddress == NULL)
    {
        std::cout << "无法在目标进程中分配内存" << std::endl;
        CloseHandle(hProcess);
        return 1;
    }

    // 将DLL路径写入目标进程内存
    if (!WriteProcessMemory(hProcess, dllPathAddress, dllPath, wcslen(dllPath) * sizeof(wchar_t), NULL))
    {
        std::cout << "无法将DLL路径写入目标进程内存" << std::endl;
        VirtualFreeEx(hProcess, dllPathAddress, 0, MEM_RELEASE);
        CloseHandle(hProcess);
        return 1;
    }

    // 在目标进程中创建远程线程并执行LoadLibrary函数
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryW, dllPathAddress, 0, NULL);
    if (hThread == NULL)
    {
        std::cout << "无法在目标进程中创建远程线程" << std::endl;
        VirtualFreeEx(hProcess, dllPathAddress, 0, MEM_RELEASE);
        CloseHandle(hProcess);
        return 1;
    }

    // 等待远程线程结束
    WaitForSingleObject(hThread, INFINITE);

    // 清理资源
    VirtualFreeEx(hProcess, dllPathAddress, 0, MEM_RELEASE);
    CloseHandle(hThread);
    CloseHandle(hProcess);

    std::cout << "DLL注入完成" << std::endl;

    return 0;
}