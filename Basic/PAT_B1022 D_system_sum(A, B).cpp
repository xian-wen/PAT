/*
1022. D进制的A+B (20)
时间限制：100 ms  内存限制：65536 kB  代码长度限制：8000 B

题目描述：
输入两个非负10进制整数A和B(<=2^30-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：输入在一行中依次给出3个整数A、B和D。
输出格式：输出A+B的D进制数。
输入样例：123 456 8
输出样例：1103
 */



#include <cstdio>

int main()
{
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d); // 数A，数B，D进制 
	
	int x = a + b;
	int ans[100], num = 0; // ans数组存放D进制的每一位，num为位数 
	
	do {
		ans[num++] = x % d; // 除基取余 
		x /= d;  
	} while (x); // 商不为0进行循环 
	
	for (int i = num - 1; i >= 0; i--) { // 输出进制转换后的A+B 
		printf("%d", ans[i]);
	}
	return 0;
}
