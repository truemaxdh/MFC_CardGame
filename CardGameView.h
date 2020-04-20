// CardGameView.h : CCardGameView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARDGAMEVIEW_H__80A17002_477F_4BEF_B470_B78CB3565553__INCLUDED_)
#define AFX_CARDGAMEVIEW_H__80A17002_477F_4BEF_B470_B78CB3565553__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCardGameView : public CView
{
typedef struct _card
{
	int shape;
	int number;
} CARD;
protected: // シリアライズ機能のみから作成します。
	CCardGameView();
	DECLARE_DYNCREATE(CCardGameView)

// アトリビュート
	CARD board[8][26], stack[4], store[4], shuffle[52];
	char shape[5], number[14];
	CPoint map[3][2];
	CString m_cardBuf;
	int m_modBuf,m_colBuf,m_rowBuf;
public:
	CCardGameDoc* GetDocument();

// オペレーション
	void Shuffle();
	void DisplayBoard();
	void ClickExec(int mode, CPoint point);
	int GetLastBoardPos(int col);
	BOOL IsCompleted(int numberWk);
	BOOL AutoStore();
	int GetStorePos(int shapeWk);
	BOOL SearchAddCard(CARD cardWk);
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CCardGameView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CCardGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CCardGameView)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CardGameView.cpp ファイルがデバッグ環境の時使用されます。
inline CCardGameDoc* CCardGameView::GetDocument()
   { return (CCardGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CARDGAMEVIEW_H__80A17002_477F_4BEF_B470_B78CB3565553__INCLUDED_)
