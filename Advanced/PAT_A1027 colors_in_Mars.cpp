/*
1027. Colors in Mars (20)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input:
Each input file contains one test case which occupies a line containing the three decimal color values.

Output:
For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.

Sample Input:
15 43 71

Sample Output:
#123456
 */



#include <cstdio>

int main()
{
	char c[13] = { // 建立0-13与'0'-'9'、'A'、'B'、'C'对应关系 
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'
	};
	
	for (int i = 0; i < 3; i++) { // 循环3次 
		int n;
		scanf("%d", &n);
		
		int a[2], num = 0; // num每次循环均需初始化 
		do {
			a[num++] = n % 13; // 除基取余 
			n /= 13;
		} while (n); // 商不为0循环继续 
		
		if (i == 0) printf("#"); // R之前加上#号 
		printf("%c%c", c[a[1]], c[a[0]]); // 根据进制转换后的数字输出相应字符 
	}
	return 0; 
}
