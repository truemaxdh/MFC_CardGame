// CardGameDoc.cpp : CCardGameDoc クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "CardGame.h"

#include "CardGameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc

IMPLEMENT_DYNCREATE(CCardGameDoc, CDocument)

BEGIN_MESSAGE_MAP(CCardGameDoc, CDocument)
	//{{AFX_MSG_MAP(CCardGameDoc)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc クラスの構築/消滅

CCardGameDoc::CCardGameDoc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

}

CCardGameDoc::~CCardGameDoc()
{
}

BOOL CCardGameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc シリアライゼーション

void CCardGameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: この位置に保存用のコードを追加してください。
	}
	else
	{
		// TODO: この位置に読み込み用のコードを追加してください。
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc クラスの診断

#ifdef _DEBUG
void CCardGameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCardGameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc コマンド
