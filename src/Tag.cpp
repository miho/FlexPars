#include "Tag.h"

Tag::Tag()
{
	_lineSize = 0;
	_numberOfLines = 0;
	setInitState( true );
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Tag::Tag( std::string tagName )
{
	setName( tagName );
	_lineSize = 0;
	_numberOfLines = 0;
	setInitState( true );
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

}

Tag::~Tag()
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	for ( unsigned int i = 0; i < _streamObjects.size();i++ )
	{
		if ( _streamObjects[i] != NULL )
		{
			delete _streamObjects[i];
			_streamObjects[i] = NULL;
		}
	}
}

const int Tag::lineSize() const
{
	return _lineSize;
}

void Tag::addElement( StreamObject *element )
{
	_lineSize++;
	element->setParent( this );
	_streamObjects.push_back( element );
}

void Tag::write( std::stringstream &f )
{
	f << "<" << getName() << ">" << std::endl;

	for ( unsigned int i = 0; i < _streamObjects.size(); i++ )
	{
		_streamObjects[i]->write( f );

		f << " ";

		if (( i + 1 ) % lineSize()  == 0 )
		{
			f << std::endl;
		}
	}

	f << "</" << getName() << ">" << std::endl;
}

bool Tag::getOpenTag( std::stringstream &f )
{
	std::string s;

	f >> s;


	bool success = true;

	std::stringstream stream;

	stream << "<" << getName() << ">";

	if ( stream.str() != s )
	{
		success = false;
	}

	if ( !success )
	{
		std::cerr << "Syntax error: \"<" << getName() << ">\" expected." << std::endl;
	}

	return success;
}

bool Tag::getCloseTag( std::string &s )
{
	bool success = true;

	std::stringstream stream;

	stream << "</" << getName() << ">";

	if ( s != stream.str() )
	{
		//std::cerr << "Syntax error: \"</" << getName() << ">\" expected." << std::endl;
		success = false;
	}

	return success;
}

bool Tag::read( std::stringstream &f )
{
	bool success = true;

	_numberOfLines = 0;

	success = getOpenTag( f );

	int numberOfElements = 0;

	std::stringstream stream;

	while ( ! f.eof() )
	{
		std::string s;
		f >> s;
		if ( getCloseTag( s ) )
		{
			break;
		}
		else
		{
			if (( s[0] == '<' ) && ( s[s.size()-1] == '>' ) || f.eof() )
			{
				if ( s != stream.str() )
				{
					std::cerr << "Syntax error: \"</" << getName() << ">\" missing." << std::endl;
					success = false;
					break;
				}
			}
			else
			{
				stream << s << std::endl;
				numberOfElements++;
			}
		}
	}

	if ( success )
	{
		if ( numberOfElements % lineSize() == 0 )
		{
			_numberOfLines = numberOfElements / lineSize();
		}
		else
		{
			std::cerr << "Syntax error: wrong number of elements in \"<" << getName() << ">\"-Tag." << std::endl;
			success = false;
		}
	}

	if ( success )
	{

		int offset = 0;

		for ( int j = 1; j < _numberOfLines; j++ )
		{
			for ( int i = 0; i < lineSize();i++ )
			{
				StreamObject *obj = elements()[i]->getInstance();

				offset = lineSize() * j;

				obj->setOffset( offset + i );

				elements().push_back( obj );
			}
		}

		for ( unsigned int i = 0; i < elements().size(); i++ )
		{
			if ( success )
			{
				success = _streamObjects[i]->read( stream );
			}
			else
			{
				break;
			}
		}
	}

	if ( success )
	{
		success = verify();
	}

	if ( success )
	{
		setInitState( true );
	}

	return success;
}

StreamObjectVector& Tag::elements()
{
	return _streamObjects;
}

