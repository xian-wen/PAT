/*
028. �˿��ղ�(20)
ʱ�����ƣ�200 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�8000 B

��Ŀ������
ĳ��������˿��ղ飬�õ���ȫ���������ա�
������д�������ҳ��������곤����������ˡ�
����ȷ��ÿ����������ڶ��ǺϷ��ģ�
����һ���Ǻ���ġ���������֪����û�г���200������ˣ���������2014��9��6�գ�
���Գ���200������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���

�����ʽ��
�����ڵ�һ�и���������N��ȡֵ��(0, 105]��
���N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ�������
�Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա�
��Ŀ��֤���곤�����������û�в��С�
�����ʽ��
��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���
����������
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
���������3 Tom John
 */



#include <cstdio>

struct birthday { // �������� 
	char name[10]; // ���� 
	int year; // �� 
	int month; // �� 
	int day; // �� 
}; 

birthday temp, max, min; // ��ʱ���ݣ����������ڣ���С�������� 

int main()
{
	int n, count = 0;
	scanf("%d", &n);
	// ��ʼ������������Ϊ1814/9/6����С��������Ϊ2014/9/6 
	max.year = 1814; 
	min.year = 2014;
	max.month = min.month = 9;
	max.day = min.day = 6;
	while (n--) {
		scanf("%s %d/%d/%d", &temp.name, &temp.year, &temp.month, &temp.day);
		// ���˳���200������պ�δ���������� 
		if (temp.year > 2014 || temp.year < 1814 
			|| (temp.year == 2014 
				&& (temp.month > 9 || (temp.month == 9 && temp.day > 6)))
			|| (temp.year == 1814 
				&& (temp.month < 9 || (temp.month == 9 && temp.day < 6)))) {
			continue;
		} else {
			// ������������ 
			if (temp.year > max.year
				|| (temp.year == max.year
					&& (temp.month > max.month 
						|| (temp.month == max.month 
							&& temp.day >= max.day)))) {
				max = temp;
			}
			// ����С�������� 
			if (temp.year < min.year
				|| (temp.year == min.year
					&& (temp.month < min.month 
						|| (temp.month == min.month 
							&& temp.day <= min.day)))) {
				min = temp;
			}
			count++; // ͳ����Ч���ո��� 
		}
	}
	
	if (count == 0) printf("0\n"); // ����Ч���գ������жϣ������ʽ���� 
	else { // ��С��������Ϊ���곤�ߣ�����������Ϊ��������
		printf("%d %s %s\n", count, min.name, max.name);
	}
	return 0;
}
