//---------------------------------------------------------------------------------
// File Name: zpta007.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef lllOOOllOOO
#define lllOOOllOOO
#ifndef TA_MFRAME_H
#include "../Common/MFrame.h"
#endif //
#ifndef TA_COLLISION_H
#include "Collision.h"
#endif //
nam\
e\
spa\
ce\

TA
{
boo\
l
TAC_CALL
lllOllll\
OOO
(
Collis\
ion
&
ll\
O\
lll\
lOlll
,
lOll\
Oll\
l\
OO\
O\

*
lOOl\
O\
l\
OO\
l\
O\
OO
)
;
boo\
l
TAC_CA\
L\
L
lllOOll\
Ol\
ll
(
Collision
&
llOlll\
lOlll
,
lO\
llO\
ll\
lO\
OO
*
lO\
OlOlOOl\
OOO
)
;
int
TAC_CALL
lO\
OOllllOOOO
(
fl\
oa\
t
lll\
lOOOO\
lO\

,
float
llllOOOOOO
,
float\

lll\
Ol\
lllll
,
float
lOOOll\
l\
OllOO
,
fl\
oat
lOOOll\
l\
Oll\
l\
O
[
4
]
)
;
boo\
l
TAC_CALL\

lOO\
Oll\
O\
llO\
Ol\

(
const
Vec3
&
lOO\
lO\
l\
lO\
OOOl
,
const
Vec3
&
lOOl\
O\
llO\
OOlO
,
con\
st
Vec\
3
&
lOOlOll\
OOOl\
l
,
const
Vec3\

&
lO\
Ol\
Ol\
l\
O\
OlOO\

,
flo\
a\
t
lOOlOll\
OOlOl
,
floa\
t
lOOlO\
l\
lO\
Oll\
O
,
fl\
o\
at\

&
llllO\
l\
OOll
,
Vec3
&
lOll\
llOOl\
l
,
Ve\
c3
&
lOlll\
lOl\
OO
)
;
in\
lin\
e
int
TAC_C\
ALL
lOlllOllOOl\

(
int\

lOO\
l\
lOl\
O\
OO\
O
,
in\
t
lOOl\
O\
llOllO\
O
)
{
int
lOlllOllOOO
=
lOOllO\
lOO\
OO
+
1
;
if
(
lO\
lllO\
l\
lOOO
>=
lO\
OlOll\
OllOO
)
lOl\
llO\
l\
lOOO
=
0
;
re\
tu\
r\
n
lO\
lllO\
llO\
OO
;
}
inlin\
e
int
TAC_\
CA\
LL\

lO\
ll\
l\
Olllll
(
int
lOO\
llOlOOOO
,
in\
t
lOOlOl\
lOll\
OO
)
{
in\
t
lOll\
lOllOO\
O
=
lOOll\
O\
lOOO\
O
-
1
;
if
(
lOlll\
O\
l\
lOOO
<
0
)
lO\
lllO\
llO\
OO
=
lO\
Ol\
OllOl\
lOO
-
1
;
return
lOlllOllOOO
;
}
}
#endif //