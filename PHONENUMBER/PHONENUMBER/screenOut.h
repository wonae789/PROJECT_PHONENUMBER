

#ifndef SCREENOUT_H
#define SCREENOUT_H

#include "phoneData.h"

void ShowMenu();
void ShowPhoneInfo();

void ShowPhoneInfo(phoneData phone);

void ShowPhoneInfoByPtr(phoneData* phone);

#endif