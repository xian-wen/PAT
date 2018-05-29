/*
1015. �²��� (25)
ʱ�����ƣ�200ms  �ڴ����ƣ�64MB  ���볤�����ƣ�16KB

��Ŀ������
�δ�ʷѧ��˾����ڡ�����ͨ��������һ�������ġ��²��ۡ������ǹʲŵ�ȫ��ν֮ʥ�ˣ��ŵ¼���ν֮���ˣ���ʤ��ν֮���ӣ���ʤ��ν֮С�ˡ���ȡ��֮����������ʥ�ˣ����Ӷ���֮�������С�ˣ����������ˡ���
�ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������

�����ʽ��
�����1�и���3�����������ֱ�Ϊ��N��<=10^5^����������������L��>=60����Ϊ¼ȡ��ͷ����ߣ����·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��H��<100����Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ������򣻲ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮�󣻵²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮�������ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��
���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�����׼��֤��Ϊ8λ�������²ŷ�Ϊ����[0, 100]�ڵ����������ּ��Կո�ָ���

�����ʽ��
�����1�����ȸ����ﵽ��ͷ����ߵĿ�������M�����M�У�ÿ�а��������ʽ���һλ��������Ϣ��������������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У����·�Ҳ���У���׼��֤�ŵ����������

����������
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

���������
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
#include <cstring> // strcmp��strcpy����ͷ�ļ� 
#include <algorithm> // sort����ͷ�ļ� 

using namespace std; // sort��std��

struct student {
	char id[10]; // ׼��֤�� 
	int talent; // �·� 
	int virtue; // �ŷ� 
	int total; // �·ֺͲŷ��ܺ� 
};

const int maxn = 100010;
// temp�ݴ����ݣ�stu1��š��ŵ�ȫ����������stu2��š���ʤ�š�����
// stu3��š��²ż�����������ʤ�š�������stu4�����������¼ȡ�����Ŀ��� 
student temp, stu1[maxn], stu2[maxn], stu3[maxn], stu4[maxn];

int n, low, high; // ������������¼ȡ��ͷ����ߣ�����¼ȡ�� 

// �ȽϺ��� 
bool cmp(student a, student b)
{
	// �ֲܷ�ͬ�߰��ִܷӴ�С�����ܷ���ͬ�߰��·ִӴ�С����
	// �·���ͬ�߰�׼��֤�Ŵ�С�������� 
	if (a.total != b.total) return a.total > b.total;
	else if (a.talent != b.talent) return a.talent > b.talent;
	else return strcmp(a.id, b.id) < 0; 
}

int main()
{
	scanf("%d%d%d", &n, &low, &high); // �ܿ����������¼ȡ�֣�����¼ȡ�� 
	
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0; // ���࿼������ͳ�� 
	for (int i = 0; i < n; i++) {
		// ���뿼��׼��֤�ţ��·֣��ŷ� 
		scanf("%s %d %d", temp.id, &temp.talent, &temp.virtue); 
		
		if (temp.talent < low || temp.virtue < low) continue; // ��¼ȡ 
		else { // ¼ȡ 
			if (temp.talent >= high && temp.virtue >= high) {
				strcpy(stu1[num1].id, temp.id); // ���ŵ�ȫ��������
				stu1[num1].talent = temp.talent;
				stu1[num1].virtue = temp.virtue;
				stu1[num1].total = temp.talent + temp.virtue; 
				num1++; 
			} else if (temp.talent >= high && temp.virtue < high) {
				strcpy(stu2[num2].id, temp.id); // ����ʤ�š�����
				stu2[num2].talent = temp.talent;
				stu2[num2].virtue = temp.virtue;
				stu2[num2].total = temp.talent + temp.virtue; 
				num2++; 
			} else if (temp.talent < high && temp.virtue < high 
				&& temp.talent >= temp.virtue) {
				strcpy(stu3[num3].id, temp.id); // ���²ż�����������ʤ�š�����
				stu3[num3].talent = temp.talent;
				stu3[num3].virtue = temp.virtue;
				stu3[num3].total = temp.talent + temp.virtue; 
				num3++;
			} else {
				strcpy(stu4[num4].id, temp.id); // ��������¼ȡ�����Ŀ���
				stu4[num4].talent = temp.talent;
				stu4[num4].virtue = temp.virtue;
				stu4[num4].total = temp.talent + temp.virtue; 
				num4++;
			}
		}
	}
	
	// �����࿼���ֱ�������� 
	sort(stu1, stu1 + num1, cmp);
	sort(stu2, stu2 + num2, cmp);
	sort(stu3, stu3 + num3, cmp);
	sort(stu4, stu4 + num4, cmp);
	
	printf("%d\n", num1 + num2 + num3 + num4); // ����ܹ�¼ȡ������ 
	
	// �ֱ�������࿼����Ϣ 
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
