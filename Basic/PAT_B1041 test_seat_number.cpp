/*
1041. ������λ��(15)
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�8000 B

��Ŀ������ 
ÿ��PAT�����ڲμӿ���ʱ���ᱻ����������λ�ţ�һ�����Ի���λ��һ���ǿ�����λ��
��������£��������볡ʱ�ȵõ��Ի���λ���룬���������Ի�״̬��
ϵͳ����ʾ�ÿ����Ŀ�����λ���룬����ʱ������Ҫ����������λ������
����Щ�����ٵ��ˣ��Ի��Ѿ�����������ֻ�������쵽���Ի���λ�����������㣬
�Ӻ�̨������ǵĿ�����λ���롣

�����ʽ��
�����һ�и���һ��������N��<=1000�������N�У�
ÿ�и���һ����������Ϣ����׼��֤�� �Ի���λ�� ������λ�š���
����׼��֤����14λ������ɣ���λ��1��N��š�
���뱣֤ÿ���˵�׼��֤�Ŷ���ͬ�������κ�ʱ�򶼲���������˷��䵽ͬһ����λ�ϡ�
������Ϣ֮�󣬸���һ��������M��<=N����
���һ���и���M������ѯ���Ի���λ���룬�Կո�ָ���
�����ʽ��
��Ӧÿ����Ҫ��ѯ���Ի���λ���룬
��һ���������Ӧ������׼��֤�źͿ�����λ���룬�м���1���ո�ָ���
����������
4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4
���������
10120150912002 2
10120150912119 1
 */



#include <cstdio>
#include <cstring> // strcpy����ͷ�ļ� 

struct student {
	char ID[20]; // ׼��֤�� 
	int testSeat; // ������λ�� 
};

const int maxn = 1010; 
student stu[maxn]; // �����ṹ�����飬���Ի���λ��Ϊ�����±�

int main()
{
	int n, trySeat, testSeat; 
	char ID[20];
	scanf("%d", &n); // n������ 
	while (n--) { 
		// �ֱ�����ÿ��������׼��֤�ţ��Ի���λ�ţ�������λ�� 
		scanf("%s %d %d", ID, &trySeat, &testSeat); 
		// ׼��֤�Ŵ������Ի���λ��Ϊ�±��������
		strcpy(stu[trySeat].ID, ID); 
		// ������λ�Ŵ������Ի���λ��Ϊ�±�������� 
		stu[trySeat].testSeat = testSeat; 
	}
	
	int m;
	scanf("%d", &m); // m������ѯ�Ի���λ��
	// ͨ���Ի���λ��ֱ�����׼��֤�źͿ�����λ��
	for (int i = 0; i < m; i++) { 
		scanf("%d", &trySeat);
		printf("%s %d\n", stu[trySeat].ID, stu[trySeat].testSeat);
	}
	return 0;
}