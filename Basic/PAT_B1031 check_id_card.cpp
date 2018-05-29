/*
1031. 查验身份证(15)
时间限制：200 ms  内存限制：65536 kB  代码长度限制：8000 B

题目描述：
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。
校验码的计算规则如下：
首先对前17位数字加权求和，
权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；
然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：
Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

输入格式：
输入第一行给出正整数N（<= 100）是输入的身份证号码的个数。
随后N行，每行给出1个18位身份证号码。
输出格式：
按照输入的顺序每行输出1个有问题的身份证号码。
这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。
如果所有号码都正常，则输出“All passed”。
输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：All passed
 */



#include <cstdio>

const int maxn = 110;

// 身份证前17位数字对应权重 
int weight[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
// z为数组下标，值为校验码 
char m[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
	char id[20]; // 身份证号 
	int N;
	scanf("%d", &N); // 身份证号个数 
	getchar(); // 吸收末尾空格 
	
	bool flag = true; // 假设身份证号全部正确 
	while (N--) {
		gets(id); // 输入身份证号 
		
		int i, z = 0; // 每次循环均需初始化 
		for (i = 0; i < 17; i++) {
			if (!(id[i] >= '0' && id[i] <= '9')) break; // 非数字 
			z += (id[i] - '0') * weight[i]; //加权求和 
		}
		
		// 非数字存在，或者校验码不等于身份证号第18位 
		if (i < 17 || (i = 17 && m[z % 11] != id[17])) { 
			puts(id); // 输出问题身份证号 
			flag = false; // 一个号有问题，flag即置为false 
		}
	}
	
	if (flag) printf("All passed\n"); // 全部没问题 
	return 0;
}
