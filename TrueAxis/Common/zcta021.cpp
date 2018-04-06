//---------------------------------------------------------------------------------
// File Name: zcta021.cpp
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#include "../Common/zcta017.h"
#ifdef lOOlOllOOOl
#ifdef lOlOlOOllO
#ifdef TA_MSVC
#undef TA_MSVC
#endif
#endif
#ifdef TA_MSVC
#include <Windows.h>
#endif
na\
mes\
pa\
ce
TA
{
lOO\
l\
O\
l\
OOOO\
l
(
lOOlOl\
O\
l\
l\
ll
)
s6\
4
lOOlO\
l\
O\
l\
lll
::
GetTime
(
)
con\
st
{
#ifndef TA_MSVC
ret\
u\
rn\

1
;
#else
union
{
st\
ruct
{
u32
nLowP\
art_rese\
rved
;
s32
nHighPart_r\
e\
served
;
}
spli\
t\
_r\
eser\
ved
;
s6\
4
lOOlll\
lOlOl
;
}
iClocks_re\
serv\
ed
;
__asm	{
	// SpellCheckerDisable
	//	_emit 0x0f	//cpuid - serialise the processor
	//	_emit 0xa2
		__emit 0fh	// rdtsc instruction opcodes
		__emit 031h
		mov iClocks_reserved.split_reserved.nHighPart_reserved, edx
		mov iClocks_reserved.split_reserved.nLowPart_reserved, eax
	// SpellCheckerEnable
	}
retur\
n
iCl\
o\
ck\
s_res\
e\
rved\

.
lOOllll\
OlO\
l
;
#endif
}
lO\
OlOl\
Ollll
::
lOOlO\
l\
Ol\
lll
(
)
{
lOOllllO\
ll\
O
=
fals\
e
;
}
lOOlOl\
O\
llll
::
~
lOOlOlO\
ll\
l\
l
(
)
{
Finali\
se
(
)
;
}
void
lOO\
lOlOllll
::
Init\
ialise\

(
)
{
#ifdef TA_MSVC
#endif
}
void
lOOlO\
l\
Ollll
::
Finalise
(
)
{
}
}
#endif //