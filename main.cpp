#pragma once

#include "stdafx.h"

/*-----------------------名前空間-----------------------------*/

using namespace cv;
using namespace std;

/*------------------------------------------------------------*/


/*-----------------------変数宣言-----------------------------*/

/* Mat */
Mat img, hsv, mask; // RGBとHSV画像
Mat red, green, blue, black, yellow, syan, magenta, all; //色ごとの2値画像
Mat shade; // 陰影情報(HSVのValueの値を格納)

/* マーカーの持つ変数 */
vector<Point2i> RedPoints, GreenPoints, BluePoints, BlackPoints, YellowPoints, SyanPoints, MagentaPoints, Points;	// 重心座標
vector<int> RedLocalNumbers, GreenLocalNumbers, BlueLocalNumbers, BlackLocalNumbers; // Localな番号(1～9)
vector<int> nLabels; // ラベルの領域数

/* クラス */
ColorMarker *RedMarker, *GreenMarker, *BlueMarker, *BlackMarker;
ColorBlock *AllBlock, *RedBlock, *GreenBlock, *BlueBlock, *BlackBlock;
RBFT *rbft;

/* Blockの数 */
int NumberOfRedBlock = 0, NumberOfGreenBlock = 0, NumberOfBlueBlock = 0, NumberOfBlackBlock = 0;

/* ラベリングされた領域の数 */
int NumOfRegions = 0;

/* リファレンス順にソートされたマーカーの位置およびテクスチャ座標 */
vector<Point2i> SortedPoints;
vector<Point2f> SortedUVs;
vector<int> SortedLocalNumbers;

/* 2,1フレーム前の頂点位置と変形前の座標(RBFT用) */
vector<Point2i> Points2FrameBack, Points1FrameBack, CenterPoints;

/* 出力するメッシュの頂点座標とテクスチャ座標 */
vector<Point2i> InputPoints, OutputPoints;
vector<Point2f> OutputUVs;

/* 入力画像から読み取ったIDs */
vector<string> IDs_input;

/* リファレンス */
vector<string> IDs; // IDの羅列
vector<Point2i> IDs_index; // IDに対応したマーカーの番号
vector<int> IDs_num; // 各ブロックが持つIDの数

/* 前フレームの色ごとの重心座標・テクスチャ座標・LocalNumber (トラッキング用) */
vector<Point2i> PreviousPoints;
vector<Point2f> PreviousUVs;
vector<int> PreviousLocalNumbers;
vector<bool> trackingIndex;
vector<Point2i> trackingPoints;
bool bTrack = false;

/* フレーム番号 */
int tt = 0;

/* 動画作成用 */
std::vector<Mat> frames1, frames2, frames3;

/* 識別率評価のための変数 */
int Denom = 0; // 分母
int Numer = 0; // 分子
float Percent = 0; // 成功率
vector<float> Percents;

/* マーカの持つ色のHue値 */
int Color[CLASS] = {

	0, // 赤(内側)
	30, // 黄(外側)
	60, // 緑(内側)
	90, // シアン(外側)
	120, // 青(内側)
	150 // マゼンタ(外側)

	// + 黒(内側)
};

/*------------------------------------------------------------*/

/*--------------------動画ファイルの選択----------------------*/

#if 1 // 動画
//VideoCapture cap(0); // ウェブカメラ
VideoCapture cap(InputVideo);
#endif

/*------------------------------------------------------------*/

/*----------------------もろもろ関数--------------------------*/

/* グローバル変数初期化 */
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

