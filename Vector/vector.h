#include <iostream>
using namespace std;
template <typename T>
class vector{
private:
	T* data;
	int size;
public:
	vector();
	~vector();
};