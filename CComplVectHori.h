#pragma once
#include <string>
#include <iostream>
#include "CComplNumb.h"
#include "CComplVect.h"
#include <chrono>
#include <omp.h>
using namespace std;

class CComplVectHori : public CComplVect
{
public:
	CComplVectHori();
	CComplVectHori(vector<CComplNumb> ArrComplNumb);
	~CComplVectHori() override;

	CComplVectHori& operator=(const CComplVectHori& b);
	CComplVectHori operator+(const CComplVectHori& b);
	CComplVectHori operator-(const CComplVectHori& b);
	CComplNumb operator*(CComplVectHori& b);
	CComplVectHori& conjugate();
	void show();
	virtual void output(ofstream& outf) override;
	friend class CComplNumb;
};
