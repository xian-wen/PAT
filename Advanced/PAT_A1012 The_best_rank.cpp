/*
1012. The Best Rank (25)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91

Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input:
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output:
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.
If a student is not on the grading list, simply output "N/A".

Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
 */



#include <cstdio>
#include <cstring> // strcmp函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中

struct student {
	char id[10]; // 学号 
	int c[4]; // c[0]='A', c[1]='C', c[2]='M', c[3]='E'
	int r[4]; // r[0]为A的排名，r[1]为C的排名，r[2]为M的排名，r[3]为E的排名 
};

struct course {
	char name; // 课程名，如A、C、M、E 
	int priority; // 优先级，A为0，C为1，M为2，E为3，越小优先级越高  
	int rank; // 该门课程排名 
};

const int maxn = 2010;
student s[maxn]; // 存放有成绩的学生信息 
char id[maxn][10]; // 存放检验者的学号 
course c[4]; // c[0]为A，c[1]为C，c[2]为M，c[3]为E 

// A的比较函数 
bool cmp_A(student a, student b)
{
	return a.c[0] > b.c[0]; // 按A从大到小排列 
}

// C的比较函数 
bool cmp_C(student a, student b)
{
	return a.c[1] > b.c[1]; // 按C从大到小排列
}

// M的比较函数 
bool cmp_M(student a, student b)
{
	return a.c[2] > b.c[2]; // 按M从大到小排列
}

// E的比较函数 
bool cmp_E(student a, student b)
{
	return a.c[3] > b.c[3]; // 按E从大到小排列
}

// 最佳排名比较函数 
bool cmp_best(course a, course b)
{
	if (a.rank != b.rank) return a.rank < b.rank; // 排名不等，排名小者在前 
	else return a.priority < b.priority; // 排名相等，优先级小者在前 
}

int main()
{
	int n, m; // 有成绩者学生数，查成绩者学生数 
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) { // 输入学生学号、各科成绩及平均成绩 
		scanf("%s%d%d%d", s[i].id, &s[i].c[1], &s[i].c[2], &s[i].c[3]);
		s[i].c[0]= (s[i].c[1] + s[i].c[2] + s[i].c[3]) / 3.0 + 0.5;
	}
	
	// 按A排序，排名记录于r[0]中 
	sort(s, s + n, cmp_A);  
	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[0] != s[i - 1].c[0]) {
			rank = i + 1;
		}
		s[i].r[0] = rank;
	}
	
	// 按C排序，排名记录于r[1]中 
	sort(s, s + n, cmp_C); 
	rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[1] != s[i - 1].c[1]) {
			rank = i + 1;
		}
		s[i].r[1] = rank;
	}
	
	// 按M排序，排名记录于r[2]中 
	sort(s, s + n, cmp_M); 
	rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[2] != s[i - 1].c[2]) {
			rank = i + 1;
		}
		s[i].r[2] = rank;
	}
	
	// 按E排序，排名记录于r[3]中 
	sort(s, s + n, cmp_E); 
	rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[3] != s[i - 1].c[3]) {
			rank = i + 1;
		}
		s[i].r[3] = rank;
	}
	
	// 按学号逐个检验，并输出每个学生最佳排名课程 
	for (int i = 0; i < m; i++) { 
		scanf("%s", id[i]); // 输入待检学号 
		
		int j = 0;
		while (j < n && strcmp(id[i], s[j].id)) j++; // 遍历学号信息 
		
		if (j == n) printf("N/A\n"); // 查无此学号 
		else { // 找到该学号 
			c[0].name = 'A'; // 各课程名 
			c[1].name = 'C'; 
			c[2].name = 'M'; 
			c[3].name = 'E'; 
			
			c[0].priority = 0; // 各课程优先级 
			c[1].priority = 1; 
			c[2].priority = 2; 
			c[3].priority = 3; 
			
			c[0].rank = s[j].r[0]; // 各课程排名 
			c[1].rank = s[j].r[1];
			c[2].rank = s[j].r[2];
			c[3].rank = s[j].r[3];
			
			sort(c, c + 4, cmp_best); // 按排名排序 
			
			printf("%d %c\n", c[0].rank, c[0].name); // 输出最佳排名课程
		}
	}
	return 0;
}
