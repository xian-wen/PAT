/*
1073. Scientific Notation (20)
ʱ�����ƣ�100 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

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
#include <cstring> // strlen����ͷ�ļ�

const int maxn = 10010; // ���Ȳ���9999Byte��charΪ1Byte 
char str[maxn]; // ��ſ�ѧ��������ʾ��ʵ��

int main()
{
	gets(str); // ���� 
	int len = strlen(str); // ���ַ������� 
	
	if (str[0] == '-') printf("-"); // ����������� 
	
	int pos = 0;
	while (str[pos] != 'E') pos++; // ��ѯE��λ�� 
	
	int exp = 0;
	for (int i = pos + 2; i < len; i++) { // ��ָ����С�������������ţ� 
		exp = exp * 10 + (str[i] - '0');
	}
	
	if (exp == 0) { // ָ��Ϊ0���� 
		for (int i = 1; i < pos; i++) {
			printf("%c", str[i]);
		}
	} else { // ָ����Ϊ0 
		if (str[pos + 1] == '-') { // ָ��Ϊ�� 
			printf("0.");
			
			int count = exp - 1;
			while (count--) printf("0"); // ���exp-1��0 
			
			for (int i = 1; i < pos; i++) { // ���E֮ǰ���� 
				if (str[i] == '.') continue; // ����С���� 
				printf("%c", str[i]);
			}
		}
		
		if (str[pos + 1] == '+') { // ָ��Ϊ�� 
			for (int i = 1; i < pos; i++) { // ���E֮ǰ���� 
				if (str[i] == '.') continue; // ����С����
				printf("%c", str[i]);
				
				// expΪС��������Ƶ�λ����������(pos-1)-2ʱ�����С���� 
				if (i == exp + 2 && exp != pos - 3) {
					printf(".");
				}
			}
			
			int count = exp - (pos - 3);
			while ((count--) > 0) printf("0"); // exp�ϴ����exp-(pos-3)��0 
		}
	}
	return 0;
}
