//---------------------------------------------------------------------------------
// File Name: Debug.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_DEBUG_H
#define TA_DEBUG_H

#ifndef TA_COMMON_H
#include "Common.h"
#endif 



namespace TA
{

#define lllOOOlOOO(lllOOOllll) TA::Debug::Output(lllOOOllll);

#ifdef _DEBUG
	#ifdef TA_IN_PLACE_ASSERT
		#if defined (TA_GCC_X86_INLINE_ASM)
			#define TA_ASSERT(x)			\
				do							\
				{							\
					if (!(x))				\
					{						\
						asm("int $3")		\
					}						\
				} while (0)
		#elif defined(TA_MSVC_X86_INLINE_ASM)
			#define TA_ASSERT(x)			\
				do							\
				{							\
					if (!(x))				\
					{						\
						__asm { int 3 }		\
					}						\
				} while (0)
		#endif
		#define lOOOOOOllO(x, lllOOOOllO) TA_ASSERT(x)
	#else
		#define TA_ASSERT(x) do { if (!(x)) TA::Debug::lllOOOlOlO(__FILE__, __LINE__, #x, 0); } while (0)
		#define lOOOOOOllO(x, lllOOOOllO) do { if (!(x)) TA::Debug::lllOOOlOlO(__FILE__, __LINE__, #x, lllOOOOllO); } while (0)
		namespace Debug
		{
			extern void TAC_CALL lllOOOlOlO(const char* lllOOOOOll, int lllOOOOlOO, const char* lllOOOOlOl, const char* lllOOOOllO);
		}
	#endif
	#define TA_VERIFY(x) TA_ASSERT(x)
	#define lllOOlOOOO TA_ASSERT(0)
	#define lllOOlOOOl(x) TA_ASSERT(x)
	#define lOlOOOllll(x, lllOOOOllO) lOOOOOOllO(x, lllOOOOllO)
	#define lOlOOlOOOl(lllOOOOllO) lOOOOOOllO(0, lllOOOOllO)
	#ifdef TA_WARNING_AS_ASSERT
		#define lOOOlllOlO(x, lllOOOOllO) lOOOOOOllO(x, lllOOOOllO)
	#else
		#define lOOOlllOlO(x, lllOOOOllO) do { if (!(x)) TA::Debug::lllOOOOOlO(__FILE__, __LINE__, #x, lllOOOOllO); } while (0)
		namespace Debug
		{
			extern void TAC_CALL lllOOOOOlO(const char* lllOOOOOll, int lllOOOOlOO, const char* lllOOOOlOl, const char* lllOOOOllO);
		}
	#endif  
#else 
	
	#define TA_ASSERT(x)
	#define TA_VERIFY(x) x
	
	#define lOOOOOOllO(x, lllOOOOllO)
	#ifdef TA_MSVC
		#define lllOOlOOOO __assume(0) 
		#define lllOOlOOOl(x) __assume(x) 
		#define lOlOOOllll(x, lllOOOOllO) __assume(x)
	#else
		#define lllOOlOOOO
		#define lllOOlOOOl(x)
		#define lOlOOOllll(x, lllOOOOllO)
	#endif
	#define lOlOOlOOOl(lllOOOOllO) lOOOOOOllO(0, lllOOOOllO)
	#define lOOOlllOlO(x, lllOOOOllO) lOOOOOOllO(x, lllOOOOllO)
#endif 

#ifdef _DEBUG

namespace Debug
{	
	void TAC_CALL OpenOutputFile(const char* szFileName);
	void TAC_CALL CloseOutputFile();
	void TAC_CALL Output(const char* szText);
	void TAC_CALL SetDebugAssertsEnable(bool bEnabled);
	void TAC_CALL SetExitWitFailureOnAssert(bool bEnabled);	

}
#endif 

}

#endif 

