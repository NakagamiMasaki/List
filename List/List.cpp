/**
* @file		List.cpp
* @brief	双方向リスト実装
* @date		2022/10/03
*/

//===== インクルード =====
#include "List.h"
#include <iostream>

//===== 関数定義 =====

List::List(void)
	: m_pRootNode(nullptr)
	, m_pEndNode(nullptr)
{
}

List::~List(void)
{
	// 全てのノードを削除する
	while (m_pRootNode)
	{
		// 末端のノードから順番に削除する
		DeleteNode(m_pRootNode);
	}
}

void List::AddNode(int Score, const std::string& Name)
{
	//*** ノードを末尾に追加
	
	// まだルートノードがなければ
	if (!m_pRootNode)
	{
		// ルートノードとして追加する
		m_pRootNode = new List::Node;

		// 設定
		m_pRootNode->m_nUserScore = Score;
		m_pRootNode->m_szUserName = Name;

		// 末尾のノードを設定
		// この場合、末尾のノードはルートノード
		m_pEndNode = m_pRootNode;
	}
	else
	{
		//*** 既にルートノードがあれば
		// 新しい末尾ノードをインスタンス化
		auto NewNode = new List::Node;
		NewNode->m_nUserScore = Score;
		NewNode->m_szUserName = Name;
		NewNode->m_pPrevious  = m_pEndNode;		// 新しい末尾ノードの前は、現在の末尾のノード
		NewNode->m_pNext      = nullptr;		// 末尾なのでnullptr

		// 末尾のさらに後ろに追加
		m_pEndNode->m_pNext = NewNode;

		// 番兵更新
		m_pEndNode = NewNode;
	}
}

List::Node* List::GetRootNode(void)
{
	return m_pRootNode;
}

void List::DeleteNode(Node* pNode)
{
	// NULLチェック
	if (!pNode)
		return;

	// 自分を削除するとき、リンクが破損しないようにする必要がある
	// NULLチェックしながら再設定する
	if(pNode->m_pPrevious)
		pNode->m_pPrevious->m_pNext = pNode->m_pNext;
	if(pNode->m_pNext)
		pNode->m_pNext->m_pPrevious = pNode->m_pPrevious;

	// もしルートノードなら更新
	if (pNode == m_pRootNode)
		m_pRootNode = pNode->m_pNext;

	// 末端ノードなら更新
	if (pNode == m_pEndNode)
		m_pEndNode = pNode->m_pPrevious;

	delete pNode;
}

void List::DebugPrintAllNode(void)
{
	//*** 全てのノードの中身を表示する

	auto CurrentNode = m_pRootNode;		// 今見ているノード
	while (CurrentNode)
	{
		// 表示
		std::cout << CurrentNode->m_nUserScore << " ";
		std::cout << CurrentNode->m_szUserName << std::endl;

		// 次へ
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
