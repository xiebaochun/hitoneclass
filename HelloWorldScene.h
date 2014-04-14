#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include  "TimeBar.h"
#include  "Mole.h"

typedef enum tagGameState 
{
	start,
	playing,
	over,
} GameState; 

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
	//testMenuItem callback
	void testMenuItemCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	
	// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (24)
#define STATE_BAR_FONT_SIZE  (36)
private:
	//use to count number
	int icount;

	//the score
	int score;

	//the stage
	int stage;

	//the target
	int target;

	//game state

	//use to test 
	cocos2d::CCLabelTTF* pLabel;

	//label to present game score
	cocos2d::CCLabelTTF* scoreLabel;

	//label to present game stage
	cocos2d::CCLabelTTF* stageLabel;

	//label to present game target
	cocos2d::CCLabelTTF* targetLabel;

	//time bar
	TimeBar *timeBar_;

	//define a mole
	Mole* mole_;

	//the help menuItem



	GameState gameState;
	//the update method extend from super
	void update(float dt);


};

#endif // __HELLOWORLD_SCENE_H__
