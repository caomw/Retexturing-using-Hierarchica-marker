#include "Block.h"

/* ���Ƀu���b�N�Ɋi�[����ׂ�Local�ԍ���Ԃ� */
int Next(const vector<int> StoredNumber, const int number) {

	if (number == 1) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}
	}
	if (number == 2) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}

	}
	if (number == 3) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}

	}
	if (number == 4) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}

	}
	if (number == 5) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}


	}
	if (number == 6) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}
	}
	if (number == 7) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}

	}
	if (number == 8) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 9) == StoredNumber.end()) {
			return 9;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}

	}
	if (number == 9) {
		if (find(StoredNumber.begin(), StoredNumber.end(), 6) == StoredNumber.end()) {
			return 6;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 8) == StoredNumber.end()) {
			return 8;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 5) == StoredNumber.end()) {
			return 5;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 3) == StoredNumber.end()) {
			return 3;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 7) == StoredNumber.end()) {
			return 7;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 2) == StoredNumber.end()) {
			return 2;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 4) == StoredNumber.end()) {
			return 4;
		}
		else if (find(StoredNumber.begin(), StoredNumber.end(), 1) == StoredNumber.end()) {
			return 1;
		}
	}

}

/* LocalNumber(number)���_�u�����u���b�N�ɂ��Đ������Ȃ������������鏈�� */
void DeleteIndex(const int number, const vector<int> index, vector<Point2i>& BlockPoints_i, vector<int>& BlockLocalNumbers_i, const Point2i BlockRepresenter)
{
	// �_�u�����}�[�J�[�̍��W
	vector<Point2i> points;
	vector<int> FalseIndex; // �����ׂ��ԍ�

	for (int i = 0; i < index.size(); ++i) {
		points.push_back(BlockPoints_i[index[i]]);
	}

	// �����̔ԍ��ƍ��W(����0�Ԗڂ𐳂������̂Ƃ��Č�Ŕ��f)
	int CorrectIndex = 0;
	Point2i CorrectPoint = points[0];

	// 1���_�u�����Ƃ�
	if ((number + 1) == 1) {

		for (int i = 1; i < points.size(); ++i) {

			if (CorrectPoint.y < points[i].y) { // y���W�Ŕ��f
				FalseIndex.push_back(i);
			}
			else {
				FalseIndex.push_back(CorrectIndex);
				CorrectIndex = i;
				CorrectPoint = points[i];
			}
		}
	}

	// 9���_�u�����Ƃ�
	if ((number + 1) == 9) {

		for (int i = 1; i < points.size(); ++i) {

			if (CorrectPoint.y > points[i].y) { // y���W�Ŕ��f
				FalseIndex.push_back(i);
			}
			else {
				FalseIndex.push_back(CorrectIndex);
				CorrectIndex = i;
				CorrectPoint = points[i];
			}
		}

	}

	// ���̂ق��̔ԍ����_�u�����Ƃ�
	if ((number + 1) == 2 || (number + 1) == 3 || (number + 1) == 4 || (number + 1) == 5 || (number + 1) == 6 || (number + 1) == 7 || (number + 1) == 8) {

		vector<float> dis; // BlockRepresenter_i����̋���
		dis.clear();

		for (int i = 0; i < points.size(); ++i) {
			dis.push_back(pow(points[i].x - BlockRepresenter.x, 2) + pow(points[i].y - BlockRepresenter.y, 2));
		}

		for (int i = 1; i < points.size(); ++i) {

			if (dis[CorrectIndex] < dis[i]) { // y���W�Ŕ��f
				FalseIndex.push_back(i);
			}
			else {
				FalseIndex.push_back(CorrectIndex);
				CorrectIndex = i;
				CorrectPoint = points[i];
			}
		}

	}

	// ����
	for (int i = (FalseIndex.size() - 1); i = 0; --i) {
		BlockPoints_i.erase(BlockPoints_i.begin()+FalseIndex[i]);
		BlockLocalNumbers_i.erase(BlockLocalNumbers_i.begin() + FalseIndex[i]);
	}
}

