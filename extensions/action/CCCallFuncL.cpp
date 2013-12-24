#include "CCCallFuncL.h"

using namespace cocos2d;
using namespace std;

CCCallFuncL * CCCallFuncL::create( SEL_CallFuncL f ){
    CCCallFuncL *pRet = new CCCallFuncL();
	if (pRet && pRet->initWithFunction(f)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool CCCallFuncL::initWithFunction( SEL_CallFuncL f ) {
	this->m_pFunc = f;
    return true;
}

CCCallFuncL::~CCCallFuncL(void){
}

CCObject * CCCallFuncL::copyWithZone(CCZone *pZone) {
    CCZone* pNewZone = NULL;
    CCCallFuncL* pRet = NULL;

    if (pZone && pZone->m_pCopyObject) {
        pRet = (CCCallFuncL*) (pZone->m_pCopyObject);
    } else {
        pRet = new CCCallFuncL();
        pZone = pNewZone = new CCZone(pRet);
    }

    CCActionInstant::copyWithZone(pZone);
	pRet->initWithFunction( m_pFunc );
    CC_SAFE_DELETE(pNewZone);
    return pRet;
}

void CCCallFuncL::update(float time) {
    CC_UNUSED_PARAM(time);
    this->execute();
}

void CCCallFuncL::execute() {
	if( m_pFunc != nullptr ){
		m_pFunc();
	}
}