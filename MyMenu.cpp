//
//  Bullet.cpp
//  Asteroids
//
//  Created by Clawoo on 9/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "MyMenu.h"

USING_NS_CC;

MyMenu* MyMenu::myMenuWithFile(const char *pszFileName)
{
    MyMenu *pobSprite = new MyMenu();
	//TimeBar *pobSprite = TimeBar::create();
	
	if (pobSprite&& pobSprite->init(pszFileName))
    {
        //pobSprite->scheduleUpdate();
        //pobSprite->setDistanceMoved(0);
		//pobSprite->setPosition(ccp(640,650));
		//pobSprite->init();
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
	return NULL;
}

bool MyMenu::init(const char *pszFileName)
{
	CCMenuItemImage* tempMenuItem=CCMenuItemImage::create(pszFileName,pszFileName,this,menu_selector(MyMenu::menuItemCallback));
	this->addChild(tempMenuItem,0);
	this->setAnchorPoint(ccp(0,0));
	this->scheduleUpdate();
	return true;
}
void MyMenu::menuItemCallback(CCObject* pSender)
{

}
void MyMenu::update(float dt)
{
	this->showUp(dt);
	this->disappear(dt);
}
void MyMenu::showUp(float dt)
{
	
}
void MyMenu::disappear(float dt)
{
	
}

void MyMenu::onEnter()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	CCLayer::onEnter();
}

void MyMenu::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}    
bool MyMenu::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	return true;
}

void MyMenu::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}



void MyMenu::ccTouchEnded(CCTouch* touch, CCEvent* event)
{

} 

void MyMenu::touchDelegateRetain()
{
	this->retain();
}

void MyMenu::touchDelegateRelease()
{
	this->release();
}
