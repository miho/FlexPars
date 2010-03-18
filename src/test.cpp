#include <iostream>

#include "File.h"
#include "HeaderTag.h"
#include "DoubleField.h"

using namespace std;

int main()
{
	HeaderTag *header = new HeaderTag();
	DoubleField *field = new DoubleField( "data" );

	File f;

	f.addElement( header );
	f.addElement( field );


	//header->setFileType( "Very-Special-File" );
	//header->setVersion( 0.1 );

	//field->element( 0 )->setValue( 32.8 );
	//field->element( 1 )->setValue( 8.45 );
	//field->element( 2 )->setValue( 4.21 );

	//f.save( "./test3.txt" );

	if ( f.load( "./test.txt" ) )
	{
		cout << "File-Type: " << header->getFileType() << endl;
		cout << "Version  : " << header->getVersion() << endl;

		for ( int i = 0; i < field->elements().size(); i++ )
		{
			cout << field->element( i )->getValue() << endl;
		}

		f.save( "./test2.txt" );
	}

	return 0;
}
