// Copyright 2011 Juri Glass, Mathias Runge, Nadim El Sayed 
// DAI-Labor, TU-Berlin
// 
// This file is part of libSML.
// 
// libSML is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// libSML is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with libSML.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _SML_TRANSPORT_H
#define	_SML_TRANSPORT_H

#include <stdlib.h>
#include <sml/sml_file.h>

#ifdef __cplusplus
extern "C" {
#endif

// sml_transport_listen reads continously bytes from fd and scans 
// for the SML transport protocol escape sequences. If a SML file
// is detected, the sml_transporter_receiver is called with the 
// complete bytes, including the escape sequences.
// The buffer is free'd after the sml_transport_receiver comes 
// back.
void sml_transport_listen(int fd, void (*sml_transport_receiver)(unsigned char *buffer, size_t buffer_len));

// sml_transport_writes adds the SML transport protocol escape 
// sequences and writes the given file to fd. The file must be 
// in the parsed format.
// The number of bytes written is returned, 0 if there was an
// error.
// The sml_file must be free'd elsewhere.
int sml_transport_write(int fd, sml_file *file);

#ifdef __cplusplus
}
#endif

#endif

