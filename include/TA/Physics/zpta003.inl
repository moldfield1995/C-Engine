//---------------------------------------------------------------------------------
// File Name: zpta003.inl
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

{
int
lOOOllOOOl\

;
TA_ASS\
ERT\

(
ll\
OOOlOl\
OO
->
lO\
llO\
lllOl
<
lOlllOOl\
Ol\
l
)
;
TA\
_\
ASSERT\

(
lO\
l\
llOOlOll
<=
32
)
;
u32
llOOll\
OOllO
=
0
;
stru\
ct
{
bool
llOOl\
lO\
Ol\
ll
:
1
;
boo\
l
llOOl\
lOl\
O\
OO
:
1
;
bo\
o\
l
llOOl\
lO\
lO\
Ol
:
1
;
}
llOOl\
lOlO\
lO
;
ll\
OOl\
l\
OlO\
l\
O
.
llOOl\
l\
OO\
l\
ll
=
fal\
se\

;
llOOl\
l\
OlO\
l\
O
.
llO\
Oll\
Ol\
OOO
=
false\

;
ll\
O\
OllOl\
OlO\

.
llOOl\
lOlO\
O\
l
=
fa\
lse
;
int
lOl\
l\
l\
O\
lOO\
O
=
0
;
for
(
lOll\
l\
OlOOO\

=
0
;
lOlll\
OlOOO
<
2
;
lOlll\
OlOO\
O
++
)
{
const
Vec3
&
llO\
OllOlOll
=
lOlllOlOOOO
[
lO\
lllOlOOO
]
;
float\

lOll\
lOlllO
=
lOl\
llO\
l\
O\
OOl
(
ll\
O\
O\
llOlO\
ll
)
;
Ve\
c3\

ll\
OOll\
Ol\
l\
OO\

=
llOOOlOlOO
->
lO\
OO\
lOOOO\
O
.
Cr\
o\
s\
s
(
llOOllOll\
Ol
)
;
float\

llO\
O\
llO\
ll\
lO
=
ll\
OOllO\
llO\
O
.
Get\
Magn\
i\
tude
(
)
;
if\

(
llO\
OllOll\
lO\

<
0.01f
)
co\
nt\
inue\

;
fl\
oat\

ll\
OOllOllll
=
llOOllOll\
l\
O
*
llOOlllOOOO
.
lOl\
O\
lOOlOlO
;
if
(
lO\
lllOlllO
>
llO\
OllO\
ll\
ll\

||
lOll\
lO\
ll\
lO\

<
-
llOOllOllll\

)
cont\
inue\

;
fl\
o\
at
ll\
OOll\
l\
OOOl
=
1.0f
/
llO\
Ol\
l\
O\
l\
l\
l\
O
;
llOOll\
Oll\
OO
*=
llO\
Olll\
OOO\
l
;
Ve\
c\
3
llOO\
l\
ll\
OO\
lO
=
ll\
OOl\
lOllOO
.
Cr\
oss
(
llO\
O\
llOl\
lO\
l
)
;
if
(
llO\
Olll\
O\
O\
lO
.
Dot\

(
llOOOlOl\
O\
O
->
lOOOl\
OO\
OOO
)
>
0.0f
)
llO\
O\
l\
l\
lOOl\
O
=
-
llOO\
ll\
lOOlO\

;
TA_ASSE\
RT
(
1.0f
-
lOl\
llOlllO
/
llOOllOllll
>=
0.0f
)
;
fl\
oat
lllO\
OllOO\
l\

=
lO\
ll\
lO\
lllO
/
ll\
OOllO\
lll\
l
;
float\

llOO\
lll\
OO\
ll
=
Sqrt
(
1.0f
-
lll\
OOllOOl
*
lllOOllOOl
)
*
llOOlll\
OOO\
O\

.
lOlO\
lOOlOlO
;
Ve\
c\
3
lllll\
ll\
l\
l\

=
llOO\
llOlOll
+
ll\
O\
O\
l\
llOOlO
*
lOlll\
Ol\
llO\

*
ll\
OOlllOOO\
l\

+
llOOll\
Ol\
lOO
*
llOOlllOOl\
l
;
Ve\
c3
lO\
OO\
O\
O\
O\
OOO
=
llOO\
llOlO\
ll\

+
ll\
OO\
l\
l\
l\
O\
O\
lO
*
lOlllOlll\
O\

*
llOOl\
llOOOl\

-
llOOllOllOO
*
llOOlllOOl\
l
;
int
llO\
O\
lll\
OlO\
O
=
-
1
;
int
llOOlllO\
lOl\

=
-
1
;
for
(
lOOO\
ll\
OO\
Ol\

=
0
;
lOOOl\
lOOO\
l
<
llOOOlOlO\
O
->
lOllO\
lllOl
;
lOOO\
llO\
OOl
++
)
{
const
Vec3
&
lO\
l\
llOlOlO\
O\

=
lOll\
l\
O\
lOlOl
(
lO\
O\
Ol\
lOO\
Ol
)
;
float
lOl\
OllOlOO
=
llOOO\
l\
OlOO\

->
llOl\
lllOlO\

[
lOO\
OllOOO\
l
]
.
lOlllO\
lOll\
l
.
Dot
(
lOlllOl\
OlOO\

-
ll\
l\
ll\
l\
lll
)
;
flo\
at\

lOlOllOlOl\

=
llO\
OO\
l\
OlO\
O
->
ll\
OllllOlO
[
lOOO\
l\
lO\
OOl
]
.
lOlllOl\
O\
ll\
l\

.
Dot
(
lO\
lllOlOl\
OO
-
lO\
OOOOOOO\
O
)
;
if
(
lO\
lO\
llOl\
OO
>
0.0f
)
{
if
(
lOlOll\
OlO\
l
>
0.0f
)
break\

;
float\

lll\
Ol\
l\
ll\
lO\

=
(
lO\
lOllOlOO\

/
(
lO\
lOll\
OlOO\

-
lOlOl\
lOl\
Ol
)
)
;
lllllllll
+=
(
lO\
OOOOOOOO
-
llll\
llll\
l\

)
*
lll\
Olllll\
O
;
ll\
OOlllOlOO
=
lOO\
Oll\
OOOl
;
}
el\
se
if\

(
lOlOl\
lOlOl
>
0.0f
)
{
float
lll\
Olllll\
O\

=
(
lOlO\
l\
l\
Ol\
O\
l
/
(
lOl\
O\
llOlOl\

-
lOlOll\
OlOO
)
)
;
lO\
OOOOO\
OOO\

+=
(
llll\
lllll
-
lOOOOOOOOO
)
*
lllOll\
lllO
;
llOO\
l\
l\
lO\
lOl
=
lO\
O\
O\
llO\
OO\
l
;
}
}
if
(
lOOO\
l\
lOOOl
!=
llO\
OOlOlOO
->
lOllOlllO\
l
)
continue
;
if
(
llOO\
lllO\
l\
OO
!=
-
1
&&
llO\
OOl\
OlOO
->
llOlll\
lOlO\

[
llOOlll\
OlOO
]
.
lO\
lllOlOlll
.
Dot
(
ll\
OOllOlO\
ll\

-
lOl\
llOlO\
lOl
(
llOOlll\
OlO\
O
)
)
<
0.0f
)
{
}
els\
e
if
(
llO\
O\
l\
llOlOl
!=
-
1
&&
ll\
O\
OOl\
OlOO\

->
llOllllOlO
[
llOOlllOlO\
l
]
.
lO\
lll\
O\
lOlll
.
Do\
t\

(
llOOllOlOll
-
lO\
l\
llOlOl\
O\
l
(
llOO\
lllOl\
Ol\

)
)
<
0.0f
)
{
}
else
{
if\

(
llO\
Ol\
llOlOO
!=
-
1
)
{
const
Vec\
3
&
lOllllOOllO
=
lOl\
llOlOlO\
l
(
llOOl\
llOlOO
)
;
int\

lO\
l\
llOl\
lOOO
=
ll\
OOlll\
OlOO\

+
1
<
llOOOlO\
l\
OO
->
lOllOll\
lO\
l\

?
llOOll\
lOl\
OO\

+
1
:
0
;
co\
n\
st
Vec3
&
lO\
lllOllO\
lO
=
lOlll\
Ol\
OlOl
(
lOl\
ll\
OllO\
O\
O
)
;
lOl\
llOllOll
(
lOllllO\
O\
llO
,
lOlll\
OllOlO
,
1
+
lOl\
l\
lOlOO\
O
)
;
}
if\

(
llOOlllOlOl
!=
-
1
)
{
const
Ve\
c3\

&
lOll\
llOOllO\

=
lO\
lllO\
lOlOl
(
ll\
OO\
ll\
l\
O\
lO\
l
)
;
int\

lO\
lllOl\
l\
O\
O\
O
=
llOOll\
l\
OlOl
+
1
<
llOO\
OlOlO\
O
->
lO\
l\
lOll\
l\
Ol
?
llOOlllOlO\
l
+
1
:
0
;
cons\
t
Vec3
&
lOlllOl\
l\
OlO
=
lOll\
lOl\
O\
l\
Ol
(
lOlllOl\
lOOO
)
;
lOlll\
Ol\
lOl\
l
(
lOlll\
l\
OO\
l\
lO
,
lOlllOllOlO
,
1
+
lOlllOlOOO
)
;
}
Vec3
lO\
O\
OOll\
lll
=
ll\
O\
O\
llOlOll
+
ll\
OOlllOOlO
*
ll\
O\
O\
l\
l\
lO\
OOO
.
lOlOlOOl\
OlO\

;
lOll\
l\
lOOOlO\

(
0.0f
,
llOOllOlll\
l
-
lOlllO\
lll\
O
,
llOOOl\
OlOO
,
lOOOOlllll
,
llOOOlOlOO\

->
lOO\
Ol\
OOOO\
O
)
;
ll\
O\
O\
l\
l\
O\
lOlO
.
llOOll\
OOl\
ll
=
true
;
}
}
{
cons\
t
Ve\
c\
3
&
lOOlOlO\
l\
ll
=
lOlllO\
l\
O\
OOO
[
0
]
;
const
Vec3
&
lOO\
lOll\
OOl
=
lOll\
lO\
lO\
O\
OO
[
1
]
;
float
lOlOllOlOO
=
lOll\
lOl\
O\
OO\
l
(
lOOl\
Ol\
Ol\
ll
)
;
float
lOl\
O\
l\
l\
OlOl
=
lOlllO\
l\
O\
O\
O\
l
(
lO\
Ol\
OllOOl
)
;
if
(
!
llOOllOl\
OlO
.
ll\
OOllOOll\
l
&&
!
SignsEqua\
l\

(
lOl\
Ol\
lO\
lOl
,
lOlOllOlOO\

)
)
{
TA_ASSERT
(
Fabs
(
lOlOllOlO\
O
-
lO\
lOllOlOl
)
>
0.0f
)
;
float
lOlll\
lOO\
lO\
O
=
(
lO\
lO\
llO\
lOO\

)
/
(
lOl\
Ol\
l\
OlOO\

-
lOlOllOlOl
)
;
Vec3
lOl\
llOlll\
O\
O\

=
lOOlOl\
O\
lll
+
(
lOO\
lOllO\
Ol\

-
lOO\
lOl\
Olll
)
*
lOlll\
lOO\
lOO
;
fo\
r
(
lOO\
Ol\
lOOO\
l
=
0
;
lOOOllOOOl
<
ll\
O\
OO\
l\
Ol\
OO
->
lO\
l\
lO\
lllOl
;
lO\
OO\
ll\
OOO\
l
++
)
{
con\
s\
t
Vec3
&
lOlll\
OlO\
lOO\

=
lOlllO\
lOlOl
(
lOOOllOOOl
)
;
if\

(
ll\
OOOlOlOO
->
llOllllOlO
[
lOO\
Oll\
OO\
O\
l\

]
.
lO\
lllOlOll\
l
.
Do\
t
(
lO\
ll\
l\
O\
ll\
lOO
-
lOlllOlO\
lO\
O\

)
<
0.0f
)
break\

;
}
if\

(
lOOOllOOOl
==
llOOOlOlOO
->
lO\
llOlllOl
)
{
flo\
at
lO\
lOOO\
lOl\
OO
=
Fa\
bs
(
llO\
O\
l\
lOll\
Ol
.
Do\
t
(
llO\
O\
OlOlO\
O
->
lOO\
OlOOO\
OO
)
)
;
if
(
lOlOO\
Ol\
O\
lOO
>
0.707f
)
{
llOOllOlOlO
.
llOOllOlOO\
l
=
true
;
}
els\
e
{
lOll\
llO\
OOlO
(
0.0f
,
ll\
OOlll\
OOOO\

.
lO\
l\
OlOO\
lOlO
,
llOOOlOlOO
,
lOlllOl\
llOO
,
llO\
OO\
l\
O\
lOO
->
lOOOl\
OOO\
OO
)
;
}
ll\
O\
O\
llO\
lOlO
.
ll\
OOllOlO\
O\
O\

=
true
;
}
}
for\

(
lOOOll\
OO\
O\
l
=
0
;
lOOOl\
lO\
OOl\

<
ll\
OO\
O\
lOlOO
->
lOll\
OlllOl\

;
lOO\
OllOOO\
l
++
)
{
const\

Ve\
c3
&
llOOll\
lOll\
O
=
lOl\
ll\
O\
lO\
lOl\

(
lO\
OO\
llOOOl
)
;
fl\
oat
ll\
OOlllO\
l\
ll
=
llO\
Oll\
OllOl
.
Do\
t\

(
llOOl\
llOllO
-
lOO\
lOlO\
lll
)
;
fl\
oat\

llOOlll\
lOOO
=
llOOllOll\
Ol\

.
Dot\

(
lOO\
l\
Ol\
lO\
Ol\

-
llOOlllOllO
)
;
if
(
llOOl\
llOlll
<
0.0f
||
llOOllllOOO\

<
0.0f
)
con\
ti\
nu\
e\

;
Vec\
3\

lO\
ll\
llOOll
;
if\

(
Geo\
met\
ry
::
FindC\
l\
ose\
stPoi\
n\
tOnL\
i\
n\
e\
UnC\
lam\
ped
(
llO\
OlllOllO
,
lO\
OlOlO\
lll
,
lOOlOllOOl\

,
lO\
llllOOll\

)
)
{
Vec\
3
lOOOl\
OO\
OOO\

=
(
lOl\
l\
llOOll
-
ll\
OOlllOllO
)
;
fl\
oat\

lO\
llllOlOl\

=
lO\
OO\
l\
O\
OO\
OO
.
Get\
Ma\
gn\
itudeSqrd\

(
)
;
const
fl\
oa\
t
lOllO\
l\
Olll
=
0.001f
*
0.001f
;
if
(
lOllll\
OlOl
<
llOOlllOO\
OO
.
lOlOlOO\
lOl\
O
*
llOOlll\
OO\
OO
.
lOl\
OlOOlOlO
&&
lOllllOlO\
l
>
lOllOl\
Ol\
ll
)
{
if
(
llOOllO\
lOlO\

.
llO\
Oll\
OlO\
OO
)
{
lOllllO\
OOOO
(
llO\
OlllOll\
O
)
;
co\
ntinue
;
}
lOl\
lll\
Ol\
Ol
=
Sqr\
t\

(
lO\
llllOl\
Ol
)
;
lOOOlOOOO\
O
/=
lO\
llllO\
lOl
;
llOOllOOllO
|=
1
<<
lOOOl\
lOOOl\

;
fl\
o\
at
lOl\
llOll\
lO
=
llOOlllOOO\
O
.
lOl\
O\
lOOlOlO
-
lOl\
lllOlO\
l
;
boo\
l
llOOl\
lll\
O\
Ol
=
tru\
e
;
if\

(
llOO\
lll\
Olll
<
ll\
OO\
l\
ll\
l\
OOO
)
{
if
(
ll\
OOlllOl\
ll
<
lOlllO\
lllO
)
{
lO\
lll\
Ol\
l\
lO\

=
llOOlllOl\
ll
;
lO\
OO\
lOOOOO
=
llO\
OllO\
l\
l\
O\
l
;
}
}
else\

if
(
ll\
OO\
llllOOO\

<
lO\
lllOlllO
)
{
lOll\
lOlll\
O
=
llOOllllOOO
;
lOOOlOO\
O\
O\
O
=
-
llOOll\
OllO\
l
;
}
else
{
llOOllllO\
Ol\

=
fa\
lse
;
}
int
lOll\
lOllOOO\

=
lOOOllOOOl\

+
1
;
if
(
lOlllOllOOO
>=
llOOO\
lOlOO
->
lO\
llOll\
lOl
)
lOlll\
OllO\
OO
=
0
;
int
lO\
lllOllllO\

=
lOOO\
llO\
OO\
l
-
1
;
if\

(
lOlll\
OllllO
<
0
)
lOlllOllllO
=
ll\
OO\
Ol\
OlO\
O
->
lO\
llOlllO\
l
-
1
;
if
(
lOOO\
lOOOOO
.
Dot
(
llO\
O\
OlOlOO
->
ll\
O\
llllOlO
[
lOll\
lOl\
ll\
lO
]
.
lOl\
l\
lOl\
Olll
)
>
0.0f
)
{
lOllllO\
OO\
OO
(
ll\
O\
Oll\
lO\
llO
)
;
if
(
llO\
Olll\
l\
O\
Ol
)
{
continue\

;
}
else\

{
lO\
ll\
l\
lOO\
OlO
(
0.0f
,
lOlll\
O\
ll\
lO
,
ll\
O\
O\
OlOlO\
O
,
lOlll\
lO\
Oll\

,
ll\
O\
OOlO\
lOO\

->
lOO\
OlOO\
OOO
)
;
contin\
u\
e
;
}
}
if\

(
lOOOl\
OO\
OOO
.
Dot
(
llOOO\
lOlOO
->
ll\
OllllOl\
O\

[
lO\
l\
ll\
OllO\
OO\

]
.
lOl\
llOlOl\
l\
l
)
>
0.0f
)
{
lOllllOOOOO
(
llOOlllOllO
)
;
if
(
llOOllllO\
Ol
)
{
continu\
e
;
}
else
{
lOllllOOOlO
(
0.0f
,
lO\
l\
l\
lOll\
lO
,
llO\
O\
Ol\
OlOO
,
lO\
llllO\
O\
ll
,
llOOO\
l\
O\
lOO
->
lOOO\
l\
OOOOO
)
;
contin\
ue
;
}
}
lO\
l\
lllO\
OO\
Ol
(
0.0f
,
lOlllOlllO\

,
ll\
OOOlOlOO\

,
lOO\
OllOOO\
l
,
true
,
llOO\
lllO\
llO
,
llO\
Oll\
lO\
l\
lO\

,
lOOOlOOOOO\

)
;
}
}
}
for
(
lOOOl\
lOOOl
=
0
;
lOOOll\
OOOl\

<
ll\
O\
OOlOlOO
->
lO\
llO\
l\
llOl\

;
lOOOllOO\
Ol
++
)
{
const
Ve\
c\
3
&
lOll\
llOOllO\

=
lOlllOlOlO\
l
(
lOOOllOOOl
)
;
const
int
lOl\
llOl\
l\
OOO
=
lOOOl\
lO\
OOl
+
1
<
ll\
OO\
OlO\
l\
OO\

->
lOllOl\
llOl\

?
lOOO\
llO\
O\
Ol
+
1
:
0
;
const
Vec\
3
&
lOll\
lOll\
OlO\

=
lOl\
llOlOlOl\

(
lOlllOllOOO
)
;
fl\
oat
lOl\
lll\
O\
Olll
=
0.0f
;
Vec\
3\

lOlll\
lOlOO
;
Vec3\

lO\
llllOO\
ll
;
Vec3
lll\
llO\
lOOl
;
Ve\
c3\

lllllOl\
lll
;
if
(
Geometry
::
Fi\
ndC\
l\
ose\
stP\
oin\
tOn\
LineToL\
ineUn\
Clampe\
d
(
lOOlO\
l\
O\
lll
,
lOOlO\
ll\
OOl
,
lOl\
l\
llO\
OllO
,
lOlll\
Oll\
OlO\

,
lllll\
OlO\
Ol
,
lllllOll\
ll
)
)
{
Vec3
lO\
OOlOOO\
OO
=
lllllO\
lOOl
-
lllll\
O\
llll\

;
float\

lllOOl\
Ol\
ll
=
lOOOlOO\
OOO
.
Ge\
tMag\
ni\
tude\
Sqrd
(
)
;
if
(
lllO\
O\
lO\
lll
<
llOOl\
llOO\
OO
.
lOlO\
lOOlOl\
O
*
llOOlllO\
OO\
O
.
lOlOlOOlOlO
)
{
if
(
llOOl\
lOlOl\
O\

.
llOO\
llO\
lOO\
O\

)
{
lOlllOl\
lOll
(
lO\
l\
lllO\
Oll\
O
,
lO\
lllO\
ll\
OlO
,
0
)
;
}
els\
e
if\

(
ll\
l\
OOlOl\
ll\

<
ll\
OOlll\
O\
OOO\

.
lOlOl\
O\
O\
lO\
lO
*
llOOl\
ll\
OOO\
O
.
lOlOlOOlOl\
O\

*
0.99f
)
{
lO\
ll\
llO\
Oll\

=
llll\
lO\
lll\
l\

;
const
fl\
oat
lOllllOlOl\

=
Sqrt
(
lllOOlOlll
)
;
const\

floa\
t
lOllOl\
Olll
=
0.001f
*
0.001f
;
if
(
lllOOlOll\
l
>
lOllOlOlll\

)
{
lOOOlOO\
OO\
O\

=
lOOOlOOOOO
/
lO\
ll\
llOl\
Ol
;
}
els\
e
{
lO\
OOlOOOOO
=
llOOO\
lO\
lOO\

->
lOOO\
lO\
OO\
OO
;
}
lOllll\
OOl\
ll
=
ll\
OO\
l\
llOOOO
.
lOlO\
lO\
O\
l\
OlO\

-
lO\
l\
l\
ll\
Ol\
Ol\

;
float\

llOOl\
lllOlO\

=
llO\
O\
l\
lOllOl\

.
Dot
(
ll\
lllOllll\

-
lOOlO\
l\
Ol\
ll
)
;
float
ll\
OOllllOll
=
llOO\
llOllOl\

.
Dot
(
lOOlOllO\
Ol
-
lll\
llOllll\

)
;
bool
llOOll\
l\
lOOl
=
true\

;
if\

(
llOO\
l\
ll\
lOlO
<
lOll\
llOOl\
ll
)
{
if
(
ll\
OO\
llllOl\
l
<
llOOl\
ll\
lO\
l\
O
)
{
lO\
OOl\
OOOOO\

=
-
ll\
OO\
ll\
OllOl
;
lOllllOOlll\

=
llOO\
llllO\
ll
;
}
else
{
lOO\
OlO\
O\
O\
OO
=
ll\
OOllO\
llOl
;
lOllll\
OOlll\

=
llO\
OllllOlO
;
}
}
el\
se
if\

(
ll\
OOll\
l\
lOll
<
lOllllO\
Oll\
l
)
{
lOO\
O\
lOOOOO\

=
-
llOOll\
OllOl\

;
lOll\
llOOll\
l\

=
llO\
OllllOll
;
}
else
{
ll\
OOl\
lllOOl
=
fa\
lse
;
}
if\

(
lOOOlOOO\
O\
O
.
Dot
(
llO\
OOlOlOO
->
llOll\
l\
lO\
l\
O
[
lOOOl\
lOO\
O\
l\

]
.
lOll\
lOl\
Ol\
ll
)
>
0.0f
)
{
lOll\
lO\
l\
l\
O\
ll
(
lOlll\
lOOll\
O
,
lOlll\
O\
ll\
OlO
,
0
)
;
if
(
ll\
OOllllO\
Ol
)
{
ll\
O\
OllOl\
O\
lO\

.
llOOll\
OlOOl\

=
tr\
ue
;
continu\
e
;
}
els\
e\

{
lOllllOO\
O\
lO\

(
0.0f
,
lOllll\
OOl\
ll\

,
llOOOlOlOO\

,
lOllllOOl\
l\

,
llOOO\
lOlOO\

->
lOOOl\
OOOO\
O\

)
;
con\
t\
inue
;
}
}
lOlll\
OlllOl
(
0.0f
,
lOl\
lll\
OOlll
,
ll\
OOO\
lOlOO\

,
lOlll\
lO\
OllO
,
lOl\
l\
lOllOl\
O
,
lO\
ll\
llOO\
ll
,
lOOOlO\
OOOO\

,
0
)
;
}
}
}
}
if
(
ll\
O\
OllOlO\
lO
.
ll\
OO\
llOlOO\
l
)
{
floa\
t
lO\
lO\
OO\
lOlOO
=
Fabs
(
ll\
OOl\
lOll\
Ol
.
Dot
(
llOOOlOlOO\

->
lO\
O\
Ol\
O\
OOO\
O
)
)
;
if
(
Fabs
(
lO\
lOO\
OlOlOO
)
>
0.707f
)
{
TA_AS\
SE\
RT
(
Fab\
s
(
lO\
lOllOl\
O\
O
-
lO\
lOllOlOl
)
>
0.0f
)
;
float
lO\
l\
l\
l\
lOO\
lOO
=
(
lO\
lOll\
Ol\
O\
O\

)
/
(
lO\
lOl\
l\
Ol\
OO
-
lOlOllOlOl\

)
;
Ve\
c3\

lOlllOlllOO
=
lOOlOlOl\
ll
+
(
lOOlOllO\
O\
l
-
lOOl\
O\
lO\
lll
)
*
lOl\
ll\
l\
OOlO\
O
;
Ve\
c3
ll\
OOllOllOO
=
llOO\
O\
lOl\
OO
->
lO\
OO\
lOOOOO
.
Cr\
o\
ss
(
ll\
O\
Ol\
lOllO\
l
)
;
float
llOOll\
lllOO\

;
Ve\
c3
llOO\
lllOO\
lO
;
if
(
Fabs\

(
lOlOO\
O\
lOl\
OO\

)
>
0.999f
)
{
llOOlll\
l\
lOO
=
0.0f
;
Ma\
t\
33
lO\
O\
OOOOOll\

;
lOO\
OOOO\
Oll
.
SetT\
oLo\
okD\
ownVector\

(
llO\
OOlOlOO
->
lOOO\
lOOOOO
)
;
llOOl\
lOllOO
=
lO\
OOO\
OOOll
.
v3X\

;
llO\
Ol\
llOOlO
=
lO\
OO\
OOOOl\
l
.
v3\
Y
;
}
else\

{
llOOll\
ll\
lOO
=
ll\
O\
OllOllOO
.
GetMagnitude
(
)
;
llOOl\
lOllO\
O
/=
llO\
Oll\
l\
l\
lOO
;
ll\
OO\
ll\
lO\
OlO
=
llOO\
OlO\
l\
OO\

->
lOOOl\
OOOOO
.
Cross
(
ll\
OOl\
lOllOO\

)
.
GetNorma\
l
(
)
;
if
(
llOOll\
OllOl\

.
Do\
t
(
llO\
OO\
lOlO\
O
->
lOO\
OlOOO\
O\
O\

)
>
0.0f
)
llOOl\
llOOlO
=
-
llO\
O\
l\
llOO\
l\
O
;
}
cons\
t\

float\

llOOlllll\
Ol
=
Cos
(
k_fPi
/
6.0f
)
*
2.0f
;
const
float\

llOO\
ll\
llll\
O
=
(
ll\
OO\
lllllOl\

*
Cos
(
k_fP\
i
/
6.0f
)
-
1.0f
)
;
con\
st
float
llOO\
lllO\
Ol\
l
=
llOOll\
lllO\
l
*
Si\
n
(
k_\
fPi\

/
6.0f
)
;
const\

float\

llO\
Ollllll\
l\

=
ll\
OOl\
llOO\
O\
O\

.
lOlOlOOl\
O\
lO\

/
lOlOO\
Ol\
O\
lOO\

;
Vec3
llOlO\
OOOOOO
[
6
]
;
bool
ll\
OlOOOOOOl
[
6
]
;
llOl\
OO\
OOOO\
O\

[
0
]
=
lOl\
llOll\
lO\
O
+
ll\
O\
O\
l\
llOO\
lO
*
llOOllll\
lll
;
llO\
lOOO\
OOOO
[
2
]
=
lOl\
ll\
Olll\
O\
O\

-
llOOl\
l\
lOOlO\

*
llO\
Olll\
lll\
l
*
llOO\
llllllO\

+
llO\
O\
llOllOO
*
llOOl\
llOOll\

*
ll\
OOlllOOOO
.
lOlOlOOlOlO
;
ll\
OlOOO\
OOOO
[
4
]
=
lO\
ll\
lO\
lllOO
-
ll\
OOlllO\
Ol\
O\

*
llOOl\
ll\
lll\
l
*
ll\
OOll\
l\
ll\
l\
O
-
llOOllOllOO
*
llOOlll\
OOl\
l
*
llOOl\
llOO\
O\
O
.
lOlO\
l\
OOlOlO\

;
llOlO\
OOOOOO\

[
1
]
=
llOl\
OOO\
OOOO
[
2
]
;
llOlOOOO\
OO\
O\

[
3
]
=
ll\
Ol\
OOOOOOO\

[
4
]
;
llOlOOOOOO\
O
[
5
]
=
llOlO\
OOOO\
OO
[
0
]
;
int
lOOOlO\
O\
l\
OlO\

;
for\

(
lOOOlOOlOl\
O\

=
0
;
lOOOlOO\
l\
O\
lO\

<
6
;
lOOOlOOlOlO
+=
2
)
{
Ve\
c3\

&
ll\
lll\
llll
=
ll\
OlOOO\
OO\
OO
[
lOO\
OlOOl\
Ol\
O
]
;
Vec\
3\

&
lO\
O\
OOOOO\
OO
=
llOlOOO\
O\
O\
O\
O
[
lOOO\
lOOlO\
lO
+
1
]
;
for
(
lO\
O\
Oll\
OOOl
=
0
;
lO\
O\
Ol\
lOO\
Ol
<
ll\
O\
OO\
lOlOO
->
lO\
l\
lOll\
lO\
l\

;
lO\
OOll\
OOO\
l
++
)
{
co\
ns\
t\

Vec3\

&
lOl\
lllOO\
llO\

=
lOlllO\
lOlO\
l
(
lOOOllO\
OOl
)
;
float
lOlOl\
lO\
lOO\

=
llO\
OO\
lOl\
OO
->
llOll\
ll\
OlO\

[
lOOOllOOOl
]
.
lOlllOlOlll
.
Dot
(
lOllll\
OOllO
-
lllllllll
)
;
float
lOl\
O\
llO\
lOl
=
llOOO\
lOlO\
O
->
llOllll\
Ol\
O
[
lO\
OOllOO\
Ol\

]
.
lOlllOlOlll\

.
Dot
(
lOlll\
lOO\
ll\
O\

-
lO\
OOOOOOOO\

)
;
if
(
lO\
lO\
l\
lOlOO
>
0.0f
)
{
if
(
lO\
l\
OllOlOl\

>
0.0f
)
break
;
floa\
t
lll\
Oll\
lllO
=
(
lO\
lOl\
l\
OlOO
/
(
lOl\
Ol\
lO\
lO\
O
-
lOlOllOlO\
l
)
)
;
lllllllll
+=
(
lO\
OOOOOOO\
O\

-
ll\
ll\
l\
llll
)
*
ll\
l\
Oll\
l\
l\
lO
;
}
el\
se
if
(
lOlOllOlOl
>
0.0f
)
{
float
lll\
Olllll\
O
=
(
lOl\
Ol\
l\
OlOl
/
(
lOlOll\
OlOl\

-
lO\
lOllO\
lOO
)
)
;
lOO\
OOO\
OOOO\

+=
(
ll\
llllll\
l\

-
lOOOO\
O\
OOO\
O
)
*
ll\
lOlllllO
;
}
}
if\

(
lOOOllOOOl
==
llOOOl\
OlOO
->
lO\
l\
l\
O\
ll\
lOl
)
{
llOl\
OOO\
OOOl\

[
lO\
OOlOOlOl\
O
]
=
tr\
u\
e
;
llOlOOOOOOl\

[
lO\
OO\
lOOl\
O\
l\
O
+
1
]
=
true
;
}
el\
se\

{
ll\
Ol\
OOOOOOl\

[
lOOOlOOlOlO\

]
=
false
;
ll\
O\
l\
OO\
OO\
OOl
[
lOOO\
lOOlOlO
+
1
]
=
fal\
s\
e
;
}
}
for
(
lOO\
Ol\
OOl\
Ol\
O\

=
0
;
lOO\
Ol\
O\
OlOlO\

<
6
;
lOOO\
lO\
OlOlO
++
)
{
int
lOlll\
OllOOO
=
lOO\
Ol\
OO\
lOl\
O
+
1
;
if\

(
lOlllOl\
l\
OOO\

>=
6
)
lOlllOll\
OOO
=
0
;
if\

(
!
llOlO\
O\
O\
OOOl
[
lO\
OOlOO\
lOlO
]
)
continu\
e
;
if
(
ll\
OlOOOOOOl
[
lO\
l\
ll\
Ol\
lO\
OO
]
&&
llO\
l\
OOOOOOO
[
lO\
OO\
lOOlOlO\

]
==
llOlOOOO\
OOO
[
lO\
l\
llOl\
lOO\
O
]
)
cont\
inue
;
floa\
t
lOllOOlOO\
ll
;
lO\
llO\
OlOO\
ll
=
lOlOllOlO\
O\

<
0.0f
?
-
lOlOllOl\
OO
:
-
lO\
lOllOlOl
;
lO\
l\
lO\
OlOOll
+=
llOOll\
lllO\
O
*
llO\
OlllOO\
OO
.
lOlOlO\
OlOlO
*
llOOllllllO\

*
llOOl\
llOOlO
.
Dot
(
llOlOOO\
OOOO
[
lOOO\
lOO\
l\
OlO
]
-
lOlllO\
lO\
OOO
[
0
]
)
;
lOll\
l\
lO\
OOlO
(
0.0f
,
lOl\
l\
OOlOOll\

,
ll\
OOOlOl\
OO
,
ll\
O\
lOO\
O\
OOOO
[
lO\
O\
OlOOl\
OlO
]
,
llO\
OO\
lO\
lO\
O\

->
lOO\
OlOOOO\
O
)
;
}
}
}
}
if
(
lOl\
llO\
O\
OO\
l\
l\

->
lOl\
l\
OlllOll
)
{
cons\
t
floa\
t
lOllOl\
Olll
=
0.0001f
;
fo\
r
(
lOll\
lOlO\
OO
=
0
;
lOll\
lOlOOO\

<
2
;
lOlll\
O\
lOOO
++
)
{
const
Vec3
&
lOOlOlOll\
l
=
lOl\
llOlO\
OOO
[
lOlllOlOOO
]
;
const
Ve\
c3\

&
lOOl\
Ol\
lO\
O\
l
=
lOll\
l\
l\
O\
OOll\

[
lOlll\
OlOOO\

]
;
floa\
t
lO\
lO\
l\
lOlO\
O
=
lOll\
l\
OlOOOl\

(
lOOl\
Ol\
Olll
)
;
float
lO\
lOllOlOl
=
lOl\
l\
lO\
l\
OOOl
(
lOO\
l\
OllO\
Ol
)
;
if
(
lOlO\
ll\
O\
lOl
<
0.0f
&&
lO\
lOllOlOO
>
0.0f
)
{
TA_ASS\
E\
RT
(
Fa\
b\
s
(
lOlOllOlOO
-
lO\
l\
OllO\
lO\
l
)
>
0.0f
)
;
flo\
at\

lOlll\
l\
O\
OlO\
O
=
(
lO\
l\
OllO\
lOO
)
/
(
lO\
lOllOl\
O\
O
-
lOlOl\
lO\
lOl
)
;
Ve\
c3
lOl\
l\
l\
Ol\
l\
l\
OO
=
lOOl\
Ol\
Olll
+
(
lO\
OlO\
llOOl
-
lOOl\
OlOlll\

)
*
lO\
lll\
lOOl\
OO\

;
for
(
lOOOl\
lO\
O\
Ol
=
0
;
lO\
OOl\
lOO\
O\
l\

<
llOO\
O\
lOl\
O\
O\

->
lOllOlllOl\

;
lOO\
O\
llOOOl\

++
)
{
co\
ns\
t
Ve\
c3\

&
lOl\
l\
l\
OlO\
l\
OO\

=
lO\
lllOlO\
l\
O\
l
(
lO\
OO\
l\
lOO\
Ol
)
;
if
(
llOOOlO\
lO\
O
->
llOll\
llOlO
[
lOO\
OllOOO\
l\

]
.
lOl\
llOl\
Ol\
ll
.
Dot
(
lOlll\
Oll\
l\
O\
O
-
lOlll\
OlOlO\
O
)
<
0.0f
)
bre\
ak
;
}
if
(
lOOOllOO\
O\
l\

==
ll\
OO\
OlO\
lOO
->
lOllOlllO\
l
)
{
lOllllOOOlO
(
lO\
llllOOlO\
O\

,
0.0f
,
llO\
OO\
lO\
l\
OO
,
lO\
ll\
lOl\
llO\
O
,
llOOOlOlO\
O\

->
lOO\
OlOOOO\
O
)
;
}
}
co\
nst
Vec3\

llOlO\
OOOOl\
O
=
lOl\
llOlOOOO
[
(
lO\
lllOl\
O\
O\
O
+
1
)
&
1
]
-
lO\
O\
l\
Ol\
Olll
;
Vec3
llOlOOO\
OO\
l\
l
=
ll\
O\
OOlOlOO\

->
lOO\
O\
lOOOO\
O
.
Cros\
s
(
llOlOOOO\
OlO
)
.
Cro\
ss\

(
llOlO\
OOOOlO\

)
;
fl\
oat
llOlOOOOlOO
=
llO\
lO\
OOOOll
.
GetMag\
nit\
ude
(
)
;
Vec\
3\

ll\
OlOOOOlOl
=
lO\
OlOlOlll
;
if
(
ll\
Ol\
OOOOlOO
>
lOllOlOlll
*
lO\
llOlO\
ll\
l
)
{
llOl\
OOOOO\
l\
l
/=
ll\
OlOOOOlOO
;
ll\
OlOOOOl\
Ol
+=
llOlO\
OO\
OOl\
l
*
llOO\
lllO\
OOO
.
lOlOlO\
O\
lOlO
;
}
con\
s\
t
Vec3\

&
llOlOOO\
Oll\
O
=
lOl\
ll\
l\
OO\
Oll
[
(
lOlllO\
lOO\
O
+
1
)
&
1
]
-
lOOl\
OllOO\
l\

;
Vec\
3\

llOlOOOOl\
ll
=
ll\
O\
OOlOlOO
->
lOOOlOOOOO
.
Cross
(
llO\
lO\
OOOl\
lO
)
.
Cr\
os\
s
(
llOlOOOOl\
lO\

)
;
flo\
a\
t\

llOl\
O\
OOl\
OOO
=
llOl\
OOO\
Oll\
l
.
GetMagnitude
(
)
;
Vec3\

llO\
l\
OOO\
l\
O\
Ol
=
lO\
Ol\
Ol\
l\
O\
Ol
;
if\

(
llO\
l\
OOOlOOO
>
lOl\
lOlOlll
*
lO\
llOlO\
lll\

)
{
llOlOO\
OOlll
/=
ll\
O\
lOOOl\
OO\
O\

;
llOlO\
OOlOOl
+=
llOl\
OO\
OO\
ll\
l
*
ll\
O\
O\
lllO\
OO\
O
.
lO\
l\
OlO\
OlOlO
;
}
{
lO\
lOl\
lO\
lOO
=
lO\
lllOl\
OOOl
(
ll\
OlOOOOlOl
)
;
lOl\
OllOlOl
=
lOl\
llOlOOOl
(
llOlOOOlOOl
)
;
if
(
lOlOllO\
lO\
l
<
0.0f
&&
lOl\
OllOlOO
>
0.0f
)
{
TA_\
ASS\
E\
RT
(
Fab\
s
(
lOl\
OllO\
lOO
-
lO\
l\
OllO\
lO\
l
)
>
0.0f
)
;
float\

lOl\
lllOOlO\
O\

=
(
lOl\
O\
ll\
OlO\
O
)
/
(
lOlOll\
OlOO
-
lO\
l\
OllO\
lO\
l
)
;
Vec3
lOlllOlll\
OO\

=
llOlOO\
OOl\
Ol
+
(
llOlOO\
OlOO\
l
-
llOl\
OOOOlOl
)
*
lOll\
llOOlOO
;
fo\
r
(
lOO\
Ol\
lO\
OOl
=
0
;
lOOOll\
OOOl
<
llOOOl\
OlOO\

->
lOll\
O\
l\
llOl
;
lOOOllOOOl
++
)
{
const
Vec\
3
&
lOlllOlOlO\
O
=
lOlll\
O\
lOlOl
(
lOO\
Ol\
lOOOl
)
;
if\

(
ll\
O\
OOl\
OlOO
->
ll\
Ollll\
OlO
[
lOOOllOOO\
l
]
.
lOlll\
OlOlll\

.
Do\
t
(
lO\
lllOlllOO
-
lO\
ll\
lO\
lOlOO
)
<
0.0f
)
break\

;
}
if\

(
lOO\
Oll\
OOOl\

==
llO\
OO\
l\
OlOO
->
lOl\
lOlllOl\

)
{
lOl\
lllOO\
OlO
(
lOll\
llOOlO\
O
,
0.0f
,
llOO\
OlOl\
OO
,
lO\
ll\
lOl\
llOO
,
llOOO\
l\
OlOO\

->
lOOOlOOO\
O\
O
)
;
}
}
}
}
stat\
ic\

Vec\
3
ll\
O\
lOOO\
lOl\
O
[
lOll\
l\
OOl\
O\
ll
]
;
for
(
lO\
OOl\
lOOOl
=
0
;
lOOOllOO\
Ol\

<
llOO\
OlOl\
OO\

->
lOllOlllOl
;
lOOOl\
lOOOl
++
)
llOlOOOlOlO
[
lOOOllO\
O\
Ol
]
=
(
lO\
l\
ll\
Ol\
Ol\
Ol
(
lOO\
Ol\
lOO\
Ol
)
/
lOl\
l\
lO\
OOOl\
O
)
*
lOlllO\
OOOOl
;
for
(
lOlll\
O\
l\
OOO
=
0
;
lOlll\
O\
lOO\
O\

<
2
;
lOl\
l\
lOlO\
OO
++
)
{
llO\
Ol\
lOllOl
=
-
ll\
O\
Oll\
O\
llOl\

;
con\
s\
t\

Vec\
3\

&
lOO\
OO\
lOOOl
=
lOl\
llOlO\
OOO
[
lOlll\
OlO\
OO
]
;
for
(
lOO\
Ol\
lOO\
Ol\

=
0
;
lOOOllOO\
O\
l
<
llO\
OOlOlOO
->
lO\
llOll\
lO\
l
;
lO\
O\
O\
ll\
OO\
Ol
++
)
{
const
Vec3
ll\
OlO\
OOlO\
ll\

=
lOlllOlOlOl
(
lOOOllOOOl
)
;
co\
nst
Vec\
3\

ll\
OlOOO\
l\
l\
OO
=
llOlOOO\
l\
OlO\

[
lOO\
Oll\
OOOl
]
;
fl\
oat
ll\
Ol\
OOOll\
O\
l\

=
llOOl\
lO\
l\
lOl
.
Do\
t
(
ll\
OlO\
OOlOll
-
lOO\
OOl\
OO\
Ol
)
;
float
llOlO\
OOlll\
O
=
llOOllOl\
lOl\

.
Dot
(
llOlOOOllOO
-
lOOOOl\
OOOl
)
;
if\

(
llO\
lO\
OOlllO
<
0.0f
&&
ll\
Ol\
OOO\
llOl
>
0.0f
)
{
floa\
t\

ll\
OlOOOllll
=
ll\
O\
lOOOllOl
/
(
llOlOO\
O\
l\
lOl
-
llOlOOOlllO
)
;
Vec\
3
lO\
l\
l\
l\
Olll\
OO
=
llOlOOOlOll
+
(
llOl\
OOOllOO
-
llOl\
OO\
Ol\
Oll
)
*
llOlO\
OOl\
lll
;
fl\
oat\

lOlll\
OOlll
=
(
lOl\
ll\
Ol\
l\
l\
OO
-
lOOOOl\
OOOl
)
.
Get\
Mag\
n\
itudeSq\
rd
(
)
;
if\

(
lOl\
llOOlll
<
llOO\
lllO\
O\
O\
O\

.
lO\
l\
O\
lO\
Ol\
O\
l\
O
*
ll\
OO\
lll\
OOOO\

.
lOlOlO\
OlOlO\

)
{
boo\
l
ll\
O\
lO\
OlOOOO
=
true\

;
Vec3\

lO\
O\
O\
lOOOOO
=
-
llOOll\
Oll\
Ol
;
if
(
llOlOO\
lOOOO\

)
{
lO\
l\
lllOOO\
Ol
(
ll\
OlOO\
Ollll
,
0.0f
,
llOOOlOlOO
,
lOOOl\
lO\
OOl
,
tr\
u\
e
,
llO\
lOOO\
l\
O\
ll
,
llOlO\
OOl\
O\
ll
,
lOOO\
lOO\
OOO
)
;
}
}
}
int\

lOlllOl\
l\
OOO
=
lO\
OO\
llOO\
Ol\

+
1
;
if
(
lOlllOllOOO
>=
ll\
OOOl\
OlOO
->
lOllOlllOl\

)
lOlll\
OllOO\
O
=
0
;
cons\
t
Vec3\

ll\
OlOOlO\
OOl\

=
lOlllOl\
OlOl
(
lOl\
ll\
Ol\
lOOO
)
;
const
Vec3
llOlOO\
lOOlO\

=
llO\
l\
OOOlOlO
[
lOlllOl\
lOO\
O
]
;
float
llOlOOlOO\
ll
=
llOO\
llO\
l\
lOl
.
Do\
t\

(
ll\
O\
lOOl\
OOOl\

-
lO\
OO\
O\
lO\
OO\
l\

)
;
float
llOlOOl\
O\
l\
OO
=
llOO\
l\
lO\
llO\
l\

.
Do\
t\

(
llOlOOlOOlO
-
lOOOOl\
OOO\
l\

)
;
float
ll\
Ol\
OOl\
O\
lO\
l
;
flo\
a\
t\

llOlOO\
lO\
llO\

;
Vec\
3
llOlOOlOlll
;
Ve\
c3
ll\
OlO\
OllOOO
;
if
(
llOlOO\
Ol\
ll\
O
<
0.0f
)
{
if
(
llO\
lOOlOlOO
<
0.0f
)
{
if
(
ll\
OlO\
OlO\
Oll
<
0.0f
)
{
if
(
llO\
lOOO\
l\
lOl
<
0.0f
)
cont\
inue
;
llO\
lOOlOlOl
=
0.0f
;
ll\
OlOOlOl\
lO
=
ll\
O\
lOO\
Oll\
Ol\

/
(
ll\
O\
lOOOll\
O\
l\

-
ll\
OlOOOlllO\

)
;
ll\
OlOOllOO\
O
=
llOl\
OO\
Ol\
Oll
+
ll\
O\
lO\
O\
lOl\
l\
O
*
(
llOlOOOllO\
O\

-
llOlO\
OO\
l\
O\
ll
)
;
llOl\
O\
Ol\
Olll
=
ll\
Ol\
OOOl\
Oll
+
llOlO\
OOllO\
l
/
(
llOlO\
O\
Ol\
lO\
l
-
llOl\
OOlO\
Oll
)
*
(
llOlOOlO\
OO\
l
-
llOl\
OOO\
lOll\

)
;
}
els\
e\

{
if\

(
llOlO\
OOl\
l\
O\
l
<
0.0f
)
{
ll\
OlO\
OlOl\
O\
l
=
0.0f
;
llOlOOlOl\
lO
=
llOlO\
O\
lOO\
ll\

/
(
llOlOOlOOll
-
llO\
lOO\
lOl\
OO
)
;
llOlO\
OllOOO
=
llOlOOl\
OOO\
l\

+
llO\
lOOl\
OllO\

*
(
llO\
lO\
OlOO\
lO
-
llOlOOlO\
OOl
)
;
llOlOOlOlll
=
llOlOOlOOOl
+
llOlOOl\
O\
O\
ll\

/
(
ll\
OlOOl\
OOll\

-
llOlOOOllO\
l
)
*
(
ll\
OlOO\
Ol\
Oll
-
llOlOOlOOOl
)
;
}
el\
s\
e
{
llOlO\
O\
lO\
lO\
l
=
llO\
l\
OO\
Ol\
lOl
/
(
llO\
l\
O\
OOllOl
-
llOl\
OO\
OlllO
)
;
llOlOOlOl\
ll
=
llOlOO\
OlOll\

+
llOlOOlO\
l\
Ol
*
(
llO\
lOOOllOO
-
llOl\
OOOlOll
)
;
llOlOOl\
OllO
=
ll\
Ol\
O\
OlOOl\
l
/
(
llOlOOlOOll
-
ll\
OlOOl\
OlOO
)
;
llO\
lOO\
l\
lOOO
=
llOl\
O\
OlO\
OOl
+
llO\
lOOlOl\
lO\

*
(
llOlOOl\
OO\
l\
O
-
llOl\
OOlOOOl
)
;
}
}
}
el\
se
{
if
(
llOl\
OOOllOl
<
0.0f
)
{
if
(
llOlOOlOOll\

<
0.0f
)
conti\
nue\

;
ll\
O\
lOOlOl\
Ol
=
0.0f
;
llOl\
OO\
lOll\
O
=
1.0f
;
llOlOOl\
Olll
=
llOl\
OOO\
lOl\
l
+
llO\
l\
O\
OOllOl\

/
(
ll\
Ol\
OO\
Ol\
lOl
-
llOlO\
OlOOll
)
*
(
llOlOOlOO\
Ol\

-
ll\
O\
lO\
OO\
l\
Oll
)
;
llO\
lOO\
ll\
OOO
=
ll\
OlO\
O\
OllOO
+
llOlO\
OOlll\
O
/
(
llOlOOO\
lllO
-
llOlO\
OlOlOO
)
*
(
llOl\
OO\
l\
OOlO
-
llO\
lOOOllO\
O\

)
;
}
else
{
llO\
lOOl\
OlOl
=
ll\
O\
lOOOllOl
/
(
llOlOOOl\
lO\
l
-
llOlOOO\
ll\
lO\

)
;
llOlOOl\
Olll
=
llOlO\
O\
O\
lOll
+
llOlO\
O\
lOlOl
*
(
llO\
lOO\
Ol\
lOO
-
llOlOO\
O\
lO\
ll
)
;
ll\
O\
lOOlOllO
=
1.0f
;
llO\
lOOllO\
OO
=
llOlOO\
Oll\
OO\

+
ll\
OlOOOl\
l\
lO\

/
(
ll\
OlO\
OOll\
lO
-
llOl\
O\
OlOlOO
)
*
(
ll\
OlOO\
lO\
OlO
-
ll\
Ol\
OOOllO\
O
)
;
}
}
}
els\
e
if
(
llOlO\
OlO\
lOO
<
0.0f
)
{
if
(
llOl\
OO\
lO\
Oll\

<
0.0f
)
{
if
(
llOlOO\
OllOl
<
0.0f
)
continue
;
llOlOO\
lOlO\
l
=
0.0f
;
ll\
O\
lOO\
lO\
ll\
O
=
1.0f
;
llO\
l\
OOl\
Oll\
l
=
ll\
OlOOlOOO\
l
+
ll\
O\
l\
OOlO\
Oll
/
(
llOlOOlOOll
-
llO\
l\
OOO\
llOl
)
*
(
llOl\
OO\
O\
lOl\
l\

-
llO\
lO\
Ol\
O\
OOl
)
;
llO\
lOOllOO\
O
=
llOlOO\
lOO\
lO
+
llOlOOlOlOO
/
(
ll\
OlOO\
lO\
lOO\

-
llOlOOOlllO
)
*
(
llOl\
OO\
Ol\
l\
OO\

-
llOlOOlOOlO\

)
;
}
else\

{
llOl\
O\
O\
l\
Ol\
Ol
=
llOl\
OOlOOll
/
(
llOlOO\
lOOll
-
llO\
lOO\
lO\
lO\
O
)
;
llOlO\
Ol\
Olll
=
llOl\
O\
Ol\
O\
OOl\

+
llO\
l\
O\
O\
l\
OlO\
l\

*
(
ll\
OlOOlOOlO
-
llOlOO\
lO\
OOl
)
;
llOl\
OOlOllO\

=
1.0f
;
llOl\
O\
OllOOO
=
llOl\
OOlO\
OlO\

+
llO\
lOOlOlOO\

/
(
llOlOO\
l\
O\
lOO\

-
llOlOOO\
lllO
)
*
(
ll\
Ol\
OOOll\
OO\

-
ll\
O\
lOOlOOlO
)
;
}
}
else\

{
cont\
i\
nue\

;
}
Vec\
3
llOlOO\
llOO\
l
=
llOlOOllOOO
-
llOlOO\
lO\
l\
ll
;
float\

ll\
OlOOllO\
lO
=
ll\
O\
lOO\
llOO\
l
.
GetM\
a\
gnitu\
deSqrd\

(
)
;
if
(
llOlO\
O\
llOl\
O
>
lOl\
lO\
lOlll
)
{
float
lOlO\
O\
Ol\
OlOO
=
(
lOOOOlOOO\
l\

-
llO\
l\
O\
OlOll\
l
)
.
Dot
(
llOlOOllOOl
)
;
Vec\
3
llO\
lOOllO\
l\
l
=
llOlO\
O\
lOlll
+
llOlOOllOO\
l
*
(
lOlOOOlOlOO
/
llO\
lOOllOlO\

)
;
flo\
a\
t
lOlllO\
Olll
=
(
llO\
l\
OOllOll
-
lO\
OOOl\
OOOl
)
.
GetMagnitude\
Sqrd
(
)
;
if\

(
lOlllOOlll\

<
llOOlllOOOO
.
lOlOlOOlOl\
O
*
llO\
OlllOOOO\

.
lO\
lOlOOlO\
lO
)
{
fl\
oat
ll\
Ol\
OO\
lll\
O\
O
=
Sqrt
(
llOOlll\
OOOO
.
lO\
lOlO\
OlOlO\

*
llOO\
lll\
OO\
OO
.
lOlOlOOl\
OlO
-
lO\
l\
llOOll\
l
)
;
floa\
t
lO\
l\
lllOlOl
=
Sq\
rt
(
ll\
OlOO\
llO\
lO
)
;
lOlOOOlOlOO
/=
lOllllOlOl
;
ll\
O\
lOOll\
OO\
l\

/=
lOllll\
O\
l\
O\
l
;
float\

lOlOllllOlO
=
lOlO\
O\
OlOl\
OO
-
ll\
Ol\
OO\
lll\
OO
;
for
(
in\
t
lOO\
lOlOOOl
=
0
;
lOOl\
O\
lOO\
Ol
<
2
;
lOOl\
OlO\
OOl
++
,
lO\
lOl\
lll\
O\
l\
O
=
lOlOOOlO\
lOO
+
llO\
lOOlllO\
O\

)
{
if
(
lOlOlll\
l\
O\
l\
O
>
0.0f
&&
lOlOlll\
lOlO
<
lO\
ll\
l\
lOlOl
)
{
Vec3
lO\
ll\
lO\
lllOO
=
llO\
lOOlOl\
l\
l\

+
llOlOO\
llO\
Ol
*
lO\
lOllllOlO\

;
floa\
t
lllO\
l\
ll\
llO\

=
llO\
lOOlOl\
Ol
+
(
lOlOllllOlO
/
lOllllOlO\
l
)
*
(
llO\
l\
OOlOll\
O
-
ll\
Ol\
O\
OlOlO\
l
)
;
Vec3
lOlllllOO\
O
=
(
llOlOOlOO\
O\
l\

-
llO\
lOOO\
l\
Oll\

)
.
Cr\
oss\

(
llOlOOlO\
OlO
-
llOlOOOl\
lOO\

)
;
floa\
t
llO\
lOOlll\
O\
l
=
lOlll\
llO\
OO
.
GetMagn\
itude
(
)
;
if
(
llOlO\
O\
l\
llOl
>
lOllOlOlll
)
{
lO\
lll\
ll\
OO\
O
/=
ll\
O\
lOOlll\
Ol
;
fl\
oa\
t
lll\
lO\
l\
O\
O\
ll\

;
Vec3
lOl\
lllO\
O\
l\
l\

;
Vec\
3\

lOl\
l\
llOlOO
;
flo\
at
llOl\
OOllll\
O\

=
(
llOlOOlOOOl\

-
llOlO\
O\
Ol\
Oll\

)
.
GetMagni\
t\
ude
(
)
;
if\

(
Geometr\
y\

::
Te\
stEdge\
Move\
men\
t\
Agains\
tEdge
(
llOlOOO\
lOll\

,
ll\
OlOO\
lO\
OOl
,
llOl\
O\
OOllOO\

,
llO\
lOO\
l\
OOl\
O\

,
lOlll\
O\
lllOO
+
lOl\
lll\
lOO\
O
*
llOl\
OOllll\
O
,
lOlllOll\
lO\
O
-
lOlllllO\
OO\

*
llOlOO\
lll\
lO\

,
llllOlOO\
ll
,
lOllll\
OOll
,
lOlll\
lOlOO
)
)
{
lllOlll\
llO
=
llllOlOO\
l\
l\

;
}
}
Vec3
lOO\
OlO\
OOOO\

;
if
(
0
)
{
lOOOlOOOOO
=
-
(
ll\
OOl\
lOl\
lO\
l
)
.
Cross
(
llOl\
OOl\
OO\
Ol\

-
llOl\
O\
OOl\
Oll
)
.
Cro\
ss\

(
llOlOOlO\
OOl
-
llOlOOOlOll
)
;
if
(
llOOl\
lO\
ll\
Ol
.
Dot
(
llOO\
OlOl\
OO\

->
lOO\
O\
l\
O\
OO\
OO
)
<
0.0f
)
lO\
OOlOOOOO
=
-
lO\
OOlOOOOO
;
}
else
{
TA_AS\
SERT\

(
(
lOOOOl\
OO\
Ol\

-
lO\
ll\
lOll\
lOO\

)
.
GetMa\
gnitud\
e
(
)
>
0.0f
)
;
lOOOlOOOOO\

=
(
lOOOOlOOOl
-
lOlll\
Oll\
lOO\

)
.
GetNor\
mal
(
)
.
Cross
(
llOOll\
O\
llOl
)
.
Cross
(
llOlO\
Ol\
OOOl
-
llO\
l\
OOO\
lOll
)
;
if
(
lO\
O\
O\
lOOO\
OO
.
Do\
t\

(
llOOO\
lOlOO
->
lOOO\
l\
OOOO\
O
)
<
0.0f
)
lOO\
OlOOO\
OO
=
-
lOOO\
l\
OOOO\
O
;
}
flo\
at\

ll\
OlOOlllll
=
lOOOl\
OO\
O\
OO
.
Ge\
tMagnit\
ude
(
)
;
if
(
ll\
OlOOlllll\

>
lOllO\
l\
Ol\
ll
*
lO\
llOl\
Olll\

*
lO\
l\
l\
O\
l\
O\
l\
l\
l
)
{
lOOOlOOO\
OO
/=
llO\
lOOllll\
l
;
}
else
{
lO\
OOlO\
OO\
OO
=
llOOOlO\
lOO
->
lOOO\
lOOOOO
;
}
if
(
lOOO\
lOOOO\
O
.
Do\
t
(
llO\
O\
O\
lOlOO
->
ll\
Oll\
ll\
OlO
[
lOOOl\
lO\
OO\
l
]
.
lOl\
llO\
lOll\
l\

)
>
0.0f
)
{
lOll\
l\
O\
llOll
(
llOlOOOlOll\

,
llO\
lOOl\
OO\
Ol
,
1
+
lOl\
ll\
OlOOO
)
;
lOllllOOOlO
(
lllOlllllO
,
0.0f
,
llO\
OOlOlO\
O
,
lO\
lll\
O\
lll\
OO
,
ll\
OOOlOlOO
->
lOOOlOOOOO
)
;
}
els\
e\

{
lOll\
lO\
ll\
lO\
l
(
lllOlll\
llO\

,
0.0f
,
llOOOlOlOO
,
llOl\
O\
OOlOl\
l
,
llOlO\
OlOOOl
,
lO\
l\
llOl\
ll\
OO\

,
lOOOlOOOOO
,
1
+
lOl\
ll\
OlO\
O\
O
)
;
}
}
}
}
}
}
}
{
for
(
lOO\
Ol\
lOOOl
=
0
;
lO\
OOllO\
O\
O\
l
<
llOO\
OlOlOO
->
lO\
ll\
OlllO\
l\

;
lO\
OOllOOOl\

++
)
{
const
Vec3
&
lOl\
ll\
lOOll\
O
=
lOlllOl\
OlOl
(
lOO\
Ol\
lOOOl
)
;
cons\
t
int
lO\
lll\
OllOO\
O
=
lOO\
Oll\
OOO\
l\

+
1
<
llOO\
Ol\
O\
lOO
->
lOl\
lOlll\
Ol
?
lOOOllOOOl
+
1
:
0
;
const
Vec3\

&
lOll\
lOl\
lOlO
=
lOl\
llOlOl\
Ol
(
lOlllOl\
l\
OO\
O\

)
;
floa\
t
lll\
l\
OlOO\
ll
=
0.0f
;
Ve\
c3
lO\
ll\
llOlOO
;
Vec3\

lOllllOOll\

;
Vec3
ll\
l\
l\
l\
Ol\
OOl\

;
Vec3
lll\
ll\
Oll\
l\
l
;
if
(
Geometry
::
TestLi\
neM\
o\
vementAg\
ainstC\
apsule\

(
lO\
ll\
lOlOO\
O\
O
[
0
]
,
lOlllOlOOO\
O
[
1
]
,
lOlll\
lO\
OOl\
l
[
0
]
,
lOlll\
l\
OOO\
l\
l
[
1
]
,
lOll\
ll\
O\
Ol\
lO
,
lOlllOl\
lOlO
,
llOOl\
llOO\
OO
.
lO\
l\
Ol\
O\
O\
lOl\
O
,
llllOlOO\
ll\

,
lOl\
lll\
OOll
,
lOll\
l\
lOl\
O\
O\

)
)
{
if
(
lO\
llllOlOOl
&&
lOllllO\
lOO
.
Dot
(
llO\
O\
Ol\
O\
lOO
->
lOOOlOO\
OOO
)
<
0.0f
)
lOl\
ll\
lOl\
OO
=
-
lOl\
lllOlOO
;
if\

(
lO\
ll\
l\
l\
OlOO
.
Do\
t
(
llO\
OOlOlO\
O
->
llOllllOlO
[
lO\
OOl\
lOOO\
l\

]
.
lOl\
llOlOll\
l\

)
<
0.0f
)
{
lOlllOlllOl\

(
llllOlO\
O\
ll
,
0.0f
,
ll\
OOO\
lOl\
OO
,
lOl\
lllO\
O\
l\
lO
,
lOlllO\
ll\
OlO\

,
lOllllOOll
,
lOllllOl\
OO\

,
0
)
;
}
el\
se
{
lOlll\
OllOll\

(
lO\
ll\
l\
lOOl\
lO
,
lOll\
lO\
l\
lOlO
,
0
)
;
if
(
lOl\
lllOlO\
O\

.
Dot
(
llOO\
OlOlO\
O
->
lOOOlO\
OOOO
)
>
0.95f
)
{
lOll\
llOlOO
=
llOOOlOlOO
->
lOO\
OlOOO\
O\
O
;
lOl\
lll\
OOOl\
O
(
llllO\
lOOl\
l
,
0.0f
,
ll\
OO\
OlOlOO
,
lOl\
l\
llO\
O\
ll\

,
lOl\
lllOlOO
)
;
}
}
}
}
for
(
lOOOl\
l\
OOOl
=
0
;
lOO\
O\
llOO\
Ol
<
llOOOlO\
l\
O\
O
->
lOl\
lOl\
llOl\

;
lO\
O\
O\
llO\
O\
Ol
++
)
{
co\
n\
s\
t
Vec3
&
lOl\
lllOO\
llO
=
lOl\
ll\
O\
lOl\
Ol\

(
lO\
O\
O\
ll\
OOOl
)
;
con\
st
Vec3
llOlOlOOOOO
=
llOlO\
OO\
lOlO
[
lOOOll\
O\
OOl
]
;
floa\
t
lll\
lOlOO\
l\
l
=
0.0f
;
float\

lO\
llll\
OO\
ll\
l
=
0.0f
;
Vec3
lOl\
l\
llOlOO
;
Vec3
lOl\
ll\
lO\
Ol\
l
;
if
(
Geo\
m\
etr\
y\

::
Test\
Sph\
ereMo\
v\
emen\
tAgains\
t\
Line
(
lOllll\
OOllO
,
ll\
O\
lOlO\
O\
OOO
,
lO\
lllOl\
O\
O\
OO\

[
0
]
,
lOl\
llO\
l\
OOOO
[
1
]
,
llO\
Oll\
l\
OOOO\

.
lOl\
O\
l\
O\
OlOlO
,
llll\
OlO\
Oll
,
lOl\
lllOOll
,
lOll\
llOl\
OO
)
)
{
TA_ASSER\
T
(
lll\
lOlOO\
ll
>
0.0f
)
;
lOlll\
l\
OlOO\

=
-
lOl\
lllOlOO
;
lO\
llll\
OOll\

-=
lOllllOl\
O\
O
*
llO\
O\
lll\
OO\
OO
.
lOl\
OlOOlOlO
;
lOlll\
l\
O\
OOOl
(
llllO\
lOOll
,
lOllllOO\
l\
ll
,
ll\
O\
OOl\
OlOO
,
lOOOllOOOl
,
true\

,
lO\
ll\
llOOl\
lO\

,
lOlll\
lOO\
ll\

,
lOllllOl\
OO
)
;
}
}
}
}
}
