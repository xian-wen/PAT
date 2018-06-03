/*
1009. Product of Polynomials (25)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

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
double a[N1] = {0.0}; // 多项式A，指数为下标，系数为元素，初始化为0 
double ab[N2] = {0.0}; // 多项式A*B，两指数为1000的项相乘指数可达到2000 

int main()
{
	int k, exp; // 项数，指数 
	double coe; // 系数 
	
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%lf", &exp, &coe); // 多项式A非零项指数、系数 
		a[exp] += coe;
	}
	
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%lf", &exp, &coe); // 多项式B非零项指数、系数
		int exp_temp = exp; // 保存exp值 
		double coe_temp = coe; // 保存coe值
		for (int j = 0; j < N1; j++) { // 遍历a中非零项
			if (a[j]) { // 系数相乘，指数相加，存于ab中 
				coe *= a[j];
				exp += j;
				ab[exp] += coe;
				exp = exp_temp; // exp回归原值，以备后用 
				coe = coe_temp; // coe回归原值，以备后用 
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < N2; i++) { // 统计ab中非零项 
		if (ab[i]) count++;
	}
	printf("%d", count);
	
	for(int i = N2 - 1; i >= 0; i--) { // 输出ab中非零项 
		if (ab[i]) {
			printf(" %d %.1f", i, ab[i]);
		}
	}
	return 0;
}
