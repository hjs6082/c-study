#include "BImage.h"

//만약 png 파일을 쓰고싶다면 인터넷에서 gdi plus	

DWORD BImage::m_TransparentColor = RGB(255, 0, 255); //스태틱 멤버 변수 초기화


BImage::BImage() : m_BitmapHandle(nullptr), m_rotateAngle(0)
{
	memset(&m_BitmapInfo, 0, sizeof(m_BitmapInfo));
}

BImage::BImage(const TCHAR* strLoadFile)
{
	this->Load(strLoadFile);
}

BImage::~BImage() 
{
	if (this->IsEmpty() == false)
	{
		DeleteObject(m_BitmapHandle); //비트맵이 존재하면 없애준다.
	}
}

bool BImage::Load(const TCHAR* strLoadFile)
{
	/* 
	LoadImage의 파라미터는 다음과 같다.
	HINSTANCE, 파일이름, 타입, x,y,로드옵션
	타입 : IMAGE_BITMAP(0), IMAGE_CURSOR(2), IMAGE_ICON(1)
	x,y : 이미지의 크기를 말하는데 만약에 이 값이 전부 0이면서 LR_DEfAuLTSIZE가 옵션으로 오면
	시스템의 SM_CXICON을 이용해서 크기를 측정하게 되고
	만약 LR_DEFAULT_SIZE가 설정되어있지 않다면 리소스가 원래 크기로 로드된다.
	
	DIB = Device-Independent Bitmap : 상시 독립적 비트맵, 색정보테이블을 가직욌는 비트맵
	LR_LOADFROMFILE : 리소스 대신 파일 경로를 이용하여 불러올것이다.
	
	GetModuleHandle => Module에 대한 인스턴스 핸들, dll이나 exe에 사용을 하게 되는데
	여기서는 nullptr을 넣으면 현재 인스턴스의 핸들이 넘어옴.
	*/

	m_BitmapHandle = (HBITMAP)LoadImage(GetModuleHandle(nullptr), strLoadFile, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);

	if (this->IsEmpty())
	{
		return false;
	}

	//로딩 성공했다면
	GetObject(m_BitmapHandle, sizeof(m_BitmapInfo), &m_BitmapInfo);
	return true;
}

bool BImage::Load(HBITMAP bitmapHandle)
{
	return false;
}

bool BImage::Release()
{
	return false;
}

void BImage::SetRotate(double value)
{
}

bool BImage::IsEmpty() const
{
	return m_BitmapHandle == NULL; // 여기선 nullptr을 쓰면 문제가 발생함.
}

HBITMAP BImage::GetBitmapHandle() const
{
	return HBITMAP();
}

const BITMAP& BImage::GetBitmapInfo() const
{
	// TODO: 여기에 return 문을 삽입합니다.
}

void BImage::DrawBitmap(HDC hdc, int x, int y, int width, int height) const
{
}

void BImage::DrawBitmapByCrop(HDC hdc, int x, int y, int width, int height, int sx, int sy, int sw, int sn) const
{
}

void BImage::SetTransparentColor(DWORD color)
{
}

DWORD BImage::GetTransparentColor()
{
	return 0;
}
