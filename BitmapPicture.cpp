//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  CBitmapPicture (Implementations) Version 1.00
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  COPYFREE (F) - ALL RIGHTS FREE
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// BitmapPicture.cpp: implementation of the CBitmapPicture class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BitmapPicture.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define HIMETRIC_INCH 2540
#define ERROR_TITLE "CPanoramaBitmap Error" // Error Title (Related To This Class)...

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBitmapPicture::CBitmapPicture()
{
	m_IPicture = NULL;
	m_Height = 0;
	m_Weight = 0;
	m_Width = 0;
}

CBitmapPicture::~CBitmapPicture()
{
	if(m_IPicture != NULL) FreePictureData(); // Important - Avoid Leaks...
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// PUBLIC
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// Does:   Open a Resource And Load It Into IPicture (Interface)
// ~~~~    (.BMP .DIB .EMF .GIF .ICO .JPG .WMF)
//
// Note:   When Adding a Bitmap Resource It Would Automatically Show On "Bitmap"
// ~~~~    This NOT Good Coz We Need To Load It From a Custom Resource "BMP"
//         To Add a Custom Rresource: Import Resource -> Open As -> Custom
//         (Both .BMP And .DIB Should Be Found Under "BMP")
//
// InPut:  ResourceName - As a UINT Defined (Example: IDR_PICTURE_RESOURCE)
// ~~~~~   ResourceType - Type Name (Example: "JPG")
//
// OutPut: TRUE If Succeeded...
// ~~~~~~
// Author: Dr. Yovav Gad, EMail: Sources@SuperMain.com ,Web: www.SuperMain.com
//=============================================================================
//-----------------------------------------------------------------------------
BOOL CBitmapPicture::Load(UINT ResourceName, CString ResourceType)
//=============================================================================
{
	//Free Bitmap if allocated
	DeleteObject();

	BOOL bResult = FALSE;

	HGLOBAL		hGlobal = NULL;
	HRSRC		hSource = NULL;
	LPVOID		lpVoid  = NULL;
	int			nSize   = 0;

	if(m_IPicture != NULL) FreePictureData(); // Important - Avoid Leaks...

	if(ResourceType=="BMP")
		return LoadStandardResource(ResourceName,ResourceType);

	if(!hSource) hSource = FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(ResourceName), ResourceType);

	if(hSource == NULL)
		{
		HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
		MessageBoxEx(hWnd, "FindResource() Failed\t", ERROR_TITLE, MB_OK | MB_ICONSTOP, LANG_ENGLISH);
		return(FALSE);
		}

	hGlobal = LoadResource(AfxGetResourceHandle(), hSource);
	if(hGlobal == NULL)
		{
		HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
		MessageBoxEx(hWnd, "LoadResource() Failed\t", ERROR_TITLE, MB_OK | MB_ICONSTOP, LANG_ENGLISH);
		return(FALSE);
		}

	lpVoid = LockResource(hGlobal);
	if(lpVoid == NULL)
		{
		HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
		MessageBoxEx(hWnd, "LockResource() Failed\t", ERROR_TITLE, MB_OK | MB_ICONSTOP, LANG_ENGLISH);
		return(FALSE);
		}

	nSize = (UINT)SizeofResource(AfxGetResourceHandle(), hSource);
	if(LoadPictureData((BYTE*)hGlobal, nSize)) bResult = TRUE;

	UnlockResource(hGlobal); // 16Bit Windows Needs This
	FreeResource(hGlobal); // 16Bit Windows Needs This (32Bit - Automatic Release)

	m_Weight = nSize; // Update Picture Size Info...

	if(m_IPicture != NULL) // Do Not Try To Read From Memory That Is Not Exist...
		{ 
		m_IPicture->get_Height(&m_Height);
		m_IPicture->get_Width(&m_Width);
	    // Calculate Its Size On a "Standard" (96 DPI) Device Context
	    m_Height = MulDiv(m_Height, 96, HIMETRIC_INCH);
	    m_Width  = MulDiv(m_Width,  96, HIMETRIC_INCH);
		}
	else // Picture Data Is Not a Known Picture Type
		{
		m_Height = 0;
		m_Width = 0;
		bResult = FALSE;
		}

	if(bResult) return(CreatePanoramaBitmap());
	else return(bResult);
}

