// CardGameView.cpp : CCardGameView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "CardGame.h"

#include "CardGameDoc.h"
#include "CardGameView.h"
#include <time.h> 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardGameView

IMPLEMENT_DYNCREATE(CCardGameView, CView)

BEGIN_MESSAGE_MAP(CCardGameView, CView)
	//{{AFX_MSG_MAP(CCardGameView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardGameView クラスの構築/消滅

CCardGameView::CCardGameView()
{
	// TODO: この場所に構築用のコードを追加してください。

}

CCardGameView::~CCardGameView()
{
}

BOOL CCardGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCardGameView クラスの描画

void CCardGameView::OnDraw(CDC* pDC)
{
	CCardGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

/////////////////////////////////////////////////////////////////////////////
// CCardGameView クラスの印刷

BOOL CCardGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// デフォルトの印刷準備
	return DoPreparePrinting(pInfo);
}

void CCardGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CCardGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

/////////////////////////////////////////////////////////////////////////////
// CCardGameView クラスの診断

#ifdef _DEBUG
void CCardGameView::AssertValid() const
{
	CView::AssertValid();
}

void CCardGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCardGameDoc* CCardGameView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCardGameDoc)));
	return (CCardGameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCardGameView クラスのメッセージ ハンドラ

void CCardGameView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	srand( (unsigned)time( NULL ) );

	shape[0] = ' ';
	shape[1] = 'S';
	shape[2] = 'H';
	shape[3] = 'C';
	shape[4] = 'D';

	for(int i = 2;i < 10; i++)
	{
		number[i] = '1' + i - 1;
	}
	number[0] = ' ';
	number[1] = 'A';
	number[10] = '*';
	number[11] = 'J';
	number[12] = 'Q';
	number[13] = 'K';

	for (i = 0; i< 8; i++)
	{
		for (int j = 0; j<26; j++)
		{
			board[i][j].number = 0;
			board[i][j].shape = 0;
		}
	}
	for(i = 0;i<4;i++)
	{
		stack[i].number = 0;
		stack[i].shape = 0;
		store[i].number = 0;
		store[i].shape = 0;
	}

	Shuffle();
	m_cardBuf = "";
}

void CCardGameView::Shuffle()
{
	int iId = 0;
	for(int i = 1; i< 5; i++)
	{
		for(int j = 1; j< 14; j++)
		{
			shuffle[iId].shape = i;
			shuffle[iId].number = j;
			iId++;
		}
	}

	for(i = 0; i< 150; i++)
	{
		int i1 = rand() * 52 / RAND_MAX;
		int i2 = rand() * 52 / RAND_MAX;
		CARD shuffleTemp = shuffle[i1];
		shuffle[i1] = shuffle[i2];
		shuffle[i2] = shuffleTemp;
	}
	
	int iRow = 0;
	int iCol = 0;
	for(i = 0; i< 52; i++)
	{
		board[iCol][iRow] = shuffle[i];
		iCol++;
		if(iCol == 8)
		{
			iRow++;
			iCol = 0;
		}
	}	
}


