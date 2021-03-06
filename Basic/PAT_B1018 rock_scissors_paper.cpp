/*
1018. 锤子剪刀布 (20)
时间限制：100ms  内存限制：64MB  代码长度限制：16KB

题目描述：
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则：
剪刀胜布，布胜锤子，锤子胜剪刀
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第1行给出正整数N（<=10^5^），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出样例：
5 3 2
2 3 5
B B
 */



#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);
	getchar(); // 吸收换行符\n 
	
	// 甲胜中B、C、J次数，乙胜中B、C、J次数，按字母序排列 
	int countA[3] = {0}, countB[3] = {0}; 
	int A[3] = {0}; // 甲胜、平、负次数 
	while (N--) {
		char a, b;
		scanf("%c %c", &a, &b);
		getchar(); // 吸收换行符\n 
		
		if(a == 'B') {
			if (b == 'B') {
				A[1]++; // 甲平加1 
			}
			if (b == 'C') {
				A[0]++; // 甲胜加1 
				countA[0]++; // 甲胜B加1 
			}
			if (b == 'J') {
				A[2]++;	// 甲负加1
				countB[2]++; // 乙胜J加1
			}
		}
		
		if(a == 'C') {
			if (b == 'B') {
				A[2]++;	// 甲负加1
				countB[0]++; // 乙胜B加1 
			}
			if (b == 'C') {
				A[1]++; // 甲平加1 
			}
			if (b == 'J') {
				A[0]++;	// 甲胜加1  
				countA[1]++; // 甲胜C加1 
			}
		}
		
		if(a == 'J') {
			if (b == 'B') {
				A[0]++; // 甲胜加1 
				countA[2]++; // 甲胜J加1
			}
			if (b == 'C') {
				A[2]++;	// 甲负加1
				countB[1]++; // 乙胜C加1
			}
			if (b == 'J') {
				A[1]++; // 甲平加1 
			}
		}
	}

	// 甲胜、平、负次数，即乙负、平、胜次数 
	printf("%d %d %d\n", A[0], A[1], A[2]); 
	printf("%d %d %d\n", A[2], A[1], A[0]);
	
	int maxA = 0, j;
	for (int i = 0; i < 3; i++) { // 找出甲胜中次数最多的手势 
		if (countA[i] > maxA) { // 因按字母序排列，相等时默认取小者 
			maxA = countA[i];
			j = i;
		}
	}
	if (j == 0) printf("B "); // 甲后有空格 
	if (j == 1) printf("C ");
	if (j == 2) printf("J ");
		
	int maxB = 0, k;
	for (int i = 0; i < 3; i++) { // 找出乙胜中次数最多的手势
		if (countB[i] > maxB) { // 因按字母序排列，相等时默认取小者 
			maxB = countB[i];
			k = i;
		} 
	}
	if (k == 0) printf("B"); // 乙后无空格 
	if (k == 1) printf("C");
	if (k == 2) printf("J");
		
	return 0; 
}
