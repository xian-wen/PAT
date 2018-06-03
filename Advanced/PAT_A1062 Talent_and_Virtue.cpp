/*
1062. Talent and Virtue (25)
时间限制：200ms  内存限制：64MB  代码长度限制：16KB

Description:
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.
Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

Input Specification:
Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=10^5^), the total number of people to be ranked; L (>=60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and H (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the L line are ranked after the "fool men".
Then N lines follow, each gives the information of a person in the format:

ID_Number Virtue_Grade Talent_Grade

where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.

Output Specification:
The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
 */



#include <cstdio>
#include <cstring> // strcmp函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中

struct student {
	char id[10]; // 准考证号 
	int virtue, talent, sum; // 德分，才分，总分 
	int flag; // 类别 
};

const int maxn = 100010;
student stu[maxn];

// 比较函数 
bool cmp(student a, student b)
{
	// 小类排前，类别相同则总分高者排前
	// 总分相同则德分高者排前，德分相同则准考证小者排前 
	if (a.flag != b.flag) return a.flag < b.flag;  
	else if (a.sum != b.sum) return a.sum > b.sum; 
	else if (a.virtue != b.virtue) return a.virtue > b.virtue;
	else return strcmp(a.id, b.id) < 0;
}

int main()
{
	int n, L, H; // 考生人数，最低录取线，优先录取线 
	scanf("%d%d%d", &n, &L, &H);
	
	int m = n; // 录取人数 
	for (int i = 0; i < n; i++) { // 输入考生信息 
		scanf("%s%d%d", stu[i].id, &stu[i].virtue, &stu[i].talent);
		stu[i].sum = stu[i].virtue + stu[i].talent;
		
		if (stu[i].virtue < L || stu[i].talent < L) { 
			stu[i].flag = 5; // 第5类，不录取者 
			m--;
		} else if (stu[i].virtue >= H && stu[i].talent >= H) {
			stu[i].flag = 1; // 第1类，圣人 
		} else if (stu[i].virtue >= H && stu[i].talent < H) {
			stu[i].flag = 2; // 第2类，君子 
		} else if (stu[i].virtue >= stu[i].talent) {
			stu[i].flag = 3; // 第3类，愚人 
		} else {
			stu[i].flag = 4; // 第4类，小人 
		} 
	}
	
	sort(stu, stu + n, cmp); // 排序 
	
	printf("%d\n", m); // 输出录取人数 
	for (int i = 0; i < m; i++) { // 输出录取人信息 
		printf("%s %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
	}
	return 0;
}