//-----------------------------------------------------------------------------
// Does:   Open a File And Load It Into IPicture (Interface)
// ~~~~    (.BMP .DIB .EMF .GIF .ICO .JPG .WMF)
//
// InPut:  sFilePathName - Path And FileName Target To Save
// ~~~~~   
//
// OutPut: TRUE If Succeeded...
// ~~~~~~
// Author: Dr. Yovav Gad, EMail: Sources@SuperMain.com ,Web: www.SuperMain.com
//=============================================================================
//-----------------------------------------------------------------------------
BOOL CBitmapPicture::Load(CString sFilePathName)
//=============================================================================
{
	//Free Bitmap if allocated
	DeleteObject();

	BOOL bResult = FALSE;
	CFile PictureFile;
	CFileException e;
	int	nSize = 0;

	if(m_IPicture != NULL) FreePictureData(); // Important - Avoid Leaks...

	if(PictureFile.Open(sFilePathName, CFile::modeRead | CFile::typeBinary, &e))
		{
		nSize = PictureFile.GetLength();
		BYTE* pBuffer = new BYTE[nSize];
	
		if(PictureFile.Read(pBuffer, nSize) > 0)
			{
			if(LoadPictureData(pBuffer, nSize))	bResult = TRUE;
			}

		PictureFile.Close();
		delete [] pBuffer;
		}
	else // Open Failed...
		{
		TCHAR szCause[255];
		e.GetErrorMessage(szCause, 255, NULL);
		HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
		MessageBoxEx(hWnd, szCause, ERROR_TITLE, MB_OK | MB_ICONSTOP, LANG_ENGLISH);
		bResult = FALSE;
		}

	m_Weight = nSize; // Update Picture Size Info...

	if(m_IPicture != NULL) // Do Not Try To Read From Memory That Is Not Exist...
		{ 
		m_IPicture->get_Height(&m_Height);
		m_IPicture->get_Width(&m_Width);
	    // Calculate Its Size On a "Standard" (96 DPI) Device Context
	    m_Height = MulDiv(m_Height, 96, HIMETRIC_INCH);
	    m_Width  = MulDiv(m_Width,  96, HIMETRIC_INCH);
		}
	else // Picture Data Is Not a Known Picture Type
		{
		m_Height = 0;
		m_Width = 0;
		bResult = FALSE;
		}

	if(bResult) return(CreatePanoramaBitmap());
	else return(bResult);
}

