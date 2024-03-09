/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5���� ȣ�� �� �� ���尡 �ִ� ���� ã�Ƴ���. (���ϰ� 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // ���� ����� ����Ѵ�.

int main(){
	char mnames[10][20]; // ���л����(�ִ� 10��)
	int mroom[10];		// ���л���ܺ� ȣ�� ���� ���
	char wnames[10][20]; // ���л����(�ִ� 10��)
	int wroom[10];		// ���л���ܺ� ȣ�� ���� ���
	int person[2][5]={0};   // 2�� ���� 5�� ȣ���� ���� �ο� �� 
	int mcount=0, wcount=0; // �ο� �հ� (��, ��)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("��Ȱ�� ȣ�� ���� ���α׷�\n");
	printf("===========================================\n");
	while(1){
		printf("�޴� : 1.���л� ��� 2.���л� ��� 0.���� > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
				continue;
			}
			printf("�л� �̸���? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
				continue;
			}
			printf("�л� �̸���? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("��Ȱ�� ȣ�� ���� ����� ������ �����ϴ�.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}


int findRoom(int persons[5]){

    	// �̰��� ���� ������ �ڵ屸��

/*
				5���� ȣ���� ������� �˻�.
				�� ȣ���� �˻��� ���� �ο��� 2�� �̸����� Ȯ��.
				�� ���尡 �ִ� ù ��° ȣ�ǿ� �� ���� �߰��� �����ϰ�, �� ȣ�� ��ȣ�� ��ȯ.
				��� ȣ���� ���� á�ٸ� -1�� ��ȯ.
*/

    for(int i = 0; i < 5; i++) {
        if(persons[i] < 2) {
            persons[i]++; 
            return i + 1; 
        }
    }
    return -1; 
}


void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
   
		// �̰��� ���� ������ �ڵ屸��

		/*
				���л� ������� ��� ����.
				���л� ��� ��ȸ.
				������ ���.
				���׻� ������� ��� ����.
				���л� ��� ��ȸ.
		*/

		printf("���л� ���� ���:\n");
    for(int i = 0; i < mc; i++) {
        printf("%s - %dȣ��\n", mn[i], mr[i]);
    }
    printf("\n���л� ���� ���:\n");
    for(int j = 0; j < wc; j++) {
        printf("%s - %dȣ��\n", wn[j], wr[j]);
    }
}
