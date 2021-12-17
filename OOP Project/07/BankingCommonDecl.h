/*
FileName: BankingCommonDecl.h
Update: 0.7
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_COUNT = 100; // 최대 개설 가능한 계좌 수
const int NAME_LEN = 20; // 이름의 최대 길이

enum {
	LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2
};
#endif