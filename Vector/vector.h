#include <iostream>
using namespace std;
template <typename T>
class Vector{
private:
	T* data;
	int size;
	int length;
	bool isCons;
	void expand();
public:
	Vector(int sizeIn,bool alter);
	~Vector();
	 T& operator[](int index);
	bool insert(int index,const T& element);
	bool remove(int index);
	void output();
};

template <typename T> Vector<T>::Vector(int sizeIn,bool alter):size(sizeIn),length(0),isCons(alter){
	data = new T[sizeIn];
}

template <typename T> Vector<T>::~Vector(){
	delete[] data;
}

template <typename T> T& Vector<T>::operator[](int index){
	return  data[index];
}
template <typename T> void Vector<T>::expand(){
	size *= 2;
	T* tmpData = new T[size];
	for(int i=0;i<length;i++){
		tmpData[i] = data[i];
	}
	delete data;
	data = tmpData;
	return;
}

template <typename T> bool Vector<T>::insert(int index,const T& element){
	if(index<0 || index>length)
		{ return false; }
	if(length >= size){
		if(isCons) { return false; }
		else { expand(); }
	}
	for(int i = length;i>index;i--){
		data[i] = data[i-1];
	}
	data[index] = element;
	length ++;
	return true;
}

template <typename T> bool Vector<T>::remove(int index){
	if(index<0 || index >= length)
		{ return false; }
	for(int i=index;i<length-1;i++){
		data[i] = data[i+1];
	}
	length --;
	return true;
}

template <typename T> void Vector<T>::output(){
	if(length == 0){
		cout<<"Nothing in yet";
	}
	else{
		for(int i=0;i<length;i++){
			cout<<data[i]<<" ";
		}
	}
	cout<<endl;
	return;
}




