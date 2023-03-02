#include <stdio.h>
#include <string.h>

int compareArrays(int a[], int b[], int n) {
  int ii;
  for(ii = 0; ii < n; ii++) {
    if (a[ii] != b[ii]) 
        return 0;
  }
  return 1;
}
// function to copy an array
void copyArray(int copy[], int arr[], int size)
{
  // loop to iterate through array
  for (int i = 0; i < size; i++)
  {
    copy[i] = arr[i];
  }
}

void print_array(int* arr){
    int size = sizeof(arr)/sizeof(int);
    printf("arr size:%d\n",size);
    for(int i = 0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}



int measure_quantity_from_jars(int* jars,int size_jars, int* state, int quantity_to_find, int** past_states){
    int size_past_states, result;
    
    if(past_states == NULL){
        size_past_states = 0;
    }
    else{
        size_past_states = sizeof(past_states)/(sizeof(int*));
    }
    printf("STATE:\n");
    print_array(state);

    printf("PAST STATES:\n");
    for(int i =0; i< size_past_states; i++){
        print_array(past_states[i]);
    }

    if(size_jars == 0 || state == NULL){
        printf("error occurs\n");
        return 0;
    }

    //Check if we have the quantity in the states:
    for(int i = 0; i < size_jars; i++){
        if(state[i] == quantity_to_find){
            printf("we found the quantity.\n");
            return 1;
        }
    }

    //Iteration call 1: fill each of the empty jars
    for(int i = 0; i < size_jars; i++){
  


        if(state[i] == 0){
            printf("Fill the jar of size: %d.\n", jars[i]);
            //Allocate memory of the new array.
            //Initialize memroy of the new array.
             //Free the memory of the past array.
            //Check if the current state is in the past array.
            int** new_past_states = malloc((size_past_states + 1) * sizeof(int*));

            for (int i = 0; i < size_past_states; i++) {
                if(compareArrays(state,past_states[i],size_jars)){
                    printf("same state was found\n");
                    // print_status(state, past_states);
                    return 0;
                }   
                new_past_states[i] = malloc(size_jars * sizeof(int));
                copyArray(new_past_states[i], past_states[i],size_jars);
                //free(past_states[i]);

            }
            //free(past_states);

            new_past_states[size_past_states] = malloc(size_jars * sizeof(int));
            copyArray(new_past_states[size_past_states], state,size_jars);
            
            int *new_state = malloc(size_jars * sizeof(int));
            copyArray(new_state, state, size_jars);
            new_state[i] = jars[i];
            //free(state);
            result += measure_quantity_from_jars(jars,size_jars,new_state, quantity_to_find,new_past_states);
        }
    }

    // //Iteration call 2: try to empty each of the full jars
    // for(int i = 0; i < size_jars; i++){
    //     if(state[i] != 0){
    //         printf("Fill the jar of size: %d.\n", jars[i]);
    //         int *new_state = malloc(size_jars * sizeof(int));
    //         copyArray(new_state, state, size_jars);
    //         new_state[i] = jars[i];
    //         measure_quantity_from_jars(jars,size_jars,new_state, quantity_to_find,new_past_states);
    //     }
    // }
    
    return result;
}


int main(){
    int jars[2] = {3,5}; //the size of each jars
    int size_jars = sizeof(jars)/sizeof(int); //the number of jars
    // int *states = malloc(size_jars*sizeof(int)); //the quantity in each of the jars
    // for(int i = 0; i < size_jars; i++){
    //     states[i] = 0;
    // }
    int state[2] = {0,0};
    int **past_states = NULL; //all the past states (2D array)
    int x = measure_quantity_from_jars(jars,size_jars,state,4,past_states);
    printf("%d", x);
    return 0;
}