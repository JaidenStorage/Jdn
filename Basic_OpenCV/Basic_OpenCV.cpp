#include "opencv2\opencv.hpp"

void JdnCV_Basic()
{
	int row = 50;  // y
	int col = 100;  // x

	cv::Mat src(row, col, CV_8UC1);
	cv::Mat dst(row, col, CV_8UC1);
	cv::Mat tmp(row, col, CV_8UC1);

	/*	�̹��� ����, ����, �ҷ�����	*/
	{
		/* �̹��� �⺻���� */
		cv::Mat Img(row, col, CV_8UC1);
		cv::Mat Img_Gray(row, col, CV_8UC1);
		cv::Mat Img_Color(row, col, CV_8UC3);
		{
			Img.rows; // y
			Img.cols;  // x
			Img.size;  // MatSize, (w,h) 
			Img.total();  // Total pixel count

			Img.depth();  // depth (Byte)
			Img.channels(); // channel
			Img.elemSize();	// depth X channel
			Img.type();  // CV_8UC1, CV_8UC3.....

			Img.empty();  // Empty?
			Img.isContinuous();  // continuous? (data)
			Img.isSubmatrix();  // SubMatrix?

			// �ȼ� �� ���� : 1ä��(���)
			unsigned char Value = Img_Gray.at<uchar>(row, col);

			// �ȼ� �� ���� : 3ä��(�÷�)
			unsigned char B = Img_Color.at<cv::Vec3b>(row, col)[0];
			unsigned char G = Img_Color.at<cv::Vec3b>(row, col)[1];
			unsigned char R = Img_Color.at<cv::Vec3b>(row, col)[2];

			// ROI
			cv::Mat Img_ROI = Img(cv::Range(0, Img.rows / 2), cv::Range(0, Img.cols / 2));
			Img_ROI.isSubmatrix(); // Roi Mat?
		}

		/* �̹��� ���� */
		cv::Mat Img_A(row, col, CV_8UC1);
		cv::Mat Img_B(cv::Size(row, col), CV_8UC1);
		cv::Mat Img_C = cv::Mat::zeros(row, col, CV_8UC1); // {0, 0, ...}
		cv::Mat Img_D(row, col, CV_8UC1, cv::Scalar(128)); // {128, 128, ...}
		cv::Mat Img_E(row, col, CV_8UC3, cv::Scalar(50, 100, 150)); // {50, 100, 150, 50, 100, 150, ...} 
		Img_E.setTo(cv::Scalar(255, 0, 0)); // {255, 0, 0, 255, 0, 0, ...}

		/* �̹��� �ҷ����� */
		cv::Mat Img_F = cv::imread("Path.bmp", cv::IMREAD_GRAYSCALE);

		/* �̹��� �����ϱ� */
		cv::imwrite("SaveFileName.bmp", Img_F);
	}


	/* �̹��� ���� */
	{
		// â�� �̹��� ���
		cv::namedWindow("TitleName", cv::WINDOW_NORMAL); // CV_WINDOW_AUTOSIZE
		cv::imshow("TitleName", dst);
		cv::waitKey(0);

		// Ʈ����
		int TrackBar = 50;
		int TrackBar_Max = 100;
		cv::namedWindow("TitleName", cv::WINDOW_NORMAL); // CV_WINDOW_AUTOSIZE
		cv::createTrackbar("TrackbarName", "TitleName", &TrackBar, TrackBar_Max);
		while (cv::waitKey(10) != 27)
		{
			dst = src + TrackBar;
			cv::imshow("TitleName", dst);
		}

		// â �ݱ�
		cv::destroyAllWindows();
	}


	/* �̹��� �⺻���� */
	{
		// ��Ģ����
		dst = src + 100;
		dst = src - 100;
		dst = src * 100;
		dst = src / 100;
		dst = src + tmp;
		dst = src - tmp;
		////dst = src * tmp; ��������
		////dst = src / tmp; ��������

		// �̹��� �����ϱ�
		src.copyTo(dst);
		dst = src.clone();

		// �÷� ��ȯ
		cv::cvtColor(src, dst, cv::COLOR_BayerBG2RGB);
		cv::cvtColor(src, dst, cv::COLOR_GRAY2BGR);

		// ��Ʈ ��ȯ
		src.convertTo(dst, CV_8UC1, 2); // dst = src * 2

		// �÷� ������ȯ (ȭ��Ʈ�뷱��, White Balance)
		cv::Mat mask(row, col, CV_8UC1);
		float red = 1.0, blue = 1.0, green = 1.0;
		cv::colorChange(src, mask, dst, red, green, blue);

		// ȸ��
		int FilpCode = 0;
		cv::flip(src, dst, FilpCode);	// 0 : X, 1 : Y, -1 : XY 
	}


	/* �̹��� ���� */
	{
		int threshold1 = 128;
		int threshold2 = 128;
		int var = 2;
		int size = 3, sigmaX = 10, sigmaY = 10;
		int repeat = 1;

		// Threshold ����, ��� ����
		cv::threshold(src, dst, threshold1, 255, cv::THRESH_BINARY);
		cv::threshold(src, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);	// �ڵ� Threshold
		cv::adaptiveThreshold(src, dst, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, size, var);

		// Blur ����, ��ó�� ����
		cv::blur(src, dst, cv::Size(row, col));
		cv::GaussianBlur(src, dst, cv::Size(row, col), sigmaX);	// Sigma : ǥ��������
		cv::medianBlur(src, dst, size);

		// bilateralFilter ����, ��ó�� ����, ���� ���� ����
		cv::bilateralFilter(src, dst, size, sigmaX, sigmaY);

		// Laplacian ����, ��輱 ����
		cv::Laplacian(src, dst, CV_8U, size);

		// Histogram ��Ȱȭ
		cv::equalizeHist(src, dst);

		// morphologyEx (Erode, Dilate, Open, Close, Gradient, Tophat, Blackhat )
		cv::Mat mask = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::morphologyEx(src, dst, cv::MORPH_ERODE, mask, cv::Point(-1, -1), repeat);
		cv::morphologyEx(src, dst, cv::MORPH_DILATE, mask, cv::Point(-1, -1), repeat);
		cv::morphologyEx(src, dst, cv::MORPH_OPEN, mask, cv::Point(-1, -1), repeat);
		cv::morphologyEx(src, dst, cv::MORPH_CLOSE, mask, cv::Point(-1, -1), repeat);
		cv::morphologyEx(src, dst, cv::MORPH_GRADIENT, mask, cv::Point(-1, -1), repeat);
		cv::morphologyEx(src, dst, cv::MORPH_TOPHAT, mask, cv::Point(-1, -1), repeat);
		cv::morphologyEx(src, dst, cv::MORPH_BLACKHAT, mask, cv::Point(-1, -1), repeat);

		// CannyEdge �˰���
		cv::Canny(src, dst, threshold1, threshold2); // threshold1 : threshold2 = 1 : 2, 1 : 3

		// Hitmap, ColorMap
		cv::applyColorMap(src, dst, cv::COLORMAP_JET);
	}


	/* �̹��� �׸��� */
	{
		cv::Point startPoint = cv::Point(0, 0);
		cv::Point endPoint = cv::Point(col, row);
		cv::Point centerPoint = cv::Point(col / 2, row / 2);
		cv::Scalar colorValue = cv::Scalar(128);
		int thickness = 1;
		int radius = 20;
		int fontscale = 1;

		cv::line(src, startPoint, endPoint, colorValue, thickness, cv::LINE_8, 0);
		cv::arrowedLine(src, startPoint, endPoint, colorValue, thickness, cv::LINE_8, 0);
		cv::rectangle(src, startPoint, endPoint, colorValue, thickness, cv::LINE_8, 0);
		cv::circle(src, centerPoint, radius, colorValue, thickness, cv::LINE_8, 0);

		cv::putText(src, "Text!!", startPoint, cv::FONT_HERSHEY_SIMPLEX, fontscale, colorValue, thickness, cv::LINE_8);
	}


	/* Ű���� ���콺 �̺�Ʈ */
	{
		int Time = 10;	// 10ms

		// �Ϲ�Ű��
		int Key = cv::waitKey(Time);
		//27(ESC), 127(DEL), 48~57(0~9), 60(<), 62(>)

	// Ư��Ű��
		int Key_ = cv::waitKeyEx(Time);
		//Delete		0x2e0000
		//��				0x250000
		//��				0x260000
		//��				0x270000
		//��				0x280000
		//F1			0x700000
		//F2			0x710000
		//F3			0x720000
		//F4			0x730000
		//F5			0x740000
		//F6			0x750000
		//F7			0x760000
		//F8			0x770000
		//F9			0x780000
		//F10			0x790000
		//F11			0x7a0000
		//F12			0x7b0000
	}


	/* Parallel_for_ ����ó�� */
	{
		// ����
		class Parallel_process : public cv::ParallelLoopBody
		{
		private:
			cv::Mat& inImg;
			cv::Mat& outImg;

		public:
			Parallel_process(cv::Mat& src, cv::Mat& dst) : inImg(src), outImg(dst) {
			}

			virtual void operator()(const cv::Range& range) const
			{
				for (int i = range.start; i < range.end; i++)
				{
					for (int j = 0; j < inImg.cols; j++)
					{
						inImg.at<uchar>(i, j) >= 128 ? outImg.at<uchar>(i, j) = 255 : outImg.at<uchar>(i, j) = 0;
					}
				}
			}

		};

		// ���
		cv::parallel_for_(cv::Range(0, src.rows), Parallel_process(src, dst));
	}


}
