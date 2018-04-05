//---------------------------------------------------------------------------------
// File Name: ConvexHull.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_CONVEXHULL_H
#define TA_CONVEXHULL_H

#ifndef lOOllOllll
#include "../Common/zcta001.h"
#endif 

#ifndef TA_VECTOR_H
#include "Vector.h"
#endif 



namespace TA
{

struct Vec3;

class TACOMMON_CLASS ConvexHull
{
public:
	
	struct Polygon
	{
		
		int GetNumVertices() const;
		int GetVertexPositionIndex(int nVertexIndex) const;
		int GetVertexAdjacentPolygonIndex(int nVertexIndex) const;
		

		struct Vertex
		{
			int llOllllOOO;
			int llOllllOOl;
		};
		int lOllOlllOl;
		Vertex llOllllOlO[16]; 
	};

	

	ConvexHull();
	~ConvexHull();

	bool Initialise(const Vec3* v3PointList, int nNumPoints, int nMaxNumVerticesInPolygon);
	bool Initialise(	
		const Vec3* pv3PlaneNormalList, 
		const Vec3* pv3PlanePointList, 
		int nNumPlanes);

	void Finalise();

	int GetNumPoints() const;
	const Vec3& GetPoint(int nIndex) const;

	int GetNumPolygons() const;
	const Polygon& GetPolygon(int nIndex) const;

	
	
private:
	struct lOllllllOl;
	class lOlOlOlllO;
	
	bool llOOOOllll;
	bool llOOlOOlOO;
	float llOllllOll;
	lOOOOlOllO<int> llOOlOlOlO;
	lOOOOlOllO<int> llOOlOlOll;
	lOOOOlOllO<Vec3, false> llOOlOllOO;
	
	
	

	bool Initialise(lOlOlOlllO& llOOlOlOOO);
	bool llOOlOOOll(const Vec3* llOOOlllOl, int llOOOllllO, int llOOOlllll, float llOOlOOOOO, float llOOlOOOOl);
};

inline int ConvexHull::Polygon::GetNumVertices() const { return lOllOlllOl; }
inline int ConvexHull::Polygon::GetVertexPositionIndex(int llOlllllOO) const { return llOllllOlO[llOlllllOO].llOllllOOO; }
inline int ConvexHull::Polygon::GetVertexAdjacentPolygonIndex(int llOlllllOO) const { return llOllllOlO[llOlllllOO].llOllllOOl; }
inline int ConvexHull::GetNumPoints() const { return llOOlOllOO.lOOOlllOOl(); }
inline const Vec3& ConvexHull::GetPoint(int lOOOlOOlll) const { return llOOlOllOO[lOOOlOOlll]; }
inline int ConvexHull::GetNumPolygons() const { return llOOlOlOll.lOOOlllOOl(); }
inline const ConvexHull::Polygon& ConvexHull::GetPolygon(int lOOOlOOlll) const { return *(Polygon*)&llOOlOlOlO[llOOlOlOll[lOOOlOOlll]]; }

}
#endif 
