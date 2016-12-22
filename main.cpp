#pragma once

#include "stdafx.h"

/*-----------------------���O���-----------------------------*/

using namespace cv;
using namespace std;

/*------------------------------------------------------------*/


/*-----------------------�ϐ��錾-----------------------------*/

/* Mat */
Mat img, hsv, mask; // RGB��HSV�摜
Mat red, green, blue, black, yellow, syan, magenta, all; //�F���Ƃ�2�l�摜
Mat shade; // �A�e���(HSV��Value�̒l���i�[)

/* �}�[�J�[�̎��ϐ� */
vector<Point2i> RedPoints, GreenPoints, BluePoints, BlackPoints, YellowPoints, SyanPoints, MagentaPoints, Points;	// �d�S���W
vector<int> RedLocalNumbers, GreenLocalNumbers, BlueLocalNumbers, BlackLocalNumbers; // Local�Ȕԍ�(1�`9)
vector<int> nLabels; // ���x���̗̈搔

/* �N���X */
ColorMarker *RedMarker, *GreenMarker, *BlueMarker, *BlackMarker;
ColorBlock *AllBlock, *RedBlock, *GreenBlock, *BlueBlock, *BlackBlock;
RBFT *rbft;

/* Block�̐� */
int NumberOfRedBlock = 0, NumberOfGreenBlock = 0, NumberOfBlueBlock = 0, NumberOfBlackBlock = 0;

/* ���x�����O���ꂽ�̈�̐� */
int NumOfRegions = 0;

/* ���t�@�����X���Ƀ\�[�g���ꂽ�}�[�J�[�̈ʒu����уe�N�X�`�����W */
vector<Point2i> SortedPoints;
vector<Point2f> SortedUVs;
vector<int> SortedLocalNumbers;

/* 2,1�t���[���O�̒��_�ʒu�ƕό`�O�̍��W(RBFT�p) */
vector<Point2i> Points2FrameBack, Points1FrameBack, CenterPoints;

/* �o�͂��郁�b�V���̒��_���W�ƃe�N�X�`�����W */
vector<Point2i> InputPoints, OutputPoints;
vector<Point2f> OutputUVs;

/* ���͉摜����ǂݎ����IDs */
vector<string> IDs_input;

/* ���t�@�����X */
vector<string> IDs; // ID�̗���
vector<Point2i> IDs_index; // ID�ɑΉ������}�[�J�[�̔ԍ�
vector<int> IDs_num; // �e�u���b�N������ID�̐�

/* �O�t���[���̐F���Ƃ̏d�S���W�E�e�N�X�`�����W�ELocalNumber (�g���b�L���O�p) */
vector<Point2i> PreviousPoints;
vector<Point2f> PreviousUVs;
vector<int> PreviousLocalNumbers;
vector<bool> trackingIndex;
vector<Point2i> trackingPoints;
bool bTrack = false;

/* �t���[���ԍ� */
int tt = 0;

/* ����쐬�p */
std::vector<Mat> frames1, frames2, frames3;

/* ���ʗ��]���̂��߂̕ϐ� */
int Denom = 0; // ����
int Numer = 0; // ���q
float Percent = 0; // ������
vector<float> Percents;

/* �}�[�J�̎��F��Hue�l */
int Color[CLASS] = {

	0, // ��(����)
	30, // ��(�O��)
	60, // ��(����)
	90, // �V�A��(�O��)
	120, // ��(����)
	150 // �}�[���^(�O��)

	// + ��(����)
};

/*------------------------------------------------------------*/

/*--------------------����t�@�C���̑I��----------------------*/

#if 1 // ����
//VideoCapture cap(0); // �E�F�u�J����
VideoCapture cap(InputVideo);
#endif

/*------------------------------------------------------------*/

/*----------------------�������֐�--------------------------*/

/* �O���[�o���ϐ������� */
void initialize() {

	RedPoints.clear(), GreenPoints.clear(), BluePoints.clear(), BlackPoints.clear();
	YellowPoints.clear(), SyanPoints.clear(), MagentaPoints.clear();

	RedLocalNumbers.clear(), GreenLocalNumbers.clear(), BlueLocalNumbers.clear(), BlackLocalNumbers.clear();

	nLabels.clear();
	NumOfRegions = 0;

	NumberOfRedBlock = NumberOfGreenBlock = NumberOfBlueBlock = NumberOfBlackBlock = 0;

	IDs_input.clear();

	SortedPoints.clear(), SortedPoints.resize(wid_num*hei_num);
	for (int i = 0; i < SortedPoints.size(); ++i) {
		SortedPoints[i] = Point2i(-1, -1);
	}
	SortedUVs.clear(), SortedUVs.resize(wid_num*hei_num);
	for (int i = 0; i < SortedUVs.size(); ++i) {
		SortedUVs[i] = Point2f(-1.0, -1.0);
	}
	SortedLocalNumbers.clear(), SortedLocalNumbers.resize(wid_num*hei_num);
	for (int i = 0; i < SortedLocalNumbers.size(); ++i) {
		SortedLocalNumbers[i] = -1;
	}

	OutputPoints.clear();

	trackingIndex.resize(wid_num*hei_num);
	for (int i = 0; i < trackingIndex.size(); ++i) {
		trackingIndex[i] = true;
	}
	trackingPoints.clear();
}

/* ���t�@�����X�̓ǂݍ��� */
void IDs_Reader(vector<string>& IDs) {

	ifstream ifs("data/input/real/cloth/IDs.txt");
	string buf;

	while (ifs && getline(ifs, buf)) {
		IDs.push_back(buf);
	}

#if 0
	/* �m�F�p�ɏo�� */
	cout << "-----------���t�@�����X�Ƃ��Ă�ID-----------" << endl;
	for (int i = 0; i < IDs.size(); ++i) {
		cout << IDs[i].c_str() << endl;
	}
	cout << IDs.size() << endl;
#endif

}
void IDs_index_Reader(vector<Point2i>& IDs_index) {

	ifstream ifs("data/input/real/cloth/IDs_index.txt");
	string buf;

	// ��s���ǂݍ���
	while (ifs && getline(ifs, buf)) {
		vector<int> p;
		p.clear();

		string tmp;
		istringstream stream(buf);

		// �J���}�����ڂɕ�������
		while (getline(stream, tmp, ',')) {

			// ������𐔎��ɕϊ�����
			auto num = atoi(tmp.c_str());
			p.push_back(num);
		}

		IDs_index.push_back(Point2i(p[0], p[1]));

	}

#if 0
	/* �m�F�p�ɏo�� */
	cout << "-----------���t�@�����X�Ƃ��Ă�ID��Index-----------" << endl;
	for (int i = 0; i < IDs_index.size(); ++i) {
		cout << IDs_index[i] << endl;
	}
	cout << IDs_index.size() << endl;
#endif

}
void IDs_num_Reader(vector<int>& IDs_num) {

	ifstream ifs("data/input/real/cloth/IDs_num.txt");
	string buf;

	// ��s���ǂݍ���
	while (ifs && getline(ifs, buf)) {

		// ������𐔎��ɕϊ�����
		int num = atoi(buf.c_str());

		IDs_num.push_back(num);
	}


#if 0
	/* �m�F�p�ɏo�� */
	cout << "-----------���t�@�����X�Ƃ��Ă�ID�̂܂Ƃ܂�̐�-----------" << endl;
	for (int i = 0; i < IDs_num.size(); ++i) {
		cout << IDs_num[i] << endl;
	}
	cout << IDs_num.size() << endl;
#endif

}