void CheckBlock(vector<vector<Point2i>>& BlockPoints, vector<vector<int>>& BlockLocalNumbers, vector<Point2i>& BlockRepresenters) 
{
	for (int i = 0; i < BlockLocalNumbers.size(); ++i) {

		for (int j = 0; j < 9; ++j) {

			vector<int> index; index.clear();

			for (int k = 0; k < BlockLocalNumbers[i].size(); ++k) {

				if (BlockLocalNumbers[i][k] == (j + 1)) {
					index.push_back(k);
				}
			}
			
			if (j == 4 && index.size() == 1) {
				BlockRepresenters[i] = BlockPoints[i][index[0]];
			}
			
			if (index.size() > 1) {
				DeleteIndex(j,index, BlockPoints[i], BlockLocalNumbers[i], BlockRepresenters[i]);
			}

			index.clear();

			for (int k = 0; k < BlockLocalNumbers[i].size(); ++k) {

				if (BlockLocalNumbers[i][k] == (j + 1)) {
					index.push_back(k);
				}
			}
			if (j == 4 && index.size() == 1) {
				BlockRepresenters[i] = BlockPoints[i][index[0]];
			}
			
		}

	}

}

/* �R���X�g���N�^ */
ColorBlock::ColorBlock()
{
	BlockPoints.clear();
	BlockLocalNumbers.clear();
	BlockRepresenters.clear();
	BlockUVs.clear();

	NumberOfBlock = 0;
	NumberOfEachLocalNumber[9] = {};
	MaxIndex = 0;

	NeighborBlockPoints.clear();

	SortedBlockPoints.clear();
	SortedBlockLocalNumbers.clear();
	SortedBlockUVs.clear();

	SortedPoints.clear();
	SortedUVs;
}

/* ���T�C�Y */

void ColorBlock::Resize1()
{
	BlockPoints.resize(NumberOfBlock);
	BlockLocalNumbers.resize(NumberOfBlock);
	BlockRepresenters.resize(NumberOfBlock);
	BlockUVs.resize(NumberOfBlock);
}
void ColorBlock::Resize2()
{
	// ��`�̈�̏ꍇ
	SortedBlockPoints.resize(wid_num*hei_num / 9);
	SortedBlockUVs.resize(wid_num*hei_num / 9);
	SortedBlockLocalNumbers.resize(wid_num*hei_num / 9);

	SortedPoints.resize(wid_num*hei_num);
	for (int i = 0; i < SortedPoints.size(); ++i) {
		SortedPoints[i] = Point2f(-1.0f, -1.0f);
	}
	SortedUVs.resize(wid_num*hei_num);
	for (int i = 0; i < SortedUVs.size(); ++i) {
		SortedUVs[i] = Point2f(-1.0f, -1.0f);
	}
	SortedLocalNumbers.resize(wid_num*hei_num);
	for (int i = 0; i < SortedLocalNumbers.size(); ++i) {
		SortedLocalNumbers[i] = -1;
	}
}

void ColorBlock::CalculateSita(const vector<Point2i> neighbor, vector<float>& sita)
{
	/* ���ڃ}�[�J�[�����_�Ƃ������̍��W */
	vector<Point2f> coord;
	coord.clear();

	/* ���΍��W���v�Z */
	for (int i = 0; i < neighbor.size() - 1; ++i) {
		coord.push_back(Point2f(neighbor[i + 1].x - neighbor[0].x, neighbor[i + 1].y - neighbor[0].y));
	}

	/* �e�u���b�N�ɑ΂���p�x���v�Z */
	for (int i = 0; i < neighbor.size() - 1; ++i) {
		sita.push_back(atan2f(coord[i].y, coord[i].x) * 180 / M_PI);
	}
}

void ColorBlock::DeleteBlock(vector<Point2i>& neighbor, vector<float>& sita, vector<float>& dist_parts)
{
	/* �폜����u���b�N�̔ԍ� */
	vector<int> num;
	num.clear();

	/* �꒼����ɂ���,��艓���u���b�N���폜 */
	for (int i = 0; i < sita.size() - 1; ++i) {
		for (int j = i + 1; j < sita.size(); ++j) {
			float dif = sita[i] - sita[j];

			/* �p�x��臒l�����߂Ă���ȉ��ł���Έ꒼����ɂ���Ƃ݂Ȃ� */
			if (fabs(dif) < angTsd || fabs(dif) > 360 - angTsd) {

				if (fabs(dist_parts[i + 1] - dist_parts[j + 1]) < 10) {
					continue;
				}
				num.push_back(j);
			}
		}
	}

	sort(num.begin(), num.end());

	/* ������ɍ폜����}�[�J�[��2�ȏ㑶�݂����Ƃ��̃G���[���� */
	while (num.size() > 1) {
		if (num[num.size() - 2] == num[num.size() - 1]) {
			num.pop_back();
		}
		else {
			neighbor.erase(neighbor.begin() + num.back() + 1);
			sita.erase(sita.begin() + num.back());
			num.pop_back();
		}
	}

	if (num.size() == 1) {
		neighbor.erase(neighbor.begin() + num.back() + 1);
		sita.erase(sita.begin() + num.back());
	}
}

