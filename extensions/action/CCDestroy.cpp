#include "CCDestroy.h"

using namespace cocos2d;

CCDestroy * CCDestroy::create( CCNode *node ){
    CCDestroy *pRet = new CCDestroy();
	if (pRet && pRet->initWithTarget(node)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool CCDestroy::initWithTarget( CCNode *node ) {
	this->m_pObject = node;
    return true;
}

CCDestroy::~CCDestroy(void){
}

CCObject * CCDestroy::copyWithZone(CCZone *pZone) {
    CCZone* pNewZone = NULL;
    CCDestroy* pRet = NULL;

    if (pZone && pZone->m_pCopyObject) {
        pRet = (CCDestroy*) (pZone->m_pCopyObject);
    } else {
        pRet = new CCDestroy();
        pZone = pNewZone = new CCZone(pRet);
    }

    CCActionInstant::copyWithZone(pZone);
	pRet->initWithTarget(this->m_pObject);
    CC_SAFE_DELETE(pNewZone);
    return pRet;
}

void CCDestroy::update(float time) {
    CC_UNUSED_PARAM(time);
    this->execute();
}

void CCDestroy::execute() {
	if( m_pObject != nullptr ){
		m_pObject->getParent()->removeChild( m_pObject, true );
		m_pObject = nullptr;
	}
}