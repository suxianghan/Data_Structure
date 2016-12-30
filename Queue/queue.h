#include <iostream>
#include <cassert>
template <typename T>
class queue{
private:
	T *data;
	int head,tail,size,count;
public:
	queue(int num);
	void push(T value);
	T pop();
	void output();
};

template <typename T>
queue<T>::queue(int num):head(0),tail(-1),count(0),size(num){data = new T[num];}

template <typename T>
void queue<T>::push(T value){
	assert(size>count);
	tail = (tail+1)%size;
	data[tail] = value;
	count++;
}

template <typename T>
T queue<T>::pop(){
	assert(count>0);
	T vals = data[head];
	head = (head+1)%size;
	count--;
	return vals;
}

template <typename T>
void queue<T>::output(){
	int index = head;
	std::cout<<"head -> ";
	if(count != 0){
		do{
			std::cout<<data[index%size]<<" -> ";
			index++;
		}while(index%size != (tail+1)%size);
	}
	std::cout<<"tail\n";
	return;
}