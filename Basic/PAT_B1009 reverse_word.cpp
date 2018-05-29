/*
1009. 说反话 (20)
时间限制：400 ms  内存限制：65536 kB  代码长度限制：8000 B

题目描述：
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。
字符串由若干单词和若干空格组成，
其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，
输入保证句子末尾没有多余的空格。
输出格式：每个测试用例的输出占一行，输出倒序后的句子。
输入样例：Hello World Here I Come
输出样例：Come I Here World Hello
 */



#include <cstdio>
#include <cstring> // strlen函数头文件 

const int maxn = 85;

int main()
{
	char str[maxn];
	gets(str); // 输入字符串 
	int len = strlen(str), count = 0; // 字符串长度，单词字母数 
	
	for (int i = len - 1; i >= 0; i--) { // 从后往前遍历 
		if (str[i] != ' ') { // 统计单词字母数 
			count++;
		} else { // 遇到空格，说明该单词结束 
			for (int j = 0; j < count; j++) { // 输出空格后的单词 
				printf("%c", str[i + 1 + j]);
			}
			printf(" "); // 输出空格 
			count = 0; // 单词统计清零，以备后续使用 
		}
	}
	
	for (int i = 0; i < count; i++) { // 第一个单词前面无空格，单独输出 
		printf ("%c", str[i]);
	}
	return 0;
}
