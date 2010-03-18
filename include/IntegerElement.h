#ifndef INTEGERELEMENT_H
#define INTEGERELEMENT_H

#include "StreamObject.h"

class IntegerElement : public StreamObject
{
	public:
		IntegerElement( );

		virtual StreamObject* getInstance();

		void write( std::stringstream &f );
		bool read( std::stringstream &f );

		const int getValue( ) const;
		void setValue(int value);
	private:
		int _value;
};

#endif /*INTEGERELEMENT_H*/
