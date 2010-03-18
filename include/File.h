#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

#include "Object.h"
#include "Tag.h"
#include "Types.h"

class File : public Object
{
	public:
		File();
		virtual bool load( std::string fileName );
		virtual bool save( std::string fileName );

		void addElement(Tag *tag);

		TagVector& elements();

		~File();

	private:
		TagVector _tags;

		void file2StringStream( std::ifstream &in, std::stringstream &out );

};

#endif /*FILE_H*/
