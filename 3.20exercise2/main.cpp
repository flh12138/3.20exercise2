#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
		cv::Mat src = imread("E:\\PIC\\coin.png",0);
		cv::Mat binaryMat;
		threshold(src, binaryMat, 0, 255, THRESH_OTSU);
		cv::Mat labels;
		cv::Mat stats;
		cv::Mat cenrtroids;
		cv::Mat resultMat;
		int nComp = cv::connectedComponentsWithStats(binaryMat,labels,stats,cenrtroids,8);
		cout << "the number is" << nComp << endl;
		for (int i = 1; i < nComp; i++)
		{
			Rect bndbox;
			bndbox.x = cenrtroids.at<int>(i, 0);
			bndbox.y = cenrtroids.at<int>(i, 1);
			bndbox.width = cenrtroids.at<int>(i, 2);
			bndbox.height = cenrtroids.at<int>(i, 3);
			rectangle(binaryMat, bndbox, CV_RGB(255, 255, 255), 1, 8, 0);
		}
		imshow("src1", src);
		imshow("sec2", binaryMat);
		//imshow("src3", resultMat);
		waitKey(0);
}