#include "stdafx.h" 
#include "opencv2\\opencv.hpp" 
#include "opencv/highgui.h"
#include "opencv/cv.h"

// cv�Ƃ����c�����ȗ����܂��Ɛ錾
using namespace cv;
// std�Ƃ����c�����ȗ����܂��Ɛ錾
using namespace std;

int main(int argc, char *argv[])
{
	Mat im, gray;					// �ϐ��錾
									// �J�X�P�[�h���ފ�̎擾
	CascadeClassifier cascade;
	if (!cascade.load("C:/Users/SENS/Downloads/opencv/sources/data/haarcascades_cuda/haarcascade_frontalface_alt.xml")) return -1;
	vector<Rect> faces;
	VideoCapture cap(0);			// �J�����̃L���v�`��
	if (!cap.isOpened()) return -1;	// �L���v�`���̃G���[����

	while (1) {
		cap >> im;							// �J�����f���̎擾
		cvtColor(im, gray, CV_RGB2GRAY);	// �O���[�X�P�[���ϊ�
											// �J�X�P�[�h���ފ�Ŋ�̒T��
		cascade.detectMultiScale(gray, faces, 1.2, 2, CV_HAAR_SCALE_IMAGE, Size(50, 50));
		// ��̈����`�ň͂�
		vector<Rect>::const_iterator r = faces.begin();
		for (; r != faces.end(); ++r) {
			rectangle(im, Point(r->x, r->y), Point(r->x + r->width, r->y + r->height), Scalar(20, 20, 200), 3, CV_AA);
		}
		imshow("Camera", im);				// �f���̕\��
		if (waitKey(30) >= 0) break;		// �L�[���͂�����ΏI��
	}
	return 0;
}