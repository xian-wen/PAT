/*
1061. Dating (20)
ʱ�����ƣ�150ms  �ڴ����ƣ�64MB  ���볤�����ƣ�16KB

Description:
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:
Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:
For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

Sample Output:
THU 14:04
 */



#include <cstdio>
#include <cstring> // strlen����ͷ�ļ� 

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
	for (i = 0; i < len[0] && i < len[1]; i++) {
		if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
			printf("%s ", day[str[0][i] - 'A']); // ��д��ĸת�������� 
			break;
		}
	}
	
	// ��ǰ2���ַ��������ϴαȽϵ���һλ��������ַ��Ƚϣ��ҳ���2����ȵ��ַ� 
	for (int j = i + 1; j < len[0] && j < len[1]; j++) {
		if (str[0][j] == str[1][j]) {
			if (str[0][j] >= '0' && str[0][j] <= '9') { // ���� 
				printf("%02d:", str[0][j] - '0'); // �ַ�����ת������������
				break; 
			} else if (str[0][j] >= 'A' && str[0][j] <= 'N') { // ��д��ĸ 
				printf("%d:", str[0][j] - 'A' + 10); // ��д��ĸת�������� 
				break; 
			}
		}
	} 
	
	// �Ժ�2���ַ�����������������ַ��Ƚϣ��ҳ���һ����ȵ�Ӣ����ĸ 
	for (int j = 0; j < len[2] && j < len[3]; j++) {
		if (str[2][j] == str[3][j]) {
			if ((str[2][j] >= 'A' && str[2][j] <= 'Z')
				|| (str[2][j] >= 'a' && str[2][j] <= 'z')) {
				printf("%02d\n", j); // ��������ĸ����λ�� 
				break;
			}
		}
	}
	return 0;
}
