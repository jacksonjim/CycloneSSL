/**
 * @file tls_extensions.h
 * @brief Parsing and checking of TLS extensions
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneSSL Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.5.2
 **/

#ifndef _TLS_EXTENSIONS_H
#define _TLS_EXTENSIONS_H

//Dependencies
#include "tls.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//TLS related functions
error_t tlsParseHelloExtensions(TlsMessageType msgType, const uint8_t *p,
   size_t length, TlsHelloExtensions *extensions);

error_t tlsCheckHelloExtensions(TlsMessageType msgType, uint16_t version,
   TlsHelloExtensions *extensions);

error_t tlsCheckDuplicateExtension(uint16_t type, const uint8_t *p,
   size_t length);

bool_t tlsIsAlpnProtocolSupported(TlsContext *context,
   const char_t *protocol, size_t length);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
