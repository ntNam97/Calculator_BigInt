
// QIntGUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QIntGUI.h"
#include "QIntGUIDlg.h"
#include "afxdialogex.h"
#include"File.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQIntGUIDlg dialog



CQIntGUIDlg::CQIntGUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_QINTGUI_DIALOG, pParent)
	, string_input_number_a(_T(""))
	, string_input_number_b(_T(""))
	, CONVERT_FROM(_T(""))
	, CONVERT_TO(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQIntGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, string_input_number_a);
	DDX_Text(pDX, IDC_EDIT1, string_input_number_b);
	DDX_Control(pDX, IDC_COMBO1, combo_box);
	DDX_Control(pDX, IDC_BUTTON1_OK, BTN_OK);
	DDX_Control(pDX, IDC_EDIT3, Solved);

	DDX_Control(pDX, IDC_COMBO2, COMBO_CONVERT_1);
	DDX_Control(pDX, IDC_COMBO3, COMBO_CONVERT_2);
	DDX_Text(pDX, IDC_EDIT4, CONVERT_FROM);
	DDX_Text(pDX, IDC_EDIT5, CONVERT_TO);
	DDX_Control(pDX, IDC_EDIT5, CONVRT_TO);
}

BEGIN_MESSAGE_MAP(CQIntGUIDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_CBN_SELCHANGE(IDC_COMBO1, &CQIntGUIDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT2, &CQIntGUIDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CQIntGUIDlg::OnEnChangeEdit1)

	ON_BN_CLICKED(IDC_BUTTON1_OK, &CQIntGUIDlg::OnBnClickedButton1Ok)

	ON_EN_CHANGE(IDC_EDIT3, &CQIntGUIDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CQIntGUIDlg::OnEnChangeEdit4)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CQIntGUIDlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CQIntGUIDlg::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CQIntGUIDlg::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(IDC_BUTTON3, &CQIntGUIDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CQIntGUIDlg message handlers

BOOL CQIntGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

									//COMBO BOX CHO CÁC PHÉP TÍNH
	combo_box.AddString(_T("Add operator (+)"));//Tạo dữ liệu và khai báo dữ liệu mặc định cho combo box
	combo_box.AddString(_T("Sub operator (-)"));
	combo_box.AddString(_T("Mul operator (*)"));
	combo_box.AddString(_T("Div operator (/)"));
	combo_box.SetCurSel(0);

	//COMBO BOX CHUYỂN ĐỔI 1
	COMBO_CONVERT_1.AddString(_T("Binary"));
	COMBO_CONVERT_1.AddString(_T("Decima"));
	COMBO_CONVERT_1.AddString(_T("Hexadecimal"));
	COMBO_CONVERT_1.SetCurSel(0);

	//COMBO BOX CHUYỂN ĐỔI 2
	COMBO_CONVERT_2.AddString(_T("Binary"));
	COMBO_CONVERT_2.AddString(_T("Decima"));
	COMBO_CONVERT_2.AddString(_T("Hexadecimal"));
	COMBO_CONVERT_2.SetCurSel(0);

	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQIntGUIDlg::OnPaint()
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
HCURSOR CQIntGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CQIntGUIDlg::OnEnChangeEditInput()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CQIntGUIDlg::OnLbnSelchangeList1()
{


	// TODO: Add your control notification handler code here
}


void CQIntGUIDlg::OnCbnSelchangeCombo1()
{

	// TODO: Add your control notification handler code here
}


void CQIntGUIDlg::OnEnChangeEdit2()
{


	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CQIntGUIDlg::OnEnChangeEdit1()
{



	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CQIntGUIDlg::OnBnClickedButton1Ok()//Xử lý BUTTON SOLVED 
{
	UpdateData(TRUE);

	QInt Input_a, Input_b;
	Init(Input_a);
	Init(Input_b);

	CString _a;//CHUỖI ĐẦU VÀO SỐ 1
	CString _b;//CHUỖI ĐẦU VÀO SỐ 2
	string Sol;//CHUỖI KẾT QUẢ

	GetDlgItemText(IDC_EDIT1, _a);// LẤY DỮ LIỆU TỪ IDC_EDIT1 VÀO CString a
	GetDlgItemText(IDC_EDIT2, _b);// LẤY DỮ LIỆU TỪ IDC_EDIT1 VÀO CString b


	if (!_a.IsEmpty())// TRÁNH LỖI KHI KHÔNG CÓ DỮ LIỆU
		StrToQInt((string)(CT2CA)_a, Input_a);// string=(string)(CT2CA)<CString> //CONVERT CString to String

	if (!_b.IsEmpty())
		StrToQInt((string)(CT2CA)_b, Input_b);

	if (combo_box.GetCurSel() == 0)//operator +
		Sol = QIntToString(SumQInt(Input_a, Input_b));

	if (combo_box.GetCurSel() == 1)//operator -
		Sol = QIntToString(SubtractQInt(Input_a, Input_b));

	if (combo_box.GetCurSel() == 2)//operator *
		Sol = QIntToString(MulQInt(Input_a, Input_b));

	if (combo_box.GetCurSel() == 3)//operator /
		Sol = QIntToString(DivQInt(Input_a, Input_b));

	Solved.SetWindowTextW((CA2T)Sol.c_str());// CString=(CA2T)<String>.c_str()
											 // TODO: Add your control notification handler code here
}


void CQIntGUIDlg::OnStnClickedStaticHexA()
{
	// TODO: Add your control notification handler code here
}


void CQIntGUIDlg::OnStnClickedStaticKq()
{

	// TODO: Add your control notification handler code here
}



void CQIntGUIDlg::OnEnChangeEdit3()
{

	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void CQIntGUIDlg::OnEnChangeEdit4()//XỬ LÝ KHI CÓ SỰ THAY ĐỔI Ở EDITTEXT CONVERT INPUT
{

	UpdateData(1);
	QInt X;
	CString From;

	GetDlgItemText(IDC_EDIT4, From);
	if (!From.IsEmpty())
	{
		if (COMBO_CONVERT_1.GetCurSel() == COMBO_CONVERT_2.GetCurSel())// 2 ĐƠN VỊ CHUYỂN ĐỔI GIỐNG NHAU
			CONVRT_TO.SetWindowTextW(From);

		if (COMBO_CONVERT_1.GetCurSel() == 0 && COMBO_CONVERT_2.GetCurSel() == 1)//2->10
		{
			bool *bin = new bool[128];
			string binary_string((CT2CA)From);

			if (binary_string.length() < 128)// NẾU CHUỖI NHỊ PHÂN NHẬP VÀO NHỎ HƠN 128 BIT
				binary_string.insert(0, 128 - binary_string.length(), '0');//THÌ THÊM BIT 0 VÀO ĐẦU CHUỖI

			bin = StringToBool(binary_string, 128);
			X = BinToDec(bin);
			string sol = QIntToString(X);
			CONVRT_TO.SetWindowTextW((CA2T)sol.c_str());
		}
		if (COMBO_CONVERT_1.GetCurSel() == 0 && COMBO_CONVERT_2.GetCurSel() == 2)//2->16
		{
			bool *bin = new bool[128];
			string binary_string((CT2CA)From);

			if (binary_string.length() < 128)
				binary_string.insert(0, 128 - binary_string.length(), '0');


			bin = StringToBool(binary_string, 128);
			string Hex = charArrToString(BinToHex(bin), 32);
			CONVRT_TO.SetWindowTextW((CA2T)Hex.c_str());
		}
		if (COMBO_CONVERT_1.GetCurSel() == 1 && COMBO_CONVERT_2.GetCurSel() == 0)//10->2
		{
			Init(X);
			StrToQInt((string)(CT2CA)From, X);
			bool *bin = new bool[128];

			bin = DecToBin(X);
			CONVRT_TO.SetWindowTextW((CA2T)boolArrToString(bin, 128).c_str());
		}
		if (COMBO_CONVERT_1.GetCurSel() == 1 && COMBO_CONVERT_2.GetCurSel() == 2)//10->16
		{
			Init(X);
			StrToQInt((string)(CT2CA)From, X);
			string Hex;

			Hex = charArrToString(DecToHex(X), 32);
			CONVRT_TO.SetWindowTextW((CA2T)Hex.c_str());
		}
		if (COMBO_CONVERT_1.GetCurSel() == 2 && COMBO_CONVERT_2.GetCurSel() == 0)//16->2
		{
			bool *bin = new bool[128];
			string Hex_string((CT2CA)From);
			if (Hex_string.length() < 32)//NẾU CHUỖI HEX NHẬP VÀO NHỎ HƠN 32
				Hex_string.insert(0, 32 - Hex_string.length(), '0');

			bin = HexToBin(Hex_string);
			CONVRT_TO.SetWindowTextW((CA2T)boolArrToString(bin, 128).c_str());
		}
		if (COMBO_CONVERT_1.GetCurSel() == 2 && COMBO_CONVERT_2.GetCurSel() == 1)//16->10
		{
			string Hex_string((CT2CA)From);
			if (Hex_string.length() < 32)
				Hex_string.insert(0, 32 - Hex_string.length(), '0');
			Init(X);
			X = HexToDec(Hex_string);
			string Dec_string = QIntToString(X);
			CONVRT_TO.SetWindowTextW((CA2T)Dec_string.c_str());
		}
	}

	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CQIntGUIDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CQIntGUIDlg::OnCbnSelchangeCombo3()
{

	CQIntGUIDlg::OnEnChangeEdit4();
	// TODO: Add your control notification handler code here
}


void CQIntGUIDlg::OnCbnSelchangeCombo2()
{

	CQIntGUIDlg::OnEnChangeEdit4();

	// TODO: Add your control notification handler code here
}


void CQIntGUIDlg::OnStnClickedStaticBinA()
{

}


void CQIntGUIDlg::OnEnChangeMfceditbrowse1()
{
	GetDlgItemText(IDC_MFCEDITBROWSE1, PATH_INPUT);
	// TODO: Add your control notification handler code here
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CQIntGUIDlg::OnBnClickedButton3()
{
	fstream check_input;
	string input = CT2CA(PATH_INPUT);
	check_input.open(input, ios::in);
	if(!check_input.is_open())
	{
		MessageBox(_T("Không thể mở file dữ liệu vào!"), _T("Error"), MB_ICONERROR | MB_OK);
	}
		
	else {
		CFileDialog dlg(FALSE, _T("txt"), NULL, OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, _T("All files|*.*||"));
		if (dlg.DoModal() != IDOK)
		{	//the user didn't click OK
			return;
		}
		CString theFileName = dlg.GetPathName();
		string output = CT2CA(theFileName);
		File_Process(input, output);
		MessageBox(_T("Nhập và xuất dữ liệu thành công!"), _T("Notification"), MB_ICONINFORMATION | MB_OK);
	}
	
	// TODO: Add your control notification handler code here

}