BOOL CBitmapPicture::SelectFileAndLoad()
{
	 CString DefExt = "jpg";
	 DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	 CString Filter = "All Supported Image files|*.jpg;*.jif;*.jpeg;*.gif;*.bmp;*.dib;|JPG - JFIF Compliant (*.jpg,*.jif,*.jpeg)|*.jpg;*.jif,*.jpg|CompuServe Graphics Interchange (*.gif)|*.gif|Windows or OS/2 Bitmap (*.bmp)|*.bmp|Windows or OS/2 DIB (*.dib)|*.dib||";
	 CFileDialog FileDialog(TRUE,DefExt,NULL,dwFlags,Filter,NULL);
	 if(FileDialog.DoModal()==IDOK)
	 {
		return Load(FileDialog.GetPathName());
	 }

	return FALSE;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// PRIVATE
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Does:   Free The Allocated Memory That Holdes The IPicture Interface Data
// ~~~~    And Clear Picture Information
//
// Note:   This Might Also Be Useful If U Only Need To Show The Picture Once
// ~~~~~   Or If U Copy The Picture To The Device Context, So It Can Still
//         Remain On Screen - But IPicture Data Is Not Needed No More
//
// Author: Dr. Yovav Gad, EMail: Sources@SuperMain.com ,Web: www.SuperMain.com
//-----------------------------------------------------------------------------
void CBitmapPicture::FreePictureData()
//=============================================================================
{
	if(m_IPicture != NULL)
		{
		m_IPicture->Release();
		m_IPicture = NULL;
		m_Height = 0;
		m_Weight = 0;
		m_Width = 0;
		}
}

//-----------------------------------------------------------------------------
// Does:   Read The Picture Data From a Source (File / Resource)
// ~~~~    And Load It Into The Current IPicture Object In Use
//
// InPut:  Buffer Of Data Source (File / Resource) And Its Size
// ~~~~~   
//
// OutPut: Feed The IPicture Object With The Picture Data
// ~~~~~~  (Use Draw Functions To Show It On a Device Context)
//         TRUE If Succeeded...
// Author: Dr. Yovav Gad, EMail: Sources@SuperMain.com ,Web: www.SuperMain.com
//=============================================================================
//-----------------------------------------------------------------------------
BOOL CBitmapPicture::LoadPictureData(BYTE *pBuffer, int nSize)
//=============================================================================
{
	BOOL bResult = FALSE;

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, nSize);

	if(hGlobal == NULL)
		{
		HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
		MessageBoxEx(hWnd, "Can not allocate enough memory\t", ERROR_TITLE, MB_OK | MB_ICONSTOP, LANG_ENGLISH);
		return(FALSE);
		}

	void* pData = GlobalLock(hGlobal);
	memcpy(pData, pBuffer, nSize);
	GlobalUnlock(hGlobal);

	IStream* pStream = NULL;

	if(CreateStreamOnHGlobal(hGlobal, TRUE, &pStream) == S_OK)
		{
		HRESULT hr;
		if((hr = OleLoadPicture(pStream, nSize, FALSE, IID_IPicture, (LPVOID *)&m_IPicture)) == E_NOINTERFACE)
			{
			HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
			MessageBoxEx(hWnd, "IPicture interface is not supported\t", ERROR_TITLE, MB_OK | MB_ICONSTOP, LANG_ENGLISH);
			return(FALSE);
			}
		else // S_OK
			{
			pStream->Release();
			pStream = NULL;
			bResult = TRUE;
			}
		}

	FreeResource(hGlobal); // 16Bit Windows Needs This (32Bit - Automatic Release)

	return(bResult);
}

// Does:   Loads the Bitmap from a Bitmap resource
// ~~~~    
//
// Note:   
// ~~~~    
//
// InPut:  ResourceName - As a UINT Defined (Example: IDR_PICTURE_RESOURCE)
// ~~~~~   ResourceType - Type Name (Example: "BMP")
//
// OutPut: TRUE If Succeeded.
// ~~~~~~
//=============================================================================
//-----------------------------------------------------------------------------
BOOL CBitmapPicture::LoadStandardResource(UINT ResourceName, CString ResourceType)
{
	BOOL result = LoadBitmap(MAKEINTRESOURCE(ResourceName));

	if(result)
	{
		BITMAP bm;
		GetBitmap( &bm );
		m_Width = bm.bmWidth;
		m_Height = bm.bmHeight;

		return TRUE;
	}

	return FALSE;
}

// Does:   Creates a Bitmap from the IPicture that was loaded.
// ~~~~    
//
// Note:   
// ~~~~    
//
// InPut:  
// ~~~~~   
//
// OutPut: TRUE If Succeeded.
// ~~~~~~
// supporting Authors
// Author: Dr. Yovav Gad, EMail: Sources@SuperMain.com ,Web: www.SuperMain.com
// Modified from: BOOL CPicture::SaveAsBitmap(CString sFilePathName)
// Author: Zafir Anjum
// Modified from: BOOL LoadBMPImage( LPCTSTR sBMPFile, CBitmap& bitmap, CPalette *pPal )
//=============================================================================
//-----------------------------------------------------------------------------

