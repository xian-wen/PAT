/*
1048. 数字加密(20)
时间限制：400 ms  内存限制：65536 kB  代码长度限制：8000 B

题目描述：
本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，
将其每1位数字与A的对应位置上的数字进行以下运算：
对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；
对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
输出格式：在一行中输出加密后的结果。
输入样例：1234567 368782971
输出样例：3695Q8118
 */



#include <cstdio>
#include <cstring> // strlen函数头文件 

const int maxn = 110;

char digital[13] = { // digital[10]='J', digital[11]='Q', digital[12]='K'
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'
}; 

int main()
{
	char a[maxn], b[maxn], c[maxn] = {0}; // 加密用数a，数b，c存放结果 
	scanf("%s %s", a, b); // 输入 
	
	int lena = strlen(a); // 求字符串长度 
	int lenb = strlen(b);
	int len = lena > lenb ? lena : lenb; // len取大者
	
	// 将a、b中不匹配部分以0补齐 
	if (lena < lenb) { // b比a大 
		for (int i = lena - 1; i >= 0; i--) // a中所有元素右移lenb-lena位 
			a[i + lenb - lena] = a[i];
			
		for (int i = 0; i < lenb - lena; i++) // 以0补齐左端空缺位置 
			a[i] = '0';
	} else if (lena > lenb) { // a比b大 
		for (int i = lenb - 1; i >= 0; i--) // b中所有元素右移lena-lenb位 
			b[i + lena - lenb] = b[i];
		
		for (int i = 0; i < lena - lenb; i++) // 以0补齐左端空缺位置
			b[i] = '0';
	}
	
	for (int i = len - 1; i >= 0; i -= 2) { // 从右数第1位开始 
		// 字符型转整型后再计算
		c[i] = digital[((a[i] - '0') + (b[i] - '0')) % 13];
	}	
	
	for (int i = len - 2; i >= 0; i -= 2) { // 右数第2位开始 
		int temp = (b[i] - '0') - (a[i] - '0'); // 字符型转整型后再计算
		if (temp < 0)  temp += 10; // 差为负 
		c[i] = temp + '0'; // 整型转字符型
	}
	
	printf("%s\n", c); // 输出c
	return 0;
}
