#include <iostream>
using namespace std;
template <class T1,class T2>
void printer(T1 a,T2 b){
	cout<<a<<b;
}
int main(){
	printer<int,int>(2,3);
	return 0;
}