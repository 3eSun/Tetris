// teluosiView.cpp : implementation of the CTeluosiView class
//

#include "stdafx.h"
#include "teluosi.h"

#include "teluosiDoc.h"
#include "teluosiView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeluosiView

IMPLEMENT_DYNCREATE(CTeluosiView, CView)

BEGIN_MESSAGE_MAP(CTeluosiView, CView)
	//{{AFX_MSG_MAP(CTeluosiView)
	ON_COMMAND(ID_MENU_START, OnMenuStart)
	ON_COMMAND(ID_MENU_PAUSE, OnMenuPause)
	ON_UPDATE_COMMAND_UI(ID_MENU_PAUSE, OnUpdateMenuPause)
	ON_COMMAND(ID_VIEW_1, OnView1)
	ON_COMMAND(ID_VIEW_2, OnView2)
	ON_UPDATE_COMMAND_UI(ID_VIEW_1, OnUpdateView1)
	ON_UPDATE_COMMAND_UI(ID_VIEW_2, OnUpdateView2)
	ON_COMMAND(ID_MENU_DSTART, OnMenuDstart)
	ON_COMMAND(ID_MENU_TSTART, OnMenuTstart)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeluosiView construction/destruction

CTeluosiView::CTeluosiView()
{
	// TODO: add construction code here

	fenmian.LoadBitmap(IDB_BITMAP1);
	for(int i = 0; i < 4; i++)
		xuanze[i].LoadBitmap(IDB_BITMAP7 + i);
	start = false;
	m_bPause = false;
	view = 1;
	player = 1;
	ixuanze = 1;
}

CTeluosiView::~CTeluosiView()
{
}

BOOL CTeluosiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTeluosiView drawing