void CCardGameView::DisplayBoard()
{
	CClientDC dc(this);
	
	CBrush pBrush(RGB(0,0,200));
	
	COLORREF color[5];
	color[0] = RGB(200,200,0);
	color[1] = RGB(0,0,0);
	color[2] = RGB(255,0,0);
	color[3] = RGB(0,0,0);
	color[4] = RGB(255,0,0);

	int ox = 50,oy = 150;
	int x,y;
	for(int col = 0; col<8; col++)
	{
		for(int row = 0;row < 26;row++)
		{
			x = ox + col * 50;
			y = oy + row * 20;
			CRect rect(x, y, x + 30,y + 15);
			
			CString prtStr = shape[board[col][row].shape];
			prtStr += number[board[col][row].number];
			CPen pen,*pOldPen;
			pen.CreatePen(PS_SOLID,1,color[board[col][row].shape]);
			pOldPen = (CPen *)dc.SelectObject(&pen);
			if(m_cardBuf == prtStr)
				dc.FillRect(rect,&pBrush);
			else
				dc.RoundRect(rect,CPoint(0,0));
			//dc.DrawText(prtStr,rect,DT_LEFT);
			dc.SetTextColor(color[board[col][row].shape]);
			dc.TextOut( x, y, prtStr);
			dc.SelectObject(pOldPen);
		}
	}
	map[2][0].x = ox;
	map[2][0].y = oy;
	map[2][1].x = x + 50;
	map[2][1].y = y + 20;


	int oStackX = 10,oStackY = 10;
	int oStoreX = 250,oStoreY = 10;
	int stackX, stackY, storeX, storeY;
	for(int i = 0; i< 4; i++)
	{
		stackX = oStackX + i * 50;
		stackY = oStackY;
		CRect rect(stackX, stackY, stackX + 30,stackY + 15);

		CString prtStr = shape[stack[i].shape];
		prtStr += number[stack[i].number];
		CPen pen,*pOldPen;
		pen.CreatePen(PS_SOLID,1,color[stack[i].shape]);
		pOldPen = (CPen *)dc.SelectObject(&pen);
		if(m_cardBuf == prtStr)
			dc.FillRect(rect,&pBrush);
		else
			dc.RoundRect(rect,CPoint(0,0));
		dc.SetTextColor(color[stack[i].shape]);
		dc.DrawText(prtStr,rect,DT_LEFT);
		
		storeX = oStoreX + i * 50;
		storeY = oStoreY;
		CRect rect1(storeX, storeY, storeX + 30, storeY + 15);

		prtStr = shape[store[i].shape];
		prtStr += number[store[i].number];
		CPen pen1;
		pen1.CreatePen(PS_SOLID,1,color[store[i].shape]);
		pOldPen = (CPen *)dc.SelectObject(&pen1);
		if(m_cardBuf == prtStr)
			dc.FillRect(rect1,&pBrush);
		else
			dc.RoundRect(rect1,CPoint(0,0));
		dc.SetTextColor(color[store[i].shape]);
		dc.DrawText(prtStr,rect1,DT_LEFT);
		dc.SelectObject(pOldPen);
	}
	map[0][0].x = oStackX;
	map[0][0].y = oStackY;
	map[0][1].x = stackX + 50;
	map[0][1].y = stackY + 20;

	map[1][0].x = oStoreX;
	map[1][0].y = oStoreY;
	map[1][1].x = storeX + 50;
	map[1][1].y = storeY + 20;
	
}

void CCardGameView::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	DisplayBoard();
	// 描画用メッセージとして CView::OnPaint() を呼び出してはいけません
}

void CCardGameView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	for(int i = 0; i<3; i++)
	{
		if(point.x >= map[i][0].x && point.y >= map[i][0].y && point.x <= map[i][1].x && point.y <= map[i][1].y)
		{
			ClickExec(i,point);
			return;
		}
	}

	m_cardBuf = "";
	CView::OnLButtonDown(nFlags, point);
}

