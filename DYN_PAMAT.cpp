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

set* rand_set(int length, int maxnum){ //constructor of random set
	set* ptr = (set*) malloc(sizeof(int)*(length+1));
	(ptr->length) = length;
	for(int i=0; i<length;i++){
		(ptr->array)[i] = rand()%maxnum;
	}
	return ptr;
};

void print_set(set* ptr){
	printf("\n %d - size of the set at 0x%.8X\n", ptr->length, ptr);
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
	int minlen = (ptr1->length) < (ptr2->length) ? (ptr1->length) : (ptr2->length); 
	set* newptr = (set*) malloc(sizeof(int)*(minlen+1)); //might allocate bigger than needed, but a minimal safe size: intersection cannot be smaller than the first set
	newptr->length = 0;
	for (int i = 0; i<ptr1->length; i++){
		if(inside(ptr1->array[i], ptr2)){
			newptr->array[newptr->length] = ptr1->array[i]; //because length is used like growing index
			newptr->length++;
		}
	}
	return newptr;
}

set* bubble_sort(set* ptr){ //return the same pointer
	int helper;
	for(int i=0; i < ptr->length-1; i++){
		for(int j = 0; j < ptr->length-i-1; j++){
			if(ptr->array[j] > ptr->array[j+1]){
				helper = ptr->array[j];
				ptr->array[j] = ptr->array[j+1];
				ptr->array[j+1] = helper;
			}
		}
	}
	return ptr;
}

set* copy_set(set* ptr){
	set* newptr = (set*) malloc(sizeof(int)*(ptr->length+1));
	newptr->length = ptr->length;
	for(int i=0; i<newptr->length; i++){
		newptr->array[i] = ptr->array[i];
	}
	return newptr;
}

//set* shrink(set* ptr){ //return the same pointer
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

int main(){
	srand(time(NULL));
	set* a = rand_set(10,10);
	print_set(a);
	set* b = rand_set(10,10);
	print_set(b);
	
	set* c = intersect(a,b);
	print_set(bubble_sort(c));
	
	set* d = copy_set(c);
	print_set(d);
	
	//printf("\n %d ", inside(5,b));
	
	free(a); free(b); free(c); free(d);
}