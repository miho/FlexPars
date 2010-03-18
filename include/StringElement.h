#ifndef STRING_H
#define STRING_H

#include "StreamObject.h"

class StringElement : public StreamObject
{
	public:
		StringElement( );

		virtual StreamObject* getInstance();

		void write( std::stringstream &f );
		bool read( std::stringstream &f );

		const std::string getValue( ) const;
		void setValue( std::string value );
	private:
		std::string _value;
};

#endif /*STRING_H*/
