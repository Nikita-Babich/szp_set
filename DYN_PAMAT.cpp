#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define REP(i, a, b) for (int i=a; i<=b; i++)

struct set {
	int length;
	int a[];
};

set* rand_set(int maxlength){ //constructor
	int length = rand()%maxlength;
	set* ptr = (set*) malloc(sizeof(int)*(length+1));
	(ptr->length) = length;
	for(int i=0; i<length;i++){
		(ptr->a)[i] = rand();
	}
	return ptr;
};

print_set(set* ptr){
	printf("\n %d - size of the set\n", ptr->length);
	for(int i=0; i < (ptr->length); i++){
		printf("%d ", (ptr->a)[i]);
	}
}

//bool inside(int num, int * a){ //ci num patri do a
//	int asize = sizeof(a)/4;
//	for (int i = 0; i<asize; i++){
//		if(num==a[i]){	
//			return true;
//		}
//	}
//	return false;
//}
//
//int * truncate(int *a, int last_index){
//	int result[last_index+1];
//	for(int i = 0; i<last_index+1; i++){
//		result[i] = a[i];
//	}
//	return result;
//	
//}

//int * prienik( int *a, int *b){
//	int result[];
//	int asize = sizeof(a)/4;
//	int bsize = sizeof(a)/4;
//	int index_res = 0;
//	for (int i = 0; i<asize; i++){
//		for (int j = 0; j<bsize; j++){
//			if(a[i]==b[j] and !inside(a[i], result)){
//				result[index_res] = a[i];
//				index_res++;
//			}
//		}
//	}
//	//truncate result
//	result = truncate(result, index_res);
//	return result;
//}

//int * zjednotenie( int *a, int *b){
//	int result[20];
//	int asize = sizeof(a)/4;
//	int bsize = sizeof(a)/4;
//	int index_res = 0;
//	for (int i = 0; i<asize; i++){
//		if(inside( a[i], b)){
//			result[index_res] = a[i];
//		};
//	}
//	//truncate result
//	result = truncate(result, index_res);
//	return result;
//}

struct sset{ //
	int size;
	int *set;
};

void r(int* set, int* size){
	printf("\ninput size of set a\n");
	scanf("%d", size);
	int msize = (*size)*sizeof(int);
	set = (int*) malloc(msize);
	for(int i =0; i<(*size); i++){
		scanf("%d", &(set[i]));
	}
}

void p(int* set, int *size){
	printf("\n");
	for(int i =0; i<(*size); i++){
		printf("%d\t", set[i]);
	}	
	printf("\n");
}

int main(){
	srand(time(NULL));
	print_set(rand_set(5));
	print_set(rand_set(15));
}

//struct set set_a,set_b;
//	struct set* ptr_a, ptr_b;
//	 
//	 
//	int *a; int *b;
//	int sizea, sizeb;
//	int msizea, msizeb;
//	 
//	r(a, &sizea);
//	p(a, &sizea);
//
//	free(a); free(b);
	
	
//	short int *buf;
//	short int i;
//	buf = malloc(5*sizeof(short int));
//	buf[2]=5;
//	free(buff);
	
	//not use smerniks with scanf