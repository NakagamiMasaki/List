/**
* @file		main.cpp
* @brief	双方向リスト課題
* @date		2022/10/03
*/

//===== インクルード =====
#include <iostream>
#include <fstream>
#include <string>
//#include <crtdbg.h>
#include "List.h"

int main(void)
{
	//*** メモリリークチェック有効化
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//*** 変数宣言
	List list;		// 双方向リスト

#if 0
	// テストコード
	list.AddNode(0, "test0");
	list.AddNode(1, "test1");
	list.AddNode(2, "test2");
	list.AddNode(3, "test3");
	list.AddNode(4, "test4");
	list.AddNode(5, "test5");
#endif

	//*** ファイル読み込み
	std::ifstream File;
	File.open("Scores.txt");
	if (!File.is_open())
	{
		// エラーメッセージ表示 & 待機
		std::cout << "Scores.txtの読み込みに失敗しました。お手数ですが、exeファイルと同階層にファイルがあるかお確かめください。" << std::endl;
		std::cout << "終了するにはエンターキーを押してください。" << std::endl;

		rewind(stdin);
		getchar();

		return -1;
	}

	//*** 1行ずつ読み込んでいく
	std::string szLoadedText;
	while (std::getline(File, szLoadedText))
	{
		std::string szScore;	// スコア
		std::string szName;		// 名前

		// タブでスコアとユーザー名を区切る
		auto nTabPos = szLoadedText.find('\t');		// タブがある位置
		szScore.assign(szLoadedText, 0, nTabPos);		// タブの前までコピー
		szName.assign(szLoadedText, nTabPos + 1, std::string::npos);	// タブの後ろから最後までコピー

		// リストに追加
		auto nScore = std::stoi(szScore);
		list.AddNode(nScore, szName);
	}

	// 中身を全て表示
	list.DebugPrintAllNode();

	// メッセージ表示 & 待機
	std::cout << std::endl;
	std::cout << "終了するにはエンターキーを押してください。" << std::endl;
	rewind(stdin);
	getchar();

	return 0;
}

