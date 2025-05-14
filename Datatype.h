/******************************************************************************
* \file      Datatype.h
* \author    Peter Potrok
*            ignacko.com@outlook.com
* \copyright Copyright (c) 1994 - 2025
*            MIT License (see License.txt file)
* \brief     Complete language data type definitions
* \details
*
* \see       https://github.com/ignackocom
*            https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef DATATYPE_H
#define DATATYPE_H		20250318L


#if !defined(__cplusplus)

    #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

        /* since C99 */
        #include <stdint.h>

    #endif

#else

    #if defined(__cplusplus) && __cplusplus > 199711L

        /* C++ */
        #include <cstdint>

    #endif

#endif


/******************************************************************************
**  basic data types
*/
typedef void                Void;

typedef char*               String;

typedef char                Char;
typedef unsigned char       UChar;

typedef short               Short;
typedef unsigned short      UShort;

typedef int                 Int;
typedef unsigned int        UInt;

typedef long                Long;
typedef unsigned long       ULong;

#if !defined(__cplusplus)

    #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

        typedef long long           LongLong;
        typedef unsigned long long  ULongLong;

    #endif /*  defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L */

#else /* !defined(__cplusplus) */

    #if __cplusplus > 199711L

        typedef std::int64_t            LongLong;
        typedef std::uint64_t           ULongLong;

    #endif /* __cplusplus > 199711L */

#endif /* !defined(__cplusplus) */

typedef     float           Float;

#if !defined(__SDCC) && !defined(SDCC)

typedef     double          Double;

typedef     long double     LongDouble;

#endif /* !defined(__SDCC) && !defined(SDCC) */


typedef Void                VOID;

typedef String              STRING;

typedef Char                CHAR;
typedef UChar               UCHAR;

typedef Short               SHORT;
typedef UShort              USHORT;

typedef Int                 INT;
typedef UInt                UINT;

typedef Long                LONG;
typedef ULong               ULONG;

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L || defined(__cplusplus) && __cplusplus > 199711L

typedef LongLong            LONGLONG;
typedef ULongLong           ULONGLONG;

#endif /*  defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L || defined(__cplusplus) && __cplusplus > 199711L */

typedef     Float           FLOAT;

#if !defined(__SDCC) && !defined(SDCC)

typedef     Double          DOUBLE;

typedef     LongDouble      LONGDOUBLE;

#endif /* !defined(__SDCC) && !defined(SDCC) */


/******************************************************************************
**  basic integer types
*/
#if !defined(__cplusplus)

    #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

        /* since C99 */

        typedef  int8_t         Int8;
        typedef  uint8_t        UInt8;

        typedef  int16_t        Int16;
        typedef  uint16_t       UInt16;

        typedef  int32_t        Int32;
        typedef  uint32_t       UInt32;

        typedef  int64_t        Int64;
        typedef  uint64_t       UInt64;

    #else /*  defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L */

        /* C95 and less */

        typedef  char           Int8;
        typedef  unsigned char  UInt8;

        typedef  short          Int16;
        typedef  unsigned short UInt16;

        typedef  long           Int32;
        typedef  unsigned long  UInt32;

    #endif /*  defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L */

#else /* !defined(__cplusplus) */

    #if __cplusplus > 199711L

        /* since CPP11 */

        typedef  std::int8_t         Int8;
        typedef  std::uint8_t        UInt8;

        typedef  std::int16_t        Int16;
        typedef  std::uint16_t       UInt16;

        typedef  std::int32_t        Int32;
        typedef  std::uint32_t       UInt32;

        typedef  std::int64_t        Int64;
        typedef  std::uint64_t       UInt64;

    #else

        /* CPP98 */

        typedef  char           Int8;
        typedef  unsigned char  UInt8;

        typedef  short          Int16;
        typedef  unsigned short UInt16;

        typedef  long           Int32;
        typedef  unsigned long  UInt32;

    #endif /* __cplusplus > 199711L */

#endif /* !defined(__cplusplus) */



typedef     Int8            INT8;
typedef     UInt8           UINT8;

typedef     Int16           INT16;
typedef     UInt16          UINT16;

typedef     Int32           INT32;
typedef     UInt32          UINT32;

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L || defined(__cplusplus) && __cplusplus > 199711L

typedef     Int64           INT64;
typedef     UInt64          UINT64;

#endif /*  defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L || defined(__cplusplus) && __cplusplus > 199711L */



typedef     Int8            I8;
typedef     UInt8           UI8;

typedef     Int16           I16;
typedef     UInt16          UI16;

typedef     Int32           I32;
typedef     UInt32          UI32;

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L || defined(__cplusplus) && __cplusplus > 199711L

typedef     Int64           I64;
typedef     UInt64          UI64;

#endif /*  defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L || defined(__cplusplus) && __cplusplus > 199711L */



/******************************************************************************
**  floating point data types
*/
typedef     Float           Float32;

#if !defined(__SDCC) && !defined(SDCC)

typedef     Double          Float64;

typedef     LongDouble      Float128;

#endif /* !defined(__SDCC) && !defined(SDCC) */


typedef     Float           FLOAT32;

#if !defined(__SDCC) && !defined(SDCC)

typedef     Double          FLOAT64;

typedef     LongDouble      FLOAT128;

#endif /* !defined(__SDCC) && !defined(SDCC) */


typedef     Float           F32;

#if !defined(__SDCC) && !defined(SDCC)

typedef     Double          F64;

typedef     LongDouble      F128;

#endif /* !defined(__SDCC) && !defined(SDCC) */


#endif /* DATATYPE_H */
