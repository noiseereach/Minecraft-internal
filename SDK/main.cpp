#include "includes.h"
//-*-*-*-*-*-*
// thanks for this code
//https://t.me/aurenex
//https://youtube.com/c/NoiseReach
//-*-*-*-*-*-*
LRESULT __stdcall keyHandler(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode < 0)
	{
		return CallNextHookEx(keyHookHandle, nCode, wParam, lParam);
	}

	if (lParam == KEY_X_UP)
	{
		wallhacks = !wallhacks;
	}
	if (lParam == KEY_B_UP)
	{
		chestesp = !chestesp;
	}

	if (lParam == KEY_V_UP)
	{
		esp = !esp;
	}


	return CallNextHookEx(keyHookHandle, nCode, wParam, lParam);
}
DWORD __stdcall keyDispatcher(LPVOID thread)
{
	keyHookHandle = SetWindowsHookEx(WH_KEYBOARD, keyHandler, GetModuleHandle(nullptr), *reinterpret_cast<DWORD*>(thread));

	if (!keyHookHandle)
	{
		return GetLastError();
	}

	MSG message{};

	while (GetMessage(&message, 0, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return 0;
}
void draw(Position& position, Radius radius, Color boxColor, bool drawLine)
{
	for (int i = 0; i < position.modelview.size(); i += 16)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(position.projection.data() + i);

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(position.modelview.data() + i);

		glLineWidth(2.0F);
		glColor4f(boxColor.red, boxColor.green, boxColor.blue, 1.0F);

		glBegin(GL_LINES);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glEnd();

		glColor4f(boxColor.red, boxColor.green, boxColor.blue, 0.2F);

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glEnd();

		if (!drawLine)
		{
			continue;
		}

		glLoadIdentity();

		glColor4f(1.0F, 1.0F, 1.0F, 0.3F);

		glBegin(GL_LINES);
		glVertex3f(0, 0, -0.1F);
		glVertex3f((position.modelview.data() + i)[12], (position.modelview.data() + i)[13], (position.modelview.data() + i)[14]);
		glEnd();
	}

	position.projection.clear();
	position.modelview.clear();
}
void savePosition(Position& position, float offsetX, float offsetY, float offsetZ)
{
	float projection[16]{};
	glGetFloatv(GL_PROJECTION_MATRIX, projection);

	float modelview[16]{};
	glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

	float m3[4]{};

	for (int i = 0; i < 4; ++i)
	{
		m3[i] = modelview[i] * offsetX
			+ modelview[i + 4] * offsetY
			+ modelview[i + 8] * offsetZ
			+ modelview[i + 12];
	}

	memcpy(modelview + 12, m3, sizeof(m3));

	position.projection.insert(position.projection.end(), begin(projection), end(projection));
	position.modelview.insert(position.modelview.end(), begin(modelview), end(modelview));
}
void DrawHud()
{
	HDC currentHDC = wglGetCurrentDC();


	if (!glFont.bBuilt || currentHDC != glFont.hdc)
	{
		glFont.Build(FONT_HEIGHT);
	}

	int viewport[4]{};
	glGetIntegerv(GL_VIEWPORT, viewport);

	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(viewport[0], viewport[2], viewport[3], viewport[1], -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GL::SetupOrtho();
	glColor4f(0.0f, 0.0f, 0.0f, 0.4f);

	GL::drawRectangle(0, 0, 199, 105);
	GL::drawRectangle(0, 0, 199, 21);
	glPopAttrib();

	glFont.Print(0, 15, rgb::green, "|");
	glFont.Print(7, 15, rgb::green, "N");
	glFont.Print(15, 15, rgb::white, "oise | Universal Xray");
	glFont.Print(0, 93, rgb::mero, "-little gui update ");
	if (wallhacks)
	{
		glFont.Print(2, 35, rgb::green, "Xray [X]");
	}
	else
	{
		glFont.Print(2, 35, rgb::red, "Xray [X]");
	}
	if (esp)
	{
		glFont.Print(2, 54, rgb::green, "Esp [V]");
	}
	else
	{
		glFont.Print(2, 54, rgb::red, "Esp [V]");
	}
	if (chestesp)
	{
		glFont.Print(2, 73, rgb::green, "ChestEsp [B]");
	}
	else
	{
		glFont.Print(2, 73, rgb::red, "ChestEsp [B]");
	}
	float modelview[16];

	glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

	GL::RestoreGL();
	glColor3f(1, 0, 0);
}
BOOL __stdcall mySwapBuffers(HDC hDC)
{
	DrawHud();
	static DWORD windowThread = 0;
	if (!windowThread)
	{
		HWND window = WindowFromDC(hDC);

		windowThread = GetWindowThreadProcessId(window, nullptr);

		if (!windowThread)
		{
			return pSwapBuffers(hDC);
		}

		CreateThread(nullptr, 0, keyDispatcher, reinterpret_cast<LPVOID>(&windowThread), 0, nullptr);
	}
	glDepthFunc(GL_LEQUAL);

	if (wallhacks) {
		glDepthFunc(GL_ALWAYS);
	}
	sInventory = false;
	return pSwapBuffers(hDC);
}
void __stdcall myglOrtho(double left, double right, double bottom, double top, double zNear, double zFar)
{
	if (zNear == 1000 and zFar == 3000)
	{
		sInventory = true;

		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);

		glEnable(GL_LINE_SMOOTH);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		if (esp) {
			draw(entity, Radius(0.8F, 2.0F, 0.8F), Color(0.5f, 1.0f, 1.0f), true);
		}
		if (chestesp) {
			draw(chest, Radius(1.0F, 1.0F, 1.0F), Color(1.0f, 0.5f, 0.0f), false);
			draw(largeChest, Radius(2.0F, 1.0F, 1.0F), Color(1.0f, 0.5f, 0.0f), false);
		}

		glPopAttrib();
		glPopMatrix();
	}

	pglOrtho(left, right, bottom, top, zNear, zFar);
}
void __stdcall myglTranslatef(float x, float y, float z)
{
	pglTranslatef(x, y, z);

	if (sInventory)
	{
		return;
	}

	// Chest
	if (x == 0.5 and y == 0.4375 and z == 0.9375)
	{
		savePosition(chest, 0.0F, 0.0625F, -0.4375F);
	}

	// Large chest
	if (x == 1 and y == 0.4375 and z == 0.9375)
	{
		savePosition(largeChest, 0.0F, 0.0625F, -0.4375F);
	}
}
void __stdcall myglScalef(float x, float y, float z)
{
	pglScalef(x, y, z);

	if (sInventory)
	{
		return;
	}

	if (x == 1 and y == -1 and z == -1)
	{
		sChest = true;
	}

	// Entity
	if (x == 0.9375 and y == 0.9375 and z == 0.9375)
	{
		sPlayer = true;
		savePosition(entity, 0.0F, -1.0F, 0.0F);
	}
}
void __stdcall myglEnable(unsigned int cap)
{
	pglEnable(cap);

	if (cap == GL_LIGHTING and sNickname)
	{
		glDisable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1, 1100000);

		sNickname = false;
	}

	pglEnable(cap);
}
void __stdcall myglDisable(unsigned int cap)
{
	pglDisable(cap);

	if (cap == 0x0000803A)
	{
		if (sChest or sPlayer)
		{
			if (sChest)
			{
				sChest = false;
			}

			if (sPlayer)
			{
				sPlayer = false;
			}

			glDisable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1, 1100000);
		}
	}
}
BOOL __stdcall DllMain(HINSTANCE handle, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
	{
		HMODULE handle = GetModuleHandleW(L"OpenGL32.dll");

		if (!handle)
		{
			return FALSE;
		}

		pglEnable = reinterpret_cast<T_glEnable>(GetProcAddress(handle, "glEnable"));
		pglDisable = reinterpret_cast<T_glDisable>(GetProcAddress(handle, "glDisable"));

		pSwapBuffers = reinterpret_cast<T_SwapBuffers>(GetProcAddress(handle, "wglSwapBuffers"));
		pglOrtho = reinterpret_cast<T_glOrtho>(GetProcAddress(handle, "glOrtho"));
		pglScalef = reinterpret_cast<T_glScalef>(GetProcAddress(handle, "glScalef"));
		pglTranslatef = reinterpret_cast<T_glTranslatef>(GetProcAddress(handle, "glTranslatef"));
		DetourRestoreAfterWith();
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<void**>(&pglEnable), myglEnable);
		DetourAttach(reinterpret_cast<void**>(&pglDisable), myglDisable);
		DetourAttach(reinterpret_cast<void**>(&pglOrtho), myglOrtho);
		DetourAttach(reinterpret_cast<void**>(&pSwapBuffers), mySwapBuffers);
		DetourAttach(reinterpret_cast<void**>(&pglTranslatef), myglTranslatef);
		DetourAttach(reinterpret_cast<void**>(&pglScalef), myglScalef);
		return DetourTransactionCommit() == NO_ERROR;
	}

	break;

	case DLL_PROCESS_DETACH:
	{
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(reinterpret_cast<void**>(&pglEnable), myglEnable);
		DetourDetach(reinterpret_cast<void**>(&pglDisable), myglDisable);
		DetourDetach(reinterpret_cast<void**>(&pglOrtho), myglOrtho);
		DetourDetach(reinterpret_cast<void**>(&pSwapBuffers), mySwapBuffers);
		DetourDetach(reinterpret_cast<void**>(&pglTranslatef), myglTranslatef);
		DetourDetach(reinterpret_cast<void**>(&pglScalef), myglScalef);
		return DetourTransactionCommit() == NO_ERROR;
	}
	}

	return TRUE;
}
