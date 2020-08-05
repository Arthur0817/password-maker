
// passwordmakerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include<time.h>
#define random(x) (rand()%x)

const wchar_t number[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };//10
const wchar_t sign[] = { '!', '@', '#', '$', '%', '^', '&', '(', ')', '_', '+', '-', '=', '?' };//14
const wchar_t up[] = { 'A','B','C' ,'D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z' };//26
const wchar_t down[] = { 'a','b','c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z' };//26


// CpasswordmakerDlg 对话框
class CpasswordmakerDlg : public CDialogEx
{
// 构造
public:
	CpasswordmakerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASSWORDMAKER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck1();

protected:
	void InitDataArr();
	void InitCombo();
	int GetARandomNum();

private:
	bool num_{ false };
	bool sign_{ false };
	bool letter_up_{ false };
	bool letter_down_{ false };
	wchar_t* target_arr_{ nullptr };
	int arr_num_{ 0 };
public:
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	CComboBox combo_;
//	CString edit_value;
	CEdit edit_ctrl;
};
