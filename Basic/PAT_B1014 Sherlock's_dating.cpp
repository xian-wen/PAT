/*
1014. ����Ħ˹��Լ�� (20)
ʱ�����ƣ�100 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�8000 B

��Ŀ������
����̽����Ħ˹�ӵ�һ����ֵ�������
������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04����
��Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'��
���������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ��
����һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
�������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ�������4���ӡ�
�ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����
�����ʽ��
��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д��
��MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�
FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣
����������
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
���������THU 14:04
 */



#include <cstdio>
#include <cstring> // strlen����ͷ�ļ� 

#define min(a, b) ((a) < (b)) ? (a) : (b) // �Ƚ��������е���Сֵ 

// �������������ڼ�Ĺ�ϵ����day[0] = "MON", day[1] = "TUE"...
char day[10][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	char str[4][65]; // 4���ַ��� 
	int len[4]; // ���ַ������� 
	for (int i = 0; i < 4; i++) { // �����ַ��������䳤�� 
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
	}
	
	int i; // ��ǰ2���ַ�����������������ַ��Ƚϣ��ҳ���1����ȵĴ�д��ĸ 
	for (i = 0; i < min(len[0], len[1]); i++) {
		if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
			printf("%s ", day[str[0][i] - 'A']); // ��д��ĸת�������� 
			break;
		}
	}
	
	// ��ǰ2���ַ��������ϴαȽϵ���һλ��������ַ��Ƚϣ��ҳ���2����ȵ��ַ� 
	for (int j = i + 1; j < min(len[0], len[1]); j++) {
		if (str[0][j] == str[1][j]) {
			if (str[0][j] >= '0' && str[0][j] <= '9') { // ���� 
				printf("%02d:", str[0][j] - '0'); // �ַ�����ת������������
				break;
			} 
			if (str[0][j] >= 'A' && str[0][j] <= 'N') { // ��д��ĸ 
				printf("%d:", str[0][j] - 'A' + 10); // ��д��ĸת��������
				break; 
			}
		}
	} 
	
	// �Ժ�2���ַ�����������������ַ��Ƚϣ��ҳ���һ����ȵ�Ӣ����ĸ 
	for (int j = 0; j < min(len[2], len[3]); j++) {
		if (str[2][j] == str[3][j] 
			&& ((str[2][j] >= 'A' && str[2][j] <= 'Z')
				|| (str[2][j] >= 'a' && str[2][j] <= 'z'))) {
			printf("%02d\n", j); // ��������ĸ����λ�� 
			break;
		}
	}
	return 0;
}