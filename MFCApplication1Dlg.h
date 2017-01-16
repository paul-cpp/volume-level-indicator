
// MFCApplication1Dlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "progctrl1.h"



// ���������� ���� CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// ��������
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);

	CProgressCtrl CTRL_PROGRESS1;
	CProgctrl1 CTRL_PROGRESSBAR_CUSTOM;
	DECLARE_EVENTSINK_MAP()
	void ClickProgctrl1();
	CEdit CTRL_EDIT1;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

