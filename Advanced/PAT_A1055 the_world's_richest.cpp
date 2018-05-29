/*
1055. The World's Richest (25)
时间限制：400 ms  内存限制：128000 kB  代码长度限制：16000 B

Description:
Forbes magazine publishes every year its list of billionaires 
based on the annual ranking of the world's wealthiest people. 
Now you are supposed to simulate this job, 
but concentrate only on the people in a certain range of ages. 
That is, given the net worths of N people, 
you must find the M richest people in a given range of their ages.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains 2 positive integers: 
N (<=10^5) - the total number of people, and K (<=10^3) - the number of queries. 
Then N lines follow, 
each contains the name (string of no more than 8 characters without space), 
age (integer in (0, 200]), 
and the net worth (integer in [-10^6, 10^6]) of a person. 
Finally there are K lines of queries, each contains three positive integers: 
M (<= 100) - the maximum number of outputs, 
and [Amin, Amax] which are the range of ages. 
All the numbers in a line are separated by a space.
Output Specification:
For each query, 
first print in a line "Case #X:" where X is the query number starting from 1. 
Then output the M richest people with their ages in the range [Amin, Amax]. 
Each person's information occupies a line, in the format
Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. 
In case there are equal worths, it must be in non-decreasing order of the ages. 
If both worths and ages are the same, 
then the output must be in non-decreasing alphabetical order of the names. 
It is guaranteed that 
there is no two persons share all the same of the three pieces of information. 
In case no one is found, output "None".
Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
 */



#include <cstdio>
#include <cstring> // strcmp函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中

struct person {
	char name[10]; // 姓名 
	int age, worth; // 年龄，价值 
};

const int maxn = 100010;
person p[maxn];

// 比较函数
bool cmp(person a, person b)
{
	if (a.worth != b.worth) return a.worth > b.worth; // 价值不等，按降序排列 
	else if (a.age != b.age) return a.age < b.age; // 价值相等，年轻者排前 
	else return strcmp(a.name, b.name) < 0; // 年龄相等，按姓名字母序排列 
}

int main()
{
	int n, k; // n个人，k组查询 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) { // 输入人物信息 
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	}
	
	sort(p, p + n, cmp); // 排序 
	
	int m, amin, amax; // 年龄段在[amin, amax]的m个富人 
	for (int i = 1; i <= k; i++) { // k组查询 
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i); 
		
		// 遍历p[]，输出至多m个年龄在[amin, amax]的人的信息 
		int j, temp = m; // 暂存m 
		for (j = 0; j < n && m > 0; j++) {
			if (p[j].age >= amin && p[j].age <= amax) {
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				m--;
			}
		}
		if (m == temp) printf("None\n"); // m未改变，即无符合者
	}
	return 0;
}



#include <cstdio>
#include <cstring> // strcmp函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中

struct person {
	char name[10]; // 姓名 
	int age, worth; // 年龄，价值 
};

const int maxn = 100010;
person p[maxn];

// 比较函数1
bool cmp1(person a, person b)
{
	return a.age < b.age; // 按年龄升序排列  
}

// 比较函数2 
bool cmp2(person a, person b)
{
	if (a.worth != b.worth) return a.worth > b.worth; // 价值不等，按降序排列 
	else if (a.age != b.age) return a.age < b.age; // 价值相等，年轻者排前 
	else return strcmp(a.name, b.name) < 0; // 年龄相等，按姓名字母序排列 
}

int main()
{
	int n, k; // n个人，k次查询 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) { // 输入人物信息 
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	}
	
	int m, amin, amax; // 年龄段在[amin, amax]的m个富人 
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &m, &amin, &amax);
		
		sort(p, p + n, cmp1); // 每次查询，均按年龄重置排序 
		
		int j = 0;
		while (j < n && p[j].age < amin) j++; // 查询年龄不小于amin的起始下标 
		int begin = j;
		
		while (j < n && p[j].age <= amax)  j++; // 查询年龄大于amax的终止下标 
		int end = j;
		
		printf("Case #%d:\n", i);
		if (begin >= end) printf("None\n"); // 起始不小于终止，即无符合者 
		else { // 起始小于终止 
			sort(p + begin, p + end, cmp2); // 对符合者排序             
			for (j = begin; j < end && m > 0; j++) { // 输出m个符合者 
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				m--;
			}
		}
	}
	return 0;
}
