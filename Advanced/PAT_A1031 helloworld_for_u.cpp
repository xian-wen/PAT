/*
1031. Hello World for U (20)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

h  d
e  l
l  r
lowo

That is, the characters must be printed in the original order, starting top-down from the left vertical line with n~1~ characters, then left to right along the bottom line with n~2~ characters, and finally bottom-up along the vertical line with n~3~ characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n~1~ = n~3~ = max { k| k <= n~2~ for all 3 <= n~2~ <= N } with n~1~ + n~2~ + n~3~ - 2 = N.

Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:
For each test case, print the input string in the shape of U as specified in the description.

Sample Input:
helloworld!

Sample Output:
h   !
e   d
l   l
lowor
 */



#include <cstdio>
#include <cstring> // strlen函数头文件 

int main()
{
	char str[85];
	gets(str); // 输入字符串 
	int n = strlen(str); // 求字符串长度 
	int row = (n + 2) / 3; // 行数 
	int col = n - 2 * (row - 1); // 列数，即最后一行字符个数 
	
	for (int i = 0; i < row; i++) {
		printf("%c", str[i]); // 每一行开头输出第i个字符 
		for (int j = 0; j < col - 2; j++) { // 每一行中间输出空格或字符 
			if (i < row -1)	printf(" "); // 前row-1行中间输出空格 
			else printf("%c", str[j + i + 1]); // 最后一行中间输出字符 
		}
		printf("%c\n", str[n - i - 1]); // 每一行末尾输出倒数第i个字符 
	}
	return 0;
}
