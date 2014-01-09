#include "CCMemory.h"

using namespace cocos2d;

CCMemory::~CCMemory(){
	CC_SAFE_DELETE( ptr );
	size = 0;
}

CCMemory *CCMemory::create(size_t size){
	CCMemory *m = new CCMemory();

	if( m != NULL && m->init(size) ){
		m->autorelease();
		return m;
	}

	CC_SAFE_DELETE(m);
	return NULL;
}
bool CCMemory::init(size_t _size){
	size = _size;
	ptr = malloc(size);

	if( ptr == NULL )
		return false;

	return true;
}

CCMemory::operator void*(){
	return ptr;
}
void *CCMemory::getPtr(){
	return ptr;
}

CCMemory *CCMemory::copy(){
	CCMemory *m = CCMemory::create(size);

	if( m != NULL ){
		memcpy( m, this, size );
		return m;
	}
	return NULL;
}