/* リファレンスの読み込み */
void IDs_Reader(vector<string>& IDs) {

	ifstream ifs("data/input/real/cloth/IDs.txt");
	string buf;

	while (ifs && getline(ifs, buf)) {
		IDs.push_back(buf);
	}

#if 0
	/* 確認用に出力 */
	cout << "-----------リファレンスとしてのID-----------" << endl;
	for (int i = 0; i < IDs.size(); ++i) {
		cout << IDs[i].c_str() << endl;
	}
	cout << IDs.size() << endl;
#endif

}
void IDs_index_Reader(vector<Point2i>& IDs_index) {

	ifstream ifs("data/input/real/cloth/IDs_index.txt");
	string buf;

	// 一行ずつ読み込む
	while (ifs && getline(ifs, buf)) {
		vector<int> p;
		p.clear();

		string tmp;
		istringstream stream(buf);

		// カンマを境目に分割する
		while (getline(stream, tmp, ',')) {

			// 文字列を数字に変換する
			auto num = atoi(tmp.c_str());
			p.push_back(num);
		}

		IDs_index.push_back(Point2i(p[0], p[1]));

	}

#if 0
	/* 確認用に出力 */
	cout << "-----------リファレンスとしてのIDのIndex-----------" << endl;
	for (int i = 0; i < IDs_index.size(); ++i) {
		cout << IDs_index[i] << endl;
	}
	cout << IDs_index.size() << endl;
#endif

}
void IDs_num_Reader(vector<int>& IDs_num) {

	ifstream ifs("data/input/real/cloth/IDs_num.txt");
	string buf;

	// 一行ずつ読み込む
	while (ifs && getline(ifs, buf)) {

		// 文字列を数字に変換する
		int num = atoi(buf.c_str());

		IDs_num.push_back(num);
	}


#if 0
	/* 確認用に出力 */
	cout << "-----------リファレンスとしてのIDのまとまりの数-----------" << endl;
	for (int i = 0; i < IDs_num.size(); ++i) {
		cout << IDs_num[i] << endl;
	}
	cout << IDs_num.size() << endl;
#endif

}

/* テクスチャの読み込み */
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

