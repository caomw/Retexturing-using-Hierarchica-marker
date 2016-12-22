#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//    �@�@�@  �����̐F���ƂɊO���̐F�z�u����LocalNumber�����肷��   �@�@�@�@ //
//       �@�@   �@�}�[�J�̌댟�o��h�����߂ɃG���[�������s��    �@�@�@       //
///////////////////////////////////////////////////////////////////////////////


using namespace std;
using namespace cv;

int LocalNumberIdentify(const string local);

class ColorMarker {

private:

	vector<Point2i> ColorPoints; // �����̐F�̍��W
	vector<int> LocalNumbers;

	vector<Point2i> YellowPoints;
	vector<Point2i> SyanPoints;
	vector<Point2i> MagentaPoints;

	int LocalNumber = 0; // �e�}�[�J�[��Local�Ȕԍ�(��������߂�̂��ړI)
	string local; // �e�}�[�J�[�̊O���̐F�z�u
	vector<Point2f> OuterPoints; // OutPoints�̒���InPoints[i]�ɏ���������W
	vector<string> OuterColor; // OutPoints�̒���InPoints[i]�ɏ�������}�[�J�[�̐F

public:

	// �R���X�g���N�^
	ColorMarker();

	// �f�X�g���N�^
	~ColorMarker() {};

	// �}�[�J�[�P�ʂŃO���[�v����
	void Grouping(vector<Point2i> PreviousPoints, vector<int> PreviousLocalNumbers,vector<Point2i>& SortedPoints, const int tt, const bool bTrack);

	// Set�֐�
	void SetOuterColorPoints(const vector<Point2i> InnerColorPoints, const vector<Point2i> OuterColorPoints1,
							const vector<Point2i> OuterColorPoints2, const vector<Point2i> OuterColorPoints3);

	// Get�֐�
	vector<Point2i> GetColorPoints();
	vector<int> GetColorLocalNumbers();
	int GetNumberOfMarker();

	// Show�֐�
	void ShowMemberVariable();
};