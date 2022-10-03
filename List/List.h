/**
* @file		List.h
* @brief	�o�������X�g��`
* @date		2022/10/03
*/

#pragma once

//===== �C���N���[�h =====
#include <string>

//===== �N���X��` =====
/**
* @class	List
* @brief	�o�������X�g
*/
class List
{
	//=== �N���X��`
public:

	/**
	* @class	Node
	* @brief	���X�g�̃m�[�h
	*/
	class Node
	{
		//=== �����o�ϐ�
	public:

		int			m_nUserScore;	// �X�R�A
		std::string m_szUserName;		// ���[�U�[��

		Node* m_pPrevious;	// �O�m�[�h
		Node* m_pNext;		// ���m�[�h

		//=== �����o�֐�
	public:

		Node(void);
		~Node(void);

		/**
		* @fn		List::GetPreviousNode(void)
		* @brief	1�O�̃m�[�h���擾����B���̃m�[�h�����[�g�m�[�h�Ȃ�nullptr���Ԃ�B
		* @return	1�O�̃m�[�h
		*/
		Node* GetPreviousNode(void);

		/**
		* @fn		List::GetNextNode(void)
		* @brief	���̃m�[�h���擾����B���̃m�[�h�����[�̃m�[�h�Ȃ�nullptr���Ԃ�B
		* @return	���̃m�[�h
		*/
		Node* GetNextNode(void);
	};

	//=== �����o�ϐ�
private:

	Node* m_pRootNode;		// ���[�g�m�[�h
	Node* m_pEndNode;		// �����m�[�h

public:

	List(void);
	~List(void);

	/**
	* @fn			List::AddNode(int, const std::string&)
	* @brief		�m�[�h�����X�g�ɒǉ�����B
	* @param[in]	nScore	�X�R�A
	* @param[in]	szName	���[�U�[��
	*/
	void AddNode(int nScore, const std::string& szName);

	/**
	* @fn		List::GetRootNode(void)
	* @brief	���[�g�m�[�h���擾����B
	* @return	���[�g�m�[�h
	*/
	Node* GetRootNode(void);

	/**
	* @fn			List::DeleteNode(void)
	* @brief		�w�肳�ꂽ�m�[�h���폜����
	* @param[in]	pNode �폜�������m�[�h
	*/
	void DeleteNode(Node* pNode);

	/**
	* @fn		List::DebugPrintAllNode(void)
	* @brief	���X�g�����S�Ẵm�[�h�̕\��
	*/
	void DebugPrintAllNode(void);
};