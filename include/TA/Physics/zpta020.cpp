//---------------------------------------------------------------------------------
// File Name: zpta020.cpp
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifdef TA_DYNAMIC_OBJECT_GROUP_ENABLED
#include "../Physics/zpta008.h"
#ifndef TA_COLLISIONOBJECTCOMBO_H
#include "CollisionObjectCombo.h"
#endif //
nam\
espace\

TA
{
void\

Dyn\
ami\
cO\
bje\
ctGroup\

::
Init\
ialis\
e
(
Dynam\
icOb\
je\
ct
*
lOlllOOl\
O\
OO
)
{
Ini\
tial\
is\
eC\
o\
mmon\

(
)
;
lOOll\
OOlO\
llO
=
Co\
llisionOb\
jectCombo
::
Crea\
teNew
(
)
;
lOOllOO\
lOl\
lO
->
Initialis\
e
(
)
;
lOl\
Ol\
OlOl\
OO
=
lO\
l\
ll\
O\
OlOOO
->
lOlOlOl\
OlOO
;
lOOlOllll\
lOO
=
lO\
lllOOlOOO
->
lO\
O\
l\
O\
ll\
ll\
lOO
;
lOOllOOll\
O\
OO
=
lOl\
ll\
OO\
lOOO\

->
lO\
OllOOll\
OOO
;
lO\
OllO\
OllOOl\

=
lOlllOOlO\
OO
->
lO\
OllOO\
l\
lOO\
l\

;
lOOl\
lOlO\
O\
lOl
=
lOlllOO\
lOOO
->
Ge\
tC\
enterO\
ffset
(
)
;
Cle\
ar
(
)
;
SetFrame
(
lO\
lll\
OOlOOO\

->
Get\
F\
r\
a\
me\

(
)
)
;
lOlll\
OO\
lO\
OO
->
lO\
OllOllOOOl
=
this
;
lOlO\
ll\
lOOll\
O
&
lOl\
OlllOO\
l\
ll
=
lO\
l\
OlllOl\
OOO
.
lO\
OOlllOOO
(
)
;
lOlOl\
ll\
OOll\
l
.
lOO\
OOO\
OOOl
.
Cl\
ear
(
)
;
lOlOlllOOl\
l\
l
.
lOlllO\
O\
lOOO
=
lOl\
llO\
OlOO\
O\

;
}
vo\
id
Dyn\
a\
micOb\
jectGrou\
p\

::
Finali\
s\
e
(
)
{
}
void\

DynamicObjec\
tGr\
oup
::
Upd\
ate
(
float
lO\
Ol\
llOOlll\
l\

)
{
Dynam\
icO\
bj\
e\
ct\

::
Updat\
e\

(
lO\
Oll\
lOOllll
)
;
}
void
Dyna\
mic\
Object\
G\
ro\
up\

::
Appl\
yVe\
l\
o\
ci\
ty\
To\
Ne\
xtFr\
ame
(
flo\
at\

lO\
Olll\
OO\
llll
)
{
Dyn\
ami\
cObj\
e\
c\
t
::
Ap\
plyV\
elo\
ci\
t\
yToNe\
xtFrame\

(
lO\
OlllOO\
ll\
ll
)
;
for
(
lOlOlll\
Ol\
OOl
lOlOl\
l\
lO\
lOlO
=
lO\
l\
Ol\
llOlO\
O\
O\

.
lOlOOOO\
lO\
O\

(
)
;
!
lOlOll\
lOlOl\
O\

.
At\
E\
nd
(
)
;
++
lOlOll\
lOlO\
lO\

)
{
lOlO\
ll\
lOOllO
&
lOlOl\
llOOlll
=
*
lOlO\
lllOlO\
lO\

;
TA_ASS\
ERT
(
lOl\
Oll\
l\
OOlll
.
lOlllOOlOOO
)
;
lOlOlllOOlll
.
lOlllO\
OlO\
OO\

->
SetF\
ram\
e
(
lOlOll\
l\
OOlll
.
lOOOOOOOOl\

*
GetFrame
(
)
)
;
lOl\
OlllOOlll
.
lOlllOO\
lOOO
->
SetAngularVelo\
cit\
y\

(
(
(
GetAn\
g\
ularVe\
l\
ocit\
y
(
)
/
GetFrame
(
)
.
m33\
Rota\
ti\
o\
n\

)
*
lOlOlllOOl\
ll
.
lOOOO\
OOOO\
l\

.
m3\
3Ro\
tation
)
*
GetF\
rame
(
)
.
m33Rotati\
on
)
;
lOl\
OlllOOl\
ll
.
lOl\
llOOlOOO
->
Se\
tLine\
a\
rVelocity\

(
GetV\
elocityAtW\
orldPosition\

(
lOlO\
lll\
OOl\
ll
.
lO\
l\
l\
l\
OOl\
OOO\

->
GetCe\
n\
terOfM\
ass
(
)
)
)
;
lOlOlllOOll\
l
.
lOlllOOlOOO
->
Ap\
plyVelocit\
yToNextF\
rame
(
lOO\
lllOO\
llll
)
;
}
}
void
Dynam\
ic\
Obje\
ctGroup
::
Ad\
d\
DynamicO\
bj\
ect
(
Dy\
namicObje\
ct
*
lOlllOOlOO\
O
)
{
lOl\
O\
lll\
OOllO\

&
lOlOl\
llOOlll\

=
lO\
lOlll\
OlO\
O\
O\

.
lOO\
Ol\
llOOO
(
)
;
lO\
lOlllO\
Olll\

.
lOO\
OO\
OOO\
Ol
=
lOll\
l\
OO\
lOOO
->
Ge\
tFram\
e
(
)
/
Ge\
t\
Frame
(
)
;
lOlOlllOOl\
ll
.
lOl\
llOOlOOO\

=
lO\
ll\
lOOlOOO
;
Calc\
ula\
teMass\

(
lO\
l\
Ol\
O\
lOlOO
,
lOOllOlOOlOl
,
lO\
Ol\
lO\
Ol\
lOOO\

)
;
TA_ASSERT
(
lO\
lOlOlOlOO
>
0.0f
)
;
lOOlO\
ll\
ll\
lOO
=
1.0f
/
lO\
lOl\
OlOlOO
;
lOOllOOllOOl\

=
lOO\
ll\
OOllOO\
O
.
GetInverse
(
)
;
lOlllO\
OlOOO
->
lOOllOl\
lOOO\
l
=
th\
i\
s
;
lOOlOlllOl\
Ol
=
lOO\
l\
l\
Ol\
OOlOl\

*
lO\
Oll\
OlOOlll
;
lOO\
l\
lOlOOll\
O
=
lO\
OllO\
l\
O\
Ol\
Ol
*
lOOll\
O\
lOlOOO
.
v3Tr\
an\
slation
;
}
void
Dyna\
micO\
b\
ject\
Gro\
up
::
Re\
mov\
eDyn\
a\
m\
ic\
Obj\
e\
ct
(
Dy\
n\
amicObj\
ect\

*
lOlllOOl\
OOO\

)
{
lOOO\
OOOl\
l\
O\

(
0
,
"DynamicObjectGroup::RemoveDynamicObject: Todo")
;
}
Dynam\
icObjectG\
roup
*
Dynam\
ic\
Ob\
j\
ectGro\
u\
p
::
Creat\
eNew
(
)
{
DynamicO\
bje\
c\
tG\
rou\
p\

*
lO\
lO\
llOlO\
O\
l\

;
lOOOOO\
l\
lOl\
O
(
lO\
l\
OllOlO\
O\
l\

,
Dyna\
mic\
Objec\
tGr\
o\
up
)
;
return
lOlOllOl\
OOl\

;
}
Dyna\
m\
i\
c\
ObjectG\
roup
::
Dyna\
m\
icObjec\
tGroup
(
)
:
DynamicObject
(
)
{
}
Dynamic\
Obj\
e\
ctGr\
oup\

::
~
Dynami\
cObject\
G\
ro\
up\

(
)
{
Finalise
(
)
;
}
void\

Dyn\
amic\
Obj\
ectGroup
::
Calcula\
teMas\
s
(
fl\
oat
&
lOll\
OOO\
Oll\
O
,
Ve\
c\
3
&
lllOllO\
OOlO
,
Ma\
t3\
3
&
lllOllOOOll
)
const\

{
lOl\
O\
l\
llO\
lO\
l\
l
lOlOlllOlOl\
O\

;
ll\
l\
OllO\
O\
Ol\
O
.
Cle\
ar
(
)
;
lO\
ll\
OOOOllO\

=
0
;
lll\
OllOOOll
.
v3X
.
Clear
(
)
;
lllOl\
lOOOll
.
v3Y
.
Cl\
ear
(
)
;
lllOllOOO\
ll
.
v3Z
.
Clear
(
)
;
for
(
lOlOl\
l\
lO\
lOlO
=
lO\
lOlllOl\
O\
OO
.
lOOO\
OO\
l\
lOO\
O
(
)
;
!
lOl\
OlllOlO\
l\
O
.
AtE\
nd
(
)
;
++
lOlOl\
llOlO\
lO
)
{
con\
s\
t
lOlOlllOO\
l\
l\
O
&
lOlO\
lllOO\
l\
ll
=
*
lOl\
O\
ll\
lOlOl\
O
;
TA_ASSERT
(
lOlO\
ll\
l\
OOl\
l\
l
.
lOlllOOlO\
O\
O\

)
;
lOllOOOO\
llO
+=
lO\
l\
O\
ll\
l\
OOl\
ll
.
lO\
lllO\
OlO\
OO\

->
GetMas\
s
(
)
;
lll\
Ol\
lOO\
Ol\
O\

+=
(
lO\
lO\
lll\
OOlll
.
lO\
lllOOl\
O\
OO
->
Ge\
tCen\
terO\
ffset\

(
)
*
lOlOll\
lO\
O\
ll\
l\

.
lO\
OOOOOO\
O\
l
)
*
lOlOl\
l\
lOOlll
.
lO\
l\
llOO\
lOOO
->
GetMa\
ss
(
)
;
}
if
(
lOllOO\
OOll\
O
>
0.0f
)
lllOllOOOl\
O\

/=
lO\
l\
lO\
OOOllO
;
for
(
lOlOlllOlOlO
=
lOlO\
lllO\
lOO\
O
.
lOO\
O\
OOllOOO
(
)
;
!
lO\
l\
Olll\
O\
lOlO
.
AtE\
nd\

(
)
;
++
lOlOll\
lO\
lO\
l\
O
)
{
con\
st\

lOlOlllOOllO
&
lOlO\
lllOOlll
=
*
lOlOl\
llOlO\
l\
O
;
TA\
_A\
SSERT
(
lOl\
Oll\
lOOll\
l\

.
lO\
lllOOlOOO\

)
;
Mat33\

lO\
lOlllOllOO
=
lOlO\
lllOO\
lll
.
lOOO\
O\
O\
OO\
Ol\

.
m33R\
o\
tation\

.
Get\
Tra\
nspo\
seAs\
Inv\
er\
se
(
)
*
lOlOlllO\
Olll
.
lOlll\
OO\
lOOO
->
lOO\
llOOllO\
OO\

*
lOl\
O\
lllOOl\
l\
l
.
lOOOO\
OOO\
Ol\

.
m33Rotati\
o\
n
;
float\

lOlOlllOl\
lOl
=
lOlO\
l\
ll\
OOl\
ll
.
lOll\
lO\
OlO\
OO
->
GetMass
(
)
;
Vec3
lO\
l\
OlllO\
l\
llO
=
lOlOlllOOl\
ll
.
lOlll\
OOlOOO\

->
Ge\
tCe\
nterOffset\

(
)
*
lOl\
OlllOOlll
.
lOO\
OOOO\
OOl
;
Vec3
lllOl\
OllOOO
=
lOlOl\
llO\
lllO
-
lllOllOOOl\
O
;
lOlOlllO\
llO\
O
.
M11
(
)
+=
lO\
lOl\
ll\
OllO\
l
*
(
lll\
O\
lOl\
lOO\
O\

.
y
*
lllOlO\
llO\
O\
O
.
y
+
lllOl\
OllO\
OO
.
z
*
lll\
Ol\
O\
llOOO\

.
z
)
;
lO\
lO\
l\
llOl\
l\
O\
O
.
M2\
2
(
)
+=
lOlOlllOll\
Ol\

*
(
ll\
lOlOllOOO
.
z
*
lll\
OlOllOOO
.
z
+
lllOlOllOOO\

.
x
*
lllOlO\
ll\
OOO
.
x
)
;
lOlOl\
l\
lO\
ll\
OO
.
M3\
3
(
)
+=
lOlOlllO\
llOl
*
(
ll\
lO\
lOl\
lO\
OO
.
x
*
lll\
OlOl\
l\
OOO
.
x
+
ll\
lOlOl\
l\
OO\
O
.
y
*
lllO\
lOllOOO\

.
y
)
;
lOl\
Olll\
Ol\
l\
O\
O
.
M12
(
)
=
lOlOll\
lOllOO\

.
M21\

(
)
-=
lOl\
Ol\
ll\
O\
llOl
*
ll\
l\
OlO\
llO\
OO\

.
x
*
ll\
lOlO\
llOO\
O
.
y
;
lO\
l\
Oll\
l\
O\
llOO
.
M23
(
)
=
lO\
lO\
lllOl\
lOO
.
M3\
2\

(
)
-=
lOlOll\
lOllOl
*
lllOlO\
llOOO
.
y
*
lllOl\
O\
llO\
OO
.
z
;
lO\
lO\
lllOll\
OO
.
M13
(
)
=
lOlOlllO\
llO\
O
.
M3\
1
(
)
-=
lOl\
Oll\
lO\
llOl
*
lllOlOllOOO
.
z
*
lll\
Ol\
O\
llO\
OO
.
x
;
lllOllOO\
Oll
+=
lOlOll\
lOll\
O\
O
;
}
}
}
#endif
