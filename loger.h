#ifndef LOGER_H
#define LOGER_H
#include <iostream>
#include <string>
#include <vector>

class Loger
{
public:
	static Loger *getInstance ();
	static void kill ();
	void Append(std::string line);

	void SetDebug(bool _debug) {
		this->_debug = _debug;
	}

	std::string GetLine(int num);
	int GetNbLine();
private:
	Loger();
	~Loger();
	static Loger *_singleton;
	bool _debug;
	std::vector<std::string> _output;
};

#endif // LOGER_H
