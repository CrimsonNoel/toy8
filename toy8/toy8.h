
// toy8.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Ctoy8App:
// �� Ŭ������ ������ ���ؼ��� toy8.cpp�� �����Ͻʽÿ�.
//

class Ctoy8App : public CWinApp
{
public:
	Ctoy8App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Ctoy8App theApp;