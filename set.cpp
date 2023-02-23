#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//new pointers
//int* a = (int*) malloc(100 * sizeof(int));
//int* b = (int*) malloc(100 * sizeof(int));
//int* res = (int*) malloc(100 * sizeof(int));

int len(int* array){
	int size = sizeof(array)/sizeof(array[0]);
	printf("%d - calculated length \n", size);
	return size;
}

void generate(int* a){
	//fill with random numbers between 0 and 49;
	int length = len(a);
	for (int i=0; i<length;i++){
		a[i]=rand()%50;
	}
}

void print_array(int* a){
	int length = len(a);
	for (int i=0; i<length;i++){
		printf("%d ",a[i]);
	}
}
//void read_set1(){
//	int read_index = 0;
//	bool cont = true;
//	if(id=="a"){
//		for(int i=0; cont; i++){
//			scanf("%d", )
//		}
//	}
//}

void intersect(int* a, int* b){
	
	//sizeof()
	//res = realloc(res, newSize);
}

void unite(){
}

main(){
	int a[100] = {6,7,8,77,88};
	int b[100] = {8,7,5};
	int res[100];
	
	srand(time(0));
	//generate(a);
	print_array(a);
}