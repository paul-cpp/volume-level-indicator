
// MFCApplication1Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include <cstring>
#include "GetVolume.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGCTRL1, CTRL_PROGRESSBAR_CUSTOM);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()

	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CMFCApplication1Dlg::OnNMCustomdrawProgress1)


END_MESSAGE_MAP()


// ����������� ��������� CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������


	int start_value = GetVolume();
	CTRL_PROGRESSBAR_CUSTOM.put_Value(start_value);




	//************************/*****************************************/*****************************************/*******************************

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �������� ���� ��� ����������� �����������
	*pResult = 0;
}
BEGIN_EVENTSINK_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_EVENT(CMFCApplication1Dlg, IDC_PROGCTRL1, DISPID_CLICK, CMFCApplication1Dlg::ClickProgctrl1, VTS_NONE)
END_EVENTSINK_MAP()


int value = 0;
int offset = 10;

void CMFCApplication1Dlg::ClickProgctrl1()
{
	// TODO: �������� ���� ��� ����������� ���������
	//UpdateData(FALSE);

	value = GetVolume();

	CTRL_PROGRESS1.SetState(value);




	CString str_value;
	str_value.Format(_T("%d"), value);
	CTRL_EDIT1.SetWindowTextW(str_value);
}

void CMFCApplication1Dlg::OnLButtonDown(UINT point)
{

}

void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication1Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	UINT _nChar = VK_VOLUME_UP;
	CDialogEx::OnKeyDown(VK_VOLUME_UP, nRepCnt, nFlags);
}


BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �������� ������������������ ��� ��� ����� �������� ������
	CString str_value;

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_VOLUME_UP)
		{
			int volume = GetVolume();
			str_value.Format(_T("key pressed:\t%d"), volume);
			CTRL_PROGRESSBAR_CUSTOM.put_Value(volume);

		}
		else if (pMsg->wParam == VK_VOLUME_DOWN)
		{
			int volume = GetVolume();
			str_value.Format(_T("key pressed:\t%d"), volume);
			CTRL_PROGRESSBAR_CUSTOM.put_Value(volume);

		}
		else if (pMsg->wParam == VK_VOLUME_MUTE)
		{
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
