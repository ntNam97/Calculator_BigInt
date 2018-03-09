
// QIntGUIDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CQIntGUIDlg dialog
class CQIntGUIDlg : public CDialogEx
{
// Construction
public:
	CQIntGUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QINTGUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString string_input_number_a;
public:
	afx_msg void OnEnChangeEditInput();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox combo_box;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	CString string_input_number_b;
	CButton BTN_OK;
	afx_msg void OnBnClickedButton1Ok();
	CStatic hex_a;
	CStatic hex_b;
	afx_msg void OnStnClickedStaticHexA();
	CStatic IDC_KQ;
	afx_msg void OnStnClickedStaticKq();
	CStatic bin_a;
	CStatic bin_b;
	CEdit Solved;
	afx_msg void OnEnChangeEdit3();
	CStatic bin_c;
	CStatic hex_c;
	
	CComboBox COMBO_CONVERT_1;
	CComboBox COMBO_CONVERT_2;
	CString CONVERT_FROM;
	CString CONVERT_TO;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton1();
	CEdit CONVRT_TO;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnStnClickedStaticBinA();
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnBnClickedButton3();
	CString PATH_INPUT;
};
