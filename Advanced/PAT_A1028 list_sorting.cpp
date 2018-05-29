/*
1028. List Sorting (25)
时间限制：200 ms  内存限制：65536 kB  代码长度限制：16000 B

Description:
Excel can sort records according to any column. 
Now you are supposed to imitate this function.

Input:
Each input file contains one test case. For each case, 
the first line contains two integers N (<=100000) and C, 
where N is the number of records 
and C is the column that you are supposed to sort the records with. 
Then N lines follow, each contains a record of a student. 
A student's record consists of his or her distinct ID (a 6-digit number), 
name (a string with no more than 8 characters without space), 
and grade (an integer between 0 and 100, inclusive).
Output:
For each test case, output the sorting result in N lines. That is, 
if C = 1 
then the records must be sorted in increasing order according to ID's; 
if C = 2 
then the records must be sorted in non-decreasing order according to names; 
and if C = 3 
then the records must be sorted in non-decreasing order according to grades. 
If there are several students who have the same name or grade, 
they must be sorted according to their ID's in increasing order.
Sample Input 1:
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1:
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2:
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2:
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3:
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3:
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
 */



#include <cstdio>
#include <cstring> // strcmp函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中

struct student {
	int id; // 学号 
	char name[10]; // 姓名 
	int grade; // 成绩 
}; 

const int maxn = 100010;
student stu[maxn];

int c; // 第几列 

// 比较函数 
bool cmp(student a, student b)
{
	switch (c) {
	case 1: // 按第1列，学号升序排序 
		return a.id < b.id;
		break;
	case 2: // 按第2列，姓名不同按字母序排列，相同按学号升序排列 
		if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
		else return a.id < b.id;
		break;
	default: // 按第3列，成绩不同按升序排列，相同按学号升序排列 
	         // 此处若写成case 3，则会出现编译错误 
		if (a.grade != b.grade) return a.grade < b.grade;
		else return a.id < b.id;
		break;
	}
}

int main()
{
	int n;
	scanf("%d%d", &n, &c); // n个学生，第c列 
	for(int i = 0; i < n; i++) { // 输入 
		scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
	}
	
	sort(stu, stu + n, cmp); // 排序 
	
	for (int i = 0; i < n; i++) { // 输出 
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
