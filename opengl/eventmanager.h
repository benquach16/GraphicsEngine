#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include "iostream"

#pragma once

//mostly used as a hash function for an array really
enum E_KEY_TYPES
{
	E_KEY_0 = 0,
	E_KEY_1 = 1,
	E_KEY_2 = 2,
	E_KEY_3 = 3,
	E_KEY_4 = 4,
	E_KEY_5 = 5,
	E_KEY_6 = 6,
	E_KEY_7 = 7,
	E_KEY_8 = 8,
	E_KEY_9 = 9,
	E_KEY_A = 10,
	E_KEY_B = 11,
	E_KEY_C = 12,
	E_KEY_D = 13,
	E_KEY_E = 14,
	E_KEY_F = 15,
	E_KEY_G = 16,
	E_KEY_H = 17,
	E_KEY_I = 18,
	E_KEY_J = 19,
	E_KEY_K = 20,
	E_KEY_L = 21,
	E_KEY_M = 22,
	E_KEY_N = 23,
	E_KEY_O = 24,
	E_KEY_P = 25,
	E_KEY_Q = 26,
	E_KEY_R = 27,
	E_KEY_S = 28,
	E_KEY_T = 29,
	E_KEY_U = 30,
	E_KEY_V = 31,
	E_KEY_W = 32,
	E_KEY_X = 33,
	E_KEY_Y = 34,
	E_KEY_Z = 35,
	E_KEY_TILDE = 36,
	E_KEY_MINUS = 37,
	E_KEY_PLUS = 38,
	E_KEY_BACKSPACE = 39,
	E_KEY_TAB = 40,
	E_KEY_LEFT_BRACKET = 41,
	E_KEY_RIGHT_BRACKET = 42,
	E_KEY_BACKSLASH = 43,
	E_KEY_SEMICOLON = 44,
	E_KEY_APOSTROPHE = 45,
	E_KEY_ENTER = 46,
	E_KEY_LEFT = 47,
	E_KEY_UP = 48,
	E_KEY_RIGHT = 49,
	E_KEY_DOWN = 50
};

class CEventManager
{
public:
	CEventManager();
	bool getKeyState(E_KEY_TYPES key_code);
	//the actual listen code
	void capture();
	void windowsKeyHook(const bool *win_keys);
	~CEventManager();

protected:
	void setKeyState(unsigned char key);

	bool keys[256];
};

#endif