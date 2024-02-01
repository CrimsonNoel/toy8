#include "stdafx.h"
#include "Student.h"
#include "vector"
using namespace std;

CStudent::CStudent()
{
	number = 0; // 번호
	name = "None"; // 이름
	isFemale = false; // true = 여, false = 남
	korean = 0; // 국어점수
	math = 0; // 수학점수
}

void CStudentMale::setStudent(vector<CString>& rawOne)
{
	this->number = atoi(rawOne[0]); // 번호
	this->name = rawOne[1]; // 이름
	this->isFemale = false; // 성별
	this->korean = atoi(rawOne[3]); // 국어점수
	this->math = atoi(rawOne[4]); // 수학점수
}

void CStudentFemale::setStudent(vector<CString>& rawOne)
{
	this->number = atoi(rawOne[0]); // 번호
	this->name = rawOne[1]; // 이름
	this->isFemale = true; // 성별
	this->korean = atoi(rawOne[3]); // 국어점수
	this->math = atoi(rawOne[4]); // 수학점수
}

int CStudentFemale::getKorean()
{
	return korean+1;
}

int CStudentFemale::getMath()
{
	return math+1;
}



CStudentManager::~CStudentManager()
{	// vector<CStudent*> pListStu; 의 delete
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
		if (rawOne[2]=="남")
		{ // 남학생 new 생성
			sss = new CStudentMale;
		}
		else
		{ // 여학생 new 생성
			sss = new CStudentFemale;
		}
		sss->setStudent(rawOne); // override
		SetListStudent(sss); 
	}
}

void CStudentManager::SetListStudent(CStudent* student)
{ // 가상함수 적용부분 CStudent* 포인터가 가리키는 객체의 오버라이딩한 함수를 실행함
	if(student->getNumber()==0){ }
	pListStu.push_back(student);
}

void CStudentManager::GetListStudent(vector<CStudent*>& studentList)
{
		studentList=pListStu;
}

CStudent::~CStudent(){	}
CStudentMale::~CStudentMale(){	}
CStudentFemale::~CStudentFemale(){	}
