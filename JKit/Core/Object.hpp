#ifndef __JKIT__CORE__OBJECT_HPP__
#define __JKIT__CORE__OBJECT_HPP__

#include <JKit/Core/ObjectProperty.hpp>

namespace J {


class ObjectClass
{
public:
	const String& name() const;
};


class Object
{
public:
	static Object* create(ObjectClass& type);
	ObjectClass& type() const;
};


}

#endif