/* �e�N�X�`���̓ǂݍ��� */
bool LoadGLTextures()
{
	Mat tex = imread(TexturePath);

	cv::cvtColor(tex, tex, CV_BGR2RGB);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXWIDTH, TEXHEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, tex.data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);

	return true;
}

/* k-means�@�ɂ��RGB�l�̊w�K */
void kmeans(Mat src) {

	Mat dst(Size(src.cols, src.rows), CV_8UC3); //�o�͉摜

	// �w�K�p�̃N���X
	int Color_buf[CLASS];

	// ���W���i�[����x�N�g��
	vector<vector<Point2i>> classes(CLASS);

	// ��f�l�Ԃ�distance
	int dist[CLASS];

	double error = 0;

	// �w�K��
	int num = 1;

	while (1) {
		std::cout << "�w�K�񐔁F" << num << endl;

		vector<vector<Point2i>> classes_buf(CLASS);

		// �ŋߖT�ŃN���X����
		for (int y = 0; y < src.rows; ++y) {
			for (int x = 0; x < src.cols; ++x) {

				int class_num = -1;

				// �e�N���X�ɕ��ނ������W���i�[
				for (int k = 0; k < classes_buf.size(); ++k) {
					if (k == class_num) {
						classes_buf[k].push_back(Point2i(x, y));
					}
				}

			}
		}

		// �e�N���X�ɐV�������σx�N�g���𐶐�
		float buf = 0;

		for (int i = 0; i < classes_buf.size(); ++i) {

			// �e�N���X�ɏ�������S�Ă̍��W�ɂ��ĉ�f�l�𑫂����킹��
			for (int j = 0; j < classes_buf[i].size(); ++j) {
				buf += (float)src.at<uchar>(classes_buf[i][j].y, classes_buf[i][j].x);
			}

			if (classes_buf[i].size() == 0) {
				Color_buf[i] = Color[i];
			}
			else {
				buf /= classes_buf[i].size();

				Color_buf[i] = (int)buf;
			}

			// ������
			buf = 0;
		}

		error = 0;

		for (int i = 0; i < classes_buf.size(); ++i) {
			error += sqrt(pow(Color[i] - Color_buf[i], 2));
			// �X�V
			Color[i] = Color_buf[i];
		}


		for (int i = 0; i < classes_buf.size(); ++i) {
			std::cout << "Color[" << i << "]" << endl;
			std::cout << Color[i] << ", ";
			std::cout << endl;
		}

		num++;

		if (error < 50) {
			for (int i = 0; i < classes_buf.size(); ++i) {
				copy(classes_buf[i].begin(), classes_buf[i].end(), back_inserter(classes[i]));
			}
			break;
		}

	}

#if 0
	for (int i = 0; i < classes.size(); ++i) {
		for (int j = 0; j < classes[i].size(); ++j) {
			for (int c = 0; c < 3; ++c) {
				dst.at<Vec3b>(classes[i][j].y, classes[i][j].x)[c] = Color[i][c];
			}
		}
	}

	// ����
	imshow("src", src);
	imshow("dst", dst);
#endif
}

