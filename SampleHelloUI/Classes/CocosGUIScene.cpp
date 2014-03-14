#include "CocosGUIScene.h"
#include "VisibleRect.h"
#include "UISceneManager.h"
#include "cocostudio/CocoStudio.h"

enum
{
    LINE_SPACE = 40,
    kItemTagBasic = 1000,
};

static struct
{
	const char *name;
	std::function<void(Ref* sender)> callback;
}
g_guisTests[] =
{
	{
        "gui ButtonTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUIButtonTest);
            pManager->setMinUISceneId(kUIButtonTest);
            pManager->setMaxUISceneId(kUIButtonTest_Title);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui CheckBoxTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUICheckBoxTest);
            pManager->setMinUISceneId(kUICheckBoxTest);
            pManager->setMaxUISceneId(kUICheckBoxTest);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
	{
        "gui SliderTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUISliderTest);
            pManager->setMinUISceneId(kUISliderTest);
            pManager->setMaxUISceneId(kUISliderTest_Scale9);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    /*
     {
     "gui PotentiometerTest",
     [](Ref* sender)
     {
     UISceneManager* pManager = UISceneManager::sharedUISceneManager();
     pManager->setCurrentUISceneId(kUIPotentiometerTest);
     pManager->setMinUISceneId(kUIPotentiometerTest);
     pManager->setMaxUISceneId(kUIPotentiometerTest);
     Scene* pScene = pManager->currentUIScene();
     Director::getInstance()->replaceScene(pScene);
     }
     },
     {
     "gui SwitchTest",
     [](Ref* sender)
     {
     UISceneManager* pManager = UISceneManager::sharedUISceneManager();
     pManager->setCurrentUISceneId(kUISwitchTest_Horizontal);
     pManager->setMinUISceneId(kUISwitchTest_Horizontal);
     pManager->setMaxUISceneId(kUISwitchTest_VerticalAndTitleVertical);
     Scene* pScene = pManager->currentUIScene();
     Director::getInstance()->replaceScene(pScene);
     }
     },
     */
    {
        "gui ImageViewTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUIImageViewTest);
            pManager->setMinUISceneId(kUIImageViewTest);
            pManager->setMaxUISceneId(kUIImageViewTest_Scale9);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui LoadingBarTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUILoadingBarTest_Left);
            pManager->setMinUISceneId(kUILoadingBarTest_Left);
            pManager->setMaxUISceneId(kUILoadingBarTest_Right_Scale9);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    /*
     {
     "gui ProgressTimerTest",
     [](Ref* sender)
     {
     UISceneManager* pManager = UISceneManager::sharedUISceneManager();
     pManager->setCurrentUISceneId(kUIProgressTimerTest_Radial);
     pManager->setMinUISceneId(kUIProgressTimerTest_Radial);
     pManager->setMaxUISceneId(kUIProgressTimerTest_WithSpriteFrame);
     Scene* pScene = pManager->currentUIScene();
     Director::getInstance()->replaceScene(pScene);
     }
     },
     */
    {
        "gui TextAtalsTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUILabelAtlasTest);
            pManager->setMinUISceneId(kUILabelAtlasTest);
            pManager->setMaxUISceneId(kUILabelAtlasTest);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui TextTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUILabelTest);
            pManager->setMinUISceneId(kUILabelTest);
            pManager->setMaxUISceneId(kUILabelTest_TTF);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui TextBMFontTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUILabelBMFontTest);
            pManager->setMinUISceneId(kUILabelBMFontTest);
            pManager->setMaxUISceneId(kUILabelBMFontTest);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui TextFieldTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUITextFieldTest);
            pManager->setMinUISceneId(kUITextFieldTest);
            pManager->setMaxUISceneId(kUITextFieldTest_Password);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui LayoutTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUILayoutTest);
            pManager->setMinUISceneId(kUILayoutTest);
            pManager->setMaxUISceneId(kUILayoutTest_Layout_Relative_Location);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui ScrollViewTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUIScrollViewTest_Vertical);
            pManager->setMinUISceneId(kUIScrollViewTest_Vertical);
            pManager->setMaxUISceneId(kUIScrollViewTest_ScrollToPercentBothDirection_Bounce);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui PageViewTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUIPageViewTest);
            pManager->setMinUISceneId(kUIPageViewTest);
            pManager->setMaxUISceneId(kUIPageViewTest);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    {
        "gui ListViewTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUIListViewTest_Vertical);
            pManager->setMinUISceneId(kUIListViewTest_Vertical);
            pManager->setMaxUISceneId(kUIListViewTest_Horizontal);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
    /*
     {
     "gui GridViewTest",
     [](Ref* sender)
     {
     UISceneManager* pManager = UISceneManager::sharedUISceneManager();
     pManager->setCurrentUISceneId(kUIGridViewTest_Mode_Column);
     pManager->setMinUISceneId(kUIGridViewTest_Mode_Column);
     pManager->setMaxUISceneId(kUIGridViewTest_Mode_Row);
     Scene* pScene = pManager->currentUIScene();
     Director::getInstance()->replaceScene(pScene);
     }
     },
     {
     "gui PickerViewTest",
     [](Ref* sender)
     {
     UISceneManager* pManager = UISceneManager::sharedUISceneManager();
     pManager->setCurrentUISceneId(kUIPickerViewTest_Vertical);
     pManager->setMinUISceneId(kUIPickerViewTest_Vertical);
     pManager->setMaxUISceneId(kUIPickerViewTest_Horizontal);
     Scene* pScene = pManager->currentUIScene();
     Director::getInstance()->replaceScene(pScene);
     }
     },
     */
    {
        "gui WidgetAddNodeTest",
        [](Ref* sender)
        {
            UISceneManager* pManager = UISceneManager::sharedUISceneManager();
            pManager->setCurrentUISceneId(kUIWidgetAddNodeTest);
            pManager->setMinUISceneId(kUIWidgetAddNodeTest);
            pManager->setMaxUISceneId(kUIWidgetAddNodeTest);
            Scene* pScene = pManager->currentUIScene();
            Director::getInstance()->replaceScene(pScene);
        }
	},
};

