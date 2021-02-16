
// Basic_MFCDlg.h: 헤더 파일
#include <string>
//

#pragma once
#define RESOURCE_ID 0

// CBasicMFCDlg 대화 상자
class CBasicMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CBasicMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BASIC_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


	std::string string_;
	std::wstring wstring_;
	CString CString_;
	char char_;
	int int_;
	float float_;
	bool bool_;


	void _Control();		// Control
	void _Control_Read();		// Control 읽기
	void _Control_Write();		// Control 쓰기


	void _CheckBox();
	void _EditControl();
	void _RadioBox();
	void _StaticText();
	void _ComboBox();
	void _ListBox();
	void _ScrollBar();
	void _Slider();
	void _Tab();
	void _Progressbar();
	void _ListControl();


};
