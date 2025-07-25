/**
 * @file tls13_misc.h
 * @brief TLS 1.3 helper functions
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

#ifndef _TLS13_MISC_H
#define _TLS13_MISC_H

//DHE key establishment
#ifndef TLS13_DHE_KE_SUPPORT
   #define TLS13_DHE_KE_SUPPORT ENABLED
#elif (TLS13_DHE_KE_SUPPORT != ENABLED && TLS13_DHE_KE_SUPPORT != DISABLED)
   #error TLS13_DHE_KE_SUPPORT parameter is not valid
#endif

//ECDHE key exchange support
#ifndef TLS13_ECDHE_KE_SUPPORT
   #define TLS13_ECDHE_KE_SUPPORT ENABLED
#elif (TLS13_ECDHE_KE_SUPPORT != ENABLED && TLS13_ECDHE_KE_SUPPORT != DISABLED)
   #error TLS13_ECDHE_KE_SUPPORT parameter is not valid
#endif

//ML-KEM key exchange support
#ifndef TLS13_MLKEM_KE_SUPPORT
   #define TLS13_MLKEM_KE_SUPPORT DISABLED
#elif (TLS13_MLKEM_KE_SUPPORT != ENABLED && TLS13_MLKEM_KE_SUPPORT != DISABLED)
   #error TLS13_MLKEM_KE_SUPPORT parameter is not valid
#endif

//Hybrid key exchange support
#ifndef TLS13_HYBRID_KE_SUPPORT
   #define TLS13_HYBRID_KE_SUPPORT DISABLED
#elif (TLS13_HYBRID_KE_SUPPORT != ENABLED && TLS13_HYBRID_KE_SUPPORT != DISABLED)
   #error TLS13_HYBRID_KE_SUPPORT parameter is not valid
#endif

//PSK-only key exchange support
#ifndef TLS13_PSK_KE_SUPPORT
   #define TLS13_PSK_KE_SUPPORT DISABLED
#elif (TLS13_PSK_KE_SUPPORT != ENABLED && TLS13_PSK_KE_SUPPORT != DISABLED)
   #error TLS13_PSK_KE_SUPPORT parameter is not valid
#endif

//PSK with DHE key exchange support
#ifndef TLS13_PSK_DHE_KE_SUPPORT
   #define TLS13_PSK_DHE_KE_SUPPORT ENABLED
#elif (TLS13_PSK_DHE_KE_SUPPORT != ENABLED && TLS13_PSK_DHE_KE_SUPPORT != DISABLED)
   #error TLS13_PSK_DHE_KE_SUPPORT parameter is not valid
#endif

//PSK with ECDHE key exchange support
#ifndef TLS13_PSK_ECDHE_KE_SUPPORT
   #define TLS13_PSK_ECDHE_KE_SUPPORT ENABLED
#elif (TLS13_PSK_ECDHE_KE_SUPPORT != ENABLED && TLS13_PSK_ECDHE_KE_SUPPORT != DISABLED)
   #error TLS13_PSK_ECDHE_KE_SUPPORT parameter is not valid
#endif

//PSK with ML-KEM key exchange support
#ifndef TLS13_PSK_MLKEM_KE_SUPPORT
   #define TLS13_PSK_MLKEM_KE_SUPPORT DISABLED
#elif (TLS13_PSK_MLKEM_KE_SUPPORT != ENABLED && TLS13_PSK_MLKEM_KE_SUPPORT != DISABLED)
   #error TLS13_PSK_MLKEM_KE_SUPPORT parameter is not valid
#endif

//PSK with hybrid key exchange support
#ifndef TLS13_PSK_HYBRID_KE_SUPPORT
   #define TLS13_PSK_HYBRID_KE_SUPPORT DISABLED
#elif (TLS13_PSK_HYBRID_KE_SUPPORT != ENABLED && TLS13_PSK_HYBRID_KE_SUPPORT != DISABLED)
   #error TLS13_PSK_HYBRID_KE_SUPPORT parameter is not valid
#endif

//Early data support
#ifndef TLS13_EARLY_DATA_SUPPORT
   #define TLS13_EARLY_DATA_SUPPORT DISABLED
#elif (TLS13_EARLY_DATA_SUPPORT != ENABLED && TLS13_EARLY_DATA_SUPPORT != DISABLED)
   #error TLS13_EARLY_DATA_SUPPORT parameter is not valid
#endif

//Middlebox compatibility mode
#ifndef TLS13_MIDDLEBOX_COMPAT_SUPPORT
   #define TLS13_MIDDLEBOX_COMPAT_SUPPORT ENABLED
#elif (TLS13_MIDDLEBOX_COMPAT_SUPPORT != ENABLED && TLS13_MIDDLEBOX_COMPAT_SUPPORT != DISABLED)
   #error TLS13_MIDDLEBOX_COMPAT_SUPPORT parameter is not valid
#endif

//Maximum size for cookies
#ifndef TLS13_MAX_COOKIE_SIZE
   #define TLS13_MAX_COOKIE_SIZE 256
#elif (TLS13_MAX_COOKIE_SIZE < 32)
   #error TLS13_MAX_COOKIE_SIZE parameter is not valid
#endif

//Maximum size for session tickets
#ifndef TLS13_MAX_TICKET_SIZE
   #define TLS13_MAX_TICKET_SIZE 1024
#elif (TLS13_MAX_TICKET_SIZE < 32)
   #error TLS13_MAX_TICKET_SIZE parameter is not valid
#endif

//Maximum lifetime of session tickets
#ifndef TLS13_MAX_TICKET_LIFETIME
   #define TLS13_MAX_TICKET_LIFETIME 604800
#elif (TLS13_MAX_TICKET_LIFETIME < 0)
   #error TLS13_MAX_TICKET_LIFETIME parameter is not valid
#endif

//Age tolerance for tickets, in milliseconds
#ifndef TLS13_TICKET_AGE_TOLERANCE
   #define TLS13_TICKET_AGE_TOLERANCE 5000
#elif (TLS13_TICKET_AGE_TOLERANCE < 0)
   #error TLS13_TICKET_AGE_TOLERANCE parameter is not valid
#endif

//Number of NewSessionTicket message sent by the server
#ifndef TLS13_NEW_SESSION_TICKET_COUNT
   #define TLS13_NEW_SESSION_TICKET_COUNT 2
#elif (TLS13_NEW_SESSION_TICKET_COUNT < 0)
   #error TLS13_NEW_SESSION_TICKET_COUNT parameter is not valid
#endif

//Maximum size for HKDF digests
#if (TLS_SHA384_SUPPORT == ENABLED)
   #define TLS13_MAX_HKDF_DIGEST_SIZE 48
#else
   #define TLS13_MAX_HKDF_DIGEST_SIZE 32
#endif

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief PSK key exchange modes
 **/