/* �F���o����щA�e���̒��o */
void ColorDetector()
{
	/* ������ */
	red = Mat::zeros(img.size(), CV_8UC1), green = Mat::zeros(img.size(), CV_8UC1), blue = Mat::zeros(img.size(), CV_8UC1), black = Mat::zeros(img.size(), CV_8UC1);
	yellow = Mat::zeros(img.size(), CV_8UC1), syan = Mat::zeros(img.size(), CV_8UC1), magenta = Mat::zeros(img.size(), CV_8UC1); all = Mat::zeros(img.size(), CV_8UC1);

	vector<Mat> planes;
	split(hsv, planes);

	shade = planes[2];

	/* ��f���ƂɃN���X���� */
	for (int y = 0; y < Height; ++y) {
		for (int x = 0; x < Width; ++x) {

			int class_num = -1; // �N���X�̔ԍ�

			if (planes[2].at<uchar>(y, x) < 30) class_num = 6; // ��
			else if (planes[1].at<uchar>(y, x) > 100 && planes[2].at<uchar>(y, x) > 60) { // ���ƍ��ȊO�̉�f�ɂ���

				// �ߖT�N���X�ɑ΂��鋗��
				float dist1, dist2;

				/* Color[0]�̒l�ŏꍇ���� */
				if (Color[0] < Color[1]) {

					if (0 <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[0]) {

						dist1 = planes[0].at<uchar>(y, x) - (Color[5] - 180);
						dist2 = Color[0] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 0;
						else class_num = 5;
					}
					else if (Color[0] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[1]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[0];
						dist2 = Color[1] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 1;
						else class_num = 0;
					}
					else if (Color[1] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[2]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[1];
						dist2 = Color[2] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 2;
						else class_num = 1;
					}
					else if (Color[2] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[3]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[2];
						dist2 = Color[3] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 3;
						else class_num = 2;
					}
					else if (Color[3] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[4]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[3];
						dist2 = Color[4] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 4;
						else class_num = 3;
					}
					else if (Color[4] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[5]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[4];
						dist2 = Color[5] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 5;
						else class_num = 4;
					}
					else if (Color[5] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= 180) {

						dist1 = planes[0].at<uchar>(y, x) - Color[5];
						dist2 = (Color[0] + 180) - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 0;
						else class_num = 5;
					}

				}
				else if (Color[5] < Color[0]) {

					if (0 <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[1]) {

						dist1 = planes[0].at<uchar>(y, x) - (Color[0] - 180);
						dist2 = Color[1] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 1;
						else class_num = 0;
					}
					else if (Color[1] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[2]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[1];
						dist2 = Color[2] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 2;
						else class_num = 1;
					}
					else if (Color[2] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[3]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[2];
						dist2 = Color[3] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 3;
						else class_num = 2;
					}
					else if (Color[3] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[4]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[3];
						dist2 = Color[4] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 4;
						else class_num = 3;
					}
					else if (Color[4] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[5]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[4];
						dist2 = Color[5] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 5;
						else class_num = 4;
					}
					else if (Color[5] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= Color[0]) {

						dist1 = planes[0].at<uchar>(y, x) - Color[5];
						dist2 = Color[0] - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 0;
						else class_num = 5;
					}
					else if (Color[0] <= planes[0].at<uchar>(y, x) && planes[0].at<uchar>(y, x) <= 180) {

						dist1 = planes[0].at<uchar>(y, x) - Color[0];
						dist2 = (Color[1] + 180) - planes[0].at<uchar>(y, x);

						if (dist1 > dist2) class_num = 1;
						else class_num = 0;
					}

				}
			}

			/* �N���X���Ƃ�Mat�쐬 */
			if (class_num == 0) {
				red.at<uchar>(y, x) = 255;
				all.at<uchar>(y, x) = 255;
			}
			else if (class_num == 2) {
				green.at<uchar>(y, x) = 255;
				all.at<uchar>(y, x) = 255;
			}
			else if (class_num == 4) {
				blue.at<uchar>(y, x) = 255;
				all.at<uchar>(y, x) = 255;
			}
			else if (class_num == 6) {
				black.at<uchar>(y, x) = 255;
				all.at<uchar>(y, x) = 255;
			}
			else if (class_num == 1) {
				yellow.at<uchar>(y, x) = 255;
				all.at<uchar>(y, x) = 255;
			}
			else if (class_num == 3) {
				syan.at<uchar>(y, x) = 255;
				all.at<uchar>(y, x) = 255;
			}
			else if (class_num == 5) {
				magenta.at<uchar>(y, x) = 255;
				all.at<uchar>(y, x) = 255;
			}
		}
	}

	/* �m�C�Y�����炷���� */
	cv::medianBlur(red, red, 5);
	cv::morphologyEx(red, red, MORPH_CLOSE, Mat(), Point(-1, -1), 4);
	cv::medianBlur(green, green, 5);
	cv::morphologyEx(green, green, MORPH_CLOSE, Mat(), Point(-1, -1), 4);
	cv::medianBlur(blue, blue, 5);
	cv::morphologyEx(blue, blue, MORPH_CLOSE, Mat(), Point(-1, -1), 4);
	cv::medianBlur(black, black, 5);
	cv::morphologyEx(black, black, MORPH_CLOSE, Mat(), Point(-1, -1), 4);
	cv::medianBlur(yellow, yellow, 5);
	cv::morphologyEx(yellow, yellow, MORPH_CLOSE, Mat(), Point(-1, -1), 4);
	cv::medianBlur(syan, syan, 5);
	cv::morphologyEx(syan, syan, MORPH_CLOSE, Mat(), Point(-1, -1), 4);
	cv::medianBlur(magenta, magenta, 5);
	cv::morphologyEx(magenta, magenta, MORPH_CLOSE, Mat(), Point(-1, -1), 4);
	//morphologyEx(all, all, MORPH_CLOSE, Mat(), Point(-1, -1), 3);
	cv::dilate(all, all, Mat(), Point(-1, -1), 3);

#if 1 // �m�F�p
	cv::imshow("red", red);
	cv::imshow("green", green);
	cv::imshow("blue", blue);
	cv::imshow("black", black);
	cv::imshow("yellow", yellow);
	cv::imshow("syan", syan);
	cv::imshow("magenta", magenta);
	cv::imshow("all", all);
	cv::imshow("shade", shade);
#endif
}

/* �}�[�J�����̖��x��� */
void ShadeInterpolation()
{
	/* ���x�����O�p�̕ϐ��錾 */
	Mat label(img.size(), CV_32S);
	Mat stats, centroids;

	/* ���x�����O���s */
	int nLabel = connectedComponentsWithStats(all, label, stats, centroids);

	// ���x�����O���ʂ̕`��F������
	std::vector<cv::Vec3b> colors(nLabel);
	colors[0] = cv::Vec3b(0, 0, 0);
	for (int i = 1; i < nLabel; ++i) {
		colors[i] = cv::Vec3b((rand() & 255), (rand() & 255), (rand() & 255));
	}

	// ���x�����O���ʂ̕`��
	cv::Mat Dst(img.size(), CV_8UC3);
	for (int i = 0; i < Dst.rows; ++i) {
		int *lb = label.ptr<int>(i);
		cv::Vec3b *pix = Dst.ptr<cv::Vec3b>(i);
		for (int j = 0; j < Dst.cols; ++j) {
			pix[j] = colors[lb[j]];
		}
	}

	/* RBF�N���X�ɊeROI��Mat��n���ĕ�Ԃ��� */
#ifdef _OPENMP
#pragma omp parallel for 
#endif
	for (int i = 1; i < nLabel; ++i) {

		int *param = stats.ptr<int>(i);

		int lt_x = param[cv::ConnectedComponentsTypes::CC_STAT_LEFT]; // left top��x���W
		int lt_y = param[cv::ConnectedComponentsTypes::CC_STAT_TOP]; // left top��y���W
		int height = param[cv::ConnectedComponentsTypes::CC_STAT_HEIGHT];
		int width = param[cv::ConnectedComponentsTypes::CC_STAT_WIDTH];

		if (param[cv::ConnectedComponentsTypes::CC_STAT_AREA] > 200 && param[cv::ConnectedComponentsTypes::CC_STAT_AREA] < 7000) {

			// �}�[�J������؂蔲��
			for (int y = lt_y; y < lt_y + height; ++y) {
				for (int x = lt_x; x < lt_x + width; ++x) {
					if (all.at<uchar>(y, x) == 255) {
						shade.at<uchar>(y, x) = 0;
					}
				}
			}

			// �o�E���f�B���O�{�b�N�X�̑傫���𒲐�
			lt_x -= 0, lt_y -= 0, width += 0, height += 0;

			cv::rectangle(Dst, cv::Rect(lt_x, lt_y, width, height), cv::Scalar(0, 255, 0), 2);

			Mat ROI = Mat(Size(width, height), CV_8UC1);

			// shade�̈ꕔ��ROI�ɑ��
			int shade_y = 0, shade_x = 0;
			for (int y = 0; y < height; ++y) {
				shade_x = 0;
				for (int x = 0; x < width; ++x) {
					ROI.at<uchar>(y, x) = shade.at<uchar>(lt_y + shade_y, lt_x + shade_x);
					++shade_x;
				}
				++shade_y;
			}
#if 0
			imshow("���x��ԑO", ROI);
			waitKey(0);
#endif
			// RBF��Ԏ��s
			int N = 0;
			for (int y = 0; y < ROI.rows; ++y) {
				for (int x = 0; x < ROI.cols; ++x) {
					if (ROI.at<uchar>(y, x) != 0) {
						N++;
					}
				}
			}
			if (N != 0) {
				RBF *rbf; // ���񕶂̒�����Ȃ��ƃG���[�N����
				rbf = new RBF;
				rbf->Exe(ROI);
				delete rbf;
			}
#if 0

			imshow("���x��Ԍ�", ROI);
#endif

			// RBF��Ԃ̌��ʂ���
			shade_y = 0, shade_x = 0;
			for (int y = lt_y; y < lt_y + height; ++y) {
				shade_x = 0;
				for (int x = lt_x; x < lt_x + width; ++x) {
					shade.at<uchar>(y, x) = ROI.at<uchar>(shade_y, shade_x);
					++shade_x;
				}
				++shade_y;
			}

			/* �g���b�L���O�p�Ɋe���׃����O�̈�̏d�S���W���i�[ */
			double *param1 = centroids.ptr<double>(i);
			trackingPoints.push_back(Point2i(static_cast<int>(param1[0]), static_cast<int>(param1[1])));
		}
	}

	/* ���x�����O���ʂ̏o�� */
	imshow("labels", Dst);

}

