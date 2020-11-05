#include<iostream>
#include<string>
using namespace std;

class Persoana {
private:
	string Nume, Prenume;
	int Varsta;
public:
	Persoana() :Nume(), Prenume(), Varsta() {};
	Persoana(string nume, string prenume, int varsta) :Nume(nume), Prenume(prenume), Varsta(varsta) {};
	Persoana(const Persoana& rhs) :Nume(rhs.Nume), Prenume(rhs.Prenume), Varsta(rhs.Varsta) {};
	virtual ~Persoana() {}



	void afisare() {
		cout << endl << Nume << " " << Prenume << " " << Varsta;
	}
};

class Student :public Persoana {
private:
	string Nume, Prenume, Facultate;
	int Varsta;
	Persoana* p;
public:
	Student() :Persoana(), Facultate() {};
	Student(string nume, string prenume, int varsta, string facultate) :Persoana(nume, prenume, varsta), Facultate(facultate) {};
	Student(const Student& rhs) :Persoana(rhs), Facultate(rhs.Facultate) {}

	Student& operator=(const Student& rhs) {
		if (this == &rhs)
			return *this;
		delete p;
		p = new Persoana(*rhs.p);
		return *this;
	}

	~Student() {}
	void afisare() {
		Persoana::afisare();
		cout << " " << Facultate;
	}

};

/*
int main()
{
	Persoana p1("Fierascu", "Sergiu", 22);
	Persoana p2(p1);
	Student p3("Popescu", "Vasile", 22, "AC");
	Student p4("Ciceu", "Diana", 22, "AC");
	p1.afisare();
	p2.afisare();
	p3.afisare();
	p4.afisare();
	p3 = p3;
	p3.afisare();
}*/