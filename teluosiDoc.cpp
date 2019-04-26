// teluosiDoc.cpp : implementation of the CTeluosiDoc class
//

#include "stdafx.h"
#include "teluosi.h"

#include "teluosiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeluosiDoc

IMPLEMENT_DYNCREATE(CTeluosiDoc, CDocument)

BEGIN_MESSAGE_MAP(CTeluosiDoc, CDocument)
	//{{AFX_MSG_MAP(CTeluosiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeluosiDoc construction/destruction

CTeluosiDoc::CTeluosiDoc()
{
	// TODO: add one-time construction code here

}

CTeluosiDoc::~CTeluosiDoc()
{
}

BOOL CTeluosiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTeluosiDoc serialization

void CTeluosiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTeluosiDoc diagnostics

#ifdef _DEBUG
void CTeluosiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTeluosiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeluosiDoc commands
