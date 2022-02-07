#include "custom_vector.h"
#include "memory_platform.h"


void vector_init(vector_t** vec)
{
    if((*vec) == NULL)
        (*vec) = memory_platform.rf_calloc(1, sizeof (vector_t));
    (*vec)->data = NULL;
    (*vec)->size = 0;
    (*vec)->count = 0;
}

rfSize vector_count(vector_t* vec)
{
    return vec->count;
}

void vector_add(vector_t* vec, void* value)
{
        if (vec->size == 0) {
                vec->size = 10;
                vec->data = memory_platform.rf_malloc(sizeof(void*) * vec->size);
                memory_platform.rf_memset(vec->data, '\0', sizeof(void*) * vec->size);
        }

        // condition to increase v->data:
        // last slot exhausted
        if (vec->size == vec->count) {
                vec->size *= 2;
                vec->data = memory_platform.rf_realloc(vec->data, sizeof(void*) * vec->size);
        }

        vec->data[vec->count] = value;
        vec->count++;
}

void vector_set(vector_t *vec, rfSize index, void *value)
{
        if (index >= vec->count) {
                return;
        }

        vec->data[index] = value;
}

void *vector_get(vector_t *vec, rfSize index)
{
        if (index >= vec->count) {
                return NULL;
        }

        return vec->data[index];
}

rfSize vector_empty(vector_t* vec) {
    return (vec->size == 0);
}

void vector_delete(vector_t *vec, rfSize index)
{
//        if (index >= vec->count) {
//                return;
//        }

//        //vec->data[index] = NULL;

//        rfSize i, j;
//        void **newarr = (void**)memory_platform.rf_malloc(sizeof(void*) * vec->count * 2);
//        for (i = 0, j = 0; i < vec->count; i++) {
//            if (i == index)
//                continue;
//            newarr[j] = vec->data[i];
//            j++;
//        }

//        memory_platform.rf_free(vec->data);

//        vec->data = newarr;
//        vec->count--;
    if (index >= vec->count) {
        return;
    }

    for (rfInt i = index; i < vec->count - 1; i++) {
        int j = i+1;
        vec->data[i] = vec->data[j];
    }

    vec->count--;
}

void vector_free(vector_t *vec)
{
    if (vec->data != NULL)
        memory_platform.rf_free(vec->data);
}

void* vector_begin(vector_t* vec){
    return vec->data;
}

void* vector_end(vector_t* vec){
   return vector_get(vec, vec->count);
}
