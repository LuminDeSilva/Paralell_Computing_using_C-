#include<mpi.h>	//contain the mpi function type declaration 
#include<stdio.h>	//stands for "standard input output"

int main() {
	int np;	//no of processors
	int pid;	//no of processor id
	MPI_Init(NULL, NULL);	//Intialize the MPI execution environment
	MPI_Comm_size(MPI_COMM_WORLD, &np);	//Determines the size of the group associate with the communication MPI_COMM_WORLD is the default communicator
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);	//Determines the rank of the calling process in the communicator 
	printf("\nHello world ........ \nMy pid = %d \nNo of Process = %d", pid, np);
	MPI_Finalize();	//Terminate the mpi execution environment


	return 0;
}