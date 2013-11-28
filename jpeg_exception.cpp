#include "jpeg_exception.h"

using namespace std;


jpeg_load_exception::jpeg_load_exception( const char * file,const char * text)
{
	ostringstream oss;
	oss << "Unable to load: "<< file<<". Why: "<<text;
	this->msg = oss.str();
}

jpeg_load_exception::~jpeg_load_exception()
{

}

const char * jpeg_load_exception::what() const 
{
	return this->msg.c_str();
}