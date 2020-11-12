#include<iostream>
#include<string>
#include <mutex>
using namespace std;

class Lock:private {
public:
	explicit Lock(mutex* pm) :mutexPtr(pm) {
		mutexPtr->lock();
	}
	~Lock() { mutexPtr->unlock(); }
private:
	mutex *mutexPtr;
};
mutex mtx;

int main()
{
	mutex m;
	Lock ml1(&m);
	Lock ml2(ml1);
}