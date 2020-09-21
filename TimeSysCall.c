#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]){

        int ITERATIONS = 100000;
        struct timeval start, end;
        gettimeofday(&start, NULL);
        
        for (int i = 0; i < ITERATIONS; i++){
                getpid();
        }

        gettimeofday(&end, NULL);
        long seconds = (end.tv_sec - start.tv_sec);
        long seconds_ms = seconds * 1000000;
        long microseconds = seconds_ms + (end.tv_usec - start.tv_usec);
        double avg_ms = (float) microseconds / ITERATIONS;
	
        printf("Syscalls Performed: %d\n", ITERATIONS);
        printf("Total Elapsed Time: %ld microseconds\n", microseconds);
        printf("Average Time Per Syscall: %f microseconds\n", avg_ms);        

        return 0;
}
