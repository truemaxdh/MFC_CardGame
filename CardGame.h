// CardGame.h : CARDGAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_CARDGAME_H__1CB1E198_1387_4484_9DA1_E0EED606D883__INCLUDED_)
#define AFX_CARDGAME_H__1CB1E198_1387_4484_9DA1_E0EED606D883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CCardGameApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� CardGame.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CCardGameApp : public CWinApp
{
public:
	CCardGameApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CCardGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CCardGameApp)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CARDGAME_H__1CB1E198_1387_4484_9DA1_E0EED606D883__INCLUDED_)
