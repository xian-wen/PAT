/*
1032. �ھ�������ļ�ǿ(20)
ʱ�����ƣ�200 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�8000 B

��Ŀ������ 
Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT��֯��һ���ھ�����ܴ�����
��������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��

�����ʽ��
�����ڵ�1�и���������10^5��������N��������������
���N�У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ���
��������������ѧУ�ı�ţ���1��ʼ������ţ�����������ɼ����ٷ��ƣ���
�м��Կո�ָ���
�����ʽ��
��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ���
��Ŀ��֤��Ψһ��û�в��С�
����������
6
3 65
2 80
1 100
2 70
3 40
3 0
���������
2 150
 */

#include <cstdio>

const int maxn = 100010; 
int schl[maxn] = {0}; // ��¼ÿ��ѧУ�ܵ÷֣�ѧУ��ż������±꣬��ʼ��Ϊ0 

int main() 
{
	int N; // ��������N 
	scanf("%d", &N);
	
	int num, score; // ������ѧУ��ţ��ɼ� 
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &num, &score); // �����������Ϣ 
		schl[num] += score; // ͬһѧУ�ĵ÷��ۼ���һ�� 
	}
	
	int max = -1, j; // maxȡ-1����0��ҲӦ�������� 
	// ��ѧУ��1��ʼ������ţ���1��N�ڱ����ҳ��ܵ÷���ߵ�ѧУ 
	for (int i = 1; i <= N; i++) { 
		if (schl[i] > max) { 
			max = schl[i];
			j = i; // ��¼�ܵ÷������ѧУ��� 
		}
	}
	printf("%d %d\n", j, max); // ����ܵ÷���ߵ�ѧУ�ı�ź��ܷ� 
	return 0;
}