#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	char str1[]="하이루 방가방가방가방가";
	char str2[]="붙여붙여";
	char str3[30];
	 
	cout<<strlen(str1)<<endl;
	cout<<strcat(str1, str2)<<endl;
	cout<<strcpy(str3, str1)<<endl;
	cout<<strcmp(str1, str2)<<endl;
	return 0;
}
