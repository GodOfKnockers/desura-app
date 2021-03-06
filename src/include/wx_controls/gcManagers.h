/*
Copyright (C) 2011 Mark Chandler (Desura Net Pty Ltd)
Copyright (C) 2014 Bad Juju Games, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.

Contact us at legal@badjuju.com.
*/

#ifndef DESURA_GCMANAGERS_H
#define DESURA_GCMANAGERS_H
#ifdef _WIN32
#pragma once
#endif

#include <wx/wx.h>
#include "wx_controls/gcImageHandle.h"
#include "managers/Managers.h"


class gcThemeManagerI : public ThemeManagerI
{
public:
	//! Gets image handle. Alpha refers to if the image has transperency
	//!
	virtual gcImageHandle getImageHandle(const char* path)=0;

	//! Gets a sprite from an image
	//!
	virtual wxBitmap getSprite(wxImage& img, const char* spriteId, const char* spriteName)=0;

protected:
	virtual void newImgHandle(uint32 hash)=0;
	virtual void desposeImgHandle(uint32 hash)=0;

	friend class gcImageHandle;
};


gcThemeManagerI* GetGCThemeManager();


extern wxWindow*		GetMainWindow();
extern void				ExitApp();


#endif //DESURA_GCMANAGERS_H
