#include <iostream>

template<typename T>
void bubble_sort(T a, int n, int &sun) {
    int temp;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - 1 - i); j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                sun++;
            }
        }
    }
}
template<typename T>
int input_all(T a, int &n)
{
    std::cin >> n;
    if ( n > 1000)
        return 0;
    for ( int i = 0; i < n; i++ )
    {
        std::cin >> a[i];
    }
}

int main() {
    int n = 0, temp = 0, sun = 0;
    int a[1000];
    input_all(a, n);
    bubble_sort(a, n, sun);

//    for (int i = 0; i < n ; ++i)
//    {
//        std::cout << a[i];
//    }
//    std::cout << std::endl;

    std::cout << sun;
    return 0;
}


//#include <iostream>
//using namespace std;
//template<typename T>
////整数或浮点数皆可使用
//void bubble_sort(T arr[], int len)
//{
//    int i, j;  T temp;
//    for (i = 0; i < len - 1; i++)
//        for (j = 0; j < len - 1 - i; j++)
//            if (arr[j] > arr[j + 1])
//            {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//}
//int main()
//{
//    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
//    int len = (int) sizeof(arr) / sizeof(*arr);
//    bubble_sort(arr, len);
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << ' ';
//
//    cout << endl;
//
//    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
//    len = (int) sizeof(arrf) / sizeof(*arrf);
//    bubble_sort(arrf, len);
//    for (int i = 0; i < len; i++)
//        cout << arrf[i] << ' ';
//
//    return 0;
//}