static const int g_maxTests = sizeof(g_guisTests) / sizeof(g_guisTests[0]);

static Point s_tCurPos = Point::ZERO;

////////////////////////////////////////////////////////
//
// CocosGUITestMainLayer
//
////////////////////////////////////////////////////////
void CocosGUITestMainLayer::onEnter()
{
    Layer::onEnter();
    
    auto s = Director::getInstance()->getWinSize();
    
    _itemMenu = Menu::create();
    _itemMenu->setPosition( s_tCurPos );
    MenuItemFont::setFontName("Arial");
    MenuItemFont::setFontSize(24);
    for (int i = 0; i < g_maxTests; ++i)
    {
        auto pItem = MenuItemFont::create(g_guisTests[i].name, g_guisTests[i].callback);
        pItem->setPosition(Point(s.width / 2, s.height - (i + 1) * LINE_SPACE));
        _itemMenu->addChild(pItem, kItemTagBasic + i);
    }
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(CocosGUITestMainLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(CocosGUITestMainLayer::onTouchesMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    addChild(_itemMenu);
}

void CocosGUITestMainLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    auto touch = static_cast<Touch*>(touches[0]);
    
    _beginPos = touch->getLocation();
}

void CocosGUITestMainLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
    auto touch = static_cast<Touch*>(touches[0]);
    
    auto touchLocation = touch->getLocation();
    float nMoveY = touchLocation.y - _beginPos.y;
    
    auto curPos  = _itemMenu->getPosition();
    auto nextPos = Point(curPos.x, curPos.y + nMoveY);
    
    if (nextPos.y < 0.0f)
    {
        _itemMenu->setPosition(Point::ZERO);
        return;
    }
    
    if (nextPos.y > ((g_maxTests + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height))
    {
        _itemMenu->setPosition(Point(0, ((g_maxTests + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height)));
        return;
    }
    
    _itemMenu->setPosition(nextPos);
    _beginPos = touchLocation;
    s_tCurPos   = nextPos;
}


////////////////////////////////////////////////////////
//
// CocosGUITestScene
//
////////////////////////////////////////////////////////

void CocosGUITestScene::onEnter()
{
    Scene::onEnter();
    
    auto layer = new CocosGUITestMainLayer();
    addChild(layer);
    layer->release();
    
    // add close menu
    auto closeItem = MenuItemImage::create("CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CocosGUITestScene::closeCallback, this) );
    auto menu =Menu::create(closeItem, NULL);
    
    menu->setPosition( Point::ZERO );
    closeItem->setPosition(Point( VisibleRect::right().x - 30, VisibleRect::top().y - 30));
    addChild(menu);
}

void CocosGUITestScene::closeCallback(Ref *pSender)
{
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}