#include <stdio.h>
#include <string.h>

int compareArrays(int a[], int b[], int n) {
  int ii;
  for(ii = 1; ii <= n; ii++) {
    if (a[ii] != b[ii]) return 0;
  }
  return 1;
}

int measure_quantity_from_jars(int* jars,int size_jars, int* states, int quantity_to_find, int** past_states){
    int size_past_states = sizeof(past_states)/(sizeof(states));

    for(int i = 0; i < size_jars; i++){
        if(states[i] == quantity_to_find){
            printf("we found the quantity.\n");
            return 1;
        }
    }

    for(int i = 0; i < size_past_states; i++){
        if(compareArrays(states,past_states[i],size_jars)){
            return 0;
        }
    }
    
    for(int i = 0; i < size_jars; i++){
        if(states[i] == 0){
            printf("Fill the jar of size: %d.\n", jars[i]);
            int *new_state = (int*)malloc(size_jars * sizeof(int));
            strncpy(new_state, states, size_jars);

            new_state[i] = jars[i];
            // measure_quantity_from_jars(jars, new_quantities, quantity_to_find,past_states);
        }
    }
    
    return 0;
}


int main(){
    int jars[2] = {3,5}; //the size of each jars
    int size_jars = sizeof(jars)/sizeof(int); //the number of jars
    int *states = (int*)malloc(size_jars*sizeof(int)); //the quantity in each of the jars
    for(int i = 0; i < size_jars; i++){
        states[i] = 0;
    }

    int *past_states[1]; //all the past states (2D array)
    past_states[0] = (int*) malloc(size_jars*sizeof(int));
    strncpy(past_states[0], states, size_jars);
    int x = measure_quantity_from_jars(jars,size_jars,states,4,past_states);
    printf("%d", x);
    return 0;
}