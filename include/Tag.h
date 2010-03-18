#ifndef TAG_H
#define TAG_H

#include "Types.h"
#include "StreamObject.h"

class Tag : public StreamObject
{
	public:
		Tag();
		Tag( std::string tagName );

		virtual StreamObject* getInstance(){};

		virtual void write( std::stringstream &f );
		virtual bool read( std::stringstream &f );

		void addElement( StreamObject *element );

		StreamObjectVector& elements();

		const int lineSize() const;

		virtual bool verify() = 0;


		~Tag();
	protected:
		int _numberOfLines;
		int _lineSize;

	private:
		std::vector<StreamObject*> _streamObjects;

		bool getOpenTag( std::stringstream &f );
		bool getCloseTag( std::string &s );
};



#endif /*TAG_H*/
