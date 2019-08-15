#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv2/xfeatures2d.hpp>

using namespace cv::xfeatures2d;
using namespace cv;

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("/home/yurik/Documents/Program/idea/images/img1.ppm");

    std::vector<cv::KeyPoint> keypoints;
    cv::FAST(img, keypoints, 20);
    cv::Mat img_keypoints;
    cv::drawKeypoints(img, keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
    cv::imshow("Keypoints", img_keypoints);

	waitKey(0);
	return 0;
}
