#include "GameScene.h"
#include "Definitions.h"
#include "time.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    if (!Layer::init()) {return false;}
    
    setTouchEnabled(true);
    isGameOver = false;

    /**Initialize Displays**/
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    /** INIT LAYER OBJECTS **/
    scrollingBgLayer = new ScrollingBgLayer(25);
    gpLayer = new GamePlayLayer();
    hud = new HUD();

    this->addChild(scrollingBgLayer, -1);
    this->addChild(gpLayer, 5);
    this->addChild(hud, 15);
    /***********************/
    
    /**Initialize Player**/
    player = Player::createPlayer(this);
    addChild(player,5);
    
    /**Schedule**/
    this->scheduleUpdate();
    this->schedule(schedule_selector(GameScene::spawnEnemies), SPAWN_FREQUENCY);

    return true;
}

void GameScene::update(float delta)
{
    score++;
    checkCollisions();
    gpLayer->update();
    hud->updateScore(score);
    scrollingBgLayer->update();
}

/** This creates a new enemy, adds as child, and pushes to enemies vector of the gpLayer class */
void GameScene::spawnEnemies(float dt)
{
    srand (time(NULL));
    // generate random number
    int r = rand()% 2 + 1;
    if(r == 1)
    {
         Enemy* spawn = Enemy::createEnemy("frog");
         gpLayer->addChild(spawn);
         gpLayer->getEnemiesVec().pushBack(spawn);
    }
    if(r == 2)
    {
        Enemy* spawn = Enemy::createEnemy("alien");
        gpLayer->addChild(spawn);
        gpLayer->getEnemiesVec().pushBack(spawn);
    }
}
bool GameScene::onTouchBegan(Touch *touch, Event *event){
    player->jumpAnim();
    return true;
}


void GameScene::setTouchEnabled(bool enabled)
{
    auto _touchListener = EventListenerTouchOneByOne::create();
    _touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    _touchListener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
}


void GameScene::checkCollisions()
{
    for (int i = 0; i < gpLayer->getEnemiesVec().size(); i++)
    {
        Enemy* eee = gpLayer->getEnemiesVec().at(i);
        Rect playerBB = player->getBoundingBox();
        Rect enemyBB = eee->getBoundingBox();
        if (player->getBoundingBox().intersectsRect(eee->getBoundingBox()))
        {
            player->deathAnim();
            cout << "Collision has occurred :( Game Over !" << endl;
            this->removeChild(eee);
            isGameOver = true;
            gameOver();
            return;
        }
    }
}

void GameScene::gameOver()
{
    if(isGameOver) {
        cout << "...Entering GameOverScene" << endl;
    }
}

void GameScene::gameResumed(){
   
    this->scheduleUpdate();
    this->schedule(schedule_selector(GameScene::spawnEnemies), SPAWN_FREQUENCY);
    
    auto _enemies_ = gpLayer->getEnemiesVec();
    
    for(int i = 0; i < _enemies_.size(); i++){
        Enemy* ene = (Enemy*)_enemies_.at(i);
        ene->resume();
    }
}
void GameScene::gamePaused(){
 
    this->unscheduleUpdate();
    this->unschedule(schedule_selector(GameScene::spawnEnemies));
    
    auto _enemies_ = gpLayer->getEnemiesVec();
    
    for(int i = 0; i < _enemies_.size(); i++){
        Enemy* ene = (Enemy*)_enemies_.at(i);
        ene->pause();
    }
}

