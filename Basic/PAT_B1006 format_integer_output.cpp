/*
1006. ������ʽ������� (15)
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�8000 B

��Ŀ������
����������ĸB����ʾ���١�����ĸS��ʾ��ʮ�����á�12...n������ʾ��λ����n��<10����
������ʽ�������һ��������3λ����������
����234Ӧ�ñ����ΪBBSSS1234����Ϊ����2�����١���3����ʮ�����Լ���λ��4��

�����ʽ��ÿ�������������1����������������������n��<1000����
�����ʽ��ÿ���������������ռһ�У��ù涨�ĸ�ʽ���n��
��������1��234
�������1��BBSSS1234
��������2��23
�������2��SS123
 */



#include <cstdio>

int main()
{
	char c[2] = {'B', 'S'}; // 0Ϊ�٣�1Ϊʮ 
	int n, num[3]; // ��������num�����λ�ϵ����� 
	scanf ("%d", &n);
	
	num[0] = n / 100; // ��ȡ��λ���� 
	num[1] = n / 10 % 10; // ��ȡʮλ���� 
	num[2] = n % 10; // ��ȡ��λ���� 
	
	while (num[0]--) { // ���num[0]��B 
		printf("%c", c[0]);
	}
	
	while (num[1]--) { // ���num[1]��S 
		printf("%c", c[1]);
	}
	
	for (int i = 0; i < num[2]; i++) { // ���1-num[2] 
		printf("%d", i + 1);
	}
	return 0;
}