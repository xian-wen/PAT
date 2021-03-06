/*
1006. 换个格式输出整数 (15)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

题目描述：
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：
每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：
每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234

输出样例1：
BBSSS1234

输入样例2：
23

输出样例2：
SS123
 */



#include <cstdio>

int main()
{
	char c[2] = {'B', 'S'}; // 0为百，1为十 
	int n, num[3]; // 正整数，num存放三位上的数字 
	scanf ("%d", &n);
	
	num[0] = n / 100; // 获取百位数字 
	num[1] = n / 10 % 10; // 获取十位数字 
	num[2] = n % 10; // 获取个位数字 
	
	while (num[0]--) { // 输出num[0]个B 
		printf("%c", c[0]);
	}
	
	while (num[1]--) { // 输出num[1]个S 
		printf("%c", c[1]);
	}
	
	for (int i = 0; i < num[2]; i++) { // 输出1-num[2] 
		printf("%d", i + 1);
	}
	return 0;
}
