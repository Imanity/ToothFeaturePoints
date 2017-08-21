#ifndef MESHMODEL_H
#define MESHMODEL_H

#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkDoubleArray.h>
#include <vtkMath.h>
#include <vtkMatrix4x4.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <io.h>
#include <vector>
#include <algorithm>

#include "Utility.h"
#include "BmpWriter.h"

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

	// ÿ����pca����ϵ��������
	vtkSmartPointer<vtkDoubleArray> xCor;
	vtkSmartPointer<vtkDoubleArray> yCor;
	vtkSmartPointer<vtkDoubleArray> zCor;

	// pca����ϵ��ֵ
	double xCorMin, xCorMax;
	double yCorMin, yCorMax;
	double zCorMin, zCorMax;

public:
	void readSTL(string folderPath, string matrixPath, int id);
	void update();
	void outputToImage(string filePath);
	void getNewCor();
	void outputFeature(string featurePath, string filePath);
};

#endif
