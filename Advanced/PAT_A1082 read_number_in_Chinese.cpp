/*
1082. Read Number in Chinese (25)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

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
#include <cstring> // strlen、strcat函数头文件 

char digit[10][5] = { // digit[1]="yi", digit[2]="er"...
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

char pos[10][5] = { // pos[1]="Shi", pos[2]="Bai"...
	"Ge", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"
};

// 反转字符串str[]
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
	char str[20], ans[20][20]; // 存放整数，存放结果
	gets(str); // 输入字符串
	int len = strlen(str); // 获取字符串长度
	if (str[0] == '-') { // 负数
		printf("Fu "); // 先输出Fu和空格
		len--; // 串长舍去负号
	}
	reverse(str); // 反转字符串

	int num = 0; // ans中字符串个数
	bool zero = true; // 0字符的判断，用以处理ling的发音
	for (int i = 0; i < len; i++) { // 遍历字符串
		if (str[i] != '0') { // 非零字符
			// i为3、7除外，因Qian之前的ling不发音
			if ((i + 1) % 4) zero = false; // 遇到非零字符置为false

			if (i > 0) { // 十位及以上
				strcpy(ans[num], pos[i]); // 对应位的拼音存于ans中

				// 十万、百万、千万中万的拼音连接在相应位的后面
				if ((i == 5 && str[i - 1] == '0')
				        || (i == 6 && str[i - 1] == '0' && str[i - 2] == '0')
				        || (i == 7 && str[i - 1] == '0' && str[i - 2] == '0'
				            && str[i - 3] == '0')) {
					strcat(ans[num], " Wan");
				}
				num++; // num指向下一位
			}

			// 数字字符转换成拼音字符串，存于ans中
			strcpy(ans[num++], digit[str[i] - '0']);
		} else { // 零字符
			if (!zero) { // 之前有非零字符
				strcpy(ans[num++], "ling"); // ling存于ans中
				zero = true; // zero重置，以备后用
			}
		}
	}

	if (len == 1 && str[0] == '0') { // 0特判
		printf("ling");
	} else { // 非0
		for (int i = num - 1; i >= 0; i--) { // 逆序输出ans
			printf("%s", ans[i]);
			if (i) printf(" "); // 中间有空格，末尾无空格
		}
	}
	return 0;
}
