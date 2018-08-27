#include "stdafx.h" 
#include "opencv2\\opencv.hpp" 
#include "opencv/highgui.h"
#include "opencv/cv.h"

int main(int argc, char* argv[])
{
	// 入力用画像
	IplImage* img;
	// 出力用画像
	IplImage* img2;
	// 読み込み画像ファイル名
	char imgfile[] = "image/lena.bmp";

	// 画像をグレースケールで読み込む
	img = cvLoadImage(imgfile, CV_LOAD_IMAGE_GRAYSCALE);
	// 指定に基づいた画像ヘッダ、及びそのデータ領域を生成する
	img2 = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

	// エッジ検出
	cvCanny(img, img2, 64, 128);

	// 画像の表示用ウィンドウ生成
	cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);
	// 指定したウィンドウ内に画像を表示する
	cvShowImage("lena", img2);

	// キー入力待ち
	cvWaitKey(0);

	// 指定したウィンドウの破棄を行う
	cvDestroyWindow("lena");
	// 入力画像の解放
	cvReleaseImage(&img);
	// 出力画像の解放
	cvReleaseImage(&img2);

	return 0;
}