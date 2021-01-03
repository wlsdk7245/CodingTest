#include <iostream>

int main(void){
	char name[100];
	char tel[100];
	
	std::cout<<"이름 : ";
	std::cin>>name;
	
	std::cout<<"전화번호 : ";
	std::cin>>tel;
	
	std::cout<<"당신의 이름은 "<<name<<"이고, 전화번호는 "<<tel<<"입니다. \n";
	return 0; 
}
