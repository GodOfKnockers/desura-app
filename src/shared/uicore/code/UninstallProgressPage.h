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

#ifndef DESURA_UFPROGRESSPAGE_H
#define DESURA_UFPROGRESSPAGE_H
#ifdef _WIN32
#pragma once
#endif

#include "BaseInstallPage.h"
#include "wx_controls/gcControls.h"
#include "wx_controls/gcSpinnerProgBar.h"
#include "mcfcore/ProgressInfo.h"


namespace UI
{
namespace Forms
{
namespace ItemFormPage
{

class UninstallProgressPage : public BaseInstallPage
{
public:
	UninstallProgressPage(wxWindow* parent, wxString label);
	~UninstallProgressPage();

	virtual void init();

protected:
	gcStaticText* m_labInfo;
	gcSpinnerProgBar* m_pbProgress;
	gcButton* m_butClose;

	virtual void onComplete(uint32&);
	virtual void onError(gcException& e);
	virtual void onMcfProgress(MCFCore::Misc::ProgressInfo& info);

	void onButtonClicked( wxCommandEvent& event );
	void completeUninstall();

private:
	bool m_bRemoveAll;
	bool m_bRemoveAcc;
};

}
}
}

#endif //DESURA_UFPROGRESSPAGE_H
