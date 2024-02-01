
// toy8Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "toy8.h"
#include "toy8Dlg.h"
#include "afxdialogex.h"
#include "vector"
#include "Student.h"
#include "resource.h"


using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctoy8Dlg ��ȭ ����



Ctoy8Dlg::Ctoy8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TOY8_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctoy8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_studentList, m_studentList);
	DDX_Control(pDX, IDC_LIST_male, m_studentMale);
	DDX_Control(pDX, IDC_LIST_female, m_studentFemale);
}

BEGIN_MESSAGE_MAP(Ctoy8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_load, &Ctoy8Dlg::OnBnClickedButtonload)
	ON_BN_CLICKED(IDC_BUTTON_saveFile, &Ctoy8Dlg::OnBnClickedButtonsavefile)
	ON_BN_CLICKED(IDC_BUTTON_average11, &Ctoy8Dlg::OnBnClickedButtonaverage11)
END_MESSAGE_MAP()


// Ctoy8Dlg �޽��� ó����

BOOL Ctoy8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	// Ȯ���� ����
	szFilter = "�ؽ�Ʈ ����(*.txt, *.csv) | *.txt;*.csv; |�������(*.*)|*.*||";


	csm = new CStudentManager;





	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Ctoy8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Ctoy8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Ctoy8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctoy8Dlg::OnBnClickedButtonload()
{
	// ��ư�� ���� csv���� �ε��մϴ�.
	// �ε��� studentList�� ��ϵǰ� ��ü ��հ��� ���մϴ�. ���л�/���л� Ŭ������ ���� �����ϰ�
	// �� ���� Ŭ������ ������ �������� â�� �ڵ� ���ε�˴ϴ�. �̶� �� ������ ����,���� ���� ����� ���մϴ�
	CFileDialog dlg(TRUE, "", "", OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CString pathName = dlg.GetPathName(); // ���
		errno_t fileOpen = fopen_s(&file, pathName, "rt");
		if (fileOpen == 0)
		{
			int cnt = 0;
			char str[100];
			while (fgets(str, sizeof(str), file) != NULL)
			{
				if (str[strlen(str) - 1] == '\n')
					str[strlen(str) - 1] = '\0';
				if (cnt == 0) //ī�װ� �з�
				{
					Category(str);
				}
				else
				{
					csm->insertData(str);
				}
				cnt++;
			}

			vector<CStudent*> nStudentList;
			size_t categorySize = category.size();// ī�װ� ����
			csm->GetListStudent(nStudentList); // ��ü�л� ������

			InsertStudentList(nStudentList, categorySize);


			fclose(file); // ���� �ݱ�
		}
		else
		{	// ������ �� ������ ���
			char errormsg[100];
			strerror_s(errormsg, sizeof(errormsg) + 1, fileOpen);
			printf("�����ڵ�: %d, ��������: %s", fileOpen, errormsg);
		}
	}
}


void Ctoy8Dlg::OnBnClickedButtonsavefile()
{
	CFileDialog dlg(FALSE, "", "", OFN_HIDEREADONLY, "�ؽ�Ʈ����(*.txt)|*.txt;||");
	CString pathName = dlg.GetPathName();
	if (IDOK == dlg.DoModal())
	{
		pathName = dlg.GetPathName(); // �������
		errno_t fileOpen = fopen_s(&file, pathName, "wt");
		if (fileOpen == 0)
		{
			CString result;
			GetDlgItemText(IDC_EDIT_studentListAverage, result);
			fprintf(file, "��ü �л� ��հ�: %s", result.GetString());
			fclose(file); // ���ϴݱ�
		}

	}
}

void Ctoy8Dlg::Category(char* str)
{// ù���� ī�װ��μ� �з��ϰ� �� List â�� �Ѹ�
	char* context = NULL;
	char* c = strtok_s(str, ",", &context);
	while (c != NULL)
	{
		category.push_back(c);
		c = strtok_s(NULL, ",", &context);
	}
	for (int i = 0; i < category.size(); i++)
	{
		m_studentList.InsertColumn(i, category[i], LVCFMT_LEFT, 100);
		m_studentMale.InsertColumn(i, category[i], LVCFMT_LEFT, 100);
		m_studentFemale.InsertColumn(i, category[i], LVCFMT_LEFT, 100);
	}
}

