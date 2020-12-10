#include <iostream>
#include<list>
#include<string>
#include<iterator>
using namespace std;

int countGainiStrut=0;
int countGaini=0;

class Pasare
{

public:
	virtual void zboara() = 0;
	virtual void sunet() = 0;
	
};


class Papagal : public Pasare
{
	list<string> cuvinte;
	int distanta;
	string sunetFacut;
public:
	Papagal(int d, string s) :distanta(d), sunetFacut(s) {};

	void adaugaCuvant(string cuvant)
	{
		cuvinte.push_front(cuvant);
	}

	void arataCuvinte()
	{
		cout <<"\n" << "Cuvinte cunoscute: { ";
		list<string>::iterator iter;
		for (iter = cuvinte.begin(); iter != cuvinte.end(); iter++)
		{
			cout << *iter << " , ";
		}
		cout << "}";
	}

	void zboara()
	{
		cout << "Distanta posibila de zbor a papagalului: " << distanta << "\n";
	}

	void sunet()
	{
		cout << "Sunetul pe care il face: " << sunetFacut << "\n";
	}

	Papagal &operator+(const Pasare& elem) {
		return *this;
	}

};




class Gaina : public Pasare {
	int distanta;
	string sunetFacut;
	
public:
	Gaina(int distanta, string sunetFacut) {
		if (countGaini < 30)
		{
			if (distanta >= 10)
				throw string("Eroare: distanta prea mare de zbor pentru Gaina");
			this->distanta = distanta;
			this->sunetFacut = sunetFacut;
			countGaini++;
		}
		else
			throw string("Eroare: out of instances range for Gaina");
	}
	~Gaina() {
		countGaini--;
	}
	
	void zboara()
	{
		cout << "Distanta posibila de zbor a gainii: " << distanta << "\n";
	}

	void sunet()
	{
		cout << "Sunetul pe care il face: " << sunetFacut << "\n";
	}

	void decrement()
	{
		countGaini--;
	}
	Gaina &operator+(const Pasare& elem) {
		return *this;
	}

};



class Strut : public Pasare
{
	int distanta;
	string sunetFacut;
	
	static Strut *instance;
	Strut() { ; }
	Strut(int distanta, string sunetFacut) {
		this->distanta = distanta;
		this->sunetFacut = sunetFacut;
	}
	~Strut() { ; }
public:
	static Strut *getInstance(int distanta, string sunet)
	{
		if (!instance) {
			instance = new Strut(distanta, sunet);
		}
		return instance;
	}
	static void Destroy() {
		if (!instance)
			delete(instance);
	}
	
	void zboara()
	{
		cout << "Distanta posibila de zbor a strutului: " << distanta << "\n";
	}

	void sunet()
	{
		cout << "Sunetul pe care il face: " << sunetFacut << "\n";
	}

	Strut &operator+(Gaina elem) {
		countGainiStrut++;
		elem.decrement();
		return *this;
	}


};

Strut* Strut::instance = NULL;

int main()
{
	try {
		Papagal p(10, "Krrr");
		p.zboara();
		p.sunet();
		p.adaugaCuvant("acum");
		p.adaugaCuvant("biscuite");
		p.adaugaCuvant("vreau");
		p.arataCuvinte();

		Gaina g(5, "cotcodac");
		Gaina g2(7, "cucuriguuuu");
		Gaina g3(3, "piupiu");
		cout << "Gaina 1: ";
		g.zboara();
		g.sunet();
		cout << "Gaina 2: ";
		g2.zboara();
		g2.sunet();
		cout << "Gaina 3: ";
		g3.zboara();
		g3.sunet();

		cout << "Numarul de gaini este: " << countGaini<<endl;


		Strut *instance = Strut::getInstance(10, "fgegeagae");
	
		cout << countGainiStrut<< endl;
		instance->sunet();
		*instance = *instance + g;
		
		cout << countGainiStrut << endl;
	}
	catch (string& e)
	{
		cout << e << "\n";
	}

	system("pause");
}