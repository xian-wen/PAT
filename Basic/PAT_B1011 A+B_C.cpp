/*
1011. A+B和C (15)
时间限制：150 ms  内存限制：65536 kB  代码长度限制：8000 B

题目描述： 
给定区间[-2^31, 2^31]内的3个整数A、B和C，请判断A+B是否大于C。

输入格式：
输入第1行给出正整数T(<=10)，是测试用例的个数。
随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。
输出格式：
对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，
否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。
输入样例：
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
输出样例：
Case #1: false
Case #2: true
Case #3: true
Case #4: false
 */



#include <cstdio>

int main()
{
	
	int T, i = 1; 
	scanf("%d", &T); // T组测试用例 
	
	while (T--) { // T次循环 
		// int范围为[-2^31, 2^31-1]，题中要求2^31，故用long long 
		long long A, B, C;
		scanf("%lld%lld%lld", &A, &B, &C);
		printf("Case #%d: %s\n", i++, (A + B > C) ? "true" : "false");
	}
	return 0;
}
