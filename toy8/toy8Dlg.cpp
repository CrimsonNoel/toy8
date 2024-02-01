
// toy8Dlg.cpp : 구현 파일
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


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// Ctoy8Dlg 대화 상자



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


// Ctoy8Dlg 메시지 처리기

BOOL Ctoy8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	// 확장자 관리
	szFilter = "텍스트 파일(*.txt, *.csv) | *.txt;*.csv; |모든파일(*.*)|*.*||";


	csm = new CStudentManager;





	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Ctoy8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Ctoy8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctoy8Dlg::OnBnClickedButtonload()
{
	// 버튼을 눌러 csv파일 로드합니다.
	// 로드후 studentList에 등록되고 전체 평균값을 구합니다. 남학생/여학생 클래스에 따로 저장하고
	// 각 성별 클래스에 저장후 성별마다 창에 자동 업로드됩니다. 이때 각 성별의 국어,수학 값의 평균을 구합니다
	CFileDialog dlg(TRUE, "", "", OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CString pathName = dlg.GetPathName(); // 경로
		errno_t fileOpen = fopen_s(&file, pathName, "rt");
		if (fileOpen == 0)
		{
			int cnt = 0;
			char str[100];
			while (fgets(str, sizeof(str), file) != NULL)
			{
				if (str[strlen(str) - 1] == '\n')
					str[strlen(str) - 1] = '\0';
				if (cnt == 0) //카테고리 분류
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
			size_t categorySize = category.size();// 카테고리 갯수
			csm->GetListStudent(nStudentList); // 전체학생 데이터

			InsertStudentList(nStudentList, categorySize);


			fclose(file); // 파일 닫기
		}
		else
		{	// 파일이 안 열렸을 경우
			char errormsg[100];
			strerror_s(errormsg, sizeof(errormsg) + 1, fileOpen);
			printf("오류코드: %d, 오류내용: %s", fileOpen, errormsg);
		}
	}
}


void Ctoy8Dlg::OnBnClickedButtonsavefile()
{
	CFileDialog dlg(FALSE, "", "", OFN_HIDEREADONLY, "텍스트파일(*.txt)|*.txt;||");
	CString pathName = dlg.GetPathName();
	if (IDOK == dlg.DoModal())
	{
		pathName = dlg.GetPathName(); // 경로저장
		errno_t fileOpen = fopen_s(&file, pathName, "wt");
		if (fileOpen == 0)
		{
			CString result;
			GetDlgItemText(IDC_EDIT_studentListAverage, result);
			fprintf(file, "전체 학생 평균값: %s", result.GetString());
			fclose(file); // 파일닫기
		}

	}
}

void Ctoy8Dlg::Category(char* str)
{// 첫줄은 카테고리로서 분류하고 각 List 창에 뿌림
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
			m_studentList.SetItemText(i, 2, "남");
			m_studentMale.InsertItem(male, str);
			m_studentMale.SetItemText(male, 1, studentList[i]->getName());
			m_studentMale.SetItemText(male, 2, "남");
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
			m_studentList.SetItemText(i, 2, "여");
			m_studentFemale.InsertItem(female, str);
			m_studentFemale.SetItemText(female, 1, studentList[i]->getName());
			m_studentFemale.SetItemText(female, 2, "여");
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	vector<CStudent*> nStudentList;
	csm->GetListStudent(nStudentList); // 전체학생 데이터
	size_t categorySize = category.size();// 카테고리 갯수
	Average(nStudentList, categorySize); // 전체학생 평균
	AverageMale(nStudentList, categorySize); // 남학생 평균
	AverageFemale(nStudentList, categorySize); // 여학생 평균
}
