#ifndef HEADERTAG_H
#define HEADERTAG_H

#include <string>

#include "Tag.h"
#include "StringElement.h"
#include "IntegerElement.h"
#include "DoubleElement.h"

class HeaderTag : public Tag
{
	public:
		HeaderTag();
		void setFileType( std::string name );
		void setVersion( double value );
		std::string getFileType();
		double getVersion();

		virtual bool verify();

	private:
		StringElement *_fileType;
		DoubleElement *_version;
};

#endif /*HEADERTAG_H*/
