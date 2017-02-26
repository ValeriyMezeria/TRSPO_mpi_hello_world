#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define MASTER 0

int main (int argc, char *argv[]) { 
    int numtasks, taskid, len; 
    char hostname[MPI_MAX_PROCESSOR_NAME];

    // initialization MPI library
    MPI_Init(&argc, &argv); 

    // This function indicates the number of processes involved in a communicator. For MPI_COMM_WORLD, it indicates the total number of processes available.
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks); 

    // This function gives the rank of the process in the particular communicator’s group.
    MPI_Comm_rank(MPI_COMM_WORLD,&taskid); 

    // =)
    MPI_Get_processor_name(hostname, &len);
    printf ("Hello from task %d on %s!\n", taskid, hostname);
    if (taskid == MASTER) 
        printf("MASTER: Number of MPI tasks is: %d\n", numtasks); 
    MPI_Finalize(); 
}
