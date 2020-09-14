#include <stdlib.h>
#include <stdio.h>

int counter = 0;

void handle_sigfpe(int signum){

        counter++;
        if (counter >= 100000) {
                // jump forward to next instruction.
        } else {
                // terminate as usual.
        }
}

int main(int argc, char *argv[]){

        int x = 5;
        int y = 0;
        int z = 0;
        // 1. Use signal() or sigaction() to register signal handler for SIGFPE
        signal(SIGFPE, handle_sigfpe);
        z = x / y;
        return 0; 
}
