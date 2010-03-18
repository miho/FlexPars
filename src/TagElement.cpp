#include "TagElement.h"

std::string TagElement::getTagName()
{
	//checkInitState(__PRETTY_FUNCTION__);
	return _tagName;
}

void TagElement::setTagName( std::string tagName )
{
	_tagName = tagName;
}
