/*
1012. 数字分类 (20)
时间限制：100ms  内存限制：64MB  代码长度限制：16KB

题目描述：
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出样例1：
30 11 2 9.7 9

输入样例2：
8 1 2 4 5 6 7 9 16

输出样例2：
N 11 2 N 9
 */



#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	
	int s[5] = {0}; // 存放五类数字，初始化为0 
	int flag[5] = {0}; // 判断某类数字是否存在，0变非0则说明存在 
	int count = 0, j = 1; // count统计A4个数，j用于A2中变换正负号 
	for (int i = 0; i < n; i++) { 
		int a;
		scanf("%d", &a);
		
		switch (a % 5) { 
		case 0: // A1
			if (a % 2 == 0) { // 偶数 
				s[0] += a;
				flag[0] = 1; // 存在即置为1 
			}
			break;
		case 1: // A2
			s[1] += a * j;
			j = -j; // 变化正负号，以交错求和 
			flag[1] = 1; 
			break;
		case 2: // A3
			s[2]++;
			flag[2] = 1; 
			break;
		case 3: // A4
			s[3] += a; // 累计求和 
			count++; // 个数加1 
			flag[3] = 1; 
			break;
		case 4: // A5
			s[4] = a > s[4] ? a : s[4]; // 找最大 
			flag[4] = 1; 
			break;
		}
	}
	
	for (int i = 0; i < 5; i++) {
		if (flag[i] == 0) { // 不存在 
			printf("N");
		} else if (i == 3) {  
			printf("%.1f", (double) s[i] / (double) count); // 求平均数 
		} else {
			printf("%d", s[i]);
		}
		if (i < 4) printf(" "); // 数字间空格，末尾无空格 
	}
	return 0;
}
