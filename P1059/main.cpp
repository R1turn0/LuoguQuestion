/*
#include<iostream>
#include<algorithm>
#include<functional>

int main()
{
    int N, num[100];
    std::cin >> N;
    if (N > 100)
        return 0;
    for (int i = 0; i < N; i++)
        std::cin >> num[i];
    sort(num, num + N, std::less<int>());//按从小到大的顺序
    int n = std::unique(num, num + N) - num;

    std::cout << n << std::endl;    //sizeof(num) / sizeof(num[0])
    for(int i=0; i < n; i++) {
        std::cout<<num[i]<<" ";
    }
}
 */


// ====================================================


#include <iostream>
#include <set>

int main(){
    int N, num[100];
    std::set<int> sum;
    std::cin >> N;
    if (N > 100)
        return 0;
    for (int i = 0; i < N; i++) {
        std::cin >> num[i];
        sum.insert(num[i]);
    }
    std::cout << sum.size() << std::endl;
    while (!sum.empty()){
        std::cout << *sum.begin() << " " ;
        sum.erase(sum.begin());
    }
    return 0;
}


/*
//产生 [0,b) 范围内到随机数
int randoxNumber = rand() % b ;

//产生 [a,b) 范围内到随机数
int randoxNumber = a + rand() % ( b -a ) ;

//产生 [a,b] 范围内到随机数
int randoxNumber = a + rand() % ( b -a +1 ) ;

//产生 [0,1] 范围内到随机小数
double randoxNumber =rand() / RAND_MAX

//产生 [0,1) 范围内到随机小数
double randoxNumber =rand() / ( RAND_MAX +1 )
*/
