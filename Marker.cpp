#include "Marker.h"

/* �O���̐F�z�u�ɑΉ�����Local�Ȕԍ���Ԃ�*/
int LocalNumberIdentify(const string local) {

	/* �}�[�J�[�̊O���̐F�z�u�ɑΉ�����Local�Ȕԍ���Ԃ� */
	if (local == "Yellow") {
		return 1;
	}
	else if (local == "SyanMagenta") {
		return 2;
	}
	else if (local == "MagentaSyan") {
		return 3;
	}
	else if (local == "MagentaYellow") {
		return 4;
	}
	else if (local == "Syan") {
		return 5;
	}
	else if (local == "YellowMagenta") {
		return 6;
	}
	else if (local == "SyanYellow") {
		return 7;
	}
	else if (local == "YellowSyan") {
		return 8;
	}
	else if (local == "Magenta") {
		return 9;
	}
	else {
		return 0;
	}
}

/* �R���X�g���N�^ */
ColorMarker::ColorMarker()
{
	ColorPoints.clear();
	LocalNumbers.clear();

	YellowPoints.clear();
	SyanPoints.clear();
	MagentaPoints.clear();
}

void ColorMarker::Grouping(const vector<Point2i> PreviousPoints, const vector<int> PreviousLocalNumbers, vector<Point2i>& SortedPoints, const int tt, const bool bTrack)
{
	vector<int> DeleteColorPointsIndex; // ��������ԍ�(OuterPoints�̃T�C�Y��0�̂��)
	DeleteColorPointsIndex.clear();

	for (int i = 0; i < ColorPoints.size(); ++i) {

		OuterPoints.clear();
		OuterColor.clear();

		for (int j = 0; j < YellowPoints.size(); ++j) {
			float dist = 0;

			dist = pow(pow(ColorPoints[i].x - YellowPoints[j].x, 2) + pow(ColorPoints[i].y - YellowPoints[j].y, 2), 0.5);

			if (dist < disLocalTsd) {
				OuterPoints.push_back(YellowPoints[j]);
				OuterColor.push_back("Yellow");
				break;
			}
		}
		for (int j = 0; j < SyanPoints.size(); ++j) {
			float dist = 0;

			dist = pow(pow(ColorPoints[i].x - SyanPoints[j].x, 2) + pow(ColorPoints[i].y - SyanPoints[j].y, 2), 0.5);

			if (dist < disLocalTsd) {
				OuterPoints.push_back(SyanPoints[j]);
				OuterColor.push_back("Syan");
				break;
			}
		}

		for (int j = 0; j < MagentaPoints.size(); ++j) {
			float dist = 0;

			dist = pow(pow(ColorPoints[i].x - MagentaPoints[j].x, 2) + pow(ColorPoints[i].y - MagentaPoints[j].y, 2), 0.5);

			if (dist < disLocalTsd) {
				OuterPoints.push_back(MagentaPoints[j]);
				OuterColor.push_back("Magenta");
				break;
			}
		}


		// �G���[����
		if (OuterPoints.size() > 2) {
			
			bool b = 0; // �F�̃_�u�肪���邩�ǂ����̔���p

			for (int j = 0; j < OuterColor.size(); ++j) {
				cout << OuterColor[j] << endl;
			}

			for (int j = 0; j < OuterColor.size(); ++j) {
				if (find(OuterColor.begin() + j + 1, OuterColor.end(), OuterColor[j]) != OuterColor.end()) {
					b = 1;
					break;
				}
			}

			// �F�̃_�u�肪����̂ŏ���
			while (b) {
				b = 0;
				for (int j = 0; j < (OuterPoints.size() - 1); ++j) {
					bool loop = false;
					string str = OuterColor[j];

					for (int k = j + 1; k < OuterPoints.size(); ++k) {
						if (str == OuterColor[k]) {
							OuterPoints.erase(OuterPoints.begin() + k);
							OuterColor.erase(OuterColor.begin() + k);
							loop = true;
							break;
						}
					}
					if (loop == true) {
						break;
					}
				}

				for (int j = 0; j < OuterColor.size(); ++j) {
					if (find(OuterColor.begin() + j + 1, OuterColor.end(), OuterColor[j]) != OuterColor.end()) {
						b = 1;
						break;
					}
				}
			}

			// �F�̃_�u��͂Ȃ��̂ŋ������������̂�����
			if (b == 0) {
				vector<float> dis; dis.clear();
				for (int j = 0; j < OuterPoints.size(); ++j) {
					dis.push_back(pow(ColorPoints[i].x - OuterPoints[j].x, 2) + pow(ColorPoints[i].y - OuterPoints[j].y, 2));
				}
				if (dis[0] > dis[1] && dis[0] > dis[2]) {
					OuterPoints.erase(OuterPoints.begin());
					OuterColor.erase(OuterColor.begin());
				}
				else if (dis[1] > dis[0] && dis[1] > dis[2]) {
					OuterPoints.erase(OuterPoints.begin() + 1);
					OuterColor.erase(OuterColor.begin() + 1);
				}
				else {
					OuterPoints.erase(OuterPoints.begin() + 2);
					OuterColor.erase(OuterColor.begin() + 2);
				}
			}
		}

		bool b1 = false;

		if (OuterPoints.empty()) {
			DeleteColorPointsIndex.push_back(i);
			b1 = true;
		}

		bool b2 = false;

		if (OuterPoints.size() >= 1) {
			if (OuterPoints.size() == 1) {
				local = OuterColor[0];
			}
			else if (OuterPoints[0].y < OuterPoints[1].y) {
				local = OuterColor[0] + OuterColor[1];
			}
			else if (OuterPoints[0].y > OuterPoints[1].y) {
				local = OuterColor[1] + OuterColor[0];
			}

			LocalNumber = LocalNumberIdentify(local);
			LocalNumbers.push_back(LocalNumber);		
			b2 = true;
		}


		/* �g���b�L���O���s��, LocalNumber���擾���� */
		if (bTrack == true && b1 == false) {
			vector<float> TrackingDis;
			TrackingDis.clear();

			for (int j = 0; j < PreviousPoints.size(); ++j) {
				TrackingDis.push_back(pow(pow(PreviousPoints[j].x - ColorPoints[i].x, 2) + pow(PreviousPoints[j].y - ColorPoints[i].y, 2), 0.5));
			}

			int minIndex = 0;
			for (int j = 1; j < TrackingDis.size(); ++j) {
				if (TrackingDis[minIndex] > TrackingDis[j]) {
					minIndex = j;
				}
			}

			// �g���b�L���O�����̏ꍇLocalNumber�������p��
			if (TrackingDis.size() > 0 && TrackingDis[minIndex] < trackTsd) {
#if 0
				std::cout << ColorPoints[i] << "�ɑΉ�������W: " << PreviousPoints[minIndex] << endl;
#endif
				if (b2 == true && LocalNumbers.size() > 0) {
					LocalNumbers.pop_back();
				}
				LocalNumbers.push_back(PreviousLocalNumbers[minIndex]);
			}
		}
	}

	// ����
	if (! DeleteColorPointsIndex.empty()) {
		reverse(DeleteColorPointsIndex.begin(), DeleteColorPointsIndex.end());
		for (int i = 0; i < DeleteColorPointsIndex.size(); ++i) {
			ColorPoints.erase(ColorPoints.begin() + DeleteColorPointsIndex[i]);
		}
	}
}

void ColorMarker::SetOuterColorPoints(const vector<Point2i> InterColorPoints, const vector<Point2i> OuterColorPoints1, const vector<Point2i> OuterColorPoints2, const vector<Point2i> OuterColorPoints3)
{
	ColorPoints = InterColorPoints;
	YellowPoints = OuterColorPoints1;
	SyanPoints = OuterColorPoints2;
	MagentaPoints = OuterColorPoints3;
}

vector<Point2i> ColorMarker::GetColorPoints()
{
	return vector<Point2i>(ColorPoints);
}

vector<int> ColorMarker::GetColorLocalNumbers()
{
	return vector<int>(LocalNumbers);
}

int ColorMarker::GetNumberOfMarker()
{
	return int(ColorPoints.size());
}

void ColorMarker::ShowMemberVariable()
{
	cout << "[���W]" << endl;
	cout << ColorPoints << endl;
	cout << "[LocalNumbers]" << endl;
	for (int i = 0; i < LocalNumbers.size(); ++i) {
		cout << LocalNumbers[i] << "  ";
	}
	cout << endl;
	cout << "�T�C�Y: " << ColorPoints.size() << endl;
}
