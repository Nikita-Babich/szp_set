#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define REP(i, a, b) for (int i=a; i<=b; i++)

struct set {
	int length;
	int array[];
};

set* rand_set(int length, int maxnum){ //constructor
	set* ptr = (set*) malloc(sizeof(int)*(length+1));
	(ptr->length) = length;
	for(int i=0; i<length;i++){
		(ptr->array)[i] = rand()%maxnum;
	}
	return ptr;
};

print_set(set* ptr){
	printf("\n %d - size of the set\n", ptr->length);
	for(int i=0; i < (ptr->length); i++){
		printf("%d ", (ptr->array)[i]);
	}
}

bool inside(int num, set* ptr){
	for (int i = 0; i<ptr->length; i++){
		if(num==ptr->array[i]){
			return true;
		}
	}
	return false;
}

set* intersect(set* ptr1, set* ptr2){ //pointer to a new set
	
}

set* shrink(set* ptr){ //return the same pointer
}

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

int main(){
	srand(time(NULL));
	set* a = rand_set(10,10);
	print_set(a);
	set* b = rand_set(5,10);
	print_set(b);
	
	printf("\n %d ", inside(5,b));
	
	free(a); free(b);
}