/*
Ex03:
	Master should send an integer value to all other inter-connected processors
*/

#include<stdio.h>
#include<mpi.h>

int main() {
	int send;
	int recieve;
	int np;
	int pd;
	MPI_Status status;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pd);
	

	if (pd == 0) {
		int sendMsg = 50;
		for (int i = 0; i < np; i++) {
			MPI_Send(&sendMsg, 1, MPI_INT, i, 50, MPI_COMM_WORLD);
			printf("My processor id is %d and I'm the sender to pid %d\n", pd, i);
		}
	}
	else {
		int recieveMsg;
		MPI_Recv(&recieveMsg, 1, MPI_INT, 0, 50, MPI_COMM_WORLD, &status);
		printf("My processor id is %d and I'm the reciever to pid %d\n", pd, recieveMsg);
	}


	MPI_Finalize();
	

	return 0;
}