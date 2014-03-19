#include<stdio.h>
#include<stdlib.h>

int main(){
	char teste[25];
	float f;
	sprintf(teste,"%f == %#f",10.10,10.10);
	f=atof("10.10");
	printf("%f == %s",f,teste);
	return 0;
}
