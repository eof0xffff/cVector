#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvec.h"

/*
TODO: Implement: string functinos, clear, pop_back, comment documentation
*/

void printCvecValue(Cvec *v, int index) 
{
	GetValueInt result = cvec_get(v, index, int);
	if(result.err == CVEC_OK) {
		printf("Value of index %i: %i\n", index, result.value);
	}
}

void printCvecValueString(Cvec *v, int index) 
{
	GetValueString result = cvec_get(v, index, char*);
	if(result.err == CVEC_OK) {
		printf("Value of index %i: %s\n", index, result.value);
	}
}


int main() {

//------------------------
// Initialize cvec vector
//------------------------
	Cvec vector;
	Cvec vectorStr;
	//init_cvec(&vector, sizeof(int));
	cvec_init(&vector, int);
	cvec_init(&vectorStr, char*);
	
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	int arr2[3] = {15,16,17};

	char *str1 = "Hello ich bin string 1";
	char str2[] = "Und ich bin der zweite String";
	char *stringArray[] = { "arr1", "arr2", "arr3" };
	
	printf("STRING!!!!\n");
	cvec_push_back(&vectorStr, str1);
	cvec_push_back(&vectorStr, str2);
	cvec_push_back(&vectorStr, "Test");
	cvec_insert_range(&vectorStr, 1, stringArray);

	for(size_t i = 0; i < vectorStr.length; i++) {
		printCvecValueString(&vectorStr, i);
	}
	printf("STRING ENDE!!!!\n\n");

//--------------------------
// Push content into vector 
//--------------------------
	printf("Fill vector with content!\n");

	cvec_insert_range(&vector, 0, arr);

	// Push singel value into vector
	cvec_push_back(&vector, 10);

	cvec_insert_range(&vector, 4, arr2);
	
	for(size_t i = 0; i < vector.length; i++) {
		printCvecValue(&vector, i);
	}
	printf("Cvec-length: %zu, Cvec-capacity: %zu, Cvec-sizeof: %zu\n\n", vector.length, vector.capacity, sizeof(vector));

	// Insert value at a specific index
	cvec_insert(&vector, 7, 36);

	for(size_t i = 0; i < vector.length; i++) {
		printCvecValue(&vector, i);
	}
	printf("Cvec-length: %zu, Cvec-capacity: %zu, Cvec-sizeof: %zu\n\n", vector.length, vector.capacity, sizeof(vector));

//------------------------------
// Erasing elements from vector
//------------------------------
	printf("Deleting elements from vector!\n");

	erase(&vector, 5);
	for(size_t i = 0; i < vector.length; i++) {
		printCvecValue(&vector, i);
	}
	printf("Cvec-length: %zu, Cvec-capacity: %zu, Cvec-sizeof: %zu\n\n", vector.length, vector.capacity, sizeof(vector));
	
	erase_range(&vector, 1, 3);
	for(size_t i = 0; i < vector.length; i++) {
		printCvecValue(&vector, i);
	}
	printf("Cvec-length: %zu, Cvec-capacity: %zu, Cvec-sizeof: %zu\n\n", vector.length, vector.capacity, sizeof(vector));

//------------------------
// Shrink to fit and free
//------------------------
	printf("Shrink cpacity of vecotor to fit actual length and free it!\n");

	shrink_to_fit(&vector);
	printf("Cvec-length: %zu, Cvec-capacity: %zu, Cvec-sizeof: %zu\n\n", vector.length, vector.capacity, sizeof(vector));

	cvec_free(&vector);
	cvec_free(&vectorStr);

	return 0; 
}
