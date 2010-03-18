#ifndef DOUBLEELEMENT_H
#define DOUBLEELEMENT_H

#include "StreamObject.h"

class DoubleElement : public StreamObject
{
	public:
		DoubleElement();

		virtual StreamObject* getInstance();

		void write( std::stringstream &f );
		bool read( std::stringstream &f );

		const double getValue( ) const;
		void setValue( double value);

	private:
		double _value;
};

#endif /*DOUBLEELEMENT_H*/
