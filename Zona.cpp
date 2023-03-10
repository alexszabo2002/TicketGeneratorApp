#include <iostream>
#include <string>
#include "Zona.h"

using namespace std;

Zona::Zona()
{
	denumireZona = "N/A";
	pretZona = 0;
	nrLocuriZona = 0;
	nrLocuriPerRand = 0;
	locuri = nullptr;
}

Zona::Zona(string _denumireZona, float _pretZona, int _nrLocuriZona, int _nrLocuriPerRand)
{
	denumireZona = _denumireZona;
	pretZona = _pretZona;
	nrLocuriZona = _nrLocuriZona;
	nrLocuriPerRand = _nrLocuriPerRand;

	if (nrLocuriZona > 0)
	{
		locuri = new int[_nrLocuriZona];

		for (int i = 0; i < _nrLocuriZona; i++)
		{
			locuri[i] = i + 1;
		}
	}
	else
	{
		nrLocuriZona = 0;
		locuri = nullptr;
	}
}

Zona::Zona(const Zona& z)
{
	this->denumireZona = z.denumireZona;
	this->pretZona = z.pretZona;

	if (z.locuri != nullptr && z.nrLocuriZona > 0)
	{
		this->nrLocuriZona = z.nrLocuriZona;
		this->nrLocuriPerRand = z.nrLocuriPerRand;

		this->locuri = new int[z.nrLocuriZona];
		for (int i = 0; i < z.nrLocuriZona; i++)
		{
			this->locuri[i] = z.locuri[i];
		}
	}
	else
	{
		this->nrLocuriZona = 0;
		this->nrLocuriPerRand = 0;
		this->locuri = nullptr;
	}
}

Zona::~Zona()
{
	if (locuri != nullptr && nrLocuriZona > 0)
	{
		delete[] locuri;
		locuri = nullptr;
	}
}

Zona& Zona::operator=(const Zona& z)
{
	if (this != &z)
	{
		this->denumireZona = z.denumireZona;
		this->pretZona = z.pretZona;

		if (this->locuri != nullptr)
		{
			delete[] this->locuri;
		}

		if(z.locuri != nullptr && z.nrLocuriZona > 0)
		{
			this->locuri = new int[z.nrLocuriZona];

			for (int i = 0; i < z.nrLocuriZona; i++)
			{
				this->locuri[i] = z.locuri[i];
			}

			this->nrLocuriZona = z.nrLocuriZona;
			this->nrLocuriPerRand = z.nrLocuriPerRand;
		}
		else
		{
			this->nrLocuriZona = 0;
			this->nrLocuriPerRand = 0;
			this->locuri = nullptr;
		}
	}
	return *this;
}

void Zona::setDenumireZona(string _denumireZona)
{
	this->denumireZona = _denumireZona;
}

string Zona::getDenumireZona()
{
	return denumireZona;
}

void Zona::setPretZona(float _pretZona)
{
	this->pretZona = _pretZona;
}

float Zona::getPretZona()
{
	return pretZona;
}

void Zona::setNrLocuriZona(int _nrLocuriZona)
{
	if (this->locuri != nullptr && this->nrLocuriZona > 0)
	{
		delete[] this->locuri;
		this->locuri = nullptr;
	}

	if (_nrLocuriZona == 0)
	{
		this->nrLocuriZona = 0;
		this->locuri = nullptr;
	}
	else
	{
		this->nrLocuriZona = _nrLocuriZona;
		this->locuri = new int[_nrLocuriZona];
		for (int i = 0; i < _nrLocuriZona; i++)
		{
			this->locuri[i] = i + 1;
		}
	}
}

int Zona::getNrLocuriZona()
{
	return nrLocuriZona;
}

void Zona::setNrLocuriPerRand(int _nrLocuriPerRand)
{
	this->nrLocuriPerRand = _nrLocuriPerRand;
}

int Zona::getNrLocuriPerRand()
{
	return nrLocuriPerRand;
}

void Zona::getLocuri()
{
	if (this->nrLocuriZona == 0)
	{
		cout << "Nu exista locuri" << endl;
	}
	else
	{
		for (int i = 0; i < this->nrLocuriZona; i++)
		{
			if (this->locuri[i] % this->nrLocuriPerRand == 0)
			{
				cout << this->locuri[i] << endl;
			}
			else
			{
				cout << this->locuri[i] << " ";
			}
		}
	}
}

void Zona::getRand(int loc)
{
	if (loc > this->nrLocuriZona || loc < 0)
	{
		cout << "Loc invalid" << endl;
	}
	else
	{
		if (loc % this->nrLocuriPerRand == 0)
		{
			cout << loc / this->nrLocuriPerRand;
		}
		else
		{
			cout << loc / this->nrLocuriPerRand + 1;
		}
	}
}

ostream& operator<<(ostream& out, Zona z)
{
	out << "Denumire zona: " << z.denumireZona << endl;
	out << "Pret zona: " << z.pretZona << endl;
	out << "Nr locuri zona: " << z.nrLocuriZona << endl;
	out << "Nr locuri per rand: " << z.nrLocuriPerRand << endl;
	out << endl;

	for (int i = 0; i < z.nrLocuriZona; i++)
	{
		if (z.locuri[i] % z.nrLocuriPerRand == 0)
		{
			out << z.locuri[i] << endl;
		}
		else
		{
			out << z.locuri[i] << " ";
		}
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, Zona& z)
{
	cout << "Denumire zona: ";
	in >> ws;
	getline(in, z.denumireZona);

	cout << "Pret zona: ";
	in >> z.pretZona;

	cout << "Nr locuri zona: ";
	in >> z.nrLocuriZona;

	if (z.nrLocuriZona > 0)
	{
		z.locuri = new int[z.nrLocuriZona];

		for (int i = 0; i < z.nrLocuriZona; i++)
		{
			z.locuri[i] = i + 1;
		}
	}

	return in;
}