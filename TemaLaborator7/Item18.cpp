#include<iostream>
#include<string>
using namespace std;

class Calendar {
public:
	struct Zi {
		explicit Zi(int z) : val(z) {}
		int val;
	};
	struct Luna {
		explicit Luna(int l) :val(l) {}
		int val;
	};
	struct An {
		explicit An(int a) :val(a) {}
		int val;
	};

	Calendar(const Luna& l, const Zi& z, const An& a)
		: m_luna(l)
		, m_zi(z)
		, m_an(a) {};
	~Calendar() {};

private:
	Luna m_luna;
	Zi m_zi;
	An m_an;

};

int main() {
	Calendar c1(Calendar::Luna(3), Calendar::Zi(3), Calendar::An(2000));
	
	
	system("Pause");
	
}