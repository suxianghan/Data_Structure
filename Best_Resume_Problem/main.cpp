//计蒜课链表project
#include <iostream>
using namespace std;
class Node{
public:
	Node* next;
	int data;
	Node(int dataIn){
		data = dataIn;
		next = NULL;
	}
};
class LinkedList{
private:
	Node* head;
	int length;
public:
	LinkedList(){
		head = NULL;
		length = 0;
	}
	~LinkedList(){
		if(head == NULL){
			return;
		}
		Node* currentNode = head;
		while(currentNode != NULL){
			Node* deleteNode = currentNode;
			currentNode = currentNode->next;
			delete deleteNode;
		}
	}
	void append(Node* node){
		length ++;
		if(head == NULL){
			head = node;
			return;
		}
		Node* currentNode = head;
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		currentNode->next = node;
		return;
	}
	void deleteNode(int bossNum){
		length --;
		if(bossNum == 1){
			head = head->next;
			return;
		}
		Node* currentNode = head;
		int count = 1;
		while(count < bossNum - 1){
			currentNode = currentNode->next;
			count++;
		}
		currentNode->next = currentNode->next->next;
		return;
	}
	void smart(){
		int destination = (length+1)/2;
		int count = 1;
		Node* currentNode = head;
		while(count < destination){
			currentNode = currentNode->next;
			count ++;
		}
		cout<<currentNode->data;
	}
};
int main(){
	LinkedList link;
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		Node* temp = new Node(i);
		link.append(temp);
	}
	for(int i=1;i<=n;i++){
		int fate;
		cin>>fate;
		link.deleteNode(fate);
	}
    link.smart();
    return 0;
}




