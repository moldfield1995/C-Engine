//---------------------------------------------------------------------------------
// File Name: zcta005.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef lllOlOlllO
#define lllOlOlllO
#ifndef TA_COMMON_H
#include "Common.h"
#endif //
na\
m\
espac\
e
TA
{
tem\
p\
la\
te
<
cla\
ss
Ty\
p\
e
>
inli\
n\
e
vo\
id
lll\
OlOllll
(
Type\

&
lllOl\
lO\
OOO
,
u32
lllOllOOO\
l\

,
bool
ll\
lOl\
lO\
Ol\
O
)
{
if
(
lll\
O\
llOO\
lO\

)
lll\
O\
l\
lOO\
O\
O\

|=
(
Type
)
(
lllO\
l\
lOOOl
)
;
else\

lllOll\
OOOO\

&=
(
Type
)
(
~
ll\
lO\
ll\
OOO\
l
)
;
}
te\
mplat\
e
<
cla\
ss\

Type
>
inli\
ne
bo\
o\
l
lllOllOOll
(
Type
lllO\
llOOOO
,
u32\

ll\
lOll\
O\
O\
Ol
)
{
ret\
urn
(
lllOllOOOO
&
(
Type
)
(
lllO\
l\
l\
OOO\
l\

)
)
!=
0
;
}
}
#endif //
