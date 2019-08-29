#include "common.h"
#include "phoneData.h"

void ShowMenu()
{
	system("cls");
	puts("-------------메뉴-------------");
	puts("1. 전화번호 입력");
	puts("2. 전체 정보 출력");
	puts("3. 전화번호 검색");
	puts("4. 전화번호 삭제");
	puts("5. 종료");
	puts("------------------------------");
}


void ShowPhoneInfo(phoneData phone)
{
	printf("------------------------------\n");
	printf("이름 : %s\n", phone.name);
	printf("번호 : %s\n", phone.phoneNum);
	printf("------------------------------\n\n");

}

void ShowPhoneInfoByPtr(const phoneData* phone)
{
	printf("------------------------------\n");
	printf("이름 : %s\n", phone->name);
	printf("번호 : %s\n", phone->phoneNum);
	printf("------------------------------\n\n");
}