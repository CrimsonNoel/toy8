
// toy8Dlg.h : ��� ����
//

#pragma once
#include "vector"
#include "afxcmn.h"
#include "Student.h"

using namespace std;

// ���� ����
//class CStudent;
class CStudentManager;

// Ctoy8Dlg ��ȭ ����
class Ctoy8Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Ctoy8Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOY8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