/* k-means法によるRGB値の学習 */
void kmeans(Mat src) {

	Mat dst(Size(src.cols, src.rows), CV_8UC3); //出力画像

	// 学習用のクラス
	int Color_buf[CLASS];

	// 座標を格納するベクトル
	vector<vector<Point2i>> classes(CLASS);

	// 画素値間のdistance
	int dist[CLASS];

	double error = 0;

	// 学習回数
	int num = 1;

	while (1) {
		std::cout << "学習回数：" << num << endl;

		vector<vector<Point2i>> classes_buf(CLASS);

		// 最近傍でクラス分類
		for (int y = 0; y < src.rows; ++y) {
			for (int x = 0; x < src.cols; ++x) {

				int class_num = -1;

				// 各クラスに分類される座標を格納
				for (int k = 0; k < classes_buf.size(); ++k) {
					if (k == class_num) {
						classes_buf[k].push_back(Point2i(x, y));
					}
				}

			}
		}

		// 各クラスに新しい平均ベクトルを生成
		float buf = 0;

		for (int i = 0; i < classes_buf.size(); ++i) {

			// 各クラスに所属する全ての座標について画素値を足し合わせる
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

			// 初期化
			buf = 0;
		}

		error = 0;

		for (int i = 0; i < classes_buf.size(); ++i) {
			error += sqrt(pow(Color[i] - Color_buf[i], 2));
			// 更新
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

	// 結果
	imshow("src", src);
	imshow("dst", dst);
#endif
}

/* 色検出および陰影情報の抽出 */
void ColorDetector()
{
	/* 初期化 */
	red = Mat::zeros(img.size(), CV_8UC1), green = Mat::zeros(img.size(), CV_8UC1), blue = Mat::zeros(img.size(), CV_8UC1), black = Mat::zeros(img.size(), CV_8UC1);
	yellow = Mat::zeros(img.size(), CV_8UC1), syan = Mat::zeros(img.size(), CV_8UC1), magenta = Mat::zeros(img.size(), CV_8UC1); all = Mat::zeros(img.size(), CV_8UC1);

	vector<Mat> planes;
	split(hsv, planes);

	shade = planes[2];

	/* 画素ごとにクラス分類 */
	for (int y = 0; y < Height; ++y) {
		for (int x = 0; x < Width; ++x) {

			int class_num = -1; // クラスの番号

			if (planes[2].at<uchar>(y, x) < 30) class_num = 6; // 黒
			else if (planes[1].at<uchar>(y, x) > 100 && planes[2].at<uchar>(y, x) > 60) { // 白と黒以外の画素について

				// 近傍クラスに対する距離
				float dist1, dist2;

				/* Color[0]の値で場合分け */
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

			/* クラスごとにMat作成 */
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

	/* ノイズを減らす処理 */
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

#if 1 // 確認用
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

/* マーカ部分の明度補間 */
void ShadeInterpolation()
{
	/* ラベリング用の変数宣言 */
	Mat label(img.size(), CV_32S);
	Mat stats, centroids;

	/* ラベリング実行 */
	int nLabel = connectedComponentsWithStats(all, label, stats, centroids);

	// ラベリング結果の描画色を決定
	std::vector<cv::Vec3b> colors(nLabel);
	colors[0] = cv::Vec3b(0, 0, 0);
	for (int i = 1; i < nLabel; ++i) {
		colors[i] = cv::Vec3b((rand() & 255), (rand() & 255), (rand() & 255));
	}

	// ラベリング結果の描画
	cv::Mat Dst(img.size(), CV_8UC3);
	for (int i = 0; i < Dst.rows; ++i) {
		int *lb = label.ptr<int>(i);
		cv::Vec3b *pix = Dst.ptr<cv::Vec3b>(i);
		for (int j = 0; j < Dst.cols; ++j) {
			pix[j] = colors[lb[j]];
		}
	}

	/* RBFクラスに各ROIのMatを渡して補間する */
#ifdef _OPENMP
#pragma omp parallel for 
#endif
	for (int i = 1; i < nLabel; ++i) {

		int *param = stats.ptr<int>(i);

		int lt_x = param[cv::ConnectedComponentsTypes::CC_STAT_LEFT]; // left topのx座標
		int lt_y = param[cv::ConnectedComponentsTypes::CC_STAT_TOP]; // left topのy座標
		int height = param[cv::ConnectedComponentsTypes::CC_STAT_HEIGHT];
		int width = param[cv::ConnectedComponentsTypes::CC_STAT_WIDTH];

		if (param[cv::ConnectedComponentsTypes::CC_STAT_AREA] > 200 && param[cv::ConnectedComponentsTypes::CC_STAT_AREA] < 7000) {

			// マーカ部分を切り抜く
			for (int y = lt_y; y < lt_y + height; ++y) {
				for (int x = lt_x; x < lt_x + width; ++x) {
					if (all.at<uchar>(y, x) == 255) {
						shade.at<uchar>(y, x) = 0;
					}
				}
			}

			// バウンディングボックスの大きさを調整
			lt_x -= 0, lt_y -= 0, width += 0, height += 0;

			cv::rectangle(Dst, cv::Rect(lt_x, lt_y, width, height), cv::Scalar(0, 255, 0), 2);

			Mat ROI = Mat(Size(width, height), CV_8UC1);

			// shadeの一部をROIに代入
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
			imshow("明度補間前", ROI);
			waitKey(0);
#endif
			// RBF補間実行
			int N = 0;
			for (int y = 0; y < ROI.rows; ++y) {
				for (int x = 0; x < ROI.cols; ++x) {
					if (ROI.at<uchar>(y, x) != 0) {
						N++;
					}
				}
			}
			if (N != 0) {
				RBF *rbf; // 並列文の中じゃないとエラー起きる
				rbf = new RBF;
				rbf->Exe(ROI);
				delete rbf;
			}
#if 0

			imshow("明度補間後", ROI);
#endif

			// RBF補間の結果を代入
			shade_y = 0, shade_x = 0;
			for (int y = lt_y; y < lt_y + height; ++y) {
				shade_x = 0;
				for (int x = lt_x; x < lt_x + width; ++x) {
					shade.at<uchar>(y, x) = ROI.at<uchar>(shade_y, shade_x);
					++shade_x;
				}
				++shade_y;
			}

			/* トラッキング用に各ラべリング領域の重心座標を格納 */
			double *param1 = centroids.ptr<double>(i);
			trackingPoints.push_back(Point2i(static_cast<int>(param1[0]), static_cast<int>(param1[1])));
		}
	}

	/* ラベリング結果の出力 */
	imshow("labels", Dst);

}

/* 一定の面積以上のラベリング領域の重心座標を格納 */
void LabelRegister(Mat stats, Mat centroids, int& nLabel, vector<Point2i>& ColorPoints)
{
	// 一定の面積以上のラベリング領域の数
	int num = 0;

	/* 各ラベリング領域について */
	for (int i = 1; i < nLabel; ++i) {

		int *param1 = stats.ptr<int>(i);
		double *param2 = centroids.ptr<double>(i);

		// 一定の面積以上の場合重心を登録
		if (param1[ConnectedComponentsTypes::CC_STAT_AREA] > minareaTsd && maxareaTsd > param1[ConnectedComponentsTypes::CC_STAT_AREA]) {

			int x = static_cast<int>(param2[0]);
			int y = static_cast<int>(param2[1]);

			num += 1;

			ColorPoints.push_back(Point2i(x, y));
			nLabels.push_back(param1[ConnectedComponentsTypes::CC_STAT_AREA]);


#if 0 // 確認用
			cout << "area " << i << " = " << param1[ConnectedComponentsTypes::CC_STAT_AREA]
				<< ", center:(" << x << ", " << y << ")" << endl;
#endif
		}
	}

	nLabel = num;
}

/* 色ごとにラベリング処理 */
void ColorLabeling(const Mat color, vector<Point2i>& ColorPoints) 
{
	/* ラベリング用の変数宣言 */
	Mat label(img.size(), CV_32S);
	Mat stats, centroids;

	/* ラベリング実行 */
	int nLabel = connectedComponentsWithStats(color, label, stats, centroids); // 返り値はbackgroundを含んだ領域数

	/* 一定の面積をもつラベリング領域の重心座標を格納 */
	LabelRegister(stats, centroids, nLabel, ColorPoints);

	/* ラベリング領域の合計数を計算*/
	NumOfRegions += nLabel;
}

/* 1箇所に2つのマーカーが存在しないようにエラー処理 */
void CheckMarker() {

	vector<Point2i> AllPoints; AllPoints.clear();

	for (int i = 0; i < RedPoints.size(); ++i) AllPoints.push_back(RedPoints[i]);
	for (int i = 0; i < GreenPoints.size(); ++i) AllPoints.push_back(GreenPoints[i]);
	for (int i = 0; i < BluePoints.size(); ++i) AllPoints.push_back(BluePoints[i]);
	for (int i = 0; i < BlackPoints.size(); ++i) AllPoints.push_back(BlackPoints[i]);

	vector<int> DeleteIndex; DeleteIndex.clear();// AllPointsについて消すべき番号

	for (int i = 0; i < AllPoints.size(); ++i) {

		for (int j = (i + 1); j < AllPoints.size(); ++j) {

			float dis = pow(pow(AllPoints[i].x - AllPoints[j].x, 2) + pow(AllPoints[i].y - AllPoints[j].y, 2), 0.5);

			// 近い場合，面積小さい方を格納
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

		// 昇順にソート
		if (DeleteIndex.size() > 1) {
			sort(DeleteIndex.begin(), DeleteIndex.end());
			reverse(DeleteIndex.begin(), DeleteIndex.end());
		}

		// 同じ番号が複数存在したときのためのエラー処理
		int previousIndex = -1;

		// 色ごとに分ける
		for (int i = 0; i < DeleteIndex.size(); ++i) {
#if 0
			cout << DeleteIndex[i] << endl;
			cout << previousIndex << endl;
#endif
			//同じ番号を2回消さないために
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

/* ラベリング */
void Labeling() {

	/* 色ごとにラベリング実行 */
	ColorLabeling(red, RedPoints);
	ColorLabeling(green, GreenPoints);
	ColorLabeling(blue, BluePoints);
	ColorLabeling(black, BlackPoints);
	ColorLabeling(yellow, YellowPoints);
	ColorLabeling(syan, SyanPoints);
	ColorLabeling(magenta, MagentaPoints);

	/* 1箇所に2つのマーカーが存在しないように処理 */
	CheckMarker();

#if 0 // 確認用に出力
	std::cout << "-------------RedPoints---------------" << endl;
	std::cout << RedPoints << endl;
	std::cout << "サイズは" << RedPoints.size() << endl;
	std::cout << "-------------GreenPoints--------------" << endl;
	std::cout << GreenPoints << endl;
	std::cout << "サイズは" << GreenPoints.size() << endl;
	std::cout << "-------------BluePoints---------------" << endl;
	std::cout << BluePoints << endl;
	std::cout << "サイズは" << BluePoints.size() << endl;
	std::cout << "-------------BlackPoints-------------" << endl;
	std::cout << BlackPoints << endl;
	std::cout << "サイズは" << BlackPoints.size() << endl;
	std::cout << "-------------YellowPoints-------------" << endl;
	std::cout << YellowPoints << endl;
	std::cout << "サイズは" << YellowPoints.size() << endl;
	std::cout << "-------------SyanPoints--------------" << endl;
	std::cout << SyanPoints << endl;
	std::cout << "サイズは" << SyanPoints.size() << endl;
	std::cout << "------------MagentaPoints-----------" << endl;
	std::cout << MagentaPoints << endl;
	std::cout << "サイズは" << MagentaPoints.size() << endl;
	std::cout << "------------------------------------" << endl;
	std::cout << "ラベリングされた領域数の総和: " << NumOfRegions << endl;
	std::cout << endl;
#endif

}

/* 内側の色と外側の色をマーカー毎にまとめる */
void GroupingMarker() {

	// 座標をSet
	RedMarker->SetOuterColorPoints(RedPoints, YellowPoints, SyanPoints, MagentaPoints);
	GreenMarker->SetOuterColorPoints(GreenPoints, YellowPoints, SyanPoints, MagentaPoints);
	BlueMarker->SetOuterColorPoints(BluePoints, YellowPoints, SyanPoints, MagentaPoints);
	BlackMarker->SetOuterColorPoints(BlackPoints, YellowPoints, SyanPoints, MagentaPoints);

	// 色ごとにグループ分け
	RedMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);
	GreenMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);
	BlueMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);
	BlackMarker->Grouping(PreviousPoints, PreviousLocalNumbers, SortedPoints, tt, bTrack);

#if 0 // 確認用に出力
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

/* 色ごとにブロックのグルーピングを行う */
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

/* 9個以下のマーカーの集合を単位としたブロックに分ける */
void GroupingBlock() {

	/* 認識できたマーカの総数 */
	Denom = RedMarker->GetNumberOfMarker() + GreenMarker->GetNumberOfMarker() + BlueMarker->GetNumberOfMarker() + BlackMarker->GetNumberOfMarker();

	// 色ごとにグルーピングを行う
	RedGroupingBlock();
	GreenGroupingBlock();
	BlueGroupingBlock();
	BlackGroupingBlock();

#if 0
	AllBlock->ShowMemberVariable();
#endif

}

/* 提案手法のコア部分 */
void ProposedMethod() {

	/* Markerクラスのメモリ確保 */
	RedMarker = new ColorMarker, GreenMarker = new ColorMarker, BlueMarker = new ColorMarker, BlackMarker = new ColorMarker;

	/* ラベリング領域をマーカー単位に分け，LocalNumberを決定する */
	GroupingMarker();

	/* Blockクラスのメモリ確保 */
	RedBlock = new ColorBlock, GreenBlock = new ColorBlock; BlueBlock = new ColorBlock; BlackBlock = new ColorBlock;
	AllBlock = new ColorBlock;

	/* グループ作り */
	GroupingBlock();

	/* マーカー識別 */
	AllBlock->GlobalIdentify(IDs, IDs_index, IDs_input, NumberOfRedBlock, NumberOfGreenBlock, NumberOfBlueBlock, NumberOfBlackBlock);
}

/* トラッキング実行 */
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

			// トラッキング成功の場合LocalNumberを引き継ぐ
			if (TrackingDis[minIndex] < trackTsd) {
#if 0
				std::cout << trackingPoints[i] << "に対応する座標: " << PreviousPoints[minIndex] << endl;
#endif
				SortedPoints[minIndex] = trackingPoints[i];
				SortedUVs[minIndex] = PreviousUVs[minIndex];
				SortedLocalNumbers[minIndex] = PreviousLocalNumbers[minIndex];
			}
		}
	}

}

/* 頂点座標・UV座標・LocalNumbersの引き継ぎ(トラッキング用) */
void Record()
{
	// 再初期化
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

/* テクスチャマッピング */
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

/* 可視化 */
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

/* 動画作成 */
void makeVideo(vector<Mat>& frames, const string name_input, const string name_output) {

	Mat frame = imread(name_input);
	frames.push_back(frame);

	if (tt == LastFrame) {
		videowriter(name_output, frames, LastFrame, fps);
	}
}

/* シェーディング */
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

	imshow("shade(補間後)", shade);

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

#if 1 // 確認用
	imshow("Shading", shadeRGB_output);
#endif
}


/*----------------------------------------------------------*/


/*---------------------コールバック関数---------------------*/

static void init()
{
	/* 背景色 */
	glClearColor(0.0, 0.0, 0.0, 1.0);

	/* リファレンスの読み込み */
	IDs_Reader(IDs);
	IDs_index_Reader(IDs_index);
	IDs_num_Reader(IDs_num);

	/* テクスチャの読み込み */
	LoadGLTextures();

	/* k-means法で学習させる画像の読み込み */
	Mat src;

#if 0 // 画像の場合
	//	img = imread(name);
	src = imread("data/self-occlusion.png");
#endif

#if 1 // 動画の場合
	/* エラー処理 */
	if (!cap.isOpened()) {
		std::cout << " Can't open movie" << endl;
	}
	cap >> src;
#endif

	//kmeans(src);

	/* InputPoints, OutputUVsの設定 */
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
			CenterPoints.push_back(Point2i(35 + j * 50, 35 + i * 50)); // 直接設定する必要あり
		}
	}

	/* 初期化 */
	Points1FrameBack.clear();
	Points2FrameBack.clear();
	frames1.clear(), frames2.clear(), frames3.clear();
}

static void display()
{
	/* StartFrameまですっ飛ばし */
	if (tt < StartFrame) {
		cap >> img;
		++tt;
	}

	else {

		glClear(GL_COLOR_BUFFER_BIT);

		/* 初期化 */
		initialize();

		/* ファイルの読み込み-------------------------------- */

#if 1 // フレームを連続的に読み込むかどうか
		stringstream ss;
		//string name ="data/bitmap/"+ ss.str() + ".bmp";
		ss << tt;
#endif

#if 0 // 画像の場合
		//	img = imread(name);
		img = imread("data/self-occlusion.png");
#endif

#if 1 // 動画の場合
		cap >> img;
#endif
		/* -------------------------------------------------- */

		/* RGB-->HSV */
		cv::cvtColor(img, hsv, CV_BGR2HSV);

		/* 色検出 */
		ColorDetector();

		//imwrite(ShadeImagePath, shade);

		/* マーカ部分の明度補間 */
		ShadeInterpolation();

		/* ラベリング */
		Labeling();

		/* 提案手法(マーカのグルーピング→ブロックの識別→マーカの識別) */
		ProposedMethod();

		/* IDs(リファレンス)の順に並び替え */
		AllBlock->MarkerSort(IDs_input, IDs, IDs_num);

		/* トラッキング */
		Tracking();

		/* トラッキングに失敗したマーカについてはBlockの結果をGet */
		for (int i = 0; i < SortedPoints.size(); ++i) {
			if (SortedPoints[i].x == -1 && AllBlock->GetSortedPoints(i).x != -1) {
				SortedPoints[i] = AllBlock->GetSortedPoints(i);
				SortedUVs[i] = AllBlock->GetSortedUVs(i);
				SortedLocalNumbers[i] = AllBlock->GetSortedLocalNumbers(i);
				trackingIndex[i] = false;
			}
		}
		delete AllBlock;

		/* 識別できたマーカがない場合はトラッキングを初期化する */
		bool bTrack = false;
		for (int i = 0; i < SortedPoints.size(); ++i) {
			if (SortedPoints[i].x != -1) {
				bTrack = true;
				break;
			}
		}

		/* 移動量の大きい外れ値を消去 */
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

		/* トラッキングのために頂点座標・UV座標・LocalNumberを保存 */
		Record();

		/* RBFT------------------------------------------------------------ */

		rbft = new RBFT;
		rbft->SetTimeWidth(SortedPoints, Points1FrameBack, Points2FrameBack);
		rbft->SetX(SortedPoints, Points1FrameBack, Points2FrameBack);
		OutputPoints = rbft->Exe(InputPoints); // テクスチャマッピング用

		// 次フレームのための設定
		if (bTrack == true) {
			Points2FrameBack = Points1FrameBack;
			Points1FrameBack = rbft->Exe(CenterPoints);
		}
		else if (bTrack == false) {
			Points1FrameBack.clear();
		}

		delete rbft;

		/* ----------------------------------------------------------------- */


		/* 3種類の画像と動画を保存----------------------------------------------------------------------------------------------- */

		// openCVからopenGLに渡す
		cv::flip(img, img, 0);
		cv::cvtColor(img, img, CV_BGR2RGB);

		// テクスチャマッピングを行い画像を保存する
		glDrawPixels(img.cols, img.rows, GL_RGB, GL_UNSIGNED_BYTE, img.data);
		TextureMapping2();

		string ImageOutput_texture = TextureImagePath + ss.str() + ".bmp";
		WriteBitmap(ImageOutput_texture.c_str(), Width, Height);


		// 1つ目(テクスチャなし・メッシュあり)
		glDrawPixels(img.cols, img.rows, GL_RGB, GL_UNSIGNED_BYTE, img.data);
		MeshVisualization();
		PointVisualization();

		string ImageOutput_mesh = MeshImagePath + ss.str() + ".bmp";
		WriteBitmap(ImageOutput_mesh.c_str(), Width, Height);

		string VideoOutput_mesh = MeshVideoPath;
//		makeVideo(frames2, ImageOutput_mesh, VideoOutput_mesh);


		// 2つ目(テクスチャあり・メッシュなし)
		Shading(ImageOutput_texture, tt);
		string VideoOutput_texture = TextureVideoPath;
		makeVideo(frames1, ImageOutput_texture, VideoOutput_texture);


		// 3つ目(テクスチャあり・メッシュあり)
		Mat shadedImg = imread(ImageOutput_texture); // 1つ目の画像の読み込み
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


#if 0  // 識別率の評価 
		for (int i = 0; i < SortedPoints.size(); ++i) {
			if (SortedPoints[i].x != -1) {
				Numer++;
			}
		}
		Percent = (float)Numer / (float)Denom;
		Percents.push_back(Percent);

		/* 書き込み */
		if (tt == LastFrame) {
			ofstream ofs("data/output/simpleocclusion/Percents.txt");

			for (int i = 0; i < Percents.size(); ++i) {
				ofs << Percents[i] << endl;
			}

		}
#endif

		/* フレーム番号の出力 */
		std::cout << "フレーム番号: " << tt << endl;
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
		/* q か Q か ESC をタイプしたら終了 */
	case '\033':
	case 'q':
	case 'Q':
		exit(0);
	default:
		break;
	}
}

/*----------------------------------------------------------*/


/*-------------------------main文---------------------------*/

int main(int argc, char *argv[])
{
	/* glfw初期化 */
	glfwInit();
	glutInit(&argc, argv);

	GLFWwindow* window = glfwCreateWindow(Width, Height, "Retexturing", NULL, NULL);

	/* カレント画面の設定(テクスチャはGPUメモリに格納されているため) */
	glfwMakeContextCurrent(window);

	init();

	glfwSetKeyCallback(window, keyboard);

	/* 射影変換(GLとCVのスケールを一致させる) */
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