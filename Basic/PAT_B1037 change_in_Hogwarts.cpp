/*
1037. �ڻ����ִ�����Ǯ��20��
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�8000 B

��Ŀ������
������ǹ����������ԣ����֪��ħ�����������Լ��Ļ���ϵͳ ���� 
���纣����߹����ģ���ʮ�߸�������(Sickle)��һ����¡(Galleon)��
��ʮ�Ÿ�����(Knut)��һ�����ɣ������ס���
���ڣ���������Ӧ���ļ�ǮP����ʵ����ǮA��
���������дһ��������������Ӧ�ñ��ҵ���Ǯ��

�����ʽ��
������1���зֱ����P��A����ʽΪ��Galleon.Sickle.Knut���������1���ո�ָ���
����Galleon��[0, 10^7]�����ڵ�������Sickle��[0, 17)�����ڵ�������
Knut��[0, 29)�����ڵ�������
�����ʽ��
��һ������������ͬ���ĸ�ʽ�������Ӧ�ñ��ҵ���Ǯ��
�����û����Ǯ����ô�����Ӧ���Ǹ�����
��������1��10.16.27 14.1.28
�������1��3.2.1
��������2��14.1.28 10.16.27
�������2��-3.2.1
 */



#include <cstdio>

struct money {
	int g, s, k; // ��¡�����ɣ����� 
};

int main()
{
	money p, a; // Ӧ����ʵ�� 
	scanf("%d.%d.%d %d.%d.%d", &p.g, &p.s, &p.k, &a.g, &a.s, &a.k);
	
	int pk = p.g * 17 * 29 + p.s * 29 + p.k; // Ӧ��ת�������� 
	int ak = a.g * 17 * 29 + a.s * 29 + a.k; // ʵ��ת�������� 
	
	int change = ak - pk; // ���� 
	if (change < 0) { // ����Ϊ����������ţ���ȡ�� 
		printf("-"); 
		change = -change; 
	}
	
	// �������ԡ���¡.����.���ء���ʽ��� 
	printf("%d.%d.%d\n", change / 29 / 17, change / 29 % 17, change % 29);
	return 0;
}