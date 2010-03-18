#include "DoubleElement.h"

DoubleElement::DoubleElement( )
{
	setName( "DoubleElement" );
}

StreamObject* DoubleElement::getInstance()
{
	StreamObject *tmpObj = ( StreamObject* )new DoubleElement( );

	tmpObj->setParent( getParent() );

	return tmpObj;
}

const double DoubleElement::getValue() const
{
	checkInitState( __PRETTY_FUNCTION__ );

	return _value;
}

void DoubleElement::setValue( double value )
{
	_value = value;
	setInitState( true );
}

bool DoubleElement::read( std::stringstream &f )
{
	/*-----------------------------------------
		   Read real number
	------------------------------------------*/
	std::string tmpStr;
	f >> tmpStr;


	double tmpVal = atof( tmpStr.c_str() );
	if (( tmpStr != "0" ) && ( tmpVal == 0 ) )
	{
		std::cerr << "Error (DoubleElement): Entry " << getOffset() + 1 << " in \"<"
		<< getParentName() << "></" << getParentName() << ">\" - Section is not a valid double number!\n";
		return false;
	}
	_value = tmpVal;

	setInitState( true );

	return true;

}

void DoubleElement::write( std::stringstream &f )
{
	f << getValue();
}
