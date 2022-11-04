#pragma once
#include "Film.h"
#include "Manager.h"
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char asciitolower(char in);
class FilmManager : public Manager<Film>
{
public:
	void findByName(string&);
	Film setFilmInfor();
	void update();
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
private:
};

