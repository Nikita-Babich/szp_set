#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define p(a) printf("\n%d\t",a)

bool inside(int num, int* a){ //If num is in a
	for (int i = 0; i<100; i++){
		if(num==a[i]){	
			return true;
		}
	}
	return false;
}

void generate(int* a){ //fill with random numbers between 0 and 49;
	for (int i=0; i<100;i++){
		a[i]=rand()%50;
	}
}

void print_array(int* a){
	for (int i=0; i<100;i++){
		printf("%d ",a[i]);
	}
}

void intersect(int* a, int* b){
	
}

void unite(){
}

main(){
	int a[100] = {6,7,8,77,88};
	int b[100] = {8,7,5};
	int res[100];
	
	srand(time(0));
	generate(a);
	generate(b);
	print_array(a);
}

//somment section
//blocks of code to test, remember, correct and so on

//sizeof()
//res = realloc(res, newSize);

//new pointers
//int* a = (int*) malloc(100 * sizeof(int));
//int* b = (int*) malloc(100 * sizeof(int));
//int* res = (int*) malloc(100 * sizeof(int));

//int len(int* array){
//	int size = sizeof(array)/sizeof(int);
//	printf("%d - calculated length \n", size);
//	return size;
//}
