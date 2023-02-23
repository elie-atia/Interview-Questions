

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MEM_LENGTH 10

// the arrival packets
struct packet
{
    int priority;
    int arrival_time;
    struct packet *next;
};

int chooseRandoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
// funct insert(packet_inter) add the arrival packet_inter to the memory
int insert(struct packet pck_to_insert,
           struct packet **heads_arr,
           struct packet **tails_arr,
           struct packet *head_hole,
           struct packet *tail_hole,
           int num_of_packet,
           struct packet *memory_packets)
{
    int priority_num = pck_to_insert.priority;
    struct packet *ptr_to_packet_inserted;

    // Case: Memory is full => error, exit the function.
    if (num_of_packet >= MEM_LENGTH)
    {
        printf("\n         ERROR: PACKET INTERFACE MEMORY IS FULL   \n");
        return 0;
    }

    printf("\nInserted Packet: time:%d , priority:%d\n", pck_to_insert.arrival_time, pck_to_insert.priority);

    // Case: No hole in the memrory => insert packet at the first empty place.
    if (head_hole == NULL)
    {
        memory_packets[num_of_packet].arrival_time = pck_to_insert.arrival_time;
        memory_packets[num_of_packet].priority = pck_to_insert.priority;
        ptr_to_packet_inserted = &memory_packets[num_of_packet];
    }

    // Case: There is a single hole in the memory => "fill the hole" and update the hole's ptr.
    else if (head_hole->next == NULL)
    {
        head_hole->arrival_time = pck_to_insert.arrival_time;
        head_hole->priority = pck_to_insert.priority;
        ptr_to_packet_inserted = head_hole;
        head_hole = NULL;
        tail_hole = NULL;
    }

    // Case: There is multiple holes in the memory => update the "hole linked list".
    else
    {
        head_hole->arrival_time = pck_to_insert.arrival_time;
        head_hole->priority = pck_to_insert.priority;
        ptr_to_packet_inserted = head_hole;
        head_hole = head_hole->next;
    }

    // Case: the linked list corresponding to the packet is empty => create it.
    if (heads_arr[priority_num] == NULL)
    {
        heads_arr[priority_num] = ptr_to_packet_inserted;
        tails_arr[priority_num] = ptr_to_packet_inserted;
    }

    // Case: the linked list corresponding to the packet exist => update it.
    else
    {
        tails_arr[priority_num]->next = ptr_to_packet_inserted;
        tails_arr[priority_num] = ptr_to_packet_inserted;
    }

    return 1;
}

// funct get_packet() return the packet interface from the memory according to the rules order
int get_packet(
    struct packet **heads_arr,
    struct packet **tails_arr,
    struct packet *head_hole,
    struct packet *tail_hole,
    struct packet *memory_packets,
    struct packet *output_packet
    )
{
    int priority_num = -1;
    output_packet->priority = -1;
    struct packet *ptr_to_packet_getted;


    // Find the priority num of the "most updated packet".
    if (heads_arr[0] != NULL)
    {
        priority_num = 0;
    }
    else if (heads_arr[1] != NULL)
    {
        priority_num = 1;
    }
    else if (heads_arr[2] != NULL)
    {
        priority_num = 2;
    }
    else if (heads_arr[3] != NULL)
    {
        priority_num = 3;
    }
    else
    {
        printf("\nERROR: YOU TRY TO GET A PACKET, BUT NO PACKET IS AVAIABLE\n");
        return 0;
    }
    
    output_packet->arrival_time = heads_arr[priority_num]->arrival_time;
    output_packet->priority = heads_arr[priority_num]->priority;

    ptr_to_packet_getted = heads_arr[priority_num];

    // Update the linked list of the corresponding to the get packet:
    if (heads_arr[priority_num] == tails_arr[priority_num])
    {
        heads_arr[priority_num] = NULL;
        tails_arr[priority_num] = NULL;
    }
    else
    {
        heads_arr[priority_num] = heads_arr[priority_num]->next;
    }

    // Update the hole linked list.
    if (head_hole == NULL)
    {
        head_hole = ptr_to_packet_getted;
        tail_hole = ptr_to_packet_getted;
    }
    else
    {
        tail_hole->next = ptr_to_packet_getted;
        tail_hole = ptr_to_packet_getted;
    }
    ptr_to_packet_getted->next = NULL;

    printf("\n   Get   Packet: time:%d , priority:%d\n", output_packet->arrival_time, output_packet->priority);

    return -1;
}

int main()
{
    struct packet memory_packets[MEM_LENGTH], // Memory array of the packets interface
                                       // pointers to write/read from the memory.
        *heads_arr[4], *tails_arr[4], *head_hole = NULL, *tail_hole = NULL,
                                      pck1, pck2; // packets declarations

    struct packet output_packet[1];

    int num_of_packet = 0;

    for (int i = 0; i < 4; i++)
    {
        heads_arr[i] = NULL;
        tails_arr[i] = NULL;
    }

    // RANDOM SIMULATION:
    int curr_time = 0;
    srand(time(0));
    while (curr_time < MEM_LENGTH*300)
    {
        pck1.priority = chooseRandoms(0, 1);
        pck1.arrival_time = curr_time;
        curr_time++;

        num_of_packet += insert(pck1,
            heads_arr,
            tails_arr,
            head_hole,
            tail_hole,
            num_of_packet,
            memory_packets);

        if(chooseRandoms(0,1)){
            num_of_packet += get_packet(
                heads_arr,
                tails_arr,
                head_hole,
                tail_hole,
                memory_packets,
                output_packet);
        }
    }
    
    return 0;
}
