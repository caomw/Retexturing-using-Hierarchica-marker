#include "Block.h"

/* 次にブロックに格納するべきLocal番号を返す */
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

/* LocalNumber(number)がダブったブロックについて正しくない方を消去する処理 */
void DeleteIndex(const int number, const vector<int> index, vector<Point2i>& BlockPoints_i, vector<int>& BlockLocalNumbers_i, const Point2i BlockRepresenter)
{
	// ダブったマーカーの座標
	vector<Point2i> points;
	vector<int> FalseIndex; // 消すべき番号

	for (int i = 0; i < index.size(); ++i) {
		points.push_back(BlockPoints_i[index[i]]);
	}

	// 正解の番号と座標(仮に0番目を正しいものとして後で判断)
	int CorrectIndex = 0;
	Point2i CorrectPoint = points[0];

	// 1がダブったとき
	if ((number + 1) == 1) {

		for (int i = 1; i < points.size(); ++i) {

			if (CorrectPoint.y < points[i].y) { // y座標で判断
				FalseIndex.push_back(i);
			}
			else {
				FalseIndex.push_back(CorrectIndex);
				CorrectIndex = i;
				CorrectPoint = points[i];
			}
		}
	}

	// 9がダブったとき
	if ((number + 1) == 9) {

		for (int i = 1; i < points.size(); ++i) {

			if (CorrectPoint.y > points[i].y) { // y座標で判断
				FalseIndex.push_back(i);
			}
			else {
				FalseIndex.push_back(CorrectIndex);
				CorrectIndex = i;
				CorrectPoint = points[i];
			}
		}

	}

	// そのほかの番号がダブったとき
	if ((number + 1) == 2 || (number + 1) == 3 || (number + 1) == 4 || (number + 1) == 5 || (number + 1) == 6 || (number + 1) == 7 || (number + 1) == 8) {

		vector<float> dis; // BlockRepresenter_iからの距離
		dis.clear();

		for (int i = 0; i < points.size(); ++i) {
			dis.push_back(pow(points[i].x - BlockRepresenter.x, 2) + pow(points[i].y - BlockRepresenter.y, 2));
		}

		for (int i = 1; i < points.size(); ++i) {

			if (dis[CorrectIndex] < dis[i]) { // y座標で判断
				FalseIndex.push_back(i);
			}
			else {
				FalseIndex.push_back(CorrectIndex);
				CorrectIndex = i;
				CorrectPoint = points[i];
			}
		}

	}

	// 消去
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

/* コンストラクタ */
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

/* リサイズ */

void ColorBlock::Resize1()
{
	BlockPoints.resize(NumberOfBlock);
	BlockLocalNumbers.resize(NumberOfBlock);
	BlockRepresenters.resize(NumberOfBlock);
	BlockUVs.resize(NumberOfBlock);
}
void ColorBlock::Resize2()
{
	// 矩形領域の場合
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
	/* 注目マーカーを原点とした時の座標 */
	vector<Point2f> coord;
	coord.clear();

	/* 相対座標を計算 */
	for (int i = 0; i < neighbor.size() - 1; ++i) {
		coord.push_back(Point2f(neighbor[i + 1].x - neighbor[0].x, neighbor[i + 1].y - neighbor[0].y));
	}

	/* 各ブロックに対する角度を計算 */
	for (int i = 0; i < neighbor.size() - 1; ++i) {
		sita.push_back(atan2f(coord[i].y, coord[i].x) * 180 / M_PI);
	}
}

void ColorBlock::DeleteBlock(vector<Point2i>& neighbor, vector<float>& sita, vector<float>& dist_parts)
{
	/* 削除するブロックの番号 */
	vector<int> num;
	num.clear();

	/* 一直線上にある,より遠いブロックを削除 */
	for (int i = 0; i < sita.size() - 1; ++i) {
		for (int j = i + 1; j < sita.size(); ++j) {
			float dif = sita[i] - sita[j];

			/* 角度の閾値を決めてそれ以下であれば一直線上にあるとみなす */
			if (fabs(dif) < angTsd || fabs(dif) > 360 - angTsd) {

				if (fabs(dist_parts[i + 1] - dist_parts[j + 1]) < 10) {
					continue;
				}
				num.push_back(j);
			}
		}
	}

	sort(num.begin(), num.end());

	/* 直線上に削除するマーカーが2つ以上存在したときのエラー処理 */
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
	/* 時計回りに並べたneighborを入れるベクトル */
	vector<Point2i> neighbor_dash;
	neighbor_dash.clear();
	neighbor_dash.push_back(neighbor[0]); // 着目しているマーカーを先頭にする

	/* neighbor_dashと同様(サイズが異なることに気を付ける) */
	vector<float> sita_dash;
	sita_dash.clear();

	/* sitaのコピー(探索用に作る) */
	vector<float> sita_copy;
	sita_copy = sita;

	/* 時計回り=角度の昇順 */
	sort(sita_copy.begin(), sita_copy.end());

	/* sita_copyの順に対応したneighbor_dashとsita_dashを作る */
	for (int i = 0; i < sita_copy.size(); ++i) {
		for (int j = 0; j < sita.size(); ++j) {

			if (sita_copy[i] == sita[j]) {
				neighbor_dash.push_back(neighbor[j + 1]);
				sita_dash.push_back(sita[j]);
			}

		}
	}

	/* 代入 */
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

			// ブロックのインデックスを表す
			int a = IDs_index[i].x; // 上からa番目(y方向)
			int b = IDs_index[i].y; // 左からb番目(x方向)

			// LocalNumber = 1 のマーカーについて各ブロック
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
	vector<float> dist; // 全てのGlobalマーカーに対して着目しているGlobalマーカーからの距離
	vector<float> dist_copy; // distのコピー
	vector<float> dist_parts; // distの一部(一定の距離以下)
	vector<Point2i> BlockRepresenters_copy; // BlockRepresentersのコピー

	for (int i = 0; i < BlockPoints.size(); i++) {

		/* 初期化 */
		dist.clear();
		dist_copy.clear();
		dist_parts.clear();
		BlockRepresenters_copy = BlockRepresenters;
		NeighborBlockPoints.clear();

		/* i番目のブロックからj番目のブロックまでの距離を計算 */
		for (int j = 0; j < BlockRepresenters.size(); j++) {
			dist.push_back(pow(pow(BlockRepresenters[i].x - BlockRepresenters[j].x, 2)
				+ pow(BlockRepresenters[i].y - BlockRepresenters[j].y, 2), 0.5));
		}

		/* コピー */
		dist_copy = dist;

		/* 一定以下の距離を持つ場合のみ格納 */
		for (int j = 0; j < BlockRepresenters.size(); ++j) {
			if (dist[j] < disGlobalTsd) {
				dist_parts.push_back(dist[j]);
			}
		}

		/* 距離を昇順にソート */
		sort(dist_parts.begin(), dist_parts.end());

		/* 距離の小さい順にブロックの代表座標を格納 */
		for (int j = 0; j < dist_parts.size(); j++) {
			for (int k = 0; k < dist_copy.size(); k++) {

				if (dist_parts[j] == dist_copy[k]) {

					NeighborBlockPoints.push_back(BlockRepresenters_copy[k]);

					/* distances_partsに同じ距離が含まれていた場合に異なる座標を取ってこれるように処理 */
					dist_copy.erase(dist_copy.begin() + k);
					BlockRepresenters_copy.erase(BlockRepresenters_copy.begin() + k);

					break;
				}
			}
		}

		/* 2つのマーカーのなす角を格納するベクトルの宣言 */
		vector<float> sita;
		sita.clear();


		/* 各ブロックに対する角度を計算する */
		CalculateSita(NeighborBlockPoints, sita);

		/* neighborは9個で十分 */
		if (NeighborBlockPoints.size() > 9) {
			NeighborBlockPoints.erase(NeighborBlockPoints.begin() + 9, NeighborBlockPoints.end());
			sita.erase(sita.begin() + 9, sita.end());
			dist_parts.erase(dist_parts.begin() + 9, dist_parts.end());
		}

		/* 近傍に存在しないブロックを削除 */
		DeleteBlock(NeighborBlockPoints, sita, dist_parts);

		/* IDの長さが正しくなるように修正 */
		if (NeighborBlockPoints.size() > 6 && NeighborBlockPoints.size() < 9) {
			NeighborBlockPoints.erase(NeighborBlockPoints.begin() + 6, NeighborBlockPoints.end());
			sita.erase(sita.begin() + 5, sita.end());
		}
		else if (NeighborBlockPoints.size() > 4 && NeighborBlockPoints.size() < 6) {
			NeighborBlockPoints.erase(NeighborBlockPoints.begin() + 4, NeighborBlockPoints.end());
			sita.erase(sita.begin() + 3, sita.end());
		}

		/* 時計回りにマーカーを並べる */
		ArrangeNeighborBlock(NeighborBlockPoints, sita);

		/* 近傍のGlobalマーカーによるID作成 */
		string ID;
		MakeID(NeighborBlockPoints, ID, NumberOfRedBlock, NumberOfGreenBlock, NumberOfBlueBlock, NumberOfYellowBlock);

		/* リファレンスを参照してブロックごと(LocalNumber = 1のみ)についてテクスチャ座標を求める */
		Point2f GlobalUV;
		GetGlobalUV(ID, GlobalUV, IDs, IDs_index);

		/* 全てのマーカーについてLocalに識別し，テクスチャ座標を取得する */
		GetLocalUV(i, GlobalUV);
		IDs_input.push_back(ID);

#if 0 // 確認用
		cout << "---------------------" << i << "番目のブロックについて" << "---------------------" << endl;
		cout << "中心のマーカーの座標:  " << BlockRepresenters[i] << endl;
		cout << "近傍のマーカーの座標:　" << endl << NeighborBlockPoints << endl;;
		cout << "検出されたマーカーに対する角度:" << endl;
		for (int j = 0; j < sita.size(); ++j) {
			cout << sita[j] << "  ";
		}
		cout << endl;
		cout << "作成されたID:  " << ID << endl;
		cout << "取得したUV座標:  " << BlockUVs[i] << endl;
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

	/*---------------IDs(リファレンス)の順にブロックを並び替える------------------*/
	int total = 0;

	SortedBlockPoints.resize(wid_num*hei_num / 9);
	SortedBlockLocalNumbers.resize(wid_num*hei_num / 9);
	SortedBlockUVs.resize(wid_num*hei_num / 9);

	for (int i = 0; i < IDs_num.size(); ++i) {

		// りサイズ
		Resize2();

		bool b = false; // IDが見つかったかどうかの判定用

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

			// 見つからなかった場合
			if (j == (IDs_num[i] - 1)) {
				SortedBlockPoints[i].push_back(Point2i(-1, -1));
				SortedBlockUVs[i].push_back(Point2i(-1, -1));
				SortedBlockLocalNumbers[i].push_back(-1);
			}

		}
#if 0 // 確認用
		cout << "---------------" << i << "番目のブロックについて" << "------------------" << endl;
		cout << "[マーカーの座標]" << endl;
		cout << SortedBlockPoints[i] << endl;
		cout << "[テクスチャ座標]" << endl;
		cout << SortedBlockUVs[i] << endl;
		cout << "[LocalNumbers]" << endl;
		for (int j = 0; j < SortedBlockLocalNumbers.size(); ++j) {
			cout << SortedBlockLocalNumbers[i][j] << endl;
		}
		cout << endl;
# endif

		total += IDs_num[i];
	}


	/* ----------ブロックを崩して，座標順にソートされたマーカのvectorを作る----------- */

	// 矩形領域の場合にしか使えない注意！！
	int wid_num_block = wid_num / 3; // x方向のブロックの数
	int hei_num_block = hei_num / 3; // y方向のブロックの数

	for (int i = 0; i < hei_num_block; ++i) { // ブロックの行ごとに

		// 1→2→3
		for (int j = 0; j < wid_num_block; ++j) { // ブロックの列ごとに

			// 1を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 1) {
					SortedPoints[3 * i*wid_num + 3 * j] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[3 * i*wid_num + 3 * j] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[3 * i * wid_num + 3 * j] = 1;
					break;
				}
			}

			// 2を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 2) {
					SortedPoints[3 * i*wid_num + 3 * j + 1] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[3 * i*wid_num + 3 * j + 1] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[3 * i * wid_num + 3 * j + 1] = 2;
					break;
				}
			}

			// 3を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 3) {
					SortedPoints[3 * i*wid_num + 3 * j + 2] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[3 * i*wid_num + 3 * j + 2] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[3 * i * wid_num + 3 * j + 2] = 3;
					break;
				}
			}
		}

		// 4→5→6
		for (int j = 0; j < wid_num_block; ++j) { // ブロックの列ごとに

			// 4を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 4) {
					SortedPoints[(3 * i + 1)*wid_num + 3 * j] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 1)*wid_num + 3 * j] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 1) * wid_num + 3 * j] = 4;
					break;
				}
			}

			// 5を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 5) {
					SortedPoints[(3 * i + 1)*wid_num + 3 * j + 1] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 1)*wid_num + 3 * j + 1] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 1) * wid_num + 3 * j + 1] = 5;
					break;
				}
			}

			// 6を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 6) {
					SortedPoints[(3 * i + 1)*wid_num + 3 * j + 2] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 1)*wid_num + 3 * j + 2] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 1) * wid_num + 3 * j + 2] = 6;
					break;
				}
			}
		}

		// 7→8→9
		for (int j = 0; j < wid_num_block; ++j) { // ブロックの列ごとに

			// 7を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 7) {
					SortedPoints[(3 * i + 2)*wid_num + 3 * j] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 2)*wid_num + 3 * j] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 2) * wid_num + 3 * j] = 7;
					break;
				}
			}

			// 8を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

				if (SortedBlockLocalNumbers[wid_num_block * i + j][k] == 8) {
					SortedPoints[(3 * i + 2)*wid_num + 3 * j + 1] = SortedBlockPoints[wid_num_block * i + j][k];
					SortedUVs[(3 * i + 2)*wid_num + 3 * j + 1] = SortedBlockUVs[wid_num_block * i + j][k];
					SortedLocalNumbers[(3 * i + 2) * wid_num + 3 * j + 1] = 8;
					break;
				}
			}

			// 9を探す
			for (int k = 0; k < SortedBlockLocalNumbers[wid_num_block * i + j].size(); ++k) { // ブロック内の各マーカーについて				

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

/*-------------------------------------- Set関数 ------------------------------------ */

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

	// Set完了 (ただし，あくまで確実に存在するブロックの数なので増える可能性がある)
	NumberOfBlock = NumberOfEachLocalNumber[MaxIndex];

	if (NumberOfBlock > max) {
		NumberOfBlock = max;
	}

	// 誤認識によってブロックがmaxを超えたときの処理
/*	if (NumberOfBlock > max) {
		for (int i = 0; i < 9; ++i) { // i番目のLocalNumberについて

			if (NumberOfEachLocalNumber[i] > max) {
				while (NumberOfEachLocalNumber[i] == max) {

					// i番目のLocalNumberをもつマーカーの座標
					vector<Point2f> PointsOfLocalNumberI;	PointsOfLocalNumberI.clear();

					for (int j = 0; j < NumberOfEachLocalNumber[i]; ++j) {
						for (int k = 0; k < LocalNumbers.size(); ++k) {

							if (LocalNumbers[k] == (i + 1)) {
								PointsOfLocalNumberI.push_back(Points[k]);
							}
						}
					}

					// 距離計算
					vector<float> dists;	dists.clear();
					for (int j = 0; j < (NumberOfEachLocalNumber[i] - 1); ++j) {
						for (int k = j + 1; k < NumberOfEachLocalNumber[i]; ++k) {

							float dist = 0.0;

							dist = pow(pow(PointsOfLocalNumberI[j].x - PointsOfLocalNumberI[k].x, 2) + pow(PointsOfLocalNumberI[j].y - PointsOfLocalNumberI[k].y, 2), 0.5);

							dists.push_back(dist);
						}
					}

					// ソート
					vector<float> dists_copy = dists;
					sort(dists_copy.begin(), dists_copy.end());
					dists.clear();

					// 探索・削除
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

	/* 各ブロックについて，番号MaxIndexのもつ変数を格納して初期化 */

	for (int i = 0; i < NumberOfBlock; ++i) {
		for (int j = 0; j < LocalNumbers.size(); ++j) {

			if (LocalNumbers[j] == (MaxIndex + 1)) {

				// ブロックに追加
				BlockPoints[i].push_back(Points[j]);
				BlockLocalNumbers[i].push_back(MaxIndex + 1);
				BlockRepresenters[i] = Points[j];

				// 削除
				Points.erase(Points.begin() + j);
				LocalNumbers.erase(LocalNumbers.begin() + j);
				break;
			}
		}
	}

	/*------------他の番号についてもブロックに格納--------------*/

	// 変数宣言
	vector<int> StoredNumber;
	StoredNumber.clear();

	StoredNumber.push_back(MaxIndex + 1);

	int	NextLocalNumber; // 次に格納する番号

	NextLocalNumber = (MaxIndex + 1); // 初期化

	while (StoredNumber.size() != 9) {

		int count = 0; //再初期化ぜったい必要

		NextLocalNumber = Next(StoredNumber, NextLocalNumber);

		StoredNumber.push_back(NextLocalNumber);

		for (int i = 0; i < LocalNumbers.size(); ++i) {

			if (LocalNumbers[i] == NextLocalNumber) {

				vector<float> dist;
				int MindistIndex = 0; // 最も距離の小さいブロックの番号

				// 距離計算
				for (int j = 0; j < NumberOfBlock; ++j) {
					dist.push_back(pow(pow(BlockRepresenters[j].x - Points[i].x, 2) + pow(BlockRepresenters[j].y - Points[i].y, 2), 0.5));
				}

				// 最も距離が小さいものを探す
				if (dist.size() > 1) {

					for (int j = 1; j < dist.size(); ++j) {
						if (dist[MindistIndex] > dist[j]) {
							MindistIndex = j;
						}
					}
				}
				if (dist.size() > 0) {
					if (dist[MindistIndex] < disGroupingTsd) {

						// ブロックに追加
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

	// 最終的なブロックの代表座標はメンバの平均を用いる
	for (int i = 0; i < BlockPoints.size(); ++i) {
		BlockRepresenters[i] = Point2i(0, 0); // 再初期化

		for (int j = 0; j < BlockPoints[i].size(); ++j) {
			BlockRepresenters[i].x += (BlockPoints[i][j].x / BlockPoints[i].size());
			BlockRepresenters[i].y += (BlockPoints[i][j].y / BlockPoints[i].size());
		}
	}

	/* ブロックのメンバが正しいかチェック */
	CheckBlock(BlockPoints, BlockLocalNumbers, BlockRepresenters);

	// 最終的なブロックの代表座標はメンバの平均を用いる
	for (int i = 0; i < BlockPoints.size(); ++i) {
		BlockRepresenters[i] = Point2i(0, 0); // 再初期化

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

/*-------------------------------------- Get関数 ------------------------------------ */

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
		cout << "-----------------ブロック" << i << "------------------" << endl;
		cout << "[LocalNumber]" << endl;
		for (int j = 0; j < BlockLocalNumbers[i].size(); ++j) {
			cout << BlockLocalNumbers[i][j] << "  ";
		}
		cout << endl;
		cout << "[マーカーの座標]" << endl;
		cout << BlockPoints[i] << endl;
		cout << "[代表座標]" << endl;
		cout << BlockRepresenters[i] << endl;
		cout << "--------------------------------------------" << endl;
	}
}
