/**
 * @file tls_sign_verify.h
 * @brief RSA/DSA/ECDSA/EdDSA signature verification
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
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
 * @version 2.4.2
 **/

#ifndef _TLS_SIGN_VERIFY_H
#define _TLS_SIGN_VERIFY_H

//Dependencies
#include "tls.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//TLS related functions
error_t tlsVerifySignature(TlsContext *context, const uint8_t *p,
   size_t length);

error_t tls12VerifySignature(TlsContext *context, const uint8_t *p,
   size_t length);

error_t tlsVerifyRsaSignature(const RsaPublicKey *key,
   const uint8_t *digest, const uint8_t *signature, size_t signatureLen);

error_t tlsVerifyRsaEm(const uint8_t *digest, const uint8_t *em, size_t emLen);

error_t tlsVerifyDsaSignature(TlsContext *context, const uint8_t *digest,
   size_t digestLen, const uint8_t *signature, size_t signatureLen);

error_t tlsVerifyEcdsaSignature(TlsContext *context, const uint8_t *digest,
   size_t digestLen, const uint8_t *signature, size_t signatureLen);

error_t tlsVerifyEd25519Signature(TlsContext *context,
   const EddsaMessageChunk *messageChunks, const uint8_t *signature,
   size_t signatureLen);

error_t tlsVerifyEd448Signature(TlsContext *context,
   const EddsaMessageChunk *messageChunks, const uint8_t *signature,
   size_t signatureLen);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