void ColorBlock::ArrangeNeighborBlock(vector<Point2i>& neighbor, vector<float>& sita)
{
	/* ���v���ɕ��ׂ�neighbor������x�N�g�� */
	vector<Point2i> neighbor_dash;
	neighbor_dash.clear();
	neighbor_dash.push_back(neighbor[0]); // ���ڂ��Ă���}�[�J�[��擪�ɂ���

	/* neighbor_dash�Ɠ��l(�T�C�Y���قȂ邱�ƂɋC��t����) */
	vector<float> sita_dash;
	sita_dash.clear();

	/* sita�̃R�s�[(�T���p�ɍ��) */
	vector<float> sita_copy;
	sita_copy = sita;

	/* ���v���=�p�x�̏��� */
	sort(sita_copy.begin(), sita_copy.end());

	/* sita_copy�̏��ɑΉ�����neighbor_dash��sita_dash����� */
	for (int i = 0; i < sita_copy.size(); ++i) {
		for (int j = 0; j < sita.size(); ++j) {

			if (sita_copy[i] == sita[j]) {
				neighbor_dash.push_back(neighbor[j + 1]);
				sita_dash.push_back(sita[j]);
			}

		}
	}

	/* ��� */
	neighbor = neighbor_dash;
	sita = sita_dash;
}

void ColorBlock::MakeID(const vector<Point2i> NeighborBlockPoints,
	string& ID, const int NumberOfRedBlock,
	const int NumberOfGreenBlock, const int NumberOfBlueBlock,
	const int NumberOfYellowBlock)
{
	for (int i = 0; i < NeighborBlockPoints.size(); ++i) {
		for (int j = 0; j < BlockRepresenters.size(); ++j) {

			if (NeighborBlockPoints[i] == BlockRepresenters[j]) {

				if (0 <= j && j < NumberOfRedBlock) {
					ID += "1";
					break;
				}
				else if (NumberOfRedBlock <= j && j < (NumberOfRedBlock + NumberOfGreenBlock)) {
					ID += "2";
					break;
				}
				else if ((NumberOfRedBlock + NumberOfGreenBlock) <= j && j < (NumberOfRedBlock + NumberOfGreenBlock + NumberOfBlueBlock)) {
					ID += "3";
					break;
				}
				else if ((NumberOfRedBlock + NumberOfGreenBlock + NumberOfBlueBlock) <= j && j < (NumberOfRedBlock + NumberOfGreenBlock + NumberOfBlueBlock + NumberOfYellowBlock)) {
					ID += "4";
					break;
				}
			}
		}
	}
}

void ColorBlock::GetGlobalUV(const string ID, Point2f& GlobalUV, const vector<string> IDs, const vector<Point2i> IDs_index)
{
	for (int i = 0; i < IDs.size(); ++i) {
		if (ID == IDs[i]) {

			// �u���b�N�̃C���f�b�N�X��\��
			int a = IDs_index[i].x; // �ォ��a�Ԗ�(y����)
			int b = IDs_index[i].y; // ������b�Ԗ�(x����)

			// LocalNumber = 1 �̃}�[�J�[�ɂ��Ċe�u���b�N
			GlobalUV = Point2f((float)b * 3 / (wid_num - 1), (float)a * 3 / (hei_num - 1));
		}
	}
}

