#include "stdafx.h"
#include "eventmanager.h"

CEventManager::CEventManager()
{
	for(unsigned i = 0; i< 256; i++)
	{
		keys[i] = false;
	}
}

CEventManager::~CEventManager()
{

}

void CEventManager::capture()
{

}

bool CEventManager::getKeyState(E_KEY_TYPES key_code)
{
	return keys[key_code];
}

void CEventManager::windowsKeyHook(const bool *win_keys)
{
	//get windows key input
	for(unsigned i = 0; i < 256; i++)
	{
		keys[i] = win_keys[i];
	}
}