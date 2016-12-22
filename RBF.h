#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//         �@�@�}�[�J�����̖��x���Ԃ��邽�߂�RBF��Ԃ�p���� �@      �@    //
///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace cv;

class RBF {

private:

	int N; // �f�[�^�̐�
	vector<Point2i> X;
//	Eigen::SparseMatrix<int> Y; // �}�[�J�����ȊO�̖��x
	Eigen::MatrixXf Y;
//	Eigen::SparseMatrix<float> W; // �d�݌W��
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