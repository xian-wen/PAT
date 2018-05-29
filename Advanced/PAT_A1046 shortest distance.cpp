/*
1046. Shortest Distance (20)
ʱ�����ƣ�100 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

Description:
The task is really simple: 
given N exits on a highway which forms a simple cycle, 
you are supposed to tell the shortest distance between any pair of exits.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains an integer N (in [3, 10^5]), 
followed by N integer distances D1 D2 ... DN, 
where Di is the distance between the i-th and the (i+1)-st exits, 
and DN is between the N-th and the 1st exits. 
All the numbers in a line are separated by a space. 
The second line gives a positive integer M (<=10^4), 
with M lines follow, each contains a pair of exit numbers, 
provided that the exits are numbered from 1 to N. 
It is guaranteed that the total round trip distance is no more than 10^7.
Output Specification:
For each test case, print your results in M lines, each contains 
the shortest distance between the corresponding given pair of exits.
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
 */



#include <cstdio>

const int N = 100010;
int dis[N]; // dis[i]��ʾ����1˳ʱ�뵽i+1�ľ��� 
int dis12[N]; // dis12[i]��ʾ����i��i+1�ľ��� 
 
int main()
{
	int n, round = 0; // �����������ܵ��ܳ� 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dis12[i]);
		round += dis12[i]; // �ۼ��ܳ� 
		dis[i] = round; // Ԥ����dis���� 
	}
	
	int m, exit1, exit2;
	scanf("%d", &m); // m������ 
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &exit1, &exit2); // �������ں� 
		if (exit1 > exit2) { // ����ʹǰ��С�ں��� 
			int temp = exit1;
			exit1 = exit2;
			exit2 = temp;
		}
		int dis12 = dis[exit2 - 1] - dis[exit1 - 1]; // �����ڼ�ľ��� 
		dis12 = dis12 < (round - dis12) ? dis12 : (round - dis12); // ��̾��� 
		printf("%d\n", dis12);
	}
	return 0;
}
