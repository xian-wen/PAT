/*
1005. Spell It Right (20)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345

Sample Output:
one five
 */



#include <cstdio>
#include <cstring> // strlen函数头文件 

const int maxn = 110; // 不超过10^100 

char digit[10][10] = { // digit[0]="zero", digit[1]="one"...
	"zero", "one", "two", "three", "four", 
	"five", "six", "seven", "eight", "nine" 
};

int main()
{
	char str[maxn];
	gets(str); // 输入正整数 
	
	int len = strlen(str), sum = 0; // 字符串长度，和 
	for (int i = 0; i < len; i++) { // 求各位数字之和 
		sum += str[i] - '0';
	} 
	
	int ans[5], num = 0; // 存放每一位数字，位数 
	do {
		ans[num++] = sum % 10; // 获取个位 
		sum /= 10; // 去除个位 
	} while (sum); // 商不为0循环继续 
	
	for (int i = num - 1; i >= 0; i--) { // 逆序输出和的各位数字对应的字符 
		printf("%s", digit[ans[i]]);
		if (i) printf(" "); // i不为0，输出空格 
	}
	return 0;
}
