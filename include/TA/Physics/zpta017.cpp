//---------------------------------------------------------------------------------
// File Name: zpta017.cpp
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#define TA_PHYSICS_INTERNAL
#define lOllOllOOlO
#include "../Physics/zpta007.h"
#ifndef TA_GEOMETRY_H
#include "../Common/Geometry.h"
#endif //
#ifndef TA_COLLISIONOBJECTCACHEDPOLYDATA_H
#include "CollisionObjectCachedPolyData.h"
#endif //
namespace\

TA
{
const\

float
lOO\
lOlOOO\
lO\
l
=
Sqrt
(
k_fMaxFl\
oa\
t
)
;
const
flo\
at\

lOO\
l\
OlOOOl\
l\
O
=
k_fMinFl\
o\
at
;
con\
st\

flo\
at\

lOOlOlOO\
Olll
=
Sq\
rt
(
3.0f
)
;
floa\
t
llOOl\
lOOOll
=
1.0f
;
bo\
ol\

TAC_CALL
lllO\
llll\
OOO
(
Co\
lli\
si\
o\
n
&
llOllllOl\
ll
,
lOllO\
lllO\
OO\

*
lOO\
lOlOOlOOO
)
{
TA_ASSERT
(
lOOl\
OlO\
OlOOO
)
;
lOllOlll\
O\
OO
&
lOO\
O\
O\
O\
l\
OOlO
=
*
(
lO\
llOlllOO\
O
*
)
lOOlO\
lOOlOOO\

;
if
(
!
lO\
O\
O\
OOlOOlO
.
lOllOl\
lll\
OO
)
{
llOll\
llOlll
.
lOllOO\
Olll\
l
=
lOOO\
OOlO\
O\
l\
O
.
lOll\
OOOllll\

;
llOlll\
lOl\
ll
.
lO\
llOOlOOOO
=
lOO\
OOOlOOl\
O\

.
lOllOOl\
OOO\
O
;
}
else
{
llOl\
ll\
l\
O\
lll
.
lOl\
l\
OOOllll
=
lOO\
OO\
OlOOlO
.
lO\
l\
lOO\
lOOO\
O
;
llOllll\
O\
lll
.
lOllO\
OlOOOO\

=
lOOO\
O\
OlOO\
lO
.
lOl\
lO\
OOl\
l\
ll
;
llOllll\
Olll
.
lO\
O\
OOlllll
*=
lOOOOOlOO\
l\
O
.
lOllOlll\
llO
;
ll\
Olll\
l\
O\
lll\

.
lOOOlOOOO\
O
*=
lOOO\
OO\
lOO\
l\
O
.
lOllOll\
lllO
.
m33Rotati\
on\

;
llOl\
lllOlll
.
lOOOl\
OO\
OOO
=
-
llOllllOlll
.
lO\
OOlO\
OOOO
;
Sw\
ap
(
llO\
l\
lllO\
lll
.
lO\
l\
lOOlOOOl
,
ll\
Olll\
lO\
lll\

.
lO\
l\
l\
O\
O\
l\
OOl\
O
)
;
}
TA_ASS\
ERT\

(
lOOO\
O\
O\
lOOlO
.
lOllOll\
lOOl\

)
;
return
lO\
O\
O\
OOl\
OOl\
O
.
lOllOlll\
OOl\

(
ll\
Ollll\
O\
lll
,
lOOO\
OOlOO\
lO
.
lOll\
OlllO\
l\
O
)
;
}
bool
TA\
C_C\
ALL
lll\
OOl\
lOlll\

(
Col\
l\
isi\
o\
n
&
llOlll\
l\
Olll
,
lOllOll\
l\
OO\
O
*
lO\
OlOlOOlOO\
O
)
{
TA_ASSERT
(
lOOl\
Ol\
OOlOOO\

)
;
lO\
llO\
ll\
lO\
O\
O
&
lOOOOO\
lOOl\
O
=
*
(
lOllO\
lllOOO
*
)
lOOlOlOO\
lOOO
;
if
(
!
lOOOOOl\
OOlO\

.
lOllOll\
l\
l\
O\
O\

)
{
llOllllOlll
.
lO\
llO\
OOl\
ll\
l
=
lO\
O\
O\
O\
O\
l\
OO\
lO\

.
lOllOOOllll
;
llOll\
llOlll
.
lO\
ll\
OOlOOO\
O
=
lO\
OO\
OOl\
OOlO
.
lO\
l\
lO\
OlOOOO\

;
}
else
{
llO\
l\
ll\
lOll\
l\

.
lOl\
lOOO\
llll
=
lOOOOOlOOl\
O
.
lOl\
lOO\
l\
OO\
OO
;
llO\
l\
lllOlll
.
lOllOO\
lOOOO
=
lOOOOO\
lOOl\
O
.
lOll\
OOOllll
;
llO\
l\
ll\
lOl\
ll\

.
lO\
OO\
O\
llll\
l
*=
lOOOOOl\
OOlO
.
lOl\
lOllll\
lO\

;
llO\
llll\
O\
ll\
l
.
lOOOlO\
O\
OOO\

*=
lOOOOOl\
OOl\
O
.
lOllO\
l\
lll\
lO
.
m3\
3R\
ota\
ti\
on
;
llOl\
l\
llOlll
.
lOOO\
lOOOOO
=
-
ll\
Ollll\
Olll
.
lOOOlO\
OO\
OO
;
Swap
(
llOlll\
lOlll
.
lOllO\
O\
lOOOl\

,
llO\
l\
ll\
lOll\
l
.
lOllO\
OlOO\
lO
)
;
}
if\

(
llOllllOll\
l\

.
lOll\
OOOl\
lll
->
GetCollisi\
onObjectT\
yp\
e
(
)
==
Collis\
io\
nOb\
ject
::
TYPE_\
C\
A\
C\
HED_POLY_DATA
)
ll\
O\
lll\
lOlll
.
lOll\
O\
OO\
llll
=
(
(
CollisionOb\
ject\
CachedPol\
y\
D\
at\
a
*
)
llOlll\
lO\
l\
l\
l
.
lOl\
lOOOll\
ll
)
->
lll\
OlOOl\
Ol\
l\

(
)
;
if
(
llOl\
lllOlll
.
lOll\
OOlOO\
OO
->
Ge\
tCollisi\
onOb\
j\
ectType\

(
)
==
Coll\
isionObje\
ct\

::
TYPE\
_CAC\
HED_POL\
Y\
_DAT\
A
)
llOl\
lllOl\
ll
.
lOllO\
OlOOO\
O
=
(
(
Collision\
Object\
CachedPolyD\
ata\

*
)
llO\
lll\
lOl\
ll
.
lOllOO\
lO\
O\
OO
)
->
lllOlOOlOll
(
)
;
TA_ASSERT
(
lOOOOOlOOlO\

.
lO\
l\
lOlllO\
Ol
)
;
retu\
rn
lO\
OOOOl\
OOl\
O
.
lOl\
l\
OlllO\
Ol
(
ll\
Oll\
llOll\
l
,
lOOOOOl\
OO\
lO
.
lOllOlll\
O\
lO
)
;
}
in\
lin\
e\

fl\
o\
at
TAC_CALL\

lOOlOlOOl\
O\
O\
l
(
fl\
oa\
t
lO\
OOOO\
lllO
)
{
retu\
rn
(
lOOOOOlllO\

>=
0.0f
)
?
Exp
(
Log
(
lO\
OOOOlllO
)
*
(
1.0f
/
3.0f
)
)
:
-
Ex\
p
(
Log
(
-
lOOOOOlll\
O
)
*
(
1.0f
/
3.0f
)
)
;
}
int
TAC_CALL
lO\
O\
l\
OlOO\
lOl\
O
(
flo\
at\

llll\
O\
OOO\
OO
,
flo\
at
lllOl\
ll\
ll\
l
,
flo\
at
lOOO\
lllOlllO
[
2
]
)
{
flo\
a\
t
lOOl\
OlO\
OlOll
=
llllOOOOO\
O
*
llll\
OOOOOO
-
4.0f
*
lllOll\
llll\

;
if
(
lO\
OlOlO\
OlOll
<
0.0f
)
{
lOOOl\
l\
lOl\
ll\
O
[
0
]
=
0.0f
;
lOO\
Ol\
llO\
lll\
O\

[
1
]
=
0.0f
;
return
0
;
}
lO\
O\
lO\
lOOlOll
=
Sqr\
t
(
lOOl\
OlOO\
lO\
ll
)
;
lOOO\
lll\
Oll\
lO
[
0
]
=
(
-
llllOOO\
OO\
O\

-
lO\
OlOlOOl\
Oll
)
*
0.5f
;
lOOOl\
l\
lOll\
lO
[
1
]
=
(
-
llll\
OOO\
OOO
+
lOOl\
Ol\
OOlOl\
l\

)
*
0.5f
;
ret\
urn
2
;
}
float
TAC_CALL
lOOlOlO\
Oll\
OO
(
flo\
at
llll\
O\
OOO\
lO
,
floa\
t\

ll\
l\
lO\
OOOOO\

,
floa\
t
ll\
lOll\
llll\

)
{
if
(
Fabs
(
lll\
lOOOOl\
O
)
>
lOO\
l\
OlOO\
OlOl
)
re\
tu\
rn\

-
lll\
lOOOOlO
;
if
(
Fa\
bs\

(
llllOOOOOO\

)
>
lOO\
lOlOOO\
lO\
l
)
{
if
(
ll\
llO\
OOOOO\

>
0.0f
)
retu\
rn
-
lllOllll\
ll
/
llllOOOOOO
;
el\
se\

re\
tur\
n
-
Sqrt\

(
-
lll\
lOO\
OOOO
)
;
}
if\

(
Fabs\

(
lll\
Ollllll
)
>
lOOlOlOO\
OlOl
)
return\

-
lOOlOlOO\
lOOl
(
lll\
Olllll\
l
)
;
float
lO\
O\
lOlO\
OllOl
=
llllOOO\
OlO\

*
(
1.0f
/
3.0f
)
;
float\

lOOlO\
l\
O\
Oll\
lO
=
lOOl\
Ol\
OOllOl
*
lOO\
lOlOO\
llOl
;
if
(
lOOlOlO\
Ol\
llO\

>
lOOlOlOO\
OlO\
l\

)
ret\
urn\

-
lll\
lOOO\
O\
lO
;
flo\
at
lOO\
lO\
lOO\
lll\
l
=
lllOll\
llll
+
lOOlOlOOl\
lOl
*
(
lOOl\
O\
lOOlllO
+
lOO\
lOlOOlllO
-
llll\
O\
O\
OO\
O\
O
)
;
if
(
Fabs
(
lOOlO\
lOOllll
)
>
lOO\
lO\
lOOOlOl
)
return
-
ll\
l\
l\
OO\
OO\
lO
;
flo\
at\

lOOlOl\
OlO\
OOO
=
llll\
OOOOOO
*
(
1.0f
/
3.0f
)
;
float\

lOOOl\
l\
l\
O\
ll\
O\
O
=
lOOlOlOl\
OO\
OO
-
lOOlOlO\
O\
lll\
O
;
float
lOOlOlO\
lOOOl
=
lOOOlllO\
l\
lOO\

+
lOO\
O\
lll\
O\
llOO
;
if
(
Fabs\

(
lO\
OlOl\
O\
lO\
OOl
)
>
lOOlO\
lOOOlOl\

)
{
if
(
ll\
l\
l\
OOOOl\
O
!=
0.0f
)
return\

-
llll\
OOO\
OOO
/
llllOOOO\
l\
O
;
if
(
llllO\
O\
OO\
OO
>
0.0f
)
re\
t\
urn
-
lllOllllll
/
ll\
llO\
O\
O\
OOO\

;
else
retu\
r\
n\

-
Sq\
rt
(
-
ll\
llO\
OOOO\
O
)
;
}
float
lO\
OlOlOlO\
OlO
=
lOOlOlOlOOOl
*
lOOlOl\
Ol\
OO\
Ol
;
if\

(
lOOlOl\
OlOO\
l\
O
>
lOOlOl\
OOOlO\
l
)
{
if\

(
lll\
lOO\
OOl\
O
!=
0.0f
)
retu\
rn\

-
llllO\
OOOO\
O
/
llllOOO\
Ol\
O\

;
if
(
llll\
O\
OOOOO\

>
0.0f
)
re\
tu\
rn
-
lll\
O\
l\
lllll
/
ll\
llOOO\
OO\
O\

;
else
ret\
u\
r\
n\

-
Sqr\
t
(
Fabs
(
ll\
llO\
OOOOO
)
)
;
}
float
ll\
lO\
Ol\
lOOl
=
lOOlOlOlOOlO
*
lOOO\
lllO\
llO\
O
+
lOOlOl\
OOl\
lll
*
lOO\
lOlOO\
llll
;
if
(
lll\
OOllOO\
l\

>=
0.0f
)
{
floa\
t\

lOO\
l\
O\
lOl\
OOll
=
lOO\
lOlO\
OlOO\
l
(
lOOlOlO\
O\
llll
<=
0.0f
?
(
-
lOOl\
OlOO\
lll\
l
+
Sq\
rt
(
lll\
OO\
ll\
OOl
)
)
*
0.5f
:
(
-
lO\
O\
lOlOO\
ll\
ll
-
Sqrt
(
lll\
OOl\
lOOl\

)
)
*
0.5f
)
;
if\

(
lOOlO\
lOlOOll
!=
0.0f
)
ll\
lOO\
l\
lOOl
=
-
lOOO\
lllOllOO
/
lOOl\
OlOlOOll
;
else
lllOOllOO\
l
=
0.0f
;
ret\
urn
lOOl\
OlOlO\
Oll
+
ll\
lOO\
llOOl\

-
lOOlOlO\
O\
ll\
Ol
;
}
if
(
lO\
OOl\
llOllO\
O
>=
0.0f
)
retu\
rn
lO\
OlOl\
OOlOOl
(
lOOlOl\
OOllll
)
-
lOOlO\
lOO\
llOl
;
ll\
lO\
OllOOl
=
Sqrt
(
-
lOOOll\
l\
Ol\
lOO
)
;
flo\
a\
t
lOOlO\
l\
OlOlOO\

=
-
lOO\
lOlO\
Oll\
ll\

/
(
lllOOll\
OOl
*
-
lOOOll\
lOll\
OO
*
2.0f
)
;
Clamp\
Po\
s\
N\
eg
(
lOOlOlO\
lOl\
OO\

,
1.0f
)
;
float\

lOO\
OOllOlOO\

=
Cos
(
ACo\
s
(
lOOlOlOlOlO\
O
)
*
(
1.0f
/
3.0f
)
)
;
if
(
lOOl\
OlOO\
l\
l\
Ol
<
0.0f
)
retu\
rn
lll\
OOllO\
Ol
*
2.0f
*
lOOOOllOl\
O\
O
-
lOOlOl\
OOll\
Ol
;
floa\
t\

lOOlO\
lOlOlOl
=
1.0f
-
lOOOOllOlOO
*
lO\
OOOllO\
lOO
;
if
(
lOOlOl\
OlO\
l\
O\
l
<
0.0f
)
lOOlOl\
OlOlO\
l
=
0.0f
;
re\
tu\
rn
lllOOllOOl
*
(
-
lOOOOllOlOO
-
lOOlOlOOOlll
*
Sqrt\

(
lOOlOlOlOlOl
)
)
-
lO\
OlOlO\
O\
ll\
O\
l
;
}
int
TAC_C\
A\
LL\

lOOOllllOOO\
O
(
float
ll\
llOO\
O\
O\
lO
,
floa\
t
lll\
lOOO\
O\
O\
O
,
float
lllOlll\
lll
,
flo\
at
lOOO\
lllOllOO
,
float
lO\
O\
O\
lllOll\
lO
[
4
]
)
{
fl\
oat
lOOl\
O\
lO\
lO\
ll\
O
=
lll\
l\
O\
OOOl\
O
*
ll\
ll\
OO\
OOlO
;
float
lOlOOO\
l\
Ol\
Ol
=
lOOl\
OlO\
OllO\
O\

(
llllOOOO\
OO
,
llllOOOO\
l\
O
*
lll\
O\
llllll
-
4.0f
*
lOOOll\
l\
OllOO
,
(
lOOlOl\
OlOll\
O\

-
4.0f
*
lll\
l\
OOOO\
OO
)
*
lOOO\
lll\
Ol\
lO\
O
+
lllOllll\
l\
l
*
lll\
Ol\
lllll
)
;
flo\
at
lOOlO\
lO\
lOll\
l
=
0.25f
*
lOOl\
Ol\
O\
lOllO
-
lll\
lOOOO\
OO\

-
lOlOOOlOlOl\

;
if
(
lOOl\
Ol\
OlO\
l\
l\
l
<
0.0f
)
retu\
rn
0
;
float
lOOlOlOll\
OOO
=
0.25f
*
lOlOO\
Ol\
OlOl
*
lOlOOOl\
O\
lO\
l
-
lOO\
OlllOllOO
;
if
(
lO\
OlOlOll\
OO\
O
<
0.0f
)
return
0
;
flo\
at
lOOl\
OlOllO\
Ol
=
-
(
0.25f
*
lll\
lOOOOlO
*
lOlOO\
O\
lOlOl
+
0.5f
*
lllOlll\
ll\
l
)
;
float
lOOlO\
lOO\
llll
;
float
lOOl\
Ol\
Ol\
lOlO
;
if\

(
(
(
(
(
u32
&
)
llll\
O\
O\
O\
Ol\
O\

)
^
(
(
u32\

&
)
ll\
llOOOO\
O\
O
)
^
(
(
u32\

&
)
ll\
lOllllll
)
)
&
0x80000000
)
==
0
||
llllOOOOlO
==
0.0f
||
llllOOOOOO
==
0.0f
||
lllO\
llll\
ll
==
0.0f
)
{
if
(
llllOOO\
OOO
<
0.0f
&&
lOlOO\
O\
l\
OlOl\

<
0.0f
&&
lOO\
lOlOl\
Ol\
l\
l\

>
0.0f
)
{
lOOl\
OlOOllll
=
Sqrt\

(
lOO\
l\
OlOlO\
ll\
l\

)
;
lO\
Ol\
Ol\
OllOlO
=
lOO\
lOl\
O\
ll\
OOl
/
lOOlOlOO\
lll\
l
;
}
else
if
(
lOOO\
ll\
l\
OllOO
<
0.0f
&&
lOO\
lOlOllOOO
>
0.0f
)
{
lOOlOlOllOlO
=
Sq\
rt
(
lOO\
lOlOl\
lO\
OO\

)
;
lOOlO\
l\
OOllll\

=
lOO\
lOlOl\
lOO\
l
/
lOOlOlO\
llO\
lO\

;
}
else
{
lOOl\
Ol\
O\
Olll\
l
=
Sq\
r\
t
(
lOOlOlOlO\
l\
ll\

)
;
lOOlO\
lOllOl\
O
=
Sqrt\

(
lOO\
lOl\
Oll\
OO\
O
)
;
if
(
lOO\
lO\
l\
OllOO\
l\

<
0.0f
)
lO\
OlOlOll\
OlO
=
-
lO\
OlOlOl\
l\
O\
lO
;
}
}
else
{
lOO\
l\
Ol\
OOll\
l\
l
=
Sq\
r\
t
(
lOO\
lOlOlOlll
)
;
lOOlO\
lOl\
lO\
l\
O\

=
Sqr\
t\

(
lOOlOlO\
l\
lOOO\

)
;
if\

(
lO\
O\
lOlOllOOl
<
0.0f
)
lOO\
lOlOl\
lO\
l\
O
=
-
lOOlOlOllO\
lO\

;
}
float
ll\
l\
OOllO\
Ol
=
lll\
lO\
OO\
O\
lO
*
0.5f
;
fl\
oat
lO\
OlO\
lOllO\
ll\

=
ll\
lO\
OllO\
O\
l
-
lOOlO\
lOOllll
;
fl\
o\
at
lO\
OlOlOl\
l\
lOO
=
lllO\
Ol\
l\
OOl
+
lO\
OlOl\
OOlll\
l\

;
if\

(
(
llllOOOO\
OO
>
0.0f
&&
lOlOO\
OlOl\
O\
l\

>
0.0f
)
||
(
llllOOOOOO
<
0.0f
&&
lO\
lOOOlOl\
Ol
<
0.0f
)
)
{
if\

(
lO\
OlO\
lOO\
lll\
l
!=
0.0f
)
{
if
(
llllOOOOlO\

>
0.0f
)
lOOl\
OlOllO\
ll
=
(
llll\
O\
OOOOO
+
lO\
l\
OOOlOlOl
)
/
lO\
OlOlOll\
lOO
;
else\

lOOlO\
lOlllO\
O
=
(
ll\
llOOOOOO
+
lOlOOOl\
OlOl
)
/
lO\
OlOlOllO\
ll
;
}
}
flo\
at
lOOl\
Ol\
O\
lllOl
;
float
lOOlOlOllllO\

;
if
(
lOl\
OOOl\
OlOl\

==
0.0f
&&
lOOlOlOll\
OlO
==
0.0f
)
{
lOOlOlOlll\
Ol
=
0.0f
;
lOOlO\
lO\
llllO
=
0.0f
;
}
els\
e\

if
(
(
lOOlOlO\
llOlO
>
0.0f
&&
lO\
lOOOl\
O\
lO\
l\

<
0.0f
)
||
(
lOOlO\
l\
Ol\
lO\
lO
<
0.0f
&&
lOlOOOlOl\
Ol\

>
0.0f
)
)
{
lOO\
lOl\
Oll\
l\
l\
O\

=
-
0.5f
*
lOlOOOlOlOl
+
lOO\
lOlOllOlO
;
lOOlOl\
Olll\
O\
l\

=
lOOOlll\
OllOO
/
lOOlO\
lOllllO\

;
}
els\
e
{
lO\
OlO\
lOl\
l\
lOl
=
-
0.5f
*
lOlOOOlOlOl
-
lOOl\
OlOll\
O\
lO
;
lOO\
lO\
lOl\
ll\
lO
=
lOOOl\
l\
l\
Ol\
lO\
O\

/
lOOlO\
l\
OlllOl\

;
}
fl\
oat
lOOlOl\
O\
lllll
[
2
]
;
fl\
o\
a\
t
lOOlOllO\
OOOO
[
2
]
;
in\
t
lOOOO\
lO\
OO\
l\
OO
=
lO\
O\
lOlOOlOlO
(
lOOlO\
lOlllO\
O
,
lO\
OlOlOllllO
,
lOOlO\
lOlll\
ll
)
;
int
lO\
OO\
O\
lOOOlO\
l
=
lOO\
l\
Ol\
OO\
l\
O\
lO\

(
lO\
OlOlOl\
lO\
ll\

,
lO\
OlO\
lOlll\
Ol
,
lO\
OlOllOOOOO
)
;
lO\
OOlllOll\
lO
[
0
]
=
lO\
Ol\
OlOl\
llll\

[
0
]
;
lOOO\
lllOlllO
[
1
]
=
lOOlOlOlllll\

[
1
]
;
lO\
OO\
lllO\
lllO
[
lO\
OOOlOO\
OlO\
O
+
0
]
=
lOOl\
Oll\
OOOOO
[
0
]
;
lOOOll\
lO\
lll\
O
[
lOOOOlOO\
Ol\
OO\

+
1
]
=
lOOlO\
llOOOOO
[
1
]
;
re\
turn
lOOOOlOOOlO\
O
+
lOOO\
OlOOO\
l\
O\
l\

;
}
bool
TAC\
_C\
ALL
lO\
OOllOllOOl\

(
const
Vec\
3\

&
lOOlOllO\
OOO\
l
,
const
Vec3
&
lOOlOll\
OOOlO
,
const
Vec3
&
lOO\
lO\
llOOOll
,
con\
st
Vec3
&
lOO\
lOllOOl\
OO
,
fl\
oat
lO\
Ol\
OllOOlOl\

,
fl\
o\
at
lOO\
l\
OllOOl\
l\
O
,
fl\
oat
&
ll\
llO\
lOO\
ll
,
Vec3
&
lO\
llll\
OOl\
l
,
Ve\
c3\

&
lOll\
l\
lO\
lOO
)
{
const
fl\
oat
lOllO\
lOlll\

=
0.00001f
;
{
Vec3\

llOlOO\
l\
lOOl
=
lOO\
lOllOOOlO
-
lOOlOllOOOOl
;
Ve\
c\
3
lOOOlOl\
OO\
lll
=
Geometry
::
Fin\
dClosestP\
o\
int\
On\
L\
i\
ne\

(
lOOlOl\
lO\
O\
Oll\

,
lOOl\
Ol\
lOOOOl\

,
lOOl\
O\
l\
lOOOl\
O
)
;
Ve\
c\
3
lO\
OlO\
llO\
Oll\
l
=
llO\
lOO\
ll\
O\
O\
l\

.
Cros\
s\

(
lOOlO\
llOO\
Oll\

-
lOOOl\
OlOO\
lll
)
.
Cross
(
lO\
OlOllOOlOO
)
;
flo\
at
lllOOl\
Oll\
l
=
lOOl\
OllOOlll\

.
GetMagnitudeSqr\
d
(
)
;
if
(
lllOOl\
Oll\
l
<
lOllOlO\
lll
*
lOllOlOl\
ll
*
lO\
l\
lO\
lOlll
)
ret\
u\
rn
fals\
e
;
lO\
Ol\
O\
l\
lOOlll
/=
Sq\
rt\

(
lll\
OO\
lOlll
)
;
Vec3
lOOlOllO\
lO\
O\
O
=
lOO\
l\
Ol\
lOOOl\
l\

+
lOO\
lOllOOlll
*
lOOlO\
llOOl\
Ol\

;
fl\
oat\

lOOlO\
llO\
l\
OOl
=
Ge\
ome\
tr\
y\

::
Fin\
dShortest\
D\
istanc\
eToLi\
ne\
Sqr\
d
(
lOOl\
Oll\
OlOOO
,
lOOlOl\
lO\
O\
O\
Ol\

,
lO\
OlOllOOOlO
)
;
if
(
lOOl\
OllO\
lOOl
>
lOOlO\
l\
l\
O\
OllO
*
lOOlOllOOl\
l\
O\

)
return\

false
;
}
Mat33
lO\
OOOOOOll
;
lOOOO\
OO\
Oll
.
SetToLo\
okDownV\
ector
(
lOO\
lOllO\
OlOO
)
;
Ma\
t33
lOOOl\
llOlOOO\

=
lOOOO\
OOOll
;
lOOOl\
llOl\
OOO
.
Tra\
nspo\
s\
e\
A\
sInv\
ert
(
)
;
Vec\
3
lllllllll\

=
(
lOOlOl\
lOOOO\
l
-
lOOlOllOOOl\
l
)
*
lOO\
Ol\
ll\
OlOOO
;
Vec\
3
lll\
lOOO\
OOl\
O
=
(
(
lOO\
l\
Ol\
lOOO\
lO\

-
lOOlOl\
lO\
OOOl\

)
*
lOO\
OlllOlOO\
O
)
;
fl\
o\
a\
t\

lO\
OOl\
ll\
OlO\
Ol
=
llllOOOO\
OlO
.
GetMagnit\
u\
deSqr\
d
(
)
;
if
(
lOOOlllOlOOl
<
lOllOlOlll
)
re\
tu\
rn
fal\
se
;
cons\
t
flo\
a\
t\

lOOlOl\
l\
Ol\
OlO\

=
llllOOO\
OOlO
.
Dot\

(
llllllll\
l
)
/
lOO\
Oll\
l\
O\
l\
O\
Ol
;
ll\
lll\
llll\

-=
llllOO\
O\
OOlO
*
lOOlOllOl\
OlO
;
fl\
oat
lOOOl\
l\
lOlOlO\

=
2.0f
*
lll\
lll\
ll\
l
.
Dot
(
llllOOOOO\
lO
)
;
flo\
at
lO\
OOlllOlOll
=
llll\
lllll
.
Ge\
t\
Mag\
nit\
udeSqrd\

(
)
-
Pow\
2
(
lOOlOllOOl\
O\
l\

)
-
Pow2
(
lOOlO\
l\
lOOllO
)
;
const\

float
llllOOOOOl
=
Pow2
(
lO\
OOlll\
OlO\
O\
l\

)
;
const
float
llllO\
O\
OO\
lO
=
2.0f
*
lO\
OOlllO\
l\
O\
Ol\

*
lOO\
Oll\
l\
OlOlO
;
con\
s\
t
float\

lll\
l\
O\
OO\
OO\
O\

=
2.0f
*
lOOO\
lllOlOOl
*
lO\
O\
Oll\
l\
O\
lOll
+
Pow2
(
lOO\
O\
l\
llOlOl\
O
)
+
4.0f
*
Pow2
(
lO\
Ol\
O\
llOOl\
Ol
*
ll\
llOOOO\
O\
lO
.
z
)
;
const
float\

ll\
lOlll\
l\
ll\

=
2.0f
*
lOO\
Oll\
lO\
l\
OlO
*
lOOOll\
l\
O\
l\
Oll
+
8.0f
*
Pow\
2
(
lO\
OlOllO\
OlOl
)
*
lll\
ll\
llll
.
z
*
ll\
llO\
OOOO\
lO
.
z
;
co\
nst
float
lOO\
OlllOll\
OO\

=
Pow2
(
lOOOlllOlO\
l\
l
)
+
4.0f
*
Pow\
2
(
lO\
OlO\
ll\
O\
OlOl
)
*
(
Pow2
(
llllll\
lll
.
z
)
-
Pow2\

(
lOOl\
OllO\
OllO\

)
)
;
const\

fl\
oat
lO\
OO\
l\
l\
l\
O\
l\
l\
Ol
=
1.0f
/
llllO\
OOOOl
;
float\

lOOOlll\
OlllO\

[
4
]
;
int
lOOOlllOl\
ll\
l\

=
lOO\
OllllOOO\
O
(
llllOOO\
O\
lO
*
lOOOll\
l\
OllO\
l
,
llllOO\
OOOO
*
lO\
OOlll\
Ol\
lOl\

,
ll\
lO\
ll\
l\
l\
ll
*
lOO\
Ol\
ll\
Ol\
lOl
,
lOOOlllOllOO\

*
lO\
OO\
ll\
lOllO\
l
,
lOO\
O\
l\
llOll\
lO
)
;
ll\
llOlO\
Oll\

=
1.0f
;
bool
lOOOOl\
OllOl\
l
=
false
;
for
(
in\
t\

lO\
OOllOOO\
l
=
0
;
lOOO\
ll\
O\
OO\
l
<
lOOOlllOll\
ll
;
lOOOllOOOl
++
)
{
float
lOO\
lOllOlOl\
l
=
lOOO\
ll\
lOlllO
[
lOOO\
llO\
O\
Ol
]
-
lOOlOl\
lOlOlO
;
if
(
lOO\
lOl\
lOl\
Oll\

<
0.0f
||
lOOl\
OllOlO\
ll
>
lll\
lOlOO\
ll
)
contin\
ue
;
Ve\
c3
lOOO\
ll\
llOOOl
=
lll\
l\
ll\
lll
+
llllOO\
OO\
Ol\
O
*
lOOOl\
llOlllO
[
lOOOl\
lOO\
Ol
]
;
if
(
lOOOl\
lll\
OOO\
l
.
z
<
0.0f
)
conti\
nu\
e
;
Vec3
llOO\
ll\
lll\
O
=
(
lOO\
O\
llllO\
OOl
)
*
lOOOOO\
OOll
+
lOOl\
Ol\
lO\
OO\
ll
;
Vec3
llOllOOll\
O
=
lO\
OOl\
lll\
O\
O\
Ol
;
llO\
llO\
O\
llO
.
z
=
0.0f
;
float\

lO\
llll\
O\
lOl
=
llOll\
OOll\
O\

.
GetMag\
n\
itud\
e\

(
)
;
if
(
lOllllOl\
Ol
<=
lOOlOl\
lOOlOl
)
co\
nti\
n\
ue
;
llOllOO\
l\
lO
*=
lOOlOllOOlOl
/
lOllllOlOl\

;
Ve\
c3\

lO\
O\
OlOOO\
O\
O\

=
lOOOllll\
O\
OO\
l
-
llOllOOllO\

;
lOl\
l\
l\
l\
O\
lOl
=
lO\
OO\
lOOOO\
O\

.
GetMagni\
tu\
de
(
)
;
TA\
_A\
SSE\
RT
(
lOllllOlO\
l
>
lO\
ll\
OlOlll
)
;
lOOOlOO\
OOO
*=
lOO\
OOOOOll
;
lO\
OOlOOOO\
O
/=
lOlll\
lOlOl
;
ll\
llO\
lO\
O\
l\
l\

=
lOOlOl\
l\
Ol\
Oll
;
lO\
ll\
ll\
OOl\
l\

=
llOO\
llll\
lO\

;
lOl\
l\
llO\
lOO\

=
lOOOlOO\
O\
O\
O\

;
lOO\
OOlOllO\
l\
l
=
tr\
u\
e
;
}
re\
turn\

lOOOOlOllOl\
l
;
}
}
