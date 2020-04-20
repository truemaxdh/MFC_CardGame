// CardGame.h : CARDGAME アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_CARDGAME_H__1CB1E198_1387_4484_9DA1_E0EED606D883__INCLUDED_)
#define AFX_CARDGAME_H__1CB1E198_1387_4484_9DA1_E0EED606D883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CCardGameApp:
// このクラスの動作の定義に関しては CardGame.cpp ファイルを参照してください。
//

class CCardGameApp : public CWinApp
{
public:
	CCardGameApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CCardGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CCardGameApp)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CARDGAME_H__1CB1E198_1387_4484_9DA1_E0EED606D883__INCLUDED_)
