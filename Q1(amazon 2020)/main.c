

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h> 



//the arrival packets
struct packet {
    int priority;
    int arrival_time;
    struct packet* next;
};

int chooseRandoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    //printf("%d ", num); 
    return num;

}
//funct insert(packet_inter) add the arrival packet_inter to the memory
int insert(struct packet pck_local,
    struct packet** heads_arr,
    struct packet** tails_arr,
    struct packet* wrt_ptr,
    struct packet* ptr_to_last_hole,
    int cnt_avaibalbe_packet,
    int holes_val,
    struct packet* memory_packets
) {
    int priority_num = pck_local.priority;
    if (cnt_avaibalbe_packet == 100) {
        printf("\n          ERROR: PACKET INTERFACE MEMORY IS FULL   \n");
        return cnt_avaibalbe_packet;
    }
    else {
        cnt_avaibalbe_packet++;
        if (holes_val != 0) {
            holes_val--;
        }
        struct packet* wrt_ptr_next = wrt_ptr->next;
        *wrt_ptr = pck_local;
        printf("\nInserted Packet: time:%d , priority:%d\n", pck_local.arrival_time, pck_local.priority);
        //update the heads/tails pointers
        if (heads_arr[priority_num] == NULL) {
            heads_arr[priority_num] = wrt_ptr;
            tails_arr[priority_num] = wrt_ptr;
        }
        else {
            tails_arr[priority_num]->next = wrt_ptr;
            tails_arr[priority_num] = wrt_ptr;
        }


        if (holes_val == 0) {
            wrt_ptr = &memory_packets[cnt_avaibalbe_packet];
        }
        else {    //each hole have a pointer to the next hole
            wrt_ptr = wrt_ptr_next;
        }
        return cnt_avaibalbe_packet;
    }
}

// funct get_packet() return the packet interface from the memory according to the rules order
struct packet get_packet(
    struct packet** heads_arr,
    struct packet** tails_arr,
    struct packet* wrt_ptr,
    struct packet* ptr_to_last_hole,
    int cnt_avaibalbe_packet,
    int holes_val,
    struct packet* memory_packets
   ) {
   bool get_succes = 1;

   struct packet output_packet;
   int priority_num = -1;
   
    if (heads_arr[0] != NULL) {
        priority_num = 0;
    }
    else if (heads_arr[1] != NULL){
        priority_num = 1;
    }
    else if (heads_arr[2] != NULL){
        priority_num = 2;
    }
    else if (heads_arr[3] != NULL){
        priority_num = 3;
    }
    else{
        printf( "\nERROR: YOU TRY TO GET A PACKET, BUT NO PACKET IS AVAIABLE\n");
        get_succes = 0;
    }
    
    if (get_succes == 1) {
        output_packet.arrival_time = heads_arr[priority_num]->arrival_time;
        output_packet.priority = heads_arr[priority_num]->priority;

        if (heads_arr[priority_num] != tails_arr[priority_num]) {
            heads_arr[priority_num] = heads_arr[priority_num]->next;
        }
        else {
           heads_arr[priority_num] = NULL;
           tails_arr[priority_num] = NULL;
        }
        cnt_avaibalbe_packet--;
        holes_val++;       
        if (holes_val > 1) {
            wrt_ptr->next = heads_arr[priority_num];
        }
        wrt_ptr = heads_arr[priority_num];
        printf("\n   Get   Packet: time:%d , priority:%d\n", output_packet.arrival_time, output_packet.priority);

    }
    return output_packet;
}

int main()
{
    struct packet memory_packets[100]; //memory array of the packets interface
//pointers to write/read from the memory
    struct packet* heads_arr[4], * tails_arr[4], * wrt_ptr = memory_packets, * ptr_to_last_hole = NULL;
    //the eight-element pointers are considered as follows:
                                       // [head0,tail0,head1,tail1,...,head3,tail3, wrt_ptr, ptr_to_last_hole]
    for (int i = 0; i < 4; i++) {
        heads_arr[i] = NULL;
        tails_arr[i] = NULL;
    }
    int holes_val = 0, cnt_avaibalbe_packet = 0;

    /////packets declarations
    struct packet pck1,pck2;

    //funct insert(packet_inter) add the arrival packet_inter to the memory

    int curr_time = 0, nmbr_or_inserted_packets = 0;
    srand(time(0));
    while (nmbr_or_inserted_packets < 320) {
        printf("%d",cnt_avaibalbe_packet);
        pck1.priority = chooseRandoms(0, 3);
        pck1.arrival_time = curr_time;
        curr_time++;
        printf("try to insert a packet at time : % d with prioriy = % d\n", pck1.arrival_time, pck1.priority);
        cnt_avaibalbe_packet =  insert(pck1,
            heads_arr,
            tails_arr,
            wrt_ptr,
            ptr_to_last_hole,
            cnt_avaibalbe_packet,
            holes_val,
            memory_packets);
        nmbr_or_inserted_packets++;

        pck2 = get_packet(
            heads_arr,
            tails_arr,
            wrt_ptr,
            ptr_to_last_hole,
            cnt_avaibalbe_packet,
            holes_val,
            memory_packets);
            printf("priority: %d, time: %d", pck2.priority, pck2.arrival_time);
        /*   if (chooseRandoms(0, 1)) {
               get_packet(
                  head0,
                   head1,
                   head2,
                 head3,
                   tail0,
                   tail1,
                  tail2,
                 tail3,
                   cnt_avaibalbe_packet,
                  holes_val,

                   wrt_ptr,
                  ptr_to_last_hole,
                  memory_packets);
           }*/
    }

    return 0;
}
