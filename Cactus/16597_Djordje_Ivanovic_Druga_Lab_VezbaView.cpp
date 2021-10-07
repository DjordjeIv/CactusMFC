
// 16597_Djordje_Ivanovic_Druga_Lab_VezbaView.cpp : implementation of the CMy16597DjordjeIvanovicDrugaLabVezbaView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "16597_Djordje_Ivanovic_Druga_Lab_Vezba.h"
#endif

#include "16597_Djordje_Ivanovic_Druga_Lab_VezbaDoc.h"
#include "16597_Djordje_Ivanovic_Druga_Lab_VezbaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
bool klick = true;
double pi = 3.1415926535897932384626433832795;
double ug1 = 2.50;
double ug2 = 2.50;
XFORM Xform;

void Rotacija(double ugao, bool IsKrug)
{
	Xform.eM11 = double(cos(ugao));
	Xform.eM12 = double(sin(ugao));
	Xform.eM21 = double(-sin(ugao));
	Xform.eM22 = double(cos(ugao));
	Xform.eDx = 0;
	Xform.eDy = 0;
	if (IsKrug != true)
	{
		Xform.eM11 = double(cos(ugao));
		Xform.eM12 = double(sin(ugao));
		Xform.eM21 = double(-sin(ugao));
		Xform.eM22 = double(cos(ugao));
		Xform.eDx = 405;
		Xform.eDy = 395;
	}
}

// CMy16597DjordjeIvanovicDrugaLabVezbaView

IMPLEMENT_DYNCREATE(CMy16597DjordjeIvanovicDrugaLabVezbaView, CView)

