/*
1012. The Best Rank (25)
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

Description:
To evaluate the performance of our first year CS majored students,
we consider their grades of three courses only:
C - C Programming Language,
M - Mathematics (Calculus or Linear Algebra), and E - English.
At the mean time,
we encourage students by emphasizing on their best ranks -- that is,
among the four ranks with respect to the three courses and the average grade,
we print the best rank for each student.
For example,
The grades of C, M, E and A - Average of 4 students are given as the following:
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1
since the 1st one has done the best in C Programming Language,
while the 2nd one in Mathematics, the 3rd one in English,
and the last one in average.

Input:
Each input file contains one test case.
Each case starts with a line containing 2 numbers N and M (<=2000),
which are the total number of students,
and the number of students who would check their ranks, respectively.
Then N lines follow, each contains a student ID which is a string of 6 digits,
followed by the three integer grades (in the range of [0, 100])
of that student in the order of C, M and E.
Then there are M lines, each containing a student ID.
Output:
For each of the M students, print in one line the best rank for him/her,
and the symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E.
Hence if there are two or more ways for a student to obtain the same best rank,
output the one with the highest priority.
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
#include <cstring> // strcmp����ͷ�ļ� 
#include <algorithm> // sort����ͷ�ļ� 

using namespace std; // sort��std��

struct student {
	char id[10]; // ѧ�� 
	int c[4]; // c[0]='A', c[1]='C', c[2]='M', c[3]='E'
	int r[4]; // r[0]ΪA��������r[1]ΪC��������r[2]ΪM��������r[3]ΪE������ 
};

struct course {
	char name; // �γ�������A��C��M��E 
	int priority; // ���ȼ���AΪ0��CΪ1��MΪ2��EΪ3��ԽС���ȼ�Խ��  
	int rank; // ���ſγ����� 
};

const int maxn = 2010;
student s[maxn]; // ����гɼ���ѧ����Ϣ 
char id[maxn][10]; // ��ż����ߵ�ѧ�� 
course c[4]; // c[0]ΪA��c[1]ΪC��c[2]ΪM��c[3]ΪE 

// A�ıȽϺ��� 
bool cmp_A(student a, student b)
{
	return a.c[0] > b.c[0]; // ��A�Ӵ�С���� 
}

// C�ıȽϺ��� 
bool cmp_C(student a, student b)
{
	return a.c[1] > b.c[1]; // ��C�Ӵ�С����
}

// M�ıȽϺ��� 
bool cmp_M(student a, student b)
{
	return a.c[2] > b.c[2]; // ��M�Ӵ�С����
}

// E�ıȽϺ��� 
bool cmp_E(student a, student b)
{
	return a.c[3] > b.c[3]; // ��E�Ӵ�С����
}

// ��������ȽϺ��� 
bool cmp_best(course a, course b)
{
	if (a.rank != b.rank) return a.rank < b.rank; // �������ȣ�����С����ǰ 
	else return a.priority < b.priority; // ������ȣ����ȼ�С����ǰ 
}

int main()
{
	int n, m; // �гɼ���ѧ��������ɼ���ѧ���� 
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) { // ����ѧ��ѧ�š����Ƴɼ���ƽ���ɼ� 
		scanf("%s%d%d%d", s[i].id, &s[i].c[1], &s[i].c[2], &s[i].c[3]);
		s[i].c[0]= (s[i].c[1] + s[i].c[2] + s[i].c[3]) / 3.0 + 0.5;
	}
	
	// ��A����������¼��r[0]�� 
	sort(s, s + n, cmp_A);  
	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[0] != s[i - 1].c[0]) {
			rank = i + 1;
		}
		s[i].r[0] = rank;
	}
	
	// ��C����������¼��r[1]�� 
	sort(s, s + n, cmp_C); 
	rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[1] != s[i - 1].c[1]) {
			rank = i + 1;
		}
		s[i].r[1] = rank;
	}
	
	// ��M����������¼��r[2]�� 
	sort(s, s + n, cmp_M); 
	rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[2] != s[i - 1].c[2]) {
			rank = i + 1;
		}
		s[i].r[2] = rank;
	}
	
	// ��E����������¼��r[3]�� 
	sort(s, s + n, cmp_E); 
	rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i].c[3] != s[i - 1].c[3]) {
			rank = i + 1;
		}
		s[i].r[3] = rank;
	}
	
	// ��ѧ��������飬�����ÿ��ѧ����������γ� 
	for (int i = 0; i < m; i++) { 
		scanf("%s", id[i]); // �������ѧ�� 
		
		int j = 0;
		while (j < n && strcmp(id[i], s[j].id)) j++; // ����ѧ����Ϣ 
		
		if (j == n) printf("N/A\n"); // ���޴�ѧ�� 
		else { // �ҵ���ѧ�� 
			c[0].name = 'A'; // ���γ��� 
			c[1].name = 'C'; 
			c[2].name = 'M'; 
			c[3].name = 'E'; 
			
			c[0].priority = 0; // ���γ����ȼ� 
			c[1].priority = 1; 
			c[2].priority = 2; 
			c[3].priority = 3; 
			
			c[0].rank = s[j].r[0]; // ���γ����� 
			c[1].rank = s[j].r[1];
			c[2].rank = s[j].r[2];
			c[3].rank = s[j].r[3];
			
			sort(c, c + 4, cmp_best); // ���������� 
			
			printf("%d %c\n", c[0].rank, c[0].name); // �����������γ�
		}
	}
	return 0;
}
