/*
1001. A+B Format (20)
时间限制：400 ms  内存限制：65536 kB  代码长度限制：16000 B

Description:
Calculate a + b and output the sum in standard format -- 
that is, the digits must be separated into groups of three by commas 
(unless there are less than four digits).

Input: 
Each input file contains one test case. 
Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. 
The numbers are separated by a space.
Output:
For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.
Sample Input:
-1000000 9
Sample Output:
-999,991
 */



#include <cstdio>

int main()
{
	int a, b, sum;
	scanf("%d%d", &a, &b);
	
	sum = a + b; 
	if (sum < 0) { // 和为负 
		printf("-"); // 输出负号 
		sum = -sum; // 取绝对值 
	}
	
	char ans[10]; // 存放格式化的和 
	int num = 0;
	do {
		ans[num] = sum % 10 + '0'; // 获取个位，转换成字符后再存放 
		sum /= 10; // 去除个位 
		num++; // num右移 
		
		// 下标为num，表示第num+1位，逗号间隔3位数字，即第4、8位 
		if ((num + 1) % 4 == 0 && sum > 0) { // sum为正 
			ans[num] = ','; // 输出逗号 
			num++; // num右移 
		} 
	} while (sum); // sum不为0循环继续 
	
	for (int i = num - 1; i >= 0; i--) { // 逆序输出 
		printf("%c", ans[i]);
	} 
	return 0;
}
