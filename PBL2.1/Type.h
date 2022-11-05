#ifndef TYPE_H
#define TYPE_H
#include <iostream>

using namespace std;

class Type
{
public:
	Type();
    string* getType();
	string getType(int);
private:
	string type[20];
};

#endif
