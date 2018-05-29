/*
1025. PAT Ranking (25)
ʱ�����ƣ�200 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

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
#include <cstring> // strcmp����ͷ�ļ� 
#include <algorithm> // sort����ͷ�ļ� 

using namespace std; // sort��std�� 

struct testee {
	char reg_num[15]; // ע��� 
	int loc_num; // ����� 
	int score; // ���� 
	int local_r; // �������� 
	int final_r; // �������� 
};

const int maxn = 30010; // ��С��100 * 300 
testee t[maxn]; 

// �ȽϺ��� 
bool cmp(testee a, testee b)
{
	// �������Ȱ������Ӵ�С���򣬷�����Ȱ�ע��Ŵ�С�������� 
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.reg_num, b.reg_num) < 0;
}

int main()
{
	int n, k, num = 0; // ��������ÿ�����㿼�������ܹ������� 
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) { // n������ 
		scanf("%d", &k); // ÿ������k������ 
		
		for (int j = 0; j < k; j++) {
			scanf("%s %d", &t[num].reg_num, &t[num].score); // ���뿼����Ϣ 
			t[num].loc_num = i + 1; // ����� 
			num++; // ��������1 
		}
		
		sort(t + num - k, t + num, cmp); // ��ÿ�����㿼������
		
		// ���������ڿ�������� 
		int rank = 1;
		for (int j = num - k; j < num; j++) {
			// �Ǹÿ����һ�������ҷ�������һ������������ 
			if (j > 0 && t[j].score != t[j - 1].score) {
				rank = j - (num - k) + 1;
			}
			t[j].local_r = rank; // ���濼���������� 
		}
	}
	
	sort(t, t + num, cmp); // �����п������� 
	
	// �������������� 
	int rank = 1;
	for (int i = 0; i < num; i++) {
		// �ǵ�һ�������ҷ�������һ������������ 
		if (i > 0 && t[i].score != t[i - 1].score) {
			rank = i + 1;
		}
		t[i].final_r = rank; // ���濼���������� 
	}
	
	printf("%d\n", num); // ����ܹ������� 
	for (int i = 0; i < num; i++) { // ���������������� 
		printf("%s %d %d %d\n", t[i].reg_num, t[i].final_r, 
			t[i].loc_num, t[i].local_r);
	}
	return 0;
}
