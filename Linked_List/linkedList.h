#include <iostream>
using namespace std;
template<class T>
class Node{
public:
	T value;
	Node* next;
	Node(T datain);
};

template<class T>
class LinkedList{
private:
	Node<T>* head;
public:
	LinkedList();
	~LinkedList();
	void insert(Node<T>* node,int index);
	void delete_node(int index);
	void reverse();
	void printer();
};

template<typename T>
Node<T>::Node(T datain):value(datain),next(NULL){}

template<typename T>
LinkedList<T>::LinkedList():head(NULL){}

template<typename T>
LinkedList<T>::~LinkedList(){
		if(head == NULL){
			return;
		}
		Node<T>* currentNode = head;
		while(currentNode != NULL){
			Node<T>* oper = currentNode;
			currentNode = currentNode->next;
			delete oper; 
		}
	}

template <typename T>
void LinkedList<T>::insert(Node<T>* node,int index){
		if(node == NULL){
			return;
		}
		if(head == NULL){
			if(index == 0){
				head = node;
			}
			return;
		}
		if(index == 0){
			node->next = head;
			head = node;
		}
		Node<T>* currentNode = head;
		int count = 0;
		while((currentNode != NULL)&&(count<index-1)){
			currentNode = currentNode->next;
			count ++;
		}
		if(count == index-1){
			Node<T>* tester = currentNode;
			Node<T>* afterNode = currentNode->next;
			currentNode->next = node;
			node->next = afterNode;
		}
		return;
		}

template <typename T>
void LinkedList<T>::delete_node(int index){
		if((index < 0)||(head == NULL)){
			return;
		}
		if(index == 0){
			head = head->next;
			return;
		}
		Node<T> *currentNode = head;
		int count = 0;
		while((currentNode != NULL)&&(count<index-1)){
			currentNode = currentNode->next;
			count += 1;
		}
		if((count == index-1)&&(currentNode->next != NULL)){
			Node<T>* delete_node = currentNode->next;
			currentNode->next = currentNode->next->next;
			delete delete_node;
		}
		return;
	}

template <typename T>
void LinkedList<T>::reverse(){
		if(head == NULL){
			return;
		}
		Node<T> *currentNode,*nextNode;
		currentNode = head;
		nextNode = head->next;
		currentNode->next = NULL;
		while(nextNode != NULL){
			head = currentNode;
			currentNode = nextNode;
			nextNode = nextNode->next;
			currentNode->next = head;
		}
		head = currentNode;
		return;
	}

template <typename T>
void LinkedList<T>::printer(){		
		Node<T>* currentNode = head;
		while(currentNode != NULL){
			cout<<currentNode->value<<" ";
			currentNode = currentNode->next;
		}
		cout<<endl;
		return;
	}

