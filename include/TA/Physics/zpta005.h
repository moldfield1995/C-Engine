//---------------------------------------------------------------------------------
// File Name: zpta005.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef lOOlOOllllOO
#define lOOlOOllllOO
#ifndef lOOllOllll
#include "../Common/zcta001.h"
#endif //
#ifndef TA_AABB_H
#include "../Common/AABB.h"
#endif //
#ifndef llOOlOllOOO
#include "../Physics/zpta015.h"
#endif //
namespac\
e\

TA\

{
st\
r\
uct
AABB
;
class\

lOlO\
lllllO\
O
lOO\
lOO\
Ol\
Oll\
O
:
public
ll\
OOlOllO\
Ol
{
public\

:
lOOlOOOlOll\
O
(
)
;
~
lOOlOOO\
l\
Ol\
lO
(
)
;
vo\
id
Initiali\
se
(
float
llOlO\
l\
OlO\
ll
,
int
llO\
lOl\
OllOO
,
cons\
t
AABB
&
lO\
OOOOOll\
l\

)
;
void\

Fi\
na\
li\
se
(
)
;
vo\
id
lOl\
OlOOOO\
l
(
SpaceDiv\
i\
sio\
nOb\
ject
&
ll\
OOOO\
O\
OO\
O\
O
)
;
void
lOOlllllll
(
Sp\
a\
ceDi\
v\
is\
ionO\
b\
je\
ct
&
llOO\
OOOO\
O\
O\
O
)
;
void
llOOOl\
OOllO
(
const
AABB
&
lOOOOOOlll
,
void\

(
TA\
C_CALL\

*
llOO\
lOl\
lOlO\

)
(
Spa\
ce\
Divisi\
onO\
bject
&
ll\
OO\
OOOOO\
OO
,
void
*
lOOlllOO\
OO
)
,
voi\
d\

*
lOOOO\
llllO
)
;
void
llOOOl\
Ol\
ll\
O
(
co\
nst
Vec3
&
lOO\
lO\
lOll\
l
,
con\
st
Vec3
&
lO\
O\
l\
OllO\
Ol
,
vo\
id
(
TAC_CALL
*
llOOlO\
l\
lOlO
)
(
SpaceDiv\
i\
si\
on\
Object
&
llOOOOO\
OOO\
O
,
void\

*
lOOlllOOOO\

)
,
voi\
d\

*
lOOOOl\
lllO
)
;
priva\
te
:
enum
{
lOOlOOl\
lllO\
l
=
0
,
lOOlOOlll\
ll\
O\

,
lOOlO\
Ol\
lllll
,
lOOlOlOOOO\
OO
,
lOOlOlOOO\
OOl\

,
lOO\
lOlOOOOlO\

,
lO\
Ol\
O\
lOO\
OOll
,
lOOlOlO\
OOlOO
,
}
;
en\
um\

Flags\

{
lOOlOO\
Ollll\
O\

=
0x1
,
lOO\
lOOlOll\
O\
O\

=
0x2
,
}
;
struct
ll\
OOO\
OOlOOO\

{
Spa\
ceDiv\
isionObject
*
llO\
OO\
OlO\
llO
;
llOO\
O\
OOlOOO
*
llOOO\
O\
OllOl
;
s8
llOO\
OOlOlO\
O
;
s8\

ll\
OOOOlOO\
lO
;
u8\

llOllOO\
lll
;
u8
lOlO\
llOOll\

;
llOOO\
OOlOOO
*
llOO\
OOlO\
Oll\

[
8
]
;
llO\
OOOOl\
OOO
(
)
;
llOOOO\
Ol\
OOO\

*
&
lOOOOO\
lOOO\
l
(
)
{
return
(
ll\
OOOOOlOOO
*
&
)
llO\
OOO\
lOl\
lO\

;
}
ll\
OOOO\
Ol\
O\
OO
*
*
&
lOO\
lOOOOOlO
(
)
{
retur\
n
(
llOO\
OO\
OlOOO
*
*
&
)
ll\
OOOOOllO\
l
;
}
}
;
stru\
ct
lO\
OlOOOl\
Olll
{
Spa\
ce\
Division\
O\
b\
ject
*
llOOOOlO\
llO\

;
llOO\
O\
OOlO\
O\
O
*
ll\
OOOO\
Ol\
lOl
;
s8
llOOOOlOlO\
O
;
s8
llO\
O\
OO\
lOOl\
O
;
u8
llOllO\
Ol\
ll
;
u8
lOl\
O\
llO\
Oll\

;
ll\
OOOOOl\
OOO
*
llOOOOO\
lll\
O
;
lO\
OlO\
OO\
lOlll
(
)
;
lOOlOOOlO\
ll\
l
*
&
lO\
O\
OOO\
l\
OOO\
l
(
)
{
return
(
lO\
OlO\
O\
OlOl\
ll
*
&
)
llO\
O\
O\
OlO\
llO
;
}
lO\
Ol\
OOO\
lOlll
*
*
&
lOO\
lOOOO\
O\
lO
(
)
{
ret\
urn
(
lOOl\
OOO\
l\
Ol\
ll\

*
*
&
)
ll\
OO\
OOOl\
lOl
;
}
}
;
struct
lOO\
lOOl\
OlOOO
{
AAB\
B
lO\
OOOOOlll
;
in\
t\

ll\
OOOO\
OOll
;
int\

llOOOO\
OlOO
;
int\

llOOO\
OOlOl\

;
in\
t\

llOOOl\
O\
lOl\
O
;
in\
t\

llOO\
OlOl\
Oll\

;
in\
t
llOOOlOllOO
;
void
(
TAC\
_CALL
*
llOOlOl\
lOlO
)
(
Sp\
a\
ce\
Divisi\
onO\
bject\

&
llOO\
OOOOO\
OO
,
vo\
id
*
lOO\
lllO\
OOO
)
;
void
*
lOOOO\
llll\
O
;
}
;
struct
lOOl\
OOlOlOlO
{
const
lOO\
l\
OOOlOllO
*
lOllOll\
OOOl\

;
void
(
TAC_\
C\
A\
LL
*
ll\
O\
OlOl\
lOlO
)
(
Sp\
ac\
eDivi\
s\
io\
nO\
bje\
ct\

&
llOOO\
OOOOOO
,
void
*
lO\
O\
lll\
OOOO
)
;
voi\
d
*
lOO\
O\
Ollll\
O
;
floa\
t\

lOOlOll\
O\
OO\

;
Vec3
lOOlOl\
Ol\
l\
l
;
Vec3
lO\
O\
lOllOOl
;
stru\
ct
Ax\
i\
s\

{
fl\
oat
llOO\
Ol\
lOOll
;
float\

llO\
O\
O\
llOOlO
;
float
llOO\
Oll\
OlOO
;
int
llOOOllOl\
Ol
;
float
llO\
OO\
llO\
llO
;
floa\
t
llOOOl\
lOlll
;
}
;
Axi\
s
lO\
OO\
OOl\
lOl\

[
3
]
;
}
;
int
lOO\
lO\
OO\
llOOO\

;
llOOOOOl\
OOO\

*
lOO\
llOlllOl
;
lOOlOOOlOlll
*
lOO\
lOOO\
lllO\
l
;
int
lOO\
lO\
OOO\
O\
OOl
;
int\

lOO\
l\
OOOOO\
O\
ll
;
lOOOOl\
OllO
<
u32\

,
false
>
lO\
OlOO\
OOOOOO
;
AAB\
B
llll\
OlOOO\
lO
;
llOOOOO\
l\
OO\
O\

*
lOOlOOOllO\
Ol
;
llOOOOOlOOO
*
ll\
O\
O\
OO\
l\
OOOO\

(
ll\
OO\
OO\
OlOOO
*
*
lOOl\
OOlOlOll\

)
;
void
llOOO\
OOOlOO
(
ll\
O\
OOOOlOOO
*
llOOO\
OO\
lO\
Ol
)
;
lOOlO\
OOlOlll
*
lO\
OlOO\
lOOllO
(
llOOOOOl\
OO\
O
*
*
lOO\
lO\
OlO\
lO\
l\
l
)
;
voi\
d
lOOlOOlOO\
OOO
(
lO\
Ol\
OOOl\
Olll\

*
llO\
OOOOlO\
O\
l\

)
;
void
lO\
Ol\
OOllOOOl
(
in\
t
lOOlOOllO\
Oll
,
llOO\
OOOlOOO\

*
*
lOOlOO\
lOlOll
)
;
vo\
id
lOOlO\
OllO\
OlO
(
in\
t
lO\
Ol\
OOl\
l\
OO\
l\
l
,
llOOO\
O\
OlOOO
*
*
lOOlO\
OlOlO\
ll\

)
;
voi\
d
lOO\
lO\
OOO\
OlOl
(
ll\
OOO\
OOl\
OOO
*
ll\
OOOO\
OlOOl
,
bool
lO\
OlO\
Ol\
lO\
lOO
)
;
#ifdef _DEBUG
void
llOOOlOll\
Ol
(
#else
st\
ati\
c
voi\
d\

TA_FA\
ST\
_CALL
llOOOlOllOl\

(
#endif		
llOO\
OOOlOO\
O
*
ll\
OOOOOlOO\
l
,
int
lOO\
l\
O\
OlO\
OlOl
,
int\

llOOOOO\
Oll\

,
in\
t\

llO\
OOOO\
lO\
O\

,
int\

ll\
OOO\
OOlO\
l
,
lOO\
lO\
OlOl\
OOO
*
lOOl\
OOl\
l\
OlOl\

)
;
#ifdef _DEBUG
vo\
id
llOOO\
lllO\
OO
(
#else
stati\
c
vo\
id\

TA\
_FAST_\
CAL\
L\

llOOO\
l\
llO\
OO\

(
#endif				
llOOOOO\
lOOO
*
ll\
OOOOOlOOl\

,
float
llOlllO\
OOl
,
Vec3
&
v3Center
,
lO\
Ol\
OOl\
O\
lOlO
*
lOOlOOllO\
lOl
)
;
vo\
id
lO\
OlO\
OO\
Ol\
O\
OO
(
llOOOOOl\
OO\
O
*
ll\
OOO\
OOlO\
Ol
)
;
bool
lOO\
lO\
OOOl\
Oll
(
llOOOO\
O\
lOO\
O
*
llO\
OOO\
OlO\
Ol
,
llOOO\
OOlOOO
*
lOO\
lOOOOlO\
lO
)
;
void
lOOlOOOOll\
O\
l
(
ll\
O\
O\
OO\
Ol\
OO\
O
*
ll\
O\
O\
OOO\
lO\
Ol
,
llOOOO\
OlOOO
*
lOO\
lOOOO\
lO\
l\
O
)
;
}
;
}
;
#endif //
