#include <opencv2/opencv.hpp>

void gaussianblur(const cv::Mat& image)
{
    cv::namedWindow("gaussianblur-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("gaussianblur-out", cv::WINDOW_AUTOSIZE);

    cv::imshow("gaussianblur", image);

    cv::Mat out;

    cv::GaussianBlur(image, out, cv::Size(5,5), 3, 3);
}
