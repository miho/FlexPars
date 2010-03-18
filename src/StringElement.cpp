#include "StringElement.h"

StringElement::StringElement( )
{
	setName( "StringElement" );
}

StreamObject* StringElement::getInstance()
{
	return ( StreamObject* )new StringElement( );
}

const std::string StringElement::getValue() const
{
	checkInitState( __PRETTY_FUNCTION__ );

	return _value;
}

void StringElement::setValue( std::string value )
{
	_value = value;
	setInitState( true );
}

bool StringElement::read( std::stringstream &f )
{
	/*-----------------------------------------
		   Read string
	------------------------------------------*/

	std::string tmpStr;

	f >> tmpStr;

	_value = tmpStr;

	setInitState( true );

	return true;

}

void StringElement::write( std::stringstream &f )
{
	f << getValue();
}
