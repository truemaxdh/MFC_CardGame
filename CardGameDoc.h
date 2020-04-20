// CardGameDoc.h : CCardGameDoc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARDGAMEDOC_H__57BA3279_E34F_4C3E_B8E6_98A8432A41AB__INCLUDED_)
#define AFX_CARDGAMEDOC_H__57BA3279_E34F_4C3E_B8E6_98A8432A41AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCardGameDoc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CCardGameDoc();
	DECLARE_DYNCREATE(CCardGameDoc)

// アトリビュート
public:

// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CCardGameDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CCardGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CCardGameDoc)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CARDGAMEDOC_H__57BA3279_E34F_4C3E_B8E6_98A8432A41AB__INCLUDED_)
