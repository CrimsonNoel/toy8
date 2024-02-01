#pragma once
#include "vector"

using namespace std;

class CStudent;
class CStudentMale;
class CStudentFemale;

//class CStudent
//{
//protected:
//	int number; // 번호
//	CString name; // 이름
//	bool isFemale; // true = 남, false = 여
//	int korean; // 국어점수
//	int math; // 수학점수
//public:
//	  int getNumber() { return number; }
//	 CString getName() { return name; }
//	 bool getIsFemale() { return isFemale; }
//	 int getKorean() { return korean; }
//	 int getMath() { return math; }
//
//
//
//	 void setStudent(vector<CString>& rawOne);
//
//	CStudent();
//	virtual ~CStudent();
//};


class CStudentManager
{

public:
	~CStudentManager();

private:
	vector<CStudent*> pListStu;
	CStudent* sss;
public:
	void insertData(char* str);
	void SetListStudent(CStudent* student);
	void GetListStudent(vector<CStudent*>& studentList);
};

class CStudent
{
protected:
	int number; // 번호
	CString name; // 이름
	bool isFemale; // true = 남, false = 여
	int korean; // 국어점수
	int math; // 수학점수
public:
	virtual int getNumber() { return number; }
	virtual CString getName() { return name; }
	virtual bool getIsFemale() { return isFemale; }
	virtual int getKorean() { return korean; }
	virtual int getMath() { return math; }
	
	virtual void setStudent(vector<CString>& rawOne) = 0;

	CStudent();
	virtual ~CStudent();
};


class CStudentMale : public CStudent
{
public:
	virtual void setStudent(vector<CString>& rawOne);
	virtual ~CStudentMale();
};
class CStudentFemale : public CStudent
{
public:
	virtual void setStudent(vector<CString>& rawOne);
	virtual int getKorean(); // 다형성을 이용해 원본을 손대지 않고 여자클래스 점수 +하기.
	virtual int getMath();   // if문을 하나 줄일 수 있는 방법이다.
	virtual ~CStudentFemale();
};
