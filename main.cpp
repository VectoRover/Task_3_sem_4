#include <string> 
#include <iostream>
#include <fstream>
#include <vector>
#include "CComplNumb.h"
#include "CComplVect.h"
#include "CComplVectHori.h"
#include "CComplVectVert.h"
#include "autotests.h"
#include "CFactoryComplVect.h"
#include "CFactoryComplVectHori.h"
#include "CFactoryComplVectVert.h"

int main()
{
	//autotest_CComplNumb();
	//autotest_CComplVect();

	vector<CComplVect*> w;
	CComplVectHori e;
	CComplVectHori f;
	vector<CComplNumb> aArr(1000000);
	vector<CComplNumb> bArr(1000000);
	CComplVectHori result1;
	CComplVectHori result2;
	CComplNumb result3;

	for (size_t i = 0; i < 1000000; i++)
	{
		/*aArr[i].set_Re(rand() % 10000 + 1);
		aArr[i].set_Im(rand() % 10000 + 1);

		bArr[i].set_Re(rand() % 10000 + 1);
		bArr[i].set_Im(rand() % 10000 + 1);*/

	    aArr[i].set_Re(100);
		aArr[i].set_Im(100);

		bArr[i].set_Re(100);
		bArr[i].set_Im(100);
		
	}

	e.set_ArrComplNumb(aArr);
	f.set_ArrComplNumb(bArr);

	//result1 = e + f;
	//result2 = e - f;
	result3 = e * f;


	return 0;
}
