#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//    　　　  内部の色ごとに外側の色配置からLocalNumberを決定する   　　　　 //
//       　　   　マーカの誤検出を防ぐためにエラー処理を行う    　　　       //
///////////////////////////////////////////////////////////////////////////////


using namespace std;
using namespace cv;

int LocalNumberIdentify(const string local);

class ColorMarker {

private:

	vector<Point2i> ColorPoints; // 内側の色の座標
	vector<int> LocalNumbers;

	vector<Point2i> YellowPoints;
	vector<Point2i> SyanPoints;
	vector<Point2i> MagentaPoints;

	int LocalNumber = 0; // 各マーカーのLocalな番号(これを求めるのが目的)
	string local; // 各マーカーの外側の色配置
	vector<Point2f> OuterPoints; // OutPointsの中でInPoints[i]に所属する座標
	vector<string> OuterColor; // OutPointsの中でInPoints[i]に所属するマーカーの色

public:

	// コンストラクタ
	ColorMarker();

	// デストラクタ
	~ColorMarker() {};

	// マーカー単位でグループ分け
	void Grouping(vector<Point2i> PreviousPoints, vector<int> PreviousLocalNumbers,vector<Point2i>& SortedPoints, const int tt, const bool bTrack);

	// Set関数
	void SetOuterColorPoints(const vector<Point2i> InnerColorPoints, const vector<Point2i> OuterColorPoints1,
							const vector<Point2i> OuterColorPoints2, const vector<Point2i> OuterColorPoints3);

	// Get関数
	vector<Point2i> GetColorPoints();
	vector<int> GetColorLocalNumbers();
	int GetNumberOfMarker();

	// Show関数
	void ShowMemberVariable();
};