
// MFCApplication2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCApplication2Dlg dialog



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALC, &CMFCApplication2Dlg::OnBnClickedButtonCalc)
	ON_EN_UPDATE(IDC_EDIT_END_POS, &CMFCApplication2Dlg::OnEnUpdateEditEndPos)
	ON_BN_CLICKED(IDC_BUTTON_DIST_DOWN, &CMFCApplication2Dlg::OnBnClickedButtonDistDown)
	ON_BN_CLICKED(IDC_BUTTON_DIST_UP, &CMFCApplication2Dlg::OnBnClickedButtonDistUp)
END_MESSAGE_MAP()


// CMFCApplication2Dlg message handlers

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	this->MoveWindow(0, 0, 830, 430);

	GetDlgItem(IDC_EDIT_STEP_VIEW)->MoveWindow(15, 15, 780, 200);

	GetDlgItem(IDC_STATIC_START_POS)->MoveWindow(15, 250, 100, 30);
	GetDlgItem(IDC_STATIC_START_POS)->SetWindowTextW(_T("START_POS"));
	GetDlgItem(IDC_EDIT_START_POS)->MoveWindow(130, 250, 100, 30);
	
	GetDlgItem(IDC_STATIC_END_POS)->MoveWindow(15, 300, 100, 30);
	GetDlgItem(IDC_STATIC_END_POS)->SetWindowTextW(_T("END_POS"));
	GetDlgItem(IDC_EDIT_END_POS)->MoveWindow(130, 300, 100, 30);

	GetDlgItem(IDC_BUTTON_DIST_DOWN)->MoveWindow(140, 330, 40, 30);
	GetDlgItem(IDC_BUTTON_DIST_UP)->MoveWindow(190, 330, 40, 30);

	GetDlgItem(IDC_BUTTON_CALC)->MoveWindow(300, 250, 120, 80);
	GetDlgItem(IDC_BUTTON_CALC)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_EXPECTANCY_COUNT)->MoveWindow(300, 250, 120, 30);
	GetDlgItem(IDC_STATIC_EXPECTANCY_COUNT)->SetWindowTextW(_T("EXPECTANCY"));
	GetDlgItem(IDC_EDIT_EXPECTANCY_COUNT)->MoveWindow(300, 300, 120, 30);

	GetDlgItem(IDC_STATIC_MAX_SPEED)->MoveWindow(450, 250, 120, 30);
	GetDlgItem(IDC_STATIC_MAX_SPEED)->SetWindowTextW(_T("MAX_SPEED"));
	GetDlgItem(IDC_EDIT_MAX_SPEED)->MoveWindow(450, 300, 100, 30);

	GetDlgItem(IDC_STATIC_MOVE_COUNT)->MoveWindow(570, 250, 120, 30);
	GetDlgItem(IDC_STATIC_MOVE_COUNT)->SetWindowTextW(_T("MOVE_COUNT"));
	GetDlgItem(IDC_EDIT_MOVE_COUNT)->MoveWindow(570, 300, 100, 30);	

	GetDlgItem(IDC_STATIC_CALC_TIME)->MoveWindow(690, 250, 120, 30);
	GetDlgItem(IDC_STATIC_CALC_TIME)->SetWindowTextW(_T("CALC_TIME"));
	GetDlgItem(IDC_EDIT_CALC_TIME)->MoveWindow(690, 300, 100, 30);



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedButtonCalc()
{
	// TODO: Add your control notification handler code here
	CAlphaCentauri cTool;

	CString strStartPos;
	GetDlgItem(IDC_EDIT_START_POS)->GetWindowTextW(strStartPos);

	CString strEndPos;
	GetDlgItem(IDC_EDIT_END_POS)->GetWindowTextW(strEndPos);

	clock_t start, finish;
	double duration = 0.;
	start = clock();	

	int iCount = cTool.GetMinWarpCount(_ttoll(strStartPos), _ttoll(strEndPos));

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	CString strTime;
	strTime.Format(_T("%f"), duration);
	GetDlgItem(IDC_EDIT_CALC_TIME)->SetWindowTextW(strTime);

	CString strStepView;

	int iMaxSpeed = cTool.GetMaxSpeed();
	long long llDist = _ttoll(strEndPos) - _ttoll(strStartPos);
	int iExpectancyCount = 0;
	CString strExpectancyCount;

	if (iMaxSpeed * iMaxSpeed == llDist)
		iExpectancyCount = iMaxSpeed + iMaxSpeed - 1;
	else if (iMaxSpeed * (iMaxSpeed + 1) < llDist)
		iExpectancyCount = iMaxSpeed + iMaxSpeed + 1;
	else if (iMaxSpeed * iMaxSpeed < llDist)
		iExpectancyCount = iMaxSpeed + iMaxSpeed;

	strExpectancyCount.Format(_T("%d"), iExpectancyCount);
	GetDlgItem(IDC_EDIT_EXPECTANCY_COUNT)->SetWindowTextW(strExpectancyCount);

	auto Steps = cTool.GetSteps();
	int iLineChange = 0;

	for (auto Step : *Steps)
	{
		CString strTemp;

		strTemp.Format(_T(" %d "), Step);
		strStepView.Append(strTemp);

		if (iLineChange == 25)
		{
			iLineChange = 0;
			strStepView.Append(_T("\r\n"));
		}

		iLineChange++;
	}

	GetDlgItem(IDC_EDIT_STEP_VIEW)->SetWindowTextW(strStepView);

	CString strMaxSpeed;
	strMaxSpeed.Format(_T("%d"), cTool.GetMaxSpeed());
	GetDlgItem(IDC_EDIT_MAX_SPEED)->SetWindowTextW(strMaxSpeed);

	CString strCount;
	strCount.Format(_T("%d"), iCount);
	GetDlgItem(IDC_EDIT_MOVE_COUNT)->SetWindowTextW(strCount);

}


void CMFCApplication2Dlg::OnEnUpdateEditEndPos()
{
	OnBnClickedButtonCalc();
}


void CMFCApplication2Dlg::OnBnClickedButtonDistDown()
{
	CString strEndPos;
	GetDlgItem(IDC_EDIT_END_POS)->GetWindowTextW(strEndPos);

	int iDist = _ttoi(strEndPos);
	strEndPos.Format(_T("%d"), --iDist);

	GetDlgItem(IDC_EDIT_END_POS)->SetWindowTextW(strEndPos);
}


void CMFCApplication2Dlg::OnBnClickedButtonDistUp()
{
	CString strEndPos;
	GetDlgItem(IDC_EDIT_END_POS)->GetWindowTextW(strEndPos);

	int iDist = _ttoi(strEndPos);
	strEndPos.Format(_T("%d"), ++iDist);

	GetDlgItem(IDC_EDIT_END_POS)->SetWindowTextW(strEndPos);
}
