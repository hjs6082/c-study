#pragma once

#include "BBasicStd.h"

class BImage
{
	BImage();
	BImage(const TCHAR* strLoadFile);
	//w_char_t를 TCHAR로 변환 시에는 반드시 const를 붙여주도록 되어 있다.
	~BImage();

protected:
	HBITMAP m_BitmapHandle;
	BITMAP m_BitmapInfo;
	double m_rotateAngle = 0;
	
public:
	bool Load(const TCHAR* strLoadFile);
	bool Load(HBITMAP bitmapHandle);
	bool Release();
	void SetRotate(double value);

	bool IsEmpty() const; //메서드 뒤에 const를 붙이면 해당 메서드는 클래스 내부의 변수를 변경하지 못한다.주로 getter 등에 쓰임
	HBITMAP GetBitmapHandle() const;
	const BITMAP& GetBitmapInfo() const;

	void DrawBitmap(HDC hdc, int x, int y, int width, int height) const;
	void DrawBitmapByCrop(HDC hdc, int x, int y, int width, int height, int sx, int sy, int sw, int sn) const;

private:
	static DWORD m_TransparentColor; //투명색 rgb(255,0,255)를 사용 예정

public:
	static void SetTransparentColor(DWORD color);
	static DWORD GetTransparentColor();
};

