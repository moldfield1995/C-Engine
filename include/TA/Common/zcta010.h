//---------------------------------------------------------------------------------
// File Name: zcta010.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef lOOlOOlllll
#define lOOlOOlllll
#ifndef lOOlOllOOOO
#include "../Common/zcta014.h"
#endif //
#ifndef llOlllllOl
#include "../Common/zcta015.h"
#endif //
#ifndef lOOOOOOllll
#include "../Common/zcta008.h"
#endif //
#ifndef lOOlOlOOOOO
#endif //
#ifndef lOOlOllOOOl
#endif //
#ifndef lOOlOllOOlO
#include "../Common/zcta017.h"
#endif //
name\
spa\
ce
TA
{
#ifdef lOOlOlOOOOO
#define lOOlOllOOll(lOOlOllOlOO)				\
extern lOOlOlOOOlO::lOOlOlOOOll lOOlOllOlOl
#define lOOlOllOllO(lOOlOllOlOO)				\
lOOlOlOOOlO::lOOlOlOOOll lOOlOllOlll(lOOlOlllOOO)
#define lOOlOlllOOl(lOOlOllOlOO)				\
lOOlOllOlll.lOOlOlllOlO()
#define lOOlOlllOll(lOOlOllOlOO)					\
lOOlOllOlll.lOOlOllllOO()
#define lOOlOllllOl(lOOlOllOlOO)					\
lOOlOlOOOlO::lOOlOlllllO lOOlOllllll(lOOlOllOlll)
#else 
#define lOOlOllOOll(lOOlOllOlOO)
#define lOOlOllOllO(lOOlOllOlOO)
#define lOOlOlllOOl(lOOlOllOlOO)
#define lOOlOlllOll(lOOlOllOlOO)
#define lOOlOllllOl(lOOlOllOlOO)
#endif //
#ifdef lOOllOOOOOO
cla\
ss
TACOM\
MON_CLASS
lOOl\
O\
l\
OO\
OlO
{
lOOl\
lOOO\
OOl\

(
lOOlOlOOOlO\

)
pub\
l\
ic\

:
class
lOOlOl\
OO\
O\
ll
{
pub\
l\
ic
:
lOOlO\
lOOO\
ll\

(
co\
nst\

cha\
r
*
lllO\
l\
OOOll
)
;
~
lOOlOlOO\
Oll
(
)
;
void
Clear\

(
)
;
void\

Re\
s\
e\
t\

(
)
;
const
llOllll\
l\
lO
&
lOOll\
OO\
OOlO\

(
)
const\

{
retur\
n\

lO\
OO\
OO\
OO\
Ol\
l
;
}
s64\

Get\
Time\

(
)
const
{
retu\
rn
lOO\
lOlOO\
lOl
;
}
s64
lOOllOOOOll\

(
)
co\
nst
{
retu\
rn\

lOOl\
OlOl\
OlO
;
}
vo\
id
lOO\
lOl\
ll\
OlO
(
)
;
void
lOOlO\
ll\
llO\
O
(
)
;
private
:
s64\

lO\
O\
l\
O\
lOlO\
Ol
;
s6\
4
lOOlOlO\
Ol\
O\
l
;
int
lO\
OlOlOlO\
O\
O\

;
int
lO\
O\
lO\
lO\
lO\
l\
O
;
int
lOOlOl\
Ol\
Oll\

;
llOlllll\
l\
O
lOOO\
O\
O\
OOOl\
l
;
}
;
class\

lOO\
l\
O\
lllllO
{
publ\
i\
c
:
lO\
OlOll\
lll\
O\

(
lOOl\
Ol\
OOO\
l\
l
&
lOO\
l\
O\
l\
OllOl
)
;
~
lOOlOl\
llll\
O
(
)
;
priv\
ate\

:
lOO\
l\
O\
lOOOll
&
lOOll\
OOOlOO
;
}
;
typed\
ef\

Li\
s\
t
<
lOOl\
OlO\
OOll\

*
>
::
lOOOOOlOOll
lOOOOOlOO\
l\
l
;
vo\
id
Res\
e\
t\

(
)
;
void
lOO\
lOlO\
OlOO
(
lOO\
l\
Ol\
OOOl\
l
*
lO\
OlOl\
Ol\
l\
l\
O
)
;
void
lOOlOlOOlll
(
lOOlO\
lOO\
Ol\
l
*
lO\
O\
lOl\
Olll\
O
)
;
lO\
O\
OO\
OlOOll
lO\
OOOOllOOO
(
)
const
{
ret\
urn
lO\
O\
lO\
lO\
llO\
O\

.
lOO\
OO\
OllOOO\

(
)
;
}
priva\
te
:
typede\
f\

List
<
lOO\
lOl\
OOOll
*
>
::
Itera\
tor\

Iterator
;
List
<
lOOlOlOOOll
*
>
lOOlO\
lOl\
l\
OO\

;
lOO\
lO\
lOO\
OlO\

(
)
;
~
lOO\
l\
Ol\
OOOlO
(
)
;
voi\
d\

Initia\
li\
se
(
)
;
void
Fi\
nal\
ise
(
)
;
}
;
#endif //
}
#ifdef lOOlOlOOOOO
#include "../Common/zcta007.inl"
#endif //
#endif //
