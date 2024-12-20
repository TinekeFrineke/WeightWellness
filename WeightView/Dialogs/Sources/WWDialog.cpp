// WWDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WWDialog.h"

#include "MyTabControl.h"
#include "ItemsPage.h"
#include "PersonaliaDialog.h"
#include "ReceptenPage.h"
#include "DiaryPage.h"


// CAboutDlg dialog used for App About

class CAboutDlg: public CDialog
{
public:
    CAboutDlg();

    // Dialog Data
    enum { IDD = IDD_ABOUTBOX };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CWWDialog dialog



CWWDialog::CWWDialog(weight::Model& aModel, CWnd* pParent /*=NULL*/)
    : CDialog(CWWDialog::IDD, pParent)
    , mTabControl(std::make_unique<CTabControl>())
    , mModel(aModel)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CWWDialog::~CWWDialog() = default;

void CWWDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //DDX_Control(pDX, IDC_TAB1, mTabControl);
    DDX_Control(pDX, IDC_TAB1, mTabControl);
}

BEGIN_MESSAGE_MAP(CWWDialog, CDialog)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //}}AFX_MSG_MAP
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CWWDialog message handlers

BOOL CWWDialog::OnInitDialog()
{
    mTabControl.AddPage(std::make_unique<CPersonaliaDialog>(mModel, this), IDD_PERSONALIA_PAGE, _T("Personalia"));
    mTabControl.AddPage(std::make_unique<CDiaryPage>(mModel, this), IDD_DIARY_PAGE, _T("Dagboek"));
    mTabControl.AddPage(std::make_unique<CItemsPage>(mModel, this), IDD_ITEMS_PAGE, _T("Items"));
    mTabControl.AddPage(std::make_unique<ReceptenPage>(mModel, this), IDD_RECEPTEN_PAGE, _T("Recepten"));

    CDialog::OnInitDialog();

    // Add "About..." menu item to system menu.

    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        CString strAboutMenu;
        strAboutMenu.LoadString(IDS_ABOUTBOX);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    mTabControl.Initialize();
    mTabControl.SelectPage(1);

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWWDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialog::OnSysCommand(nID, lParam);
    }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWWDialog::OnPaint()
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
        CDialog::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWWDialog::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CWWDialog::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;
    *pResult = 0;
}
