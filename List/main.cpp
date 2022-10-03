/**
* @file		main.cpp
* @brief	�o�������X�g�ۑ�
* @date		2022/10/03
*/

//===== �C���N���[�h =====
#include <iostream>
#include <fstream>
#include <string>
//#include <crtdbg.h>
#include "List.h"

int main(void)
{
	//*** ���������[�N�`�F�b�N�L����
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//*** �ϐ��錾
	List list;		// �o�������X�g

#if 0
	// �e�X�g�R�[�h
	list.AddNode(0, "test0");
	list.AddNode(1, "test1");
	list.AddNode(2, "test2");
	list.AddNode(3, "test3");
	list.AddNode(4, "test4");
	list.AddNode(5, "test5");
#endif

	//*** �t�@�C���ǂݍ���
	std::ifstream File;
	File.open("Scores.txt");
	if (!File.is_open())
	{
		// �G���[���b�Z�[�W�\�� & �ҋ@
		std::cout << "Scores.txt�̓ǂݍ��݂Ɏ��s���܂����B���萔�ł����Aexe�t�@�C���Ɠ��K�w�Ƀt�@�C�������邩���m���߂��������B" << std::endl;
		std::cout << "�I������ɂ̓G���^�[�L�[�������Ă��������B" << std::endl;

		rewind(stdin);
		getchar();

		return -1;
	}

	//*** 1�s���ǂݍ���ł���
	std::string szLoadedText;
	while (std::getline(File, szLoadedText))
	{
		std::string szScore;	// �X�R�A
		std::string szName;		// ���O

		// �^�u�ŃX�R�A�ƃ��[�U�[������؂�
		auto nTabPos = szLoadedText.find('\t');		// �^�u������ʒu
		szScore.assign(szLoadedText, 0, nTabPos);		// �^�u�̑O�܂ŃR�s�[
		szName.assign(szLoadedText, nTabPos + 1, std::string::npos);	// �^�u�̌�납��Ō�܂ŃR�s�[

		// ���X�g�ɒǉ�
		auto nScore = std::stoi(szScore);
		list.AddNode(nScore, szName);
	}

	// ���g��S�ĕ\��
	list.DebugPrintAllNode();

	// ���b�Z�[�W�\�� & �ҋ@
	std::cout << std::endl;
	std::cout << "�I������ɂ̓G���^�[�L�[�������Ă��������B" << std::endl;
	rewind(stdin);
	getchar();

	return 0;
}

