#include "stdafx.h" 
#include "opencv2\\opencv.hpp" 
#include "opencv/highgui.h"
#include "opencv/cv.h"

int main(int argc, char* argv[])
{
	// ���͗p�摜
	IplImage* img;
	// �o�͗p�摜
	IplImage* img2;
	// �ǂݍ��݉摜�t�@�C����
	char imgfile[] = "image/lena.bmp";

	// �摜���O���[�X�P�[���œǂݍ���
	img = cvLoadImage(imgfile, CV_LOAD_IMAGE_GRAYSCALE);
	// �w��Ɋ�Â����摜�w�b�_�A�y�т��̃f�[�^�̈�𐶐�����
	img2 = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

	// �G�b�W���o
	cvCanny(img, img2, 64, 128);

	// �摜�̕\���p�E�B���h�E����
	cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);
	// �w�肵���E�B���h�E���ɉ摜��\������
	cvShowImage("lena", img2);

	// �L�[���͑҂�
	cvWaitKey(0);

	// �w�肵���E�B���h�E�̔j�����s��
	cvDestroyWindow("lena");
	// ���͉摜�̉��
	cvReleaseImage(&img);
	// �o�͉摜�̉��
	cvReleaseImage(&img2);

	return 0;
}