/*
1016. Phone Bills (25)
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

Description:
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, 
depending on the time of day when the call is made. 
When a customer starts connecting a long-distance call, 
the time will be recorded, 
and so will be the time when the customer hangs up the phone. 
Every calendar month, a bill is sent to the customer for each minute called 
(at a rate determined by the time of day). 
Your job is to prepare the bills for each month, 
given a set of phone call records.

Input Specification:
Each input file contains one test case. 
Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers 
denoting the toll (cents/minute) from 00:00 - 01:00, 
the toll from 01:00 - 02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), 
followed by N lines of records. 
Each phone call record consists of the name of the customer 
(string of up to 20 characters without space), 
the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
For each test case, all dates will be within a single month. 
Each "on-line" record is paired with the chronologically next record 
for the same customer provided it is an "off-line" record. 
Any "on-line" records that are not paired with an "off-line" record are ignored, 
as are "off-line" records not paired with an "on-line" record. 
It is guaranteed that at least one call is well paired in the input. 
You may assume that no two records for the same customer have the same time. 
Times are recorded using a 24-hour clock.
Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. 
For each customer, first print in a line the name of the customer 
and the month of the bill in the format shown by the sample. 
Then for each time period of a call, 
print in one line the beginning and ending time and date (dd:hh:mm), 
the lasting time (in minute) and the charge of the call. 
The calls must be listed in chronological order. 
Finally, print the total charge for the month in the format shown by the sample.
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
#include <cstring> // strcmp����ͷ�ļ� 
#include <algorithm> // sort����ͷ�ļ� 

using namespace std; // sort��std��

struct record {
	char name[25]; // ���� 
	int mon, day, hou, min; // �£��գ�ʱ���� 
	int flag; // 1Ϊon-line��0Ϊoff-line 
};

const int maxn = 1010;
record r[maxn]; 

// �ȽϺ��� 
bool cmp(record a, record b)
{
	// ������ͬ����ĸ�����У�������ͬ��ʱ���Ⱥ����� 
	if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	else if (a.day != b.day) return a.day < b.day; 
	else if (a.hou != b.hou) return a.hou < b.hou;
	else return a.min < b.min;
}

int main()
{
	int rate[24]; // ÿСʱ���� 
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
	}
	
	int n;
	char flag[10]; // on-line��off-line 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { // ����n��ͨ����¼ 
		scanf("%s %d:%d:%d:%d %s", 
			r[i].name, &r[i].mon, &r[i].day, &r[i].hou, &r[i].min, flag);
		if (!strcmp(flag, "on-line")) r[i].flag = 1;
		else if (!strcmp(flag, "off-line")) r[i].flag = 0;
	}
	
	sort(r, r + n, cmp); // ���� 
	
	int total = 0; // �ͻ�ÿ���ܻ��� 
	for(int i = 0; i < n; i++) {
		if (!strcmp(r[i].name, r[i + 1].name)) { // ������ͬ 
			// on-line��off-line���
			if (r[i].flag == 1 && r[i + 1].flag == 0) { 
				// ��һ����Чͨ��������ͻ��������·ݣ��ڶ����򲻱������ 
				if (!total) printf("%s %02d\n", r[i].name, r[i].mon);
				
				// ����ü�¼ͨ����ֹʱ�䣬����2λ��0���� 
				printf("%02d:%02d:%02d ", r[i].day, r[i].hou, r[i].min); 
				printf("%02d:%02d:%02d ", r[i+1].day, r[i+1].hou, r[i+1].min);
				
				int minute = 0, bill = 0; // ������������ 
				// ��1����¼���������ϼ�1ֱ�����2����¼ʱ�����
				// ���ɵõ�����ͨ��ʱ����ͬʱ�������Ӧ���� 
				while (r[i].day < r[i + 1].day 
					|| r[i].hou < r[i + 1].hou || r[i].min < r[i + 1].min) {
					r[i].min++;
					minute++;
					bill += rate[r[i].hou]; // �÷�������Сʱ����εĻ��� 
					if (r[i].min == 60) { // ����������60 
						r[i].hou++; // Сʱ��1 
						r[i].min = 0; // ���ӹ�0 
					}
					if (r[i].hou == 24) { // Сʱ������24 
						r[i].day++; // ������1 
						r[i].hou = 0; // Сʱ��0 
					}
				}
				
				// ���ͨ��ʱ������Ԫ�ƻ��� 
				printf("%d $%.2f\n", minute, bill / 100.0);
				total += bill; // �ۼƸ����ܻ��� 
			} 
		} else { // �ܻ��Ѳ�Ϊ0�����������0 
			if (total) printf("Total amount: $%.2f\n", total / 100.0);
			total = 0;
		}
	}
	return 0;
}