/* ���̖ʐψȏ�̃��x�����O�̈�̏d�S���W���i�[ */
void LabelRegister(Mat stats, Mat centroids, int& nLabel, vector<Point2i>& ColorPoints)
{
	// ���̖ʐψȏ�̃��x�����O�̈�̐�
	int num = 0;

	/* �e���x�����O�̈�ɂ��� */
	for (int i = 1; i < nLabel; ++i) {

		int *param1 = stats.ptr<int>(i);
		double *param2 = centroids.ptr<double>(i);

		// ���̖ʐψȏ�̏ꍇ�d�S��o�^
		if (param1[ConnectedComponentsTypes::CC_STAT_AREA] > minareaTsd && maxareaTsd > param1[ConnectedComponentsTypes::CC_STAT_AREA]) {

			int x = static_cast<int>(param2[0]);
			int y = static_cast<int>(param2[1]);

			num += 1;

			ColorPoints.push_back(Point2i(x, y));
			nLabels.push_back(param1[ConnectedComponentsTypes::CC_STAT_AREA]);


#if 0 // �m�F�p
			cout << "area " << i << " = " << param1[ConnectedComponentsTypes::CC_STAT_AREA]
				<< ", center:(" << x << ", " << y << ")" << endl;
#endif
		}
	}

	nLabel = num;
}

/* �F���ƂɃ��x�����O���� */
void ColorLabeling(const Mat color, vector<Point2i>& ColorPoints) 
{
	/* ���x�����O�p�̕ϐ��錾 */
	Mat label(img.size(), CV_32S);
	Mat stats, centroids;

	/* ���x�����O���s */
	int nLabel = connectedComponentsWithStats(color, label, stats, centroids); // �Ԃ�l��background���܂񂾗̈搔

	/* ���̖ʐς������x�����O�̈�̏d�S���W���i�[ */
	LabelRegister(stats, centroids, nLabel, ColorPoints);

	/* ���x�����O�̈�̍��v�����v�Z*/
	NumOfRegions += nLabel;
}

/* 1�ӏ���2�̃}�[�J�[�����݂��Ȃ��悤�ɃG���[���� */
void CheckMarker() {

	vector<Point2i> AllPoints; AllPoints.clear();

	for (int i = 0; i < RedPoints.size(); ++i) AllPoints.push_back(RedPoints[i]);
	for (int i = 0; i < GreenPoints.size(); ++i) AllPoints.push_back(GreenPoints[i]);
	for (int i = 0; i < BluePoints.size(); ++i) AllPoints.push_back(BluePoints[i]);
	for (int i = 0; i < BlackPoints.size(); ++i) AllPoints.push_back(BlackPoints[i]);

	vector<int> DeleteIndex; DeleteIndex.clear();// AllPoints�ɂ��ď����ׂ��ԍ�

	for (int i = 0; i < AllPoints.size(); ++i) {

		for (int j = (i + 1); j < AllPoints.size(); ++j) {

			float dis = pow(pow(AllPoints[i].x - AllPoints[j].x, 2) + pow(AllPoints[i].y - AllPoints[j].y, 2), 0.5);

			// �߂��ꍇ�C�ʐϏ����������i�[
			if (dis < 10) {
				if (nLabels[i] > nLabels[j]) {
					DeleteIndex.push_back(j);
				}
				else if (nLabels[j] > nLabels[i]) {
					DeleteIndex.push_back(i);
				}
			}
		}
	}

#if 0
	for (int i = 0; i < DeleteIndex.size(); ++i) {
		std::cout << DeleteIndex[i] << endl;
	}
#endif

	int NumOfRedMarker = RedPoints.size(), NumOfGreenMarker = GreenPoints.size(), NumOfBlueMarker = BluePoints.size(), NumOfBlackMarker = BlackPoints.size();

	if (DeleteIndex.size() > 0) {

		// �����Ƀ\�[�g
		if (DeleteIndex.size() > 1) {
			sort(DeleteIndex.begin(), DeleteIndex.end());
			reverse(DeleteIndex.begin(), DeleteIndex.end());
		}

		// �����ԍ����������݂����Ƃ��̂��߂̃G���[����
		int previousIndex = -1;

		// �F���Ƃɕ�����
		for (int i = 0; i < DeleteIndex.size(); ++i) {
#if 0
			cout << DeleteIndex[i] << endl;
			cout << previousIndex << endl;
#endif
			//�����ԍ���2������Ȃ����߂�
			if (previousIndex != DeleteIndex[i]) {

				if (DeleteIndex[i] < NumOfRedMarker) {
					RedPoints.erase(RedPoints.begin() + DeleteIndex[i]);
				}
				else if (DeleteIndex[i] >= NumOfRedMarker && DeleteIndex[i] < (NumOfRedMarker + NumOfGreenMarker)) {
					GreenPoints.erase(GreenPoints.begin() + (DeleteIndex[i] - NumOfRedMarker));
				}
				else if (DeleteIndex[i] >= (NumOfRedMarker + NumOfGreenMarker) && DeleteIndex[i] < (NumOfRedMarker + NumOfGreenMarker + NumOfBlueMarker)) {
					BluePoints.erase(BluePoints.begin() + (DeleteIndex[i] - NumOfRedMarker - NumOfGreenMarker));
				}
				else if (DeleteIndex[i] >= (NumOfRedMarker + NumOfGreenMarker + NumOfBlueMarker)) {
					BlackPoints.erase(BlackPoints.begin() + (DeleteIndex[i] - NumOfRedMarker - NumOfGreenMarker - NumOfBlueMarker));
				}

			}
			previousIndex = DeleteIndex[i];
		}

	}
}

