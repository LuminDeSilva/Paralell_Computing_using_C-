/*
	Ex07:-
		Matser has an array arr={1,2,3,4,5} and master wants to send 2 elements from index 2 to process id 1.
*/

#include<stdio.h>
#include<mpi.h>

int main() {
	int np;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Status status;
	if (pid == 0) {
		int send[5] = {1,2,3,4,5};
		MPI_Send(&send[0], 2, MPI_INT, 1, 50, MPI_COMM_WORLD);
		printf("My process id is %d and I'm sender.\n", pid);
	}
	else if (pid != np - 1) {
		int rec_msg1[2];
		MPI_Recv(&rec_msg1, 2, MPI_INT, 0, 50, MPI_COMM_WORLD, &status);
		printf("My process id is %d and I'm the reciever.\n", pid);
		for (int i = 0; i < 2; i++) {
			printf("num[%d] = %d", i, rec_msg1[i]);
		}
	}
	else {
		char rec_msg2[50];
		MPI_Recv(&rec_msg2, 50, MPI_CHAR, pid - 1, 50, MPI_COMM_WORLD, &status);
		printf("My process id is %d and I'm the reciever. Recieved from process id %d. Message is %s\n", pid, pid - 1, rec_msg2);
		MPI_Send(&rec_msg2, 50, MPI_CHAR, 0, 50, MPI_COMM_WORLD);
		printf("My process id is %d and I'm sender to %d. Message is %s\n", pid, 0, rec_msg2);
	}
	MPI_Finalize();


	return 0;
}