/*
1077. Kuchiguse (20)
时间限制：100 ms  内存限制：65536 kB  代码长度限制：16000 B

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
#include <cstring> // strlen函数头文件 

// 字符串逆转 
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
	getchar(); // 吸收空格 
	
	char str[110][260], suf[260]; // 存放n个字符串，存放相同后缀 
	gets(str[0]); // 输入字符串 
	gets(str[1]); 
	
	int len0 = strlen(str[0]); // 求字符串长度 
	int len1 = strlen(str[1]);  
	int len = len0 < len1 ? len0 : len1; // len取小者 
	
	reverse(str[0]); // 反转字符串 
	reverse(str[1]);
	
	for (int i = 0; i < len; i++) { // 遍历两字符串 
		if (str[0][i] == str[1][i]) { // 匹配 
			suf[i] = str[0][i];
		} else break; // 发现第一个不匹配字符即退出 
	}
	
	int len_suf = strlen(suf); // 求后缀长度 
	
	if (n > 2 && len_suf) { // 字符串数多于2且后缀存在 
		for (int i = 2; i < n; i++) {  
			gets(str[i]); // 输入后续字符串
			int leni = strlen(str[i]);  
			len = leni < len_suf ? leni : len_suf; // 更新len，防止访问越界
			reverse(str[i]); 
			
			// 判断字符串同后缀是否匹配
			for (int j = 0; j < len; j++) { // 遍历两字符串
				if (str[i][j] != suf[j]) { // 不匹配 
					suf[j] = '\0'; // 以结束标志更新后缀 
					break; // 退出循环 
				}
			}
			
			len_suf = strlen(suf); // 更新后缀长度 
			if (len_suf == 0) break; // 后缀不存在退出循环 
		}
	}
	
	if (len_suf) { // 存在后缀 
		reverse(suf); // 反转后缀 
		puts(suf); // 输出后缀 
	} else { // 后缀不存在 
		puts("nai");
	}
	return 0;
}