void ColorBlock::GetLocalUV(const int i, const Point2f GlobalUV)
{
	BlockUVs.resize(BlockPoints.size());

	for (int j = 0; j < BlockLocalNumbers[i].size(); ++j) {
		int localnumber = BlockLocalNumbers[i][j];

		if (localnumber == 1) {
			BlockUVs[i].push_back(GlobalUV);
		}
		else if (localnumber == 2) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x + 1.0 / (wid_num - 1), GlobalUV.y));
		}
		else if (localnumber == 3) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x + 2.0 / (wid_num - 1), GlobalUV.y));
		}
		else if (localnumber == 4) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x, GlobalUV.y + 1.0 / (hei_num - 1)));
		}
		else if (localnumber == 5) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x + 1.0 / (wid_num - 1), GlobalUV.y + 1.0 / (hei_num - 1)));
		}
		else if (localnumber == 6) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x + 2.0 / (wid_num - 1), GlobalUV.y + 1.0 / (hei_num - 1)));
		}
		else if (localnumber == 7) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x, GlobalUV.y + 2.0 / (hei_num - 1)));
		}
		else if (localnumber == 8) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x + 1.0 / (wid_num - 1), GlobalUV.y + 2.0 / (hei_num - 1)));
		}
		else if (localnumber == 9) {
			BlockUVs[i].push_back(Point2f(GlobalUV.x + 2.0 / (wid_num - 1), GlobalUV.y + 2.0 / (hei_num - 1)));
		}
	}
}

void ColorBlock::GlobalIdentify(const vector<string> IDs, const vector<Point2i> IDs_index,
	vector<string>& IDs_input, const int NumberOfRedBlock,
	const int NumberOfGreenBlock, const int NumberOfBlueBlock,
	const int NumberOfYellowBlock)
{
	vector<float> dist; // �S�Ă�Global�}�[�J�[�ɑ΂��Ē��ڂ��Ă���Global�}�[�J�[����̋���
	vector<float> dist_copy; // dist�̃R�s�[
	vector<float> dist_parts; // dist�̈ꕔ(���̋����ȉ�)
	vector<Point2i> BlockRepresenters_copy; // BlockRepresenters�̃R�s�[

	for (int i = 0; i < BlockPoints.size(); i++) {

		/* ������ */
		dist.clear();
		dist_copy.clear();
		dist_parts.clear();
		BlockRepresenters_copy = BlockRepresenters;
		NeighborBlockPoints.clear();

		/* i�Ԗڂ̃u���b�N����j�Ԗڂ̃u���b�N�܂ł̋������v�Z */
		for (int j = 0; j < BlockRepresenters.size(); j++) {
			dist.push_back(pow(pow(BlockRepresenters[i].x - BlockRepresenters[j].x, 2)
				+ pow(BlockRepresenters[i].y - BlockRepresenters[j].y, 2), 0.5));
		}

		/* �R�s�[ */
		dist_copy = dist;

		/* ���ȉ��̋��������ꍇ�̂݊i�[ */
		for (int j = 0; j < BlockRepresenters.size(); ++j) {
			if (dist[j] < disGlobalTsd) {
				dist_parts.push_back(dist[j]);
			}
		}

		/* �����������Ƀ\�[�g */
		sort(dist_parts.begin(), dist_parts.end());

		/* �����̏��������Ƀu���b�N�̑�\���W���i�[ */
		for (int j = 0; j < dist_parts.size(); j++) {
			for (int k = 0; k < dist_copy.size(); k++) {

				if (dist_parts[j] == dist_copy[k]) {

					NeighborBlockPoints.push_back(BlockRepresenters_copy[k]);

					/* distances_parts�ɓ����������܂܂�Ă����ꍇ�ɈقȂ���W������Ă����悤�ɏ��� */
					dist_copy.erase(dist_copy.begin() + k);
					BlockRepresenters_copy.erase(BlockRepresenters_copy.begin() + k);

					break;
				}
			}
		}

		/* 2�̃}�[�J�[�̂Ȃ��p���i�[����x�N�g���̐錾 */
		vector<float> sita;
		sita.clear();


		/* �e�u���b�N�ɑ΂���p�x���v�Z���� */
		CalculateSita(NeighborBlockPoints, sita);

		/* neighbor��9�ŏ\�� */
		if (NeighborBlockPoints.size() > 9) {
			NeighborBlockPoints.erase(NeighborBlockPoints.begin() + 9, NeighborBlockPoints.end());
			sita.erase(sita.begin() + 9, sita.end());
			dist_parts.erase(dist_parts.begin() + 9, dist_parts.end());
		}

		/* �ߖT�ɑ��݂��Ȃ��u���b�N���폜 */
		DeleteBlock(NeighborBlockPoints, sita, dist_parts);

		/* ID�̒������������Ȃ�悤�ɏC�� */
		if (NeighborBlockPoints.size() > 6 && NeighborBlockPoints.size() < 9) {
			NeighborBlockPoints.erase(NeighborBlockPoints.begin() + 6, NeighborBlockPoints.end());
			sita.erase(sita.begin() + 5, sita.end());
		}
		else if (NeighborBlockPoints.size() > 4 && NeighborBlockPoints.size() < 6) {
			NeighborBlockPoints.erase(NeighborBlockPoints.begin() + 4, NeighborBlockPoints.end());
			sita.erase(sita.begin() + 3, sita.end());
		}

		/* ���v���Ƀ}�[�J�[����ׂ� */
		ArrangeNeighborBlock(NeighborBlockPoints, sita);

		/* �ߖT��Global�}�[�J�[�ɂ��ID�쐬 */
		string ID;
		MakeID(NeighborBlockPoints, ID, NumberOfRedBlock, NumberOfGreenBlock, NumberOfBlueBlock, NumberOfYellowBlock);

		/* ���t�@�����X���Q�Ƃ��ău���b�N����(LocalNumber = 1�̂�)�ɂ��ăe�N�X�`�����W�����߂� */
		Point2f GlobalUV;
		GetGlobalUV(ID, GlobalUV, IDs, IDs_index);

		/* �S�Ẵ}�[�J�[�ɂ���Local�Ɏ��ʂ��C�e�N�X�`�����W���擾���� */
		GetLocalUV(i, GlobalUV);
		IDs_input.push_back(ID);

#if 0 // �m�F�p
		cout << "---------------------" << i << "�Ԗڂ̃u���b�N�ɂ���" << "---------------------" << endl;
		cout << "���S�̃}�[�J�[�̍��W:  " << BlockRepresenters[i] << endl;
		cout << "�ߖT�̃}�[�J�[�̍��W:�@" << endl << NeighborBlockPoints << endl;;
		cout << "���o���ꂽ�}�[�J�[�ɑ΂���p�x:" << endl;
		for (int j = 0; j < sita.size(); ++j) {
			cout << sita[j] << "  ";
		}
		cout << endl;
		cout << "�쐬���ꂽID:  " << ID << endl;
		cout << "�擾����UV���W:  " << BlockUVs[i] << endl;
		cout << "LocalNumbers: ";
		for (int j = 0; j < BlockLocalNumbers[i].size(); ++j) {
			cout << BlockLocalNumbers[i][j] << " ";
		}
		cout << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << endl;
#endif

	}
}

