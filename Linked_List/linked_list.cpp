#include <iostream>
#include "linkedList.h"
using namespace std;
int main(){
	LinkedList<char> tester = LinkedList<char>();
	Node<char>* inputer;
	for(int i=1;i<4;i++){
		inputer = new Node<char>(char(i+45));
		tester.insert(inputer,i-1);
	}
	tester.delete_node(2);
	tester.printer();
	tester.reverse();
	tester.printer();
	return 0;
}