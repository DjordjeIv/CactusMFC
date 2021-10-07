
// 16597_Djordje_Ivanovic_Druga_Lab_VezbaDoc.h : interface of the CMy16597DjordjeIvanovicDrugaLabVezbaDoc class
//


#pragma once


class CMy16597DjordjeIvanovicDrugaLabVezbaDoc : public CDocument
{
protected: // create from serialization only
	CMy16597DjordjeIvanovicDrugaLabVezbaDoc() noexcept;
	DECLARE_DYNCREATE(CMy16597DjordjeIvanovicDrugaLabVezbaDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMy16597DjordjeIvanovicDrugaLabVezbaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
