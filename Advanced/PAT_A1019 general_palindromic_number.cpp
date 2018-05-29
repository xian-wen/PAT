/*
1019. General Palindromic Number (20)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N > 0 in base b >= 2, where it is written in standard notation with k+1 digits a~i~ as the sum of (a~i~b^i^) for i from 0 to k. Here, as usual, 0 <= a~i~ < b for all i and a~k~ is non-zero. Then N is palindromic if and only if a~i~ = a~k-i~ for all i. Zero is written 0 in any base and is also palindromic by definition.
Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

Input Specification:
Each input file contains one test case. Each case consists of two non-negative numbers N and b, where 0 <= N <= 10^9^ is the decimal number and 2 <= b <= 10^9^ is the base. The numbers are separated by a space.

Output Specification:
For each test case, first print in one line "Yes" if N is a palindromic number in base b, or "No" if not. Then in the next line, print N as the number in base b in the form "a~k~ a~k-1~ ... a~0~". Notice that there must be no extra space at the end of output.

Sample Input 1:
27 2

Sample Output 1:
Yes
1 1 0 1 1

Sample Input 2:
121 5

Sample Output 2:
No
4 4 1
 */



#include <cstdio>

int main()
{
	int n, b;
	scanf("%d%d", &n, &b); // 非负整数，进制 
	
	// 将n由十进制转换成b进制 
	int a[31], k = 0; // 数组a存放进制转换后的每一位，k为位数 
	do {
		a[k++] = n % b; // 除基取余 
		n /= b; 
	} while (n); // 商不为0进行循环 
	
	// 判断是否为回文数 
	int i = 0, j = k - 1; // i指向头，j指向尾 
	while (i < j) { // 由两头向中间，逐位检查是否相等 
		if (a[i] != a[j]) break; // 存在不等即可结束检查 
		else { // 相等则分别进行下一位的比较 
			i++;
			j--;
		}
	}
	if (i >= j) printf("Yes\n"); // i不小于j，说明全部检查完毕 
	else printf("No\n"); // i比j小，说明还未检查完毕，即出现前后不等 
	
	// 从高位向低位输出进制转换后结果
	for (int i = k - 1; i >= 0; i--) {  
		printf("%d", a[i]);
		if (i > 0) printf(" "); // 末尾无空格 
	}
	return 0;
}
