#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    int next;
};

void write_into_arr(struct node* mem, int value, int *wrt_ptr){
    if(*wrt_ptr != -1 ){
        // write data to current position of write_ptr
        mem[*wrt_ptr].value = value;

        // move write_ptr to next position
        *wrt_ptr = mem[*wrt_ptr].next;
    }
    else{
        printf("The array is full, you cannot writte into it.\n");
    }
}

int read_from_mem(struct node* mem, int index, int *wrt_ptr){
    int result = mem[index].value;
    int temp = *wrt_ptr;

    // update the write_ptr
    *wrt_ptr = index;
    mem[*wrt_ptr].next = temp;

    return result;
}

int main(){
    int size = 100, r1;
    struct node mem[100];
    // struct node *mem = (struct node*) malloc(size * sizeof(struct node));

    int wrt_ptr = 0;

    for (int i= 0; i < (size-1); i++){
        mem[i].next = i+1;
    }
    mem[size-1].next = -1;

    for (int i= 0; i < 101; i++){
        write_into_arr(mem,i,&wrt_ptr);
    }
    r1 = read_from_mem(mem,2,&wrt_ptr);
    printf("reading at index = %d ,value= %d\n",2,r1);

    r1 = read_from_mem(mem,4,&wrt_ptr);
    printf("reading at index = %d ,value= %d\n",4,r1);

    write_into_arr(mem,87,&wrt_ptr);
    printf("writting value= %d\n",87,r1);

    r1 = read_from_mem(mem,4,&wrt_ptr);
    r1 = printf("reading at index = %d ,value= %d\n",4,r1);


    
    // free(mem);
    return 0;
}