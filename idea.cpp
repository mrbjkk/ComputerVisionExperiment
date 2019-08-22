#include <iostream>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <typeinfo>

using namespace cv;

int main(int argc, char* argv[])
{
    cv::Mat img1 = cv::imread("/home/yurik/Documents/Program/cvexp/images/img1.ppm", CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat img2 = cv::imread("/home/yurik/Documents/Program/cvexp/images/img2.ppm", CV_LOAD_IMAGE_GRAYSCALE);
//    std::vector<cv::KeyPoint> keypoints_1, keypoints_2;
//    cv::Mat descriptor_1, descriptor_2;

    int Thres = 70;
    int Octave = 4;
    float PatternScales = 1.0f;

    auto brisk = cv::BRISK::create(Thres, Octave, PatternScales);
//    std::cout<<typeid(brisk).name()<<std::endl;
    std::vector<cv::KeyPoint> kp1, kp2;
    cv::Mat des1, des2;

//    brisk->detect(img1, kp1);
//    brisk->compute(img1, )
    brisk->detectAndCompute(img1, Mat(), kp1, des1);
    brisk->detectAndCompute(img2, Mat(), kp2, des2);

    std::cout<<"kp1 size is: "<<kp1.size()<<std::endl;
    std::cout<<"kp2 size is: "<<kp2.size()<<std::endl;

    float x = kp1[0].pt.x;
    std::cout<<"x is:"<<x<<std::endl;

//    for(auto i : kp1)
//    {
//        std::cout<<i<<std::endl;
//    }

//    cv::BFMatcher matcher(NORM_HAMMING, true);
//    std::vector<std::vector<DMatch>> matches;
}
