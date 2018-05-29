/*
1009. Product of Polynomials (25)
ʱ�����ƣ�400ms  �ڴ����ƣ�64MB  ���볤�����ƣ�16KB

Description:
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output:
3 3 3.6 2 6.0 1 1.6
 */



#include <cstdio>

const int N1 = 1001, N2 = 2001; 
double a[N1] = {0.0}; // ����ʽA��ָ��Ϊ�±꣬ϵ��ΪԪ�أ���ʼ��Ϊ0 
double ab[N2] = {0.0}; // ����ʽA*B����ָ��Ϊ1000�������ָ���ɴﵽ2000 

int main()
{
	int k, exp; // ������ָ�� 
	double coe; // ϵ�� 
	
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%lf", &exp, &coe); // ����ʽA������ָ����ϵ�� 
		a[exp] += coe;
	}
	
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%lf", &exp, &coe); // ����ʽB������ָ����ϵ��
		int exp_temp = exp; // ����expֵ 
		double coe_temp = coe; // ����coeֵ
		for (int j = 0; j < N1; j++) { // ����a�з�����
			if (a[j]) { // ϵ����ˣ�ָ����ӣ�����ab�� 
				coe *= a[j];
				exp += j;
				ab[exp] += coe;
				exp = exp_temp; // exp�ع�ԭֵ���Ա����� 
				coe = coe_temp; // coe�ع�ԭֵ���Ա����� 
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < N2; i++) { // ͳ��ab�з����� 
		if (ab[i]) count++;
	}
	printf("%d", count);
	
	for(int i = N2 - 1; i >= 0; i--) { // ���ab�з����� 
		if (ab[i]) {
			printf(" %d %.1f", i, ab[i]);
		}
	}
	return 0;
}
