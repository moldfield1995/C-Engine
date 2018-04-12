#include "BasicMeshHitbox.h"
#include "..\TrueAxis\Physics\Physics.h"
#include "..\TrueAxis\Physics\DynamicObject.h"
#include "..\TrueAxis\Physics\CollisionObjectCombo.h"
#include "ModelClass.h"
#include "Utills.h"
#include "GameObject.h"

BasicMeshHitbox::BasicMeshHitbox(bool ControledByVelocity, CollisionLayer collisonLayer)
	: Collider(ControledByVelocity)
{
	controledByVelocity = ControledByVelocity;
	this->collisonLayer = collisonLayer;
}


BasicMeshHitbox::~BasicMeshHitbox()
{
}

void BasicMeshHitbox::Initalize()
{
	//varible and object set up
	TA::Physics& physicsInstance = TA::Physics::GetInstance();
	//Collision Setup
	TA::CollisionObjectConvex *convexCollishon = generateConvexHull();
	if (convexCollishon == 0)
	{
		Utills::DebugString("Unable to create convexCollisonMesh : Initalize : BasicMehsHitbox");
		return;
	}
	//Combo object Setup
	TA::CollisionObjectCombo *comboObject = TA::CollisionObjectCombo::CreateNew();
	comboObject->Initialise();
	comboObject->AddCollisionObject(convexCollishon);
	convexCollishon->Release();
	//Dynamic Object SetUp
	TA::DynamicObject *dynamicObject = TA::DynamicObject::CreateNew();
	dynamicObject->Initialise(comboObject);
	comboObject->Release();
	dynamicObject->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33((owner->GetRotation()* Leap::DEG_TO_RAD).ToEuler())));
	dynamicObject->SetGhost(true);
	dynamicObject->SetToMoving();
	CollisonData* collisonData = new CollisonData{ collisonLayer, owner };
	dynamicObject->SetUserData(collisonData);
	physicsInstance.AddDynamicObject(dynamicObject);
	SetOwnersDynamicObject(dynamicObject);
}


void BasicMeshHitbox::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void BasicMeshHitbox::Destroy()
{
}


//This only works reliably for models that are pivitoed on 0,0,0
TA::CollisionObjectConvex * BasicMeshHitbox::generateConvexHull()
{
	TA::CollisionObjectConvex* collisonObject = 0;
	std::string fileName;
	//Check if CollishonFile is avalable
	fileName = GetModel()->GetFileName();
	fileName.replace(fileName.length() - 3, 3, "col");
	if (Utills::FileExsits(fileName.data()))
	{
		collisonObject = TA::CollisionObjectConvex::CreateNew();
		if (collisonObject->InitialiseFromFile(fileName.data()))
		{
			return collisonObject;
		}
		//Could not load collison Object
		collisonObject->Release();
		collisonObject = 0;
	}

	//initalize varibles
	Float3 negZmax = Float3(0.0f), negZmin = Float3(0.0f), posZmax = Float3(0.0f), posZmin = Float3(0.0f);
	Float3 scale = owner->GetScale();
	TA::Vec3 *pointList = new TA::Vec3[8];
	const ModelClass::ModelType *verts = GetModel()->GetModelData();
	const int vetexCount = GetModel()->GetIndexCount();
	//Gets the highest X,Y for the lowest and highest Z
	for (int currentVert = vetexCount - 1; currentVert >= 0; currentVert--)
	{
		ModelClass::ModelType vert = verts[currentVert];
		if (vert.z < 0.0f)
		{
			if (negZmax.X < vert.x)
				negZmax.X = vert.x;
			else if (negZmin.X > vert.x)
				negZmin.X = vert.x;

			if (negZmax.Y < vert.y)
				negZmax.Y = vert.y;
			else if (negZmin.Y > vert.y)
				negZmin.Y = vert.y;

			if (negZmin.Z > vert.z)
			{
				negZmax.Z = negZmin.Z = vert.z;
			}

		}
		else
		{
			if (posZmax.X < vert.x)
				posZmax.X = vert.x;
			else if (posZmin.X > vert.x)
				posZmin.X = vert.x;

			if (posZmax.Y < vert.y)
				posZmax.Y = vert.y;
			else if (posZmin.Y > vert.y)
				posZmin.Y = vert.y;

			if (posZmin.Z < vert.z)
			{
				posZmax.Z = posZmin.Z = vert.z;
			}
		}
	}

	//Frount face
	//BottemLeft
	pointList[0] = (negZmin* scale).ToVec3();
	//BottemRight
	pointList[1] = TA::Vec3(negZmax.X * scale.X, negZmin.Y * scale.Y, negZmin.Z * scale.Z);
	//TopLeft
	pointList[2] = TA::Vec3(negZmin.X * scale.X, negZmax.Y * scale.Y, negZmin.Z * scale.Z);
	//TopRight
	pointList[3] = (negZmax * scale).ToVec3();

	//BackFace
	//BottemLeft
	pointList[4] = (posZmin *scale).ToVec3();
	//BottemRight
	pointList[5] = TA::Vec3(posZmax.X* scale.X, posZmin.Y* scale.Y, posZmin.Z* scale.Z);
	//TopLeft
	pointList[6] = TA::Vec3(posZmin.X* scale.X, posZmax.Y* scale.Y, posZmin.Z* scale.Z);
	//TopRight
	pointList[7] = (posZmax* scale).ToVec3();

	collisonObject = TA::CollisionObjectConvex::CreateNew();
	collisonObject->InitialiseFromPointList(pointList, 8);
	if (!collisonObject->SaveToFile(fileName.data()))
	{
		Utills::DebugString("Unable to save collishon File : GenerateConvexHull : BasicMeshHitbox ");
	}

	return collisonObject;
}
