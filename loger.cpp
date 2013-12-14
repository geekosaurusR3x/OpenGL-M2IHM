#include "loger.h"

using namespace std;
Loger::Loger()
{
	_debug = false;
}

Loger::~Loger()
{
}

Loger* Loger::getInstance()
{
	if (NULL == _singleton)
      {
        _singleton =  new Loger;
      }
    return _singleton;
}

void Loger::kill()
{
	 if (NULL != _singleton)
      {
        delete _singleton;
        _singleton = NULL;
      }
}

void Loger::Append(std::string line)
{
	this->_output.push_back(line);
	if(_debug){cout<<line<<endl;}
}

std::string Loger::GetLine(int num)
{
	return _output[num];
}

int Loger::GetNbLine()
{
	return _output.size();
}

Loger *Loger::_singleton = NULL;