void ColorBlock::MarkerSort(const vector<string> IDs_input, const vector<string> IDs, const vector<int> IDs_num)
{
#if 0
	cout << "/*----------------------------------SortedBlock-------------------------------------*/" << endl;
#endif

	/*---------------IDs(���t�@�����X)�̏��Ƀu���b�N����ёւ���------------------*/
	int total = 0;

	SortedBlockPoints.resize(wid_num*hei_num / 9);
	SortedBlockLocalNumbers.resize(wid_num*hei_num / 9);
	SortedBlockUVs.resize(wid_num*hei_num / 9);

	for (int i = 0; i < IDs_num.size(); ++i) {

		// ��T�C�Y
		Resize2();

		bool b = false; // ID�������������ǂ����̔���p

		for (int j = 0; j < IDs_num[i]; ++j) {

			for (int k = 0; k < IDs_input.size(); ++k) {

				if (IDs[total + j] == IDs_input[k]) {

					for (int l = 0; l < BlockPoints[k].size(); ++l) {
						SortedBlockPoints[i].push_back(BlockPoints[k][l]);
						SortedBlockUVs[i].push_back(BlockUVs[k][l]);
						SortedBlockLocalNumbers[i].push_back(BlockLocalNumbers[k][l]);
					}

					b = true;
					break;
				}
			}

			if (b == true) {
				break;
			}

			// ������Ȃ������ꍇ
			if (j == (IDs_num[i] - 1)) {
				SortedBlockPoints[i].push_back(Point2i(-1, -1));
				SortedBlockUVs[i].push_back(Point2i(-1, -1));
				SortedBlockLocalNumbers[i].push_back(-1);
			}

		}
#if 0 // �m�F�p
		cout << "---------------" << i << "�Ԗڂ̃u���b�N�ɂ���" << "------------------" << endl;
		cout << "[�}�[�J�[�̍��W]" << endl;
		cout << SortedBlockPoints[i] << endl;
		cout << "[�e�N�X�`�����W]" << endl;
		cout << SortedBlockUVs[i] << endl;
		cout << "[LocalNumbers]" << endl;
		for (int j = 0; j < SortedBlockLocalNumbers.size(); ++j) {
			cout << SortedBlockLocalNumbers[i][j] << endl;
		}
		cout << endl;
# endif

		total += IDs_num[i];
	}


	/* ----------�u���b�N������āC���W���Ƀ\�[�g���ꂽ�}�[�J��vector�����----------- */

	// ��`�̈�̏ꍇ�ɂ����g���Ȃ����ӁI�I
	int wid_num_block = wid_num / 3; // x�����̃u���b�N�̐�
	int hei_num_block = hei_num / 3; // y�����̃u���b�N�̐�

	for (int i = 0; i < hei_num_block; ++i) { // �u���b�N�̍s���Ƃ�

		// 1��2��3
		for (int j = 0; j < wid_num_block; ++j) { // �u���b�N�̗񂲂Ƃ�

			// 1��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 1) {
					SortedPoints[3 * i*wid_num + 3 * j] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[3 * i*wid_num + 3 * j] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[3 * i * wid_num + 3 * j] = 1;
					break;
				}
			}

			// 2��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 2) {
					SortedPoints[3 * i*wid_num + 3 * j + 1] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[3 * i*wid_num + 3 * j + 1] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[3 * i * wid_num + 3 * j + 1] = 2;
					break;
				}
			}

			// 3��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 3) {
					SortedPoints[3 * i*wid_num + 3 * j + 2] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[3 * i*wid_num + 3 * j + 2] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[3 * i * wid_num + 3 * j + 2] = 3;
					break;
				}
			}
		}

		// 4��5��6
		for (int j = 0; j < wid_num_block; ++j) { // �u���b�N�̗񂲂Ƃ�

			// 4��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 4) {
					SortedPoints[(3 * i + 1)*wid_num + 3 * j] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 1)*wid_num + 3 * j] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 1) * wid_num + 3 * j] = 4;
					break;
				}
			}

			// 5��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 5) {
					SortedPoints[(3 * i + 1)*wid_num + 3 * j + 1] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 1)*wid_num + 3 * j + 1] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 1) * wid_num + 3 * j + 1] = 5;
					break;
				}
			}

			// 6��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 6) {
					SortedPoints[(3 * i + 1)*wid_num + 3 * j + 2] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 1)*wid_num + 3 * j + 2] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 1) * wid_num + 3 * j + 2] = 6;
					break;
				}
			}
		}

		// 7��8��9
		for (int j = 0; j < wid_num_block; ++j) { // �u���b�N�̗񂲂Ƃ�

			// 7��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 7) {
					SortedPoints[(3 * i + 2)*wid_num + 3 * j] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 2)*wid_num + 3 * j] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 2) * wid_num + 3 * j] = 7;
					break;
				}
			}

			// 8��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 8) {
					SortedPoints[(3 * i + 2)*wid_num + 3 * j + 1] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 2)*wid_num + 3 * j + 1] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 2) * wid_num + 3 * j + 1] = 8;
					break;
				}
			}

			// 9��T��
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // �u���b�N���̊e�}�[�J�[�ɂ���				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 9) {
					SortedPoints[(3 * i + 2)*wid_num + 3 * j + 2] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 2)*wid_num + 3 * j + 2] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 2) * wid_num + 3 * j + 2] = 9;
					break;
				}
			}
		}

	}

