CCExtension
===========

CCExtension은 cocos2d-x의 쉬운 사용을 도와주는 각종 기능들의 모음입니다.


Image
====

###CCMosaic
CCMosaic는 스프라이트에 모자이크 효과를 줄 수 있습니다.


![Alt text](https://raw.github.com/pjc0247/CCExtension/master/img/mosaic2.png) 
![Alt text](https://raw.github.com/pjc0247/CCExtension/master/img/mosaic.png) 
```C++
after = CCMosaic::create( before, 0.05 );
```

##CCBlend
CCBlend은 ccBlendFunc프리셋들의 모음입니다.

```
지원하는 프리셋

None, Blend,Add, Multiply, Screen, Linear Dodge
```

```C++
sprite->setBlendFunc(
    CCBlend::Multiply);
```

Layer
====

###CCYSortedLayer
CCYSortedLayer는 Y축을 기준으로 z-order가 정렬되는 레이어입니다.
```C++
layer = CCYSortedLayer::create();

obj1->setPosition( ccp(0,100) );
obj2->setPosition( ccp(0,140) );

layer->addChild( obj1 );
layer->addChild( obj2 );
```

###CCScroller
CCScroller는 터치를 통해 내용을 스크롤 할 수 있는 레이어입니다.
```C++
CCScroller *scroller =
    CCScroller::create( CCScroller::Vertical );

scroller->addItem( sprite1 );
scroller->addItem( sprite2 );

/*
    apply 메소드를 사용하여 새로 추가된 아이템들을 반영하여 즉시 다시 그립니다.
*/
scroller->apply();

/*
    LiveUpdate를 true로 설정할 경우 매 프레임마다 아이템들이 다시 그려집니다.
    아이템들이 동적으로 변화하는 경우에 true로 설정해야 합니다.
*/
scroller->enableLiveUpdate( true );
```


UserInterface
====
###CCReactButton
CCReactButton은 클릭했을 때 지정된 액션을 수행한 후 callback을 부르는 버튼입니다.

CCReactButton을 이용해 누르면 반응하는 버튼을 만들 수 있습니다.
```C++
CCReactButton *btn;
btn = CCReactButton::create(
    "normal.png", "clicked.png", "disalbed.png",
    this, menu_selector(cb),
    CCSequence::create(
        CCScaleTo::create(0.3, 1.2,1.1),
        CCScaleTo::create(0.3, 1.0,1.0),
        NULL
    ));
```

###CCProgressBar
```C++
CCProgressBar *pg = CCProgressBar::create();
```


Action
====

###CCDynamicActionManager
CCDynamicActionManager는 전역적으로 모든 액션들을 n배속으로 재생할 수 있도록 해주는 액션 매니져입니다.

```C++
CCDynamicActionManager *action_mgr = CCDynamicActionManager::create();
director->setActionManager(action_mgr);
```
```C++
// 2배속으로 재생
action_mgr->setSpeed(2);
```

###CCAnimateWithBlending
CCAnimateWithBlending은 스프라이트 애니메이션에 블렌딩을 적용시킬 수 있도록 해주는 클래스입니다.

```C++
ccBlendFunc blendFunc = {GL_SRC_ALPHA, GL_ONE};

action = CCAnimate::create(
    animation, blendFunc );
```

###CCDestroy
CCDestroy는 대상 오브젝트를 파괴하는 액션입니다.

특정 액션 이후, 또는 지정된 시간 이후에 오브젝트를 파괴해야 할 때 이용할 수 있습니다.
```C++
obj->runAction(
    CCSequence::create(
        CCDelayTime::create( 1 ),
        CCDestroy::create( obj ),
        NULL
    ));
```



###CCCallFuncL
CCCallFuncL은 CCCallFunc액션을 lambda함수와 함께 사용할 수 있도록 해줍니다.
```C++
obj->runAction(
    CCCallFuncL::create( callfuncL_selector(){
        for(int i=0;i<5;i++){
            printf("hello world\n");
        }
    }));
```



###CCParallel
CCParallel은 여러개의 액션들을 동시에 실행할 수 있도록 해줍니다.

아래의 예제에서 CCFadeOut과 CCScaleTo는 동시에 실행됩니다.
```C++
obj->runAction(
    CCParallel::create(
        CCFadeOut::create(1),
        CCScaleTo::create(1, 1.4),
        NULL
    ));
```


###CCDelay
CCDelay는 지정된 시간 이후에 액션을 실행시킵니다.

CCSequence와 CCDelayTime을 조합하여 사용하는것보다 간결하게 코드를 작성할 수 있습니다.
```C++
obj->runAction(
    CCSequence::create(
        CCDelayTime::create(1),
        CCDestroy::create(obj),
        NULL
    ));
```
```C++
obj->runAction(
    CCDelay::create( 1, CCDestroy::create(obj) )
    );
```

Multi-thread
====

###CCMutex
CCMutex는 뮤텍스 객체입니다.
```C++
CCMutex *mutex = CCMutex::create();

mutex->lock();
    // do work
mutex->unlock();
```

###CCSync
CCSync는 쓰레드간에 데이터 동기화를 도와주는 오브젝트입니다.

```C++
foo_thread(){
    if( io() )
        sync->throwObject( IO_OK, data );
    else
        sync->throwObject( IO_ERROR, data );
}

bar_thread(){
    sync->catchObject( IO_OK, catchobject_selector {
            printf("okok\n");
        });
    sync->catchObject( IO_ERROR, catchobject_selector {
            printf("error\n");
        });
}
```


Network
====

###CCHttpClient
CCHttpClient는 비동기로 동작하는 http 클라이언트입니다.

```C++
CCHttpClient *http = CCHttpClient::getInstance();

http->requestGet(
    "http://www.github.com",
    ResponseHandler(int code,string &body){
        printf("response : %d\n", code);
        printf("%s\n", body.c_str());
    });

```

###CCSpriteFromURL
CCSpriteFromURL은 Http 프로토콜을 통해서 다운받은 이미지를 CCSprite로 로드합니다.

```C++
CCSprite *sprite = CCSpriteFromURL::create("http://www.asdf.com/logo.png");
```


Packaging
====

###CCPackage
CCPackage는 여러 리소스 파일들을 하나로 합쳐서 하나의 파일로 만들고 개별적으로 로드할수 있도록 해줍니다.

```C++
CCPackage *pack = CCPackage::create("res.pack");

printf("%s\n", pack->unpack("hello").data_ptr);
CCTexture2D *tex = pack->unpackTexture("a.png");
```


Memory
====

###CCMemory
CCMemory는 CCObject로부터 상속받아 retain counter를 가지고 cocos2d의 autorelease pool에 등록할 수 있는 스마트 포인터입니다.

```C++
CCMemory *mem = CCMemory::create(1024);

mem2 = mem->copy();
```
