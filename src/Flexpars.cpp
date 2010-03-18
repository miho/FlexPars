#include <iostream>

bool NNet::readHeaderSection( ifstream &f, vector <string> &headerList )
{
	/*-----------------------------------------
		  Read Header Information
	------------------------------------------*/

	while ( !f.eof() )
	{
		string tmpStr;
		f >> tmpStr;
		headerList.push_back( tmpStr );
		if ( tmpStr == "</header>" ) break;
	}

	/*-----------------------------------------
	   Error Handling for Header Information
	------------------------------------------*/

	if ( headerList[ 0 ] != "<header>" )
	{
		cerr << "Error: Unknown file format!" << endl;
		return false;
	}

	if ( headerList[ headerList.size() - 1 ] != "</header>" )
	{
		cerr << "Error: Missing </header>!" << endl;
		return false;
	}

	if ( headerList[ 1 ] != "#NNet-File" )
	{
		cerr << "Error: Unknown file format!" << endl;
		return false;
	}

	if ( atof( headerList[ 2 ].c_str() ) == 0 )
	{
		cerr << "Error: Can't verify version of file format!" << endl;
		return false;
	}
	else
	{
		if ( atof( headerList[ 2 ].c_str() ) > 0.1 )
		{
			cerr << "Error: File is made by newer version of this program!" << endl;
			return false;
		}
	}
	return true;
}

bool NNet::readInputSection( ifstream &f )
{
	vector <string> inputStrList;
	/*-----------------------------------------
		   Read Input-Cell Indices
	------------------------------------------*/

	while ( !f.eof() )
	{
		string tmpStr;
		f >> tmpStr;
		inputStrList.push_back( tmpStr );
		if ( tmpStr == "</inputs>" ) break;
	}


	if ( inputStrList[ 0 ] != "<inputs>" )
	{
		cerr << "Error: Input section missing!" << endl;
		return false;
	}

	if ( inputStrList[ inputStrList.size() - 1 ] != "</inputs>" )
	{
		cerr << "Error: Missing </inputs>!" << endl;
		return false;
	}

	for ( unsigned int i = 1;i < inputStrList.size() - 1;i++ )
	{
		int tmpVal = atoi( inputStrList[ i ].c_str() );
		if ( ( inputStrList[ i ] != "0" ) && ( tmpVal == 0 ) )
		{
			cerr << "Error: Entry " << i << " in \"<inputs> </inputs>\" - Section is not a valid integer number!" << endl;
			return false;
		}
		inputList.push_back( tmpVal );
	}

	return true;
}

bool NNet::readOutputSection( ifstream &f )
{
	vector <string> outputStrList;

	/*-----------------------------------------
		   Read Output-Cell Indices
	------------------------------------------*/

	while ( !f.eof() )
	{
		string tmpStr;
		f >> tmpStr;
		outputStrList.push_back( tmpStr );
		if ( tmpStr == "</outputs>" ) break;
	}


	if ( outputStrList[ 0 ] != "<outputs>" )
	{
		cerr << "Error: Output section missing!" << endl;
		return false;
	}
	if ( outputStrList[ outputStrList.size() - 1 ] != "</outputs>" )
	{
		cerr << "Error: Missing </outputs>!" << endl;
		return false;
	}

	for ( unsigned int i = 1;i < outputStrList.size() - 1;i++ )
	{
		int tmpVal = atoi( outputStrList[ i ].c_str() );
		if ( ( outputStrList[ i ] != "0" ) && ( tmpVal == 0 ) )
		{
			cerr << "Error: Entry " << i << " in \"<outputs> </outputs>\" - Section is not a valid integer number!" << endl;
			return false;
		}
		outputList.push_back( tmpVal );
	}

	return true;
}

