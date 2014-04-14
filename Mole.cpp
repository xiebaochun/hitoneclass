//
//  Bullet.cpp
//  Asteroids
//
//  Created by Clawoo on 9/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Mole.h"

USING_NS_CC;

Mole* Mole::spriteWithFile(const char *pszFileName)
{
    Mole *pobSprite = new Mole();
	//TimeBar *pobSprite = TimeBar::create();
	if (pobSprite&& pobSprite->initWithFile(pszFileName))
    {
        //pobSprite->scheduleUpdate();
        //pobSprite->setDistanceMoved(0);
		//pobSprite->setPosition(ccp(640,650));
		pobSprite->init();
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
	return NULL;
}
bool Mole::init()
{
	this->icount_=0;
	this->setAlive(true);
	this->setShowUpFinshed(false);
	this->currentFrame2D_.x=6;
	this->currentFrame2D_.y=0;
	this->setAnchorPoint(ccp(0,0));
	/*this->setEachRoundTime(20);
	this->setEachRoundPassedTime(0);*/
	this->setFrame2D(cpv(7,1));
	this->setTextureWidth(this->getContentSize().width);
	this->setVisibleRect(CCRectMake(0,0,this->getContentSize().width/this->getFrame2D().x,this->getContentSize().height/this->getFrame2D().y));
	this->setVisibleRect(CCRectMake(this->currentFrame2D_.x*this->getVisibleRect().size.width,this->currentFrame2D_.y*this->getVisibleRect().size.height,this->getVisibleRect().size.width,this->getVisibleRect().size.height));
	this->setTextureRect(this->getVisibleRect());
	this->scheduleUpdate();
	return true;
}
void Mole::update(float dt)
{
	this->showUp(dt);
	this->disappear(dt);
}
void Mole::showUp(float dt)
{
	if(this->isVisible()==true&&this->getAlive()==true&&this->getShowUpFinshed()==false)
	{
		this->icount_+=dt;
		if(this->icount_>=1)
		{
			this->icount_=0;
			this->currentFrame2D_.x--;
			//this->setVisibleRect(CCRectMake(this->currentFrame2D_.x,this->currentFrame2D_.y,this->getVisibleRect().size.width,this->getVisibleRect().size.height));
			this->setVisibleRect(CCRectMake(this->currentFrame2D_.x*this->getVisibleRect().size.width,this->currentFrame2D_.y*this->getVisibleRect().size.height,this->getVisibleRect().size.width,this->getVisibleRect().size.height));
			this->setTextureRect(this->getVisibleRect());
			if(this->currentFrame2D_.x<=0)
			{
				this->setShowUpFinshed(true);
			
			}
		}
	}
}
void Mole::disappear(float dt)
{
	if(this->isVisible()==true&&this->getAlive()==false&&this->getShowUpFinshed()==true)
	{
		this->icount_+=dt;
		if(this->icount_>=1)
		{
			this->icount_=0;
			this->currentFrame2D_.x++;
			//this->setVisibleRect(CCRectMake(this->currentFrame2D_.x,this->currentFrame2D_.y,this->getVisibleRect().size.width,this->getVisibleRect().size.height));
			this->setVisibleRect(CCRectMake(this->currentFrame2D_.x*this->getVisibleRect().size.width,this->currentFrame2D_.y*this->getVisibleRect().size.height,this->getVisibleRect().size.width,this->getVisibleRect().size.height));
			this->setTextureRect(this->getVisibleRect());

			if(this->currentFrame2D_.x>=6)
			{
				//this->setAlive(true);
				this->setShowUpFinshed(false);
				this->setVisible(false);
			}
		}
	}
}
void Mole::setAlive(bool isAlive)
{
	if(isAlive==true)this->setVisible(true);
	this->alive_=isAlive;
}
bool Mole::getAlive()
{
	return this->alive_;
}

void Mole::onEnter()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}

void Mole::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}    

bool Mole::containsTouchLocation(CCTouch* touch)
{
	//return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
	return true;
}


bool Mole::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	//if (m_state != kPlayerStateUngrabbed) return false;
	//if ( !containsTouchLocation(touch) ) return false;//touch on the sprite, then we do something

	//m_state = kPlayerStateGrabbed;
	this->setAlive(false);
	return true;
}

void Mole::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

	//CCAssert(m_state == kPlayerStateGrabbed, "Player - Unexpected state!");    
	//CCSize screenSize = CCDirector::sharedDirector()->getWinSize();


	//CCPoint tap = touch->getLocation();
	//CCPoint nextPosition = tap;
	////keep player in court
	//nextPosition = ccp(max(nextPosition.x, radius()), max(nextPosition.y, radius()));
	//nextPosition = ccp(min(nextPosition.x, screenSize.width - radius()) ,
	//	min(nextPosition.y, screenSize.height - radius()));

	////keep player in its area
	//if (getPositionY() < screenSize.height * 0.5f) {
	//	nextPosition.y = min(nextPosition.y, screenSize.height / 2 - radius());
	//} else {
	//	nextPosition.y = max(nextPosition.y, screenSize.height / 2 + radius());
	//}

	//setNextPosition(nextPosition);
	//setVector(ccp(tap.x -  getPositionX(), tap.y - getPositionY()));

}



void Mole::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	/*CCAssert(m_state == kPlayerStateGrabbed, "Player - Unexpected state!");    

	m_state = kPlayerStateUngrabbed;

	setVector(CCPointZero);*/
} 

void Mole::touchDelegateRetain()
{
	this->retain();
}

void Mole::touchDelegateRelease()
{
	this->release();
}
