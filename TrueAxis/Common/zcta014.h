//---------------------------------------------------------------------------------
// File Name: zcta014.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------

#ifndef lOOlOllOOOO
#define lOOlOllOOOO
#ifndef TA_DEBUG_H
#include "Debug.h"
#endif //
#ifndef TA_MEMORYMGR_H
#include "MemoryMgr.h"
#endif //
namespace
TA\

{
#define lOOlllOOOOO(Type)						\
public:																\
	static void TAC_CALL DestroyInstance();						\
	static Type& TAC_CALL GetInstance()							\
	{																\
		lOOOOOOllO(s_p##Type, "Singleton("#Type")::GetInstance. Not initialised");	\
		return *s_p##Type;											\
	}																\
	static Type* TAC_CALL lOOlOlOOllO() {	return s_p##Type; }	\
private:															\
	static Type* s_p##Type;											\
public:
#define lOOllOOOOOl(Type)										\
public:																\
	static void TAC_CALL CreateInstance();							\
	friend class MemoryMgr;											\
	lOOlllOOOOO(Type)
#define	lOOlllOOOOl(Type)					\
Type* Type::s_p##Type;												\
void Type::DestroyInstance()										\
{																	\
	if (!s_p##Type)													\
		return;														\
	lOOlOOOOOO(s_p##Type, Type);							\
	s_p##Type = 0;													\
}
#define	lOOlOlOOOOl(Type)									\
lOOlllOOOOl(Type)							\
void Type::CreateInstance()											\
{																	\
	if (s_p##Type)													\
		return;														\
	lOOOOOllOlO(s_p##Type, Type);								\
	s_p##Type->Initialise();										\
}
}
#endif //
