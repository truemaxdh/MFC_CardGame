// CardGameDoc.cpp : CCardGameDoc �N���X�̓���̒�`���s���܂��B
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
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc �N���X�̍\�z/����

CCardGameDoc::CCardGameDoc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CCardGameDoc::~CCardGameDoc()
{
}

BOOL CCardGameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc �V���A���C�[�[�V����

void CCardGameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă��������B
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă��������B
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCardGameDoc �N���X�̐f�f

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
// CCardGameDoc �R�}���h
