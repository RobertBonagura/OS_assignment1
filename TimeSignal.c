#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

int counter = 0;
int ITERATIONS = 100000;
struct timeval start, end;

void handle_sigfpe(int signum){

        counter++;
        if (counter >= ITERATIONS) {
                gettimeofday(&end, NULL);
                long seconds = (end.tv_sec - start.tv_sec);
                long seconds_ms = seconds * 1000000;
                long microseconds = seconds_ms + (end.tv_usec - start.tv_usec);
                double avg_ms = (float) microseconds / counter;
                printf("Exceptions Occured: %d\n", counter);
                printf("Total Elapsed Time: %ld microseconds\n", microseconds);
                printf("Average Time Per Syscall: %f microseconds\n", avg_ms);
                exit(0);
        } else {
                // Do nothing -- Return to line 35
        }
}

int main(int argc, char *argv[]){

        int x = 5;
        int y = 0;
        int z;
        signal(SIGFPE, handle_sigfpe);
        gettimeofday(&start, NULL);
        z = x / y;
        return 0; 
}
