#ifndef INTEGERFIELD_H
#define INTEGERFIELD_H

#include <string>

#include "Tag.h"
#include "IntegerElement.h"

class IntegerField : public Tag
{
	public:
		IntegerField( std::string name, int size = 0 );
		IntegerElement* element( int i );
		virtual bool verify();
};

#endif /*INTEGERFIELD_H*/
