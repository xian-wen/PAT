/*
1025. PAT Ranking (25)
时间限制：200 ms  内存限制：65536 kB  代码长度限制：16000 B

Description:
Programming Ability Test (PAT) is organized by the College of Computer Science 
and Technology of Zhejiang University. 
Each test is supposed to run simultaneously in several places, 
and the ranklists will be merged immediately after the test. 
Now it is your job to write a program to correctly merge all the ranklists 
and generate the final rank.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains a positive number N (<=100), 
the number of test locations. Then N ranklists follow, 
each starts with a line containing a positive integer K (<=300), 
the number of testees, and then K lines containing the registration number 
(a 13-digit number) and the total score of each testee. 
All the numbers in a line are separated by a space.
Output Specification:
For each test case, first print in one line the total number of testees. 
Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. 
The output must be sorted in nondecreasing order of the final ranks. 
The testees with the same score must have the same rank, 
and the output must be sorted 
in nondecreasing order of their registration numbers.
Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
 */
 
 
 
#include <cstdio>
#include <cstring> // strcmp函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中 

struct testee {
	char reg_num[15]; // 注册号 
	int loc_num; // 考点号 
	int score; // 分数 
	int local_r; // 考点排名 
	int final_r; // 最终排名 
};

const int maxn = 30010; // 不小于100 * 300 
testee t[maxn]; 

// 比较函数 
bool cmp(testee a, testee b)
{
	// 分数不等按分数从大到小排序，分数相等按注册号从小到大排序 
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.reg_num, b.reg_num) < 0;
}

int main()
{
	int n, k, num = 0; // 考点数，每个考点考生数，总共考生数 
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) { // n个考点 
		scanf("%d", &k); // 每个考点k个考生 
		
		for (int j = 0; j < k; j++) {
			scanf("%s %d", &t[num].reg_num, &t[num].score); // 输入考生信息 
			t[num].loc_num = i + 1; // 考点号 
			num++; // 考生数加1 
		}
		
		sort(t + num - k, t + num, cmp); // 对每个考点考生排序
		
		// 求考生在所在考点的排名 
		int rank = 1;
		for (int j = num - k; j < num; j++) {
			// 非该考点第一个考生且分数和上一考生分数不等 
			if (j > 0 && t[j].score != t[j - 1].score) {
				rank = j - (num - k) + 1;
			}
			t[j].local_r = rank; // 保存考生考点排名 
		}
	}
	
	sort(t, t + num, cmp); // 对所有考生排序 
	
	// 求考生的最终排名 
	int rank = 1;
	for (int i = 0; i < num; i++) {
		// 非第一个考生且分数和上一考生分数不等 
		if (i > 0 && t[i].score != t[i - 1].score) {
			rank = i + 1;
		}
		t[i].final_r = rank; // 保存考生最终排名 
	}
	
	printf("%d\n", num); // 输出总共考生数 
	for (int i = 0; i < num; i++) { // 输出考生总排名情况 
		printf("%s %d %d %d\n", t[i].reg_num, t[i].final_r, 
			t[i].loc_num, t[i].local_r);
	}
	return 0;
}
