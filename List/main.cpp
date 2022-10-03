/**
* @file		main.cpp
* @brief	双方向リスト課題
* @date		2022/10/03
*/

//===== インクルード =====
#include <iostream>
#include <fstream>
#include <string>
#include <crtdbg.h>
#include "List.h"

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//*** 変数宣言
	List list;		// 双方向リスト

#if 1
	// テストコード
	list.AddNode(0, "test0");
	list.AddNode(1, "test1");
	list.AddNode(2, "test2");
	list.AddNode(3, "test3");
	list.AddNode(4, "test4");
	list.AddNode(5, "test5");
#endif

	// 中身を全て表示
	list.DebugPrintAllNode();

	rewind(stdin);
	getchar();

	return 0;
}

