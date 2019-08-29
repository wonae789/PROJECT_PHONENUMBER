#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

void InputPhoneData(void)
{
	int i;
	phoneData* pData;
	if (numOfData > LIST_NUM)
	{
		puts("\n�ڡڡڸ޸� ������ �����մϴ١ڡڡ�");
		return;
	}

	pData = (phoneData*)malloc(sizeof(phoneData));

	fputs("�̸� �Է� : ", stdout);
	gets_s(pData->name, sizeof(pData->name));
	fputs("��ȭ��ȣ �Է� : ", stdout);
	gets_s(pData->phoneNum, sizeof(pData->phoneNum));

	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, pData->name) &&
			!strcmp(phoneList[i]->phoneNum, pData->phoneNum))
		{
			puts("\n�ڡڡ��̹� �Էµ� ������ �Դϴ١ڡڡ�");
			free(pData); // �޸� ����
			getchar();
			return;

		}
	}

	phoneList[numOfData] = pData;
	numOfData++;

	puts("\n�ڡڡ��Է��� �Ϸ�Ǿ����ϴ١ڡڡ�");
	getchar();

}

void ShowAllData(void)
{
	int i;
	for (i = 0; i < numOfData; i++)
	{
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	puts("\n�ڡڡ������ �Ϸ�Ǿ����ϴ١ڡڡ�");
	getchar();
}


void SearchPhoneData(void)
{
	char searchName[NAME_LEN];
	int i, searchSte = 0;
	fputs("ã�� �̸���? ", stdout);
	gets_s(searchName, sizeof(searchName));
	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, searchName))
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			searchSte = 1;
		}
	}
	if (searchSte == 0)
		puts("\n�ڡڡ���ġ�ϴ� �̸��� �����ϴ١ڡڡ�");
	else
		puts("\n�ڡڡڰ˻��� �Ϸ�Ǿ����ϴ١ڡڡ�");
	getchar();
}

void DeletePhoneData(void)
{
	int i;
	char delName[NAME_LEN];// ���� �̸��� ������ �迭
	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int delIdx = 0;
	int selection = 0;
	fputs("ã�� �̸���? ", stdout);
	gets_s(delName, sizeof(delName));
	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, delName))
		{
			idxOfMatchingData[matchedCount++] = i;
		}
	}
	if (matchedCount == 0)
	{
		puts("\n�ڡڡ�ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ١ڡڡ�");
		getchar();
		return;
	}
	else if (matchedCount == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for (i = 0; i < matchedCount; i++)
		{
			printf("NUM. %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}
		fputs("���� : ", stdout);
		scanf("%d", &selection);
		while (getchar() != '\n');
		delIdx = idxOfMatchingData[selection - 1];
	}
	for (i = delIdx; i < numOfData - 1; i++)
	{
		phoneList[i] = phoneList[i + 1];
	}
	numOfData--;
	puts("\n�ڡڡڻ����� �Ϸ�Ǿ����ϴ١ڡڡ�");
	getchar();
}