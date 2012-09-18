#include <OgreSceneNode.h>
#include <btBulletCollisionCommon.h>

class PhysMotionState : public btMotionState {
  public:
    PhysMotionState(Ogre::SceneNode* node, const btTransform& initialpos = btTransform::getIdentity()) {
      mVisibleobj = node;
      mPos1 = initialpos;
    }

    virtual ~PhysMotionState() {
    }

    void setNode(Ogre::SceneNode* node) {
      mVisibleobj = node;
    }

    virtual void getWorldTransform(btTransform& worldTrans) const {
      worldTrans = mPos1;
    }

    virtual void setWorldTransform(const btTransform& worldTrans) {
      if(NULL == mVisibleobj)
        return; // silently return before we set a node
      btQuaternion rot = worldTrans.getRotation();
      mVisibleobj->setOrientation(rot.w(), rot.x(), rot.y(), rot.z());
      btVector3 pos = worldTrans.getOrigin();
      mVisibleobj->setPosition(pos.x(), pos.y(), pos.z());
    }

  protected:
    Ogre::SceneNode* mVisibleobj;
    btTransform mPos1;
};
