/*
1002. A+B for Polynomials (25)
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

Description:
This time, you are supposed to find A+B where A and B are two polynomials.

Input:
Each input file contains one test case.
Each case occupies 2 lines,
and each line contains the information of a polynomial:
K N1 aN1 N2 aN2 ... NK aNK,
where K is the number of nonzero terms in the polynomial,
Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively.
It is given that 1 <= K <= 10��0 <= NK < ... < N2 < N1 <=1000.
Output:
For each test case you should output the sum of A and B in one line,
with the same format as the input.
Notice that there must be NO extra space at the end of each line.
Please be accurate to 1 decimal place.
Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output: 3 2 1.5 1 2.9 0 3.2
 */



#include <cstdio>

const int MAX_EXP = 1010; // ��ߴ���
double a[MAX_EXP] = {0.0}; // ����Ϊ�����±꣬ϵ��Ϊ����Ԫ�أ���ʼ��Ϊ0

int main()
{
	int k, exp, count = 0;
	double coe;

	scanf("%d", &k); // A������
	for (int i = 0; i < k; i++) {
		scanf("%d%lf", &exp, &coe); // ������ϵ��
		a[exp] += coe;
	}

	scanf("%d", &k); // B������
	for (int i = 0; i < k; i++) {
		scanf("%d%lf", &exp, &coe);
		a[exp] += coe;
	}

	for (int i = 0; i < MAX_EXP; i++) {
		if (a[i]) count++; // ͳ�Ʒ�����
	}

	printf("%d", count);
	for (int i = MAX_EXP - 1; i >= 0; i--) { // ����������ɸ��������
		if (a[i]) printf(" %d %.1f", i, a[i]); // �м��пո�ĩβ�޿ո�
	}
	return 0;
}
