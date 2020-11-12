#include<iostream>
#include<string>
using namespace std;

class Investment {
public:
	string Name;
	Investment() :Name() {}
	Investment(string name) :Name(name) {}
	
	void afisare(string ptName)
	{
		cout << endl << ptName<<" = "<<Name;
	}

};

Investment* createInvestment(string name) {
	return new Investment(name);
}

int main()
{

	Investment* pInv;
	std::auto_ptr<Investment>pInv1(createInvestment("Nume"));
	cout << endl << "*pInv1";
	pInv = pInv1.get();
	pInv->afisare("pInv1");///pInv1->obiect

	cout << endl << "Declarand pointerul pInv2 astfel: auto_ptr<Investment>pInv2(pInv1)/npInv1 pointeaza spre null, iar pInv2 spre obiect."<<endl;
	std::auto_ptr<Investment>pInv2(pInv1);
	pInv = pInv1.get();
	//pInv->afisare("pInv1");///eroare-pInv1 ->null
	pInv = pInv2.get();
	pInv->afisare("pInv2");///eroare-pInv2 ->obiect

	cout << endl << "Folosind pInv1=pInv2,pInv1 pointeaza iar spre obiect, iar pInv2 pointeaza spre null" << endl;
	pInv1 = pInv2;
	pInv = pInv1.get();
	pInv->afisare("pInv1");///eroare-pInv1 ->obiect
	pInv = pInv2.get();
	//pInv->afisare("pInv2");///eroare-pInv2 ->null

	cout <<endl<< "Folosind pointeri de tip shared_ptr in loc de auto_ptr rezolva problema atribuirii"<<endl;
	std::shared_ptr<Investment>pInv3(createInvestment("Nume"));
	std::shared_ptr<Investment>pInv4(createInvestment("Nume"));
	pInv = pInv3.get();
	pInv->afisare("pInv3");
	pInv = pInv4.get();
	pInv->afisare("pInv4");



}