
// toy8Dlg.h : 헤더 파일
//

#pragma once
#include "vector"
#include "afxcmn.h"
#include "Student.h"

using namespace std;

// 전방 선언
//class CStudent;
class CStudentManager;

// Ctoy8Dlg 대화 상자
class Ctoy8Dlg : public CDialogEx
{
// 생성입니다.
public:
	Ctoy8Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOY8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	FILE* file;
	CString szFilter;
	vector<CString> category;
	CStudentManager* csm;
	CStudent* stu;

public:
	CListCtrl m_studentList;

	afx_msg void OnBnClickedButtonload();
	afx_msg void OnBnClickedButtonsavefile();

	void Category(char* str); 

	/*double sumNum(vector<CStudent>& st);
	double sumNum(vector<CStudentFemale>& sf);
	double sumNum(vector<CStudentMale>& sm);*/
	void InsertStudentList(vector<CStudent*>& student, int size); 
	void Average(vector<CStudent*>& student, int categorySize);
	void AverageMale(vector<CStudent*>& student, int categorySize);
	void AverageFemale(vector<CStudent*>& student, int categorySize);
	afx_msg void OnBnClickedButtonaverage11();
	CListCtrl m_studentMale;
	CListCtrl m_studentFemale;
};
