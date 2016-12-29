#include <iostream>
using namespace std;
class Node{
public:
	int value;
	Node* next;
	Node():value(0),next(NULL){}
	Node(int valIn):value(valIn),next(NULL){}
};
class LinkedList{
private:
	Node* head;
	static int size;
	bool insert_helper(Node* &node,const int &index){
		if((index<0)||(index>=size)){
			return false;
		}
		if(index == 0){
			if(head == NULL){
				head = node;
				head->next = head;
				return true;
			}
			else{
				node->next = head->next;
				head->next = node;
				return true;
			}
		}
		Node* currentNode = head->next;
		int count = 0;
		while(count<index-1){
			currentNode = currentNode->next;
			count++;
		}
		node->next = currentNode->next;
		currentNode->next = node;
		if((index != 0) && (currentNode == head)){
			head = currentNode->next;
		}
		return true;
	}
	bool delete_Helper(const int& index){
		if((index<0)||(index>=size)){
			return false;
		}
		if(size == 2){
			head = NULL;
			return true;
		}
		if(index == 0){
			Node* delNode = head->next;
			head->next = head->next->next;
			delete delNode;
			return true;
		}
		Node* currentNode = head;
		int count = 0;
		while(count<index-1){
			currentNode = currentNode->next;
			count++;
		}
		Node* delNode = currentNode->next;
		if(currentNode->next == head){
			head = currentNode;
		}
		currentNode->next = currentNode->next->next;
		delete delNode;
		return true;
	}
public:
	LinkedList():head(NULL){}
	~LinkedList(){
		Node* currentNode = head->next;
		while(currentNode != head){
			Node* delNode = currentNode;
			currentNode = currentNode->next;
			delete delNode;
		}
		delete currentNode;
	}
	void insert(Node* node,int index){
		if(insert_helper(node,index) == true){
			size++;
		}
		return;
	}
	void append(Node* &node){
		insert(node,size-1);
	}
	void deleteNode(int index){
		if(delete_Helper(index) == true){
			size--;
		}
		return;
	}
	void print(){
		if(size == 1){
			cout<<"empty list! Insert something please"<<endl;
			return;
		}
		cout<<"start ";
		Node* currentNode = head->next;
		while(currentNode != head){
			cout<<"-> "<<currentNode->value<<" ";
			currentNode = currentNode->next;
		}
		cout<<"-> "<<head->value<<" -> end"<<endl;
		return;
	}
};
int LinkedList::size = 1;
int main(){
	LinkedList amp;
	for(int i=1;i<10;i++){
		Node* inserter = new Node(i);
		amp.append(inserter);
		amp.print();
	}
	return 0;
}