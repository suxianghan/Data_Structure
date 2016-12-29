#include <iostream>
#include "sphere.h"

sphere::sphere(){
	theRadius = 1;
}
sphere::sphere(double radius){
	theRadius = radius;
}
double sphere::getArea(){
	return theRadius*theRadius*3.1415926535;
}
int* rollercoaster(){
	int* point;
	point = new int(5);
	return point;
}
int main(){
	int* point = rollercoaster();
	sphere *a = new sphere(1.02);
	sphere b;
	std::cout<<a->getArea()<<std::endl;
	std::cout<<(*a).getArea()<<std::endl;
	std::cout<<b.getArea()<<std::endl;
	std::cout<<*point<<std::endl;
	std::cout<<"WoW"<<std::endl;
	return 0;
}