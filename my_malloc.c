#include <assert.h>
#include <stdio.h>
#include <unistd.h>

// one sided Linklist
struct metaData_block
{
    size_t size;
    struct metaData_block* next;
    int free;

};


// Not having magic number like that
#define METADATA_SIZE sizeof(struct metaData_block)


// Head of the linkList of the request memory
void* global_head_block = NULL;

/*---------------*/


/*
 * **Last - is the head of the Linklist
 *  size - amount we want to check if it unused
 *
 *
 * */
struct metaData_block* findUnusedBlock(struct metaData_block** last, size_t size)
{
    struct metaData_block* curr = global_head_block;
    while(curr && !(curr->free && curr->size >= size))
    {
        *last = curr;
        curr = curr->next;
    }
    return curr;
}




struct metaData_block* reqSpace(struct metaData_block* b, size_t size)
{
    struct metaData_block* block = NULL;
    block = sbrk(0);
    void* req = sbrk(size + METADATA_SIZE);
    assert((void*)block == req);
    if(req == (void*) - 1)
    {
        return NULL;
    }

}

void* my_malloc(size_t size)
{
    if(global_head_block != NULL)
    {
        // Find freed memory
        // return something
    }
    

    void* head_of_memory = sbrk(0);
    void* requested_memory = sbrk(size + METADATA_SIZE);
    
    


    
}

int main(void)
{
    void* s = sbrk(0);
    printf("%p\n", s);
    printf("Here I am trying to create my own malloc xD\n");

    return 0;
}


