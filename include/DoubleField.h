#ifndef DOUBLEFIELD_H
#define DOUBLEFIELD_H

#include <string>

#include "Tag.h"
#include "DoubleElement.h"

class DoubleField : public Tag
{
	public:
		DoubleField( std::string name, int size = 0 );
		DoubleElement* element( int i );
		virtual bool verify();
};

#endif /*DOUBLEFIELD_H*/
