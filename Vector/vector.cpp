#include "vector.h"

using namespace std;

int main(){
	Vector<int> a(10,false);
	for(int i=0;i<10;i++){
		a.insert(i,i);
		a.output();
	}
	a.remove(0);
	a.output();
	a.insert(0,0);
	a.output();
	a.remove(9);
	a.output();
	a.remove(4);
	a.output();
	a.remove(0);
	a.output();
	for(int i=0;i<10;i++){
		a.insert(i,i);
		a.output();
	}
	a[10] = 2;
	cout<<a[10]<<endl;
	a.output();
}
