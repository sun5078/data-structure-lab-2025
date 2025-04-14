#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cout << "이미지를 불러올 수 없습니다." << std::endl;
        return -1;
    }
    cv::imshow("입력 이미지", image);
    cv::waitKey(0);  


    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    int maxBrightness = 0;
    for (int i = 0; i < gray.rows; i++) {
        for (int j = 0; j < gray.cols; j++) {
            int brightness = static_cast<int>(gray.at<uchar>(i, j));
            if (brightness > maxBrightness) {
                maxBrightness = brightness;
            }
        }
    }
    std::cout << "출력 예시" << std::endl;
    std::cout << maxBrightness << std::endl;

    return 0;
}