void CCardGameView::ClickExec(int mode, CPoint point)
{
	int col = (point.x - map[mode][0].x) / 50;
	int row = (point.y - map[mode][0].y) / 20;

	switch(mode)
	{
	case 0:
		if(m_cardBuf == "")
		{
			m_cardBuf = shape[stack[col].shape];
			m_cardBuf += number[stack[col].number];
			m_cardBuf.TrimLeft();
			m_modBuf = 0;
			m_colBuf = col;
			m_rowBuf = row;
		}
		else if(m_modBuf == 2)
		{
			m_cardBuf = "";
			if(stack[col].shape == 0)			
			{
				stack[col] = board[m_colBuf][m_rowBuf];
				board[m_colBuf][m_rowBuf].number = 0;
				board[m_colBuf][m_rowBuf].shape = 0;
				
			}
		}
		break;
	case 1:
		if(m_cardBuf == "");
		else if(m_modBuf == 0)
		{
			m_cardBuf = "";
			if(store[col].shape == stack[m_colBuf].shape && (store[col].number + 1) == stack[m_colBuf].number )			
			{
				store[col] = stack[m_colBuf];
				stack[m_colBuf].number = 0;
				stack[m_colBuf].shape = 0;
			}
			else if(stack[m_colBuf].number == 1 && store[col].shape == 0)
			{
				store[col] = stack[m_colBuf];
				stack[m_colBuf].number = 0;
				stack[m_colBuf].shape = 0;
			}
		}
		else if(m_modBuf == 2)
		{
			m_cardBuf = "";
			if(store[col].shape == board[m_colBuf][m_rowBuf].shape && (store[col].number + 1) == board[m_colBuf][m_rowBuf].number )			
			{
				store[col] = board[m_colBuf][m_rowBuf];
				board[m_colBuf][m_rowBuf].number = 0;
				board[m_colBuf][m_rowBuf].shape = 0;
			}
			else if(board[m_colBuf][m_rowBuf].number == 1 && store[col].shape == 0)
			{
				store[col] = board[m_colBuf][m_rowBuf];
				board[m_colBuf][m_rowBuf].number = 0;
				board[m_colBuf][m_rowBuf].shape = 0;
			}
		}
		break;
	case 2:
		row = GetLastBoardPos(col);
		
		if(m_cardBuf == "" && row > 0)
		{
			
			m_cardBuf = shape[board[col][row -1].shape];
			m_cardBuf+= number[board[col][row -1].number];
			m_cardBuf.TrimLeft();
			m_modBuf = 2;
			m_colBuf = col;
			m_rowBuf = row -1;
		}
		else
		{
			m_cardBuf = "";

			if(	m_modBuf == 2 )
			{
				
				int iSEmpty = 0, iBEmpty = 0;
				for(int i = 0; i < 4 ; i++)
				{
					if(stack[i].number == 0) iSEmpty++;
				}
				for(i = 0; i < 8 ; i++)
				{
					if(col != i && board[i][0].number == 0) iBEmpty++;
				}
				
				int iTotAccept = (iSEmpty + 1) * (iBEmpty * 2 - 1) + iSEmpty;
				if(iBEmpty == 0) 
					iTotAccept = iSEmpty;

				for(i = 0; i < iTotAccept; i++)
				{
					if(m_rowBuf - i == 0) break;
					if
					(
						(board[m_colBuf][m_rowBuf - i].shape - board[m_colBuf][m_rowBuf - i - 1].shape) % 2 ==0	
						|| 
						board[m_colBuf][m_rowBuf - i].number != board[m_colBuf][m_rowBuf - i - 1].number -1
					) 
						break;
				}
				int iRowTemp = i;
				if(	row == 0 )
				{
					if(iRowTemp !=0)
					{
						if(AfxMessageBox("Do you want to move many cards?",MB_YESNO) == IDYES)
						{
							for(i = iRowTemp; i>=0;i--)
							{
								board[col][row] = board[m_colBuf][m_rowBuf - i];
								board[m_colBuf][m_rowBuf - i].number = 0;
								board[m_colBuf][m_rowBuf - i].shape = 0;
								row++;
							}
						}
						else
						{
							board[col][row] = board[m_colBuf][m_rowBuf];
							board[m_colBuf][m_rowBuf].number = 0;
							board[m_colBuf][m_rowBuf].shape = 0;
						}
					}
					else
					{
						board[col][row] = board[m_colBuf][m_rowBuf];
						board[m_colBuf][m_rowBuf].number = 0;
						board[m_colBuf][m_rowBuf].shape = 0;
					}
				}
				else 
				{
					for(i = 0; i <= iRowTemp; i++)
					{
						if( 
							(board[m_colBuf][m_rowBuf - i].shape - board[col][row-1].shape) % 2 !=0	
							&& 
							board[col][row-1].number == board[m_colBuf][m_rowBuf - i].number + 1 
						) 
						{
							
							for(; i>=0;i--)
							{
								board[col][row] = board[m_colBuf][m_rowBuf - i];
								board[m_colBuf][m_rowBuf - i].number = 0;
								board[m_colBuf][m_rowBuf - i].shape = 0;
								row++;
							}
							break;
						}
					}
				}
			}
			if(	m_modBuf == 0 
				&& 
				(	row == 0
					||
					(	
						(stack[m_colBuf].shape - board[col][row-1].shape) % 2!=0
						&& 
						board[col][row-1].number == stack[m_colBuf].number + 1 
					)			
				)
			)
			{
				board[col][row] = stack[m_colBuf];
				stack[m_colBuf].number = 0;
				stack[m_colBuf].shape = 0;
				
			}
		}
		break;
	default:
		AfxMessageBox("???");
	}
	
	while(AutoStore());
	
	DisplayBoard();
	if(IsCompleted(13)) 
	{
		AfxMessageBox("Congratulation!");
	}
}

int CCardGameView::GetLastBoardPos(int col)
{	
	int row;
	for(int i=0;i<26;i++)
	{
		row = i;
		if(board[col][i].shape == 0) 
			break;
	}
	return row;
}


