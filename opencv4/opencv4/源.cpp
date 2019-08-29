
#include <opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
#define WINDOW_NAME "�����Ի��ʾ����"


const int g_nMaxAlphaValue = 100;//Alphaֵ�����ֵ
int g_nAlphaValueSlider;//��������Ӧ�ı���
double g_dAlphaValue;
double g_dBetaValue;
//�����洢ͼ��ı���
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;
//��������Ӧ�������Ļص�����
void on_Trackbar(int, void*)
{
	g_dAlphaValue = (double) g_nAlphaValueSlider / g_nMaxAlphaValue;

	g_dBetaValue = (1.0 - g_dAlphaValue);

	addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);

	imshow(WINDOW_NAME,g_dstImage);
}

int main(int argc,char**argv)
{
	g_srcImage1 = imread("2.jpg");//ͼ���С����ͬ
	g_srcImage2 = imread("1.jpg");
	if(!g_srcImage1.data)
	{
		printf("��ȡ��һ��ͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ��ͼƬ����~��\n");
			return-1;
	}
			if(!g_srcImage2.data)
	{
		printf("��ȡ�ڶ���ͼƬ������ȷ��Ŀ¼���Ƿ���imread ����ָ��ͼƬ����~��\n");
			return-1;
	}

	//���û�������ֵΪ70
	g_nAlphaValueSlider = 70;

	namedWindow(WINDOW_NAME,WINDOW_NORMAL);
	//�ڴ����Ĵ����д���һ���������ؼ�
	char TrackbarName[50];
	sprintf(TrackbarName,"͸��ֵ%d",g_nMaxAlphaValue);
	createTrackbar(TrackbarName,WINDOW_NAME,&g_nAlphaValueSlider,g_nMaxAlphaValue,on_Trackbar);
	//����ڻص���������ʾ
	on_Trackbar(g_nAlphaValueSlider,0);
	//��������˳�
	waitKey(0);
	return 0;
}