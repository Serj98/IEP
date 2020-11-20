#include<iostream>
#include<string>
using namespace std;

class Punct {
public:
	int getX() { return x; }
	void setX(int value) { x = value; }
	int getY() { return y; }
	void setY(int value) { y = value; }

	Punct() :x(), y() {}
	Punct(int a,int b) :x(a), y(b) {}

	void afisare(string nume)
	{
		cout <<endl<< nume<<"("<<x<<" , "<<y<<")";
	}
private:
	int x;
	int y;
};

const Punct& operator*(Punct& a, Punct& b)
{
	return Punct(a.getX() * b.getX(),a.getY() * b.getY());
}

const Punct& operator+(Punct& a, Punct& b)
{
	return Punct(a.getX() + b.getX(), a.getY() + b.getY());
}

//itemi 22 24 25
int main()
{
	Punct a(1, 2);
	Punct b(3, 4);
	a.afisare("a");
	b.afisare("b");
	Punct c = a + b;
	c.afisare("c");
	Punct d = a * b;
	d.afisare("d");
	swap(a, b);
	a.afisare("a");
	b.afisare("b");


}