#if 0
	cout << "------------------------------SortedPoints---------------------------------" << endl;
	cout << SortedPoints << endl;
	cout << endl;
	cout << "-------------------------------SortedUVs----------------------------------" << endl;
	cout << SortedUVs << endl;
	cout << endl;
#endif

}

/*-------------------------------------- Set�֐� ------------------------------------ */

void ColorBlock::SetNumberOfBlock(vector<Point2i>& Points, vector<int>& LocalNumbers, const int max)
{
	MaxIndex = 0;

	for (int i = 0; i < 9; ++i) {

		NumberOfEachLocalNumber[i] = 0;

		for (int j = 0; j < LocalNumbers.size(); ++j) {
			if (LocalNumbers[j] == (i + 1)) {
				NumberOfEachLocalNumber[i] += 1;
			}
		}
	}

	if (NumberOfEachLocalNumber[4] == max) {
		MaxIndex = 4;
	}
	else{
		for (int i = 0; i < 9; ++i) {
			if (NumberOfEachLocalNumber[i] == max) {
				MaxIndex = i;
			}
		}
	}

	// Set���� (�������C�����܂Ŋm���ɑ��݂���u���b�N�̐��Ȃ̂ő�����\��������)
	NumberOfBlock = NumberOfEachLocalNumber[MaxIndex];

	if (NumberOfBlock > max) {
		NumberOfBlock = max;
	}

	// ��F���ɂ���ău���b�N��max�𒴂����Ƃ��̏���
/*	if (NumberOfBlock > max) {
		for (int i = 0; i < 9; ++i) { // i�Ԗڂ�LocalNumber�ɂ���

			if (NumberOfEachLocalNumber[i] > max) {
				while (NumberOfEachLocalNumber[i] == max) {

					// i�Ԗڂ�LocalNumber�����}�[�J�[�̍��W
					vector<Point2f> PointsOfLocalNumberI;	PointsOfLocalNumberI.clear();

					for (int j = 0; j < NumberOfEachLocalNumber[i]; ++j) {
						for (int k = 0; k < LocalNumbers.size(); ++k) {

							if (LocalNumbers[k] == (i + 1)) {
								PointsOfLocalNumberI.push_back(Points[k]);
							}
						}
					}

					// �����v�Z
					vector<float> dists;	dists.clear();
					for (int j = 0; j < (NumberOfEachLocalNumber[i] - 1); ++j) {
						for (int k = j + 1; k < NumberOfEachLocalNumber[i]; ++k) {

							float dist = 0.0;

							dist = pow(pow(PointsOfLocalNumberI[j].x - PointsOfLocalNumberI[k].x, 2) + pow(PointsOfLocalNumberI[j].y - PointsOfLocalNumberI[k].y, 2), 0.5);

							dists.push_back(dist);
						}
					}

					// �\�[�g
					vector<float> dists_copy = dists;
					sort(dists_copy.begin(), dists_copy.end());
					dists.clear();

					// �T���E�폜
					for (int j = 0; j < (NumberOfEachLocalNumber[i] - 1); ++j) {
						for (int k = j + 1; k < NumberOfEachLocalNumber[i]; ++k) {

							float dist = 0.0;

							dist = pow(pow(PointsOfLocalNumberI[j].x - PointsOfLocalNumberI[k].x, 2) + pow(PointsOfLocalNumberI[j].y - PointsOfLocalNumberI[k].y, 2), 0.5);

							if (dist == dists_copy[0]) {
								if (i == 1) {
									if (PointsOfLocalNumberI[j].y > PointsOfLocalNumberI[k].y) {

									}
								}
								else if (i == 5) {

								}
								else if (i == 9) {

								}
							}
						}
					}
				}

			}
		}
	}*/
}

