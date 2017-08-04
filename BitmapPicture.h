// BitmapPicture.h: interface for the CBitmapPicture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPPICTURE_H__D1D5BD84_9C00_4935_9A59_F198A9544895__INCLUDED_)
#define AFX_BITMAPPICTURE_H__D1D5BD84_9C00_4935_9A59_F198A9544895__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBitmapPicture : public CBitmap  
{
public:
	CBitmapPicture();
	virtual ~CBitmapPicture();

//attributes
	LONG      m_Height; // Height (In Pixels Ignor What Current Device Context Uses)
	LONG      m_Weight; // Size Of The Image Object In Bytes (File OR Resource)
	LONG      m_Width;  // Width (In Pixels Ignor What Current Device Context Uses)

//operations
	BOOL Load(CString sFilePathName);
	BOOL Load(UINT ResourceName, CString ResourceType);
	BOOL SelectFileAndLoad();

private:
//attributes
	IPicture* m_IPicture; // Same As LPPICTURE (typedef IPicture __RPC_FAR *LPPICTURE)

//operations
	void FreePictureData();
	BOOL LoadPictureData(BYTE* pBuffer, int nSize);
	BOOL LoadStandardResource(UINT ResourceName, CString ResourceType);
	BOOL CreatePanoramaBitmap();

};

#endif // !defined(AFX_BITMAPPICTURE_H__D1D5BD84_9C00_4935_9A59_F198A9544895__INCLUDED_)