BEGIN_MESSAGE_MAP(CMy16597DjordjeIvanovicDrugaLabVezbaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy16597DjordjeIvanovicDrugaLabVezbaView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy16597DjordjeIvanovicDrugaLabVezbaView construction/destruction

CMy16597DjordjeIvanovicDrugaLabVezbaView::CMy16597DjordjeIvanovicDrugaLabVezbaView() noexcept
{
	// TODO: add construction code here

}

CMy16597DjordjeIvanovicDrugaLabVezbaView::~CMy16597DjordjeIvanovicDrugaLabVezbaView()
{
}

BOOL CMy16597DjordjeIvanovicDrugaLabVezbaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy16597DjordjeIvanovicDrugaLabVezbaView drawing

void CMy16597DjordjeIvanovicDrugaLabVezbaView::OnDraw(CDC* pDC)
{
	CMy16597DjordjeIvanovicDrugaLabVezbaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// grid
	CPen greyPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 4, RGB(220, 220, 220));
	CBrush grayBrush(RGB(135, 206, 250));
	CBrush* oldBrushGrid = pDC->SelectObject(&grayBrush);
	CPen* oldPenGrid = pDC->SelectObject(&greyPen);
	CPoint grid[4];
	grid[0] = CPoint(100, 100);
	grid[1] = CPoint(100, 600);
	grid[2] = CPoint(600, 600);
	grid[3] = CPoint(600, 100);
	pDC->Polygon(grid, 4);
	pDC->SelectObject(oldPenGrid);
	greyPen.DeleteObject();
	pDC->SelectObject(oldBrushGrid);
	grayBrush.DeleteObject();

	//metafajl kaktusa
	CString MFname1 = CString("C:\\Users\\Dimeni\\source\\repos\\16597_Djordje_Ivanovic_Druga_Lab_Vezba\\16597_Djordje_Ivanovic_Druga_Lab_Vezba\\res\\cactus_part.emf");
	CString MFname2 = CString("C:\\Users\\Dimeni\\source\\repos\\16597_Djordje_Ivanovic_Druga_Lab_Vezba\\16597_Djordje_Ivanovic_Druga_Lab_Vezba\\res\\cactus_part_light.emf");
	HENHMETAFILE Kaktus1 = GetEnhMetaFile(MFname1);
	HENHMETAFILE Kaktus2 = GetEnhMetaFile(MFname2);
	ENHMETAHEADER heder;
	GetEnhMetaFileHeader(Kaktus1, sizeof(ENHMETAHEADER), &heder);
	/*PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(317, 448, 383, 527));
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(340, 373, 360, 452));
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(393, 321, 413, 400));
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(370, 244, 436, 323));*/

	//krivi ukoso
	int mod = SetGraphicsMode(pDC->m_hDC, GM_ADVANCED);
	DWORD dw = GetLastError();
	XFORM XformOld;


	BOOL b = GetWorldTransform(pDC->m_hDC, &XformOld);
	Rotacija(ug1 * pi / 2.0, false);
	b = SetWorldTransform(pDC->m_hDC, &Xform);
	dw = GetLastError();
	PlayEnhMetaFile(pDC->m_hDC, Kaktus2, CRect(-8, -5, 12, 74));
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(-31, 72, 35, 151));
	CPen zeleniKruziciPenObrtni(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 1, RGB(0, 0, 0));
	CBrush zelenaCetkaKruziciObrtni(RGB(50, 205, 50));
	CBrush* oldBrush3 = pDC->SelectObject(&zelenaCetkaKruziciObrtni);
	CPen* oldPen3 = pDC->SelectObject(&zeleniKruziciPenObrtni);
	pDC->Ellipse(CRect(-8, 63, 12, 83));
	pDC->SelectObject(oldBrush3);
	zeleniKruziciPenObrtni.DeleteObject();
	pDC->SelectObject(oldPen3);
	zelenaCetkaKruziciObrtni.DeleteObject();

	//ostatak
	Rotacija(1.75 * pi / 7.0, true);
	b = SetWorldTransform(pDC->m_hDC, &Xform);
	dw = GetLastError();

	// Iscrtavanje
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(556, -6, 576, 73));

	Rotacija(ug2 * pi / 2.0, false);
	b = SetWorldTransform(pDC->m_hDC, &Xform);
	dw = GetLastError();
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(-30, 49, -74, 128));

	//nova rotacija
	Rotacija((ug2 + 0.5)* pi / 2.0, false);
	b = SetWorldTransform(pDC->m_hDC, &Xform);
	dw = GetLastError();
	//crtam
	PlayEnhMetaFile(pDC->m_hDC, Kaktus2, CRect(-11, -5, 9, 74));
	//rotiram
	Rotacija((ug2 + 3.0) * pi / 2.0, false);
	b = SetWorldTransform(pDC->m_hDC, &Xform);
	dw = GetLastError();

	//crtanje
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(-73, -130, -29, -51));

	CPen zeleniKruziciPenObrtni1(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 1, RGB(0, 0, 0));
	CBrush zelenaCetkaKruziciObrtni1(RGB(50, 205, 50));
	CBrush* oldBrush4 = pDC->SelectObject(&zelenaCetkaKruziciObrtni1);
	CPen* oldPen4 = pDC->SelectObject(&zeleniKruziciPenObrtni1);
	pDC->Ellipse(CRect(-40, -63, -60, -43));
	pDC->SelectObject(oldBrush4);
	zeleniKruziciPenObrtni1.DeleteObject();
	pDC->SelectObject(oldPen4);
	zelenaCetkaKruziciObrtni1.DeleteObject();

	Rotacija(5.00 * pi / 2.0, true);
	b = SetWorldTransform(pDC->m_hDC, &Xform);
	dw = GetLastError();
	pDC->SetBkColor(RGB(135, 206, 250));
	pDC->SetTextColor(RGB(255, 0, 0));
	CFont font;
	font.CreateFont(30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("Times New Roman"));
	CFont* pOldFont = (CFont*)pDC->SelectObject(&font);
	pDC->TextOut(125, -575, _T("16597 Djordje Ivanovic"));
	pDC->SelectObject(pOldFont);
	font.DeleteObject();

	//zadnja rotacija
	Rotacija(5.5 * pi / 2.0, true);
	b = SetWorldTransform(pDC->m_hDC, &Xform);
	dw = GetLastError();
	//crtanje
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(61, -489, 81, -568));
	

	//brisanje i vracanje na staro
	b = SetWorldTransform(pDC->m_hDC, &XformOld);
	SetGraphicsMode(pDC->m_hDC, mod);
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(317, 448, 383, 527));
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(340, 373, 360, 452));
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(393, 321, 413, 400));
	PlayEnhMetaFile(pDC->m_hDC, Kaktus1, CRect(370, 244, 436, 323));
	DeleteEnhMetaFile(Kaktus1);
	DeleteEnhMetaFile(Kaktus2);


	//zeleni kruzici
	CPen zeleniKruziciPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 1, RGB(0, 0, 0));
	CBrush zelenaCetkaKruzici(RGB(50, 205, 50));
	CBrush* oldBrush2 = pDC->SelectObject(&zelenaCetkaKruzici);
	CPen* oldPen2 = pDC->SelectObject(&zeleniKruziciPen);
	pDC->Ellipse(CRect(340, 515, 360, 535));
	pDC->Ellipse(CRect(340, 440, 360, 460));
	pDC->Ellipse(CRect(393, 387, 413, 407));
	pDC->Ellipse(CRect(393, 312, 413, 332));
	//pDC->Ellipse(CRect(468, 387, 488, 407));
	pDC->SelectObject(oldBrush2);
	zeleniKruziciPen.DeleteObject();
	pDC->SelectObject(oldPen2);
	zelenaCetkaKruzici.DeleteObject();

	

	// braon saksija
	CPen saksijaPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 1, RGB(0, 0, 0));
	CBrush cetkaSaksija(RGB(244, 164, 96));
	CBrush* oldBrushTroCrveni = pDC->SelectObject(&cetkaSaksija);
	CPen* oldPenTroCrveni = pDC->SelectObject(&saksijaPen);
	CPoint saksija[8];
	saksija[0] = CPoint(310, 600);
	saksija[1] = CPoint(390, 600);
	saksija[2] = CPoint(400, 550);
	saksija[3] = CPoint(410, 550);
	saksija[4] = CPoint(410, 530);
	saksija[5] = CPoint(290, 530);
	saksija[6] = CPoint(290, 550);
	saksija[7] = CPoint(300, 550);
	pDC->Polygon(saksija, 8);
	pDC->SelectObject(oldPenTroCrveni);
	saksijaPen.DeleteObject();
	pDC->SelectObject(oldBrushTroCrveni);
	cetkaSaksija.DeleteObject();

	if (klick)
	{
		LOGBRUSH logBrush3;
		logBrush3.lbStyle = BS_SOLID;
		logBrush3.lbColor = RGB(255, 255, 255);
		CPen* pPen3 = new CPen(PS_GEOMETRIC | PS_SOLID |
			PS_ENDCAP_ROUND | PS_JOIN_ROUND, 1, &logBrush3);
		CPen* oldPen3 = pDC->SelectObject(pPen3);

		for (int i = 0; i < 21; i++)
		{
			int strt = i * 25;
			int mv = 100 + strt;
			int ed = 600;
			pDC->MoveTo(100, mv);
			pDC->LineTo(ed, mv);
			pDC->MoveTo(mv, 100);
			pDC->LineTo(mv, ed);
		}
	}
	
}



