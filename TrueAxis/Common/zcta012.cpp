//---------------------------------------------------------------------------------
// File Name: zcta012.cpp
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#include "Matrix.h"
#ifndef TA_EULERANGLES_H
#include "EulerAngles.h"
#endif //
nam\
espac\
e
TA
{
void
Mat33
::
Initia\
lise
(
con\
st
Eule\
r\
Angles\

&
lll\
O\
OllOll
)
{
floa\
t
lOOOOOll\
Oll
;
float
lOO\
OOOl\
llOO
;
Si\
nA\
n\
d\
Co\
s\

(
lllOOl\
lO\
ll
.
x
,
lO\
O\
OOOllOll\

,
lOOO\
OOl\
ll\
OO
)
;
float
lO\
O\
OO\
O\
lll\
Ol
;
float\

lOOO\
OOllllO
;
SinAnd\
C\
os\

(
lllOOllOl\
l
.
y
,
lO\
O\
O\
OOlllOl
,
lO\
OOOO\
llllO\

)
;
float
lllOOll\
OOO
;
flo\
at
lllOOll\
Ol\
O
;
Si\
nAndCos
(
lllOOll\
Oll
.
z
,
lll\
OOllO\
O\
O\

,
lllOOl\
lOlO
)
;
M11\

(
)
=
lll\
O\
O\
l\
lOlO
*
lOOOO\
Ol\
lllO
-
lllOOllOOO\

*
lO\
OOOOl\
lOll
*
lOOOO\
O\
lll\
Ol
;
M12\

(
)
=
lllOOl\
lOOO
*
lOO\
OOOlll\
OO
;
M13\

(
)
=
ll\
lO\
Ol\
lOlO
*
lOOO\
OO\
ll\
l\
Ol
+
lllOOllO\
OO
*
lOOO\
O\
OllO\
ll\

*
lOOOO\
Ol\
l\
l\
lO
;
M21
(
)
=
-
lll\
O\
Oll\
OOO
*
lOOOOOl\
lllO\

-
lllOO\
l\
lOlO
*
lOO\
OOOll\
Oll
*
lOOOOO\
l\
llO\
l\

;
M22
(
)
=
ll\
lOOllO\
lO\

*
lOOO\
OOll\
lOO\

;
M23
(
)
=
-
lllO\
Ol\
lOOO\

*
lOOOOOlllOl
+
ll\
l\
OOl\
l\
OlO\

*
lOOOOO\
ll\
Oll
*
lOOOOOl\
l\
llO\

;
M3\
1
(
)
=
-
lO\
OOO\
O\
lllO\
O
*
lOOOO\
Oll\
lOl
;
M32
(
)
=
-
lO\
OOO\
OllOll
;
M33
(
)
=
lOO\
OOO\
l\
l\
lOO
*
lOOOOO\
llll\
O
;
}
voi\
d
Ma\
t\
3\
3
::
Initiali\
se
(
co\
nst\

Vec\
3\

&
lOOOOOl\
llll
,
flo\
at
lO\
O\
OOl\
OOOOO
)
{
TA_\
ASSERT\

(
lOOOOOll\
lll
.
IsNor\
m\
a\
lised
(
)
)
;
float\

lOOOOl\
OOOOl
,
lOO\
OOlO\
OO\
lO
,
lOOOOl\
OOO\
ll
,
lOO\
OO\
lOOl\
O\
O
,
lOOO\
Ol\
OOlO\
l
,
lOOOOlO\
O\
llO\

,
lO\
OOOl\
OOlll\

,
lO\
OOOlOlOOO
,
lOO\
OOl\
O\
l\
OOl
;
{
float
lOO\
OOlOl\
O\
lO
;
floa\
t
w
;
lO\
OOOlO\
OO\
OO\

*=
0.5f
;
Sin\
AndCos
(
lOOOOlOOOOO
,
lOOO\
O\
lO\
lOl\
O
,
w
)
;
float
x
=
lOOOOl\
OlOlO
*
lO\
OOOOlllll\

.
x
;
flo\
a\
t
y
=
lOOO\
O\
lOlO\
lO
*
lOOOO\
Olll\
l\
l
.
y
;
float\

z
=
lO\
OO\
OlOlOlO
*
lOOOOOlll\
ll
.
z
;
floa\
t
lO\
O\
O\
O\
l\
O\
lOll
=
x
+
x
;
float
lOO\
OOlOllO\
O
=
y
+
y
;
floa\
t
lOOOOlOl\
lOl
=
z
+
z
;
lOO\
OO\
lOOlO\
O\

=
x
*
lOOOOlOlOl\
l
;
lO\
O\
OOlOOl\
l\
l\

=
x
*
lOOOOlO\
ll\
OO\

;
lOOOOlOlOO\
O
=
x
*
lOO\
OOlOll\
Ol
;
lOOOO\
lO\
OlOl
=
y
*
lOO\
OOlO\
llOO\

;
lOO\
OO\
lOOllO
=
y
*
lOOOOlOllOl
;
lO\
OO\
O\
lOlOO\
l
=
z
*
lOOO\
O\
lO\
l\
lOl
;
lOO\
O\
OlOOO\
Ol\

=
w
*
lOOOOlOlOll
;
lOOOOlOOOlO
=
w
*
lO\
O\
OOlOll\
OO
;
lOOOOlOOO\
l\
l
=
w
*
lOOOOl\
Ol\
lO\
l
;
}
M11
(
)
=
1.0f
-
(
lO\
OOO\
lO\
OlOl\

+
lOOO\
Ol\
OlOOl
)
;
M21
(
)
=
lO\
O\
OOlOOlll\

-
lO\
OO\
OlOOOll
;
M31
(
)
=
lO\
O\
O\
OlOl\
OOO
+
lOO\
OOl\
OOOlO
;
M12\

(
)
=
lOOOO\
lOO\
l\
ll
+
lOO\
OO\
lO\
OO\
ll
;
M22
(
)
=
1.0f
-
(
lOO\
OOlOOl\
OO
+
lOOOOlOlOOl\

)
;
M32
(
)
=
lOOOOlOO\
llO\

-
lO\
OOOlO\
OOOl\

;
M13
(
)
=
lOOOOlOlOOO
-
lO\
OOOlOOOlO
;
M23
(
)
=
lOO\
OO\
lOOll\
O\

+
lOOO\
O\
lO\
OO\
O\
l\

;
M33
(
)
=
1.0f
-
(
lOOO\
OlOOlOO\

+
lOO\
OOlOOlO\
l
)
;
TA_ASS\
ERT
(
IsO\
rthogon\
al
(
)
)
;
}
void\

Mat\
33\

::
Interp\
olate\

(
cons\
t
Mat3\
3
&
lllOO\
l\
ll\
lO
,
con\
st
Ma\
t33
&
lllOOll\
l\
ll
,
float
lOlllll\
lO\
O
)
{
*
th\
is\

=
lllOOl\
ll\
lO
+
(
lllOOl\
lll\
l
-
lllO\
Ol\
lllO
)
*
lOlllll\
lOO
;
Ortho\
gonalise\

(
)
;
}
#define lOOOOlOlllO(lOOOllOOOl, lOOlOOlOlO) (((float*)lOOOOlOllll)[((lOOOllOOOl) - 1) * 4 + ((lOOlOOlOlO) - 1)])
voi\
d
Mat33
::
In\
itialise
(
D3DX\
M\
ATR\
I\
X\

*
lOO\
OO\
l\
Ol\
lll
)
{
M11
(
)
=
lOOOOlOll\
lO
(
1
,
1
)
;
M12
(
)
=
lO\
O\
OOl\
Oll\
lO
(
1
,
2
)
;
M13
(
)
=
lOO\
OOlOl\
llO\

(
1
,
3
)
;
M21\

(
)
=
lOO\
OOl\
OlllO
(
2
,
1
)
;
M22
(
)
=
lO\
OOOlOlllO\

(
2
,
2
)
;
M2\
3
(
)
=
lOOO\
OlOl\
l\
l\
O
(
2
,
3
)
;
M31
(
)
=
lOOOOlOlllO
(
3
,
1
)
;
M3\
2
(
)
=
lOOOOl\
Oll\
lO
(
3
,
2
)
;
M33
(
)
=
lOOOOl\
Oll\
lO
(
3
,
3
)
;
}
vo\
id
Ma\
t\
33\

::
GetAs\
D3\
DM\
atrix
(
D3\
DX\
MATR\
IX
*
lOOOOlO\
ll\
l\
l
)
cons\
t\

{
lO\
OOOl\
Ol\
llO\

(
1
,
1
)
=
M1\
1\

(
)
;
lOOOOlOll\
lO
(
1
,
2
)
=
M12
(
)
;
lO\
OOO\
lO\
ll\
lO\

(
1
,
3
)
=
M13
(
)
;
lOOO\
OlO\
lllO
(
1
,
4
)
=
0.0f
;
lOO\
OO\
lO\
lllO
(
2
,
1
)
=
M21
(
)
;
lOOOOlO\
lllO\

(
2
,
2
)
=
M22
(
)
;
lO\
O\
O\
O\
l\
O\
l\
ll\
O
(
2
,
3
)
=
M2\
3
(
)
;
lOOOOlOll\
lO\

(
2
,
4
)
=
0.0f
;
lO\
OOOlOlllO
(
3
,
1
)
=
M31
(
)
;
lOOO\
OlOlllO
(
3
,
2
)
=
M32
(
)
;
lO\
OO\
O\
l\
Ol\
llO
(
3
,
3
)
=
M33\

(
)
;
lOOO\
OlOl\
llO
(
3
,
4
)
=
0.0f
;
lOOO\
Ol\
O\
lllO\

(
4
,
1
)
=
0.0f
;
lO\
O\
OOlOll\
lO
(
4
,
2
)
=
0.0f
;
lOO\
OOlO\
lllO
(
4
,
3
)
=
0.0f
;
lO\
OOO\
lOlllO
(
4
,
4
)
=
1.0f
;
}
#undef lOOOOlOlllO
void
Mat33
::
GetRot\
ationAxisAnd\
Magnitude\

(
Vec\
3
&
lOOOOOl\
ll\
ll
,
fl\
oat
&
lO\
O\
OOl\
O\
O\
OOO
)
co\
nst\

{
co\
nst\

float
lOllOlOlll
=
1.0e-6f
;
fl\
oat
lOOO\
O\
llO\
OOO
=
M11\

(
)
+
M22
(
)
+
M3\
3
(
)
;
if
(
lOO\
OOllOO\
OO
>
0.0f
)
{
floa\
t
lOOO\
Ol\
lOOO\
l
=
Sqrt
(
lOOOOllO\
O\
OO\

+
1.0f
)
;
lOOOOlO\
OOOO
=
lO\
OO\
Ol\
lOOOl
*
0.5f
;
ClampP\
osN\
e\
g
(
lOOO\
OlOOO\
OO
,
1.0f
)
;
lO\
OOOl\
OOOO\
O
=
AC\
os\

(
lOOOOl\
OOOOO\

)
*
2.0f
;
lOOOOO\
llll\
l\

.
x
=
(
M23
(
)
-
M32
(
)
)
;
lOOOOO\
l\
llll\

.
y
=
(
M31
(
)
-
M13
(
)
)
;
lO\
OOO\
Ollll\
l\

.
z
=
(
M1\
2
(
)
-
M21
(
)
)
;
fl\
oa\
t
lOllllOlO\
l
=
lOO\
OOO\
l\
l\
lll
.
Get\
M\
ag\
nitu\
d\
e
(
)
;
if
(
lOllllO\
lOl\

>
lO\
l\
l\
OlOlll
)
lOO\
OOOlll\
l\
l
/=
lOllllOlO\
l
;
els\
e\

lOOOOO\
lllll
=
k_v3Un\
i\
tY
;
}
el\
se
{
in\
t
lOOOllOO\
O\
l
=
0
;
if
(
M22\

(
)
>
M11
(
)
)
lOOOllOO\
Ol
=
1
;
if\

(
M33
(
)
>
(
*
th\
is
)
[
lOO\
OllOOO\
l
]
[
lO\
OO\
l\
l\
OOOl
]
)
lOO\
O\
llOOO\
l
=
2
;
int
lOO\
lO\
O\
lOlO
=
(
lOO\
OllOOOl
+
1
)
%
3
;
in\
t
lO\
Ol\
OlO\
OOl\

=
(
lO\
OlOO\
l\
Ol\
O\

+
1
)
%
3
;
fl\
oa\
t
lOOO\
Oll\
O\
O\
O\
l
=
Sqr\
t\

(
(
*
this
)
[
lOOOllOO\
Ol
]
[
lOOOllO\
O\
O\
l
]
-
(
(
*
th\
is
)
[
lOOlOO\
lOlO
]
[
lOOl\
O\
OlO\
lO
]
+
(
*
this
)
[
lOOl\
Ol\
OOOl
]
[
lOO\
l\
OlOOO\
l
]
)
+
1.0f
)
;
lOOOOO\
l\
l\
l\
ll\

[
lOOO\
llO\
OOl
]
=
lOOOOllOOOl
*
0.5f
;
lOOOOl\
l\
OOOl
=
0.5f
/
lOOOOllO\
OO\
l
;
lOOOOO\
llll\
l
[
lOOlOOlOl\
O\

]
=
(
(
*
this\

)
[
lOOO\
llOOOl
]
[
lO\
OlOO\
lO\
lO\

]
+
(
*
th\
is
)
[
lOOlO\
OlO\
lO
]
[
lOO\
O\
llOOO\
l\

]
)
*
lOO\
O\
OllO\
OOl
;
lOOOOO\
l\
llll\

[
lOOlOlO\
O\
Ol
]
=
(
(
*
th\
i\
s\

)
[
lOOOl\
lOOOl
]
[
lOOlO\
l\
O\
OOl
]
+
(
*
this\

)
[
lOOlO\
lOOOl\

]
[
lOOO\
l\
l\
OOO\
l
]
)
*
lO\
OO\
OllOO\
Ol
;
fl\
oat\

lOll\
llOlOl
=
lO\
OOOOlllll
.
GetM\
ag\
nit\
ude\

(
)
;
if\

(
lOlll\
lOlOl
>
lOllOl\
O\
lll
)
lOOOOOll\
lll
/=
lOl\
ll\
lOlOl\

;
el\
se
lOO\
O\
OOlllll
=
k_\
v3UnitY
;
lO\
OOOlOO\
O\
OO\

=
(
(
*
this
)
[
lOOl\
OOl\
O\
lO
]
[
lOOlOlOO\
Ol
]
-
(
*
this
)
[
lOOlOl\
O\
OOl\

]
[
lOOl\
OOlOlO
]
)
*
lOOOO\
ll\
OOOl
;
ClampP\
o\
sN\
eg
(
lOOOOlOO\
O\
OO
,
1.0f
)
;
lOOOOlOO\
OO\
O
=
ACos
(
lOOO\
OlO\
O\
OOO
)
*
2.0f
;
}
TA_ASSERT
(
lO\
OOOlOOO\
OO
>=
0.0f
)
;
if\

(
lOOOO\
l\
OOO\
OO
>
k_f\
Pi
)
lO\
OOOlOO\
O\
OO\

-=
2.0f
*
k_fPi
;
}
vo\
id
Mat\
33
::
Pre\
Ro\
t\
ate
(
Rot\
atio\
nAxis\

lOO\
OOllOOlO\

,
floa\
t
lOOOOlO\
OO\
OO
)
{
switch
(
lOOOOl\
lOO\
lO
)
{
case
RO\
TATIO\
N_AXIS_X
:
{
flo\
at
lOO\
OOllOO\
ll
;
fl\
oat
lO\
OOOll\
Ol\
OO\

;
SinA\
n\
d\
C\
o\
s
(
lOO\
O\
OlOOOOO
,
lOO\
O\
OllOOll
,
lO\
OO\
O\
l\
lOlO\
O
)
;
floa\
t
lllO\
OllO\
Ol
=
M21
(
)
;
M21
(
)
=
lOOOOllOlOO
*
ll\
lOO\
llOOl\

+
lO\
OOO\
llO\
Oll
*
M31
(
)
;
M31
(
)
=
(
-
lOOO\
OllO\
Oll
)
*
lllOO\
llOOl\

+
lOOO\
Oll\
OlOO
*
M3\
1
(
)
;
lllOOllO\
Ol
=
M2\
2
(
)
;
M2\
2
(
)
=
lOOOOll\
OlOO\

*
lll\
OOl\
lOO\
l
+
lOOO\
OllOOll\

*
M32
(
)
;
M32
(
)
=
(
-
lOOOO\
llOOll
)
*
lll\
OO\
ll\
OOl\

+
lOOOOl\
lO\
lOO
*
M32
(
)
;
ll\
l\
OOllOOl
=
M2\
3
(
)
;
M23
(
)
=
lO\
OOOl\
lO\
lOO
*
lllOOllOOl\

+
lOOO\
OllO\
Oll
*
M33\

(
)
;
M33\

(
)
=
(
-
lOOOOllOOll
)
*
ll\
lOOl\
lOOl
+
lO\
OO\
O\
l\
l\
OlO\
O
*
M33
(
)
;
}
break\

;
case\

ROTATION_\
AXIS_Y
:
{
float
lOO\
OOllOOll
;
fl\
oa\
t
lOOOOllO\
lO\
O
;
SinAnd\
Co\
s
(
lOOOO\
l\
OOO\
OO
,
lOOOOllOO\
ll
,
lOO\
OOl\
lOl\
OO\

)
;
fl\
o\
a\
t\

lllO\
O\
l\
lOOl
=
M11\

(
)
;
M11\

(
)
=
lOOOOl\
l\
Ol\
OO\

*
lllOOl\
lOO\
l\

+
lOOO\
Oll\
OOll
*
M31
(
)
;
M31
(
)
=
(
-
lO\
OOO\
llOO\
ll
)
*
ll\
lOOllOO\
l\

+
lOOO\
O\
l\
lOlOO
*
M3\
1
(
)
;
ll\
l\
OO\
llO\
O\
l
=
M12\

(
)
;
M1\
2
(
)
=
lOOO\
OllOl\
OO
*
ll\
lOOllOO\
l
+
lOOO\
OllOOll
*
M32
(
)
;
M32
(
)
=
(
-
lO\
OOOllOOl\
l\

)
*
lllOOllO\
Ol
+
lOO\
OO\
ll\
Ol\
OO
*
M32
(
)
;
lllO\
OllOO\
l
=
M13\

(
)
;
M13
(
)
=
lOOOOllOlO\
O
*
lll\
OOl\
lOOl
+
lOO\
OOllO\
Oll
*
M33\

(
)
;
M33
(
)
=
(
-
lOOOOl\
lOOl\
l
)
*
lll\
OOl\
l\
OOl\

+
lOO\
OOllOlOO
*
M33
(
)
;
}
brea\
k\

;
case
RO\
TA\
TION\
_AXIS\
_Z
:
{
float\

lOO\
OOllOOll\

;
float
lOO\
OOllOlOO
;
SinAn\
dCos
(
lO\
O\
OOlOO\
O\
OO
,
lOOOOll\
OOll
,
lOOOOllOlOO
)
;
float
lll\
O\
OllO\
O\
l
=
M11
(
)
;
M1\
1
(
)
=
lOOOOl\
l\
Ol\
OO
*
lllOOllOO\
l\

+
lO\
O\
OOllO\
O\
ll
*
M21
(
)
;
M21
(
)
=
(
-
lOOO\
O\
llOOll
)
*
ll\
l\
OOllOOl\

+
lOOO\
O\
llO\
lOO
*
M21
(
)
;
lllOOl\
lOO\
l
=
M12
(
)
;
M1\
2
(
)
=
lOOO\
Ol\
l\
Ol\
OO
*
lllOOllOO\
l
+
lO\
OOOllO\
Oll
*
M22
(
)
;
M22
(
)
=
(
-
lO\
OO\
OllOOll\

)
*
lllOOll\
OOl
+
lOOOO\
ll\
OlOO
*
M22\

(
)
;
ll\
lOOll\
OO\
l
=
M13
(
)
;
M13\

(
)
=
lOOO\
Oll\
Ol\
O\
O
*
ll\
l\
OOl\
lO\
Ol
+
lOO\
O\
OllO\
Oll
*
M23
(
)
;
M2\
3
(
)
=
(
-
lOOOOl\
l\
OOll\

)
*
lll\
OOllO\
Ol\

+
lO\
OO\
O\
l\
lO\
lOO
*
M23\

(
)
;
}
brea\
k
;
de\
fau\
lt\

:
lllOO\
lOOOO\

;
}
}
void
Ma\
t\
33\

::
Mul
(
const\

Ma\
t\
3\
3
&
lllOOlll\
lO\

,
const\

Mat33\

&
lll\
OOlll\
ll
,
Mat33\

&
lOOOOllO\
l\
Ol
)
{
lO\
O\
O\
Oll\
OlOl
.
M11
(
)
=
lllO\
Olll\
lO
.
M11\

(
)
*
lllOOlllll\

.
M11
(
)
+
lllOOllllO
.
M12\

(
)
*
lll\
OOl\
ll\
l\
l
.
M2\
1\

(
)
+
lllOOllll\
O
.
M1\
3\

(
)
*
lllO\
Olllll\

.
M31
(
)
;
lOOOOl\
lO\
l\
Ol
.
M12
(
)
=
ll\
lOOllllO
.
M11\

(
)
*
lllO\
O\
l\
lll\
l\

.
M12
(
)
+
lllOO\
llllO
.
M1\
2\

(
)
*
ll\
lOOlll\
l\
l
.
M22\

(
)
+
ll\
lOOllll\
O\

.
M13
(
)
*
lllO\
Ol\
llll
.
M32
(
)
;
lOO\
OOll\
OlOl
.
M1\
3
(
)
=
lllO\
OllllO
.
M11\

(
)
*
lllOOllll\
l
.
M13
(
)
+
lllO\
O\
lll\
l\
O
.
M12
(
)
*
lllO\
O\
lllll
.
M23
(
)
+
lllOOl\
ll\
lO
.
M13
(
)
*
lllOO\
lll\
ll\

.
M3\
3
(
)
;
lOOO\
OllOl\
Ol
.
M21
(
)
=
lll\
OOll\
llO\

.
M21\

(
)
*
lll\
OOl\
ll\
ll\

.
M11
(
)
+
lllOOlll\
lO\

.
M22
(
)
*
ll\
l\
OOlllll
.
M21
(
)
+
lll\
OOllllO\

.
M23
(
)
*
ll\
lOOl\
llll
.
M31
(
)
;
lOOOOl\
lO\
lOl
.
M22
(
)
=
lllOO\
llllO
.
M21
(
)
*
lll\
OOl\
lll\
l
.
M1\
2\

(
)
+
lllO\
OllllO
.
M22
(
)
*
lllOO\
llll\
l
.
M22
(
)
+
lllOOll\
llO
.
M23
(
)
*
lll\
O\
Ol\
ll\
ll
.
M3\
2\

(
)
;
lO\
OOOl\
l\
O\
lOl\

.
M23
(
)
=
ll\
lOO\
ll\
llO\

.
M2\
1\

(
)
*
lllOOlllll\

.
M13
(
)
+
lllOOl\
ll\
lO
.
M22
(
)
*
lll\
O\
Olllll
.
M23
(
)
+
ll\
lO\
O\
l\
l\
l\
lO\

.
M23\

(
)
*
lllO\
O\
lllll
.
M33
(
)
;
lOO\
OO\
ll\
O\
lOl
.
M3\
1
(
)
=
lllOOllll\
O
.
M31\

(
)
*
lllOOll\
lll\

.
M11
(
)
+
lllOO\
ll\
ll\
O
.
M32
(
)
*
lll\
O\
Olllll\

.
M21
(
)
+
ll\
lOOll\
l\
l\
O\

.
M3\
3
(
)
*
lllO\
Ol\
ll\
l\
l
.
M31
(
)
;
lOOOOll\
O\
lO\
l
.
M32\

(
)
=
lllOO\
l\
lllO
.
M31
(
)
*
lll\
OOl\
ll\
ll
.
M12
(
)
+
ll\
l\
O\
Olll\
lO
.
M32\

(
)
*
lll\
OO\
ll\
lll
.
M2\
2
(
)
+
lllOOllllO
.
M33
(
)
*
lllOOlll\
ll
.
M32
(
)
;
lO\
OOOllOlOl
.
M33
(
)
=
lllO\
OllllO
.
M3\
1\

(
)
*
lllOO\
llll\
l\

.
M13
(
)
+
lll\
OOllllO\

.
M32\

(
)
*
ll\
l\
OO\
llll\
l
.
M2\
3\

(
)
+
lll\
OO\
llllO\

.
M33
(
)
*
lllOOlllll
.
M33
(
)
;
}
voi\
d
TA_\
FA\
ST_\
CA\
LL
Ma\
t\
3\
3\

::
Mu\
lInPlace
(
Mat33\

&
lllOOll\
llO
,
const
Mat\
3\
3
&
ll\
lOOlllll
)
{
floa\
t
ll\
ll\
OO\
O\
OOl
=
ll\
lOOll\
ll\
O
.
M11\

(
)
;
float
llllOOOOl\
O\

=
lllOOlll\
lO
.
M12
(
)
;
float\

llllOOOO\
O\
O
=
lll\
OOll\
llO
.
M13
(
)
;
lllO\
Ol\
lllO
.
M11\

(
)
=
llll\
OO\
OOO\
l
*
lll\
OOlllll\

.
M1\
1
(
)
+
llllOOOOlO
*
ll\
lOOllll\
l
.
M21\

(
)
+
ll\
llOOOOO\
O
*
lll\
OOlllll\

.
M31
(
)
;
lllOOl\
l\
llO
.
M12
(
)
=
ll\
ll\
OOO\
O\
Ol
*
ll\
lOO\
ll\
lll
.
M1\
2
(
)
+
llllOO\
OO\
lO
*
ll\
l\
OOlllll
.
M22
(
)
+
llllO\
OOO\
O\
O
*
lll\
OOl\
ll\
ll
.
M32
(
)
;
lllOOl\
l\
llO
.
M1\
3\

(
)
=
llll\
O\
O\
OOO\
l
*
lll\
OO\
l\
ll\
ll
.
M1\
3
(
)
+
llll\
OOOOlO
*
ll\
lOOlllll
.
M23
(
)
+
ll\
llOOOOOO
*
lllOOl\
llll
.
M33
(
)
;
llllOOO\
OO\
l
=
lllO\
O\
l\
lllO\

.
M21
(
)
;
llll\
OOOOlO
=
lllO\
Ol\
ll\
lO
.
M22
(
)
;
ll\
l\
l\
OOO\
OO\
O\

=
ll\
lO\
Ol\
lllO
.
M23
(
)
;
lllO\
OllllO
.
M21
(
)
=
ll\
llOOOOO\
l
*
ll\
l\
OOlllll\

.
M1\
1
(
)
+
llllOOO\
OlO
*
lllOOll\
lll
.
M21\

(
)
+
ll\
l\
lOOOOOO
*
lllOOl\
llll
.
M31
(
)
;
lllO\
Ollll\
O
.
M22\

(
)
=
llll\
OOOOO\
l
*
ll\
lO\
Oll\
lll
.
M12\

(
)
+
llll\
O\
OO\
OlO
*
lllOOl\
lll\
l
.
M22
(
)
+
lll\
lO\
OOOOO
*
lllOOl\
l\
lll
.
M32
(
)
;
lllOO\
l\
lllO\

.
M23
(
)
=
lll\
lOOOOOl
*
lllOOlll\
ll
.
M13
(
)
+
lll\
l\
O\
O\
OOlO
*
lllOOll\
lll
.
M23
(
)
+
llll\
OO\
O\
OOO
*
lll\
OOlllll
.
M3\
3
(
)
;
llllO\
OOOOl
=
lllOOll\
llO
.
M31
(
)
;
ll\
llO\
O\
OO\
lO
=
ll\
lOO\
llllO
.
M3\
2\

(
)
;
llllO\
OOOOO
=
ll\
lOO\
llllO
.
M33\

(
)
;
lllOO\
llllO
.
M31
(
)
=
ll\
llOOO\
O\
Ol
*
lllOOlll\
ll
.
M11
(
)
+
lll\
lOOOOlO
*
lll\
OOlll\
ll
.
M21\

(
)
+
ll\
ll\
OOO\
OOO\

*
lll\
OO\
ll\
l\
ll\

.
M31\

(
)
;
lllOOlll\
lO\

.
M32
(
)
=
ll\
llOOOOOl\

*
lllOOlllll
.
M12
(
)
+
ll\
llO\
OO\
OlO
*
ll\
lOOl\
l\
lll\

.
M22
(
)
+
ll\
llOO\
OO\
O\
O
*
lllOOlllll
.
M32
(
)
;
ll\
lOO\
llllO\

.
M33
(
)
=
llll\
OOOO\
O\
l
*
lllOO\
l\
l\
l\
ll
.
M13
(
)
+
llll\
O\
OO\
OlO\

*
ll\
lOOlllll
.
M23\

(
)
+
ll\
l\
lO\
OO\
OOO
*
lllO\
Ollll\
l\

.
M33\

(
)
;
}
void
TA_F\
AST_CALL
Mat\
33
::
Mu\
l\
ByT\
ra\
n\
spos\
e\

(
con\
s\
t
Ma\
t\
33
&
lll\
OOlll\
lO
,
co\
nst\

Ma\
t33
&
lllOOllll\
l
,
Ma\
t33
&
lOO\
OOllOlOl
)
{
lOOO\
Oll\
OlOl
.
v3X
.
x
=
lllO\
O\
l\
lllO
.
v3X
.
Do\
t
(
lllO\
Ol\
ll\
ll
.
v3X
)
;
lOOOO\
llOlOl
.
v3X\

.
y
=
lllOOll\
ll\
O
.
v3X\

.
Dot
(
ll\
l\
OO\
lllll\

.
v3\
Y
)
;
lOOO\
Ol\
lOlOl
.
v3X
.
z
=
ll\
lO\
OllllO
.
v3\
X\

.
Dot
(
lllOOlllll
.
v3Z
)
;
lOO\
O\
OllOlOl
.
v3\
Y
.
x
=
lll\
OO\
llllO\

.
v3Y
.
Dot
(
ll\
lOOllll\
l
.
v3X
)
;
lO\
OO\
OllOlOl
.
v3Y
.
y
=
lllOO\
ll\
l\
lO\

.
v3Y
.
Do\
t
(
ll\
lOOlllll\

.
v3Y\

)
;
lOO\
O\
Oll\
OlO\
l\

.
v3\
Y
.
z
=
lllOOl\
lllO
.
v3Y
.
Dot\

(
lllOO\
ll\
l\
ll
.
v3Z\

)
;
lOO\
OOllOl\
O\
l\

.
v3Z
.
x
=
lll\
OOllllO
.
v3Z\

.
Dot
(
lllO\
Ollll\
l
.
v3X
)
;
lOOOO\
llOlOl
.
v3\
Z
.
y
=
ll\
lOOlll\
lO
.
v3Z
.
Dot
(
lllO\
Olllll
.
v3Y\

)
;
lOO\
OO\
l\
lO\
lOl\

.
v3\
Z
.
z
=
lllOO\
ll\
llO\

.
v3\
Z
.
Dot
(
ll\
lO\
Olll\
ll
.
v3\
Z
)
;
}
vo\
id\

TA_FAST\
_\
C\
AL\
L
Mat\
33
::
Mu\
lBy\
Tr\
ans\
pos\
eIn\
Place
(
Mat33
&
lllOOlll\
lO
,
const
Mat33
&
ll\
lOOlllll
)
{
Vec\
3
lOOOOll\
O\
llO
;
lOOOO\
l\
lOll\
O
=
lllOOllll\
O
.
v3X\

;
ll\
l\
O\
Ol\
l\
llO\

.
v3X
.
x
=
lOO\
O\
Ol\
lO\
llO
.
Dot\

(
lll\
OOlllll\

.
v3X\

)
;
lllOOl\
l\
llO
.
v3X\

.
y
=
lO\
OO\
Oll\
OllO
.
Dot\

(
lllOO\
lllll
.
v3Y
)
;
lllO\
O\
l\
ll\
l\
O
.
v3\
X
.
z
=
lOOOO\
llOllO
.
Dot
(
lllOO\
lllll
.
v3\
Z
)
;
lOO\
OOl\
l\
O\
llO
=
lllOOl\
ll\
lO
.
v3\
Y\

;
lllO\
Ollll\
O
.
v3Y\

.
x
=
lO\
OOOllOl\
lO
.
Do\
t\

(
lllO\
Olll\
l\
l\

.
v3X
)
;
ll\
l\
OO\
ll\
l\
lO
.
v3Y
.
y
=
lOO\
OOll\
O\
ll\
O
.
Dot\

(
ll\
lOO\
llll\
l
.
v3Y
)
;
ll\
lOO\
l\
l\
llO
.
v3Y\

.
z
=
lOOOO\
l\
lOll\
O
.
Dot
(
lllOO\
lllll
.
v3\
Z
)
;
lO\
OOOllO\
l\
l\
O
=
lll\
OOlll\
lO\

.
v3Z
;
lllOOllllO
.
v3Z
.
x
=
lOOOOll\
OllO
.
Dot
(
lllOOlll\
ll
.
v3X
)
;
ll\
lOO\
ll\
llO
.
v3Z\

.
y
=
lOOOOllOllO
.
Do\
t
(
lllOOlllll
.
v3Y
)
;
ll\
l\
OOll\
llO
.
v3\
Z
.
z
=
lOOOOll\
OllO
.
Dot
(
lll\
O\
Oll\
lll
.
v3Z\

)
;
}
vo\
id\

TA\
_FAST_CAL\
L
Mat33
::
Mul\
ByTr\
a\
nspo\
se
(
const
Ve\
c3
&
lllllllll
,
con\
st
Mat33
&
ll\
lOOlllll
,
Vec3
&
lOO\
OO\
llOlll
)
{
lO\
OOOll\
Olll\

.
x
=
lll\
llllll
.
Dot
(
ll\
l\
OOl\
l\
lll
.
v3X
)
;
lO\
OO\
OllOll\
l
.
y
=
ll\
lllllll
.
Do\
t
(
lll\
OO\
l\
ll\
ll\

.
v3Y\

)
;
lOOO\
O\
llOll\
l
.
z
=
ll\
ll\
lllll
.
Dot
(
lll\
OOl\
lll\
l\

.
v3Z
)
;
}
}