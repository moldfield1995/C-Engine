//---------------------------------------------------------------------------------
// File Name: zcta008.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef lOOOOOOllll
#define lOOOOOOllll
#ifndef TA_DEBUG_H
#include "Debug.h"
#endif //
#ifndef TA_MEMORYMGR_H
#include "MemoryMgr.h"
#endif //
nam\
es\
pac\
e\

TA\

{
te\
m\
plate\

<
cl\
a\
ss\

Ty\
p\
e\

>
class
TACOMMO\
N_\
CLAS\
S\

List
{
pr\
ot\
ected
:
st\
ruct
lOOl\
l\
OOOOO
;
public
:
class\

It\
er\
ato\
r
{
public\

:
Iterator
(
)
{
lOOOO\
OlOOOO
=
0
;
}
~
Itera\
tor
(
)
{
Fi\
nalise
(
)
;
}
void\

opera\
tor
++
(
)
{
if
(
lOO\
O\
OOlOOOO
)
lOOOOOl\
O\
OOO
=
lOOOOOl\
O\
OOO
->
lOOO\
OO\
lOOOl\

;
}
Type\

&
operator
*
(
)
{
ret\
urn
lOO\
OOO\
lO\
O\
OO
->
lOO\
OOO\
l\
OOlO
;
}
bo\
ol
AtEn\
d
(
)
{
re\
tur\
n\

lO\
OOOOlOOO\
O
==
0
;
}
private
:
fri\
en\
d
cl\
a\
ss
Li\
s\
t
;
void\

Initiali\
s\
e\

(
lO\
Ol\
lOOOOO\

*
lO\
OlllOOOl
)
{
lO\
OO\
O\
Ol\
OOOO
=
lO\
O\
ll\
lO\
O\
Ol
;
}
void
Finalise
(
)
{
lOO\
OO\
OlO\
OO\
O
=
0
;
}
lOOllOO\
O\
OO
*
lOOOOOl\
OOOO
;
}
;
cl\
ass
lO\
O\
OOO\
lOOl\
l
{
pu\
blic
:
lOOOO\
OlOO\
ll\

(
)
{
lOOOOO\
lO\
OOO
=
0
;
}
~
lOO\
O\
OOlOOll
(
)
{
Fin\
alise
(
)
;
}
vo\
id
ope\
rator
++
(
)
{
if
(
lOOO\
OO\
l\
OOOO
)
lOOO\
OOlOOOO
=
lOOO\
OO\
l\
OO\
OO
->
lOO\
OOO\
l\
OOO\
l
;
}
cons\
t
Type\

&
operator
*
(
)
{
re\
turn
lOOOOO\
lOOOO
->
lO\
O\
O\
OO\
lOOl\
O\

;
}
bool
AtE\
nd\

(
)
{
re\
turn
lO\
OOO\
OlO\
OOO
==
0
;
}
pr\
i\
vate
:
fr\
iend
clas\
s\

Li\
st
;
void
Init\
ialise
(
lOO\
ll\
OOOOO
*
lOOl\
l\
lO\
OOl\

)
{
lOOOOO\
l\
O\
OOO
=
lO\
O\
lllOO\
Ol
;
}
vo\
id\

Final\
ise\

(
)
{
lOOOOOlO\
OO\
O\

=
0
;
}
co\
nst\

lOOll\
O\
OOOO
*
lOOOOOl\
O\
OO\
O
;
}
;
List
(
)
;
~
Lis\
t
(
)
;
voi\
d
Finalis\
e\

(
)
;
void
Clea\
r
(
)
;
int\

lOOOll\
lOO\
l
(
)
co\
nst
;
bo\
ol
lOOO\
OO\
lOl\
O\
O
(
)
const
;
Ty\
pe
&
ope\
rator
[
]
(
int\

lOO\
OlOOlll
)
;
const
Ty\
pe\

&
ope\
r\
ator
[
]
(
int
lOOO\
lO\
Ol\
ll
)
co\
ns\
t\

;
Ty\
pe
&
lO\
O\
Ol\
l\
l\
OO\
O
(
)
;
void
lOOOl\
l\
l\
O\
O\
O\

(
con\
s\
t
Ty\
p\
e
&
lOO\
O\
lOOllO
)
{
lOOOlllOOO
(
)
=
lO\
OOlOOllO\

;
}
void
lOOOOOlOlOl
(
const
Type
&
lOOOlOO\
llO\

)
;
void
lOO\
l\
llll\
l\
l
(
con\
st\

Type
*
lOO\
O\
OOl\
OllO
)
;
It\
erator
lOlOOOOl\
OO
(
)
{
Itera\
t\
or
lOl\
OOl\
OOl\
O\

;
lO\
l\
OO\
l\
OOlO\

.
Initialise
(
lOOO\
OOlOlll
)
;
re\
turn
lOlOOl\
OOlO
;
}
lOO\
OOOlOO\
ll
lO\
OO\
OOllOO\
O
(
)
const
{
lO\
OOOOlO\
Oll
lOlO\
Ol\
OOlO
;
lOlO\
OlOOlO\

.
Initialise
(
lOO\
OOOlOll\
l
)
;
ret\
urn
lOl\
OO\
l\
OOlO
;
}
pro\
tec\
ted\

:
struct
lOOllOOO\
OO
{
Typ\
e
lOOO\
OOlO\
O\
lO
;
lOO\
ll\
OOO\
OO\

*
lO\
OOOOlOOOl
;
}
;
lOOl\
lOO\
OOO
*
lOO\
O\
O\
O\
l\
Olll
;
lO\
O\
l\
lOOOOO
*
lOOO\
OO\
llOOl
;
}
;
}
#include "../Common/zcta003.inl"
#endif //