void Ctoy8Dlg::InsertStudentList(vector<CStudent*>& studentList, int size)
{
	int male = 0;
	int female = 0;
	CString str;
	for (int i = 0; i < studentList.size(); i++)
	{
		/*str.Format("%d", studentList[i]->getNumber());
		m_studentList.InsertItem(i, str);
		m_studentList.SetItemText(i, 1, studentList[i]->getName());
		str.Format("%d", studentList[i]->getKorean());
		m_studentList.SetItemText(i, 3, str);
		str.Format("%d", studentList[i]->getMath());
		m_studentList.SetItemText(i, 4, str);*/
		if (studentList[i]->getIsFemale() == false)
		{
			str.Format("%d", studentList[i]->getNumber());
			m_studentList.InsertItem(i, str);
			m_studentList.SetItemText(i, 1, studentList[i]->getName());
			m_studentList.SetItemText(i, 2, "��");
			m_studentMale.InsertItem(male, str);
			m_studentMale.SetItemText(male, 1, studentList[i]->getName());
			m_studentMale.SetItemText(male, 2, "��");
			str.Format("%d", studentList[i]->getKorean());
			m_studentList.SetItemText(i, 3, str);
			m_studentMale.SetItemText(male, 3, str);
			str.Format("%d", studentList[i]->getMath());
			m_studentList.SetItemText(i, 4, str);
			m_studentMale.SetItemText(male, 4, str);
			male++;
		}
		else
		{
			str.Format("%d", studentList[i]->getNumber());
			m_studentList.InsertItem(i, str);
			m_studentList.SetItemText(i, 1, studentList[i]->getName());
			m_studentList.SetItemText(i, 2, "��");
			m_studentFemale.InsertItem(female, str);
			m_studentFemale.SetItemText(female, 1, studentList[i]->getName());
			m_studentFemale.SetItemText(female, 2, "��");
			str.Format("%d", (studentList[i]->getKorean())>100 ? 100 : (studentList[i]->getKorean()));
			m_studentList.SetItemText(i, 3, str);
			m_studentFemale.SetItemText(female, 3, str);
			str.Format("%d", (studentList[i]->getMath())>100 ? 100 : (studentList[i]->getMath()));
			m_studentList.SetItemText(i, 4, str);
			m_studentFemale.SetItemText(female, 4, str);
			female++;
		}
	}
}
//double Ctoy8Dlg::sumNum operator+(vector<CStudent*>& st)
//{
//	AfxMessageBox("CStudent");
//	return 1;
//}
//
//double Ctoy8Dlg::sumNum(vector<CStudentFemale>& sf)
//{
//	AfxMessageBox("CStudentFemale");
//	return 1;
//}
//double Ctoy8Dlg::sumNum(vector<CStudentMale>& sm)
//{
//	AfxMessageBox("CStudentMale");
//	return 1;
//}
void Ctoy8Dlg::Average(vector<CStudent*>& student, int categorySize)
{
	student;
	double sum = 0;
	for (int i = 0; i < student.size(); i++)
	{
		sum += student[i]->getKorean();
		sum += student[i]->getMath();
	}
	CString average;
	sum = sum / (student.size() * 2);
	average.Format("%.2f", sum);
	SetDlgItemText(IDC_EDIT_studentListAverage, average);
}

void Ctoy8Dlg::AverageMale(vector<CStudent*>& student, int categorySize)
{
	int cnt = 0;
	double sum = 0;
	for (int i = 0; i < student.size(); i++)
	{
		if (student[i]->getIsFemale() == false)
		{
			sum += student[i]->getKorean();
			sum += student[i]->getMath();
			cnt++;
		}
	}
	CString average;
	sum = sum / (cnt * 2);
	average.Format("%.2f", sum);
	SetDlgItemText(IDC_EDIT_maleAverage, average);
}

void Ctoy8Dlg::AverageFemale(vector<CStudent*>& student, int categorySize)
{
	int cnt = 0;
	double sum = 0;
	for (int i = 0; i < student.size(); i++)
	{
		if (student[i]->getIsFemale() == true)
		{
			sum += student[i]->getKorean();
			sum += student[i]->getMath();
			cnt++;
		}
	}
	CString average;
	sum = sum / (cnt * 2);
	average.Format("%.2f", sum);
	SetDlgItemText(IDC_EDIT_femaleAverage, average);

}

void Ctoy8Dlg::OnBnClickedButtonaverage11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	vector<CStudent*> nStudentList;
	csm->GetListStudent(nStudentList); // ��ü�л� ������
	size_t categorySize = category.size();// ī�װ� ����
	Average(nStudentList, categorySize); // ��ü�л� ���
	AverageMale(nStudentList, categorySize); // ���л� ���
	AverageFemale(nStudentList, categorySize); // ���л� ���
}
