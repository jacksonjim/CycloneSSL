/**
 * @file tls_ffdhe.c
 * @brief FFDHE key exchange
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

//Switch to the appropriate trace level
#define TRACE_LEVEL TLS_TRACE_LEVEL

//Dependencies
#include "tls.h"
#include "tls_ffdhe.h"
#include "debug.h"

//Check TLS library configuration
#if (TLS_SUPPORT == ENABLED && TLS_FFDHE_SUPPORT == ENABLED)

#if (TLS_FFDHE2048_SUPPORT == ENABLED)

/**
 * @brief ffdhe2048 group
 **/

const TlsFfdheGroup ffdhe2048Group =
{
   //Group name
   "ffdhe2048",
   //Prime modulus
   {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAD, 0xF8, 0x54, 0x58, 0xA2, 0xBB, 0x4A, 0x9A,
    0xAF, 0xDC, 0x56, 0x20, 0x27, 0x3D, 0x3C, 0xF1, 0xD8, 0xB9, 0xC5, 0x83, 0xCE, 0x2D, 0x36, 0x95,
    0xA9, 0xE1, 0x36, 0x41, 0x14, 0x64, 0x33, 0xFB, 0xCC, 0x93, 0x9D, 0xCE, 0x24, 0x9B, 0x3E, 0xF9,
    0x7D, 0x2F, 0xE3, 0x63, 0x63, 0x0C, 0x75, 0xD8, 0xF6, 0x81, 0xB2, 0x02, 0xAE, 0xC4, 0x61, 0x7A,
    0xD3, 0xDF, 0x1E, 0xD5, 0xD5, 0xFD, 0x65, 0x61, 0x24, 0x33, 0xF5, 0x1F, 0x5F, 0x06, 0x6E, 0xD0,
    0x85, 0x63, 0x65, 0x55, 0x3D, 0xED, 0x1A, 0xF3, 0xB5, 0x57, 0x13, 0x5E, 0x7F, 0x57, 0xC9, 0x35,
    0x98, 0x4F, 0x0C, 0x70, 0xE0, 0xE6, 0x8B, 0x77, 0xE2, 0xA6, 0x89, 0xDA, 0xF3, 0xEF, 0xE8, 0x72,
    0x1D, 0xF1, 0x58, 0xA1, 0x36, 0xAD, 0xE7, 0x35, 0x30, 0xAC, 0xCA, 0x4F, 0x48, 0x3A, 0x79, 0x7A,
    0xBC, 0x0A, 0xB1, 0x82, 0xB3, 0x24, 0xFB, 0x61, 0xD1, 0x08, 0xA9, 0x4B, 0xB2, 0xC8, 0xE3, 0xFB,
    0xB9, 0x6A, 0xDA, 0xB7, 0x60, 0xD7, 0xF4, 0x68, 0x1D, 0x4F, 0x42, 0xA3, 0xDE, 0x39, 0x4D, 0xF4,
    0xAE, 0x56, 0xED, 0xE7, 0x63, 0x72, 0xBB, 0x19, 0x0B, 0x07, 0xA7, 0xC8, 0xEE, 0x0A, 0x6D, 0x70,
    0x9E, 0x02, 0xFC, 0xE1, 0xCD, 0xF7, 0xE2, 0xEC, 0xC0, 0x34, 0x04, 0xCD, 0x28, 0x34, 0x2F, 0x61,
    0x91, 0x72, 0xFE, 0x9C, 0xE9, 0x85, 0x83, 0xFF, 0x8E, 0x4F, 0x12, 0x32, 0xEE, 0xF2, 0x81, 0x83,
    0xC3, 0xFE, 0x3B, 0x1B, 0x4C, 0x6F, 0xAD, 0x73, 0x3B, 0xB5, 0xFC, 0xBC, 0x2E, 0xC2, 0x20, 0x05,
    0xC5, 0x8E, 0xF1, 0x83, 0x7D, 0x16, 0x83, 0xB2, 0xC6, 0xF3, 0x4A, 0x26, 0xC1, 0xB2, 0xEF, 0xFA,
    0x88, 0x6B, 0x42, 0x38, 0x61, 0x28, 0x5C, 0x97, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
   256,
   //Generator
   2
};

#endif
#if (TLS_FFDHE3072_SUPPORT == ENABLED)

/**
 * @brief ffdhe3072 group
 **/

const TlsFfdheGroup ffdhe3072Group =
{
   //Group name
   "ffdhe3072",
   //Prime modulus
   {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAD, 0xF8, 0x54, 0x58, 0xA2, 0xBB, 0x4A, 0x9A,
    0xAF, 0xDC, 0x56, 0x20, 0x27, 0x3D, 0x3C, 0xF1, 0xD8, 0xB9, 0xC5, 0x83, 0xCE, 0x2D, 0x36, 0x95,
    0xA9, 0xE1, 0x36, 0x41, 0x14, 0x64, 0x33, 0xFB, 0xCC, 0x93, 0x9D, 0xCE, 0x24, 0x9B, 0x3E, 0xF9,
    0x7D, 0x2F, 0xE3, 0x63, 0x63, 0x0C, 0x75, 0xD8, 0xF6, 0x81, 0xB2, 0x02, 0xAE, 0xC4, 0x61, 0x7A,
    0xD3, 0xDF, 0x1E, 0xD5, 0xD5, 0xFD, 0x65, 0x61, 0x24, 0x33, 0xF5, 0x1F, 0x5F, 0x06, 0x6E, 0xD0,
    0x85, 0x63, 0x65, 0x55, 0x3D, 0xED, 0x1A, 0xF3, 0xB5, 0x57, 0x13, 0x5E, 0x7F, 0x57, 0xC9, 0x35,
    0x98, 0x4F, 0x0C, 0x70, 0xE0, 0xE6, 0x8B, 0x77, 0xE2, 0xA6, 0x89, 0xDA, 0xF3, 0xEF, 0xE8, 0x72,
    0x1D, 0xF1, 0x58, 0xA1, 0x36, 0xAD, 0xE7, 0x35, 0x30, 0xAC, 0xCA, 0x4F, 0x48, 0x3A, 0x79, 0x7A,
    0xBC, 0x0A, 0xB1, 0x82, 0xB3, 0x24, 0xFB, 0x61, 0xD1, 0x08, 0xA9, 0x4B, 0xB2, 0xC8, 0xE3, 0xFB,
    0xB9, 0x6A, 0xDA, 0xB7, 0x60, 0xD7, 0xF4, 0x68, 0x1D, 0x4F, 0x42, 0xA3, 0xDE, 0x39, 0x4D, 0xF4,
    0xAE, 0x56, 0xED, 0xE7, 0x63, 0x72, 0xBB, 0x19, 0x0B, 0x07, 0xA7, 0xC8, 0xEE, 0x0A, 0x6D, 0x70,
    0x9E, 0x02, 0xFC, 0xE1, 0xCD, 0xF7, 0xE2, 0xEC, 0xC0, 0x34, 0x04, 0xCD, 0x28, 0x34, 0x2F, 0x61,
    0x91, 0x72, 0xFE, 0x9C, 0xE9, 0x85, 0x83, 0xFF, 0x8E, 0x4F, 0x12, 0x32, 0xEE, 0xF2, 0x81, 0x83,
    0xC3, 0xFE, 0x3B, 0x1B, 0x4C, 0x6F, 0xAD, 0x73, 0x3B, 0xB5, 0xFC, 0xBC, 0x2E, 0xC2, 0x20, 0x05,
    0xC5, 0x8E, 0xF1, 0x83, 0x7D, 0x16, 0x83, 0xB2, 0xC6, 0xF3, 0x4A, 0x26, 0xC1, 0xB2, 0xEF, 0xFA,
    0x88, 0x6B, 0x42, 0x38, 0x61, 0x1F, 0xCF, 0xDC, 0xDE, 0x35, 0x5B, 0x3B, 0x65, 0x19, 0x03, 0x5B,
    0xBC, 0x34, 0xF4, 0xDE, 0xF9, 0x9C, 0x02, 0x38, 0x61, 0xB4, 0x6F, 0xC9, 0xD6, 0xE6, 0xC9, 0x07,
    0x7A, 0xD9, 0x1D, 0x26, 0x91, 0xF7, 0xF7, 0xEE, 0x59, 0x8C, 0xB0, 0xFA, 0xC1, 0x86, 0xD9, 0x1C,
    0xAE, 0xFE, 0x13, 0x09, 0x85, 0x13, 0x92, 0x70, 0xB4, 0x13, 0x0C, 0x93, 0xBC, 0x43, 0x79, 0x44,
    0xF4, 0xFD, 0x44, 0x52, 0xE2, 0xD7, 0x4D, 0xD3, 0x64, 0xF2, 0xE2, 0x1E, 0x71, 0xF5, 0x4B, 0xFF,
    0x5C, 0xAE, 0x82, 0xAB, 0x9C, 0x9D, 0xF6, 0x9E, 0xE8, 0x6D, 0x2B, 0xC5, 0x22, 0x36, 0x3A, 0x0D,
    0xAB, 0xC5, 0x21, 0x97, 0x9B, 0x0D, 0xEA, 0xDA, 0x1D, 0xBF, 0x9A, 0x42, 0xD5, 0xC4, 0x48, 0x4E,
    0x0A, 0xBC, 0xD0, 0x6B, 0xFA, 0x53, 0xDD, 0xEF, 0x3C, 0x1B, 0x20, 0xEE, 0x3F, 0xD5, 0x9D, 0x7C,
    0x25, 0xE4, 0x1D, 0x2B, 0x66, 0xC6, 0x2E, 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
   384,
   //Generator
   2
};

#endif
#if (TLS_FFDHE4096_SUPPORT == ENABLED)

/**
 * @brief ffdhe4096 group
 **/

const TlsFfdheGroup ffdhe4096Group =
{
   //Group name
   "ffdhe4096",
   //Prime modulus
   {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAD, 0xF8, 0x54, 0x58, 0xA2, 0xBB, 0x4A, 0x9A,
    0xAF, 0xDC, 0x56, 0x20, 0x27, 0x3D, 0x3C, 0xF1, 0xD8, 0xB9, 0xC5, 0x83, 0xCE, 0x2D, 0x36, 0x95,
    0xA9, 0xE1, 0x36, 0x41, 0x14, 0x64, 0x33, 0xFB, 0xCC, 0x93, 0x9D, 0xCE, 0x24, 0x9B, 0x3E, 0xF9,
    0x7D, 0x2F, 0xE3, 0x63, 0x63, 0x0C, 0x75, 0xD8, 0xF6, 0x81, 0xB2, 0x02, 0xAE, 0xC4, 0x61, 0x7A,
    0xD3, 0xDF, 0x1E, 0xD5, 0xD5, 0xFD, 0x65, 0x61, 0x24, 0x33, 0xF5, 0x1F, 0x5F, 0x06, 0x6E, 0xD0,
    0x85, 0x63, 0x65, 0x55, 0x3D, 0xED, 0x1A, 0xF3, 0xB5, 0x57, 0x13, 0x5E, 0x7F, 0x57, 0xC9, 0x35,
    0x98, 0x4F, 0x0C, 0x70, 0xE0, 0xE6, 0x8B, 0x77, 0xE2, 0xA6, 0x89, 0xDA, 0xF3, 0xEF, 0xE8, 0x72,
    0x1D, 0xF1, 0x58, 0xA1, 0x36, 0xAD, 0xE7, 0x35, 0x30, 0xAC, 0xCA, 0x4F, 0x48, 0x3A, 0x79, 0x7A,
    0xBC, 0x0A, 0xB1, 0x82, 0xB3, 0x24, 0xFB, 0x61, 0xD1, 0x08, 0xA9, 0x4B, 0xB2, 0xC8, 0xE3, 0xFB,
    0xB9, 0x6A, 0xDA, 0xB7, 0x60, 0xD7, 0xF4, 0x68, 0x1D, 0x4F, 0x42, 0xA3, 0xDE, 0x39, 0x4D, 0xF4,
    0xAE, 0x56, 0xED, 0xE7, 0x63, 0x72, 0xBB, 0x19, 0x0B, 0x07, 0xA7, 0xC8, 0xEE, 0x0A, 0x6D, 0x70,
    0x9E, 0x02, 0xFC, 0xE1, 0xCD, 0xF7, 0xE2, 0xEC, 0xC0, 0x34, 0x04, 0xCD, 0x28, 0x34, 0x2F, 0x61,
    0x91, 0x72, 0xFE, 0x9C, 0xE9, 0x85, 0x83, 0xFF, 0x8E, 0x4F, 0x12, 0x32, 0xEE, 0xF2, 0x81, 0x83,
    0xC3, 0xFE, 0x3B, 0x1B, 0x4C, 0x6F, 0xAD, 0x73, 0x3B, 0xB5, 0xFC, 0xBC, 0x2E, 0xC2, 0x20, 0x05,
    0xC5, 0x8E, 0xF1, 0x83, 0x7D, 0x16, 0x83, 0xB2, 0xC6, 0xF3, 0x4A, 0x26, 0xC1, 0xB2, 0xEF, 0xFA,
    0x88, 0x6B, 0x42, 0x38, 0x61, 0x1F, 0xCF, 0xDC, 0xDE, 0x35, 0x5B, 0x3B, 0x65, 0x19, 0x03, 0x5B,
    0xBC, 0x34, 0xF4, 0xDE, 0xF9, 0x9C, 0x02, 0x38, 0x61, 0xB4, 0x6F, 0xC9, 0xD6, 0xE6, 0xC9, 0x07,
    0x7A, 0xD9, 0x1D, 0x26, 0x91, 0xF7, 0xF7, 0xEE, 0x59, 0x8C, 0xB0, 0xFA, 0xC1, 0x86, 0xD9, 0x1C,
    0xAE, 0xFE, 0x13, 0x09, 0x85, 0x13, 0x92, 0x70, 0xB4, 0x13, 0x0C, 0x93, 0xBC, 0x43, 0x79, 0x44,
    0xF4, 0xFD, 0x44, 0x52, 0xE2, 0xD7, 0x4D, 0xD3, 0x64, 0xF2, 0xE2, 0x1E, 0x71, 0xF5, 0x4B, 0xFF,
    0x5C, 0xAE, 0x82, 0xAB, 0x9C, 0x9D, 0xF6, 0x9E, 0xE8, 0x6D, 0x2B, 0xC5, 0x22, 0x36, 0x3A, 0x0D,
    0xAB, 0xC5, 0x21, 0x97, 0x9B, 0x0D, 0xEA, 0xDA, 0x1D, 0xBF, 0x9A, 0x42, 0xD5, 0xC4, 0x48, 0x4E,
    0x0A, 0xBC, 0xD0, 0x6B, 0xFA, 0x53, 0xDD, 0xEF, 0x3C, 0x1B, 0x20, 0xEE, 0x3F, 0xD5, 0x9D, 0x7C,
    0x25, 0xE4, 0x1D, 0x2B, 0x66, 0x9E, 0x1E, 0xF1, 0x6E, 0x6F, 0x52, 0xC3, 0x16, 0x4D, 0xF4, 0xFB,
    0x79, 0x30, 0xE9, 0xE4, 0xE5, 0x88, 0x57, 0xB6, 0xAC, 0x7D, 0x5F, 0x42, 0xD6, 0x9F, 0x6D, 0x18,
    0x77, 0x63, 0xCF, 0x1D, 0x55, 0x03, 0x40, 0x04, 0x87, 0xF5, 0x5B, 0xA5, 0x7E, 0x31, 0xCC, 0x7A,
    0x71, 0x35, 0xC8, 0x86, 0xEF, 0xB4, 0x31, 0x8A, 0xED, 0x6A, 0x1E, 0x01, 0x2D, 0x9E, 0x68, 0x32,
    0xA9, 0x07, 0x60, 0x0A, 0x91, 0x81, 0x30, 0xC4, 0x6D, 0xC7, 0x78, 0xF9, 0x71, 0xAD, 0x00, 0x38,
    0x09, 0x29, 0x99, 0xA3, 0x33, 0xCB, 0x8B, 0x7A, 0x1A, 0x1D, 0xB9, 0x3D, 0x71, 0x40, 0x00, 0x3C,
    0x2A, 0x4E, 0xCE, 0xA9, 0xF9, 0x8D, 0x0A, 0xCC, 0x0A, 0x82, 0x91, 0xCD, 0xCE, 0xC9, 0x7D, 0xCF,
    0x8E, 0xC9, 0xB5, 0x5A, 0x7F, 0x88, 0xA4, 0x6B, 0x4D, 0xB5, 0xA8, 0x51, 0xF4, 0x41, 0x82, 0xE1,
    0xC6, 0x8A, 0x00, 0x7E, 0x5E, 0x65, 0x5F, 0x6A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
   512,
   //Generator
   2
};

#endif


/**
 * @brief Select the named group to be used when performing FFDHE key exchange
 * @param[in] context Pointer to the TLS context
 * @param[in] groupList List of named groups supported by the peer
 * @return Error code
 **/

error_t tlsSelectFfdheGroup(TlsContext *context,
   const TlsSupportedGroupList *groupList)
{
   error_t error;
   uint_t i;
   uint_t j;
   uint_t n;
   uint16_t namedGroup;
   bool_t ffdheGroupFound;

   //Initialize status code
   error = ERROR_HANDSHAKE_FAILED;

   //Initialize flag
   ffdheGroupFound = FALSE;

   //Reset the named group to its default value
   context->namedGroup = TLS_GROUP_NONE;

   //Check whether a list of named groups is offered by the client
   if(groupList != NULL)
   {
      //Get the number of named groups present in the list
      n = ntohs(groupList->length) / sizeof(uint16_t);

      //Any preferred groups?
      if(context->numSupportedGroups > 0)
      {
         //Loop through the list of allowed groups (most preferred first)
         for(i = 0; i < context->numSupportedGroups; i++)
         {
            //Loop through the list of named groups the client supports
            for(j = 0; j < n; j++)
            {
               //Convert the named group to host byte order
               namedGroup = ntohs(groupList->value[j]);

               //Check whether the SupportedGroups extension contains codepoints
               //between 256 and 511, inclusive
               if(namedGroup >= TLS_GROUP_FFDHE2048 &&
                  namedGroup <= TLS_GROUP_FFDHE_MAX)
               {
                  //The list contains at least one FFDHE group
                  ffdheGroupFound = TRUE;
               }

               //The named group to be used when performing FFDHE key exchange
               //must be one of those present in the SupportedGroups extension
               if(context->supportedGroups[i] == namedGroup)
               {
                  //Acceptable FFDHE group found?
                  if(tlsGetFfdheGroup(context, namedGroup) != NULL)
                  {
                     //Save the named group
                     if(context->namedGroup == TLS_GROUP_NONE)
                     {
                        context->namedGroup = namedGroup;
                     }
                  }
               }
            }
         }
      }
      else
      {
         //The named group to be used when performing FFDHE key exchange must
         //be one of those present in the SupportedGroups extension
         for(j = 0; j < n; j++)
         {
            //Convert the named group to host byte order
            namedGroup = ntohs(groupList->value[j]);

            //Check whether the SupportedGroups extension contains codepoints
            //between 256 and 511, inclusive
            if(namedGroup >= TLS_GROUP_FFDHE2048 &&
               namedGroup <= TLS_GROUP_FFDHE_MAX)
            {
               //The list contains at least one FFDHE group
               ffdheGroupFound = TRUE;
            }

            //Acceptable FFDHE group found?
            if(tlsGetFfdheGroup(context, namedGroup) != NULL)
            {
               //Save the named group
               if(context->namedGroup == TLS_GROUP_NONE)
               {
                  context->namedGroup = namedGroup;
               }
            }
         }
      }
   }

   //If the SupportedGroups extension is either absent from the ClientHello
   //entirely or contains no FFDHE groups, then the server knows that the
   //client is not compatible with RFC 7919
   if(!ffdheGroupFound)
   {
      //In this scenario, the server may select an FFDHE group of its choice
      if(tlsGetFfdheGroup(context, TLS_GROUP_FFDHE2048) != NULL)
      {
         //Select ffdhe2048 finite field group
         context->namedGroup = TLS_GROUP_FFDHE2048;
      }
      else if(tlsGetFfdheGroup(context, TLS_GROUP_FFDHE3072) != NULL)
      {
         //Select ffdhe3072 finite field group
         context->namedGroup = TLS_GROUP_FFDHE3072;
      }
      else if(tlsGetFfdheGroup(context, TLS_GROUP_FFDHE4096) != NULL)
      {
         //Select ffdhe4096 finite field group
         context->namedGroup = TLS_GROUP_FFDHE4096;
      }
      else
      {
         //Just for sanity
         context->namedGroup = TLS_GROUP_NONE;
      }
   }

   //If no acceptable choices are presented, then return an error
   if(context->namedGroup != TLS_GROUP_NONE)
   {
      error = NO_ERROR;
   }

   //Return status code
   return error;
}


/**
 * @brief Get the FFDHE parameters that match the specified named group
 * @param[in] context Pointer to the TLS context
 * @param[in] namedGroup Named group
 * @return FFDHE parameters
 **/

const TlsFfdheGroup *tlsGetFfdheGroup(TlsContext *context, uint16_t namedGroup)
{
   uint_t i;
   const TlsFfdheGroup *ffdheGroup;

   //Check named group
   switch(namedGroup)
   {
#if (TLS_FFDHE2048_SUPPORT == ENABLED)
   //ffdhe2048 group?
   case TLS_GROUP_FFDHE2048:
      ffdheGroup = &ffdhe2048Group;
      break;
#endif
#if (TLS_FFDHE3072_SUPPORT == ENABLED)
   //ffdhe3072 group?
   case TLS_GROUP_FFDHE3072:
      ffdheGroup = &ffdhe3072Group;
      break;
#endif
#if (TLS_FFDHE4096_SUPPORT == ENABLED)
   //ffdhe4096 group?
   case TLS_GROUP_FFDHE4096:
      ffdheGroup = &ffdhe4096Group;
      break;
#endif
   //Unknown group?
   default:
      ffdheGroup = NULL;
      break;
   }

   //Restrict the use of certain FFDHE groups
   if(context->numSupportedGroups > 0)
   {
      //Loop through the list of allowed named groups
      for(i = 0; i < context->numSupportedGroups; i++)
      {
         //Compare named groups
         if(context->supportedGroups[i] == namedGroup)
            break;
      }

      //Check whether the use of the FFDHE group is restricted
      if(i >= context->numSupportedGroups)
         ffdheGroup = NULL;
   }

   //Return FFDHE parameters, if any
   return ffdheGroup;
}


/**
 * @brief Load FFDHE parameters
 * @param[out] params Pointer to the structure to be initialized
 * @param[in] ffdheGroup FFDHE parameters
 * @return Error code
 **/

error_t tlsLoadFfdheParameters(DhParameters *params,
   const TlsFfdheGroup *ffdheGroup)
{
   error_t error;

   //Make sure the FFDHE group is supported
   if(ffdheGroup != NULL)
   {
      //Convert the prime modulus to a multiple precision integer
      error = mpiImport(&params->p, ffdheGroup->p, ffdheGroup->pLen,
         MPI_FORMAT_BIG_ENDIAN);

      //Check status code
      if(!error)
      {
         //Convert the generator to a multiple precision integer
         error = mpiSetValue(&params->g, ffdheGroup->g);
      }
   }
   else
   {
      //The specified FFDHE group is not supported
      error = ERROR_FAILURE;
   }

   //Return status code
   return error;
}

#endif
