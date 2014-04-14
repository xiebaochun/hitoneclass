#include "HelloWorldScene.h"

USING_NS_CC;

	

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	#define ccsf(...) CCString::createWithFormat(__VA_ARGS__)->getCString();
	icount=0;
	score=0;
	stage=1;
	target=24;
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    


	CCMenuItemImage* testMenuItem=CCMenuItemImage::create("layout-04.png","bg_white.png",this,menu_selector(HelloWorld::testMenuItemCallback));
	//this->addChild(testMenuItem,3);

	// create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(testMenuItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
	int width=visibleSize.width;
	int height=visibleSize.height;

	//************************************ Label **************************************
	CCString* ns=CCString::createWithFormat("%d*%d origin:%d*%d",width,height,(int)origin.x,(int)origin.y);

	 pLabel = CCLabelTTF::create(ns->getCString(), "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
	pLabel->setColor(ccc3(0,0,0));
    // add the label as a child to this layer
    this->addChild(pLabel, 5);

	scoreLabel=CCLabelTTF::create("1", "Arial", STATE_BAR_FONT_SIZE);
	scoreLabel->setPosition(ccp(260,695));
	scoreLabel->setColor(ccc3(0,0,0));
	this->addChild(scoreLabel,2);

    stageLabel=CCLabelTTF::create("1", "Arial", STATE_BAR_FONT_SIZE);
	stageLabel->setPosition(ccp(640,695));
	stageLabel->setColor(ccc3(0,0,0));
	this->addChild(stageLabel,2);

	targetLabel=CCLabelTTF::create("1", "Arial", STATE_BAR_FONT_SIZE);
	targetLabel->setPosition(ccp(1000,695));
	targetLabel->setColor(ccc3(0,0,0));
	this->addChild(targetLabel,2);



	//************************************ Sprite **************************************
    // add "HelloWorld" splash screen"
    //CCSprite* pSprite = CCSprite::create("HelloWorld.png");
	CCSprite* pSprite = CCSprite::create("bg_c.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

	
	CCSprite* spBackground_01=CCSprite::create("bg1.png");
	spBackground_01->setAnchorPoint(ccp(0,0));
	spBackground_01->setPosition(ccp(origin.x,origin.y));
	//spBackground_01->setScale(1);
	this->addChild(spBackground_01,0);

	CCSprite* spBackground_02=CCSprite::create("bg2.png");
	spBackground_02->setAnchorPoint(ccp(0,0));
	spBackground_02->setVisible(false);
	//spBackground_01->setPosition(ccp(640,384));
	this->addChild(spBackground_02,0);

	CCSprite* spBackground_03=CCSprite::create("bg3.png");
	spBackground_03->setAnchorPoint(ccp(0,0));
	spBackground_03->setVisible(false);
	//spBackground_01->setPosition(ccp(640,384));
	this->addChild(spBackground_03,0);
	
	CCSprite* stateBar=CCSprite::create("StateBar.png");
	//stateBar->setAnchorPoint(ccp(0.5,0));
	stateBar->setVisible(true);
	CCPoint STATE_BAR_POSITION=ccp(visibleSize.width/2 + origin.x,visibleSize.height-stateBar->getContentSize().height/2);
	stateBar->setPosition(STATE_BAR_POSITION);
	//stateBar->setScale(1.5f);
	//stateBar->setTextureRect(CCRectMake(0,0,300,200));
	this->addChild(stateBar,1);

	//********************************** TimeBar **********************************
	timeBar_=(TimeBar*)TimeBar::spriteWithFile("TimeBar.png");
	timeBar_->setPosition(ccp(visibleSize.width/2-timeBar_->getTextureWidth()/2+27,613));
	//timeBar_->setEachRoundTime(20);
	//timeBar_->setTextureRect(CCRectMake(0,0,400,timeBar_->getContentSize().height));
	this->addChild(timeBar_,2);
	
	//******************************** Mole **************************************
	mole_=(Mole*)Mole::spriteWithFile("hit_2.png");
	this->addChild(mole_,1);

	ns=CCString::createWithFormat("%d*%d origin:%d*%d statebar:%d%d rect%d%d",width,height,(int)origin.x,(int)origin.y,(int)(stateBar->getContentSize().width),(int)(stateBar->getContentSize().height),(int)(stateBar->getTextureRect().size.width),(int)(stateBar->getTextureRect().size.height));
	pLabel->setString(ns->getCString());

	
	

	this->gameState=start;
	//auto listener1=EventListenerTouchOneByOne::create();
	//this->schedule(schedule_selector(HelloWorld::update));
	this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
	icount++;
	if(icount>=1000)icount=0;
	//CCString* s=CCString::createWithFormat("%d",icount);
	CCString* s=CCString::createWithFormat("%d",(int)timeBar_->getEachRoundPassedTime());
	pLabel->setString(s->getCString());

	switch(gameState)
	{
		case start:
			this->gameState=playing;
			break;

		case playing:

			break;

		case over:
		break;
	}

}
void HelloWorld::testMenuItemCallback(CCObject* pSender)
{
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
