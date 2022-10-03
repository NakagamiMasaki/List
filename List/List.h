/**
* @file		List.h
* @brief	双方向リスト定義
* @date		2022/10/03
*/

#pragma once

//===== インクルード =====
#include <string>

//===== クラス定義 =====
/**
* @class	List
* @brief	双方向リスト
*/
class List
{
	//=== クラス定義
public:

	/**
	* @class	Node
	* @brief	リストのノード
	*/
	class Node
	{
		//=== メンバ変数
	public:

		int			m_nUserScore;	// スコア
		std::string m_szUserName;		// ユーザー名

		Node* m_pPrevious;	// 前ノード
		Node* m_pNext;		// 次ノード

		//=== メンバ関数
	public:

		Node(void);
		~Node(void);

		/**
		* @fn		List::GetPreviousNode(void)
		* @brief	1つ前のノードを取得する。このノードがルートノードならnullptrが返る。
		* @return	1つ前のノード
		*/
		Node* GetPreviousNode(void);

		/**
		* @fn		List::GetNextNode(void)
		* @brief	次のノードを取得する。このノードが末端のノードならnullptrが返る。
		* @return	次のノード
		*/
		Node* GetNextNode(void);
	};

	//=== メンバ変数
private:

	Node* m_pRootNode;		// ルートノード
	Node* m_pEndNode;		// 末尾ノード

public:

	List(void);
	~List(void);

	/**
	* @fn			List::AddNode(int, const std::string&)
	* @brief		ノードをリストに追加する。
	* @param[in]	nScore	スコア
	* @param[in]	szName	ユーザー名
	*/
	void AddNode(int nScore, const std::string& szName);

	/**
	* @fn		List::GetRootNode(void)
	* @brief	ルートノードを取得する。
	* @return	ルートノード
	*/
	Node* GetRootNode(void);

	/**
	* @fn			List::DeleteNode(void)
	* @brief		指定されたノードを削除する
	* @param[in]	pNode 削除したいノード
	*/
	void DeleteNode(Node* pNode);

	/**
	* @fn		List::DebugPrintAllNode(void)
	* @brief	リストが持つ全てのノードの表示
	*/
	void DebugPrintAllNode(void);
};