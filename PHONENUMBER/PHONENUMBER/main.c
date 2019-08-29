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
		fputs("�����ϼ��� : ", stdout);
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
			puts("\n�ڡڡ��̿����ּż� �����մϴ١ڡڡ�");
			break;
		}
	}

	return 0;
}