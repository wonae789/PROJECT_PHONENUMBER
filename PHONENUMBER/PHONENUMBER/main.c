#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"


enum { INPUT = 1, SHOW, SEARCH, DELETE, QUIT };


int main(void)
{
	int inputMenu = 0;
	while (1)
	{
		ShowMenu();
		fputs("선택하세요 : ", stdout);
		scanf("%d", &inputMenu);
		while (getchar() != '\n');

		switch (inputMenu)
		{
		case INPUT:
			InputPhoneData();
			break;
		case SHOW:
			ShowAllData();
			break;
		case SEARCH:
			SearchPhoneData();
			break;
		case DELETE:
			DeletePhoneData();
			break;
		}
		if (inputMenu == QUIT)
		{
			puts("\n★★★이용해주셔서 감사합니다★★★");
			break;
		}
	}

	return 0;
}