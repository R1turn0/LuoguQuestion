#include <iostream>
#include <cmath>

int main()
{
    int n;
    scanf_s("%d", &n, sizeof(int));
    printf("%.2f",(pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5));
    return 0;
}
