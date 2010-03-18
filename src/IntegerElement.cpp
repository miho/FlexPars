#include "IntegerElement.h"

IntegerElement::IntegerElement( )
{
	setName( "IntegerElement" );
}

StreamObject* IntegerElement::getInstance()
{
	StreamObject *tmpObj = ( StreamObject* )new IntegerElement( );

	tmpObj->setParent( getParent() );

	return tmpObj;
}

const int IntegerElement::getValue() const
{
	checkInitState( __PRETTY_FUNCTION__ );

	return _value;
}

void IntegerElement::setValue( int value )
{
	_value = value;
	setInitState( true );
}

bool IntegerElement::read( std::stringstream &f )
{
	/*-----------------------------------------
		   Read integer number
	------------------------------------------*/

	std::string tmpStr;
	f >> tmpStr;

	int tmpVal = atoi( tmpStr.c_str() );
	double tmpVal2 =  atof( tmpStr.c_str() );

	if (( tmpStr != "0" ) && ( tmpVal == 0 ) )
	{
		std::cerr << "Error (IntegerElement): Entry " << getOffset() + 1 << " in \"<"
		<< getParentName() << "></" << getParentName() << ">\" - Section is not a valid integer number!\n";
		return false;
	}

	if (( double )tmpVal != tmpVal2 )
	{
		std::cerr << "Error (IntegerElement): Entry " << getOffset() + 1 << " in \"<"
		<< getParentName() << "></" << getParentName() << ">\" - Section is a floating point number!\n";
		return false;
	}
	_value = tmpVal;

	setInitState( true );

	return true;

}

void IntegerElement::write( std::stringstream &f )
{
	f << getValue();
}

