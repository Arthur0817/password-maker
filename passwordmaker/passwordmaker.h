
// passwordmaker.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CpasswordmakerApp: 
// �йش����ʵ�֣������ passwordmaker.cpp
//

class CpasswordmakerApp : public CWinApp
{
public:
	CpasswordmakerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CpasswordmakerApp theApp;