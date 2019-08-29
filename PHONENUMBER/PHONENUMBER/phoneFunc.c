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
		puts("\n★★★메모리 공간이 부족합니다★★★");
		return;
	}

	pData = (phoneData*)malloc(sizeof(phoneData));

	fputs("이름 입력 : ", stdout);
	gets_s(pData->name, sizeof(pData->name));
	fputs("번화번호 입력 : ", stdout);
	gets_s(pData->phoneNum, sizeof(pData->phoneNum));

	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, pData->name) &&
			!strcmp(phoneList[i]->phoneNum, pData->phoneNum))
		{
			puts("\n★★★이미 입력된 데이터 입니다★★★");
			free(pData); // 메모리 해제
			getchar();
			return;

		}
	}

	phoneList[numOfData] = pData;
	numOfData++;

	puts("\n★★★입력이 완료되었습니다★★★");
	getchar();

}

void ShowAllData(void)
{
	int i;
	for (i = 0; i < numOfData; i++)
	{
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	puts("\n★★★출력이 완료되었습니다★★★");
	getchar();
}


void SearchPhoneData(void)
{
	char searchName[NAME_LEN];
	int i, searchSte = 0;
	fputs("찾는 이름은? ", stdout);
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
		puts("\n★★★일치하는 이름이 없습니다★★★");
	else
		puts("\n★★★검색이 완료되었습니다★★★");
	getchar();
}

void DeletePhoneData(void)
{
	int i;
	char delName[NAME_LEN];// 지울 이름을 저장할 배열
	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int delIdx = 0;
	int selection = 0;
	fputs("찾는 이름은? ", stdout);
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
		puts("\n★★★찾는 이름의 데이터가 존재하지 않습니다★★★");
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
		fputs("선택 : ", stdout);
		scanf("%d", &selection);
		while (getchar() != '\n');
		delIdx = idxOfMatchingData[selection - 1];
	}
	for (i = delIdx; i < numOfData - 1; i++)
	{
		phoneList[i] = phoneList[i + 1];
	}
	numOfData--;
	puts("\n★★★삭제가 완료되었습니다★★★");
	getchar();
}