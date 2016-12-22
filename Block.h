#pragma once
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//    �@�@�@�@   �����̐F���ƂɃ}�[�J�𕡐��̃u���b�N�ɕ��ނ���     �@�@�@�@ //
//          �u���b�N�̎��ʂ��s���C�}�[�J�̃e�N�X�`�����W���擾����           //
//    �@�@�@    ���t�@�����X���Ƀu���b�N����у}�[�J���\�[�g����    �@�@     //
///////////////////////////////////////////////////////////////////////////////


using namespace std;
using namespace cv;


class ColorBlock {

private:

	// �u���b�N���ɏ�������}�[�J�[�̍��W���i�[
	vector<vector<Point2i>> BlockPoints;

	// �u���b�N���ɏ�������}�[�J�[��local�Ȕԍ�(1�`9)���i�[
	vector<vector<int>> BlockLocalNumbers;

	// �u���b�N���\����d�S���W(�ӂ�5�Ԃ̒��S���W��\��)���i�[
	vector<Point2i> BlockRepresenters; 

	// �u���b�N���ɏ�������}�[�J�[��UV���W���i�[ 
	vector<vector<Point2f>> BlockUVs;

	// �u���b�N�̐�
	int NumberOfBlock;

	// LocalNumbers(!= BlockLocalNumbers)�ɑ��݂���eLocalNumber�̐����i�[
	int NumberOfEachLocalNumber[9] = {}; 

	// NumberOfEachLocalNumber�̔z��̒��ōł��傫���l������index
	int MaxIndex = 0; 

	// �ߖT��9�̃}�[�J�[�̍��W���i�[����x�N�g��(������)
	vector<Point2i> NeighborBlockPoints; 


	/* AllBlock��p--------------------------------------------- */

	// ���W���Ƀ\�[�g���ꂽBlockPoints
	vector<vector<Point2i>> SortedBlockPoints;

	// BlockPoints�ɑΉ����ĕ��ёւ���ꂽBlockLocalNumbers
	vector<vector<int>> SortedBlockLocalNumbers; 

	// BlockPoints�ɑΉ����ĕ��ёւ���ꂽBlockUVs
	vector<vector<Point2f>> SortedBlockUVs; 

	// �\�[�g���ꂽ�}�[�J�[�̍��W�ƃe�N�X�`�����W
	vector<Point2i> SortedPoints;
	vector<Point2f> SortedUVs;
	vector<int> SortedLocalNumbers;

	/* --------------------------------------------------------- */


public:

	// �R���X�g���N�^
	ColorBlock();

	// �f�X�g���N�^
	~ColorBlock(){}

	// ���T�C�Y
	void Resize1(); // BlockXXX�ɂ���
	void Resize2(); // SortedBlockXXX�ɂ���
	
	// �e�u���b�N�ɑ΂���p�x���v�Z����
	void CalculateSita(const vector<Point2i> neighbor, vector<float>& sita);

	// �ߖT�ɂȂ��u���b�N���폜����
	void DeleteBlock(vector<Point2i>& neighbor, vector<float>& sita, vector<float>& dist_parts);

	// �u���b�N�����v���ɕ��ׂ�
	void ArrangeNeighborBlock(vector<Point2i>& neighbor, vector<float>& sita);

	// NeighborBlock�ɑΉ�����ID���쐬����
	void MakeID(const vector<Point2i> GlobalNeighbor, string& ID, const int NumberOfRedBlock,
				const int NumberOfGreenBlock, const int NumberOfBlueBlock, const int NumberOfYellowBlock);

	// LocalNumber = 1 �̃}�[�J�[�ɂ��ăe�N�X�`�����W�����߂�
	void GetGlobalUV(const string ID, Point2f& GlobalUV, const vector<string> IDs, const vector<Point2i> IDs_index);

	// ����LocalNumber �ɂ��Ă��e�N�X�`�����W�����߂�
	void GetLocalUV(const int i, const Point2f GlobalUV);

	// �O���[�o���Ȏ��_�ŋߖT��Global�}�[�J�[���擾�E���ʂ��s��
	void GlobalIdentify(const vector<string> IDs, const vector<Point2i> IDs_index,
						vector<string>& IDs_input, const int NumberOfRedBlock,
						const int NumberOfGreenBlock, const int NumberOfBlueBlock,
						const int NumberOfYellowBlock);

	// AllBlock�̕��ёւ� 
	void MarkerSort(const vector<string> IDs_input, const vector<string> IDs, const vector<int> IDs_num);

	// Set�֐�
	void SetNumberOfBlock(vector<Point2i>& Points, vector<int>& LocalNumbers, const int max);
	void SetBlockMemberVariable(vector<int>& LocalNumbers, vector<Point2i>& Points);
	void SetAllBlockMemberVariable(const vector<vector<Point2i>> AddedBlockPoints, 
								   const vector<vector<int>> AddedBlockLocalNumbers, 
								   const vector<Point2i> AddedBlockRepresenters);

	// Get�֐�
	vector<vector<Point2i>> GetBlockPoints();
	vector<vector<int>> GetBlockLocalNumbers();
	vector<Point2i> GetBlockRepresenters();
	vector<vector<Point2f>> GetBlockUVs();
	Point2i GetSortedPoints(const int i);
	Point2f GetSortedUVs(const int i);
	int GetSortedLocalNumbers(const int i);
	int GetNumberOfBlock();


	// Show�֐�
	void ShowMemberVariable();
};