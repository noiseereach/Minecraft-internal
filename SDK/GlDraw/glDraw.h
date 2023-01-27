#pragma once
#pragma comment(lib, "OpenGL32.lib")
#include <Windows.h>
#include <stdio.h>
#include <gl\GL.h>

namespace rgb
{
	const GLubyte red[3] = { 255,0,0 };
	const GLubyte gray[3] = { 55,55,55 };
	const GLubyte lightgray[3] = { 173,173,173 };
	const GLubyte white[3] = { 255,255,255};
	const GLubyte black[3] = { 0,0,0 };
	const GLubyte green[3] = { 0,173,0 };
	const GLubyte yellow[3] = { 240, 220, 130 };
	const GLubyte mero[3] = { 188, 185, 184 };
}

namespace GL
{
	void SetupOrtho();
	void RestoreGL();
	void drawRectangle(float x, float y, float width, float height);
}