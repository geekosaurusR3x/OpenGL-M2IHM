#include "terminal.h"

using namespace std;

Terminal::Terminal()
{
	this->mylog = Loger::getInstance();
	this->fps = 0;
	this->_beforeLine = 0;
	this->_nblinedisplay = 10;
	this->_cmd = "";
}

Terminal::~Terminal()
{
}

void Terminal::Draw()
{
	//display the fps
	WriteLine(2,2,"FPS : "+to_string(this->fps),GLUT_BITMAP_9_BY_15);
	//display the cmd
	WriteLine(2,18,"Input : "+_cmd,GLUT_BITMAP_9_BY_15);
	//display the log
	int start_number = this->mylog->GetNbLine()+this->_beforeLine;
	cout<<this->mylog->GetNbLine()<<" "<<this->_beforeLine<<endl;
	int h = 2;
    for ( int i = start_number ; i > start_number-this->_nblinedisplay && i > 0; i--)
    {
		h++;
		WriteLine(2,h*15,"> "+this->mylog->GetLine(i-1),GLUT_BITMAP_9_BY_15);
    }

	
}

void Terminal::WriteLine(int x,int y,std::string string,void *font)
{
  glRasterPos2f(x,y);
  for (int i = 0; i < (int)string.length(); i++) {
    glutBitmapCharacter(font,string[i]); }
}

void Terminal::NextLine()
{
	this->_beforeLine++;
	if(this->_beforeLine>0)
	{
		this->_beforeLine = 0;
	}
}

void Terminal::PreviousLine()
{
	this->_beforeLine--;
	if(this->mylog->GetNbLine()+this->_beforeLine<this->_nblinedisplay)
	{
		this->_beforeLine = -(this->mylog->GetNbLine()-this->_nblinedisplay);
	}
}

void Terminal::Append(std::string input)
{
	this->_cmd+=input;
}

void Terminal::Remove()
{
	if(this->_cmd.length()>0)
	{
		this->_cmd.pop_back();
	}
}

std::string Terminal::Validate()
{
	this->mylog->Append(this->_cmd);
	string temp = this->_cmd;
	this->_cmd = "";
	return temp;
}
