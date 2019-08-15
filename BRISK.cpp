#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv2/xfeatures2d.hpp>

//using namespace cv::xfeatures2d;
using namespace cv;

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("/home/yurik/Documents/Program/idea/images/img1.ppm");
    std::vector<cv::Mat> cDownOut;
    std::vector<cv::Mat> dDownOut;
    std::vector<cv::Mat> GauOut;

    // Downsampling the orig image (paper's ci)
    cv::Mat cDownsampleout = img;
    for(int i = 1; i < 5; i++)
    {
        cDownOut.emplace_back(cDownsampleout);
        cv::pyrDown(cDownsampleout, cDownsampleout, cv::Size(cDownsampleout.cols/2, cDownsampleout.rows/2));
    }

    // paper's di
    cv::Mat dDownsampleout;
    cv::pyrDown(img, dDownsampleout, cv::Size(img.cols/1.5, img.rows/1.5));
    for(int i = 1; i < 5; i++)
    {
        dDownOut.emplace_back(dDownsampleout);
        cv::pyrDown(dDownsampleout, dDownsampleout, cv::Size(dDownsampleout.cols/2, dDownsampleout.rows/2));
    }
    //    cv::Mat outputGaussian;
    //    cv::GaussianBlur(img, outputGaussian, cv::Size(4,3), 0, 0);
//    for(int i = 3; i < 10; i = i + 2)
//    {
//        cv::Mat outputGaussian;
//        cv::GaussianBlur(img, outputGaussian, cv::Size(i,3), 0, 0);
//        GauOut.emplace_back(outputGaussian);
////        std::cout<<"i : "<<i<<std::endl;
////        std::cout<<"outsize: "<<GauOut.size()<<std::endl;
////        cv::imshow("test", GauOut[i-1]);
//    }
////    for (auto i : GauOut)
////    {
////        cv::imshow("test", i);
////    }
//
//    for (int i = 0; i < GauOut.size(); i++)
//    {
//        cv::imshow("test"+i, GauOut[i]);
//    }
//    cv::imshow("Gaussian", outputGaussian);

//    std::vector<cv::KeyPoint> keypoints;
//    cv::FAST(img, keypoints, 20);
//    cv::Mat img_keypoints;
//    cv::drawKeypoints(img, keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
//    cv::imshow("Keypoints", img_keypoints);
//
	waitKey(0);
	return 0;
}
