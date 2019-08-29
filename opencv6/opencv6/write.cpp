#include<opencv2/opencv.hpp>
#include <vector>
#include <time.h>

using namespace std;
using namespace cv;

int main()
{
	//��ʼ��
	FileStorage fs("test.yaml", FileStorage::WRITE);

	//��ʼ�ļ�д��
	fs << "frameCount" << 5;

	time_t rawtime;
	time(&rawtime);
	fs << "calibrationDate" << asctime(localtime(&rawtime));

	Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, 320, 0, 1000, 240, 0, 0, 1);
	Mat distCoeffs = (Mat_<double>(5, 1) << 0.1, 0.01, -0.001, 0, 0);

	fs << "cameraMatrix" << cameraMatrix << "distCoeffs" << distCoeffs;
	fs << "features" << "[";
	for (int i = 0; i < 3; ++i)
	{
		int x = rand() % 640;
		int y = rand() % 480;
		uchar lbp = rand() % 256;

		fs << "{:" << "x" << x << "y" << y << "lbp" << "[:";
		for (int j = 0; j < 8; ++j)
		{
			fs << ((lbp >> j) & 1);
		}
		fs << "]" << "}";
	}

	fs << "]";

	fs.release();

	printf("�ļ���д��ϣ����ڹ���Ŀ¼�²鿴���ɵ��ļ�~\n");

	waitKey(0);

	return 0;
}