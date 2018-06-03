/*
1015. 德才论 (25)
时间限制：200ms  内存限制：64MB  代码长度限制：16KB

题目描述：
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第1行给出3个正整数，分别为：N（<=10^5^），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。
随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：
输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
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

输出样例：
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
#include <cstring> // strcmp、strcpy函数头文件 
#include <algorithm> // sort函数头文件 

using namespace std; // sort在std中

struct student {
	char id[10]; // 准考证号 
	int talent; // 德分 
	int virtue; // 才分 
	int total; // 德分和才分总和 
};

const int maxn = 100010;
// temp暂存数据，stu1存放“才德全尽”考生，stu2存放“德胜才”考生
// stu3存放“德才兼亡”但“德胜才”考生，stu4存放其他满足录取条件的考生 
student temp, stu1[maxn], stu2[maxn], stu3[maxn], stu4[maxn];

int n, low, high; // 考生总人数，录取最低分数线，优先录取线 

// 比较函数 
bool cmp(student a, student b)
{
	// 总分不同者按总分从大到小排序，总分相同者按德分从大到小排序，
	// 德分相同者按准考证号从小到大排序 
	if (a.total != b.total) return a.total > b.total;
	else if (a.talent != b.talent) return a.talent > b.talent;
	else return strcmp(a.id, b.id) < 0; 
}

int main()
{
	scanf("%d%d%d", &n, &low, &high); // 总考生数，最低录取分，优先录取分 
	
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0; // 四类考生人数统计 
	for (int i = 0; i < n; i++) {
		// 输入考生准考证号，德分，才分 
		scanf("%s %d %d", temp.id, &temp.talent, &temp.virtue); 
		
		if (temp.talent < low || temp.virtue < low) continue; // 不录取 
		else { // 录取 
			if (temp.talent >= high && temp.virtue >= high) {
				strcpy(stu1[num1].id, temp.id); // “才德全尽”考生
				stu1[num1].talent = temp.talent;
				stu1[num1].virtue = temp.virtue;
				stu1[num1].total = temp.talent + temp.virtue; 
				num1++; 
			} else if (temp.talent >= high && temp.virtue < high) {
				strcpy(stu2[num2].id, temp.id); // “德胜才”考生
				stu2[num2].talent = temp.talent;
				stu2[num2].virtue = temp.virtue;
				stu2[num2].total = temp.talent + temp.virtue; 
				num2++; 
			} else if (temp.talent < high && temp.virtue < high 
				&& temp.talent >= temp.virtue) {
				strcpy(stu3[num3].id, temp.id); // “德才兼亡”但“德胜才”考生
				stu3[num3].talent = temp.talent;
				stu3[num3].virtue = temp.virtue;
				stu3[num3].total = temp.talent + temp.virtue; 
				num3++;
			} else {
				strcpy(stu4[num4].id, temp.id); // 其他满足录取条件的考生
				stu4[num4].talent = temp.talent;
				stu4[num4].virtue = temp.virtue;
				stu4[num4].total = temp.talent + temp.virtue; 
				num4++;
			}
		}
	}
	
	// 对四类考生分别进行排序 
	sort(stu1, stu1 + num1, cmp);
	sort(stu2, stu2 + num2, cmp);
	sort(stu3, stu3 + num3, cmp);
	sort(stu4, stu4 + num4, cmp);
	
	printf("%d\n", num1 + num2 + num3 + num4); // 输出总共录取考生数 
	
	// 分别输出四类考生信息 
	for (int i = 0; i < num1; i++) {  
		printf("%s %d %d\n", stu1[i].id, stu1[i].talent, stu1[i].virtue);
	}
	for (int i = 0; i < num2; i++) {
		printf("%s %d %d\n", stu2[i].id, stu2[i].talent, stu2[i].virtue);
	}
	for (int i = 0; i < num3; i++) {
		printf("%s %d %d\n", stu3[i].id, stu3[i].talent, stu3[i].virtue);
	}
	for (int i = 0; i < num4; i++) {
		printf("%s %d %d\n", stu4[i].id, stu4[i].talent, stu4[i].virtue);
	}
	return 0;
}
