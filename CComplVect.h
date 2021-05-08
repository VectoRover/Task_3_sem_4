#pragma once
#include <string>
#include <iostream>
#include "CComplNumb.h"
#include "CFactoryComplVect.h"
#include <vector>
#include <fstream>
using namespace std;

class CComplVect
{
protected:
	vector<CComplNumb> ArrComplNumb;
public:
	CComplVect();
	CComplVect(vector<CComplNumb> ArrComplNumb);
	virtual ~CComplVect();
	vector<CComplNumb> get_ArrComplNumb();
	void set_ArrComplNumb(vector<CComplNumb> ArrComplNumb);
	virtual void show() = 0;
	virtual void output(ofstream& outf) = 0;

	static int Input(string filename, vector<CFactoryComplVect*>& factory, vector<CComplVect*>& w);

	friend class CComplNumb;
};
