
// passwordmakerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "passwordmaker.h"
#include "passwordmakerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpasswordmakerDlg �Ի���



CpasswordmakerDlg::CpasswordmakerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PASSWORDMAKER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpasswordmakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combo_);
	//  DDX_Text(pDX, IDC_EDIT1, edit_value);
	DDX_Control(pDX, IDC_EDIT1, edit_ctrl);
}

BEGIN_MESSAGE_MAP(CpasswordmakerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CpasswordmakerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &CpasswordmakerDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CpasswordmakerDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CpasswordmakerDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CpasswordmakerDlg::OnBnClickedCheck4)
END_MESSAGE_MAP()


// CpasswordmakerDlg ��Ϣ�������

BOOL CpasswordmakerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	InitCombo();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CpasswordmakerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CpasswordmakerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CpasswordmakerDlg::OnBnClickedOk()
{
	InitDataArr();

	CString strCBText;
	combo_.GetWindowTextW(strCBText);
	//char *str = new char[strCBText.GetLength() + 1];
	//size_t converted = 0;
	//wcstombs_s(&converted, str, wcslen(strCBText.GetBuffer(strCBText.GetLength())) + 1, strCBText.GetBuffer(strCBText.GetLength()), _TRUNCATE);
	int len = _wtoi(strCBText.GetBuffer());
	if (0 >= len || 0 >= arr_num_)
	{
		MessageBox(_T("length or type is illegal!!!"));
		return;
	}


	CString edit_value;
	srand((int)time(0));
	for (int i = 0; i < len;)
	{
		int pos = GetARandomNum();
		if (pos >= arr_num_ || 0 > pos) continue;
		else
		{
			wchar_t tmp = target_arr_[pos];
			edit_value.AppendChar(tmp);
			++i;
		}
	}

	edit_ctrl.SetWindowText(edit_value);
}

void CpasswordmakerDlg::InitDataArr()
{
	arr_num_ = 0;

	//����
	if (target_arr_)
	{
		delete target_arr_;
		target_arr_ = nullptr;
	}


	if (num_) arr_num_ += sizeof(number) / sizeof(wchar_t);
	if (sign_) arr_num_ += sizeof(sign) / sizeof(wchar_t);
	if (letter_up_) arr_num_ += sizeof(up) / sizeof(wchar_t);
	if (letter_down_) arr_num_ += sizeof(down) / sizeof(wchar_t);

	target_arr_ = new wchar_t[arr_num_];
	memset(target_arr_, 0, arr_num_ * sizeof(wchar_t));
	int pos = 0;
	if (num_)
	{
		for (int i = 0; i < sizeof(number) / sizeof(wchar_t); ++i)
		{
			target_arr_[pos++] = number[i];
		}
	}

	if (sign_)
	{
		for (int i = 0; i < sizeof(sign) / sizeof(wchar_t); ++i)
		{
			target_arr_[pos++] = sign[i];
		}
	}

	if (letter_up_)
	{
		for (int i = 0; i < sizeof(up) / sizeof(wchar_t); ++i)
		{
			target_arr_[pos++] = up[i];
		}
	}

	if (letter_down_)
	{
		for (int i = 0; i < sizeof(down) / sizeof(wchar_t); ++i)
		{
			target_arr_[pos++] = down[i];
		}
	}
}


void CpasswordmakerDlg::InitCombo()
{
	combo_.Clear();

	for (int i = 4; i <= 18; ++i)
	{
		CString str;
		str.Format(_T("%d"), i);
		combo_.InsertString(i - 4, str);
	}
}


void CpasswordmakerDlg::OnBnClickedCheck1()
{
	num_ = num_ == false ? true : false;
}


void CpasswordmakerDlg::OnBnClickedCheck2()
{
	sign_ = sign_ == false ? true : false;
}


void CpasswordmakerDlg::OnBnClickedCheck3()
{
	letter_up_ = letter_up_ == false ? true : false;
}


void CpasswordmakerDlg::OnBnClickedCheck4()
{
	letter_down_ = letter_down_ == false ? true : false;
}

int CpasswordmakerDlg::GetARandomNum()
{
	return random(arr_num_ - 1);
}