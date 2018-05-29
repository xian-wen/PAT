/*
1006. Sign In and Sign Out (25)
ʱ�����ƣ�400 ms  �ڴ����ƣ�65536 kB  ���볤�����ƣ�16000 B

Description:
At the beginning of every day, 
the first person who signs in the computer room will unlock the door, 
and the last one who signs out will lock the door. 
Given the records of signing in's and out's, you are supposed to find 
the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. 
Each case contains the records for one day. 
The case starts with a positive integer M, 
which is the total number of records, followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, 
and ID number is a string with no more than 15 characters.
Output Specification:
For each test case, output in one line the ID numbers of the persons 
who have unlocked and locked the door on that day. 
The two ID numbers must be separated by one space.
Note: It is guaranteed that the records are consistent. That is, 
the sign in time must be earlier than the sign out time for each person, 
and there are no two persons sign in or out at the same moment.
Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output: SC3021234 CS301133
 */



#include <cstdio>
#include <cstring> // strcpy����ͷ�ļ� 

struct time {
	int hh, mm, ss; // ʱ���֡��� 
};

struct person {
	char ID[20]; // ѧ�� 
	time in; // ����ʱ�� 
	time out; // ����ʱ�� 
}; 

person temp, unlock, lock; // ��ʱ�������ߣ������� 

// ʱ��Ƚϣ�aС�ڵ���b����true�����򷵻�false 
bool LessEqu(time a, time b)
{
	if (a.hh != b.hh) return a.hh <= b.hh;
	else if (a.mm != b.mm) return a.mm <= b.mm;
	else return a.ss <= b.ss;
}

// ʱ��Ƚϣ�a���ڵ���b����true�����򷵻�false 
bool MoreEqu(time a, time b)
{
	if (a.hh != b.hh) return a.hh >= b.hh;
	else if (a.mm != b.mm) return a.mm >= b.mm;
	else return a.ss >= b.ss;
}

// ��ʼ������ʱ��Ϊ23:59:59������ʱ��Ϊ00:00:00 
void init()
{
	unlock.in.hh = 23;
	unlock.in.mm = unlock.in.ss = 59;
	lock.out.hh = lock.out.mm = lock.out.ss = 0;
}

int main()
{
	init();
	int M;
	scanf("%d", &M);
	while (M--) {
		// ����ѧ�š�����ʱ�䡢����ʱ�� 
		scanf("%s %d:%d:%d %d:%d:%d", temp.ID, 
			&temp.in.hh, &temp.in.mm, &temp.in.ss, 
			&temp.out.hh, &temp.out.mm, &temp.out.ss);  
		// �Ƚϵó�����ʱ��Ϳ�����ѧ�� 
		if (LessEqu(temp.in, unlock.in)) {  
			unlock.in = temp.in;
			strcpy(unlock.ID, temp.ID);
		}
		// �Ƚϵó�����ʱ��͹�����ѧ�� 
		if (MoreEqu(temp.out, lock.out)) {
			lock.out = temp.out;
			strcpy(lock.ID, temp.ID);
		}
	}
	
	printf("%s %s\n", unlock.ID, lock.ID); // ���������ѧ�ź͹�����ѧ�� 
	return 0;
}
