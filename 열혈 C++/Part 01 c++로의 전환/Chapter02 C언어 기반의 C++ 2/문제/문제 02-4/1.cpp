#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	char str1[]="���̷� �氡�氡�氡�氡";
	char str2[]="�ٿ��ٿ�";
	char str3[30];
	 
	cout<<strlen(str1)<<endl;
	cout<<strcat(str1, str2)<<endl;
	cout<<strcpy(str3, str1)<<endl;
	cout<<strcmp(str1, str2)<<endl;
	return 0;
}
