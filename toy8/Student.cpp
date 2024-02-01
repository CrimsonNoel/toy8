#include "stdafx.h"
#include "Student.h"
#include "vector"
using namespace std;

CStudent::CStudent()
{
	number = 0; // ��ȣ
	name = "None"; // �̸�
	isMale = false; // true = ��, false = ��
	korean = 0; // ��������
	math = 0; // ��������
}

void CStudentMale::setStudent(vector<CString>& rawOne)
{
	this->number = atoi(rawOne[0]); // ��ȣ
	this->name = rawOne[1]; // �̸�
	this->isMale = false; // ����
	this->korean = atoi(rawOne[3]); // ��������
	this->math = atoi(rawOne[4]); // ��������
}
void CStudentFemale::setStudent(vector<CString>& rawOne)
{
	this->number = atoi(rawOne[0]); // ��ȣ
	this->name = rawOne[1]; // �̸�
	this->isMale = true; // ����
	this->korean = atoi(rawOne[3]); // ��������
	this->math = atoi(rawOne[4]); // ��������
}



CStudentManager::~CStudentManager()
{	// vector<CStudent*> pListStu; �� delete
	for (int i = 0; i < pListStu.size(); i++) 
	{
		delete(pListStu[i]);
	}
}

void CStudentManager::insertData(char* str)
{
	int cnt = 0;
	vector<CString> rawOne;

	char* context = NULL;
	char* c = strtok_s(str, ",", &context);
	while (c != NULL)
	{
		rawOne.push_back(c);
		c = strtok_s(NULL, ",", &context);
		cnt++;
	}
	if (cnt == 5)
	{
		if (rawOne[2]=="��")
		{ // ���л�
			sss = new CStudentMale;
		}
		else
		{ // ���л�
			sss = new CStudentFemale;
		}
		sss->setStudent(rawOne); // override
		SetListStudent(sss); 
	}
}

void CStudentManager::SetListStudent(CStudent* student)
{
	if(student->getNumber()==0){ }
	pListStu.push_back(student);
}

void CStudentManager::GetListStudent(vector<CStudent*>& studentList)
{
	for (int i = 0; i < pListStu.size(); i++)
	{
		studentList.push_back(pListStu[i]);
	}
}

CStudent::~CStudent(){	}
CStudentMale::~CStudentMale(){	}
CStudentFemale::~CStudentFemale(){	}
