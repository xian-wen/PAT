/*
1011. World Cup Betting (20)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.
Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.
For example, 3 games' odds are given as the following:

 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1

To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input:
Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

Output:
For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

Sample Input:
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1

Sample Output:
T T W 37.98
 */



#include <cstdio>

int main()
{
	char result[3] = {'W', 'T', 'L'}; // 赢、平、输 
	double game[3][3], max[3]; // 每局游戏数值，每局游戏最大数值 
	int index[3]; // 每局最大数值的下标 
	
	for (int i = 0; i < 3; i++) { // 初始化max每一项为-1 
		max[i] = -1;
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &game[i][j]);
			if (game[i][j] > max[i]) { // 比较得出每局游戏的最大值及下标 
				max[i] = game[i][j];
				index[i] = j;
			}
		}
	}
	
	double profit = 1.0;
	for (int i = 0; i < 3; i++) { // 计算最大利润 
		profit *= max[i];
	}
	profit = (profit * 0.65 - 1) * 2;
	
	for (int i = 0; i < 3; i++) { // 输出最大数值下标所对应的结果 
		printf("%c ", result[index[i]]);
	}
	printf("%.2f\n", profit); // 保留两位小数
	return 0;
}
