//---------------------------------------------------------------------------------
// File Name: zcta012.inl
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef TA_DEBUG_H
#include "Debug.h"
#endif //
namespace\

TA
{
namespace
lOl\
OO\
OOO\
llO\

{
tem\
pla\
te
<
class\

Type
>
__fo\
rceinline
Vec\
3
lOl\
OOO\
OllOO
<
Type
>
::
Ge\
tNormal\

(
)
const
{
lOlO\
O\
OO\
Olll
lOlOOl\
OOlOl
;
lO\
lO\
OlO\
OlOl\

.
x
=
lOl\
OOO\
Ol\
lOl\

(
)
;
lOlOOl\
O\
OlO\
l
.
y
=
lO\
l\
OOOO\
ll\
lO
(
)
;
lO\
lO\
O\
lOOl\
Ol\

.
z
=
lOl\
OOO\
O\
ll\
ll
(
)
;
floa\
t\

lOlOO\
lOOl\
lO
=
1.0f
/
Sq\
r\
t
(
lOlOOlO\
Ol\
O\
l\

.
x
*
lO\
lOOlOOl\
Ol
.
x
+
lOl\
OOlOOlO\
l\

.
y
*
lOlOOlO\
OlOl\

.
y
+
lOlOOlOOlO\
l
.
z
*
lOl\
OO\
l\
OO\
lOl
.
z
)
;
Vec3
lO\
OO\
Oll\
Olll
;
lOOOOl\
l\
Olll
.
x
=
lOlOOlOO\
lOl\

.
x
*
lO\
lO\
O\
lO\
OllO
;
lOO\
OOllOll\
l
.
y
=
lOlOOlOOl\
O\
l
.
y
*
lOlO\
OlOOllO\

;
lOO\
OOllOll\
l\

.
z
=
lOl\
OOlOO\
l\
O\
l
.
z
*
lO\
lOO\
l\
OOllO
;
ret\
u\
rn\

lOOOOllOlll
;
}
template
<
clas\
s
lO\
lOOOlOOOO
,
cl\
as\
s
lOlOOOlOO\
O\
l
>
__\
forcei\
n\
l\
ine
lOl\
O\
OO\
lll\
O\
l
<
lOl\
O\
OOOllOO
<
lOl\
OOOlOOO\
O
>
,
lOlO\
OO\
O\
l\
lOO
<
lOl\
O\
OOlOOOl
>
,
lOlOlO\
O\
OO\
l
>
operato\
r
+
(
const
lOlOOO\
OllOO\

<
lOlOOO\
lO\
OOO
>
&
lllOOlllOO\

,
cons\
t\

lOl\
O\
OO\
OllO\
O
<
lO\
lOOO\
lOOOl
>
&
lllOlOO\
OO\
O
)
{
retur\
n
lO\
l\
OOOll\
l\
Ol
<
lOl\
OOO\
OllOO
<
lO\
l\
O\
O\
O\
l\
O\
O\
OO\

>
,
lOl\
OO\
OOllOO
<
lOl\
OOOlO\
OOl\

>
,
lOlOl\
O\
O\
OO\
l
>
(
lllOOlllO\
O\

,
lllOlOOOOO
)
;
}
template
<
cla\
ss
lOlOOOlOOOO\

,
cla\
ss
lOlO\
OOlOOOl\

>
__fo\
rce\
i\
nl\
ine
lOlOOOll\
l\
Ol
<
lOl\
OOOOllOO
<
lO\
lOO\
OlO\
OOO
>
,
lOlOOOO\
l\
lOO
<
lOl\
OOOlOOOl
>
,
lOl\
OOOll\
O\
OO
>
oper\
a\
t\
or
-
(
const
lOlO\
OOOl\
l\
O\
O
<
lOlOOOlOO\
OO
>
&
ll\
lO\
OlllO\
O
,
const
lOl\
OOO\
OllOO
<
lO\
lO\
O\
Ol\
OOOl
>
&
lll\
OlOOO\
O\
O
)
{
return
lOlOOOl\
ll\
Ol
<
lO\
lOOOO\
ll\
O\
O
<
lOlOO\
Ol\
OOOO
>
,
lOlOOOO\
ll\
OO
<
lOl\
OOOlOOO\
l\

>
,
lOl\
OOOllOOO\

>
(
lllO\
Olll\
OO
,
ll\
lOl\
OO\
OOO\

)
;
}
templ\
a\
t\
e
<
class
Type
>
__forc\
e\
inline
lO\
lOOlOO\
O\
O\
l
<
lOl\
O\
OOOl\
l\
OO
<
Type
>
,
Mu\
l
>
operato\
r
*
(
const
lOl\
OO\
OOl\
l\
OO
<
Ty\
pe
>
&
lll\
O\
Ol\
ll\
OO
,
floa\
t\

ll\
l\
OlOOOOO
)
{
re\
turn
lOlOOl\
OOO\
Ol\

<
lOlOOOOllOO
<
Ty\
pe\

>
,
Mul
>
(
lllOOlllOO\

,
lllOl\
OOOO\
O\

)
;
}
template
<
cla\
ss\

Type
>
__fo\
rceinline
lOlOOlOOOl\
O
<
lOlOOOOl\
l\
O\
O
<
Typ\
e
>
,
Mul
>
operato\
r
*
(
floa\
t
lllOO\
lll\
OO
,
const
lO\
lOOOOllO\
O
<
Typ\
e
>
&
lllO\
l\
OO\
OO\
O
)
{
ret\
u\
rn
lOlO\
O\
lOOOlO
<
lOlO\
OO\
O\
llO\
O\

<
Type\

>
,
Mu\
l\

>
(
lllOOlllOO\

,
lllOl\
OOOOO
)
;
}
template
<
cl\
ass\

Ty\
pe\

>
__\
forc\
ei\
n\
line
lO\
l\
OOlOO\
O\
Ol\

<
lOl\
OO\
OOll\
OO\

<
Type
>
,
lOlO\
OOllOOl
>
operator
/
(
co\
n\
st\

lOl\
OOOOl\
l\
OO
<
Type
>
&
lll\
OOlllOO
,
flo\
at
ll\
lOlO\
OOO\
O\

)
{
return
lOlOO\
l\
OOO\
Ol
<
lO\
lOOOOllOO\

<
Ty\
pe\

>
,
lOlOOOllOOl\

>
(
ll\
lOOlllOO
,
lllOlOOO\
O\
O
)
;
}
templ\
ate\

<
clas\
s
Type
>
__force\
inline
lO\
lOOlO\
O\
O\
OO
<
lOlOOOOllO\
O
<
Typ\
e\

>
,
lOlO\
OOllOlO
>
op\
era\
tor
+
(
const
lOlOOO\
OllOO
<
Type
>
&
lllOOl\
llOO\

)
{
re\
t\
u\
rn
lOl\
OOlO\
OOOO
<
lO\
lOO\
lOOlll\

<
Ty\
pe
>
,
lOlOOO\
ll\
OlO
>
(
ll\
lOOlllOO\

)
;
}
te\
mplate
<
cla\
ss
Typ\
e
>
__\
force\
inli\
ne
lO\
l\
O\
O\
l\
OO\
OO\
O
<
lO\
l\
OOOO\
llOO
<
Ty\
pe\

>
,
lO\
l\
OOO\
l\
l\
Oll
>
operator\

-
(
co\
nst\

lOlO\
O\
OOl\
lOO
<
Type\

>
&
lll\
OOlllOO\

)
{
return\

lO\
l\
OO\
lOO\
OOO
<
lO\
lO\
OOOllOO
<
Type\

>
,
lOlOOOllO\
ll
>
(
lllO\
O\
l\
llO\
O
)
;
}
tem\
plate
<
cla\
ss
lOlO\
OOl\
OOOO\

,
cla\
ss
lOlO\
OOl\
OOOl\

>
__fo\
rcei\
nline\

bo\
ol
ope\
rat\
o\
r
==
(
co\
n\
s\
t
lOlOOOOllO\
O
<
lOlOOOl\
OO\
OO
>
&
lllOOlllO\
O
,
const
lOlOOO\
O\
l\
lOO
<
lOl\
OOOlO\
OO\
l\

>
&
lllO\
lO\
O\
OO\
O\

)
{
return\

lll\
OO\
lllO\
O
.
lOlOOOOllOl
(
)
==
ll\
lOlO\
OOOO
.
lOlO\
O\
O\
OllO\
l\

(
)
&&
ll\
lOOlll\
OO
.
lO\
lOOOO\
l\
llO
(
)
==
lllOlOOOOO
.
lOlOOOOlllO
(
)
&&
ll\
lOOlllOO\

.
lO\
l\
OOO\
Oll\
ll
(
)
==
lllOlO\
OOOO
.
lOlO\
O\
O\
O\
llll
(
)
;
}
te\
mplate
<
class\

lOlOOO\
lOOOO\

,
clas\
s\

lOlO\
OOlOO\
O\
l\

>
__fo\
rceinli\
ne
bool
op\
erator
!=
(
co\
ns\
t
lOlOOOO\
l\
lOO
<
lO\
lOO\
OlOOO\
O
>
&
lll\
OO\
lllO\
O
,
co\
nst
lOlO\
OO\
Ol\
lOO
<
lO\
lOO\
Ol\
OOOl
>
&
lllO\
lOO\
OOO
)
{
return
lll\
OOll\
lO\
O
.
lOlO\
OO\
OllO\
l
(
)
!=
lllOlO\
O\
OOO\

.
lOlOOO\
OllOl
(
)
||
lll\
O\
Olll\
OO
.
lO\
lOOOOl\
ll\
O
(
)
!=
lllOlOOOO\
O
.
lOl\
O\
O\
O\
Ol\
llO
(
)
||
ll\
lOOlllOO
.
lOl\
O\
OOOllll
(
)
!=
lllOlO\
OOOO\

.
lOlO\
OOOllll
(
)
;
}
}
inline
int
Vec3
::
Ge\
t\
GreatestA\
x\
is\

(
)
const
{
fl\
oa\
t
lOlOO\
OOOO\
lO
=
Fa\
bs
(
x
)
;
floa\
t
lO\
l\
O\
OOOOOll
=
Fabs\

(
y
)
;
floa\
t
lOlOOOOOl\
OO
=
Fab\
s
(
z
)
;
if
(
lOlO\
OO\
O\
OOlO
>
lOl\
OOOOOO\
ll
)
{
if
(
lOl\
OO\
O\
OO\
OlO\

>
lOlO\
O\
OO\
OlOO
)
ret\
urn\

AXI\
S_\
X
;
else
re\
t\
ur\
n\

AXIS_Z
;
}
else
{
if\

(
lOlOOOOO\
Ol\
l
>
lOl\
OO\
OOO\
lOO
)
return
AX\
IS_Y
;
else
re\
turn\

AX\
IS_Z
;
}
}
inline
void
Ve\
c3
::
GetAx\
isOrder
(
int
llll\
O\
O\
lO\
ll
[
3
]
)
con\
st
{
float
lOlOOO\
OOOlO
=
Fa\
bs\

(
x
)
;
floa\
t\

lOl\
OOO\
OOOll
=
Fabs\

(
y
)
;
fl\
oa\
t\

lOl\
OOOOOlOO
=
Fabs
(
z
)
;
if
(
lOlOO\
OOOOlO
>
lOlOOOO\
OOll
)
{
if
(
lOl\
OOOOOOlO
>
lOlOOOOOl\
OO\

)
{
llllO\
OlOl\
l\

[
0
]
=
AXI\
S_X
;
if
(
lOl\
OOO\
OOOll
>
lOlO\
OO\
OOlOO
)
{
llllO\
OlO\
ll
[
1
]
=
AXIS_Y
;
lll\
lO\
OlOll\

[
2
]
=
AX\
IS_\
Z
;
}
els\
e\

{
llllOOl\
O\
l\
l
[
1
]
=
AXI\
S_Z
;
ll\
l\
lOOlOll
[
2
]
=
AXIS_\
Y
;
}
}
els\
e
{
llll\
O\
OlOll
[
0
]
=
AX\
I\
S_Z
;
ll\
llOO\
lO\
ll\

[
1
]
=
AXI\
S_X
;
ll\
l\
lOOlOll
[
2
]
=
AX\
I\
S_Y
;
}
}
else\

{
if\

(
lO\
l\
OOOOOO\
ll
>
lO\
lOOOOOl\
O\
O
)
{
llll\
OOlOll\

[
0
]
=
AX\
IS_Y\

;
if
(
lOlOOO\
O\
OOlO\

>
lO\
lOO\
O\
O\
OlO\
O
)
{
llll\
O\
Ol\
O\
ll
[
1
]
=
AXIS_X\

;
lll\
lOOlOll\

[
2
]
=
AXI\
S_Z
;
}
el\
se
{
llllOOlO\
ll
[
1
]
=
AX\
IS\
_Z
;
llll\
O\
O\
lOll
[
2
]
=
AX\
I\
S_\
X\

;
}
}
else
{
lll\
lOOl\
Oll
[
0
]
=
AXI\
S\
_Z\

;
ll\
l\
lOOlO\
l\
l\

[
1
]
=
AXI\
S_Y\

;
llllO\
Ol\
Oll\

[
2
]
=
AX\
IS\
_\
X
;
}
}
TA\
_\
AS\
SE\
RT\

(
Fabs
(
Get\
Ax\
i\
s
(
llllOOlOl\
l
[
0
]
)
)
>=
Fabs
(
Ge\
t\
Axis\

(
llllOOlOl\
l
[
1
]
)
)
)
;
TA_A\
SSERT
(
Fabs
(
GetAx\
is
(
llllOOlOl\
l
[
1
]
)
)
>=
Fabs
(
Ge\
t\
Axis
(
llllOO\
l\
O\
ll\

[
2
]
)
)
)
;
}
inline\

con\
st
Vec3\

&
Vec3
::
Ge\
t\
Un\
itVe\
ctor
(
in\
t
lOO\
Ol\
O\
Olll
)
{
swi\
tch
(
lOOOlOOlll
)
{
case
AXIS_X\

:
return
k_v3\
Uni\
tX
;
break\

;
ca\
s\
e
AXIS_Y
:
re\
turn\

k_\
v3UnitY
;
brea\
k
;
case
AX\
IS_Z
:
ret\
u\
r\
n
k_\
v3UnitZ\

;
break
;
de\
fa\
ul\
t
:
lllOOlOO\
OO\

;
re\
turn
k_v\
3\
Un\
itX
;
}
}
}