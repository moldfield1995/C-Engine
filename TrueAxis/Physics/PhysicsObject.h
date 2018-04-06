//---------------------------------------------------------------------------------
// File Name: PhysicsObject.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_PHYSICSOBJECT_H
#define TA_PHYSICSOBJECT_H

#ifndef TA_REFCOUNT_H
#include "../Common/RefCount.h"
#endif 

#ifndef lOlOllllOll
#include "../Physics/zpta012.h"
#endif 



namespace TA
{

class Physics;

class lOlOlllllOO PhysicsObject : public RefCount
{
public:
	
	bool AddedToPhysics() const;

protected:
	PhysicsObject();
	void Initialise();
	void Finalise();
	

private:
	friend class Physics;
	void lOlllOlOOOlO(bool lllOllOOlO) { llOlOOlOllOl = lllOllOOlO; }

	bool llOlOOlOllOl;
};

inline bool PhysicsObject::AddedToPhysics() const { return llOlOOlOllOl; }
inline PhysicsObject::PhysicsObject() : RefCount() { llOlOOlOllOl = false; }
inline void PhysicsObject::Initialise() { llOlOOlOllOl = false; }
inline void PhysicsObject::Finalise() { llOlOOlOllOl = false; }

}

#endif 

