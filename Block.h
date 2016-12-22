#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//    　　　　   内部の色ごとにマーカを複数のブロックに分類する     　　　　 //
//          ブロックの識別を行い，マーカのテクスチャ座標を取得する           //
//    　　　    リファレンス順にブロックおよびマーカをソートする    　　     //
///////////////////////////////////////////////////////////////////////////////


using namespace std;
using namespace cv;


class ColorBlock {

private:

	// ブロック毎に所属するマーカーの座標を格納
	vector<vector<Point2i>> BlockPoints;

	// ブロック毎に所属するマーカーのlocalな番号(1～9)を格納
	vector<vector<int>> BlockLocalNumbers;

	// ブロックを代表する重心座標(ふつう5番の中心座標を表す)を格納
	vector<Point2i> BlockRepresenters; 

	// ブロック毎に所属するマーカーのUV座標を格納 
	vector<vector<Point2f>> BlockUVs;

	// ブロックの数
	int NumberOfBlock;

	// LocalNumbers(!= BlockLocalNumbers)に存在する各LocalNumberの数を格納
	int NumberOfEachLocalNumber[9] = {}; 

	// NumberOfEachLocalNumberの配列の中で最も大きい値を示すindex
	int MaxIndex = 0; 

	// 近傍の9個のマーカーの座標を格納するベクトル(距離順)
	vector<Point2i> NeighborBlockPoints; 


	/* AllBlock専用--------------------------------------------- */

	// 座標順にソートされたBlockPoints
	vector<vector<Point2i>> SortedBlockPoints;

	// BlockPointsに対応して並び替えられたBlockLocalNumbers
	vector<vector<int>> SortedBlockLocalNumbers; 

	// BlockPointsに対応して並び替えられたBlockUVs
	vector<vector<Point2f>> SortedBlockUVs; 

	// ソートされたマーカーの座標とテクスチャ座標
	vector<Point2i> SortedPoints;
	vector<Point2f> SortedUVs;
	vector<int> SortedLocalNumbers;

	/* --------------------------------------------------------- */


public:

	// コンストラクタ
	ColorBlock();

	// デストラクタ
	~ColorBlock(){}

	// リサイズ
	void Resize1(); // BlockXXXについて
	void Resize2(); // SortedBlockXXXについて
	
	// 各ブロックに対する角度を計算する
	void CalculateSita(const vector<Point2i> neighbor, vector<float>& sita);

	// 近傍にないブロックを削除する
	void DeleteBlock(vector<Point2i>& neighbor, vector<float>& sita, vector<float>& dist_parts);

	// ブロックを時計回りに並べる
	void ArrangeNeighborBlock(vector<Point2i>& neighbor, vector<float>& sita);

	// NeighborBlockに対応したIDを作成する
	void MakeID(const vector<Point2i> GlobalNeighbor, string& ID, const int NumberOfRedBlock,
				const int NumberOfGreenBlock, const int NumberOfBlueBlock, const int NumberOfYellowBlock);

	// LocalNumber = 1 のマーカーについてテクスチャ座標を求める
	void GetGlobalUV(const string ID, Point2f& GlobalUV, const vector<string> IDs, const vector<Point2i> IDs_index);

	// 他のLocalNumber についてもテクスチャ座標を求める
	void GetLocalUV(const int i, const Point2f GlobalUV);

	// グローバルな視点で近傍のGlobalマーカーを取得・識別を行う
	void GlobalIdentify(const vector<string> IDs, const vector<Point2i> IDs_index,
						vector<string>& IDs_input, const int NumberOfRedBlock,
						const int NumberOfGreenBlock, const int NumberOfBlueBlock,
						const int NumberOfYellowBlock);

	// AllBlockの並び替え 
	void MarkerSort(const vector<string> IDs_input, const vector<string> IDs, const vector<int> IDs_num);

	// Set関数
	void SetNumberOfBlock(vector<Point2i>& Points, vector<int>& LocalNumbers, const int max);
	void SetBlockMemberVariable(vector<int>& LocalNumbers, vector<Point2i>& Points);
	void SetAllBlockMemberVariable(const vector<vector<Point2i>> AddedBlockPoints, 
								   const vector<vector<int>> AddedBlockLocalNumbers, 
								   const vector<Point2i> AddedBlockRepresenters);

	// Get関数
	vector<vector<Point2i>> GetBlockPoints();
	vector<vector<int>> GetBlockLocalNumbers();
	vector<Point2i> GetBlockRepresenters();
	vector<vector<Point2f>> GetBlockUVs();
	Point2i GetSortedPoints(const int i);
	Point2f GetSortedUVs(const int i);
	int GetSortedLocalNumbers(const int i);
	int GetNumberOfBlock();


	// Show関数
	void ShowMemberVariable();
};