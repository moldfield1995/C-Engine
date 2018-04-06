//---------------------------------------------------------------------------------
// File Name: zcta005.cpp
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif
#include "Debug.h"
#ifdef _DEBUG
#ifndef llOlllllOl
#include "../Common/zcta015.h"
#endif //
#ifndef lOlOlOOllO
#include <io.h>
#include <sys/stat.h>
#endif //
#ifdef TA_MSVC
#include <windows.h>
#include <crtdbg.h>
#endif
#include <stdio.h>
#include <stdlib.h>
namespace
TA
{
na\
mes\
pace
De\
b\
u\
g\

{
static
llOlll\
ll\
lO
llOll\
l\
ll\
ll\

;
#ifdef _DEBUG
st\
a\
tic
bool
ll\
l\
OO\
OO\
OO\
O
=
true
;
sta\
ti\
c\

boo\
l
ll\
lOO\
OOOO\
l\

=
true
;
void
TAC\
_CALL
lll\
OO\
O\
OOl\
O
(
co\
nst
ch\
ar
*
ll\
lOOO\
O\
Ol\
l
,
in\
t
lllO\
OO\
O\
lOO\

,
co\
n\
st
char
*
lllOO\
OOlO\
l
,
co\
n\
st
ch\
ar
*
lll\
OO\
OOl\
lO\

)
{
llOlll\
lll\
O
lllO\
OO\
Ol\
ll
;
if
(
lll\
OOO\
O\
llO
)
{
lllOOOOlll
+=
"WARNING MSG: \"";
lllOOOOlll\

+=
lllOOO\
O\
ll\
O\

;
lllOOOOlll\

+=
"\" ";
}
else
{
ll\
lOOOOlll
+=
"INTERNAL ERROR: ";
}
lllOOOOl\
ll
+=
"CONDITION FAILED: ";
lllO\
O\
OOlll
+=
lllOOO\
Ol\
Ol
;
lllOOOO\
l\
ll
+=
"\n";
#ifdef TA_MSVC
_CrtDb\
gReport\

(
_CR\
T_\
WARN
,
lllOOOOOll
,
lllO\
OOO\
l\
OO
,
0
,
lll\
OOOOll\
l
)
;
#endif
ll\
lO\
OO\
lOO\
O
(
lllOO\
OOll\
l
)
;
}
st\
a\
tic
void\

TAC_CALL\

lllOOOlO\
O\
l
(
const
char\

*
lllOOOO\
Oll
,
int
lllOO\
OO\
lO\
O
,
const
char
*
lllOOOOl\
lO
)
;
void
TAC_CALL
lllOOO\
lOlO
(
co\
n\
st
ch\
ar
*
lllOOO\
OOll
,
int
ll\
l\
OOOOlOO
,
cons\
t
char
*
ll\
lO\
OOOl\
O\
l
,
cons\
t
ch\
ar
*
lllOOOOllO
)
{
ll\
Ol\
l\
llll\
O\

lllOO\
OOl\
ll\

;
if\

(
lllOOOOllO
)
{
lll\
OOOOl\
ll
+=
"ERROR MSG: \"";
lllOOOO\
ll\
l
+=
lllO\
OO\
OllO
;
ll\
l\
O\
OO\
Olll
+=
"\" ";
}
el\
se
{
lllO\
OOOlll
+=
"INTERNAL ERROR: ";
}
lllOOOOl\
ll
+=
"CONDITION FAILED: ";
lllO\
OOO\
ll\
l\

+=
lll\
O\
OO\
OlO\
l
;
lll\
O\
OOOl\
ll
+=
"\n";
lll\
O\
O\
Ol\
OO\
l
(
lllOOOOO\
ll
,
lllO\
OO\
OlOO\

,
lll\
OOO\
Oll\
l\

)
;
if
(
lllO\
O\
OO\
OOO
)
{
#ifdef TA_MSVC_X86_INLINE_ASM
__\
asm{ int 3 }
#endif
#ifdef TA_GCC_X86_INLINE_ASM
asm
(
"int $3")
;
#endif
}
if
(
ll\
lOOO\
O\
OOl\

)
{
exi\
t
(
1
)
;
}
}
st\
a\
t\
ic
vo\
id
TAC_C\
AL\
L
lll\
OOOlOOl
(
const
ch\
a\
r
*
ll\
lOOOOOll
,
int\

lllO\
OO\
OlOO\

,
const
char
*
lllOOOOll\
O
)
{
#ifdef TA_MSVC
_CrtD\
bgReport
(
_CRT_WARN\

,
lllOOO\
OOll\

,
lllOOOOlOO
,
0
,
lll\
OO\
OOllO
)
;
#endif //
lllOOOlO\
OO\

(
lllO\
O\
OOllO
)
;
}
#endif //
void
TAC_CA\
LL
Ope\
nO\
utput\
File
(
co\
n\
s\
t
Ch\
ar
*
lllOOOlO\
ll\

)
{
ll\
Olll\
llll
=
lllOOOlOll
;
#ifndef lOlOlOOllO
_chmod
(
ll\
l\
OOOl\
Oll
,
_S\
_IR\
E\
AD
|
_S\
_I\
W\
R\
I\
T\
E
)
;
#endif //
FILE
*
lllOOOll\
O\
O
=
fop\
en
(
ll\
Olll\
llll
,
"w")
;
if
(
ll\
lOOOl\
l\
OO
)
fc\
lose\

(
lll\
OOOl\
lOO
)
;
else
ll\
Oll\
llll\
l
.
Cl\
ear
(
)
;
}
void
TA\
C_CALL\

Clos\
eOutp\
u\
tF\
ile
(
)
{
llOlll\
l\
lll\

.
Clear
(
)
;
}
void
TAC_C\
ALL
Out\
p\
u\
t\

(
const
Cha\
r
*
lllO\
OO\
llO\
l
)
{
if
(
llOlllllll
.
lOOOll\
lOOl
(
)
)
{
FILE
*
lll\
O\
OOllO\
O
=
fopen\

(
llOl\
lll\
lll
,
"a")
;
if
(
lllOOO\
ll\
OO
)
{
fp\
u\
ts
(
lllOOOllO\
l\

,
lllOOOllOO\

)
;
fclose\

(
ll\
l\
OO\
O\
llOO\

)
;
}
}
}
void
TAC_CALL\

Se\
tDebu\
gAsserts\
Enab\
l\
e
(
bool
ll\
lO\
O\
OlllO
)
{
ll\
lO\
OOOOOO
=
lllOOOlllO\

;
}
voi\
d
TAC\
_CA\
LL
SetExi\
tW\
it\
Failure\
On\
As\
s\
e\
rt\

(
bool
ll\
lOO\
OlllO
)
{
ll\
l\
OOOOOO\
l
=
lllO\
OOlllO\

;
}
}
}
#endif //
