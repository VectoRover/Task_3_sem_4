#pragma once
#include <string>
#include <iostream>
#include "CComplNumb.h"
#include "CComplVect.h"
using namespace std;

class CComplVectVert : public CComplVect
{
public:
	CComplVectVert();
	CComplVectVert(vector<CComplNumb> ArrComplNumb);
	~CComplVectVert() override;

	CComplVectVert& operator=(const CComplVectVert& b);
	CComplVectVert operator+(const CComplVectVert& b);
	CComplVectVert operator-(const CComplVectVert& b);
	CComplNumb operator*(CComplVectVert& b);
	CComplVectVert& conjugate();
	void show();
	virtual void output(ofstream& outf) override;
	friend class CComplNumb;
};
