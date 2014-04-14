#ifndef __MOLE_H__
#define __MOLE_H__

#include "cocos2d.h"
#include "chipmunk_types.h"
#include "cpVect.h"

USING_NS_CC;

class Mole : public CCSprite,public CCTargetedTouchDelegate
{
public:    
    virtual void update(float dt);
	static Mole* spriteWithFile(const char *pszFileName);
	virtual bool init();

	 void showUp(float dt);
	 void disappear(float dt);
	 void setAlive(bool alive);
	 bool getAlive();

	 bool containsTouchLocation(CCTouch* touch);
    /*CC_SYNTHESIZE(float, distanceMoved_, DistanceMoved);
    CC_SYNTHESIZE(cocos2d::CCPoint, velocity_, Velocity);
    CC_SYNTHESIZE(bool, expired_, Expired);*/
	CC_SYNTHESIZE(float,eachRoundTime_,EachRoundTime);
	CC_SYNTHESIZE(float,eachRoundPassedTime_,EachRoundPassedTime);
	CC_SYNTHESIZE(float,textureWidth_,TextureWidth);
	CC_SYNTHESIZE(cpVect,frame2D,Frame2D);
	CC_SYNTHESIZE(cocos2d::CCRect,visibleRect,VisibleRect);
	bool alive_;
	CC_SYNTHESIZE(bool,showUpFinshed_,ShowUpFinshed);
	cpVect currentFrame2D_;
	float icount_;
	// implement the "static node()" method manually
	CREATE_FUNC(Mole);
	/** 2.Overwrite some virtual function @{ */ 
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();
	/** @} */
	
};

#endif // __BULLET_H__