/* ���x�����O */
void Labeling() {

	/* �F���ƂɃ��x�����O���s */
	ColorLabeling(red, RedPoints);
	ColorLabeling(green, GreenPoints);
	ColorLabeling(blue, BluePoints);
	ColorLabeling(black, BlackPoints);
	ColorLabeling(yellow, YellowPoints);
	ColorLabeling(syan, SyanPoints);
	ColorLabeling(magenta, MagentaPoints);

	/* 1�ӏ���2�̃}�[�J�[�����݂��Ȃ��悤�ɏ��� */
	CheckMarker();

#if 0 // �m�F�p�ɏo��
	std::cout << "-------------RedPoints---------------" << endl;
	std::cout << RedPoints << endl;
	std::cout << "�T�C�Y��" << RedPoints.size() << endl;
	std::cout << "-------------GreenPoints--------------" << endl;
	std::cout << GreenPoints << endl;
	std::cout << "�T�C�Y��" << GreenPoints.size() << endl;
	std::cout << "-------------BluePoints---------------" << endl;
	std::cout << BluePoints << endl;
	std::cout << "�T�C�Y��" << BluePoints.size() << endl;
	std::cout << "-------------BlackPoints-------------" << endl;
	std::cout << BlackPoints << endl;
	std::cout << "�T�C�Y��" << BlackPoints.size() << endl;
	std::cout << "-------------YellowPoints-------------" << endl;
	std::cout << YellowPoints << endl;
	std::cout << "�T�C�Y��" << YellowPoints.size() << endl;
	std::cout << "-------------SyanPoints--------------" << endl;
	std::cout << SyanPoints << endl;
	std::cout << "�T�C�Y��" << SyanPoints.size() << endl;
	std::cout << "------------MagentaPoints-----------" << endl;
	std::cout << MagentaPoints << endl;
	std::cout << "�T�C�Y��" << MagentaPoints.size() << endl;
	std::cout << "------------------------------------" << endl;
	std::cout << "���x�����O���ꂽ�̈搔�̑��a: " << NumOfRegions << endl;
	std::cout << endl;
#endif

}

/* �����̐F�ƊO���̐F���}�[�J�[���ɂ܂Ƃ߂� */
void GroupingMarker() {

	// ���W��Set
	RedMarker->SetOuterColorPoints(RedPoints, YellowPoints, SyanPoints, MagentaPoints);
	GreenMarker->SetOuterColorPoints(GreenPoints, YellowPoints, SyanPoints, MagentaPoints);
	BlueMarker->SetOuterColorPoints(BluePoints, YellowPoints, SyanPoints, MagentaPoints);
	BlackMarker->SetOuterColorPoints(BlackPoints, YellowPoints, SyanPoints, MagentaPoints);

	// �F���ƂɃO���[�v����
	RedMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);
	GreenMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);
	BlueMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);
	BlackMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);

#if 0 // �m�F�p�ɏo��
	cout << "---------------RedMarker----------------" << endl;
	RedMarker->ShowMemberVariable();

	cout << "--------------GreenMarker---------------" << endl;
	GreenMarker->ShowMemberVariable();

	cout << "--------------BlueMarker----------------" << endl;
	BlueMarker->ShowMemberVariable();

	cout << "--------------BlackMarker---------------" << endl;
	BlackMarker->ShowMemberVariable();
#endif
}

/* �F���ƂɃu���b�N�̃O���[�s���O���s�� */
void RedGroupingBlock() {

	RedPoints = RedMarker->GetColorPoints();
	RedLocalNumbers = RedMarker->GetColorLocalNumbers();

	delete RedMarker;

	RedBlock->SetNumberOfBlock(RedPoints, RedLocalNumbers, MaxNumberOfRedBlock);
	RedBlock->SetBlockMemberVariable(RedLocalNumbers, RedPoints);
	AllBlock->SetAllBlockMemberVariable(RedBlock->GetBlockPoints(), RedBlock->GetBlockLocalNumbers(), RedBlock->GetBlockRepresenters());
	NumberOfRedBlock = RedBlock->GetNumberOfBlock();

#if 0
	RedBlock->ShowMemberVariable();
#endif

	delete RedBlock;
}
void GreenGroupingBlock() {

	GreenPoints = GreenMarker->GetColorPoints();
	GreenLocalNumbers = GreenMarker->GetColorLocalNumbers();

	delete GreenMarker;

	GreenBlock->SetNumberOfBlock(GreenPoints, GreenLocalNumbers, MaxNumberOfGreenBlock);
	GreenBlock->SetBlockMemberVariable(GreenLocalNumbers, GreenPoints);
	AllBlock->SetAllBlockMemberVariable(GreenBlock->GetBlockPoints(), GreenBlock->GetBlockLocalNumbers(), GreenBlock->GetBlockRepresenters());
	NumberOfGreenBlock = GreenBlock->GetNumberOfBlock();

#if 0
	GreenBlock->ShowMemberVariable();
#endif

	delete GreenBlock;
}
void BlueGroupingBlock() {

	BluePoints = BlueMarker->GetColorPoints();
	BlueLocalNumbers = BlueMarker->GetColorLocalNumbers();

	delete BlueMarker;

	BlueBlock->SetNumberOfBlock(BluePoints, BlueLocalNumbers, MaxNumberOfBlueBlock);
	BlueBlock->SetBlockMemberVariable(BlueLocalNumbers, BluePoints);
	AllBlock->SetAllBlockMemberVariable(BlueBlock->GetBlockPoints(), BlueBlock->GetBlockLocalNumbers(), BlueBlock->GetBlockRepresenters());
	NumberOfBlueBlock = BlueBlock->GetNumberOfBlock();

#if 0
	BlueBlock->ShowMemberVariable();
#endif

	delete BlueBlock;
}
void BlackGroupingBlock() {

	BlackPoints = BlackMarker->GetColorPoints();
	BlackLocalNumbers = BlackMarker->GetColorLocalNumbers();

	delete BlackMarker;

	BlackBlock->SetNumberOfBlock(BlackPoints, BlackLocalNumbers, MaxNumberOfBlackBlock);
	BlackBlock->SetBlockMemberVariable(BlackLocalNumbers, BlackPoints);
	AllBlock->SetAllBlockMemberVariable(BlackBlock->GetBlockPoints(), BlackBlock->GetBlockLocalNumbers(), BlackBlock->GetBlockRepresenters());
	NumberOfBlackBlock = BlackBlock->GetNumberOfBlock();

#if 0
	BlackBlock->ShowMemberVariable();
#endif

	delete BlackBlock;
}