void ColorBlock::SetBlockMemberVariable(vector<int>& LocalNumbers, vector<Point2i>& Points)
{
	Resize1();

	/* �e�u���b�N�ɂ��āC�ԍ�MaxIndex�̂��ϐ����i�[���ď����� */

	for (int i = 0; i < NumberOfBlock; ++i) {
		for (int j = 0; j < LocalNumbers.size(); ++j) {

			if (LocalNumbers[j] == (MaxIndex + 1)) {

				// �u���b�N�ɒǉ�
				BlockPoints[i].push_back(Points[j]);
				BlockLocalNumbers[i].push_back(MaxIndex + 1);
				BlockRepresenters[i] = Points[j];

				// �폜
				Points.erase(Points.begin() + j);
				LocalNumbers.erase(LocalNumbers.begin() + j);
				break;
			}
		}
	}

	/*------------���̔ԍ��ɂ��Ă��u���b�N�Ɋi�[--------------*/

	// �ϐ��錾
	vector<int> StoredNumber;
	StoredNumber.clear();

	StoredNumber.push_back(MaxIndex + 1);

	int	NextLocalNumber; // ���Ɋi�[����ԍ�

	NextLocalNumber = (MaxIndex + 1); // ������

	while (StoredNumber.size() != 9) {

		int count = 0; //�ď��������������K�v

		NextLocalNumber = Next(StoredNumber, NextLocalNumber);

		StoredNumber.push_back(NextLocalNumber);

		for (int i = 0; i < LocalNumbers.size(); ++i) {

			if (LocalNumbers[i] == NextLocalNumber) {

				vector<float> dist;
				int MindistIndex = 0; // �ł������̏������u���b�N�̔ԍ�

				// �����v�Z
				for (int j = 0; j < NumberOfBlock; ++j) {
					dist.push_back(pow(pow(BlockRepresenters[j].x - Points[i].x, 2) + pow(BlockRepresenters[j].y - Points[i].y, 2), 0.5));
				}

				// �ł����������������̂�T��
				if (dist.size() > 1) {

					for (int j = 1; j < dist.size(); ++j) {
						if (dist[MindistIndex] > dist[j]) {
							MindistIndex = j;
						}
					}
				}
				if (dist.size() > 0) {
					if (dist[MindistIndex] < disGroupingTsd) {

						// �u���b�N�ɒǉ�
	//					cout << MindistIndex << endl;
						BlockPoints[MindistIndex].push_back(Points[i]);
						BlockLocalNumbers[MindistIndex].push_back(NextLocalNumber);
						count++;
	//					cout << count << endl;

						BlockRepresenters[MindistIndex] = Points[i];

					}
				}
			}
		}
	}

	// �ŏI�I�ȃu���b�N�̑�\���W�̓����o�̕��ς�p����
	for (int i = 0; i < BlockPoints.size(); ++i) {
		BlockRepresenters[i] = Point2i(0, 0); // �ď�����

		for (int j = 0; j < BlockPoints[i].size(); ++j) {
			BlockRepresenters[i].x += (BlockPoints[i][j].x / BlockPoints[i].size());
			BlockRepresenters[i].y += (BlockPoints[i][j].y / BlockPoints[i].size());
		}
	}

	/* �u���b�N�̃����o�����������`�F�b�N */
	CheckBlock(BlockPoints, BlockLocalNumbers, BlockRepresenters);

	// �ŏI�I�ȃu���b�N�̑�\���W�̓����o�̕��ς�p����
	for (int i = 0; i < BlockPoints.size(); ++i) {
		BlockRepresenters[i] = Point2i(0, 0); // �ď�����

		for (int j = 0; j < BlockPoints[i].size(); ++j) {
			BlockRepresenters[i].x += (BlockPoints[i][j].x / BlockPoints[i].size());
			BlockRepresenters[i].y += (BlockPoints[i][j].y / BlockPoints[i].size());
		}
	}

}

