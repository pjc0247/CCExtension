#ifndef _CC_CALLFUNC_L_H
#define _CC_CALLFUNC_L_H

#include <cocos2d.h>
#include <actions/CCAction.h>

#include <functional>

NS_CC_BEGIN

typedef std::function<void()> SEL_CallFuncL;

#define callfuncL_selector [=]

/*
	CCCallFuncL

	lambda�Լ��� �����ϴ� CCCallFunc �׼��Դϴ�.
*/
class CCCallFuncL : public CCActionInstant //<NSCopying>
{
public:
    CCCallFuncL()
		: m_pFunc( nullptr )
    {
    }
    virtual ~CCCallFuncL();

	static CCCallFuncL * create( SEL_CallFuncL f );

	virtual bool initWithFunction( SEL_CallFuncL f );
    
    virtual void execute();
    
    virtual void update(float time);

    CCObject * copyWithZone(CCZone *pZone);

protected:    
	SEL_CallFuncL m_pFunc;
};

NS_CC_END

#endif // _CC_CALLFUNC_L_H
