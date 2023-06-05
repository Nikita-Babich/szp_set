#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#define nl printf("\n")

struct set {
	int length;
	int array[]; // flexible member: https://en.wikipedia.org/wiki/Flexible_array_member
	// if needed to axpand the struct add int* array; at the start
};

#include"treesort.h"

set* rand_set(int length, int maxstep){ //constructor of sorted random set
	int value = 0;
	set* ptr = (set*) malloc(sizeof(int)*(length+1));
	(ptr->length) = length;
	for(int i=0; i<length;i++){
		value += 1+rand()%maxstep;
		(ptr->array)[i] = value;
	}
	return ptr;
};

set* create_set(int length, ...){
	va_list valist;
	va_start(valist, length);
	set* ptr = (set*) malloc(sizeof(int)*(length+1));
	(ptr->length) = length;
	for(int i=0; i<length;i++){
		(ptr->array)[i] = va_arg(valist, int);
	}
	va_end(valist);
	return ptr;
}

void print_set(set* ptr){
	printf("\n 0x%.8X with the size %d \n", ptr, ptr->length);
	for(int i=0; i < (ptr->length); i++){
		printf("%d ", (ptr->array)[i]);
	}
	nl;
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
	//works as expected, O(n^2)
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

set* intersect_sorted(set* ptr1, set*ptr2){ //pointer to a new set
	// O(n+m), working correctly
	int minlen = (ptr1->length) < (ptr2->length) ? (ptr1->length) : (ptr2->length); 
	set* newptr = (set*) malloc(sizeof(int)*(minlen+1));
	int index1 = 0;
	int index2 = 0;
	newptr->length = 0;
	while( index1 < ptr1->length && index2 < ptr2->length ){
		if( ptr1->array[index1] < ptr2->array[index2]){
			index1++;
		} else if( ptr1->array[index1] > ptr2->array[index2]){
			index2++;
		} else {
			newptr->array[newptr->length] = ptr2->array[index2];
			index1++;	
			index2++;
			newptr->length++;
		}
	}
	return newptr;
}

set* union_sorted(set* ptr1, set*ptr2){
	int maxlen = ptr1->length + ptr2->length ; 
	set* newptr = (set*) malloc(sizeof(int)*(maxlen+1));
	int index1 = 0;
	int index2 = 0;
	newptr->length = 0;
	while( index1 < ptr1->length && index2 < ptr2->length ){
		if( ptr1->array[index1] < ptr2->array[index2]){
			newptr->array[newptr->length] = ptr1->array[index1];
			index1++;
		} else if( ptr1->array[index1] > ptr2->array[index2]){
			newptr->array[newptr->length] = ptr2->array[index2];
			index2++;
		} else {
			newptr->array[newptr->length] = ptr2->array[index2];
			index1++;	
			index2++;
		}
		newptr->length++;
	}
	while(index1 < ptr1->length){
		newptr->array[newptr->length] = ptr1->array[index1];
		newptr->length++;
		index1++;
	}
	while(index2 < ptr2->length){
		newptr->array[newptr->length] = ptr2->array[index2];
		newptr->length++;
		index2++;
	}
	return newptr;
}

set* bubble_sort(set* ptr){ //return the same pointer 
	//works as expected, O(n^2)
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
	//working correctly, O(n)
	set* newptr = (set*) malloc(sizeof(int)*(ptr->length+1));
	newptr->length = ptr->length;
	for(int i=0; i < newptr->length; i++){
		newptr->array[i] = ptr->array[i];
	}
	return newptr;
}

set* shrink_sorted(set* ptr){ // O(n), return new ptr
	int recent=ptr->array[0];
	set* newptr = (set*) malloc(sizeof(int)*(ptr->length+1));
	newptr->array[0] = recent;
	newptr->length = 1;
	for(int i=1; i<ptr->length; i++){
		if( ptr->array[i] != recent){
			recent = ptr->array[i];
			newptr->array[newptr->length] = ptr->array[i];
			newptr->length++;
		}
	}
	return newptr;
}

set* shrink2(set* ptr){ //return the same pointer 
	//working correctly O(n^2)
	set* newptr = (set*) malloc(sizeof(int)*(ptr->length+1));
	newptr->length = 0;
	for(int i=0; i<ptr->length; i++){
		if( !(inside(ptr->array[i], newptr)) ){
			newptr->array[newptr->length] = ptr->array[i];
			newptr->length++;
		}
	}
	ptr = copy_set(newptr);
	free(newptr);
	return ptr;
}

int main(){
	srand(time(NULL));
	printf("\nRandom set a:");
	set* a = rand_set(10,3);
	print_set(a);
	
	printf("\nRandom set b:");
	set* b = rand_set(10,3);
	print_set(b);	
	
	printf("\nIntersection of a and b:");
	set* c = intersect_sorted(a,b);
	print_set(c); free(c);
	
	printf("\nUnion of a and b:");
	c = union_sorted(a,b);
	print_set(c); free(c);
	
	printf("\n Handcrafted set e:");
	set* e = create_set(10, 2,3,2,12,5,5,2,4,5,8);
	print_set(e);
	
	printf("\n Sorted set e:");
	e = bubble_sort(e);
	print_set(e);
	
	printf("\n New set c equals shrunk set e:");
	c = shrink_sorted(e);
	print_set(c);
	
	printf("\n Now that 'cleaned set' c can be used with set functions");

}

//plans: union, create with variable amount of arguments