void CCardGameView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if(m_modBuf != 2) 
		return;
	m_cardBuf = "";
	if(point.x >= map[2][0].x && point.y >= map[2][0].y && point.x <= map[2][1].x && point.y <= map[2][1].y)
	{
		for(int iStack = 0;iStack < 4; iStack++)
		{
			if(stack[iStack].shape == 0)
			{
				ClickExec(2,point);
			
				point.x = 50 * iStack + map[0][0].x;
				point.y = map[0][0].y;
				ClickExec(0,point);
				break;
			}
		}
	}
	
	CView::OnLButtonDblClk(nFlags, point);
}

BOOL CCardGameView::IsCompleted(int numberWk)
{
	for(int iStore = 0;iStore <4;iStore++)
	{
		if(store[iStore].number < numberWk)
			return FALSE;
	}
	return TRUE;
}

BOOL CCardGameView::AutoStore()
{
	CARD cardWk;
	int numberWk,shapeWk;
	BOOL bRet = FALSE;

	for(numberWk = 1; numberWk <3; numberWk++)
	{
		for(shapeWk = 1; shapeWk < 5; shapeWk++)
		{
			if(store[GetStorePos(shapeWk)].number + 1 == numberWk)
			{
				cardWk.number = numberWk;
				cardWk.shape = shapeWk;
				bRet |=SearchAddCard(cardWk);
			}
		}
	}

	while(IsCompleted(numberWk)) 
		numberWk++;

	BOOL iLoop = TRUE;
	while(iLoop)
	{
		iLoop = FALSE;
		if(store[GetStorePos(2)].number + 1 >= numberWk && store[GetStorePos(4)].number +1 >= numberWk)
		{
			cardWk.number = numberWk;
			if(store[GetStorePos(1)].number + 1 == numberWk)
			{
				cardWk.shape = 1;
				iLoop = SearchAddCard(cardWk) | iLoop;
			}
				
			if (store[GetStorePos(3)].number + 1 == numberWk)
			{
				cardWk.shape = 3;
				iLoop = SearchAddCard(cardWk) | iLoop;
			}
		}
		if(store[GetStorePos(1)].number + 1 >= numberWk && store[GetStorePos(3)].number +1 >= numberWk)
		{
			cardWk.number = numberWk;
			if(store[GetStorePos(2)].number + 1 == numberWk)
			{
				cardWk.shape = 2;
				iLoop = SearchAddCard(cardWk) | iLoop;
			}
				
			if (store[GetStorePos(4)].number + 1 == numberWk)
			{
				cardWk.shape = 4;
				iLoop = SearchAddCard(cardWk) | iLoop;
			}
		}
		if(IsCompleted(numberWk))
			numberWk++;
		
		bRet |=iLoop;
	}
	return bRet;
}



int CCardGameView::GetStorePos(int shapeWk)
{
	for(int iStore = 0;iStore < 4;iStore++)
	{
		if(store[iStore].shape == shapeWk)
		{	
			return iStore;
		}
	}
	for(iStore = 0;iStore < 4;iStore++)
	{
		if(store[iStore].shape == 0)
		{	
			return iStore;
		}
	}
	
}

BOOL CCardGameView::SearchAddCard(CARD cardWk)
{
	
	int iCol, iRow;
	for (iCol = 0;iCol < 4; iCol++)
	{
		if(stack[iCol].number == cardWk.number && stack[iCol].shape == cardWk.shape)
		{
			m_cardBuf = shape[cardWk.shape];
			m_cardBuf+= number[cardWk.number];
			Sleep(180);
			DisplayBoard();

			store[GetStorePos(cardWk.shape)] = cardWk;
			stack[iCol].shape = 0;
			stack[iCol].number = 0;
			m_cardBuf = "";
			
			Sleep(180);
			DisplayBoard();
			
			return TRUE;
		}
	}
	for (iCol = 0;iCol < 8; iCol++)
	{
		iRow = GetLastBoardPos(iCol) - 1;
		if(board[iCol][iRow].number == cardWk.number && board[iCol][iRow].shape == cardWk.shape)
		{
			m_cardBuf = shape[cardWk.shape];
			m_cardBuf+= number[cardWk.number];
			Sleep(180);
			DisplayBoard();

			store[GetStorePos(cardWk.shape)] = cardWk;
			board[iCol][iRow].shape = 0;
			board[iCol][iRow].number = 0;
			m_cardBuf = "";
			
			Sleep(180);
			DisplayBoard();
			
			return TRUE;
		}
	}
	
	return FALSE;
}