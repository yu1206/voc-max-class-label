#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
using namespace cv;
using namespace std;

int test19(int argc, char *argv[])
{

	
	string  labelpath = "G:/F/YOLO/yolo-v2/darknet-master/train/VOCdevkit/VOC2007/labels/0_test.txt";
	fstream finRead;
	finRead.open(labelpath, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line;   int k = 0;
	int maxlabel = 0; int minlabel = 100;
	while (getline(finRead, line))
	{
		if (line.empty())
		{
			break;
		}
		fstream fin1;
		fin1.open(line);
		cout << line.c_str() << endl;
		if (!fin1.is_open())
		{
			cout << "error" << endl;
			cout << line.c_str() << endl;
			cout << "fin1 文件数据打开错误！" << endl;
			system("pause");
			return false;
		}
		
		string line1;  
		while (getline(fin1, line1))
		{
			int label; int x1, y1, x2, y2;
			stringstream str_s(line1);
			str_s >> label >> x1 >> y1 >> x2 >> y2;
			if (maxlabel < label)
			{
				maxlabel = label;
			}
			if (minlabel>label)
			{
				minlabel = label;
			}
		}
		
	}

	printf("maxlabel=%d,minlabel=%d,\n", maxlabel, minlabel);
	system("pause");
	finRead.close();
	return 0;
}