typedef enum
{
   TLS_PSK_KEY_EXCH_MODE_PSK_KE     = 0,
   TLS_PSK_KEY_EXCH_MODE_PSK_DHE_KE = 1
} Tls13PskKeyExchMode;


/**
 * @brief Key update requests
 **/

typedef enum
{
   TLS_KEY_UPDATE_NOT_REQUESTED = 0,
   TLS_KEY_UPDATE_REQUESTED     = 1
} Tls13KeyUpdateRequest;


//CC-RX, CodeWarrior or Win32 compiler?
#if defined(__CCRX__)
   #pragma pack
#elif defined(__CWCC__) || defined(_WIN32)
   #pragma pack(push, 1)
#endif


/**
 * @brief Cookie
 **/

typedef __packed_struct
{
   uint16_t length; //0-1
   uint8_t value[]; //2
} Tls13Cookie;


/**
 * @brief Key share entry
 **/

typedef __packed_struct
{
   uint16_t group;        //0
   uint16_t length;       //1
   uint8_t keyExchange[]; //2
} Tls13KeyShareEntry;


/**
 * @brief List of key shares
 **/

typedef __packed_struct
{
   uint16_t length; //0
   uint8_t value[]; //1
} Tls13KeyShareList;


/**
 * @brief List of PSK key exchange modes
 **/

typedef __packed_struct
{
   uint8_t length;  //0
   uint8_t value[]; //1
} Tls13PskKeModeList;


/**
 * @brief PSK identity
 **/

typedef __packed_struct
{
   uint16_t length; //0-1
   uint8_t value[]; //2
} Tls13PskIdentity;


/**
 * @brief List of PSK identities
 **/

typedef __packed_struct
{
   uint16_t length; //0-1
   uint8_t value[]; //2
} Tls13PskIdentityList;


/**
 * @brief PSK binder
 **/

typedef __packed_struct
{
   uint8_t length;  //0
   uint8_t value[]; //1
} Tls13PskBinder;


/**
 * @brief List of PSK binders
 **/

typedef __packed_struct
{
   uint16_t length; //0-1
   uint8_t value[]; //2
} Tls13PskBinderList;


/**
 * @brief Certificate request context
 **/

typedef __packed_struct
{
   uint8_t length; //0
   uint8_t value[]; //1
} Tls13CertRequestContext;


/**
 * @brief Digitally-signed element (TLS 1.3)
 **/

typedef __packed_struct
{
   uint16_t algorithm; //0-1
   uint16_t length;    //2-3
   uint8_t value[];    //4
} Tls13DigitalSignature;


