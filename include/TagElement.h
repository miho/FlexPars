#ifndef TAGELEMENT_H
#define TAGELEMENT_H

#include <string>

#include "Object.h"

class TagElement
{
	public:
		std::string getTagName();
		void setTagName( std::string );
	private:
		std::string _tagName;
};

#endif /*TAGELEMENT_H*/
