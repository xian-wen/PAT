/*
1014. 福尔摩斯的约会 (20)
时间限制：100ms  内存限制：64MB  代码长度限制：16KB

题目描述：
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

输出样例：
THU 14:04
 */



#include <cstdio>
#include <cstring> // strlen函数头文件 

#define min(a, b) ((a) < (b)) ? (a) : (b) // 比较两个数中的最小值 

// 建立数字与星期间的关系，即day[0] = "MON", day[1] = "TUE"...
char day[10][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	char str[4][65]; // 4个字符串 
	int len[4]; // 各字符串长度 
	for (int i = 0; i < 4; i++) { // 输入字符串，求其长度 
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
	}
	
	int i; // 对前2个字符串，从左往右逐个字符比较，找出第1对相等的大写字母 
	for (i = 0; i < min(len[0], len[1]); i++) {
		if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
			printf("%s ", day[str[0][i] - 'A']); // 大写字母转换成数字 
			break;
		}
	}
	
	// 对前2个字符串，从上次比较的下一位继续逐个字符比较，找出第2对相等的字符 
	for (int j = i + 1; j < min(len[0], len[1]); j++) {
		if (str[0][j] == str[1][j]) {
			if (str[0][j] >= '0' && str[0][j] <= '9') { // 数字 
				printf("%02d:", str[0][j] - '0'); // 字符数字转换成整型数字
				break;
			} 
			if (str[0][j] >= 'A' && str[0][j] <= 'N') { // 大写字母 
				printf("%d:", str[0][j] - 'A' + 10); // 大写字母转换成数字
				break; 
			}
		}
	} 
	
	// 对后2个字符串，从左往右逐个字符比较，找出第一对相等的英文字母 
	for (int j = 0; j < min(len[2], len[3]); j++) {
		if (str[2][j] == str[3][j] 
			&& ((str[2][j] >= 'A' && str[2][j] <= 'Z')
				|| (str[2][j] >= 'a' && str[2][j] <= 'z'))) {
			printf("%02d\n", j); // 输出相等字母所在位置 
			break;
		}
	}
	return 0;
}
