#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>

// Place any necessary global variables here
int ITERATIONS = 5000;

int main(int argc, char *argv[]){

        // 1. Save start time using gettimeofday().
        struct timeval start, end;
        gettimeofday(&start, NULL);

        // For 5,000 times:
        //      1. Call fork() and then wait() or waitpid()
        //      2. Child process should immediately terminiate with exit() or return
        for (int i = 0; i < ITERATIONS; i++){
                if (fork() == 0){
                        exit(0);
                } else {
                        wait(NULL);
                }
        }

        // 3. Calculate time elapsed and average syscall using floating point arithemtic. 
        gettimeofday(&end, NULL);

        long seconds = (end.tv_sec - start.tv_sec);
        long microseconds = ((seconds * 1000000) + end.tv_usec ) - (start.tv_usec);
        printf("Time elapsed is %ld seconds and %ld miliseconds\n", seconds, microseconds);

	return 0;

}
