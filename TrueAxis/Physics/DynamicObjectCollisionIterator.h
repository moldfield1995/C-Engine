//---------------------------------------------------------------------------------
// File Name: DynamicObjectCollisionIterator.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_DYNAMICOBJECTCOLLISIONITERATOR_H
#define TA_DYNAMICOBJECTCOLLISIONITERATOR_H

#ifndef lOlOllOlllll
#include "../Physics/zpta009.h"
#endif 



namespace TA
{

class DynamicObject;

class DynamicObjectCollisionIterator
{
public:
	
	DynamicObjectCollisionIterator();
	~DynamicObjectCollisionIterator();
	DynamicObjectCollisionIterator(const DynamicObjectCollisionIterator& that);
	void Finalise() ;
	void operator ++();
	DynamicObjectCollisionIterator& operator = (const DynamicObjectCollisionIterator& that);
	bool operator == (const DynamicObjectCollisionIterator& that) const ;
	Collision& operator *();
	bool AtEnd();
	

private:

	friend class DynamicObject;

	DynamicObject* lOlOlllOOOOO;
	lOlOOOOOlOlO* lOlOlllOOOOl;
	lOlOOOOOOlll::CollisionIterator lOlOlllOOOlO;
	
	DynamicObjectCollisionIterator(DynamicObject* lOlllOOlOOO, lOlOOOOOlOlO* lOlOlllOOOll)
	{
		lOlOlllOOOOO = lOlllOOlOOO;
		lOlOlllOOOOl = lOlOlllOOOll;
		lOlOlllOOlOO();		
	}

	void lOlOlllOOlOO()
	{
		for (; lOlOlllOOOOl; lOlOlllOOOOl = lOlOlllOOOOl->llOOOlOOOOl)
		{
			if (!lOlOlllOOOOl->lOlOOOOOllOO->lOlOlllOOlOl.lOOOOOlOlOO())
			{
				lOlOlllOOOlO = lOlOlllOOOOl->lOlOOOOOllOO->lOlOlllOOlOl.lOlOOOOlOO();
				break;
			}
		}
	}
};

inline DynamicObjectCollisionIterator::DynamicObjectCollisionIterator() 
{
	lOlOlllOOOOO = 0;
	lOlOlllOOOOl = 0;
}
inline DynamicObjectCollisionIterator::~DynamicObjectCollisionIterator() 
{
}
inline DynamicObjectCollisionIterator::DynamicObjectCollisionIterator(const DynamicObjectCollisionIterator& lOOlOOOOOOO) 
{
	lOlOlllOOOOO = lOOlOOOOOOO.lOlOlllOOOOO;
	lOlOlllOOOOl = lOOlOOOOOOO.lOlOlllOOOOl;
	lOlOlllOOOlO = lOOlOOOOOOO.lOlOlllOOOlO;
}
inline void DynamicObjectCollisionIterator::Finalise() 
{
	lOlOlllOOOOO = 0;
	lOlOlllOOOOl = 0;
	lOlOlllOOOlO.Finalise();
}
inline void DynamicObjectCollisionIterator::operator ++() 
{
	if (lOlOlllOOOOl)
	{
		++lOlOlllOOOlO;
		if (lOlOlllOOOlO.AtEnd())
		{
			lOlOlllOOOOl = lOlOlllOOOOl->llOOOlOOOOl;
			lOlOlllOOlOO();		
		}
	}
}
inline DynamicObjectCollisionIterator& DynamicObjectCollisionIterator::operator = (const DynamicObjectCollisionIterator& lOOlOOOOOOO) 
{
	lOlOlllOOOOO = lOOlOOOOOOO.lOlOlllOOOOO;
	lOlOlllOOOOl = lOOlOOOOOOO.lOlOlllOOOOl;
	lOlOlllOOOlO = lOOlOOOOOOO.lOlOlllOOOlO;
	return *this;
}
inline bool DynamicObjectCollisionIterator::operator == (const DynamicObjectCollisionIterator& lOOlOOOOOOO) const 
{
	return
		(lOlOlllOOOOO == lOOlOOOOOOO.lOlOlllOOOOO &&
		lOlOlllOOOOl == lOOlOOOOOOO.lOlOlllOOOOl &&
		lOlOlllOOOlO == lOOlOOOOOOO.lOlOlllOOOlO);
}
inline Collision& DynamicObjectCollisionIterator::operator *() 
{ 
	return *lOlOlllOOOlO; 
}
inline bool DynamicObjectCollisionIterator::AtEnd() 
{ 
	return lOlOlllOOOOl == 0; 
}

}

#endif 
