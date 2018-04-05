//---------------------------------------------------------------------------------
// File Name: zpta002.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef llOllOOOlOO
#define llOllOOOlOO
#ifndef TA_MATHS_H
#include "../Common/Maths.h"
#endif //
#ifndef lOOllOllll
#include "../Common/zcta001.h"
#endif //
#ifndef TA_VECTOR_H
#include "../Common/Vector.h"
#endif //
#ifndef llOOlOllOOO
#include "../Physics/zpta015.h"
#endif //
namespac\
e
TA
{
str\
uct
AABB\

;
cl\
as\
s
lO\
l\
Ol\
llllO\
O
llOlOlO\
OOOl
:
pu\
bl\
ic
llOOlO\
l\
lOOl
{
pu\
b\
l\
ic
:
ll\
O\
lOlOO\
OOl\

(
)
;
~
llOlOlOOOOl\

(
)
;
voi\
d
Initial\
ise
(
float
ll\
OlOlOlOll
,
int
llOlO\
l\
Oll\
O\
O\

,
const
AABB
&
lOOO\
OOOl\
ll
,
in\
t\

llOl\
O\
lOll\
Ol
,
int
llOlOlOl\
l\
l\
O
)
;
vo\
i\
d
Fin\
ali\
s\
e
(
)
;
void
lOlOlOOO\
Ol\

(
Sp\
ac\
eDivisio\
nO\
bj\
ect
&
llOO\
O\
OOOOOO
)
;
voi\
d
lOOl\
l\
lllll
(
SpaceDi\
visi\
onO\
bje\
c\
t
&
llOOOOOOOOO
)
;
void
ll\
OOOlO\
OllO
(
const
AA\
BB\

&
lO\
OOOOOll\
l
,
voi\
d
(
TAC_CAL\
L
*
llOOl\
O\
llOlO
)
(
Spa\
c\
eDivis\
io\
nOb\
jec\
t
&
llOO\
OO\
O\
OOOO
,
voi\
d
*
lOOlllOO\
OO
)
,
vo\
id
*
lOOOOl\
lllO
)
;
void
llO\
OOlOlllO
(
const\

Ve\
c3\

&
lO\
O\
lOl\
Oll\
l
,
const
Vec3
&
lOOlOll\
OOl
,
void
(
TAC_\
CALL\

*
ll\
O\
O\
lOllOlO\

)
(
Space\
Divisio\
n\
Ob\
ject\

&
llO\
O\
OOO\
OO\
OO
,
voi\
d\

*
lOOlllOOOO
)
,
void
*
lOO\
OOl\
l\
l\
lO
)
;
in\
line\

int
llO\
lO\
llO\
lOO
(
fl\
oa\
t
llOllOOOlOl
)
{
return
FastFloa\
tT\
oInt
(
(
ll\
OllOOO\
lO\
l
+
llOlO\
lOOllO
)
*
llO\
lOl\
OlOO\
O
)
;
}
in\
line\

int\

ll\
O\
lOllOl\
Ol\

(
float
llO\
llOO\
O\
l\
lO
)
{
retu\
r\
n
Fas\
tFloa\
t\
T\
o\
In\
t
(
(
llO\
ll\
OOOllO
+
llO\
lOlOO\
l\
l\
l
)
*
llOlOl\
OlOOl
)
;
}
private
:
int\

llO\
l\
OlO\
OOlO\

;
int\

llOlOlOOOll
;
in\
t
llOlO\
lOOl\
OO
;
int
llOlOl\
OOlOl
;
float
llOl\
OlOOllO
;
flo\
at
llOlOlOOl\
ll
;
fl\
oa\
t
llOlOlOlOOO
;
float
llO\
l\
Ol\
OlOOl\

;
lOOO\
O\
lOllO
<
Spac\
eD\
ivisi\
onOb\
j\
ect\

*
,
fal\
se
>
llOlOllO\
OO\
l
;
Spac\
e\
DivisionOb\
ject\

*
llO\
lOlOlO\
lO
;
Spa\
ceDivi\
sio\
n\
Ob\
je\
ct
*
*
llOlOllO\
llO\

(
int
llO\
OOO\
OO\
ll\

,
int
llO\
OOOOl\
OO\

)
{
return\

&
llO\
lOllOOOl
[
ll\
OO\
O\
O\
OlO\
O
*
llOl\
OlO\
OlOO\

+
ll\
O\
OOOO\
Oll\

]
;
}
}
;
}
;
#endif //
