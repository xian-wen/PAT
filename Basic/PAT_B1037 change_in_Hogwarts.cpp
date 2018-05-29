/*
1037. 在霍格沃茨找零钱（20）
时间限制：400 ms  内存限制：65536 kB  代码长度限制：8000 B

题目描述：
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 
就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，
二十九个纳特(Knut)兑一个西可，很容易。”
现在，给定哈利应付的价钱P和他实付的钱A，
你的任务是写一个程序来计算他应该被找的零钱。

输入格式：
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。
这里Galleon是[0, 10^7]区间内的整数，Sickle是[0, 17)区间内的整数，
Knut是[0, 29)区间内的整数。
输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。
如果他没带够钱，那么输出的应该是负数。
输入样例1：10.16.27 14.1.28
输出样例1：3.2.1
输入样例2：14.1.28 10.16.27
输出样例2：-3.2.1
 */



#include <cstdio>

struct money {
	int g, s, k; // 加隆，西可，纳特 
};

int main()
{
	money p, a; // 应付，实付 
	scanf("%d.%d.%d %d.%d.%d", &p.g, &p.s, &p.k, &a.g, &a.s, &a.k);
	
	int pk = p.g * 17 * 29 + p.s * 29 + p.k; // 应付转换成纳特 
	int ak = a.g * 17 * 29 + a.s * 29 + a.k; // 实付转换成纳特 
	
	int change = ak - pk; // 找零 
	if (change < 0) { // 找零为负，输出负号，再取正 
		printf("-"); 
		change = -change; 
	}
	
	// 将找零以“加隆.西可.纳特”格式输出 
	printf("%d.%d.%d\n", change / 29 / 17, change / 29 % 17, change % 29);
	return 0;
}
