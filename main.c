#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    srand(time(0));
    
    pid_t p1;
    p1 = fork();
    int num1 = 1 + rand() % 5;

    if (p1<0) {
        perror("fork fail");
        exit(1);
    }

    if (p1 == 0) {
        //in child process
        printf("%d ", getpid());
        printf("%d\n", num1);
        sleep(num1);
        printf("%d finished after %d seconds.\n", getpid(), num1);
        return 0;
    }

    pid_t p2;
    p2 = fork();
    int num2 = 1 + rand() % 5;

    if (p2<0) {
        perror("fork fail");
        exit(1);
    }

    if (p2 == 0) {
        //in child process
        printf("%d ", getpid());
        printf("%d\n", num2);
        sleep(num2);
        printf("%d finished after %d seconds.\n", getpid(), num2);
        return 0;
    }

    printf("%d about to create 2 child processes\n", getpid());
    int *status;
    wait(status);
    printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), p1, num1);
}
