#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


int main(int argc, char** argv)
{
	cv::Mat buffer;
	buffer = cv::imread("cn7pen.jpg");
	cv::Mat gray;
	cv::Mat edges;
	cv::Mat color;
	cv::cvtColor(buffer, gray, cv::COLOR_BGR2GRAY);
	cv::medianBlur(gray, gray, 5);
	cv::adaptiveThreshold(gray, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 9, 9);
	cv::bilateralFilter(buffer, color, 9, 300, 300);
	cv::bitwise_and(color, color, buffer, edges);
	cv::imshow("Cartoon", buffer);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

