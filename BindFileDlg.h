/////////////////////////////////////////////////////////////////////////////
// 类名：CBindFileDlg
// 功能：进行可执行文件的绑定工作。
// 作者：徐景周(Johnny Xu, xujingzhou2016@gmail.com)
// 组织：未来工作室(Future Studio)
// 日期：2001.12.1
////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_BINDFILEDLG_H__763C7F30_CE97_4F40_9D80_6A2EF0EB234A__INCLUDED_)
#define AFX_BINDFILEDLG_H__763C7F30_CE97_4F40_9D80_6A2EF0EB234A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SYS/TYPES.H" //加入类型定义头文件
#include "sys/stat.h"  //加入状态显示头文件
#include "StaticFilespec.h" //扩展静态框类
#include "WBButton.h" //位图按钮类
#include "GradientProgressCtrl.h" //渐变色进度条类

#pragma pack(1)

typedef struct ICONRESDIR { 
   BYTE Width; 
   BYTE Height; 
   BYTE ColorCount; 
   BYTE reserved; 
} ICONRESDIR;  //图标结构

typedef struct tagRESDIR { 
   ICONRESDIR   Icon; 
   WORD    Planes; 
   WORD    BitCount; 
   DWORD   BytesInRes; 
   WORD  IconCursorId; 
} RESDIR; 

typedef struct NEWHEADER { 
   WORD Reserved; 
   WORD ResType; 
   WORD ResCount; 
} NEWHEADER, *PNEWHEADER; 

typedef struct {
     const RESDIR* pcResDir;
     BYTE* pMatchIcon;
} my_enum_res_callback_data;

class CBindFileDlg : public CDialog
{
// Construction
public:
	CBindFileDlg(CWnd* pParent = NULL);	// standard constructor

public:
	_off_t prog1_length ;
   	TCHAR my_name[MAX_PATH];
    CString his_name;
    BYTE *buf ;
	CString strFirstFilePath;     //保存第一个要绑定的文件名
	CString strSecondFilePath;    //保存第二个要绑定的文件名
	CString strFinalFilePath;     //保存最终合成文件名

	void Create_Process(const char* temp_exe, BOOL async);//创建分解文件时的进程
	void Unbind_and_Run(); //分解已合并的文件，同时运行它们
    bool Bind_Files(); //将二个可执行文件绑定在一起
    BYTE* find_match_icon(const RESDIR* pcResDir); //查询匹配图标
	void list_my_icons(); //列出所有图标

// Dialog Data
	//{{AFX_DATA(CBindFileDlg)
	enum { IDD = IDD_BINDFILE_DIALOG };
	CGradientProgressCtrl	m_Progress;  //改为渐变色进度条显示
	CWBButton	m_Cancel;                //改为位图按钮显示
	CWBButton	m_SecondBrowse;          //改为位图按钮显示
	CWBButton	m_FirstBrowse;           //改为位图按钮显示
	CWBButton	m_FinalBrowse;           //改为位图按钮显示
	CWBButton	m_BindFile;              //改为位图按钮显示
	CWBButton	m_About;                 //改为位图按钮显示
	CStaticFilespec	m_SecondPath;        //改为扩展编辑框显示
	CStaticFilespec	m_FirstPath;         //改为扩展编辑框显示
	CStaticFilespec	m_FinalPath;         //改为扩展编辑框显示
	CString	m_strFirstPath;              //第一个要绑定的文件
	CString	m_strSecondPath;             //第二个要绑定的文件
	CString	m_strFinalPath;              //最终合成的文件名
	CString	m_Parts;
	int		m_Sync;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBindFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBindFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAbout();
	afx_msg void OnFirstBrowse();
	afx_msg void OnSecondBrowse();
	afx_msg void OnFinalBrowse();
	afx_msg void OnButtonBindFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINDFILEDLG_H__763C7F30_CE97_4F40_9D80_6A2EF0EB234A__INCLUDED_)
