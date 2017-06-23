////////////////////////////////////////////////////////////////////////////
// 类名：CBindFileApp
// 功能：进行程序初始化工作。
// 作者：徐景周(Johnny Xu, xujingzhou2016@gmail.com)
// 组织：未来工作室(Future Studio)
// 日期：2001.12.1
////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_BINDFILE_H__4F42214F_FD09_493E_AF33_242D3D90EE1B__INCLUDED_)
#define AFX_BINDFILE_H__4F42214F_FD09_493E_AF33_242D3D90EE1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

class CBindFileApp : public CWinApp
{
public:
	CBindFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBindFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBindFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINDFILE_H__4F42214F_FD09_493E_AF33_242D3D90EE1B__INCLUDED_)
