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


/* �T�C�Y�ݒ� */
const int Width = 1920;
const int Height = 1080;

const int TEXWIDTH = 891; /* �e�N�X�`���̕� */
const int TEXHEIGHT = 891; /* �e�N�X�`���̍��� */


/* 臒l�ݒ� */
const int minareaTsd = 10; /* ���x�����O�ɂ�����}�[�J�[���o�̂��߂̖ʐς̍ŏ�臒l */
const int maxareaTsd = 2000; /* ���x�����O�ɂ�����}�[�J�[���o�̂��߂̖ʐς̍ő�臒l */

const int disLocalTsd = 30; /* �}�[�J�[�̃O���[�s���O�̂��߂̋���臒l */
const int disGlobalTsd = 800; /* Global���ʂɂ�����{���͈͂̂��߂̋�����臒l */
const int disGroupingTsd = 300; /* �O���[�s���O�ɂ�����u���b�N�Ɋi�[���邽�߂̋�����臒l */

const int angTsd = 25; /* Global���ʂɂ�����꒼���㔻��̂��߂̊p�x��臒l */
const int moveTsd = 70; /* �O��l���ǂ������f���邽�߂̈ړ��ʂ�臒l */

const int trackTsd = 0;


/* �}�[�J�[�ݒ� */
const int wid_num = 9;
const int hei_num = 9;

const int MaxNumberOfRedBlock = 2;
const int MaxNumberOfGreenBlock = 3;
const int MaxNumberOfBlueBlock = 2;
const int MaxNumberOfBlackBlock = 2;


/* ���̑��ݒ� */
const int CLASS = 6;
const int mesh_num = 5;
const int StartFrame = 543;
const int LastFrame = 800;
const int fps = 60;


/* �p�X */
// ���͓���
const string InputVideo = "data/video/body/tatsuki.mp4";

// ���ʂ��o�͂������f�B���N�g���̎w��
const string targetPath = "D:/mymarker/output/body/tatsuki/trackingOFF";

// �e�N�X�`���摜
const string TexturePath = "data/texture/texture1.jpg";

// ���ʉ摜
const string TextureImagePath = targetPath + "/Texture/"; // �e�N�X�`���݂̂̉摜
const string MeshImagePath = targetPath + "/Mesh/"; // �e�N�X�`���Ȃ����b�V������̉摜
const string MeshOnTextureImagePath = targetPath + "/MeshOnTexture/"; // �e�N�X�`�����胁�b�V������̉摜
const string ShadeImagePath = targetPath + "/Shade.bmp";
const string InterpolationShadeImagePath = targetPath + "/InterpolatedShade.bmp";

// ���ʓ���
const string TextureVideoPath = targetPath + "/Texture";
const string MeshVideoPath = targetPath + "/Mesh";
const string MeshOnTextureVideoPath = targetPath + "/MeshOnTexture";
