// P5705.cpp: 定义应用程序的入口点。
//

#include "P5705.h"

int main()
{
	std::string str;

	std::cin >> str;

	for (int i = (int)str.length() - 1; i >= 0; i--)
	{
		std::cout << str[i];
	}

	return 0;
}