/**
 * @brief HelloRetryRequest message
 **/

typedef __packed_struct
{
   uint16_t serverVersion; //0-1
   uint8_t random[32];     //2-33
   uint8_t sessionIdLen;   //34
   uint8_t sessionId[];    //35
} Tls13HelloRetryRequest;


/**
 * @brief EndOfEarlyData message
 **/

typedef void *Tls13EndOfEarlyData;


/**
 * @brief EncryptedExtensions message
 **/

typedef __packed_struct
{
   uint16_t extensionsLen; //0-1
   uint8_t extensions[];   //2
} Tls13EncryptedExtensions;


/**
 * @brief NewSessionTicket message (TLS 1.3)
 **/

typedef __packed_struct
{
   uint32_t ticketLifetime; //0-3
   uint32_t ticketAgeAdd;   //4-7
   uint8_t ticketNonceLen;  //8
   uint8_t ticketNonce[];   //9
} Tls13NewSessionTicket;


/**
 * @brief KeyUpdate message
 **/

typedef __packed_struct
{
   uint8_t requestUpdate; //0
} Tls13KeyUpdate;


/**
 * @brief Session ticket
 **/

typedef __packed_struct
{
   uint16_t length; //0-1
   uint8_t data[];  //2
} Tls13Ticket;


/**
 * @brief Session state information
 **/

typedef __packed_struct
{
   uint16_t version;                              ///<Protocol version
   uint16_t cipherSuite;                          ///<Cipher suite identifier
   systime_t ticketTimestamp;                     ///<Timestamp to manage ticket lifetime
   uint32_t ticketLifetime;                       ///<Lifetime of the ticket
   uint32_t ticketAgeAdd;                         ///<Random value used to obscure the age of the ticket
   uint8_t ticketNonce[4];                        ///<A per-ticket value that is unique across all tickets issued
   size_t ticketPskLen;                           ///<Length of the PSK associated with the ticket
   uint8_t ticketPsk[TLS13_MAX_HKDF_DIGEST_SIZE]; ///<PSK associated with the ticket
} Tls13PlaintextSessionState;


//CC-RX, CodeWarrior or Win32 compiler?
#if defined(__CCRX__)
   #pragma unpack
#elif defined(__CWCC__) || defined(_WIN32)
   #pragma pack(pop)
#endif

//TLS 1.3 related constants
extern const uint8_t tls11DowngradeRandom[8];
extern const uint8_t tls12DowngradeRandom[8];
extern const uint8_t tls13HelloRetryRequestRandom[32];

//TLS 1.3 related functions
error_t tls13ComputePskBinder(TlsContext *context, const void *clientHello,
   size_t clientHelloLen, size_t truncatedClientHelloLen,
   const Tls13PskIdentity *identity, uint8_t *binder, size_t binderLen);

error_t tls13GenerateKeyShare(TlsContext *context, uint16_t namedGroup);

error_t tls13GenerateSharedSecret(TlsContext *context, const uint8_t *keyShare,
   size_t length);

error_t tls13Encapsulate(TlsContext *context, uint16_t namedGroup,
   const uint8_t *keyShare, size_t length);

error_t tls13Decapsulate(TlsContext *context, const uint8_t *keyShare,
   size_t length);

error_t tls13ComputeMac(TlsContext *context, TlsEncryptionEngine *encryptionEngine,
   void *record, const uint8_t *data, size_t dataLen, uint8_t *mac);

error_t tls13DigestClientHello1(TlsContext *context);

bool_t tls13IsPskValid(TlsContext *context);

bool_t tls13IsGroupSupported(TlsContext *context, uint16_t namedGroup);
bool_t tls13IsFfdheGroupSupported(TlsContext *context, uint16_t namedGroup);
bool_t tls13IsEcdheGroupSupported(TlsContext *context, uint16_t namedGroup);
bool_t tls13IsMlkemGroupSupported(TlsContext *context, uint16_t namedGroup);
bool_t tls13IsHybridGroupSupported(TlsContext *context, uint16_t namedGroup);

const KemAlgo *tls13GetMlkemAlgo(TlsContext *context, uint16_t namedGroup);

const EcCurve *tls13GetTraditionalAlgo(TlsContext *context,
   uint16_t namedGroup);

const KemAlgo *tls13GetNextGenAlgo(TlsContext *context, uint16_t namedGroup);

error_t tls13CheckDuplicateKeyShare(uint16_t namedGroup, const uint8_t *p,
   size_t length);

error_t tls13FormatCertExtensions(uint8_t *p, size_t *written);

error_t tls13ParseCertExtensions(const uint8_t *p, size_t length,
   size_t *consumed);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
