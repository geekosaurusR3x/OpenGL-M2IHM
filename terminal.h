#ifndef TERMINAL_H
#define TERMINAL_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string>
#include "loger.h"

class Terminal
{
public:
	Terminal();
	~Terminal();

	void SetFps(int fps) {
		this->fps = fps;
	}
	void Draw();
	void PreviousLine();
	void NextLine();
	void Append(std::string input);
	void Remove();
	std::string Validate();
	void WriteLine(int x,int y,std::string string,void *font);
private:
	int fps;
	Loger *mylog;
	int _beforeLine;
	int _nblinedisplay;
	std::string _cmd;
};

#endif // TERMINAL_H
