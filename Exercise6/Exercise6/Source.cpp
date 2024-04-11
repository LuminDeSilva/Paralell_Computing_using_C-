/*
	Ex 06:-
		Circulate a string msg from master using ring communication model
*/

#include<stdio.h>
#include<mpi.h>
#include<string>

int main() {
	int np;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Status status;
	if (pid == 0) {
		char send[50] = "Hello";
		MPI_Send(&send,50, MPI_CHAR, 1, 50, MPI_COMM_WORLD);
		printf("My process id is %d and I'm sender to 1. Message is %s\n", pid,send);
		char rec_msg[50];
		MPI_Recv(&rec_msg, 50, MPI_CHAR, np - 1, 50, MPI_COMM_WORLD, &status);
		printf("My process id is %d and I'm the reciever. Recieved from process id %d. Message is %s\n", pid,np-1, rec_msg);
	}
	else if (pid!=np-1){
		char rec_msg1[50];
		MPI_Recv(&rec_msg1, 50, MPI_CHAR, pid - 1, 50, MPI_COMM_WORLD, &status);
		printf("My process id is %d and I'm the reciever. Recieved from process id %d. Message is %s\n", pid, pid - 1, rec_msg1);
		MPI_Send(&rec_msg1, 50, MPI_CHAR,pid+1, 50, MPI_COMM_WORLD);
		printf("My process id is %d and I'm sender to %d. Message is %s\n", pid,pid+1, rec_msg1);
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