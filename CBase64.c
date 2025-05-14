/******************************************************************************
* \file      CBase64.c
* \author    Peter Potrok
*            ignacko.com@outlook.com
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

#include "Datatype.h"
#include "CBase64.h"


#if defined(__clang__)
#pragma clang diagnostic ignored "-Wold-style-cast"
#endif /* defined(__clang__) */


/******************************************************************************
**  Base64 character set
*/
static const char base64_chars[] = \
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


/******************************************************************************
**  Get the index of a Base64 character
*/
int base64_char_value(char c);

int base64_char_value(char c)
{
    if ('A' <= c && c <= 'Z') return(c - 'A');
    if ('a' <= c && c <= 'z') return(c - 'a' + 26);
    if ('0' <= c && c <= '9') return(c - '0' + 52);
    if (c == '+') return(62);
    if (c == '/') return(63);
    return(-1);
}

#if defined(__clang__)
#pragma clang unsafe_buffer_usage begin
#endif /* defined(__clang__) */


/******************************************************************************
**  Encode input buffer to Base64
*/
char* BASE64_Encode(const unsigned char* inputdata, size_t inputlength, size_t* outputlength)
{
    const size_t mod_table[] = { 0, 2, 1 };
    size_t i, j;
    UINT32 octet_a, octet_b, octet_c;
    UINT32 triple;
    char* outputdata;


    *outputlength = 4 * ((inputlength + 2) / 3);

    outputdata = (char *)malloc(*outputlength + 1);
    if (outputdata == NULL) return(NULL);

    for (i = 0, j = 0; i < inputlength;) 
    {
        octet_a = i < inputlength ? inputdata[i++] : 0;
        octet_b = i < inputlength ? inputdata[i++] : 0;
        octet_c = i < inputlength ? inputdata[i++] : 0;

        triple = (octet_a << 16) | (octet_b << 8) | octet_c;

        outputdata[j++] = base64_chars[(triple >> 18) & 0x3F];
        outputdata[j++] = base64_chars[(triple >> 12) & 0x3F];
        outputdata[j++] = base64_chars[(triple >> 6) & 0x3F];
        outputdata[j++] = base64_chars[triple & 0x3F];
    }

    for (i = 0; i < mod_table[inputlength % 3]; i++)
        outputdata[*outputlength - 1 - (size_t)i] = '=';

    outputdata[*outputlength] = '\0';

    return(outputdata);
}


/******************************************************************************
**  Decode Base64 string to original data
*/
unsigned char* BASE64_Decode(const char* inputdata, size_t* outputlength)
{
    size_t inputlength;
    size_t padding;
    size_t i, j;
    UINT32 sextet_a, sextet_b, sextet_c, sextet_d;
    UINT32 triple;
    unsigned char* outputdata;

    padding = 0;

    inputlength = strlen(inputdata);
    if (inputlength % 4 != 0) return(NULL);

    if (inputdata[inputlength - 1] == '=') padding=1;
    if (inputdata[inputlength - 2] == '=') padding++;

    *outputlength = (inputlength * 3) / 4 - padding;
    outputdata = (unsigned char*)malloc((size_t)*outputlength);
    if (outputdata == NULL) return(NULL);

    for (i = 0, j = 0; i < inputlength;)
    {
        sextet_a = (UINT32)base64_char_value(inputdata[i++]);
        sextet_b = (UINT32)base64_char_value(inputdata[i++]);
        sextet_c = (UINT32)base64_char_value(inputdata[i++]);
        sextet_d = (UINT32)base64_char_value(inputdata[i++]);

        triple = (UINT32)((sextet_a << 18)
                               | (sextet_b << 12)
                               | ((sextet_c & 0x3F) << 6)
                               | (sextet_d & 0x3F));

        if (j < *outputlength) outputdata[j++] = (triple >> 16) & 0xFF;
        if (j < *outputlength) outputdata[j++] = (triple >> 8) & 0xFF;
        if (j < *outputlength) outputdata[j++] = triple & 0xFF;
    }

    return(outputdata);
}

#if defined(__clang__)
#pragma clang unsafe_buffer_usage end
#endif /* defined(__clang__) */



long CBASE64_VERSION(void)
{
    return (CBASE64_H);
}