void ColorBlock::SetAllBlockMemberVariable(const vector<vector<Point2i>> AddedBlockPoints,
	const vector<vector<int>> AddedBlockLocalNumbers,
	const vector<Point2i> AddedBlockRepresenters)
{
	for (int i = 0; i < AddedBlockPoints.size(); ++i) {
		BlockPoints.push_back(AddedBlockPoints[i]);
		BlockLocalNumbers.push_back(AddedBlockLocalNumbers[i]);
		BlockRepresenters.push_back(AddedBlockRepresenters[i]);
	}
}

/*----------------------------------------------------------------------------------- */

/*-------------------------------------- Get�֐� ------------------------------------ */

vector<vector<Point2i>> ColorBlock::GetBlockPoints()
{
	return vector<vector<Point2i>>(BlockPoints);
}

vector<vector<int>> ColorBlock::GetBlockLocalNumbers()
{
	return vector<vector<int>>(BlockLocalNumbers);
}

vector<Point2i> ColorBlock::GetBlockRepresenters()
{
	return vector<Point2i>(BlockRepresenters);
}

vector<vector<Point2f>> ColorBlock::GetBlockUVs()
{
	return vector<vector<Point2f>>(BlockUVs);
}

Point2i ColorBlock::GetSortedPoints(const int i)
{
	return SortedPoints[i];
}

Point2f ColorBlock::GetSortedUVs(const int i)
{
	return SortedUVs[i];
}

int ColorBlock::GetSortedLocalNumbers(const int i)
{
	return SortedLocalNumbers[i];
}

int ColorBlock::GetNumberOfBlock()
{
	return NumberOfBlock;
}

/*----------------------------------------------------------------------------------- */

void ColorBlock::ShowMemberVariable()
{
	cout << "/*--------------------------------------Block-----------------------------------------*/" << endl;
	for (int i = 0; i < NumberOfBlock; ++i) {
		cout << "-----------------�u���b�N" << i << "------------------" << endl;
		cout << "[LocalNumber]" << endl;
		for (int j = 0; j < BlockLocalNumbers[i].size(); ++j) {
			cout << BlockLocalNumbers[i][j] << "  ";
		}
		cout << endl;
		cout << "[�}�[�J�[�̍��W]" << endl;
		cout << BlockPoints[i] << endl;
		cout << "[��\���W]" << endl;
		cout << BlockRepresenters[i] << endl;
		cout << "--------------------------------------------" << endl;
	}
}
