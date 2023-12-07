#include <iostream>
#include <windows.h>
#include "ss_lm_runtime.h"

#define LICENSE_ID 1

typedef UINT (CALLBACK* SLMINIT)(ST_INIT_PARAM*);
typedef UINT (CALLBACK* SLMLOGIN)(ST_LOGIN_PARAM*, INFO_FORMAT_TYPE, SLM_HANDLE_INDEX*, void*);

unsigned char g_api_password[16] = { 0xD7, 0xAA, 0x1D, 0xEE, 0x34, 0x95, 0xFA, 0xA0, 0xE8, 0x11, 0x61, 0xFA, 0xBB, 0x75, 0x26, 0x87 };

int main() {
    int ret = 0;
    ST_INIT_PARAM st_init_param = {0}; //ss_init_param
    ST_LOGIN_PARAM st_login_param = {0}; //ss_login_param
    SLM_HANDLE_INDEX slm_handle = 0;
   

    // 加载动态链接库
    HMODULE slmHandle = LoadLibrary("slm_runtime.dll");
    std::cout << GetLastError();

    if (slmHandle != NULL) {
        // 获取函数地址
        SLMINIT getSlmInit = (SLMINIT)GetProcAddress(slmHandle, "slm_init");
        if (getSlmInit != NULL) {
             //ss_init_param
            st_init_param.version = SLM_CALLBACK_VERSION02;
            st_init_param.pfn = NULL;
            st_init_param.timeout = 60;
            memcpy(st_init_param.password, g_api_password, sizeof(g_api_password));
            ret = getSlmInit(&st_init_param);
            std::cout << "GetProcAddress success! ret = " << ret << std::endl;
        } else {
            std::cerr << "Failed to get function address." << std::endl;
        }

        SLMLOGIN getSlmLogin = (SLMLOGIN)GetProcAddress(slmHandle, "slm_login");
        if (getSlmLogin != NULL) {
            // ss_login_param
            st_login_param.size = sizeof(ST_LOGIN_PARAM);
            st_login_param.license_id = 0;
            st_login_param.login_mode = SLM_LOGIN_MODE_LOCAL_DONGLE;
            ret = getSlmLogin(&st_login_param, STRUCT, &slm_handle, NULL);
            std::cout << "GetProcAddress success! ret = " << ret << std::endl;
        } else {
            std::cerr << "Failed to get function address." << std::endl;
        }

        // 卸载动态链接库
        FreeLibrary(slmHandle);
    } else {
        std::cerr << "Failed to load library." << std::endl;
    }
    return 0;
}
