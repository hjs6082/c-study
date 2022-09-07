#include "BImage.h"

//���� png ������ ����ʹٸ� ���ͳݿ��� gdi plus	

DWORD BImage::m_TransparentColor = RGB(255, 0, 255); //����ƽ ��� ���� �ʱ�ȭ


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
		DeleteObject(m_BitmapHandle); //��Ʈ���� �����ϸ� �����ش�.
	}
}

bool BImage::Load(const TCHAR* strLoadFile)
{
	/* 
	LoadImage�� �Ķ���ʹ� ������ ����.
	HINSTANCE, �����̸�, Ÿ��, x,y,�ε�ɼ�
	Ÿ�� : IMAGE_BITMAP(0), IMAGE_CURSOR(2), IMAGE_ICON(1)
	x,y : �̹����� ũ�⸦ ���ϴµ� ���࿡ �� ���� ���� 0�̸鼭 LR_DEfAuLTSIZE�� �ɼ����� ����
	�ý����� SM_CXICON�� �̿��ؼ� ũ�⸦ �����ϰ� �ǰ�
	���� LR_DEFAULT_SIZE�� �����Ǿ����� �ʴٸ� ���ҽ��� ���� ũ��� �ε�ȴ�.
	
	DIB = Device-Independent Bitmap : ��� ������ ��Ʈ��, ���������̺��� ������� ��Ʈ��
	LR_LOADFROMFILE : ���ҽ� ��� ���� ��θ� �̿��Ͽ� �ҷ��ð��̴�.
	
	GetModuleHandle => Module�� ���� �ν��Ͻ� �ڵ�, dll�̳� exe�� ����� �ϰ� �Ǵµ�
	���⼭�� nullptr�� ������ ���� �ν��Ͻ��� �ڵ��� �Ѿ��.
	*/

	m_BitmapHandle = (HBITMAP)LoadImage(GetModuleHandle(nullptr), strLoadFile, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);

	if (this->IsEmpty())
	{
		return false;
	}

	//�ε� �����ߴٸ�
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
	return m_BitmapHandle == NULL; // ���⼱ nullptr�� ���� ������ �߻���.
}

HBITMAP BImage::GetBitmapHandle() const
{
	return HBITMAP();
}

const BITMAP& BImage::GetBitmapInfo() const
{
	// TODO: ���⿡ return ���� �����մϴ�.
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
