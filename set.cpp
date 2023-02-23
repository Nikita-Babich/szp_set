#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define p(a) printf("\n%d\t",a)

bool inside(int num, int* a){ //If num is in a
	for (int i = 0; i<10; i++){
		if(num==a[i]){	
			return true;
		}
	}
	return false;
}

void generate(int* a){ //fill with random numbers between 1 and 9;
	for (int i=0; i<10;i++){
		a[i]=rand()%9+1;
	}
}

void print_array(int* a){
	printf("\n");
	for (int i=0; i<10;i++){
		printf(" %d ",a[i]);
	}
	printf("\n");
}

void print_res(int* z){
	printf("\n");
	for (int i=0; i<20;i++){
		if(z[i]!=0) {
			printf(" %d ",z[i]);
		}
	}
	printf("\n");
}

void intersect(int* a, int* b, int* z){
	int index = 0;
	for(int i=0;i<10;i++){
		if(inside(a[i],b)){
			z[index]=a[i];
			index++;
		}
	}
	for(;index<10;index++){
		z[index]=0;
	}
}

void unite(int* a, int* b, int* z){
	
}

main(){
	int a[10];
	int b[10];
	int res[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //zero stands for empty
	
	srand(time(0));
	generate(a);
	generate(b);
	print_array(a);
	print_array(b);
	
	intersect(a,b,res);
	print_res(res);
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
