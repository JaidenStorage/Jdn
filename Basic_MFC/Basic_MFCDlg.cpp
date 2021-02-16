
// Basic_MFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Basic_MFC.h"
#include "Basic_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBasicMFCDlg 대화 상자



CBasicMFCDlg::CBasicMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BASIC_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBasicMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBasicMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CBasicMFCDlg 메시지 처리기

BOOL CBasicMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBasicMFCDlg::OnPaint()
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
HCURSOR CBasicMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBasicMFCDlg::_Control()
{
	CButton* m_Control_;
	WINDOWPLACEMENT NowPos;

	// 생성
	m_Control_ = new CButton();
	m_Control_->Create(CString_, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 10, 100, 36), this, int_);
	// 1번인자. 표시 문자열
	// 2번인자. 속성
	// 3번인자. 위치 및 크기
	// 4번인자. 부모윈도우핸들
	// 5번인자. 리소스값
	
	// 이동
	m_Control_->GetWindowPlacement(&NowPos);
	m_Control_->MoveWindow(CRect(NowPos.rcNormalPosition.left + 10, NowPos.rcNormalPosition.top + 30, NowPos.rcNormalPosition.right + 10, NowPos.rcNormalPosition.bottom + 30), TRUE);

	// 사이즈변경
	m_Control_->GetWindowPlacement(&NowPos);
	m_Control_->MoveWindow(CRect(NowPos.rcNormalPosition.left, NowPos.rcNormalPosition.top, NowPos.rcNormalPosition.right + 10, NowPos.rcNormalPosition.bottom + 30), TRUE);

	// 삭제
	delete m_Control_;
}

void CBasicMFCDlg::_Control_Read()
{
	int TextControl_Value;

	// Read
	UpdateData(TRUE);
	int Get_ControlValue = TextControl_Value;
}

void CBasicMFCDlg::_Control_Write()
{
	int TextControl_Value;
	int Set_ControlValue = 0;

	// Write
	TextControl_Value = Set_ControlValue;
	UpdateData(FALSE);
}



void CBasicMFCDlg::_CheckBox()
{
	// 직접접근
	((CButton*)GetDlgItem(RESOURCE_ID));

	// Control변수 추가
	CButton m_Control_CheckBox;
	int_ = m_Control_CheckBox.GetCheck();	// Read
	m_Control_CheckBox.SetCheck(TRUE);	    // Write

}

void CBasicMFCDlg::_EditControl()
{
	// 직접접근
	((CEdit*)GetDlgItem(RESOURCE_ID));
	GetDlgItemText(RESOURCE_ID, CString_);	 // Read
	SetDlgItemText(RESOURCE_ID, CString_);	 // Write

	// Control변수 추가
	CEdit m_Control_EditControl;
	m_Control_EditControl.GetWindowText(CString_);	 // Read
	m_Control_EditControl.SetWindowText(CString_);	 // Write
}

void CBasicMFCDlg::_RadioBox()
{
	// 직접접근
	((CButton*)GetDlgItem(RESOURCE_ID));

	// Control변수 추가
	CButton m_Control_RadioBox;
	bool_ = m_Control_RadioBox.GetCheck();	// Read
	m_Control_RadioBox.SetCheck(TRUE);		// Write
}

void CBasicMFCDlg::_StaticText()
{
	// 직접접근
	((CStatic*)GetDlgItem(RESOURCE_ID));
	GetDlgItemText(RESOURCE_ID, CString_);	 // Read
	SetDlgItemText(RESOURCE_ID, CString_);	 // Write

	// Control변수 추가
	CStatic m_Control_StaticText;
	m_Control_StaticText.GetWindowText(CString_);	 // Read
	m_Control_StaticText.SetWindowText(CString_);	 // Write
}

void CBasicMFCDlg::_ComboBox()
{
	// 직접접근
	((CComboBox*)GetDlgItem(RESOURCE_ID));

	// Control변수 추가
	CComboBox m_Control_ComboBox;
	int_ = m_Control_ComboBox.GetCurSel();        // Index 가져오기
	m_Control_ComboBox.SetCurSel(int_);	          // 선택
	m_Control_ComboBox.GetLBText(int_, CString_); // 문자열 가져오기
	m_Control_ComboBox.AddString(CString_);       // 항목추가
	m_Control_ComboBox.DeleteString(int_);        // 항목삭제
	m_Control_ComboBox.Clear();                   // 선택해제

}

void CBasicMFCDlg::_ListBox()
{
	// 직접접근
	((CListBox*)GetDlgItem(RESOURCE_ID));

	// Control변수 추가
	CListBox m_Control_ListBox;
	int_ = m_Control_ListBox.GetCurSel();          // 선택 셀 값 가져오기
	m_Control_ListBox.SetCurSel(int_);             // 셀 선택
	m_Control_ListBox.AddString(CString_);         // 문자열 삽입
	m_Control_ListBox.GetText(int_, CString_);     // Index 텍스트 가져오기 
	int_ = m_Control_ListBox.GetCount();           // 총 항목 갯수
	m_Control_ListBox.DeleteString(int_);          // 해당항목 삭제
	m_Control_ListBox.ResetContent();              // 전체삭제

}

