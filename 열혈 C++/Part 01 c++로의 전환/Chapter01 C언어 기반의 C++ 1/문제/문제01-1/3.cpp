#include <iostream>

int main(void){
	int num;
	
	std::cout<<"���ڸ� �Է��ϼ���: ";
	std::cin>>num;
	
	for(int i=1; i<10; i++){
		std::cout<<num<<" x "<<i<<" = "<<i*num<<std::endl;
	}
	return 0; 
}
