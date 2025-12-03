#include "cvec_internals.h"


// push_back wrapper functinos for specific datatypes
/*
 * Each function passes the address of the local variable 'value' to push_back().
 * The value stored at that address is then copied into the vector's memory.
 */
CvecError cvec_push_char(Cvec *v, char value) { return push_back(v, &value, CVEC_INTEGER); }
CvecError cvec_push_uchar(Cvec *v, unsigned char value) { return push_back(v, &value, CVEC_INTEGER); }
CvecError cvec_push_string(Cvec *v, const char* str) 
{
	// Create a heap-allocated copy of the input string.
	// strdup() uses malloc() internally, and must be freed -> cvec_free().
	// The copy is importand because the original string can be created on the stack like a temporary address in a fuction and not a const string-literal.
	char *copy_str = strdup(str);
	if (!copy_str) {
		return CVEC_ERR_ALLOC;
	}
	// Pass the address of the copy (i.e., a pointer to the heap-allocated string -> type char**) into push_back, which will store it in the vector.
	return push_back(v, &copy_str, CVEC_STRING);
}

CvecError cvec_push_bool(Cvec *v, bool value) { return push_back(v, &value, CVEC_INTEGER); }

CvecError cvec_push_short(Cvec *v, short value) { return push_back(v, &value, CVEC_SHORT); }
CvecError cvec_push_int(Cvec *v, int value) { return push_back(v, &value, CVEC_INTEGER); }
CvecError cvec_push_uint(Cvec *v, unsigned int value) { return push_back(v, &value, CVEC_UINTEGER); }
CvecError cvec_push_long(Cvec *v, long value) { return push_back(v, &value, CVEC_LONG); }
CvecError cvec_push_ulong(Cvec *v, unsigned long value) { return push_back(v, &value, CVEC_ULONG); }
CvecError cvec_push_llong(Cvec *v, long long value) { return push_back(v, &value, CVEC_LONG_LONG); }
CvecError cvec_push_ullong(Cvec *v, unsigned long long value) { return push_back(v, &value, CVEC_ULONG_LONG); }

CvecError cvec_push_float(Cvec *v, float value) { return push_back(v, &value, CVEC_FLOAT); }
CvecError cvec_push_double(Cvec *v, double value) { return push_back(v, &value, CVEC_DOUBLE); }
CvecError cvec_push_ldouble(Cvec *v, long double value) { return push_back(v, &value, CVEC_LONG_DOUBLE); }


// Get functions for specific types
GetValueChar get_char(Cvec *v, size_t index) 
{
	char val;
	CvecError getVal = get_copy(v, index, &val);
	if(getVal == CVEC_OK) {
		return (GetValueChar) { .value = val, .err = CVEC_OK };
	}
	return (GetValueChar) { .err = CVEC_ERR_INDEX_OUT_OF_BOUNDS };
}

GetValueString get_string(Cvec *v, size_t index) 
{
	char* val;
	CvecError getVal = get_copy(v, index, &val);
	if(getVal == CVEC_OK) {
		return (GetValueString) { .value = val, .err = CVEC_OK };
	}
	return (GetValueString) { .err = CVEC_ERR_INDEX_OUT_OF_BOUNDS };
}

GetValueInt get_int(Cvec *v, int index) 
{
	int val;
	CvecError getVal = get_copy(v, index, &val);
	if(getVal == CVEC_OK) {
		return (GetValueInt) { .value = val, .err = CVEC_OK };
	}
	return (GetValueInt) { .err = CVEC_ERR_INDEX_OUT_OF_BOUNDS };
}

GetValueFloat get_float(Cvec *v, int index) 
{
	float val;
	CvecError getVal = get_copy(v, index, &val);
	if(getVal == CVEC_OK) {
		return (GetValueFloat) { .value = val, .err = CVEC_OK };
	}
	return (GetValueFloat) { .err = CVEC_ERR_INDEX_OUT_OF_BOUNDS };
}

