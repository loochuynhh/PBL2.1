#pragma once
#include "Film.h"
#include "Manager.h"
#include <string>

using namespace std;

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

