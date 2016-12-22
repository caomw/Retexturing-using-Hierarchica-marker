#include "RBFT.h"

RBFT::RBFT()
{
	N = 0;
	TimeWidth1 = TimeWidth2 = 0;
	A.clear();
	B.clear();
}

float RBFT::potential(const Point3i Ai, const Point3i Aj)
{
	return pow(pow(Ai.x - Aj.x, 2) + pow(Ai.y - Aj.y, 2) + pow(Ai.z - Aj.z, 2), 0.5);
}

void RBFT::SetABN(const vector<Point2i> AllPoints, const vector<Point2i> Points1FrameBack, const vector<Point2i> Points2FrameBack)
{

	if (TimeWidth1 != 0) {
		for (int i = 0; i < Points2FrameBack.size(); ++i) {
			if (Points2FrameBack[i].x != -1) {
				A.push_back(Point3i(35 + 50 * (i % wid_num), 35 + 50 * (i / wid_num), 50 + TimeWidth1 + TimeWidth2));
				B.push_back(Point3i(Points2FrameBack[i].x, Points2FrameBack[i].y, 50 + TimeWidth1 + TimeWidth2));
				N++;
			}
		}
	}

	if (TimeWidth2 != 0) {
		for (int i = 0; i < Points1FrameBack.size(); ++i) {
			if (Points1FrameBack[i].x != -1) {
				A.push_back(Point3i(35 + 50 * (i % wid_num), 35 + 50 * (i / wid_num), 50 + TimeWidth2));
				B.push_back(Point3i(Points1FrameBack[i].x, Points1FrameBack[i].y, 50 + TimeWidth2));
				N++;
			}
		}
	}

	for (int i = 0; i < AllPoints.size(); ++i) {
		if (AllPoints[i].x != -1) {
			A.push_back(Point3i(35 + 50 * (i%wid_num), 35 + 50 * (i / wid_num), 50)); // 10は適当(0でなければ)
			B.push_back(Point3i(AllPoints[i].x, AllPoints[i].y, 50));
			N++;
		}
	}

}

void RBFT::SetTimeWidth(const vector<Point2i> AllPoints, const vector<Point2i> Points1FrameBack, const vector<Point2i> Points2FrameBack)
{
	float DisAve1 = 0 , DisAve2 = 0;
	int count1 = 0 , count2 = 0;

	if (Points1FrameBack.size() == 0 || Points2FrameBack.size() == 0) {
		TimeWidth1 = TimeWidth2 = 0;
	}

	else {
		for (int i = 0; i < Points1FrameBack.size(); ++i) {
			if (Points1FrameBack[i].x != -1 && Points2FrameBack[i].x != -1) {
				DisAve1 += pow(pow(Points1FrameBack[i].x - Points2FrameBack[i].x, 2) + pow(Points1FrameBack[i].y - Points2FrameBack[i].y, 2), 0.5);
				count1++;
			}
		}

		if (count1 == 0) {
			TimeWidth1 = 0;
		}
		else {
			DisAve1 = DisAve1 / count1;
			TimeWidth1 = DisAve1;
		}

		for (int i = 0; i < AllPoints.size(); ++i) {
			if (AllPoints[i].x > 0 && Points1FrameBack[i].x != -1) {
				DisAve2 += pow(pow(Points1FrameBack[i].x - AllPoints[i].x, 2) + pow(Points1FrameBack[i].y - AllPoints[i].y, 2), 0.5);
				count2++;
			}
		}

		if (count2 == 0) {
			TimeWidth2 = 0;
		}
		else {
			DisAve2 = DisAve2 / count2;
			TimeWidth2 = DisAve2;
		}
	}
}

void RBFT::SetF()
{
	F.resize(N + 4, 3);
	F.setZero();

	for (int i = 0; i < N; ++i) {
		F(i, 0) = B[i].x;
		F(i, 1) = B[i].y;
		F(i, 2) = B[i].z;
	}
}

void RBFT::SetG()
{
	G.resize(N + 4, N + 4);
	G.setZero();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			G(i, j) = potential(A[i], A[j]);
		}
		G(i, i) -= 8 * N * 3.14159265 * rho;
	}

	for (int i = 0; i < N; ++i) {
		G(i, N) = 1;
		G(i, N + 1) = A[i].x;
		G(i, N + 2) = A[i].y;
		G(i, N + 3) = A[i].z;
		G(N, i) = 1;
		G(N + 1, i) = A[i].x;
		G(N + 2, i) = A[i].y;
		G(N + 3, i) = A[i].z;
	}
}

/* 頂点A → 頂点B へ変形するときのパラメータ行列Xを求める */
void RBFT::SetX(const vector<Point2i> AllPoints, const vector<Point2i> Points1FrameBack, const vector<Point2i> Points2FrameBack)
{
	// A,B,NのSet
	SetABN(AllPoints, Points1FrameBack, Points2FrameBack);

	/* 行列の宣言 */
	X.resize(N + 4, 3);

	// F,GのSet
	SetF();
	SetG();

	X = G.inverse() * F;

#if 0 // 確認用
	cout << "-----A-----" << endl;
	cout << A << endl;
	cout << "-----B-----" << endl;
	cout << B << endl;
//	cout << "-----F-----" << endl;
//	cout << F << endl;
//	cout << "-----G-----" << endl;
//	cout << G << endl;
//	cout << "-----X-----" << endl;
//	cout << X << endl;
#endif
}

vector<Point2i> RBFT::Exe(const vector<Point2i> InputPoints)
{
	vector<Point2i> OutputPoints;
	OutputPoints.clear();

	for (int i = 0; i < InputPoints.size(); ++i) {

		float x, y;
		x = y = 0;

		for (int j = 0; j < N; ++j) {
			x += potential(Point3i(InputPoints[i].x, InputPoints[i].y, 50), A[j]) * X(j, 0);
			y += potential(Point3i(InputPoints[i].x, InputPoints[i].y, 50), A[j]) * X(j, 1);
		}

		x += (X(N, 0) + InputPoints[i].x * X(N + 1, 0) + InputPoints[i].y * X(N + 2, 0) + 50 * X(N + 3, 0));
		y += (X(N, 1) + InputPoints[i].x * X(N + 1, 1) + InputPoints[i].y * X(N + 2, 1) + 50 * X(N + 3, 1));

		OutputPoints.push_back(Point2i(x, y));
	}

#if 0 // 確認用
	cout << "-------------------RBF補間された結果----------------------" << endl;
	cout << OutputPoints << endl;
#endif

	return OutputPoints;
}
