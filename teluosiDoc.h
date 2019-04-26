// teluosiDoc.h : interface of the CTeluosiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TELUOSIDOC_H__C8B3912C_DC82_470C_A9AF_1007643886EC__INCLUDED_)
#define AFX_TELUOSIDOC_H__C8B3912C_DC82_470C_A9AF_1007643886EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTeluosiDoc : public CDocument
{
protected: // create from serialization only
	CTeluosiDoc();
	DECLARE_DYNCREATE(CTeluosiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeluosiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTeluosiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTeluosiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TELUOSIDOC_H__C8B3912C_DC82_470C_A9AF_1007643886EC__INCLUDED_)