void CBasicMFCDlg::_ScrollBar()
{
	int int_Max = 0, int_Min = 0;

	// 직접접근
	((CScrollBar*)GetDlgItem(RESOURCE_ID));

	// Control변수 추가
	CScrollBar m_Control_ScrollBar;
	int_ = m_Control_ScrollBar.GetScrollPos();                            // 스크롤 위치 가져오기
	m_Control_ScrollBar.SetScrollPos(int_);                               // 스크롤 움직이기
	m_Control_ScrollBar.SetScrollRange(int_Min, int_Max, TRUE);           // 스크롤 범위지정
	m_Control_ScrollBar.GetScrollRange((LPINT)int_Min, (LPINT)int_Max);   // 스크롤 범위값 가져오기
}

void CBasicMFCDlg::_Slider()
{
	int int_Max = 0, int_Min = 0;

	// 직접접근
	((CSliderCtrl*)GetDlgItem(RESOURCE_ID));

	// Control변수
	CSliderCtrl m_Control_Slider;
	int_ = m_Control_Slider.GetPos();						 // 스크롤 위치 가져오기
	m_Control_Slider.SetPos(int_);							 // 스크롤 움직이기
	m_Control_Slider.SetRange(int_Min, int_Max, TRUE);		 // 스크롤 범위지정
	m_Control_Slider.GetRange(int_Min, int_Max);			 // 스크롤 범위값 가져오기
}

void CBasicMFCDlg::_Tab()
{
	// 1. Tab Control 생성

	// 2-1. Tab Control control변수 생성
	CTabCtrl m_Control_Tab;
	// 2-2. Tab Control Tab 추가
	m_Control_Tab.InsertItem(int_, CString_, 0);

	// 3-1. Tab에 띄울 Dialog 제작 : Border-Thin, Style-Child, SystemMenu-False, TitleBar-False 로 설정
	// 3-2. Dialog의 Class생성 : 기본클래스-CDialog
	class CTAB1 : public CDialog {};
	class CTAB2 : public CDialog {};

	// 4-1. 메인.h에 3-2에서 생성된 헤더(*.h)파일 연결  [ #include "TAB.h" ]
	// 4-2. class변수 선언
	CTAB1 mCTAB1;
	CTAB2 mCTAB2;

	// 5. 공용 핸들러 선언
	CWnd* m_Wndshow;

	// 6. Tab Control의 Rect 가져오기
	CRect Rect;
	m_Control_Tab.GetClientRect(&Rect);

	// 7-1. 기본 탭 Dialog 출력
	mCTAB1.Create(RESOURCE_ID, &m_Control_Tab);
	mCTAB1.SetWindowPos(NULL, 5, 25, Rect.Width() - 10, Rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);
	m_Wndshow = &mCTAB1;

	// 7-2. 추가 탭 Dialog 생성
	mCTAB2.Create(RESOURCE_ID, &m_Control_Tab);
	mCTAB2.SetWindowPos(NULL, 5, 25, Rect.Width() - 10, Rect.Height() - 30, SWP_NOZORDER);
	m_Wndshow = &mCTAB2;

	// 8. TCN_SELCHANGE 이벤트 생성하여 클릭이벤트 생성
	if (m_Wndshow != NULL) {
		m_Wndshow->ShowWindow(SW_HIDE);
		m_Wndshow = NULL;
	}

	int tabIndex = m_Control_Tab.GetCurSel();

	switch (tabIndex) {
	case 0:
		mCTAB1.ShowWindow(SW_SHOW);
		m_Wndshow = &mCTAB1;
		break;

	case 1:
		mCTAB2.ShowWindow(SW_SHOW);
		m_Wndshow = &mCTAB2;
		break;
	}
}

void CBasicMFCDlg::_Progressbar()
{
	int int_Max = 0, int_Min = 0;

	CProgressCtrl m_Control_Progress;
	m_Control_Progress.SetRange(int_Min, int_Max);	   // 프로그래스 범위 지정
	m_Control_Progress.GetRange(int_Min, int_Max);	   // 프로그래스 범위 가져오기
	int_ = m_Control_Progress.GetPos();				   // 프로그래스 현재값 가져오기
	m_Control_Progress.SetPos(int_);				   // 프로그래스 현재값 설정하기
	m_Control_Progress.SetStep(int_);				   // 프로그래스 증가할 스텝 지정하기
	m_Control_Progress.StepIt();                       // 프로그래스 SetStep만큼 증가

}

void CBasicMFCDlg::_ListControl()
{
	int Column_ = 0, Row_ = 0;
	CRect Size_;

	CListCtrl m_control_ListControl;

	// 열의 크기를 정하기위한 ListControl의 사이즈 획득하기

	// ListControl 스타일
	m_control_ListControl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_TRANSPARENTBKGND);

	// ListControl 열 항목 추가하기
	m_control_ListControl.GetWindowRect(&Size_);
	m_control_ListControl.InsertColumn(Column_, CString_, LVCFMT_CENTER, Size_.Width() / Column_);  // ListControl 열 title 추가, 사이즈지정
	m_control_ListControl.InsertItem(Row_, CString_);	          // ListControl 행 title 추가
	m_control_ListControl.SetItemText(Row_, Column_, CString_);   // ListControl 값 입력
}


