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
	    int nComp = connectedComponentsWithStats(binaryMat,labels,stats,cenrtroids,8,4);
		//int labelNum = cenrtroids.rows-1;
		cout << "the number is" << nComp-1 << endl;
		for (int i = 1; i < nComp; i++)
		{
			Rect bndbox;
	    	bndbox.x = stats.at<int>(i, 0);
	        bndbox.y = stats.at<int>(i, 1);
			bndbox.width = stats.at<int>(i, 2);
			bndbox.height = stats.at<int>(i, 3);
			rectangle(binaryMat, bndbox, CV_RGB(255, 255, 255), 3, 8, 0);
		}
	    imshow("src1", src);
		imshow("sec2", binaryMat);
		waitKey(0);
}