//---------------------------------------------------------------------------------
// File Name: StackAlloc.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef lOOlllOOOlO
#define lOOlllOOOlO

#ifndef TA_COMMON_H
#include "Common.h"
#endif 

#include <malloc.h>



#ifdef lOlOlOOllO
#define lOOlllOOOll(Type, lOlOOOOlll, lOOlllOllO) Type lOlOOOOlll[lOOlllOllO]
#else
#define lOOlllOOOll(Type, lOlOOOOlll, lOOlllOllO) Type* lOlOOOOlll = (Type*)_alloca((lOOlllOllO) * sizeof (Type))
#endif

#endif 

