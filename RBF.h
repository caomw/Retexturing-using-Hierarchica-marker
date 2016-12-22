#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//         　　マーカ部分の明度を補間するためにRBF補間を用いる 　      　    //
///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace cv;

class RBF {

private:

	int N; // データの数
	vector<Point2i> X;
//	Eigen::SparseMatrix<int> Y; // マーカ部分以外の明度
	Eigen::MatrixXf Y;
//	Eigen::SparseMatrix<float> W; // 重み係数
	Eigen::MatrixXf W;
//	Eigen::SparseMatrix<float> Phi; // RBF
	Eigen::MatrixXf Phi;

public:

	RBF();
	~RBF(){}
	void SetY(const Mat roi);
	void SetPhi();
	void SetW();
	int GetValue(const int x, const int y);
	void Exe(Mat& roi);
};