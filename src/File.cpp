#include "File.h"

#include <sstream>
#include <fstream>

File::File() : Object()
{
	//code
}

File::~File()
{
	for ( unsigned int i = 0; i < _tags.size();i++ )
	{
		if ( _tags[i] != NULL )
		{
			delete _tags[i];
			_tags[i] = NULL;
		}
	}
}


bool File::load( std::string fileName )
{
	bool success = true;

	std::ifstream file( fileName.c_str() );

	if ( !file )
	{
		std::cerr << "Error: File doesn't exist!" << std::endl;
		success = false;
	}

	std::stringstream stream;

	file2StringStream( file, stream );

	for ( unsigned int i = 0; i < elements().size();i++ )
	{
		success = elements()[i]->read( stream );

		if ( !success )
		{
			file.close();
			break;
		}
	}

	file.close();

	return success;
}

bool File::save( std::string fileName )
{
	bool success = true;

	std::ofstream file( fileName.c_str() );

	if ( !file )
	{
		std::cerr << "Error: Can't create File!" << std::endl;
		success = false;
	}

	std::stringstream stream;

	for ( unsigned int i = 0; i < elements().size(); i++ )
	{
		elements()[i]->write( stream );
	}

	file << stream.str();

	file.close();

	return success;
}

void File::file2StringStream( std::ifstream &in, std::stringstream &out )
{
	while ( !in.eof() )
	{
		std::string s;

		in >> s;


		/*-----------------------------------------
			filter comments
		------------------------------------------*/

		if ( s[0] == '#' )
		{
			getline( in, s );
		}
		else
		{
			out << s << std::endl;
		}
	}
}

void File::addElement( Tag* tag )
{
	elements().push_back( tag );
}

TagVector& File::elements()
{
	return _tags;
}