bool NNet::readConnectionSection( ifstream &f )
{
	vector <string> connectionStrList;
	/*-----------------------------------------
		Read Connection Information
	------------------------------------------*/

	while ( !f.eof() )
	{
		string tmpStr;
		f >> tmpStr;
		if ( tmpStr[ 0 ] == '#' )
		{
			getline( f, tmpStr );
		}
		else
		{
			connectionStrList.push_back( tmpStr );
		}
		if ( tmpStr == "</connections>" ) break;
	}

	if ( connectionStrList[ 0 ] != "<connections>" )
	{
		cerr << "Error: Connections section missing!" << endl;
		return false;
	}
	if ( connectionStrList[ connectionStrList.size() - 1 ] != "</connections>" )
	{
		cerr << "Error: Missing </connections>!" << endl;
		return false;
	}

	/*--------------------------------------------
		Convert connectionList to
		netList

		Start with i = 1 because first
		entry is <connections> tag.

		Stop with < connectionList.size() - 2
		because size is one too much and
		last entry is </conections> tag.

		This concerns also most of the
		following for-loops
	----------------------------------------------*/

	if ( ( connectionStrList.size() - 2 ) % 3 != 0 )
	{
		cerr << "Error: Wrong number of Entries in \"<connections> </connections>\" - Section!" << endl;
		return false;
	}

	for ( unsigned int i = 1;i < connectionStrList.size() - 2;i += 3 )
	{
		int tmpVal = atoi( connectionStrList[ i ].c_str() );
		if ( ( connectionStrList[ i ] != "0" ) && ( tmpVal == 0 ) )
		{
			cerr << "Error: Entry " << i << " in \"<connections> </connections>\" - Section is not a valid integer number!" << endl;
			return false;

		}
		tmpVal = atoi( connectionStrList[ i + 1 ].c_str() );
		if ( ( connectionStrList[ i + 1 ] != "0" ) && ( tmpVal == 0 ) )
		{
			cerr << "Error: Entry " << i + 1 << " in \"<connections> </connections>\" - Section is not a valid integer number!" << endl;
			return false;
		}
		double tmpVal2 = atof( connectionStrList[ i + 2 ].c_str() );
		if ( ( connectionStrList[ i + 2 ] != "0" ) && ( tmpVal2 == 0 ) )
		{
			cerr << "Error: Entry " << i + 2 << " in \"<connections> </connections>\" - Section is not a valid floating point number!" << endl;
			return false;
		}

		// 		netConnection tmpConnection;
		// 		tmpConnection(connectionStrList[ i ],connectionStrList[ i + 1 ],connectionStrList[ i + 2 ]);
		connectionList.push_back( netConnection( connectionStrList[ i ], connectionStrList[ i + 1 ], connectionStrList[ i + 2 ] ) );
	}

	return true;
}

bool NNet::loadNet( string fileName )
{
	// List with header informations
	vector <string> headerList;

	// The file stream
	ifstream f( fileName.c_str() );

	if ( !f )
	{
		cerr << "Error: File doesn't exist!" << endl;
		return false;
	};

	if ( !this->readHeaderSection( f, headerList ) ) return false;

	if ( !this->readInputSection( f ) ) return false;

	if ( !this->readOutputSection( f ) ) return false;

	if ( !this->readConnectionSection( f ) ) return false;

	f.close();

	generateNet( inputList, outputList, connectionList );

	return true;
}

void NNet::writeHeaderSection( ofstream &f, double version ) const
{
	/*-----------------------------------------
		  Write Header-Section
	------------------------------------------*/

	f << "<header>\n";
	f << "#NNet-File " << version;
	f << "\n</header>\n";

}

void NNet::writeInputSection( ofstream &f ) const
{
	/*-----------------------------------------
		  Write Input-Section
	------------------------------------------*/

	f << "<inputs>\n";

	for ( unsigned int i = 0;i < this->inputList.size();i++ )
	{
		f << this->inputList[ i ] << " ";
	}

	f << "\n</inputs>\n";

}

void NNet::writeOutputSection( ofstream &f ) const
{
	/*-----------------------------------------
		  Write Output-Section
	------------------------------------------*/

	f << "<outputs>\n";

	for ( unsigned int i = 0;i < this->outputList.size();i++ )
	{
		f << this->outputList[ i ] << " ";
	}

	f << "\n</outputs>\n";
}

void NNet::writeConnectionSection( ofstream &f ) const
{
	/*-----------------------------------------
		  Write Connection-Section
	------------------------------------------*/

	f << "<connections>\n";

	int weightIndex = 0;
	int senderTmp = 0;

	for ( unsigned int i = 0;i < this->connectionList.size();i++ )
	{
		int sender = this->connectionList[ i ].sender;
		int receiver = this->connectionList[ i ].receiver;

		if ( senderTmp != sender )
		{
			weightIndex = 0;
			senderTmp = sender;
		}

		f << sender << " " << receiver
		<< " " << this->allCells[ sender ] ->weights[ weightIndex ] << endl;

// 		cout << sender << " " << receiver
// 		<< " " << this->allCells[ sender ] ->weights[ weightIndex ] << endl;

		weightIndex++;
	}

	f << "</connections>\n";
}

bool NNet::saveNet( string fileName )
{

	// The file stream
	ofstream f( fileName.c_str(), ios::out );

	this->writeHeaderSection( f, 0.1 );
	this->writeInputSection( f );
	this->writeOutputSection( f );
	this->writeConnectionSection( f );

	f.close();

	return true;
}

