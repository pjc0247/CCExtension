#ifndef _CC_DESTROY_H
#define _CC_DESTROY_H

#include <cocos2d.h>
#include <actions/CCAction.h>

NS_CC_BEGIN

/*
	CCDestroy

	�ش� ������Ʈ�� remove/cleanup �ϴ� �׼��Դϴ�.
*/
class CCDestroy : public CCActionInstant //<NSCopying>
{
public:
    CCDestroy()
		: m_pObject( nullptr )
    {
    }
    virtual ~CCDestroy();

	static CCDestroy * create( CCNode *node );

	virtual bool initWithTarget( CCNode *node );
    
    virtual void execute();
    
    virtual void update(float time);

    CCObject * copyWithZone(CCZone *pZone);

protected:    
	CCNode *m_pObject;
};

NS_CC_END

#endif // _CC_DESTROY_H