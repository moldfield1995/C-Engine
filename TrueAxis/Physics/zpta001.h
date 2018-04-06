//---------------------------------------------------------------------------------
// File Name: zpta001.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef llOOllOOOOl
#define llOOllOOOOl
#ifndef TA_VECTOR_H
#include "../Common/Vector.h"
#endif //
na\
m\
espac\
e\

TA
{
co\
n\
st
int\

lO\
ll\
lOOl\
Oll
=
31
;
co\
ns\
t\

floa\
t\

llO\
O\
l\
lOOOlO\

=
0.01f
;
ex\
tern\

flo\
at
llOOllOO\
Ol\
l\

;
na\
m\
e\
space
llOO\
llO\
O\
lOO
{
inline
bo\
ol
IsZe\
ro
(
con\
s\
t
Vec3
&
ll\
lll\
ll\
ll
)
{
re\
tu\
rn\

ll\
ll\
lllll
.
Ge\
tM\
agni\
tude
(
)
<
0.01f
*
0.01f
;
}
in\
l\
ine\

bool
llOOllOO\
l\
O\
l
(
const\

Vec3
&
lll\
lllll\
l
,
co\
ns\
t
Vec3
&
lO\
OO\
OOOOO\
O
)
{
re\
t\
u\
r\
n
Is\
Zero
(
lOOO\
OOOO\
O\
O
-
ll\
l\
l\
ll\
lll
)
;
}
}
}
#endif //