GetValueDouble get_double(Cvec *v, int index) 
{
	double val;
	CvecError getVal = get_copy(v, index, &val);
	if(getVal == CVEC_OK) {
		return (GetValueDouble) { .value = val, .err = CVEC_OK };
	}
	return (GetValueDouble) { .err = CVEC_ERR_INDEX_OUT_OF_BOUNDS };
}


// Insert wrapper functinos for specific datatypes
/*
 * Each function passes the address of the local variable 'value' and an indeex value to insert().
 * The value stored at that address is then copied into the vector's memory.
 */
CvecError insert_char(Cvec *v, size_t index, char value) { return insert(v, index, &value, CVEC_CHAR); }
CvecError insert_uchar(Cvec *v, size_t index, unsigned char value) { return insert(v, index, &value, CVEC_UCHAR); }
CvecError insert_string(Cvec *v, size_t index, const char* str) 
{
	char *copy_str = strdup(str);
	if (!copy_str) {
		return CVEC_ERR_ALLOC;
	}
    return insert(v, index, &copy_str, CVEC_STRING);
}

CvecError insert_bool(Cvec *v, size_t index, int value) { return insert(v, index, &value, CVEC_BOOL); }

CvecError insert_short(Cvec *v, size_t index, short value) { return insert(v, index, &value, CVEC_SHORT); }
CvecError insert_int(Cvec *v, size_t index, int value) { return insert(v, index, &value, CVEC_INTEGER); }
CvecError insert_uint(Cvec *v, size_t index, unsigned int value) { return insert(v, index, &value, CVEC_UINTEGER); }
CvecError insert_long(Cvec *v, size_t index, long value) { return insert(v, index, &value, CVEC_LONG); }
CvecError insert_llong(Cvec *v, size_t index, long long value) { return insert(v, index, &value, CVEC_LONG_LONG); }
CvecError insert_ulong(Cvec *v, size_t index, unsigned long value) { return insert(v, index, &value, CVEC_ULONG); }
CvecError insert_ullong(Cvec *v, size_t index, unsigned long long value) { return insert(v, index, &value, CVEC_ULONG_LONG); }

CvecError insert_float(Cvec *v, size_t index, float value) { return insert(v, index, &value, CVEC_FLOAT); }
CvecError insert_double(Cvec *v, size_t index, double value) { return insert(v, index, &value, CVEC_DOUBLE); }
CvecError insert_ldouble(Cvec *v, size_t index, long double value) { return insert(v, index, &value, CVEC_LONG_DOUBLE); }


CvecError insert_range_char(Cvec *v, size_t index, char *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_uchar(Cvec *v, size_t index, unsigned char *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_string(Cvec *v, size_t index, char **arr, size_t arr_length) 
{
    // Array of heap-pointers
    char **str_arr_copy = malloc(arr_length * sizeof(char*));
    if (!str_arr_copy) return CVEC_ERR_ALLOC;

    for (size_t i = 0; i < arr_length; i++) 
	{
        str_arr_copy[i] = strdup(arr[i]);
        if (!str_arr_copy[i]) {
            // Cleaning, if strdup fails
            for (size_t j = 0; j < i; j++) free(str_arr_copy[j]);
            free(str_arr_copy);
            return CVEC_ERR_ALLOC;
        }
    }

    CvecError err = insert_range(v, index, arr_length, str_arr_copy, CVEC_STRING);

    // Optional: wenn insert_range die Ownership übernimmt, dann hier nichts freigeben
    // ansonsten:
    free(str_arr_copy);

    return err;
}

CvecError insert_range_short(Cvec *v, size_t index, short *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_int(Cvec *v, size_t index, int *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_uint(Cvec *v, size_t index, unsigned int *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_long(Cvec *v, size_t index, long *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_llong(Cvec *v, size_t index, long long *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_ulong(Cvec *v, size_t index, unsigned long *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_ullong(Cvec *v, size_t index, unsigned long long *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }

CvecError insert_range_float(Cvec *v, size_t index, float *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_double(Cvec *v, size_t index, double *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }
CvecError insert_range_ldouble(Cvec *v, size_t index, long double *arr, size_t arr_length) { return insert_range(v, index, arr_length, arr, CVEC_INTEGER); }

