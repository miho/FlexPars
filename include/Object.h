#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>


class Object
{
	public:
		Object();

		void setInitState( bool init );

		void setInitState(bool state) const;
		const bool getInitState() const;

		void checkInitState( std::string function ) const;

	private:
		bool _initialized;
};

#endif /*OBJECT_H*/
