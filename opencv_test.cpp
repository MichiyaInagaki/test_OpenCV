// opencv_test.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(void)
{
	cv::Mat image;
	image = cv::imread("C:/opencv/opencv_contrib/samples/data/corridor.jpg");

	if (image.empty() == true) {
		return 0;
	}

	cv::imshow("画像", image);
	cv::waitKey();

	return 0;
}
