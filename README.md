CCExtension
===========

cocos2d-x extension


Utility
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

Action
====

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
    CCCallFuncL::create( callfuncL_selector{
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
