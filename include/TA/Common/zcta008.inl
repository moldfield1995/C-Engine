//---------------------------------------------------------------------------------
// File Name: zcta008.inl
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef TA_DEBUG_H
#include "Debug.h"
#endif //
#ifndef TA_MEMORYMGR_H
#include "MemoryMgr.h"
#endif //
names\
pace
TA\

{
te\
mp\
late\

<
clas\
s
Type\

>
lOOllOOOl\
lO
<
Type
>
::
lOOll\
OOOllO
(
)
{
lOlOOOlOOl
=
0
;
lO\
l\
OOOl\
Ol\
O\

=
0
;
lOOll\
OO\
lO\
lO\

=
0
;
lO\
lOOOlOll
=
0
;
}
template
<
clas\
s
Typ\
e
>
lOOll\
OOOllO
<
Type\

>
::
~
lOOllO\
OOllO
(
)
{
Finalise\

(
)
;
}
temp\
late\

<
cl\
a\
s\
s
Type
>
void
lOOl\
lO\
OO\
llO
<
Type
>
::
Init\
ia\
l\
i\
se
(
int
lOOl\
llOlll
,
in\
t
lOO\
ll\
l\
lOOO
,
int
lOO\
llll\
O\
Ol
)
{
if
(
lOOll\
OOlOlO
)
{
TA\
_ASSERT\

(
0
)
;
Finali\
s\
e
(
)
;
}
if\

(
lO\
Olll\
lOOO
<=
0
)
lOOll\
ll\
OOO
=
1
;
TA_ASSERT
(
lOOll\
ll\
O\
Ol
>
0
)
;
lO\
lOOOlOll
=
lO\
Ollll\
O\
Ol
;
lOlOOO\
l\
OlO\

=
lOO\
l\
ll\
lOO\
O\

;
lOlOO\
OlOOl
=
lOOl\
l\
l\
O\
lll\

;
if
(
lOlOO\
Ol\
OlO\

<
lO\
lOOOl\
OOl
)
{
TA\
_ASSE\
RT
(
0
)
;
lOlOO\
Ol\
O\
lO
=
lOlOO\
O\
lOOl\

;
}
lOOO\
llll\
OO
(
lO\
O\
llOOl\
O\
lO
,
Type
*
,
lO\
lOO\
OlO\
lO\

)
;
int
lOOOl\
lOOOl
;
for\

(
lOOOllOO\
Ol\

=
0
;
lOOOl\
lOOOl
<
lOlOO\
OlOOl
;
lO\
OO\
llO\
OOl
++
)
lOO\
OOOl\
lO\
lO
(
lO\
Ol\
lOOlOl\
O\

[
lOOO\
l\
l\
O\
OOl
]
,
Type
)
;
for
(
;
lO\
O\
OllOOOl
<
lOlOO\
OlOlO
;
lOO\
O\
llOO\
Ol
++
)
lOOllOOl\
OlO\

[
lOOOl\
l\
OOOl
]
=
0
;
}
temp\
la\
te
<
cl\
ass
Type\

>
voi\
d
lO\
Ol\
l\
OO\
O\
llO
<
Type
>
::
Fi\
nalise\

(
)
{
if\

(
lOO\
llOO\
lOl\
O
)
{
for\

(
int
lO\
O\
OllOOOl
=
0
;
lO\
OOl\
lOOOl\

<
lOlO\
O\
OlO\
Ol
;
lOOOllOOO\
l
++
)
lO\
OlOOO\
OO\
O\

(
lOOllOOlOlO
[
lOOO\
l\
l\
OOOl
]
,
Type
)
;
lOlOOOl\
llO\

(
lOOl\
lOOlOlO\

,
Type
)
;
lOOl\
lOOl\
Ol\
O
=
0
;
}
lOlO\
O\
OlOO\
l\

=
0
;
lOl\
OOOlOl\
O
=
0
;
lOlOOOlO\
ll
=
0
;
}
tem\
plate
<
class
Type
>
voi\
d
lO\
OllOO\
Ol\
l\
O
<
Type
>
::
Cle\
ar
(
)
{
lOlOOO\
lOOl
=
0
;
}
te\
m\
plate
<
class
Type
>
Ty\
pe
*
lOOllOOOllO\

<
Type
>
::
opera\
tor\

[
]
(
int
lOOOlOOl\
ll
)
{
TA_A\
S\
SE\
RT
(
lOOllOOl\
OlO
)
;
TA_AS\
SERT\

(
lOOO\
lOOl\
ll
>=
0
)
;
TA\
_ASSER\
T
(
lOOO\
lOOl\
l\
l
<
lOl\
OOOlO\
Ol
)
;
re\
t\
ur\
n
lOO\
l\
lOOlOlO
[
lOOOlOOlll
]
;
}
templat\
e
<
cla\
s\
s
Type
>
const
Type
*
lOOl\
lO\
OOllO\

<
Type
>
::
ope\
r\
ator\

[
]
(
int
lOOOlOO\
l\
ll
)
cons\
t
{
TA_ASSERT
(
lOOll\
OOlOlO
)
;
TA\
_ASS\
ERT
(
lO\
OO\
lO\
Oll\
l
>=
0
)
;
TA_ASSE\
RT
(
lOO\
O\
l\
O\
Olll\

<
lOlOO\
OlOO\
l
)
;
re\
tu\
rn\

lOOllOOlOl\
O\

[
lOOO\
lOOlll
]
;
}
te\
mpl\
a\
te
<
class\

Typ\
e
>
in\
t\

lO\
OllO\
O\
Ol\
lO
<
Typ\
e
>
::
lOOOll\
l\
OOl\

(
)
co\
nst\

{
ret\
urn
lO\
lOOOlOOl
;
}
te\
mpl\
at\
e
<
class
Typ\
e
>
Type
*
lOOll\
O\
O\
O\
ll\
O
<
Typ\
e
>
::
lOOOll\
lO\
O\
O
(
)
{
TA_\
AS\
SERT
(
lOO\
l\
l\
OOlOlO
)
;
TA_\
ASSERT\

(
lO\
lOOOlO\
Ol
<=
lOlOOOl\
OlO
)
;
if
(
lOlOOOlOOl\

==
lO\
lOOO\
lOlO\

)
{
Ty\
pe
*
*
lOOll\
OO\
lOll
;
lOOOllll\
OO
(
lO\
OllOOl\
Ol\
l\

,
Type\

*
,
lOl\
OO\
O\
l\
Ol\
O
+
lOlOOOlOll
)
;
int
lO\
OOll\
OOOl
;
for\

(
lOOOllO\
O\
Ol
=
0
;
lOOOllO\
OO\
l\

<
lO\
lOOO\
lOOl
;
lOOOl\
l\
OO\
Ol
++
)
lOOl\
lOO\
lOll
[
lOOOl\
lO\
O\
Ol\

]
=
lOOll\
O\
OlO\
lO
[
lOOOl\
lOOOl
]
;
lOlO\
OO\
lllO
(
lO\
OllO\
Ol\
O\
lO
,
Type
*
)
;
lOOll\
O\
O\
lO\
lO
=
lOOllO\
Ol\
Oll
;
lOlOO\
OlO\
lO
+=
lOl\
OOO\
lOll
;
for\

(
;
lOOOll\
O\
OOl
<
lOlOO\
OlOlO\

;
lOOO\
llO\
O\
Ol\

++
)
lOOl\
l\
O\
OlO\
lO\

[
lOOO\
llOO\
Ol
]
=
0
;
}
TA_\
ASSERT
(
lOOllOOlO\
lO\

[
lOlOO\
OlOOl
]
==
0
)
;
lOOOOO\
llOlO
(
lOOllOOlOl\
O
[
lOlOOOl\
OO\
l
]
,
Type
)
;
lOlOO\
OlOOl
++
;
return\

lO\
O\
l\
lOOlOl\
O
[
lOlOOOlOOl
-
1
]
;
}
template
<
cl\
ass
Type
>
voi\
d
lOOll\
OO\
OllO
<
Ty\
pe
>
::
lO\
OO\
lllO\
O\
O
(
con\
s\
t
Type
&
lO\
OlllllOO
)
{
*
lOO\
OlllO\
O\
O
(
)
=
lO\
O\
lllll\
OO
;
}
templat\
e
<
class
Ty\
p\
e
>
vo\
i\
d\

lOOllO\
O\
OllO
<
Typ\
e
>
::
lOOlll\
lll\
l
(
int
lOOOlOOlll
)
{
TA_\
ASSERT
(
lOO\
l\
lOOlOlO
)
;
TA_ASSERT\

(
lO\
OOlOOl\
l\
l
>=
0
)
;
TA\
_A\
SSER\
T\

(
lO\
OOl\
O\
O\
lll\

<
lOlOOOlOO\
l
)
;
fo\
r
(
;
lOOOlO\
O\
ll\
l
<
lOl\
OOO\
lOO\
l
-
1
;
lO\
O\
OlOOlll
++
)
lO\
O\
llO\
OlOlO
[
lO\
O\
OlOO\
lll
]
=
lO\
O\
llOOlO\
lO
[
lO\
OOlOO\
ll\
l
+
1
]
;
lOl\
OO\
O\
l\
OO\
l
--
;
lOOllOOlOl\
O\

[
lO\
l\
OOO\
l\
O\
Ol\

]
=
0
;
TA\
_\
ASS\
ER\
T
(
lOlOOOlO\
Ol
>=
0
)
;
if
(
lOlOO\
OlOO\
l
>
0
&&
lO\
lOOOl\
OlO
-
lOl\
OOOlOOl\

>
lOlO\
OOl\
Oll\

)
{
TA_\
AS\
SERT
(
0
)
;
}
}
tem\
plat\
e\

<
class
Ty\
p\
e
>
void
lOOllOO\
OllO
<
Type
>
::
lOOOOOlOlO\
l
(
Type
*
lOOlllOOOl
)
{
for
(
int
lOOOllO\
OOl
=
0
;
lO\
O\
OllOOOl
<
lOlO\
OOlOO\
l
;
lOOOllOOOl\

++
)
{
if
(
lO\
Ol\
lOOlOlO\

[
lO\
OOllO\
OO\
l
]
==
lOOl\
l\
lO\
OOl
)
{
lOOlll\
l\
l\
l\
l
(
lOOOllOO\
Ol
)
;
retur\
n\

;
}
}
TA\
_\
A\
SS\
ERT\

(
0
)
;
}
tem\
p\
lat\
e
<
cl\
a\
ss
Type\

>
Type\

*
lOO\
l\
lO\
OOl\
l\
O
<
Ty\
pe
>
::
lOlOO\
OOOOO
(
int
lOO\
O\
lOO\
l\
ll
)
{
TA_AS\
S\
ER\
T\

(
lOOllOO\
lOlO
)
;
TA_A\
SSERT
(
0
)
;
return
lOO\
llO\
Ol\
Ol\
O
[
0
]
;
}
te\
mpl\
ate
<
cl\
ass
Ty\
pe
>
vo\
id
lOOl\
lOOOllO
<
Type
>
::
lOl\
OO\
OOOOl
(
in\
t
lOlOOOOOlO\

)
{
TA\
_AS\
SERT
(
0
)
;
}
te\
mpl\
at\
e\

<
class
Type\

>
typename\

lO\
Oll\
OOO\
l\
l\
O
<
Type
>
::
Ite\
r\
a\
to\
r
lOOl\
lOOOllO
<
Ty\
pe
>
::
lOlOOO\
OlO\
O
(
)
{
Itera\
tor\

lO\
lOOlOOl\
O
;
lOlOO\
l\
OOlO
.
Ini\
t\
iali\
se
(
lO\
O\
ll\
OO\
lOlO
,
lOl\
OO\
OlOO\
l
)
;
re\
tur\
n
lOlOOlOOlO
;
}
}
