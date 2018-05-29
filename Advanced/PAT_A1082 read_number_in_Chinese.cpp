/*
1082. Read Number in Chinese (25)
ʱ�����ƣ�400ms  �ڴ����ƣ�64MB  ���볤�����ƣ�16KB

Description:
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:
For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789

Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu

Sample Input 2:
100800

Sample Output 2:
yi Shi Wan ling ba Bai
 */



#include <cstdio>
#include <cstring> // strlen��strcat����ͷ�ļ� 

char digit[10][5] = { // digit[1]="yi", digit[2]="er"...
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

char pos[10][5] = { // pos[1]="Shi", pos[2]="Bai"...
	"Ge", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"
};

// ��ת�ַ���str[]
void reverse(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

int main()
{
	char str[20], ans[20][20]; // �����������Ž��
	gets(str); // �����ַ���
	int len = strlen(str); // ��ȡ�ַ�������
	if (str[0] == '-') { // ����
		printf("Fu "); // �����Fu�Ϳո�
		len--; // ������ȥ����
	}
	reverse(str); // ��ת�ַ���

	int num = 0; // ans���ַ�������
	bool zero = true; // 0�ַ����жϣ����Դ���ling�ķ���
	for (int i = 0; i < len; i++) { // �����ַ���
		if (str[i] != '0') { // �����ַ�
			// iΪ3��7���⣬��Qian֮ǰ��ling������
			if ((i + 1) % 4) zero = false; // ���������ַ���Ϊfalse

			if (i > 0) { // ʮλ������
				strcpy(ans[num], pos[i]); // ��Ӧλ��ƴ������ans��

				// ʮ�򡢰���ǧ�������ƴ����������Ӧλ�ĺ���
				if ((i == 5 && str[i - 1] == '0')
				        || (i == 6 && str[i - 1] == '0' && str[i - 2] == '0')
				        || (i == 7 && str[i - 1] == '0' && str[i - 2] == '0'
				            && str[i - 3] == '0')) {
					strcat(ans[num], " Wan");
				}
				num++; // numָ����һλ
			}

			// �����ַ�ת����ƴ���ַ���������ans��
			strcpy(ans[num++], digit[str[i] - '0']);
		} else { // ���ַ�
			if (!zero) { // ֮ǰ�з����ַ�
				strcpy(ans[num++], "ling"); // ling����ans��
				zero = true; // zero���ã��Ա�����
			}
		}
	}

	if (len == 1 && str[0] == '0') { // 0����
		printf("ling");
	} else { // ��0
		for (int i = num - 1; i >= 0; i--) { // �������ans
			printf("%s", ans[i]);
			if (i) printf(" "); // �м��пո�ĩβ�޿ո�
		}
	}
	return 0;
}
