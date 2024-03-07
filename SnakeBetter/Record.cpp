#include "Record.h"

Record::Record() {
	path = "record.txt";
}

int Record::GetRecord() {
	std::ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		std::string record;
		if (!fin.eof()) {
			fin >> record;
		}
		return std::stoi(record);
	}
	return 0;
}

void Record::SetRecord(int curRec) {
	std::ofstream fout;
	int absRec = GetRecord();
	if (curRec > absRec) {
		fout.open(path);
		if (fout.is_open()) {
			fout << curRec;
		}
		fout.close();
	}
}