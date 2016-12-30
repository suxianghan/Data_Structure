#include "queue.h"
using namespace std;

int main(){
	assert(1==1);
	queue<int> lab(10);
	lab.output();
	for(int i=1;i<6;i++){
		lab.push(i);
		lab.output();
	}
	cout<<"Now go to the terminal"<<endl;
	int inputer = 0;
	while(inputer != -1){
		cin>>inputer;
		if(inputer == 0){
			lab.pop();
		}
		else{
			lab.push(inputer);
		}
		lab.output();
	}
	return 0;
}