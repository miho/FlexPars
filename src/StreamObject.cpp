#include "StreamObject.h"

StreamObject::StreamObject()
{
	_offset = 0;
	_name = "";
	_parent = NULL;

	//std::cout << "StreamObject!" << std::endl;
}

std::string StreamObject::getParentName()
{
	if ( getParent() == NULL )
	{
		return std::string("");
	}

	return getParent()->getName();
}

void StreamObject::setParent(StreamObject *parent)
{
	_parent = parent;
}

StreamObject* StreamObject::getParent()
{
	//checkInitState(__PRETTY_FUNCTION__);
	
	if ( _parent == NULL )
	{
		std::cerr << __PRETTY_FUNCTION__ << "\n>> no parent defined!\n"; 
	}
	
	return _parent;
}

void StreamObject::setOffset( int offset )
{
	_offset = offset;
}

const int StreamObject::getOffset() const
{
	return _offset;
}

std::string StreamObject::getName()
{
	return _name;
}

void StreamObject::setName( std::string name )
{
	_name = name;
}

//StreamObject* StreamObject::getInstance()
//{
//        std::cerr << "Error: " << __PRETTY_FUNCTION__ << " not implemented!" << std::endl;
//        return NULL;
//}
