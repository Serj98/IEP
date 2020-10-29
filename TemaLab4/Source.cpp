#include<iostream>
#include<string>
using namespace std;


template<typename T>
class Sum {
private:
	T x;
	T y; 
	T s;
	Sum& operator=(const Sum&) {};//nu se mai poate atribui valoare unui obiect prin = altui obiect
public:
	Sum() :x(), y(),s() {};
	Sum(T a, T b) :x(a), y(b),s(){};

	T MakeSum(T a, T b) {
		s = a + b;
		return s;
	}
	void afisare() { cout << x <<" + "<< y << " = " << MakeSum(x,y) << endl; }

};

int main()
{

	Sum<int> s = {};
	s.afisare();

	Sum<int> s1 = {1,2};
	s1.afisare();

	Sum<float> s2 = { 1.5,2.5 };
	s2.afisare();

	Sum<char> s3 = { 1,'a' };
	s3.afisare();

	s = s1;//operatia = nu mai e accesibila, deci apare eroare
	s.afisare();



}