/*
1073. Scientific Notation (20)
时间限制：100 ms  内存限制：65536 kB  代码长度限制：16000 B

Description:
Scientific notation is the way that scientists easily handle 
very large numbers or very small numbers. 
The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ 
which means that the integer portion has exactly one digit, 
there is at least one digit in the fractional portion, 
and the number and its exponent's signs are always provided 
even when they are positive.
Now given a real number A in scientific notation, 
you are supposed to print A in the conventional notation 
while keeping all the significant figures.

Input Specification:
Each input file contains one test case. For each case, 
there is one line containing the real number A in scientific notation. 
The number is no more than 9999 bytes in length 
and the exponent's absolute value is no more than 9999.
Output Specification:
For each test case, 
print in one line the input number A in the conventional notation, 
with all the significant figures kept, including trailing zeros.
Sample Input 1: +1.23400E-03
Sample Output 1: 0.00123400
Sample Input 2: -1.2E+10
Sample Output 2: -12000000000
 */



#include <cstdio>
#include <cstring> // strlen函数头文件

const int maxn = 10010; // 长度不超9999Byte，char为1Byte 
char str[maxn]; // 存放科学计数法表示的实数

int main()
{
	gets(str); // 输入 
	int len = strlen(str); // 求字符串长度 
	
	if (str[0] == '-') printf("-"); // 负数输出负号 
	
	int pos = 0;
	while (str[pos] != 'E') pos++; // 查询E的位置 
	
	int exp = 0;
	for (int i = pos + 2; i < len; i++) { // 求指数大小（不包括正负号） 
		exp = exp * 10 + (str[i] - '0');
	}
	
	if (exp == 0) { // 指数为0特判 
		for (int i = 1; i < pos; i++) {
			printf("%c", str[i]);
		}
	} else { // 指数不为0 
		if (str[pos + 1] == '-') { // 指数为负 
			printf("0.");
			
			int count = exp - 1;
			while (count--) printf("0"); // 输出exp-1个0 
			
			for (int i = 1; i < pos; i++) { // 输出E之前的数 
				if (str[i] == '.') continue; // 跳过小数点 
				printf("%c", str[i]);
			}
		}
		
		if (str[pos + 1] == '+') { // 指数为正 
			for (int i = 1; i < pos; i++) { // 输出E之前的数 
				if (str[i] == '.') continue; // 跳过小数点
				printf("%c", str[i]);
				
				// exp为小数点需后移的位数，不等于(pos-1)-2时则输出小数点 
				if (i == exp + 2 && exp != pos - 3) {
					printf(".");
				}
			}
			
			int count = exp - (pos - 3);
			while ((count--) > 0) printf("0"); // exp较大，输出exp-(pos-3)个0 
		}
	}
	return 0;
}