/* 9�ȉ��̃}�[�J�[�̏W����P�ʂƂ����u���b�N�ɕ����� */
void GroupingBlock() {

	/* �F���ł����}�[�J�̑��� */
	Denom = RedMarker->GetNumberOfMarker() + GreenMarker->GetNumberOfMarker() + BlueMarker->GetNumberOfMarker() + BlackMarker->GetNumberOfMarker();

	// �F���ƂɃO���[�s���O���s��
	RedGroupingBlock();
	GreenGroupingBlock();
	BlueGroupingBlock();
	BlackGroupingBlock();

#if 0
	AllBlock->ShowMemberVariable();
#endif

}

/* ��Ď�@�̃R�A���� */
void ProposedMethod() {

	/* Marker�N���X�̃������m�� */
	RedMarker = new ColorMarker, GreenMarker = new ColorMarker, BlueMarker = new ColorMarker, BlackMarker = new ColorMarker;

	/* ���x�����O�̈���}�[�J�[�P�ʂɕ����CLocalNumber�����肷�� */
	GroupingMarker();

	/* Block�N���X�̃������m�� */
	RedBlock = new ColorBlock, GreenBlock = new ColorBlock; BlueBlock = new ColorBlock; BlackBlock = new ColorBlock;
	AllBlock = new ColorBlock;

	/* �O���[�v��� */
	GroupingBlock();

	/* �}�[�J�[���� */
	AllBlock->GlobalIdentify(IDs, IDs_index, IDs_input, NumberOfRedBlock, NumberOfGreenBlock, NumberOfBlueBlock, NumberOfBlackBlock);
}

/* �g���b�L���O���s */
void Tracking() 
{
#if 0
	for (int i = 0; i < PreviousPoints.size(); ++i) {
		cout << PreviousPoints[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < trackingPoints.size(); ++i) {
		cout << trackingPoints[i] << endl;
	}
#endif

	if (bTrack == true && trackingPoints.size() > 0 && PreviousPoints.size() > 0) {

		for (int i = 0; i < trackingPoints.size()>0; ++i) {

			vector<float> TrackingDis;
			TrackingDis.clear();

			for (int j = 0; j < PreviousPoints.size(); ++j) {
				TrackingDis.push_back(pow(pow(PreviousPoints[j].x - trackingPoints[i].x, 2) + pow(PreviousPoints[j].y - trackingPoints[i].y, 2), 0.5));
			}

			int minIndex = 0;
			for (int j = 1; j < TrackingDis.size(); ++j) {
				if (TrackingDis[minIndex] > TrackingDis[j]) {
					minIndex = j;
				}
			}

			// �g���b�L���O�����̏ꍇLocalNumber�������p��
			if (TrackingDis[minIndex] < trackTsd) {
#if 0
				std::cout << trackingPoints[i] << "�ɑΉ�������W: " << PreviousPoints[minIndex] << endl;
#endif
				SortedPoints[minIndex] = trackingPoints[i];
				SortedUVs[minIndex] = PreviousUVs[minIndex];
				SortedLocalNumbers[minIndex] = PreviousLocalNumbers[minIndex];
			}
		}
	}

}

/* ���_���W�EUV���W�ELocalNumbers�̈����p��(�g���b�L���O�p) */
void Record()
{
	// �ď�����
	PreviousPoints.clear();
	PreviousUVs.clear();
	PreviousLocalNumbers.clear();

	for (int i = 0; i < SortedPoints.size(); ++i) {
		if (SortedPoints[i].x != -1) {
			PreviousPoints.push_back(SortedPoints[i]);
			PreviousUVs.push_back(SortedUVs[i]);
			PreviousLocalNumbers.push_back(SortedLocalNumbers[i]);
		}
	}
}

/* �e�N�X�`���}�b�s���O */
void TextureMapping2() {

	glColor4f(1.0, 1.0, 1.0, 0.5);
	glEnable(GL_TEXTURE_2D);
	//	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);

	for (int i = 0; i < (wid_num - 1) * mesh_num; ++i) {

		glBegin(GL_TRIANGLES);

		for (int j = 0; j < (wid_num - 1) * mesh_num; ++j) {

			glTexCoord2f(OutputUVs[((wid_num - 1) * mesh_num + 1) * i + j].x, OutputUVs[((wid_num - 1) * mesh_num + 1) * i + j].y);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + j].y - Height / 2), 0);

			glTexCoord2f(OutputUVs[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].x, OutputUVs[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].y);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].y - Height / 2), 0);

			glTexCoord2f(OutputUVs[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].x, OutputUVs[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].y);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].y - Height / 2), 0);


			glTexCoord2f(OutputUVs[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].x, OutputUVs[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].y);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].y - Height / 2), 0);

			glTexCoord2f(OutputUVs[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].x, OutputUVs[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].y);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].y - Height / 2), 0);

			glTexCoord2f(OutputUVs[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].x, OutputUVs[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].y);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].y - Height / 2), 0);
		}

		glEnd();
	}

	glDisable(GL_TEXTURE_2D);
}

