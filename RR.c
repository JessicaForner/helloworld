#include <stdio.h>
#include <unistd.h>
#include <time.h>

void task1() {
    printf("Task 1\n");
}

void task2() {
    printf("Task 2\n");
}

void task3() {
    printf("Task 3\n");

}

void printSecondsElapsed(void (*fonction)()) {
    clock_t start_time = clock();
    clock_t current_time;
    int seconds_elapsed = 0;

    while (1) {
        // Get the current clock time
        current_time = clock();

        // Calculate elapsed time in seconds
        int  a = (int)(current_time - start_time) / CLOCKS_PER_SEC;

        if(a>seconds_elapsed)
        {
            seconds_elapsed = a;
            fonction();
        }


        clock_t delay = CLOCKS_PER_SEC;

        while ((clock() - current_time) < delay) {
            // Busy-wait until the desired time has passed
        }

        if(seconds_elapsed>=1)
        {
            break;
        }
    }
}

int main() {
    int numIterations = 3;
    int i;
    for (i = 0; i < numIterations; ++i)
    {
        task1();
        task2();
        task3();
    }

    // With timer
    printf("With the timer \n");
    for (i = 0; i < numIterations; ++i)
    {
        printSecondsElapsed(task1);
        printSecondsElapsed(task2);
        printSecondsElapsed(task3);
    }

    return 0;
}
