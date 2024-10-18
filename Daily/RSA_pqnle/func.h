#ifndef RSA_PQNLE_FUNC_H
#define RSA_PQNLE_FUNC_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define TURE 1

__declspec(dllexport) int prime_rand();
__declspec(dllexport) int LCM(int, int);
__declspec(dllexport) int GCD(int);

#endif //RSA_PQNLE_FUNC_H
