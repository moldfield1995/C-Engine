//---------------------------------------------------------------------------------
// File Name: zpta021.cpp
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#define TA_PHYSICS_INTERNAL
#define lOllOllOOlO
#ifndef TA_PHYSICS_H
#include "DynamicObject.h"
#endif //
#ifndef TA_PHYSICS_H
#include "Physics.h"
#endif //
#define lOlOlllllOlO lOlOlOlOOO lOlOlOlOOl
names\
pace\

TA\

{
exter\
n
float
lOOlOllllllO\

;
ext\
ern
fl\
oat\

lOOl\
lOOO\
O\
OOl
;
exter\
n
float\

lOlO\
llll\
lOl\
l
;
namesp\
ac\
e
lOlO\
O\
lOOOO\
ll
{
lOlOlllll\
OlO
float\

lO\
O\
lOlllOlOO
(
Vec3
*
lO\
lOlOO\
lll
lOl\
Ol\
lllllOO
,
const\

Ve\
c3
*
lOlOl\
OOl\
ll
lOlOll\
lll\
lO\
l
,
cons\
t\

Vec\
3
*
lOlOlOOlll\

lOlO\
l\
ll\
l\
lllO
,
con\
st
Vec3
*
lO\
lOl\
O\
Olll
lOlOll\
lll\
lll
,
co\
n\
st\

Mat33
*
lOl\
Ol\
O\
Olll
lOl\
l\
OOOOO\
OO\
O\

,
const
flo\
a\
t
lOllOOOOOOO\
l
)
{
const
Ve\
c3
lOOll\
O\
O\
Ollll
=
*
lOl\
Olll\
llllO\

-
*
lOlOlllll\
l\
O\
l\

;
*
lOlOl\
lllllOO
=
lO\
lO\
llll\
lll\
l\

->
Cr\
oss
(
lOOllOOOl\
lll
)
*
*
lOllOOOOO\
O\
OO
;
fl\
o\
a\
t
lOOlOlllOO\
O\
O
=
-
lOlOllllll\
ll\

->
Dot
(
lO\
lOlll\
l\
llOO
->
Cross
(
lO\
Ol\
lO\
OOllll\

)
)
*
lOOlOll\
llllO
+
lO\
l\
lOO\
OO\
OO\
Ol\

;
retur\
n\

lOOlO\
lllOO\
O\
O
;
}
lOl\
OlllllOlO\

void
lOOlO\
l\
lllOlO\

(
Ve\
c\
3
*
lOl\
Ol\
O\
O\
lll\

lOOOl\
OOllOO
,
const\

Vec\
3
*
lOlOlOOl\
l\
l\

lOll\
O\
OO\
O\
O\
OlO
,
fl\
oat
lOll\
O\
OOOOOl\
l
)
{
*
lOOOlOOll\
OO
+=
*
lOllOO\
O\
O\
O\
OlO
*
lOl\
lOOOOOOl\
l\

;
}
lOlOll\
lllOlO
void\

lOOl\
l\
OOOO\
llO\

(
Vec3
*
lOl\
OlOO\
lll\

lOllOOOO\
OlOO\

,
con\
st
Ve\
c3
*
lO\
l\
OlO\
Olll
lOl\
lOOOOO\
lOl
,
const
Vec3\

*
lO\
lOl\
OOlll
lO\
llOOOO\
Ol\
lO\

,
cons\
t
Ve\
c3\

*
lOlOlOOlll
lOl\
lOOOOOl\
ll
,
const
Vec\
3\

*
lOlO\
lOOlll\

lO\
llOOOO\
lOO\
O
,
cons\
t\

Vec3\

*
lO\
lOlOOlll
lO\
l\
l\
O\
OOOlO\
Ol
,
const\

Vec3\

*
lOlO\
l\
O\
Olll
lOll\
O\
OOO\
l\
O\
lO
,
co\
ns\
t
Vec\
3\

*
lOl\
Ol\
OO\
lll
lOllOO\
OOl\
Oll\

)
{
Ve\
c3
lOl\
l\
OOO\
Ol\
lOO
=
*
lO\
ll\
OOOOOlOl
-
*
lOllO\
OOOl\
OOO\

;
Vec3\

lOl\
lOOOOllOl\

=
*
lOl\
l\
O\
O\
O\
OOlOl
-
*
lOll\
OO\
O\
OlOll\

;
Vec3
lOll\
O\
O\
OOll\
lO\

=
lOll\
OOOO\
Olll
->
Cro\
ss
(
lO\
llO\
O\
OO\
llOO
)
;
Vec3\

lOllOO\
OO\
llll\

=
lOll\
OOOO\
l\
OlO
->
Cr\
oss
(
lOllOOOOll\
Ol
)
;
*
lOllOOOO\
OlOO
=
*
lO\
llOO\
OOOl\
lO
;
*
lO\
l\
lOOOOOl\
OO
-=
*
lO\
ll\
O\
O\
OOlOOl
;
*
lO\
ll\
O\
OO\
OOl\
O\
O\

+=
lOl\
l\
O\
OOO\
lllO\

;
*
lOll\
O\
OO\
OOl\
OO\

-=
lO\
l\
lOOOOllll
;
}
#include "../Physics/zpta008.inl"
}
}