void CTeluosiView::OnDraw(CDC* pDC)
{
	//窗口在中间
	//AfxGetMainWnd()->CenterWindow();
	CTeluosiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC Dc;
	if( Dc.CreateCompatibleDC(pDC) == false )
		AfxMessageBox("Can't create DC");
	//发送消息
	///////////////////////////////////////////////
	/*if( player == 4 )
	{
		CMainFrame * pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
		char msg[10000];
		strcpy(msg, "");
		int i, j;

		if( pFrame->ynserver == 1 )
		{
			for(i = 0; i < 4; i++)
				for(j = 0; j < 4; j++)
				{
					if( russia2.Will[i][j] == 0 )
						strcat(msg, "0");
					else
						strcat(msg, "1");
				}
			for(i = 0; i < russia2.m_RowCount; i++)
				for(j = 0; j < russia2.m_ColCount; j++)
				{
					if( russia2.Russia[i][j] == 0 )
						strcat(msg, "0");
					else
						strcat(msg, "1");
				}
			char mm[1];
			itoa(russia2.m_Level, mm, 10);
			strcat(msg, mm);
			itoa(russia2.m_Speed, mm, 10);
			strcat(msg, mm);
			char mmm[5];
			itoa(russia2.m_Score, mmm, 10);
			strcat(msg, mmm);

			char pMsg[10000];
			sprintf(pMsg, "%s", msg);
			CTeluosiApp *App = (CTeluosiApp *)AfxGetApp();
			if(App->pRequestSave != NULL)
				pFrame->SendMsg(App->pRequestSave, pMsg);
		}
		if( pFrame->ynserver == 2 )
			if( pFrame->m_pSocket )
			{
				for(i = 0; i < 4; i++)
					for(j = 0; j < 4; j++)
					{
						if( russia.Will[i][j] == 0 )
							strcat(msg, "0");
						else
							strcat(msg, "1");
					}
				for(i = 0; i < russia.m_RowCount; i++)
					for(j = 0; j < russia.m_ColCount; j++)
					{
						if( russia.Russia[i][j] == 0 )
							strcat(msg, "0");
						else
							strcat(msg, "1");
					}
				char mm[1];
				itoa(russia.m_Level, mm, 10);
				strcat(msg, mm);
				itoa(russia.m_Speed, mm, 10);
				strcat(msg, mm);
				char mmm[5];
				itoa(russia.m_Score, mmm, 10);
				strcat(msg, mmm);

				char pMsg[10000];
				sprintf(pMsg, "%s", msg);
				CTeluosiApp *App = (CTeluosiApp *)AfxGetApp();
				//if(App->pRequestSave != NULL)
				pFrame->SendMsg(App->pRequestSave, pMsg);
			}
		/////////////////////////////////////////////////
		//接收消息
		CTeluosiApp *App = (CTeluosiApp *)AfxGetApp();
		//char msg[10000];
		strcpy(msg, App->str);
		int k = 0;
		char m[1];
		if( (pFrame->ynserver == 1) && (App->pRequestSave != NULL) )
		{
			for(i = 0; i < 4; i++)
				for(j = 0; j < 4; j++)
				{
					m[0] = msg[k];
					int a = atoi(m);
					if( a == 0 )
					{
						russia.Will[i][j] = 0;
						k++;
					}
					else
					{
						russia.Will[i][j] = 1;
						k++;
					}
				}
			for(i = 0; i < 18; i++)	//russia.m_RowCount
				for(j = 0; j < 12; j++)	//russia.m_ColCount
				{
					m[0] = msg[k];
					int a = atoi(m);
					if( a == 0 )
					{
						russia.Will[i][j] = 0;
						k++;
					}
					else
					{
						russia.Will[i][j] = 1;
						k++;
					}
				}
			m[0] = msg[k];
			int a = atoi(m);
			russia.m_Level = a;
			k++;
			m[0] = msg[k];
			a = atoi(m);
			russia.m_Speed = a;
			k++;
			m[0] = msg[k];
			a = atoi(m);
			russia.m_Score = a;
		}
		if( pFrame->ynserver == 2 )
		{
			k = 0;
			for(i = 0; i < 4; i++)
				for(j = 0; j < 4; j++)
				{
					m[0] = msg[k];
					int a = atoi(m);
					if( a == 0 )
					{
						russia2.Will[i][j] = 0;
						k++;
					}
					else
					{
						russia2.Will[i][j] = 1;
						k++;
					}
				}
			for(i = 0; i < 18; i++)	//russia.m_RowCount
				for(j = 0; j < 12; j++)	//russia.m_ColCount
				{
					m[0] = msg[k];
					int a = atoi(m);
					if( a == 0 )
					{
						russia2.Will[i][j] = 0;
						k++;
					}
					else
					{
						russia2.Will[i][j] = 1;
						k++;
					}
				}
			m[0] = msg[k];
			int a = atoi(m);
			russia2.m_Level = a;
			k++;
			m[0] = msg[k];
			a = atoi(m);
			russia2.m_Speed = a;
			k++;
			m[0] = msg[k];
			a = atoi(m);
			russia2.m_Score = a;
		}
	}*/
	//没有开始，显示封面
	if( !start )
	{
		Dc.SelectObject(fenmian);
		pDC->BitBlt(0, 0, 500, 550, &Dc, 0, 0, SRCCOPY);
		//显示选择位图
		Dc.SelectObject(xuanze[ixuanze - 1]);
		pDC->BitBlt(200, 350, 150, 150, &Dc, 0, 0, SRCCOPY);
	}
	//显示背景
	else
	{
		if( view == 1 )
		{
			if( player == 1 )
				russia.DrawJiemian1(0, 0, pDC);
			if( player == 2 || player == 4 )
			{
				russia.DrawJiemian1(600, 0, pDC);
				russia2.DrawJiemian1(0, 0, pDC);
			}
		}
		if( view == 2 )
		{
			if( player == 1 )
				russia.DrawJiemian2(0, 0, pDC);
			if( player == 2 || player == 4 )
			{
				russia.DrawJiemian2(253, 0, pDC);
				russia2.DrawJiemian2(0, 0, pDC);
			}
		}
		//if( player == 3 )
		//	russia0.DrawJiemian(pDC);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTeluosiView printing

BOOL CTeluosiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTeluosiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTeluosiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTeluosiView diagnostics

#ifdef _DEBUG
void CTeluosiView::AssertValid() const
{
	CView::AssertValid();
}

void CTeluosiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTeluosiDoc* CTeluosiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTeluosiDoc)));
	return (CTeluosiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeluosiView message handlers

void CTeluosiView::OnMenuStart() 
{
	// TODO: Add your command handler code here
	//先改变框架大小
	if( view == 1 )
		AfxGetMainWnd()->SetWindowPos(NULL, 0, 0, 500, 650, SWP_NOMOVE|SWP_NOZORDER);
	if( view == 2 )
		AfxGetMainWnd()->SetWindowPos(NULL, 0, 0, 260, 570, SWP_NOMOVE|SWP_NOZORDER);
	player = 1;
	start = true;
	russia.Start();
	SetTimer(1, 50*(11 - russia.m_Speed), NULL);
}




void CTeluosiView::OnMenuPause() 
{
	// TODO: Add your command handler code here
	m_bPause = !m_bPause;
	if(m_bPause)
		KillTimer(1);
	else
	{
		SetTimer(1, 50*(11 - russia.m_Speed), NULL);
		if( player == 4 )
		{
			if( net == 1 )
				SetTimer(1, 50*(11 - russia2.m_Speed), NULL);
			else
				SetTimer(1, 50*(11 - russia.m_Speed), NULL);
		}
	}
}

void CTeluosiView::OnUpdateMenuPause(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	//是否显示勾选
	pCmdUI->SetCheck(m_bPause);
}

void CTeluosiView::OnView1() 
{
	// TODO: Add your command handler code here
	if( player == 3 )
		return;
	view = 1;
	//调整窗口大小
	if( player == 1 )
		AfxGetMainWnd()->SetWindowPos(NULL, 0, 0, 500, 590, SWP_NOMOVE | SWP_NOZORDER);
	if( (player == 2) || (player == 4) )
		AfxGetMainWnd()->SetWindowPos(NULL, 0, 0, 1000, 590, SWP_NOMOVE | SWP_NOZORDER);
}

void CTeluosiView::OnView2() 
{
	// TODO: Add your command handler code here
	if( player == 3 )
		return;
	view = 2;
	if( !start )
		return;
	//调整窗口大小
	if( player == 1 )
		AfxGetMainWnd()->SetWindowPos(NULL, 0, 0, 253, 510, SWP_NOMOVE | SWP_NOZORDER);
	if( (player == 2) || (player == 4) )
		AfxGetMainWnd()->SetWindowPos(NULL, 0, 0, 510, 510, SWP_NOMOVE | SWP_NOZORDER);
}

void CTeluosiView::OnUpdateView1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(view == 1);
}

