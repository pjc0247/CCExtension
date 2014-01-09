#ifndef _CC_MEMORY_H
#define _CC_MERMOY_H

#include <cocos2d.h>

NS_CC_BEGIN

class CCMemory : public CCObject{
public:
	virtual ~CCMemory();

	static CCMemory *create(size_t size);
	virtual bool init(size_t size);

	CCMemory *copy();

	void *getPtr();

	operator void*();
protected:
	void *ptr;
	size_t size;
};

NS_CC_END

#endif // _CC_MEMORY_H	