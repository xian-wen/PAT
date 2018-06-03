/*
1058. A+B in Hogwarts (20)
时间限制：50ms  内存限制：64MB  代码长度限制：16KB

Description:
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 10^7^], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27

Sample Output:
14.1.28
 */



#include <cstdio>

struct money {
	long g, s, k; // Galleon, Sickle, Knut 
};

const int Galleon = 17 * 29; // 1 Galleon = 17 * 29 Knut
const int Sickle = 29; // 1 Sickle = 29 Knut

int main()
{
	money a, b;
	scanf("%ld.%ld.%ld %ld.%ld.%ld", &a.g, &a.s, &a.k, &b.g, &b.s, &b.k);
	
	// 将a、b全部转换成Knut再求和，考虑可能溢出，选long 
	long ka = a.g * Galleon + a.s * Sickle + a.k; 
	long kb = b.g * Galleon + b.s * Sickle + b.k;
	long sum = ka + kb;
	
	// 将和以“Galleon.Sickle.Knut”格式输出 
	printf("%ld.%ld.%ld\n", sum / Galleon, 
		sum % Galleon / Sickle, sum % Sickle);
	return 0;
}
