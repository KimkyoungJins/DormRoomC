/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}


int findRoom(int persons[5]){

    	// 이곳에 생각 정리와 코드구현

/*
				5개의 호실을 순서대로 검사.
				각 호실을 검사해 현재 인원이 2명 미만인지 확인.
				빈 베드가 있는 첫 번째 호실에 한 명을 추가로 배정하고, 그 호실 번호를 반환.
				모든 호실이 가득 찼다면 -1을 반환.
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
   
		// 이곳에 생각 정리와 코드구현

		/*
				남학생 배정결과 출력 시작.
				남학생 목록 순회.
				구분자 출력.
				여항색 배정결과 출력 시작.
				여학생 목록 순회.
		*/

		printf("남학생 배정 결과:\n");
    for(int i = 0; i < mc; i++) {
        printf("%s - %d호실\n", mn[i], mr[i]);
    }
    printf("\n여학생 배정 결과:\n");
    for(int j = 0; j < wc; j++) {
        printf("%s - %d호실\n", wn[j], wr[j]);
    }
}
