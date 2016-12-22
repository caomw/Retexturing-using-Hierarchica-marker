#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//     �@�@ RBFT��p���ĎO�p�`���b�V���̒��_�̕ԊҌ�̍��W�����߂�     �@    //
//    �@�@   �}�[�J�̓��͍��W�Əo�͍��W�̑Ή��_����W�������߂�              //
//      �@ �@ ���Ԏ��������l�����邽��3�t���[�����̑Ή��_���l����    �@      //
///////////////////////////////////////////////////////////////////////////////


#define rho 0.005

using namespace std;
using namespace cv;

class RBFT {

private:
	int N; // ���_��
	vector<Point3i> A, B; // �ό`�O�E�ό`��̈ʒu�x�N�g��
	float TimeWidth1, TimeWidth2;
	Eigen::MatrixXf F, G, X; // F = GX

public:
	RBFT();
	~RBFT() {}
	float potential(Point3i Ai, Point3i Aj);
	void SetABN(const vector<Point2i> AllPoints, const vector<Point2i> Points1FrameBack, const vector<Point2i> Points2FrameBack);

	/* Set�֐� */
	void SetTimeWidth(const vector<Point2i> AllPoints, const vector<Point2i> Points1FrameBack, const vector<Point2i> Points2FrameBack);
	void SetF();
	void SetG();
	void SetX(vector<Point2i> AllPoints, vector<Point2i> Points1FrameBack, vector<Point2i> Points2FrameBack);

	/* RBF��Ԏ��s */
	vector<Point2i> Exe(vector<Point2i> InputPoints);
};