/* ���� */
void PointVisualization()
{
	glPointSize(32.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < SortedPoints.size(); ++i) {
		
		if (trackingIndex[i] == true) {
			glColor3f(1.0, 0.0, 0.0);
		}
		else {
			glColor3f(0.15, 0.15, 0.15);
		}

		if (SortedPoints[i].x != -1) {
			glVertex3i(SortedPoints[i].x - Width / 2, -(SortedPoints[i].y - Height / 2), 0);
		}
	}
	glEnd();
}
void MeshVisualization()
{
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.3, 0.3, 0.3);

	for (int i = 0; i < (wid_num - 1) * mesh_num; ++i) {
		for (int j = 0; j < (wid_num - 1) * mesh_num; ++j) {

			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + j].y - Height / 2), 0);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].y - Height / 2), 0);

			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].y - Height / 2), 0);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].y - Height / 2), 0);

			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].y - Height / 2), 0);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + j].y - Height / 2), 0);

			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + j].y - Height / 2), 0);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].y - Height / 2), 0);

			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * (i + 1) + (j + 1)].y - Height / 2), 0);
			glVertex3i(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].x - Width / 2, -(OutputPoints[((wid_num - 1) * mesh_num + 1) * i + (j + 1)].y - Height / 2), 0);
		}
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
}

/* ����쐬 */
void makeVideo(vector<Mat>& frames, const string name_input, const string name_output) {

	Mat frame = imread(name_input);
	frames.push_back(frame);

	if (tt == LastFrame) {
		videowriter(name_output, frames, LastFrame, fps);
	}
}

/* �V�F�[�f�B���O */
void Shading(string name, const int tt)
{
	stringstream ss;
	ss << tt;

	Mat shadeRGB_input, shadeRGB_output;
	Mat shadeHSV_input, shadeHSV_output;
	vector<Mat> planes;

	shadeRGB_input = imread(name);
	cvtColor(shadeRGB_input, shadeHSV_input, CV_BGR2HSV);
	split(shadeHSV_input, planes);

	imshow("shade(��Ԍ�)", shade);

	for (int y = 0; y < shadeHSV_input.rows; ++y) {
		for (int x = 0; x < shadeHSV_input.cols; ++x) {

			if (planes[2].at<uchar>(y, x) != shade.at<uchar>(y, x)) {
				planes[2].at<uchar>(y, x) = (float)planes[2].at<uchar>(y, x) * ((float)shade.at<uchar>(y, x) / 255.0);
			}
		}
	}

	merge(planes, shadeHSV_output);

	cvtColor(shadeHSV_output, shadeRGB_output, CV_HSV2BGR);

	string shadedImg = TextureImagePath + ss.str() + ".bmp";
	imwrite(shadedImg, shadeRGB_output);

#if 1 // �m�F�p
	imshow("Shading", shadeRGB_output);
#endif
}


/*----------------------------------------------------------*/


/*---------------------�R�[���o�b�N�֐�---------------------*/

static void init()
{
	/* �w�i�F */
	glClearColor(0.0, 0.0, 0.0, 1.0);

	/* ���t�@�����X�̓ǂݍ��� */
	IDs_Reader(IDs);
	IDs_index_Reader(IDs_index);
	IDs_num_Reader(IDs_num);

	/* �e�N�X�`���̓ǂݍ��� */
	LoadGLTextures();

	/* k-means�@�Ŋw�K������摜�̓ǂݍ��� */
	Mat src;

#if 0 // �摜�̏ꍇ
	//	img = imread(name);
	src = imread("data/self-occlusion.png");
#endif

#if 1 // ����̏ꍇ
	/* �G���[���� */
	if (!cap.isOpened()) {
		std::cout << " Can't open movie" << endl;
	}
	cap >> src;
#endif

	//kmeans(src);

	/* InputPoints, OutputUVs�̐ݒ� */
	for (int i = 0; i < (wid_num - 1)*mesh_num + 1; ++i) {
		for (int j = 0; j < (wid_num - 1)*mesh_num + 1; ++j) {
			InputPoints.push_back(Point2i(35 + j * 10, 35 + i * 10));
		}
	}
	for (int i = 0; i < (wid_num - 1)*mesh_num + 1; ++i) {
		for (int j = 0; j < (wid_num - 1)*mesh_num + 1; ++j) {
			OutputUVs.push_back(Point2f(j * (1.0 / ((wid_num - 1)*mesh_num)), i * (1.0 / ((wid_num - 1)*mesh_num))));
		}
	}
	for (int i = 0; i < hei_num; ++i) {
		for (int j = 0; j < wid_num; ++j) {
			CenterPoints.push_back(Point2i(35 + j * 50, 35 + i * 50)); // ���ڐݒ肷��K�v����
		}
	}

	/* ������ */
	Points1FrameBack.clear();
	Points2FrameBack.clear();
	frames1.clear(), frames2.clear(), frames3.clear();
}

