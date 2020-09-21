#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

        int ITERATIONS = 5000;
        struct timeval start, end;
        gettimeofday(&start, NULL);

        for (int i = 0; i < ITERATIONS; i++){
                if (fork() == 0){
                        exit(0);
                } else {
                        wait(NULL);
                }
        }

        gettimeofday(&end, NULL);
        long seconds = (end.tv_sec - start.tv_sec);
        long microseconds = (seconds * 1000000) + (end.tv_usec - start.tv_usec);
        double avg_microseconds = (float) microseconds / ITERATIONS;

        printf("Forks Performed: %d\n", ITERATIONS);
        printf("Total Elapsed Time: %ld microseconds\n", microseconds);
        printf("Average Time Per Fork: %f microseconds\n", avg_microseconds);

	return 0;

}
