//---------------------------------------------------------------------------------
// File Name: PhysicsRender.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_PHYSICSRENDER_H
#define TA_PHYSICSRENDER_H

#ifndef TA_TYPES_H
#include "../Common/Types.h"
#endif 

#ifndef lOlOllllOll
#include "../Physics/zpta012.h"
#endif 



namespace TA
{

struct Vec3;
struct MFrame;

class lOlOlllllOO PhysicsRender
{
public:
	

	typedef void (TAC_CALL *RenderLineCallBack)(const Vec3& v3PosA, const Vec3& v3PosB, u32 nColour);
	typedef void (TAC_CALL *RenderArrowCallBack)(const Vec3& v3Pos, const Vec3& v3Vector, u32 nColour);
	typedef void (TAC_CALL *RenderPolygonCallBack)(int nNumVertices, const Vec3* pv3VertexList, const Vec3* pv3NormalList);

	static inline void TAC_CALL RenderLine(
		const Vec3& v3PosA, 
		const Vec3& v3PosB,
		u32 nColour = 0xFFFFFFFF);
	static inline void TAC_CALL RenderArrow(
		const Vec3& v3Pos, 
		const Vec3& v3Vector,
		u32 nColour = 0xFFFFFFFF);
	static inline void TAC_CALL RenderPolygon(
		int nNumVertices,
		const Vec3* pv3VertexList,
		const Vec3* pv3NormalList);
	static inline void TAC_CALL SetRenderLineCallback(
		RenderLineCallBack pRenderLineCallBack);
	static inline void TAC_CALL SetRenderArrowCallback(
		RenderArrowCallBack pRenderArrowCallBack);
	static inline void TAC_CALL SetRenderPolygonCallback(
		RenderPolygonCallBack pRenderPolygonCallBack);
	static void TAC_CALL PhysicsRender::RenderBox(
		const MFrame& mFrame,
		const Vec3& v3Center,
		const Vec3& v3Extent,
		u32 nColour);
	


private:
	static RenderLineCallBack llOlOOlOlllO;
	static RenderArrowCallBack llOlOOlOllll;
	static RenderPolygonCallBack llOlOOllOOOO;	
};


inline void TAC_CALL PhysicsRender::RenderLine(
	const Vec3& llllOOOOll, 
	const Vec3& llllOOOlOO,
	u32 llOlOOllOOOl)
{
	if (llOlOOlOlllO)
		llOlOOlOlllO(llllOOOOll, llllOOOlOO, llOlOOllOOOl);
}

inline void TAC_CALL PhysicsRender::RenderArrow(
	const Vec3& llOOlllllO, 
	const Vec3& lOOOlOOOlOl,
	u32 llOlOOllOOOl)
{
	if (llOlOOlOllll)
		llOlOOlOllll(llOOlllllO, lOOOlOOOlOl, llOlOOllOOOl);
}

inline void TAC_CALL PhysicsRender::RenderPolygon(
	int lOllOlllOl,
	const Vec3* lllOlOllOlO,
	const Vec3* lllOlOllOll)
{
	if (llOlOOllOOOO)
		llOlOOllOOOO(lOllOlllOl, lllOlOllOlO, lllOlOllOll);
}

inline void TAC_CALL PhysicsRender::SetRenderLineCallback(
	RenderLineCallBack llOlOOllOOlO)
{
	llOlOOlOlllO = llOlOOllOOlO;
}

inline void TAC_CALL PhysicsRender::SetRenderArrowCallback(
	RenderArrowCallBack llOlOOllOOll)
{
	llOlOOlOllll = llOlOOllOOll;
}

inline void TAC_CALL PhysicsRender::SetRenderPolygonCallback(
	RenderPolygonCallBack llOlOOllOlOO)
{
	llOlOOllOOOO = llOlOOllOlOO;
}
	

}

#endif 
