#ifndef MESHMODEL_H
#define MESHMODEL_H

#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkDoubleArray.h>
#include <vtkMath.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "myAlgo.h"
#include "pfh.h"

using namespace std;

class MeshModel {
public:
	MeshModel();
	~MeshModel() {}

public:
	int id;
	bool isValid;

	// �����������Ϣ
	vtkSmartPointer<vtkSTLReader> reader;		// STL reader
	vtkSmartPointer<vtkPolyData> polydata;		// ���������
	vtkSmartPointer<vtkDoubleArray> center;		// ����

	// pca���ɷַ�������
	vtkSmartPointer<vtkDoubleArray> xAxis;
	vtkSmartPointer<vtkDoubleArray> yAxis;
	vtkSmartPointer<vtkDoubleArray> zAxis;

	// ÿ�㷨����
	vtkSmartPointer<vtkDoubleArray> normalX;
	vtkSmartPointer<vtkDoubleArray> normalY;
	vtkSmartPointer<vtkDoubleArray> normalZ;

	// ÿ����pca����ϵ��������
	vtkSmartPointer<vtkDoubleArray> xCor;
	vtkSmartPointer<vtkDoubleArray> yCor;
	vtkSmartPointer<vtkDoubleArray> zCor;

	// pca����ϵ��ֵ
	double xCorMin, xCorMax;
	double yCorMin, yCorMax;
	double zCorMin, zCorMax;

	// ��߳���
	double maxLen;

public:
	void readSTL(string folderPath, int id);
	void update();
	void getNormal();
	void getNewCor();
	void getPFH(int i, vtkSmartPointer<vtkDoubleArray> &histogram);
	void output();
	void outputToFilePFH(string folderPath);
	void outputToFilePos(string folderPath);
	void outputToFileNewCor(string inPath, string outPath);
};

#endif
