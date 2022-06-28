#include <iostream>
#include <stack>

int main()
{
    std::stack<char>Expression;
    char num = 0;
    int sum1 = 0, sum2 = 0;
    while (num != '@' )
    {
        std::cin >> num;
        Expression.push(num);
        if (num == '(')
            sum1 +=1;
        else if (num == ')')
            sum2 += 1;
        if (sum2 > sum1)
        {
            std::cout << "NO";
            return 0;
        }
    }
    if (sum1 == sum2)
    {
        while (!Expression.empty())
        {
            if (Expression.top() == ')')
                break;
            if (Expression.top() == '(')
            {
                std::cout << "NO";
                return 0;
            }
            Expression.pop();
        }
        std::cout << "YES";
    }
    else
        std::cout << "NO";
    return 0;
}
