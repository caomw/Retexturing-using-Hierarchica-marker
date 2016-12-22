#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <omp.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <glfw3.h>
#include <freeglut.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include "Bitmap.h"
#include "Marker.h"
#include "Block.h"
#include "RBFT.h"
#include "RBF.h"
#include "video.h"

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"GLFW3.lib")
#pragma warning(disable:4996)


/* サイズ設定 */
const int Width = 1920;
const int Height = 1080;

const int TEXWIDTH = 891; /* テクスチャの幅 */
const int TEXHEIGHT = 891; /* テクスチャの高さ */


/* 閾値設定 */
const int minareaTsd = 10; /* ラベリングにおけるマーカー検出のための面積の最小閾値 */
const int maxareaTsd = 2000; /* ラベリングにおけるマーカー検出のための面積の最大閾値 */

const int disLocalTsd = 30; /* マーカーのグルーピングのための距離閾値 */
const int disGlobalTsd = 800; /* Global識別における捜索範囲のための距離の閾値 */
const int disGroupingTsd = 300; /* グルーピングにおけるブロックに格納するための距離の閾値 */

const int angTsd = 25; /* Global識別における一直線上判定のための角度の閾値 */
const int moveTsd = 70; /* 外れ値かどうか判断するための移動量の閾値 */

const int trackTsd = 0;


/* マーカー設定 */
const int wid_num = 9;
const int hei_num = 9;

const int MaxNumberOfRedBlock = 2;
const int MaxNumberOfGreenBlock = 3;
const int MaxNumberOfBlueBlock = 2;
const int MaxNumberOfBlackBlock = 2;


/* その他設定 */
const int CLASS = 6;
const int mesh_num = 5;
const int StartFrame = 543;
const int LastFrame = 800;
const int fps = 60;


/* パス */
// 入力動画
const string InputVideo = "data/video/body/tatsuki.mp4";

// 結果を出力したいディレクトリの指定
const string targetPath = "D:/mymarker/output/body/tatsuki/trackingOFF";

// テクスチャ画像
const string TexturePath = "data/texture/texture1.jpg";

// 結果画像
const string TextureImagePath = targetPath + "/Texture/"; // テクスチャのみの画像
const string MeshImagePath = targetPath + "/Mesh/"; // テクスチャなしメッシュありの画像
const string MeshOnTextureImagePath = targetPath + "/MeshOnTexture/"; // テクスチャありメッシュありの画像
const string ShadeImagePath = targetPath + "/Shade.bmp";
const string InterpolationShadeImagePath = targetPath + "/InterpolatedShade.bmp";

// 結果動画
const string TextureVideoPath = targetPath + "/Texture";
const string MeshVideoPath = targetPath + "/Mesh";
const string MeshOnTextureVideoPath = targetPath + "/MeshOnTexture";
