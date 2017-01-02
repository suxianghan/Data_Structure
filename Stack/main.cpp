#include "stack.h"

template <typename T> void updater(Stack<T> &stack, T &element){
	while(stack.top() < element && stack.isEmpty() == false){
		stack.pop();
	}
	stack.push(element);
}
int main(){
	Stack<int> stack(10);
	for(int i=0;i<10;i++){
		stack.push(i);
		stack.output();
	}
	for(int i=0;i<10;i++){
		stack.pop();
		stack.output();
	}
	for(int i=0;i<100;i++){
		cin>>i;
		updater(stack,i);
		stack.output();
	}
	//Real situation
}