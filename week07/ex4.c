#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* realloc( void *ptr, size_t size){

	void *dummy = malloc(size); 


	if( ptr != NULL ){
		memcpy( dummy, ptr, size);
	}

	free(ptr);

	return dummy;
}




int main(){

	// Allows user to specify the original array size, stored in variable n1.
	printf("I will use ex3 code to check if my realloc is implemented correctly \nOriginal array size is 3\n");
	int n1=3;

	//Create a new array of n1 ints
	int* a1 = malloc( n1*sizeof(int));
	int i;


	//Set each value in a1 to 100
	for(i=0; i<n1; i++){
		
		a1[i]=100;
		
		printf("%d ",a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nNew array size is 7\n");
	int n2=7;

	//Dynamically change the array to size n2
	a1 = realloc( a1, n2*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	if ( n2 > n1) for(i=n1; i<n2; i++) a1[i]=0;
	

	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}


	printf("\nNew array size is 1\n");
	n2=1;

	//Dynamically change the array to size n2
	a1 = realloc( a1, n2*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	if ( n2 > n1) for(i=n1; i<n2; i++) a1[i]=0;
	

	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}


	printf("\nNew array size is 9\n");
	n2=9;

	//Dynamically change the array to size n2
	a1 = realloc( a1, n2*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	if ( n2 > n1) for(i=n1; i<n2; i++) a1[i]=0;
	

	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}


	printf("\nNew array size is 0 (just free)\n");
	n2=0;

	//Dynamically change the array to size n2
	a1 = realloc( a1, n2*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	if ( n2 > n1) for(i=n1; i<n2; i++) a1[i]=0;
	

	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}

	printf("\nIt works!\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
