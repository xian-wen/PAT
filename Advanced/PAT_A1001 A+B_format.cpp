/*
1001. A+B Format (20)
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

Description:
Calculate a + b and output the sum in standard format -- 
that is, the digits must be separated into groups of three by commas 
(unless there are less than four digits).

Input: 
Each input file contains one test case. 
Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. 
The numbers are separated by a space.
Output:
For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.
Sample Input:
-1000000 9
Sample Output:
-999,991
 */



#include <cstdio>

int main()
{
	int a, b, sum;
	scanf("%d%d", &a, &b);
	
	sum = a + b; 
	if (sum < 0) { // ��Ϊ�� 
		printf("-"); // ������� 
		sum = -sum; // ȡ����ֵ 
	}
	
	char ans[10]; // ��Ÿ�ʽ���ĺ� 
	int num = 0;
	do {
		ans[num] = sum % 10 + '0'; // ��ȡ��λ��ת�����ַ����ٴ�� 
		sum /= 10; // ȥ����λ 
		num++; // num���� 
		
		// �±�Ϊnum����ʾ��num+1λ�����ż��3λ���֣�����4��8λ 
		if ((num + 1) % 4 == 0 && sum > 0) { // sumΪ�� 
			ans[num] = ','; // ������� 
			num++; // num���� 
		} 
	} while (sum); // sum��Ϊ0ѭ������ 
	
	for (int i = num - 1; i >= 0; i--) { // ������� 
		printf("%c", ans[i]);
	} 
	return 0;
}