static void display()
{
	/* StartFrame�܂ł�����΂� */
	if (tt < StartFrame) {
		cap >> img;
		++tt;
	}

	else {

		glClear(GL_COLOR_BUFFER_BIT);

		/* ������ */
		initialize();

		/* �t�@�C���̓ǂݍ���-------------------------------- */

#if 1 // �t���[����A���I�ɓǂݍ��ނ��ǂ���
		stringstream ss;
		//string name ="data/bitmap/"+ ss.str() + ".bmp";
		ss << tt;
#endif

#if 0 // �摜�̏ꍇ
		//	img = imread(name);
		img = imread("data/self-occlusion.png");
#endif

#if 1 // ����̏ꍇ
		cap >> img;
#endif
		/* -------------------------------------------------- */

		/* RGB-->HSV */
		cv::cvtColor(img, hsv, CV_BGR2HSV);

		/* �F���o */
		ColorDetector();

		//imwrite(ShadeImagePath, shade);

		/* �}�[�J�����̖��x��� */
		ShadeInterpolation();

		/* ���x�����O */
		Labeling();

		/* ��Ď�@(�}�[�J�̃O���[�s���O���u���b�N�̎��ʁ��}�[�J�̎���) */
		ProposedMethod();

		/* IDs(���t�@�����X)�̏��ɕ��ёւ� */
		AllBlock->MarkerSort(IDs_input, IDs, IDs_num);

		/* �g���b�L���O */
		Tracking();

		/* �g���b�L���O�Ɏ��s�����}�[�J�ɂ��Ă�Block�̌��ʂ�Get */
		for (int i = 0; i < SortedPoints.size(); ++i) {
			if (SortedPoints[i].x == -1 && AllBlock->GetSortedPoints(i).x != -1) {
				SortedPoints[i] = AllBlock->GetSortedPoints(i);
				SortedUVs[i] = AllBlock->GetSortedUVs(i);
				SortedLocalNumbers[i] = AllBlock->GetSortedLocalNumbers(i);
				trackingIndex[i] = false;
			}
		}
		delete AllBlock;

		/* ���ʂł����}�[�J���Ȃ��ꍇ�̓g���b�L���O������������ */
		bool bTrack = false;
		for (int i = 0; i < SortedPoints.size(); ++i) {
			if (SortedPoints[i].x != -1) {
				bTrack = true;
				break;
			}
		}

		/* �ړ��ʂ̑傫���O��l������ */
		if (tt>StartFrame && bTrack == true) {
			for (int i = 0; i < SortedPoints.size(); ++i) {
				if (SortedPoints[i].x != -1) {

					int move_dis = pow(pow(SortedPoints[i].x - Points1FrameBack[i].x, 2) + pow(SortedPoints[i].y - Points1FrameBack[i].y, 2), 0.5);

					if (move_dis > moveTsd) {
						SortedPoints[i] = Point2i(-1, -1);
					}
				}
			}
		}

		/* �g���b�L���O�̂��߂ɒ��_���W�EUV���W�ELocalNumber��ۑ� */
		Record();

		/* RBFT------------------------------------------------------------ */

		rbft = new RBFT;
		rbft->SetTimeWidth(SortedPoints, Points1FrameBack, Points2FrameBack);
		rbft->SetX(SortedPoints, Points1FrameBack, Points2FrameBack);
		OutputPoints = rbft->Exe(InputPoints); // �e�N�X�`���}�b�s���O�p

		// ���t���[���̂��߂̐ݒ�
		if (bTrack == true) {
			Points2FrameBack = Points1FrameBack;
			Points1FrameBack = rbft->Exe(CenterPoints);
		}
		else if (bTrack == false) {
			Points1FrameBack.clear();
		}

		delete rbft;

		/* ----------------------------------------------------------------- */


		/* 3��ނ̉摜�Ɠ����ۑ�----------------------------------------------------------------------------------------------- */

		// openCV����openGL�ɓn��
		cv::flip(img, img, 0);
		cv::cvtColor(img, img, CV_BGR2RGB);

		// �e�N�X�`���}�b�s���O���s���摜��ۑ�����
		glDrawPixels(img.cols, img.rows, GL_RGB, GL_UNSIGNED_BYTE, img.data);
		TextureMapping2();

		string ImageOutput_texture = TextureImagePath + ss.str() + ".bmp";
		WriteBitmap(ImageOutput_texture.c_str(), Width, Height);


		// 1��(�e�N�X�`���Ȃ��E���b�V������)
		glDrawPixels(img.cols, img.rows, GL_RGB, GL_UNSIGNED_BYTE, img.data);
		MeshVisualization();
		PointVisualization();

		string ImageOutput_mesh = MeshImagePath + ss.str() + ".bmp";
		WriteBitmap(ImageOutput_mesh.c_str(), Width, Height);

		string VideoOutput_mesh = MeshVideoPath;
//		makeVideo(frames2, ImageOutput_mesh, VideoOutput_mesh);


		// 2��(�e�N�X�`������E���b�V���Ȃ�)
		Shading(ImageOutput_texture, tt);
		string VideoOutput_texture = TextureVideoPath;
		makeVideo(frames1, ImageOutput_texture, VideoOutput_texture);


		// 3��(�e�N�X�`������E���b�V������)
		Mat shadedImg = imread(ImageOutput_texture); // 1�ڂ̉摜�̓ǂݍ���
		cv::flip(shadedImg, shadedImg, 0);
		cv::cvtColor(shadedImg, shadedImg, CV_BGR2RGB);

		glDrawPixels(shadedImg.cols, shadedImg.rows, GL_RGB, GL_UNSIGNED_BYTE, shadedImg.data);
		MeshVisualization();
		PointVisualization();

		string ImageOutput_meshontexture = MeshOnTextureImagePath + ss.str() + ".bmp";
		WriteBitmap(ImageOutput_meshontexture.c_str(), Width, Height);

		string VideoOutput_meshontexture = MeshOnTextureVideoPath;
		makeVideo(frames3, ImageOutput_meshontexture, VideoOutput_meshontexture);

		// shade
		cv::imwrite(InterpolationShadeImagePath, shade);

		/* ------------------------------------------------------------------------------------------------------------------ */


#if 0  // ���ʗ��̕]�� 
		for (int i = 0; i < SortedPoints.size(); ++i) {
			if (SortedPoints[i].x != -1) {
				Numer++;
			}
		}
		Percent = (float)Numer / (float)Denom;
		Percents.push_back(Percent);

		/* �������� */
		if (tt == LastFrame) {
			ofstream ofs("data/output/simpleocclusion/Percents.txt");

			for (int i = 0; i < Percents.size(); ++i) {
				ofs << Percents[i] << endl;
			}

		}
#endif

		/* �t���[���ԍ��̏o�� */
		std::cout << "�t���[���ԍ�: " << tt << endl;
		++tt;
	}

	glFlush();
	if ((tt - 1) == LastFrame) {
		exit(0);
	}
}

static void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key) {
		/* q �� Q �� ESC ���^�C�v������I�� */
	case '\033':
	case 'q':
	case 'Q':
		exit(0);
	default:
		break;
	}
}

/*----------------------------------------------------------*/


/*-------------------------main��---------------------------*/

int main(int argc, char *argv[])
{
	/* glfw������ */
	glfwInit();
	glutInit(&argc, argv);

	GLFWwindow* window = glfwCreateWindow(Width, Height, "Retexturing", NULL, NULL);

	/* �J�����g��ʂ̐ݒ�(�e�N�X�`����GPU�������Ɋi�[����Ă��邽��) */
	glfwMakeContextCurrent(window);

	init();

	glfwSetKeyCallback(window, keyboard);

	/* �ˉe�ϊ�(GL��CV�̃X�P�[������v������) */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-Width / 2, Width / 2, -Height / 2, Height / 2, -1, 1);

	while (!glfwWindowShouldClose(window)) {
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
//		waitKey(0);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

/*----------------------------------------------------------*/