#ifndef _CC_PARALLEL_H
#define _CC_PARALLEL_H

#include <cocos2d.h>
#include <actions/CCAction.h>

#include <vector>
#include <varargs.h>

NS_CC_BEGIN

/*
	CCParallel
	
	�������� �׼��� ���ÿ� ��������ִ� �׼��Դϴ�.
*/
class CCParallel : public CCActionInstant //<NSCopying>
{
public:
    CCParallel()
    {
    }
    virtual ~CCParallel();

	static CCParallel * create( CCAction *action1, ... );

	virtual bool initWithActions( CCAction *action1, va_list params );
	virtual bool initWithArray( std::vector<CCAction*> &ary );
    
    virtual void execute();
    
    virtual void update(float time);

    CCObject * copyWithZone(CCZone *pZone);

protected:
	std::vector<CCAction*> m_pArray;
};

NS_CC_END

#endif // _CC_PARALLEL_H