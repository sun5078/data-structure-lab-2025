#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cout << "�̹����� �ҷ��� �� �����ϴ�." << std::endl;
        return -1;
    }
    cv::imshow("�Է� �̹���", image);
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
    std::cout << "��� ����" << std::endl;
    std::cout << maxBrightness << std::endl;

    return 0;
}
