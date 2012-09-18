/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Dmitro Melnichuk <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef MESHTOSHAPECONVERTER_H
#define MESHTOSHAPECONVERTER_H

#include "OgreBulletCollisionsPreRequisites.h"

#include <BulletCollision/btBulletCollisionCommon.h>
#include <OgreMatrix4.h>
#include <OgreMesh.h>

#include <OgreRoot.h>
#include <BulletDynamics/btBulletDynamicsCommon.h>

class BtOgreConverter;
class OgreBtConverter;

class CollisionsWorld;

class CollisionRayResultCallback;
class CollisionClosestRayResultCallback;

class DebugLines;

class DebugDrawer;

class DebugContact;
class DebugNormal;
class DebugContactText;

class DebugCollisionShape;
class BoxDebugShape;
class SphereDebugShape;
class ConeDebugShape;
class TriangleMeshDebugShape;
class RayDebugShape;

class GImpactConcaveShape;
class HeightmapCollisionShape;
class CollisionShape;
class BoxCollisionShape;
class SphereCollisionShape;
class CylinderCollisionShape;
class CapsuleCollisionShape;
class ConeCollisionShape;

class CompoundCollisionShape;

class MultiSphereCollisionShape;
class MinkowskiSumCollisionShape;

class ConvexHullCollisionShape;
class TriangleMeshCollisionShape;

class Object;

class ObjectState;

class CollisionShapebject;

typedef std::vector<Ogre::Vector3> Vector3Array;
typedef std::map<unsigned short, Vector3Array* > BoneIndex;
typedef std::pair<unsigned short, Vector3Array* > BoneKeyIndex;

class MeshToShapeConverter {
  public:
    MeshToShapeConverter();
    virtual ~MeshToShapeConverter();
};

#include <BulletCollision/CollisionShapes/btShapeHull.h>

class VertexIndexToShape {
  public:
    VertexIndexToShape(const Ogre::Matrix4& transform = Ogre::Matrix4::IDENTITY);
    ~VertexIndexToShape();

    Ogre::Real      getRadius();
    Ogre::Vector3   getSize();


    /*btSphereShape*           createSphere();*/
    btBoxShape*              createBox();
    btBvhTriangleMeshShape*	     createTrimesh();
    /*btCylinderShape*         createCylinder();*/
    btConvexHullShape*       createConvex();/*
    //GImpactConcaveShape*	     createConcave();
    btCompoundShape*         createConvexDecomposition(
      unsigned int depth = 5 // depth to split, a maximum of 10, generally not over 7.
                           , float cpercent     = 5 	// the concavity threshold percentage.  0=20 is reasonable.
                               , float ppercent     = 15 // the percentage volume conservation threshold to collapse hulls. 0-30 is reasonable.
                                   , unsigned int maxv  = 32 // maximum number of vertices in the output hull. Recommended 32 or less.
                                       , float skinWidth    = 0.0 // a skin width to apply to the output hulls.
    );*/


    const Ogre::Vector3*    getVertices();
    unsigned int            getVertexCount();
    const unsigned int*     getIndices();
    unsigned int            getIndexCount();

  protected:

    void addStaticVertexData(const Ogre::VertexData* vertex_data);

    void addAnimatedVertexData(const Ogre::VertexData* vertex_data,
                               const Ogre::VertexData* blended_data,
                               const Ogre::Mesh::IndexMap* indexMap);

    void addIndexData(Ogre::IndexData* data, const unsigned int offset = 0);


  protected:
    Ogre::Vector3*	    mVertexBuffer;
    unsigned int*       mIndexBuffer;
    unsigned int        mVertexCount;
    unsigned int        mIndexCount;

    Ogre::Matrix4		mTransform;

    Ogre::Real		    mBoundRadius;
    Ogre::Vector3		mBounds;

    BoneIndex*           mBoneIndex;

};

class StaticMeshToShapeConverter : public VertexIndexToShape {
  public:

    StaticMeshToShapeConverter(Ogre::Renderable* rend, const Ogre::Matrix4& transform = Ogre::Matrix4::IDENTITY);
    StaticMeshToShapeConverter(Ogre::Entity* entity,   const Ogre::Matrix4& transform = Ogre::Matrix4::IDENTITY);
    StaticMeshToShapeConverter();

    ~StaticMeshToShapeConverter();

    virtual void addEntity(Ogre::Entity* entity, const Ogre::Matrix4& transform = Ogre::Matrix4::IDENTITY);

    virtual void addMesh(const Ogre::MeshPtr& mesh, const Ogre::Matrix4& transform = Ogre::Matrix4::IDENTITY);


  protected:

    Ogre::Entity*		mEntity;
    Ogre::SceneNode*	mNode;

};

class AnimatedMeshToShapeConverter : public VertexIndexToShape {
  public:

    AnimatedMeshToShapeConverter(Ogre::Entity* entity, const Ogre::Matrix4& transform = Ogre::Matrix4::IDENTITY);
    AnimatedMeshToShapeConverter();
    ~AnimatedMeshToShapeConverter();

    void addEntity(Ogre::Entity* entity, const Ogre::Matrix4& transform = Ogre::Matrix4::IDENTITY);
    void addMesh(const Ogre::MeshPtr& mesh, const Ogre::Matrix4& transform);

    BoxCollisionShape* createAlignedBox(unsigned char bone,
                                        const Ogre::Vector3& bonePosition,
                                        const Ogre::Quaternion& boneOrientation);

    BoxCollisionShape* createOrientedBox(unsigned char bone,
                                         const Ogre::Vector3& bonePosition,
                                         const Ogre::Quaternion& boneOrientation);

    CapsuleCollisionShape* createOrientedCapsuleCollisionShape(unsigned char bone,
        const Ogre::Vector3& bonePosition,
        const Ogre::Quaternion& boneOrientation);

  protected:

    bool getBoneVertices(unsigned char bone,
                         unsigned int& vertex_count,
                         Ogre::Vector3* &vertices,
                         const Ogre::Vector3& bonePosition);

    bool getOrientedBox(unsigned char bone,
                        const Ogre::Vector3& bonePosition,
                        const Ogre::Quaternion& boneOrientation,
                        Ogre::Vector3& extents,
                        Ogre::Vector3* axis,
                        Ogre::Vector3& center);


    Ogre::Entity*		mEntity;
    Ogre::SceneNode*	mNode;

    Ogre::Vector3*       mTransformedVerticesTemp;
    size_t               mTransformedVerticesTempSize;

};

#endif // MESHTOSHAPECONVERTER_H
