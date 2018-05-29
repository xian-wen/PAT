/*
1016. 部分A+B (15)
时间限制：100ms  内存限制：64MB  代码长度限制：16KB

题目描述：
正整数A的“D~A~（为1位整数）部分”定义为由A中所有D~A~组成的新整数P~A~。例如：给定A = 3862767，D~A~ = 6，则A的“6部分”P~A~是66，因为A中有2个6。
现给定A、D~A~、B、D~B~，请编写程序计算P~A~ + P~B~。

输入格式：
输入在一行中依次给出A、D~A~、B、D~B~，中间以空格分隔，其中0 < A, B < 10^10^。

输出格式：
在一行中输出P~A~ + P~B~的值。

输入样例1：
3862767 6 13530293 3

输出样例1：
399

输入样例2：
3862767 1 13530293 8

输出样例2：
0
 */



#include <cstdio>

int main()
{
	long long a, b; // 10^10，选long long 
	int da, db;
	scanf("%lld%d%lld%d", &a, &da, &b, &db);
	
	long long pa = 0, pb = 0; // 10^10，选long long 
	while (a > 0) { // a为0则退出循环 
		if (a % 10 == da) { // 获取个位数，等于da则更新pa 
			pa = pa * 10 + da;
		}
		a /= 10; // 剔除个位数 
	}
	while (b > 0) {
		if (b % 10 == db) {
			pb = pb * 10 + db;
		}
		b /= 10;
	}
	
	printf("%lld\n", pa + pb);
	return 0;
}
