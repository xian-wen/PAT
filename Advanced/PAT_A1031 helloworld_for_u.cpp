/*
1031. Hello World for U (20)
ʱ�����ƣ�400ms  �ڴ����ƣ�64MB  ���볤�����ƣ�16KB

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
#include <cstring> // strlen����ͷ�ļ� 

int main()
{
	char str[85];
	gets(str); // �����ַ��� 
	int n = strlen(str); // ���ַ������� 
	int row = (n + 2) / 3; // ���� 
	int col = n - 2 * (row - 1); // �����������һ���ַ����� 
	
	for (int i = 0; i < row; i++) {
		printf("%c", str[i]); // ÿһ�п�ͷ�����i���ַ� 
		for (int j = 0; j < col - 2; j++) { // ÿһ���м�����ո���ַ� 
			if (i < row -1)	printf(" "); // ǰrow-1���м�����ո� 
			else printf("%c", str[j + i + 1]); // ���һ���м�����ַ� 
		}
		printf("%c\n", str[n - i - 1]); // ÿһ��ĩβ���������i���ַ� 
	}
	return 0;
}
