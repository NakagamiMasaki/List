/**
* @file		List.cpp
* @brief	�o�������X�g����
* @date		2022/10/03
*/

//===== �C���N���[�h =====
#include "List.h"
#include <iostream>

//===== �֐���` =====

List::List(void)
	: m_pRootNode(nullptr)
	, m_pEndNode(nullptr)
{
}

List::~List(void)
{
	// �S�Ẵm�[�h���폜����
	while (m_pRootNode)
	{
		// ���[�̃m�[�h���珇�Ԃɍ폜����
		DeleteNode(m_pRootNode);
	}
}

void List::AddNode(int Score, const std::string& Name)
{
	//*** �m�[�h�𖖔��ɒǉ�
	
	// �܂����[�g�m�[�h���Ȃ����
	if (!m_pRootNode)
	{
		// ���[�g�m�[�h�Ƃ��Ēǉ�����
		m_pRootNode = new List::Node;

		// �ݒ�
		m_pRootNode->m_nUserScore = Score;
		m_pRootNode->m_szUserName = Name;

		// �����̃m�[�h��ݒ�
		// ���̏ꍇ�A�����̃m�[�h�̓��[�g�m�[�h
		m_pEndNode = m_pRootNode;
	}
	else
	{
		//*** ���Ƀ��[�g�m�[�h�������
		// �V���������m�[�h���C���X�^���X��
		auto NewNode = new List::Node;
		NewNode->m_nUserScore = Score;
		NewNode->m_szUserName = Name;
		NewNode->m_pPrevious  = m_pEndNode;		// �V���������m�[�h�̑O�́A���݂̖����̃m�[�h
		NewNode->m_pNext      = nullptr;		// �����Ȃ̂�nullptr

		// �����̂���Ɍ��ɒǉ�
		m_pEndNode->m_pNext = NewNode;

		// �ԕ��X�V
		m_pEndNode = NewNode;
	}
}

List::Node* List::GetRootNode(void)
{
	return m_pRootNode;
}

void List::DeleteNode(Node* pNode)
{
	// NULL�`�F�b�N
	if (!pNode)
		return;

	// �������폜����Ƃ��A�����N���j�����Ȃ��悤�ɂ���K�v������
	// NULL�`�F�b�N���Ȃ���Đݒ肷��
	if(pNode->m_pPrevious)
		pNode->m_pPrevious->m_pNext = pNode->m_pNext;
	if(pNode->m_pNext)
		pNode->m_pNext->m_pPrevious = pNode->m_pPrevious;

	// �������[�g�m�[�h�Ȃ�X�V
	if (pNode == m_pRootNode)
		m_pRootNode = pNode->m_pNext;

	// ���[�m�[�h�Ȃ�X�V
	if (pNode == m_pEndNode)
		m_pEndNode = pNode->m_pPrevious;

	delete pNode;
}

void List::DebugPrintAllNode(void)
{
	//*** �S�Ẵm�[�h�̒��g��\������

	auto CurrentNode = m_pRootNode;		// �����Ă���m�[�h
	while (CurrentNode)
	{
		// �\��
		std::cout << CurrentNode->m_nUserScore << " ";
		std::cout << CurrentNode->m_szUserName << std::endl;

		// ����
		CurrentNode = CurrentNode->GetNextNode();
	}
}

List::Node::Node(void)
	: m_pPrevious(nullptr)
	, m_pNext(nullptr)
{
	m_nUserScore = -1;
	m_szUserName.clear();
}

List::Node::~Node(void)
{
	this->m_pNext     = nullptr;
	this->m_pPrevious = nullptr;
}

List::Node* List::Node::GetPreviousNode(void)
{
	return m_pPrevious;
}

List::Node* List::Node::GetNextNode(void)
{
	return m_pNext;
}