BOOL CBitmapPicture::CreatePanoramaBitmap()
//=============================================================================
{
	// Author: Dr. Yovav Gad, EMail: Sources@SuperMain.com ,Web: www.SuperMain.com

	BOOL bResult = FALSE;
	ILockBytes *Buffer = 0;
	IStorage   *pStorage = 0;
	IStream    *FileStream = 0;
	BYTE	   *BufferBytes;
	BYTE	   *pBufferBytes;//Added by Liming Xuan to solve the mem leaks
	STATSTG		BytesStatistics;
	DWORD		OutData;
	long		OutStream;
	CFile		BitmapFile;	CFileException e;
	double		SkipFloat = 0;
	DWORD		ByteSkip = 0;
	_ULARGE_INTEGER RealData;

	CreateILockBytesOnHGlobal(NULL, TRUE, &Buffer); // Create ILockBytes Buffer

	HRESULT hr = ::StgCreateDocfileOnILockBytes(Buffer,
				 STGM_SHARE_EXCLUSIVE | STGM_CREATE | STGM_READWRITE, 0, &pStorage);

	hr = pStorage->CreateStream(L"PICTURE",
		 STGM_SHARE_EXCLUSIVE | STGM_CREATE | STGM_READWRITE, 0, 0, &FileStream);

	m_IPicture->SaveAsFile(FileStream, TRUE, &OutStream); // Copy Data Stream
	FileStream->Release();
	pStorage->Release();
	Buffer->Flush(); 

	// Get Statistics For Final Size Of Byte Array
	Buffer->Stat(&BytesStatistics, STATFLAG_NONAME);

	// Cut UnNeeded Data Coming From SaveAsFile() (Leave Only "Pure" Picture Data)
	SkipFloat = (double(OutStream) / 512); // Must Be In a 512 Blocks...
	if(SkipFloat > DWORD(SkipFloat)) ByteSkip = (DWORD)SkipFloat + 1;
	else ByteSkip = (DWORD)SkipFloat;
	ByteSkip = ByteSkip * 512; // Must Be In a 512 Blocks...
	
	// Find Difference Between The Two Values
	ByteSkip = (DWORD)(BytesStatistics.cbSize.QuadPart - ByteSkip);

	// Allocate Only The "Pure" Picture Data
	RealData.LowPart = 0;
	RealData.HighPart = 0;
	RealData.QuadPart = ByteSkip;
	BufferBytes = (BYTE*)malloc(OutStream);
	pBufferBytes = BufferBytes;//Added by Liming Xuan to solve the mem leak
	if(BufferBytes == NULL)
		{
		Buffer->Release();
		HWND hWnd = AfxGetApp()->GetMainWnd()->m_hWnd;
		MessageBoxEx(hWnd, "Can not allocate enough memory\t", ERROR_TITLE, MB_OK | MB_ICONSTOP, LANG_ENGLISH);
		}

	Buffer->ReadAt(RealData, BufferBytes, OutStream, &OutData);
// Author: Zafir Anjum

	//get header information
	BITMAPFILEHEADER  bmfHeader;
	memcpy(&bmfHeader,BufferBytes,sizeof(bmfHeader));

	// remove Header
	DWORD bmfHeaderSize = sizeof(BITMAPFILEHEADER);
	BufferBytes += bmfHeaderSize;

	//get remainder of the information
	BITMAPINFOHEADER &bmiHeader = *(LPBITMAPINFOHEADER)BufferBytes ;
	BITMAPINFO &bmInfo = *(LPBITMAPINFO)BufferBytes ;

	// If bmiHeader.biClrUsed is zero we have to infer the number
	// of colors from the number of bits used to specify it.
	int nColors = bmiHeader.biClrUsed ? bmiHeader.biClrUsed : 
						1 << bmiHeader.biBitCount;

	LPVOID lpDIBBits;
	if( bmInfo.bmiHeader.biBitCount > 8 )
		lpDIBBits = (LPVOID)((LPDWORD)(bmInfo.bmiColors + bmInfo.bmiHeader.biClrUsed) + 
			((bmInfo.bmiHeader.biCompression == BI_BITFIELDS) ? 3 : 0));
	else
		lpDIBBits = (LPVOID)(bmInfo.bmiColors + nColors);

	CClientDC dc(NULL);

	HBITMAP hBmp = CreateDIBitmap(dc.m_hDC,		// handle to device context 
				&bmiHeader,			// pointer to bitmap size and format data 
				CBM_INIT,			// initialization flag 
				lpDIBBits,			// pointer to initialization data 
				&bmInfo,			// pointer to bitmap color-format data 
				DIB_RGB_COLORS);	// color-data usage 


	Attach(hBmp);
	Buffer->Release();

	//Added by Liming Xuan to solve the mem leak
	if (pBufferBytes)
	{
		free(pBufferBytes);
	}


	FreePictureData();

	return TRUE;
}
