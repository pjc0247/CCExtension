#include "CCParallel.h"

#include <varargs.h>

using namespace cocos2d;
using namespace std;

CCParallel * CCParallel::create(CCAction *action1, ...){
	va_list params;
    va_start(params, action1);

    CCParallel *pRet = new CCParallel();
	if (pRet && pRet->initWithActions( action1, params )) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);

	va_end( params );

    return NULL;
}

bool CCParallel::initWithActions(CCAction *action1, va_list params) {
	m_pArray.clear();

	action1->retain();
	m_pArray.push_back( action1 );

	while(true){
		CCAction *action;

		action = va_arg(params, CCAction*);
		if( action == NULL )
			break;

		action->retain();
		m_pArray.push_back( action );
	}
	
    return true;
}
bool CCParallel::initWithArray(std::vector<CCAction*> &ary) {
	m_pArray = ary;

    return true;
}

CCParallel::~CCParallel(void){
}

CCObject * CCParallel::copyWithZone(CCZone *pZone) {
    CCZone* pNewZone = NULL;
    CCParallel* pRet = NULL;

    if (pZone && pZone->m_pCopyObject) {
        pRet = (CCParallel*) (pZone->m_pCopyObject);
    } else {
        pRet = new CCParallel();
        pZone = pNewZone = new CCZone(pRet);
    }

    CCActionInstant::copyWithZone(pZone);
	pRet->initWithArray( m_pArray );
    CC_SAFE_DELETE(pNewZone);
    return pRet;
}

void CCParallel::update(float time) {
    CC_UNUSED_PARAM(time);
    this->execute();
}

void CCParallel::execute() {
	for each(auto action in m_pArray){
		m_pTarget->runAction(
			action);
	}
}