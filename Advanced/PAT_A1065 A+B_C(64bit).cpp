/*
1065. A+B and C (64bit) (20)
时间限制：100ms  内存限制：64MB  代码长度限制：16KB

Description:
Given three integers A, B and C in [-2^63^, 2^63^], you are supposed to tell whether A+B > C.

Input Specification:
The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:
For each test case, output in one line "Case #X: true" if A+B&gtC, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

Sample Output:
Case #1: false
Case #2: true
Case #3: false
 */



#include <cstdio>

int main()
{
	int T, i = 1;
	scanf("%d", &T);
	while (T--) {
		long double a, b, c; // long double占16Bytes，范围[-2^127, 2^127-1] 
		scanf("%llf%llf%llf", &a, &b, &c);
		if (a + b > c) printf("Case #%d: true\n", i++);
		else printf("Case #%d: false\n", i++);
	}
	return 0;
}
