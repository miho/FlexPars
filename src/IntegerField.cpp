#include "IntegerField.h"

IntegerField::IntegerField( std::string name, int size ) : Tag( name )
{
	// we have to add at least one element
	if ( size == 0 )
	{
		addElement( new IntegerElement() );
	}
	else
	{
		for ( int i = 0; i < size; i++ )
		{
			addElement( new IntegerElement() );
		}
	}
	// We want to treat each element
	// as seperate line
	_lineSize = 1;
	_numberOfLines = size;
}

IntegerElement* IntegerField::element( int i )
{
	return ( IntegerElement* )elements()[i];
}

bool IntegerField::verify()
{
	return true;
}

