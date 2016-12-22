#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//     　　 RBFTを用いて三角形メッシュの頂点の返還後の座標を求める     　    //
//    　　   マーカの入力座標と出力座標の対応点から係数を求める              //
//      　 　 時間軸方向を考慮するため3フレーム分の対応点を考える    　      //
///////////////////////////////////////////////////////////////////////////////


#define rho 0.005

using namespace std;
using namespace cv;

class RBFT {

private:
	int N; // 頂点数
	vector<Point3i> A, B; // 変形前・変形後の位置ベクトル
	float TimeWidth1, TimeWidth2;
	Eigen::MatrixXf F, G, X; // F = GX

public:
	RBFT();
	~RBFT() {}
	float potential(Point3i Ai, Point3i Aj);
	void SetABN(const vector<Point2i> AllPoints, const vector<Point2i> Points1FrameBack, const vector<Point2i> Points2FrameBack);

	/* Set関数 */
	void SetTimeWidth(const vector<Point2i> AllPoints, const vector<Point2i> Points1FrameBack, const vector<Point2i> Points2FrameBack);
	void SetF();
	void SetG();
	void SetX(vector<Point2i> AllPoints, vector<Point2i> Points1FrameBack, vector<Point2i> Points2FrameBack);

	/* RBF補間実行 */
	vector<Point2i> Exe(vector<Point2i> InputPoints);
};