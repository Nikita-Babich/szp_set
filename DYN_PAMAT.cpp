#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define nl printf("\n")

struct set {
	int length;
	int array[]; // flexible member: https://en.wikipedia.org/wiki/Flexible_array_member
	// if needed to axpand the struct add int* array; at the start
};

set* rand_set(int length, int maxnum){ //constructor of random set
	srand(time(NULL));
	set* ptr = (set*) malloc(sizeof(int)*(length+1));
	(ptr->length) = length;
	for(int i=0; i<length;i++){
		(ptr->array)[i] = rand()%maxnum;
	}
	return ptr;
};

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
	// O(n+m), not yet working correctly
	int minlen = (ptr1->length) < (ptr2->length) ? (ptr1->length) : (ptr2->length); 
	set* newptr = (set*) malloc(sizeof(int)*(minlen+1));
	int index1 = 0;
	int index2 = 0;
	newptr->length = 0;
	int a1=ptr1->array[index1];
	int a2=ptr2->array[index2];
	int recent;
	while( index1 < ptr1->length && index2 < ptr2->length ){
		if( ptr1->array[index1++] < ptr2->array[index2]){
			newptr->array[newptr->length] = ptr1->array[index1];
		} else if (ptr1->array[index1] > ptr2->array[index2++]){
			newptr->array[newptr->length] = ptr2->array[index2];
		} else {
			newptr->array[newptr->length] = ptr2->array[index2];
			index1++;	index2++;
		}
		newptr->length++;
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
			newptr->array[newptr->length] = recent;
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
	ptr = copy_set(newptr); //*ptr = *newptr;
	free(newptr);
	return ptr;
}

int main(){
	
	set* a = rand_set(10,10);
	print_set(a);
	a=shrink2(bubble_sort(a));
	print_set(a);
	nl;
	
	set* b = rand_set(20,10);
	print_set(b);
	print_set(shrink_sorted(b));
	
	
	b=shrink2(bubble_sort(b));
	
	set* c = intersect(a,b);
	print_set(bubble_sort(c));
	
	set* d = intersect_sorted(a,b);
	//copy_set(c);
	print_set(shrink2(d));

	
	free(a); free(b); free(c); free(d); 
}

//plans: union, create with variable amount of arguments