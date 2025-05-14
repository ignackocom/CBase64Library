/******************************************************************************
* \file      CBase64.h
* \version   2025.03.18
* \author    Peter Potrok ( @ignackocom )
*            ignacko.com@outlook.com
*            https://github.com/ignackocom
* \copyright Copyright (c) 1994 - 2025
*            MIT License (see License.txt file)
* \brief     C Base64 library
*            C89, C99 and >C99 compatible, CPP compatible, Embedded C compatible
* \details
*
* \see       https://github.com/ignackocom
*            https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CBASE64_H
#define CBASE64_H      20250318L


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef __cplusplus
extern "C" {
#endif

    /******************************************************************************
     * \brief
     *	Encode input buffer to Base64.
     *
     * \param
     *	inputdata - Input data to convert to base64
     * \param
     *	inputlength - Input data length.
     * \param
     *	outputlength - Output data length.
     *
     * \return
     *	Base64 encoded data string.
     *
     */
	char* BASE64_Encode(const unsigned char* inputdata, size_t inputlength, size_t* outputlength);

    /******************************************************************************
     * \brief
     *	Decode Base64 string to original data.
     *
     * \param
     *	inputdata - Input data base64 string.
     * \param
     *	outputlength - Output data length.
     *
     * \return
     *	Base64 decoded data.
     *
     */
	unsigned char* BASE64_Decode(const char* inputdata, size_t* outputlength);

#ifdef __cplusplus
}
#endif



#ifdef __cplusplus
extern "C" {
#endif

    long CBASE64_VERSION(void);

#ifdef __cplusplus
}
#endif



#endif /* CBASE64_H */
