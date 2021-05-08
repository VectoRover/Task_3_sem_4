#include "CComplVect.h"

CComplVect::CComplVect()
{
}

CComplVect::CComplVect(vector<CComplNumb> ArrComplNumb)
{
	this->ArrComplNumb = ArrComplNumb;
}

CComplVect::~CComplVect()
{

}

vector<CComplNumb> CComplVect::get_ArrComplNumb()
{
	return this->ArrComplNumb;
}


void CComplVect::set_ArrComplNumb(vector<CComplNumb> ArrComplNumb)
{
	this->ArrComplNumb = ArrComplNumb;
}



int CComplVect::Input(string filename, vector<CFactoryComplVect*>& factory, vector<CComplVect*>& w)
{
	string str = "";
	int it = 0;
	int line = 0;
	int count = 0;
	string tmp_str = "";
	ifstream input_file(filename);

	if (input_file)
	{

		while (!input_file.eof())
		{
			getline(input_file, tmp_str, '\n');
			if (tmp_str.find(" ") == -1)
			{
				cout << "invalid input data 2" << endl;
				exit(-10);
			}
			line++;
		}

		input_file.seekg(0, ios::beg);
		w.resize(line);
		line = 0;


		while (!input_file.eof())
		{
			int j = 0;
			int m = -1;
			getline(input_file, tmp_str, ' ');
			if (stoi(tmp_str) != 0 && stoi(tmp_str) != 1)
			{
				cout << "invalid input data 2" << endl;
				exit(-20);
			}
			str = str + tmp_str;
			while (!input_file.eof() && tmp_str.find("\n") == -1)
			{
				getline(input_file, tmp_str, ' ');
				str = str + tmp_str;
				count++;
				if (count == 0)
				{
					cout << "invalid input data 3" << endl;
				}
			}

			if (count % 2 != 0 || str[str.size() - 1] == ' ')
			{
				cout << "invalid input data 1" << endl;
				exit(2);
			}

			if (!input_file.eof())
			{
				input_file.seekg(-int(str.size()) - count - 2, ios::cur);
			}
			else
			{
				input_file.seekg(-int(str.size()) - count, ios::cur);
			}

			getline(input_file, tmp_str, ' ');


			w[line] = factory[stoi(tmp_str)]->create();
			vector<CComplNumb> ArrComplNumb(count / 2);
			while (!input_file.eof() && tmp_str.find("\n") == -1)
			{
				getline(input_file, tmp_str, ' ');
				if (j % 2 == 0)
				{
					m++;
					ArrComplNumb[m].set_Re(double(stoi(tmp_str)));
				}
				if (j % 2 != 0 && tmp_str.find("\n") == -1)
				{
					ArrComplNumb[m].set_Im(double(stoi(tmp_str)));
				}
				if (tmp_str.find("\n") != -1)
				{
					ArrComplNumb[m].set_Im(double(stoi(tmp_str)));
					input_file.seekg(-int(tmp_str.size() - (tmp_str.substr(0, tmp_str.find("\n"))).size()), ios::cur);
				}
				j++;
			}
			w[line]->ArrComplNumb = ArrComplNumb;
			w[line]->show();

			str = "";
			count = 0;
			line++;
			ArrComplNumb.clear();
		}
		return 0;
	}
	else
	{
		cout << "could not open the input file" << endl;
		return NULL;
	}
}