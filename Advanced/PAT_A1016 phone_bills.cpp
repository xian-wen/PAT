/*
1016. Phone Bills (25)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
 */



#include <cstdio>
#include <cstring> // strcmp函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中

struct record {
	char name[25]; // 姓名 
	int mon, day, hou, min; // 月，日，时，分 
	int flag; // 1为on-line，0为off-line 
};

const int maxn = 1010;
record r[maxn]; 

// 比较函数 
bool cmp(record a, record b)
{
	// 姓名不同按字母序排列，姓名相同按时间先后排列 
	if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	else if (a.day != b.day) return a.day < b.day; 
	else if (a.hou != b.hou) return a.hou < b.hou;
	else return a.min < b.min;
}

int main()
{
	int rate[24]; // 每小时费率 
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
	}
	
	int n;
	char flag[10]; // on-line或off-line 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { // 输入n条通话记录 
		scanf("%s %d:%d:%d:%d %s", 
			r[i].name, &r[i].mon, &r[i].day, &r[i].hou, &r[i].min, flag);
		if (!strcmp(flag, "on-line")) r[i].flag = 1;
		else if (!strcmp(flag, "off-line")) r[i].flag = 0;
	}
	
	sort(r, r + n, cmp); // 排序 
	
	int total = 0; // 客户每月总话费 
	for(int i = 0; i < n; i++) {
		if (!strcmp(r[i].name, r[i + 1].name)) { // 姓名相同 
			// on-line和off-line配对
			if (r[i].flag == 1 && r[i + 1].flag == 0) { 
				// 第一次有效通话，输出客户姓名和月份，第二次则不必再输出 
				if (!total) printf("%s %02d\n", r[i].name, r[i].mon);
				
				// 输出该记录通话起止时间，不足2位以0补齐 
				printf("%02d:%02d:%02d ", r[i].day, r[i].hou, r[i].min); 
				printf("%02d:%02d:%02d ", r[i+1].day, r[i+1].hou, r[i+1].min);
				
				int minute = 0, bill = 0; // 分钟数，话费 
				// 第1条记录分钟数不断加1直至与第2条记录时间相等
				// 即可得到本次通话时长，同时计算出相应话费 
				while (r[i].day < r[i + 1].day 
					|| r[i].hou < r[i + 1].hou || r[i].min < r[i + 1].min) {
					r[i].min++;
					minute++;
					bill += rate[r[i].hou]; // 该分钟所在小时区间段的话费 
					if (r[i].min == 60) { // 分钟自增至60 
						r[i].hou++; // 小时进1 
						r[i].min = 0; // 分钟归0 
					}
					if (r[i].hou == 24) { // 小时自增至24 
						r[i].day++; // 天数进1 
						r[i].hou = 0; // 小时归0 
					}
				}
				
				// 输出通话时长和美元制话费 
				printf("%d $%.2f\n", minute, bill / 100.0);
				total += bill; // 累计该月总话费 
			} 
		} else { // 总话费不为0则输出，并归0 
			if (total) printf("Total amount: $%.2f\n", total / 100.0);
			total = 0;
		}
	}
	return 0;
}
