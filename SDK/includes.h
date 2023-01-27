#include <Windows.h>
#include <fstream>
#include <tchar.h>
#include <random>
#include <ctime>
#include <Windows.h>
#include "Color.h"
#include "Radius.h"
#include "Position.h"
#define and &&
#define or ||
#define not !
#include "Detours.h"
#include <gl/gl.h> 
#include "glDraw.h"
#include "gltext.h"
#include <stdio.h>
#include <iostream>
#include <mutex>
#pragma comment(lib,"opengl32.lib")
#define KEY_X 0x58
#define KEY_V 0x56
#define KEY_B 0x42

#define KEY_B_DOWN 3145729
#define KEY_B_UP 3224371201
#define KEY_V_DOWN 3080193
#define KEY_V_UP 3224305665
#define KEY_X_DOWN 2949121
#define KEY_X_UP 3224174593
#pragma once
typedef void(__stdcall* T_glEnable)(GLenum);
typedef void(__stdcall* T_glDisable)(GLenum);
typedef BOOL(__stdcall* T_SwapBuffers)(HDC);
typedef void(__stdcall* T_glScalef)(float, float, float);
typedef void(__stdcall* T_glTranslatef)(float, float, float);
typedef void(__stdcall* T_glOrtho)(double, double, double, double, double, double);
Position chest;
Position entity;
Position largeChest;
T_glEnable pglEnable = nullptr;
T_glDisable pglDisable = nullptr;
T_glOrtho pglOrtho = nullptr;
T_glScalef pglScalef = nullptr;
T_SwapBuffers pSwapBuffers = nullptr;
T_glTranslatef pglTranslatef = nullptr;
GL::Font glFont;
HHOOK keyHookHandle = nullptr;
using namespace std;
bool hud = false;
bool esp = false;
bool chestesp = false;
bool wallhacks = false;
bool sChest = false;
bool sPlayer = false;
bool sNickname = false;
bool sInventory = false;
const int FONT_HEIGHT = 15;
const int FONT_WIDTH = 9;
int red = 0;
int green = 0;
int blue = 0;
int alpha = 0;