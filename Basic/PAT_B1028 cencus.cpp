/*
028. 人口普查(20)
时间限制：200 ms  内存限制：65536 kB  代码长度限制：8000 B

题目描述：
某城镇进行人口普查，得到了全体居民的生日。
现请你写个程序，找出镇上最年长和最年轻的人。
这里确保每个输入的日期都是合法的，
但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，
所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数N，取值在(0, 105]；
随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、
以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。
题目保证最年长和最年轻的人没有并列。
输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：3 Tom John
 */



#include <cstdio>

struct birthday { // 出生日期 
	char name[10]; // 姓名 
	int year; // 年 
	int month; // 月 
	int day; // 日 
}; 

birthday temp, max, min; // 临时数据，最大出生日期，最小出生日期 

int main()
{
	int n, count = 0;
	scanf("%d", &n);
	// 初始化最大出生日期为1814/9/6，最小出生日期为2014/9/6 
	max.year = 1814; 
	min.year = 2014;
	max.month = min.month = 9;
	max.day = min.day = 6;
	while (n--) {
		scanf("%s %d/%d/%d", &temp.name, &temp.year, &temp.month, &temp.day);
		// 过滤超过200岁的生日和未出生的生日 
		if (temp.year > 2014 || temp.year < 1814 
			|| (temp.year == 2014 
				&& (temp.month > 9 || (temp.month == 9 && temp.day > 6)))
			|| (temp.year == 1814 
				&& (temp.month < 9 || (temp.month == 9 && temp.day < 6)))) {
			continue;
		} else {
			// 求最大出生日期 
			if (temp.year > max.year
				|| (temp.year == max.year
					&& (temp.month > max.month 
						|| (temp.month == max.month 
							&& temp.day >= max.day)))) {
				max = temp;
			}
			// 求最小出生日期 
			if (temp.year < min.year
				|| (temp.year == min.year
					&& (temp.month < min.month 
						|| (temp.month == min.month 
							&& temp.day <= min.day)))) {
				min = temp;
			}
			count++; // 统计有效生日个数 
		}
	}
	
	if (count == 0) printf("0\n"); // 无有效生日，单独判断，以免格式错误 
	else { // 最小出生日期为最年长者，最大出生日期为最年轻者
		printf("%d %s %s\n", count, min.name, max.name);
	}
	return 0;
}
