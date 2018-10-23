/**
 * @file	compiler.h
 * @brief	include file for standard system include files,
 *			or project specific include files that are used frequently,
 *			but are changed infrequently
 */

#define	_WIN32_IE	0x0200

#ifndef WINVER                // Specifies that the minimum required platform is Windows 95.
#define WINVER 0x0400         // Change this to the appropriate value to target other versions of Windows.
#endif	

#ifndef _WIN32_WINNT          // Specifies that the minimum required platform is Windows NT4.0 SP3.
#define _WIN32_WINNT 0x0400   // Change this to the appropriate value to target other versions of Windows.
#endif

#include <windows.h>
#include <prsht.h>
#include <tchar.h>
#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>
#if defined(TRACE)
#include <assert.h>
#endif

#define	BYTESEX_LITTLE
#if !defined(UNICODE)
#define	OSLANG_SJIS
#else
#define	OSLANG_UCS2
#endif
#define	OSLINEBREAK_CRLF

#if !defined(__GNUC__) || defined(__MINGW32__)
typedef signed int			SINT;
typedef signed char			SINT8;
typedef unsigned char		UINT8;
typedef	signed short		SINT16;
typedef	unsigned short		UINT16;
typedef	signed int			SINT32;
typedef	unsigned int		UINT32;
typedef signed __int64		SINT64;
typedef unsigned __int64	UINT64;
#define	INLINE				__inline
#define	QWORD_CONST(v)		((UINT64)(v))
#define	SQWORD_CONST(v)		((SINT64)(v))
#define	snprintf			_snprintf
#define	vsnprintf			_vsnprintf
#else
#include	<stdlib.h>
typedef signed char			SINT8;
typedef unsigned char		UINT8;
typedef	short				SINT16;
typedef	unsigned short		UINT16;
typedef	int					SINT32;
typedef signed __int64		SINT64;
#define	INLINE				inline
#endif
#define	FASTCALL			__fastcall

#define	LOADINTELDWORD(a)		(*((UINT32 *)(a)))
#define	LOADINTELWORD(a)		(*((UINT16 *)(a)))
#define	STOREINTELDWORD(a, b)	*(UINT32 *)(a) = (b)
#define	STOREINTELWORD(a, b)	*(UINT16 *)(a) = (b)


#define	sigjmp_buf				jmp_buf
#define	sigsetjmp(env, mask)	setjmp(env)
#define	siglongjmp(env, val)	longjmp(env, val)
#define	msgbox(title, msg)		MessageBox(NULL, msg, title, MB_OK)

#define	STRCALL		__stdcall

#define	BRESULT				UINT8
#define	OEMCHAR				TCHAR
#define	OEMTEXT(string)		TEXT(string)
#define	OEMSPRINTF			wsprintf
#define	OEMSTRLEN			lstrlen

#include "common.h"
#include "milstr.h"
#include "_memory.h"
#include "rect.h"
#include "misc\tickcounter.h"
#include "misc\trace.h"

#ifdef __cplusplus
#include "misc\vc6macros.h"
#endif	/* __cplusplus */

#define	GETTICK				GetTickCounter
#if defined(TRACE)
#define	__ASSERT(s)			assert(s)
#else
#define	__ASSERT(s)
#endif
#if defined(UNICODE)
#define	SPRINTF				sprintf
#define	STRLEN				strlen
#else
#define	SPRINTF				wsprintf
#define	STRLEN				lstrlen
#endif

#define	LABEL				__declspec(naked)
#define RELEASE(x) 			if (x) {(x)->Release(); (x) = NULL;}

#define	PARTSCALL	__fastcall
#define	CPUCALL		__fastcall
#define	MEMCALL		__fastcall
#define DMACCALL	__fastcall
#define	IOOUTCALL	__fastcall
#define	IOINPCALL	__fastcall
#define SOUNDCALL	__fastcall
#define	VRAMCALL	__fastcall
#define	SCRNCALL	__fastcall

#if !defined(UNICODE)
#define	SUPPORT_SJIS
#else
#define	SUPPORT_ANK
#endif

#define	SUPPORT_8BPP
#define	SUPPORT_16BPP
#define	SUPPORT_24BPP
#define	SUPPORT_32BPP

#define	SUPPORT_OPM
#define SUPPORT_OPMx2
#define	SUPPORT_BANKMEM
#define	SUPPORT_X1F
#ifdef __MINGW32__
#define	SUPPORT_WAVEREC
#endif
#define	SUPPORT_DCLOCK
#define	SUPPORT_RESUME
#define	SUPPORT_STATSAVE	10

#define	SOUNDRESERVE		20

#define SUPPORT_DCLOCK
#define SUPPORT_KEYDISP
#define SUPPORT_SOFTKBD
