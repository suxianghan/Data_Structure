#include <iostream>
using namespace std;
template <typename T>
class Stack{
private:
	T* data;
	int size;
	int length;
public:
	Stack(int lengthIn);
	virtual ~Stack();
	virtual bool push(T& element);
	T pop();
	bool isEmpty();
	T top();
	virtual void output();
};
template <typename T> Stack<T>::Stack(int lengthIn):size(lengthIn),length(0) { data = new T[size]; }

template <typename T> Stack<T>::~Stack() {delete[] data;}

template <typename T> bool Stack<T>::push(T& element){
	if(length == size){
		return false;
	}
	data[length] = element;
	length++;
	return true;
}

template <typename T> bool Stack<T>::isEmpty(){return !(length>0);}

template <typename T> T Stack<T>::pop(){
	if(this->isEmpty()){
		return T();
	}
	T tmp = data[length-1];
	length -- ;
	return tmp;
}

template <typename T> T Stack<T>::top(){
	if(this->isEmpty()){
		return 0;
	} else {
		return data[length-1];
	}
}

template <typename T> void Stack<T>::output(){
	if(this->isEmpty()){
		cout<<"Nothing!"<<endl;
		return;
	} else {
		for(int i =0;i<length;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
		return;
	}
}




