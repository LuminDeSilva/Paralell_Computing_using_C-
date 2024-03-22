/*
Ex04 :
	Master have to send to recieve the process id from all other inter-connected processor
*/

#include<stdio.h>
#include<mpi.h>

int main() {
	int pid;
	int np;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Status status;

	if (pid == 0) {
		for (int i = 0; i < np; i++) {
			int recieveMsg;
			MPI_Recv(&recieveMsg, 1, MPI_INT, i, 50, MPI_COMM_WORLD, &status);
			printf("My processor id is %d and I'm the reciever from processor %d. Message is %d.\n", pid, i, recieveMsg);
		}
	}
	else {
		int sendMsg;
		MPI_Send(&sendMsg, 1, MPI_INT, 0, 50, MPI_COMM_WORLD);
		printf("My processor id is %d and I'm the sender the message is %d.\n", pid, sendMsg);
	}

	MPI_Finalize();

	return 0;
}