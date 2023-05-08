#pragma once

#ifndef Dialogue.h
#include <iostream>
#include <string>
#include <fstream>
#endif // !Dialogue.h

using std::string;
using std::ifstream;

class Dialogue
{
private:
	string text;
	string path;
public:
	Dialogue(string path);

	string ReadDialogue();
};

