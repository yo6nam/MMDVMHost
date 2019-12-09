/*
 *   Copyright (C) 2019 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef	RemoteControl_H
#define	RemoteControl_H

#include "UDPSocket.h"

#include <vector>
#include <string>

enum REMOTE_COMMAND {
	RCD_NONE,
	RCD_MODE_IDLE,
	RCD_MODE_LOCKOUT,
	RCD_MODE_DSTAR,
	RCD_MODE_DMR,
	RCD_MODE_YSF,
	RCD_MODE_P25,
	RCD_MODE_NXDN,
	RCD_PAGE
};

class CRemoteControl {
public:
	CRemoteControl(unsigned int port);
	~CRemoteControl();

	bool open();

	REMOTE_COMMAND getCommand();

	unsigned int getArgCount() const;

	std::string  getArgString(unsigned int n) const;
	unsigned int getArgUInt(unsigned int n) const;
	signed int   getArgInt(unsigned int n) const;

	void close();

private:
	CUDPSocket               m_socket;
	REMOTE_COMMAND           m_command;
	std::vector<std::string> m_args;
};

#endif
