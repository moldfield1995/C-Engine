//---------------------------------------------------------------------------------
// File Name: zcta006.inl
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef TA_MEMORYMGR_H
#include "MemoryMgr.h"
#endif //
namespace
TA
{
temp\
late
<
class\

Ty\
pe
,
bool
lOOOl\
llllll
>
lOlOl\
llOlO
<
Ty\
p\
e\

,
lOOOll\
lllll\

>
::
lOl\
OlllOlO
(
)
{
lOlO\
OOlOOl
=
0
;
lOOlOO\
ll\
OOO
.
lO\
OlOOlOll\
l
=
0
;
lOOlOO\
llOOO
.
lOOOO\
OlO\
OO\
l
=
0
;
}
te\
mpla\
te
<
class
Typ\
e
,
bool
lOOOlllllll
>
lOl\
O\
l\
l\
lO\
lO
<
Typ\
e
,
lOO\
Oll\
lllll
>
::
~
lO\
lOlll\
OlO
(
)
{
Final\
i\
se
(
)
;
}
tem\
pla\
te\

<
class
Ty\
pe
,
bool
lO\
OO\
lllllll\

>
vo\
id
lOlOl\
l\
lOlO
<
Type
,
lO\
OO\
lllll\
ll
>
::
Initialise
(
int
lOOlllOllO\

)
{
if
(
lO\
O\
lO\
OllOOO
.
lOOlO\
O\
lOl\
l\
l
)
{
lOOOO\
OOllO
(
0
,
"Pool::Initialise. Already initialised.")
;
Fi\
n\
a\
l\
ise\

(
)
;
}
lOlOOO\
lOOl
=
lOO\
ll\
lOllO
;
lOOO\
l\
l\
llOO
(
lO\
O\
lOOllOO\
O
.
lOO\
l\
OOlOl\
ll
,
lOOllOO\
OOO\

,
lOlOOO\
lOOl
)
;
TA_ASS\
ERT
(
lO\
OlOO\
llOOO
.
lOO\
l\
OO\
lOl\
ll
)
;
lOOlOO\
llOOO
.
lOOOOO\
l\
OOOl
=
0
;
fo\
r
(
int\

lO\
OlOO\
llOlO\

=
0
;
lOOl\
OO\
ll\
OlO
<
lOO\
ll\
lOllO
;
lO\
Ol\
O\
Oll\
O\
lO
++
)
{
#ifdef _DEBUG
lOO\
lO\
Oll\
OOO
.
lOOlOOlO\
lll\

[
lO\
OlOO\
l\
lOlO
]
.
lO\
OOOOlO\
O\
O\
l
=
0
;
lO\
OlOOllOOO
.
lOOlO\
OlOlll
[
lOOlOOllOlO
]
.
lOO\
l\
OOOOO\
l\
O
=
0
;
#endif //
lO\
O\
lO\
OllOOl
.
lO\
lOlO\
O\
OOl
(
&
lOO\
lO\
Oll\
OOO
.
lOO\
lOO\
lOll\
l
[
lOO\
lOOl\
lOlO\

]
.
lOOOOO\
lOOlO
)
;
}
}
te\
mp\
la\
te\

<
class
Type\

,
bool\

lOOOl\
ll\
llll\

>
void
lOlO\
lllOl\
O
<
Type
,
lOO\
Olllllll
>
::
Fin\
a\
l\
i\
se
(
)
{
lO\
O\
lOOl\
lOO\
l
.
Finalis\
e
(
)
;
fo\
r\

(
lOOlO\
OlO\
l\
lO
*
lOO\
lOOll\
Oll
=
&
lOOl\
OOl\
lOOO\

;
lO\
O\
lOO\
ll\
Oll
;
)
{
lO\
O\
lOOlOllO
*
lO\
OlOOlllOO\

=
lOOl\
OOl\
l\
O\
ll
->
lOOOOO\
l\
OOOl\

;
if
(
lO\
OlOO\
ll\
Ol\
l
->
lOOl\
O\
O\
lOlll
)
{
lO\
l\
OOO\
lll\
O
(
lOOl\
OOllO\
ll
->
lOO\
l\
O\
OlOlll
,
lOOll\
OO\
O\
OO
)
;
lOOlO\
OllOll\

->
lOOlO\
Ol\
O\
lll
=
0
;
lO\
OlOOllOll
->
lOOOOOl\
OOOl
=
0
;
}
if
(
lO\
OlO\
Oll\
O\
l\
l\

!=
&
lOOlOO\
ll\
OOO
)
{
lOO\
lO\
OOOOO
(
lO\
Ol\
OOllOll\

,
lOOlOOlOllO
)
;
}
lOO\
lO\
Oll\
Oll\

=
lO\
O\
lOOlllOO\

;
}
lOlOOOlOOl
=
0
;
}
temp\
lat\
e\

<
class
Type
,
bo\
ol
lOO\
Olllllll
>
bool
lOlOlllOlO
<
Type
,
lOOOl\
lllll\
l\

>
::
lOOlOOl\
OO\
ll
(
)
{
retur\
n
lOOlOOllOOO
.
lOOl\
OOlO\
lll\

!=
0
;
}
temp\
lat\
e\

<
clas\
s
Type
,
bool
lOOOll\
lllll
>
Typ\
e
*
lOl\
Oll\
lOl\
O
<
Type
,
lOOO\
l\
lllll\
l
>
::
Al\
loc\

(
)
{
lOOllOOOOO
*
lO\
Oll\
l\
OOOl
=
lOOl\
OOl\
l\
OOl
.
lOOlOO\
lOO\
OO
(
)
;
if
(
!
lOOlllOOOl
)
{
if
(
!
lO\
OOllllll\
l\

)
ret\
urn
0
;
lO\
OlO\
OlOl\
l\
O
*
lO\
OlOOl\
llOl
=
&
lOOlOOllOO\
O
;
TA\
_ASSERT
(
lOOlO\
Olll\
O\
l
)
;
whi\
le
(
lO\
O\
lOO\
lllOl
->
lOOO\
OOlOOOl
)
lOOlOOlllOl
=
lOOl\
OOlllOl
->
lOOOOOl\
OOOl\

;
lOO\
l\
OO\
lOllO
*
lOOlOOllOl\
l
;
lOO\
OOOll\
OlO
(
lOO\
l\
O\
O\
llO\
ll\

,
lOOl\
OOl\
OllO
)
;
lOOOll\
llOO
(
lOOlOOllOl\
l
->
lOOl\
OOlOl\
ll
,
lOOllOOOOO
,
lOlOO\
OlO\
Ol
)
;
TA_\
A\
S\
SER\
T
(
lOlOOOlOOl
>
0
)
;
TA\
_A\
SSERT\

(
lOOlOOll\
Oll
->
lO\
Ol\
OOlOlll
)
;
lOO\
l\
OOllOll
->
lOOOO\
OlOOOl\

=
0
;
lOOlO\
Oll\
lOl
->
lOOOOO\
l\
OOOl
=
lO\
OlOOl\
lO\
ll\

;
for\

(
int\

lOOlOOl\
lOlO\

=
0
;
lOOlO\
O\
llO\
lO
<
lO\
lOOOlOOl\

;
lOO\
lO\
O\
ll\
O\
lO
++
)
{
#ifdef _DEBUG
lOOlOO\
llOl\
l\

->
lOOl\
OOlO\
l\
ll
[
lOOlO\
Ol\
lOlO
]
.
lO\
OOOO\
lOOOl
=
0
;
lOOlO\
OllOl\
l
->
lO\
OlO\
OlOll\
l\

[
lOOlOOllO\
lO
]
.
lO\
OlOO\
O\
OOlO
=
0
;
#endif //
lO\
OlO\
O\
l\
lOOl\

.
lOlOl\
OOOOl\

(
&
lOOl\
OOllOll\

->
lO\
O\
l\
O\
OlOlll
[
lOO\
lO\
OllO\
lO\

]
.
lO\
OOOOlOOlO
)
;
}
lO\
l\
OOO\
lO\
O\
l
<<=
1
;
lOO\
ll\
l\
OO\
O\
l\

=
lOOl\
OOl\
lOOl
.
lOOlOOl\
OO\
OO
(
)
;
}
lOOlO\
Ol\
lOO\
l
.
lOO\
l\
l\
lllll\

(
&
lOOl\
llOOO\
l\

->
lOOOOOlOOlO
)
;
retu\
rn
&
lOO\
l\
llOOOl
->
lO\
OOOOlO\
Ol\
O
;
}
tem\
plate
<
cla\
s\
s\

Typ\
e\

,
bool
lOOOlllllll
>
void
lOlOlllOl\
O
<
Type
,
lO\
OOllllll\
l\

>
::
Free
(
Type
*
lOOlll\
OOOl
)
{
lOOlOOllOO\
l
.
lOlOl\
OOOOl
(
lOOlllO\
OOl\

)
;
}
te\
mp\
late
<
class
Type
,
bool\

lO\
OO\
llllll\
l\

>
void
lOlO\
ll\
lOlO
<
Typ\
e\

,
lO\
OOlllllll
>
::
llO\
lO\
lO\
O\
l\
l
(
lOlO\
lllOl\
l
&
lOOlO\
O\
OlOlO\

)
{
typen\
ame
lOlOlll\
Oll\

::
Ite\
r\
ato\
r
lO\
lOOl\
OOlO
=
lOOlOOOlO\
lO
.
lOlO\
OOOlOO
(
)
;
while
(
!
lOl\
OO\
l\
O\
OlO
.
AtE\
nd
(
)
)
{
Type
&
lOOl\
O\
OllllO\

=
*
lOlO\
OlOOlO\

;
++
lOlOOlOOl\
O
;
lOOlOOOlOlO
.
lOOl\
lll\
lll
(
&
lOOlO\
OllllO
)
;
Free\

(
&
lO\
OlOOll\
ll\
O\

)
;
}
}
templa\
t\
e
<
class
Type\

,
bool
lOO\
Ol\
llllll
>
int
lOlOlll\
OlO
<
Type
,
lOOOll\
lll\
ll
>
::
lO\
O\
lOOlOlOO
(
)
{
re\
t\
urn
lOO\
lOOllO\
Ol
.
lOO\
Olll\
OOl
(
)
;
}
tem\
p\
late
<
clas\
s
Type
,
bool
lOOOll\
ll\
lll
>
bool
lOlOll\
lOlO
<
Ty\
pe
,
lOOOllll\
ll\
l
>
::
lOOlOOlOlOl
(
)
{
if
(
lO\
OOlllllll
)
retu\
r\
n
true
;
retu\
rn
!
lOOlOOll\
OOl\

.
lOl\
OO\
O\
OlOO
(
)
.
AtE\
nd\

(
)
;
}
templ\
ate
<
class
Type
,
bool
lOOO\
l\
llllll
>
int\

lOlOlllOlO
<
Type
,
lO\
OOl\
ll\
llll
>
::
lOOO\
lll\
OOl
(
)
{
re\
t\
urn\

lOl\
OOOlOO\
l
;
}
}
