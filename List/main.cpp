/**
* @file		main.cpp
* @brief	�o�������X�g�ۑ�
* @date		2022/10/03
*/

//===== �C���N���[�h =====
#include <iostream>
#include <fstream>
#include <string>
#include <crtdbg.h>
#include "List.h"

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//*** �ϐ��錾
	List list;		// �o�������X�g

#if 1
	// �e�X�g�R�[�h
	list.AddNode(0, "test0");
	list.AddNode(1, "test1");
	list.AddNode(2, "test2");
	list.AddNode(3, "test3");
	list.AddNode(4, "test4");
	list.AddNode(5, "test5");
#endif

	// ���g��S�ĕ\��
	list.DebugPrintAllNode();

	rewind(stdin);
	getchar();

	return 0;
}

