#include "common.h"
#include "phoneData.h"

void ShowMenu()
{
	system("cls");
	puts("-------------�޴�-------------");
	puts("1. ��ȭ��ȣ �Է�");
	puts("2. ��ü ���� ���");
	puts("3. ��ȭ��ȣ �˻�");
	puts("4. ��ȭ��ȣ ����");
	puts("5. ����");
	puts("------------------------------");
}


void ShowPhoneInfo(phoneData phone)
{
	printf("------------------------------\n");
	printf("�̸� : %s\n", phone.name);
	printf("��ȣ : %s\n", phone.phoneNum);
	printf("------------------------------\n\n");

}

void ShowPhoneInfoByPtr(const phoneData* phone)
{
	printf("------------------------------\n");
	printf("�̸� : %s\n", phone->name);
	printf("��ȣ : %s\n", phone->phoneNum);
	printf("------------------------------\n\n");
}