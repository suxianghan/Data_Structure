#include "stack.h"
using namespace std;
template <typename T> int updater(Stack<T> &stackQ, Stack<T> &stackI, T &element, int &index, int &size){
	int difference = 0;
	while(stackQ.top() < element && stackQ.isEmpty() == false){
		stackQ.pop();
		stackI.pop();
	}
	if(stackI.isEmpty()){
		difference = size-index-1;
	} else{
		difference = stackI.top() - index - 1;
	}
	stackQ.push(element);
	stackI.push(index);
	return difference;
}
int main(){
	int size,input;
	int* holder;
	cin>>size;
	Stack<int> stackQ(size);
	Stack<int> stackI(size);
	holder = new int[size];
	for (int i=0;i<size;i++){
		cin>>input;
		holder[i] = input;
	}
	for (int i=size-1;i>=0;i--){
		cout<<updater(stackQ,stackI,holder[i],i,size);
	}
}