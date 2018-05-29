/*
1055. The World's Richest (25)
ʱ�����ƣ�400 ms  �ڴ����ƣ�128000 kB  ���볤�����ƣ�16000 B

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
#include <cstring> // strcmp����ͷ�ļ� 
#include <algorithm> // sort����ͷ�ļ� 

using namespace std; // sort��std��

struct person {
	char name[10]; // ���� 
	int age, worth; // ���䣬��ֵ 
};

const int maxn = 100010;
person p[maxn];

// �ȽϺ���
bool cmp(person a, person b)
{
	if (a.worth != b.worth) return a.worth > b.worth; // ��ֵ���ȣ����������� 
	else if (a.age != b.age) return a.age < b.age; // ��ֵ��ȣ���������ǰ 
	else return strcmp(a.name, b.name) < 0; // ������ȣ���������ĸ������ 
}

int main()
{
	int n, k; // n���ˣ�k���ѯ 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) { // ����������Ϣ 
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	}
	
	sort(p, p + n, cmp); // ���� 
	
	int m, amin, amax; // �������[amin, amax]��m������ 
	for (int i = 1; i <= k; i++) { // k���ѯ 
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i); 
		
		// ����p[]���������m��������[amin, amax]���˵���Ϣ 
		int j, temp = m; // �ݴ�m 
		for (j = 0; j < n && m > 0; j++) {
			if (p[j].age >= amin && p[j].age <= amax) {
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				m--;
			}
		}
		if (m == temp) printf("None\n"); // mδ�ı䣬���޷�����
	}
	return 0;
}



#include <cstdio>
#include <cstring> // strcmp����ͷ�ļ� 
#include <algorithm> // sort����ͷ�ļ� 

using namespace std; // sort��std��

struct person {
	char name[10]; // ���� 
	int age, worth; // ���䣬��ֵ 
};

const int maxn = 100010;
person p[maxn];

// �ȽϺ���1
bool cmp1(person a, person b)
{
	return a.age < b.age; // ��������������  
}

// �ȽϺ���2 
bool cmp2(person a, person b)
{
	if (a.worth != b.worth) return a.worth > b.worth; // ��ֵ���ȣ����������� 
	else if (a.age != b.age) return a.age < b.age; // ��ֵ��ȣ���������ǰ 
	else return strcmp(a.name, b.name) < 0; // ������ȣ���������ĸ������ 
}

int main()
{
	int n, k; // n���ˣ�k�β�ѯ 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) { // ����������Ϣ 
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	}
	
	int m, amin, amax; // �������[amin, amax]��m������ 
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &m, &amin, &amax);
		
		sort(p, p + n, cmp1); // ÿ�β�ѯ������������������ 
		
		int j = 0;
		while (j < n && p[j].age < amin) j++; // ��ѯ���䲻С��amin����ʼ�±� 
		int begin = j;
		
		while (j < n && p[j].age <= amax)  j++; // ��ѯ�������amax����ֹ�±� 
		int end = j;
		
		printf("Case #%d:\n", i);
		if (begin >= end) printf("None\n"); // ��ʼ��С����ֹ�����޷����� 
		else { // ��ʼС����ֹ 
			sort(p + begin, p + end, cmp2); // �Է���������             
			for (j = begin; j < end && m > 0; j++) { // ���m�������� 
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				m--;
			}
		}
	}
	return 0;
}