void CTeluosiView::OnUpdateView2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(view == 2);
}

void CTeluosiView::OnMenuDstart() 
{
	// TODO: Add your command handler code here
	if( view == 1 )
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,1000,590,SWP_NOMOVE|SWP_NOZORDER );
	if( view == 2 )
		AfxGetMainWnd() ->SetWindowPos(NULL,0,0,510,510,SWP_NOMOVE|SWP_NOZORDER );
	//player赋值为2
	player = 2;
	start = true;
	//开始第一人
	russia.Start();
	//时间间隔
	Sleep(300);
	//开始第二人
	russia2.Start();
	SetTimer(1,50*(11-russia.m_Speed ),NULL); 
}

void CTeluosiView::OnMenuTstart() 
{
	// TODO: Add your command handler code here
	
}

void CTeluosiView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	//没有开始
	if( !start )
	{
		//部分重画
		CRect rect;
		rect.left = 170;
		rect.top = 330;
		rect.right = 340;
		rect.bottom = 500;
		//按下键，ixuanze循环增加
		if( nChar == VK_DOWN )
		{
			if( ixuanze < 4 )
				ixuanze++;
			else
				ixuanze = 1;
			InvalidateRect(&rect);
		}
		//按下键，ixuanze循环减少
		if( nChar == VK_UP )
		{
			if( ixuanze > 1 )
				ixuanze--;
			else
				ixuanze = 4;
			InvalidateRect(&rect);
		}
		if( nChar == VK_SPACE )
		{
			if( ixuanze == 1 )
				OnMenuStart();
			if( ixuanze == 2 )
				OnMenuDstart();
			if( ixuanze == 3 )
				OnMenuTstart();
			//if( ixuanze == 4 )
				//OnNet();
		}
		return;
	}
	//暂停
	if( m_bPause == true )
		return;
	switch(nChar)
	{
	case VK_LEFT:
		russia.Move(1);	//russia0.Move(5);
		break;
	case VK_RIGHT:
		russia.Move(2);	//russia0.Move(6);
		break;
	case VK_UP:
		russia.Move(4);	//russia0.Move(8);
		break;
	case VK_DOWN:
		russia.Move(3);	//russia0.Move(7);
		break;
	case 65:
		russia2.Move(1);	//russia0.Move(1);
		break;
	case 68:
		russia2.Move(2);	//russia0.Move(2);
		break;
	case 87:
		russia2.Move(4);	//russia0.Move(4);
		break;
	case 83:
		russia2.Move(3);	//russia0.Move(3);
		break;
	}
	OnDraw(GetDC());
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTeluosiView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//下移
	if( player == 1 )
		russia.Move(3);
	if( player == 2 )
	{
		russia.Move(3);
		russia2.Move(3);
	}
	OnDraw(GetDC());
	CView::OnTimer(nIDEvent);
}

void CTeluosiView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//如果开始，退出
	if(start)
		return;
	//部分重画
	CRect rect;
	rect.left=170;
	rect.top=330;
	rect.right=340; 
	rect.bottom=580;
	//point.x和point.y是判断指针是否在菜单上面
	if( point.x > 200 && point.x < 350 )
	{
		if( point.y > 350 && point.y < 390 )
		{
			//如果选择菜单不同，改变，重画
			if( ixuanze != 1 )
			{
				ixuanze = 1;
				InvalidateRect(&rect);
			}
		}
		if( point.y > 390 && point.y < 430 )
			if( ixuanze != 2 )
			{
				ixuanze = 2;
				InvalidateRect(&rect);
			}
		if( point.y > 430 && point.y < 470 )
			if( ixuanze != 3 )
			{
				ixuanze = 3;
				InvalidateRect(&rect);
			}
		if( point.y > 470 && point.y < 510 )
			if( ixuanze != 4 )
			{
				ixuanze = 4;
				InvalidateRect(&rect);
			}
	}
	CView::OnMouseMove(nFlags, point);
}

void CTeluosiView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//判断是否在菜单位图上
	if(point.x > 200 && point.x < 340 && point.y > 350 && point.y < 450)
	{
		//判断菜单参数，开始相应游戏
		if(ixuanze==1)
			OnMenuStart();
		if(ixuanze==2)
			OnMenuDstart();
		if(ixuanze==3)
			OnMenuTstart();
	}
	CView::OnLButtonDown(nFlags, point);
}
