#include "Object.h"

Object::Object()
{
	_initialized = false;
}

void Object::setInitState( bool state)
{
	_initialized=state;
}

const bool Object::getInitState() const
{
	return _initialized;
}

void Object::checkInitState( std::string function ) const
{
	if ( getInitState() == false)
	{
		std::cerr << function << "\n>> OBJ not initialized!\n";
	}
}
