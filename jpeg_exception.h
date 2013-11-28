#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H

#include <iostream>
#include <sstream>
#include <exception>

class jpeg_load_exception
{
public:
	jpeg_load_exception(const char * file,const char * text);
	~jpeg_load_exception();
	const char * what() const;

private:
    std::string msg;
};

#endif // FILE_EXCEPTION_H
