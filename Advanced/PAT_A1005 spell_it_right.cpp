/*
1005. Spell It Right (20)
ʱ�����ƣ�400ms  �ڴ����ƣ�64MB  ���볤�����ƣ�16KB

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
#include <cstring> // strlen����ͷ�ļ� 

const int maxn = 110; // ������10^100 

char digit[10][10] = { // digit[0]="zero", digit[1]="one"...
	"zero", "one", "two", "three", "four", 
	"five", "six", "seven", "eight", "nine" 
};

int main()
{
	char str[maxn];
	gets(str); // ���������� 
	
	int len = strlen(str), sum = 0; // �ַ������ȣ��� 
	for (int i = 0; i < len; i++) { // ���λ����֮�� 
		sum += str[i] - '0';
	} 
	
	int ans[5], num = 0; // ���ÿһλ���֣�λ�� 
	do {
		ans[num++] = sum % 10; // ��ȡ��λ 
		sum /= 10; // ȥ����λ 
	} while (sum); // �̲�Ϊ0ѭ������ 
	
	for (int i = num - 1; i >= 0; i--) { // ��������͵ĸ�λ���ֶ�Ӧ���ַ� 
		printf("%s", digit[ans[i]]);
		if (i) printf(" "); // i��Ϊ0������ո� 
	}
	return 0;
}
