#include "DoubleField.h"

DoubleField::DoubleField( std::string name, int size ) : Tag( name )
{
	// we have to add at least one element
	if ( size == 0 )
	{
		addElement( new DoubleElement() );
	}
	else
	{
		for ( int i = 0; i < size; i++ )
		{
			addElement( new DoubleElement() );
		}
	}
	// We want to treat each element
	// as seperate line
	_lineSize = 1;
	_numberOfLines = size;
}

DoubleElement* DoubleField::element( int i )
{
	return ( DoubleElement* )elements()[i];
}

bool DoubleField::verify()
{
	return true;
}
