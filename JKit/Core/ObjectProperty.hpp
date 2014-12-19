#ifndef __JKIT__CORE__OBJECT_PROPERTY_HPP__
#define __JKIT__CORE__OBJECT_PROPERTY_HPP__

#include <JKit/Core/String.hpp>

namespace J {


class ObjectProperty
{
public:
	inline const String& name() const
		{ return m_Name; }

private:
	String m_Name;
};


}

#endif
