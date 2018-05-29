/*
1077. Kuchiguse (20)
ʱ�����ƣ�100 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

Description:
The Japanese language is notorious for its sentence ending particles. 
Personal preference of such particles can be considered 
as a reflection of the speaker's personality. 
Such a preference is called "Kuchiguse" 
and is often exaggerated artistically in Anime and Manga. 
For example, the artificial sentence ending particle "nyan~" 
is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:
Each input file contains one test case. 
For each case, the first line is an integer N (2<=N<=100). 
Following are N file lines of 0~256 (inclusive) characters in length, 
each representing a character's spoken line. 
The spoken lines are case sensitive.
Output Specification:
For each test case, print in one line the kuchiguse of the character, i.e., 
the longest common suffix of all N lines. 
If there is no such suffix, write "nai".
Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1: nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2: nai
 */



#include <cstdio>
#include <cstring> // strlen����ͷ�ļ� 

// �ַ�����ת 
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
	int n;
	scanf("%d", &n);
	getchar(); // ���տո� 
	
	char str[110][260], suf[260]; // ���n���ַ����������ͬ��׺ 
	gets(str[0]); // �����ַ��� 
	gets(str[1]); 
	
	int len0 = strlen(str[0]); // ���ַ������� 
	int len1 = strlen(str[1]);  
	int len = len0 < len1 ? len0 : len1; // lenȡС�� 
	
	reverse(str[0]); // ��ת�ַ��� 
	reverse(str[1]);
	
	for (int i = 0; i < len; i++) { // �������ַ��� 
		if (str[0][i] == str[1][i]) { // ƥ�� 
			suf[i] = str[0][i];
		} else break; // ���ֵ�һ����ƥ���ַ����˳� 
	}
	
	int len_suf = strlen(suf); // ���׺���� 
	
	if (n > 2 && len_suf) { // �ַ���������2�Һ�׺���� 
		for (int i = 2; i < n; i++) {  
			gets(str[i]); // ��������ַ���
			int leni = strlen(str[i]);  
			len = leni < len_suf ? leni : len_suf; // ����len����ֹ����Խ��
			reverse(str[i]); 
			
			// �ж��ַ���ͬ��׺�Ƿ�ƥ��
			for (int j = 0; j < len; j++) { // �������ַ���
				if (str[i][j] != suf[j]) { // ��ƥ�� 
					suf[j] = '\0'; // �Խ�����־���º�׺ 
					break; // �˳�ѭ�� 
				}
			}
			
			len_suf = strlen(suf); // ���º�׺���� 
			if (len_suf == 0) break; // ��׺�������˳�ѭ�� 
		}
	}
	
	if (len_suf) { // ���ں�׺ 
		reverse(suf); // ��ת��׺ 
		puts(suf); // �����׺ 
	} else { // ��׺������ 
		puts("nai");
	}
	return 0;
}
