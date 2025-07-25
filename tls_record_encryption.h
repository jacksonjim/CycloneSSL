/**
 * @file tls_record_encryption.h
 * @brief TLS record encryption
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

#ifndef _TLS_RECORD_ENCRYPTION_H
#define _TLS_RECORD_ENCRYPTION_H

//Dependencies
#include "tls.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//TLS related functions
error_t tlsEncryptRecord(TlsContext *context,
   TlsEncryptionEngine *encryptionEngine, void *record);

error_t tlsEncryptAeadRecord(TlsContext *context,
   TlsEncryptionEngine *encryptionEngine, void *record);

error_t tlsEncryptCbcRecord(TlsContext *context,
   TlsEncryptionEngine *encryptionEngine, void *record);

error_t tlsEncryptStreamRecord(TlsContext *context,
   TlsEncryptionEngine *encryptionEngine, void *record);

error_t tlsAppendMessageAuthCode(TlsContext *context,
   TlsEncryptionEngine *decryptionEngine, void *record);

error_t tlsComputeMac(TlsContext *context, TlsEncryptionEngine *encryptionEngine,
   const void *record, const uint8_t *data, size_t dataLen, uint8_t *mac);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
