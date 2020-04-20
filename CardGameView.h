// CardGameView.h : CCardGameView �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
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
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CCardGameView();
	DECLARE_DYNCREATE(CCardGameView)

// �A�g���r���[�g
	CARD board[8][26], stack[4], store[4], shuffle[52];
	char shape[5], number[14];
	CPoint map[3][2];
	CString m_cardBuf;
	int m_modBuf,m_colBuf,m_rowBuf;
public:
	CCardGameDoc* GetDocument();

// �I�y���[�V����
	void Shuffle();
	void DisplayBoard();
	void ClickExec(int mode, CPoint point);
	int GetLastBoardPos(int col);
	BOOL IsCompleted(int numberWk);
	BOOL AutoStore();
	int GetStorePos(int shapeWk);
	BOOL SearchAddCard(CARD cardWk);
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CCardGameView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CCardGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CCardGameView)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CardGameView.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CCardGameDoc* CCardGameView::GetDocument()
   { return (CCardGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CARDGAMEVIEW_H__80A17002_477F_4BEF_B470_B78CB3565553__INCLUDED_)
