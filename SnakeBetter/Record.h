#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Record {
public:
	Record();
	void SetRecord(int);
	int GetRecord();
private:
	std::string path;
};
