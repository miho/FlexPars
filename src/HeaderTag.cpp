#include "HeaderTag.h"

HeaderTag::HeaderTag() : Tag( "header" )
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	_fileType = new StringElement();
	_version = new DoubleElement();
	addElement( _fileType );
	addElement( _version );

}


void HeaderTag::setFileType( std::string name )
{
	_fileType->setValue( name );
}

void HeaderTag::setVersion( double value )
{
	_version->setValue( value );
}

std::string HeaderTag::getFileType()
{
	return _fileType->getValue();
}

double HeaderTag::getVersion()
{
	return _version->getValue();
}

bool HeaderTag::verify()
{
	if (elements().size() > 2)
	{
		std::cerr << "Error: (HeaderTag): too many entries!" << std::endl;
		return false;
	}

	return true;
}
