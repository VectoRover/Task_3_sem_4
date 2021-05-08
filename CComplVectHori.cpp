#include "CComplVect.h"
#include "CComplVectHori.h"

CComplVectHori::CComplVectHori() : CComplVect() {}
CComplVectHori::CComplVectHori(vector<CComplNumb> ArrComplNumb) : CComplVect(ArrComplNumb) {}
CComplVectHori:: ~CComplVectHori()
{

}


CComplVectHori& CComplVectHori::operator=(const CComplVectHori& b)
{
	this->ArrComplNumb = b.ArrComplNumb;
	return *this;
}

void CComplVectHori::show()
{
	for (size_t i = 0; i < ArrComplNumb.size(); i++)
	{
		ArrComplNumb[i].show();
	}
}

CComplVectHori CComplVectHori::operator+(const CComplVectHori& b)
{
	CComplVectHori tmp;
	vector<CComplNumb> arr(b.ArrComplNumb.size());
	if (this->ArrComplNumb.size() == b.ArrComplNumb.size())
	{

		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

		#pragma omp parallel for
		for (int i = 0; i < int(b.ArrComplNumb.size()); i++)
		{
			arr[i] = this->ArrComplNumb[i] + b.ArrComplNumb[i];
		}

		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";

		tmp.ArrComplNumb = arr;
		return tmp;
	}
	else
	{
		cout << "vectors of different lengths1" << endl;
		exit(-1);
	}
}

CComplVectHori CComplVectHori::operator-(const CComplVectHori& b)
{
	CComplVectHori tmp;
	vector<CComplNumb> arr(b.ArrComplNumb.size());
	if (this->ArrComplNumb.size() == b.ArrComplNumb.size())
	{
		for (size_t i = 0; i < b.ArrComplNumb.size(); i++)
		{
			arr[i] = this->ArrComplNumb[i] - b.ArrComplNumb[i];
		}
		tmp.ArrComplNumb = arr;
		return tmp;
	}
	else
	{
		cout << "vectors of different lengths1" << endl;
		exit(-1);
	}
}

CComplNumb CComplVectHori::operator*(CComplVectHori& b)
{
    CComplNumb m;
	double resre = 0;
	double resim = 0;
	if (this->ArrComplNumb.size() != b.ArrComplNumb.size())
	{
		cout << "vectors of different lengths" << endl;
		exit(-1);
	}
	else
	{
		b.conjugate();

		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

      /*  #pragma omp parallel for
		for (int i = 0; i < b.ArrComplNumb.size(); i++)
		{
			m[i] = this->ArrComplNumb[i] * b.ArrComplNumb[i];
		}

        #pragma omp parallel for
		for (int i = 0; i < b.ArrComplNumb.size(); i++)
		{
			
		}*/


		#pragma omp parallel shared(resre, resim) private(m)
		{
			#pragma omp for reduction(+:resre, resim)
			for (int i = 0; i < b.ArrComplNumb.size(); i++)
			{
				m = this->ArrComplNumb[i] * b.ArrComplNumb[i];
				resre += m.get_Re();
				resim += m.get_Im();
			}
		}

		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Composition operator runtime is " << elapsed_ms << " ms\n";
		m.set_Re(resre);
		m.set_Im(resim);

		return m;
	}
}

CComplVectHori& CComplVectHori::conjugate()
{
	for (size_t i = 0; i < this->ArrComplNumb.size(); i++)
	{
		this->ArrComplNumb[i].set_Im(-this->ArrComplNumb[i].get_Im());
	}
	return *this;
}


void CComplVectHori::output(ofstream& outf)
{
	for (size_t i = 0; i < this->ArrComplNumb.size(); i++)
	{
		ArrComplNumb[i].showf(outf);
	}
	outf << endl;
}