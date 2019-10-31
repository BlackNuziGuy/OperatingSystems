#include <stdio.h>
#include <unistd.h>

void f1(){

 printf("Hello");
 fork();
 printf("\n");

}

void f2(){
 printf("Hello\n");
 fork();
 printf("\n");
}


int main(void) {

	int n;


	scanf("%d", &n);


	if (n){
		f2();
	}
	else{
		f1();
	}

}	