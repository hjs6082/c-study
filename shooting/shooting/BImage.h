#pragma once

#include "BBasicStd.h"

class BImage
{
	BImage();
	BImage(const TCHAR* strLoadFile);
	//w_char_t�� TCHAR�� ��ȯ �ÿ��� �ݵ�� const�� �ٿ��ֵ��� �Ǿ� �ִ�.
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

	bool IsEmpty() const; //�޼��� �ڿ� const�� ���̸� �ش� �޼���� Ŭ���� ������ ������ �������� ���Ѵ�.�ַ� getter � ����
	HBITMAP GetBitmapHandle() const;
	const BITMAP& GetBitmapInfo() const;

	void DrawBitmap(HDC hdc, int x, int y, int width, int height) const;
	void DrawBitmapByCrop(HDC hdc, int x, int y, int width, int height, int sx, int sy, int sw, int sn) const;

private:
	static DWORD m_TransparentColor; //����� rgb(255,0,255)�� ��� ����

public:
	static void SetTransparentColor(DWORD color);
	static DWORD GetTransparentColor();
};