// CMy16597DjordjeIvanovicDrugaLabVezbaView printing


void CMy16597DjordjeIvanovicDrugaLabVezbaView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy16597DjordjeIvanovicDrugaLabVezbaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy16597DjordjeIvanovicDrugaLabVezbaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy16597DjordjeIvanovicDrugaLabVezbaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy16597DjordjeIvanovicDrugaLabVezbaView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy16597DjordjeIvanovicDrugaLabVezbaView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy16597DjordjeIvanovicDrugaLabVezbaView diagnostics

#ifdef _DEBUG
void CMy16597DjordjeIvanovicDrugaLabVezbaView::AssertValid() const
{
	CView::AssertValid();
}

void CMy16597DjordjeIvanovicDrugaLabVezbaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy16597DjordjeIvanovicDrugaLabVezbaDoc* CMy16597DjordjeIvanovicDrugaLabVezbaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy16597DjordjeIvanovicDrugaLabVezbaDoc)));
	return (CMy16597DjordjeIvanovicDrugaLabVezbaDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy16597DjordjeIvanovicDrugaLabVezbaView message handlers


void CMy16597DjordjeIvanovicDrugaLabVezbaView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	switch (nChar)
	{
	case 68: ug1 += 0.05;
		break;
	case 65 : ug1 -= 0.05;
		break;
	case 39: ug2 += 0.05;
		break;
	case 37: ug2 -= 0.05;
		break;
	case 32 : klick = !klick;
		break;
	}
	Invalidate();
}
