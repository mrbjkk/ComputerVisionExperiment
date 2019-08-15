#include<opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;


int main(int argc, char** argv)
{
    Mat img_1 = imread("/home/yurik/Pictures/Pre0325/1562086963.jpg");
    Mat img_2 = imread("/home/yurik/Pictures/Pre0325/465532305.jpg");

    // -- Step 1: Detect the keypoints using STAR Detector
    std::vector<KeyPoint> keypoints_1,keypoints_2;
    StarDetector detector;
    detector.detect(img_1, keypoints_1);
    detector.detect(img_2, keypoints_2);

    // -- Stpe 2: Calculate descriptors (feature vectors)
    BriefDescriptorExtractor brief;
    Mat descriptors_1, descriptors_2;
    brief.compute(img_1, keypoints_1, descriptors_1);
    brief.compute(img_2, keypoints_2, descriptors_2);

    //-- Step 3: Matching descriptor vectors with a brute force matcher
    BFMatcher matcher(NORM_HAMMING);
    std::vector<DMatch> mathces;
    matcher.match(descriptors_1, descriptors_2, mathces);
    // -- dwaw matches
    Mat img_mathes;
    drawMatches(img_1, keypoints_1, img_2, keypoints_2, mathces, img_mathes);
    // -- show
    imshow("Mathces", img_mathes);
    waitKey(0);
    return 0;
}
