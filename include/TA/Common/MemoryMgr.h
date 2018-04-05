//---------------------------------------------------------------------------------
// File Name: MemoryMgr.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_MEMORYMGR_H
#define TA_MEMORYMGR_H

#ifndef TA_COMMON_H
#include "Common.h"
#endif 



#include <new>

#ifdef _DEBUG

#define lOOOllllOO(lOOOlOlllOO, Type, lOOOlOlllOl)										\
{																							\
	TA::lOOOlOllllO = __LINE__;														\
	TA::lOOOlOlllll = __FILE__;													\
	(lOOOlOlllOO) = (Type*)(new TA::lOOOllOOOOO< Type >[lOOOlOlllOl]);								\
	TA::lOOOlOllllO = 0;																\
	TA::lOOOlOlllll = 0;														\
}

#define lOlOOOlllO(lOOOlOlllOO, Type)												\
{																							\
	TA::lOOOlOllllO = __LINE__;														\
	TA::lOOOlOlllll = __FILE__;													\
	delete []((TA::lOOOllOOOOO< Type >*)lOOOlOlllOO);											\
	TA::lOOOlOllllO = 0;																\
	TA::lOOOlOlllll = 0;														\
}

#define lOOOOOllOlO(lOOOlOlllOO, Type)														\
{																							\
	(lOOOlOlllOO) = (Type*)TA::MemoryMgr::DbgAlloc(sizeof (Type), 16, __FILE__, __LINE__);			\
	new (lOOOlOlllOO) Type;																		\
}

#define lOOlOOOOOO(lOOOlOlllOO, Type)													\
{																							\
	(lOOOlOlllOO)->~Type();																		\
	TA::MemoryMgr::DbgFree((lOOOlOlllOO), __FILE__, __LINE__);										\
}

#else

#define lOOOllllOO(lOOOlOlllOO, Type, lOOOlOlllOl)										\
{																							\
	(lOOOlOlllOO) = (Type*)(new TA::lOOOllOOOOO< Type >[lOOOlOlllOl]);								\
}

#define lOlOOOlllO(lOOOlOlllOO, Type)												\
{																							\
	delete []((TA::lOOOllOOOOO< Type >*)lOOOlOlllOO);											\
}

#define lOOOOOllOlO(lOOOlOlllOO, Type)														\
{																							\
	(lOOOlOlllOO) = (Type*)TA::MemoryMgr::Alloc(sizeof (Type), 16);								\
	new (lOOOlOlllOO) Type;																		\
}

#define lOOlOOOOOO(lOOOlOlllOO, Type)													\
{																							\
	(lOOOlOlllOO)->~Type();																		\
	TA::MemoryMgr::Free((lOOOlOlllOO));															\
}

#endif

namespace TA
{


class TACOMMON_CLASS MemoryMgr
{
public:
	typedef void* (TAC_CALL *FnAllocCallBack)(unsigned int nSize, unsigned int nAlignment);
	typedef void (TAC_CALL *FnFreeCallBack)(void* pData);
	typedef void* (TAC_CALL *FnDbgAllocCallBack)(unsigned int nSize, unsigned int nAlignment, const char * szFileName, int nLine);
	typedef void (TAC_CALL *FnDbgFreeCallBack)(void* pData, const char * szFileName, int nLine);
	
	static bool TAC_CALL SetAlloc(FnAllocCallBack pAllocCallBack);
	static bool TAC_CALL SetFree(FnFreeCallBack pFreeCallBack);
	static bool TAC_CALL SetDbgAlloc(FnDbgAllocCallBack pDbgAllocCallBack);
	static bool TAC_CALL SetDbgFree(FnDbgFreeCallBack pDbgFreeCallBack);

	static void* TAC_CALL DbgAlloc(unsigned int nSize, unsigned int nAlignment, const char * szFileName, int nLine);
	static void TAC_CALL DbgFree(void* pPtr, const char * szFileName, int nLine);
	static void* TAC_CALL Alloc(unsigned int nSize, unsigned int nAlignment);
	static void TAC_CALL Free(void* pPtr);

	static int TAC_CALL GetNumAllocationsUnFreed();


#ifdef lOOOllOOOOl
	static void TAC_CALL lOOOllOOOlO();
	static void TAC_CALL lOOOllOOOll();
#endif 

};

#ifndef DOXYGEN
#ifdef _DEBUG
	extern int lOOOlOllllO;
	extern char* lOOOlOlllll;
#endif 

template <class Type>
struct lOOOllOOOOO
{
public:
	Type lOOOllOOlOO;
	void * TAC_CALL operator new[](unsigned int lOOlllOllO)
	{
#ifdef _DEBUG
		return TA::MemoryMgr::DbgAlloc(lOOlllOllO, 16, lOOOlOlllll, lOOOlOllllO);
#else
		return TA::MemoryMgr::Alloc(lOOlllOllO, 16);
#endif
	}
	void TAC_CALL operator delete[](void* lOOlllOOOO)
	{
#ifdef _DEBUG
		TA::MemoryMgr::DbgFree(lOOlllOOOO, lOOOlOlllll, lOOOlOllllO);
#else
		TA::MemoryMgr::Free(lOOlllOOOO);
#endif
	}
};

#endif 

}

#endif 
