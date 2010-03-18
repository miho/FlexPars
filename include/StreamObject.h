#ifndef STREAMOBJECT_H
#define STREAMOBJECT_H

#include <iostream>
#include <sstream>

#include "Object.h"

#include <stdio.h>
#include <stdlib.h>

class StreamObject : public Object
{
	public:
		StreamObject();
		virtual void write( std::stringstream &f ){};
		virtual bool read( std::stringstream &f ){};

		virtual StreamObject* getInstance() = 0;

		void setOffset( int offset );

		const int getOffset() const;

		std::string getName();
		std::string getParentName();

		void setParent( StreamObject *parent );
		StreamObject* getParent();

	protected:
		void setName( std::string name );
	private:
		std::string _name;
		int _offset;
		StreamObject *_parent;
};

#endif /*STREAMOBJECT_H*/
