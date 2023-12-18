#include<stdio.h>
#include <time.h>

double summ(double a, double b)
{
    double c = a+b;
    return c;
}
int binarySearch(const int array[], int taille, int cible) {
    int debut = 0;
    int fin = taille - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;


        if (array[milieu] == cible) {
            return milieu;
        }

        else if (array[milieu] > cible) {
            fin = milieu - 1;
        }

        else {
            debut = milieu + 1;
        }
    }

    return -1;
}

void printSecondsElapsed() {
    clock_t start_time = clock();
    clock_t current_time;

    while (1) {
        // Get the current clock time
        current_time = clock();

        // Calculate elapsed time in seconds
        double seconds_elapsed = (double)(current_time - start_time) / CLOCKS_PER_SEC;

        // Print the seconds elapsed
        printf("Seconds elapsed: %.2f\n", seconds_elapsed);

        clock_t delay = CLOCKS_PER_SEC;
        while ((clock() - current_time) < delay) {
            // Busy-wait until the desired time has passed
        }

        if(seconds_elapsed>4)
        {
            break;
        }
    }
}

int main()
{
    printf("Hello World \n");

    //

    int a1 = 2;
    int a2 = 3;
    int a = a1+a2;
    printf("%d + %d = %d \n", a1, a2, a);

    //

    int b = 2;
    int c = 3;
    printf("The numbers are b = %d and c = %d \n", b, c);
    if(c<b)
    {
        printf("the larger number is b : %d", b);
    }
    else
    {
        printf("the larger number is c : ");
    }

    //
    int i;
    for(i= 1; i<101; i++)
    {
        printf("For loop : i = %d \n", i);
    }

    //

    int j=1;
    while(j<101)
    {
        printf("Wile loop : i = %d \n", j);
        j ++;
    }

    //

    int d = 10;
    printf("the value of d is : %d and the memory address is : %d \n", d, &d);


    //

    double e1 = 10.0;
    double e2 = 14.5;
    double e = summ(e1, e2);
    printf("La somme de %f et de %f est egale a : %f \n", e1,e2,e);

    //

    int array_list[3] = {1,5,4};
    int size = sizeof(array_list)/sizeof(int);
    int idx;
    int value_to_find = 5;
    int found = 0;
    for(idx = 0; idx<size+1; idx++)
    {
        if(value_to_find==array_list[idx])
        {
            found = 1;
            break;
        }
    }
    printf("In the list we have : \n");
    for(i = 0;i<size;i++)
        {
            printf("%d \n", array_list[i]);
        }
    if(found == 1)
    {
        printf("The value %d is found in the list\n", value_to_find );
    }

    //

    int list[] = {2,3,5, 8, 15, 26};
    size = sizeof(list)/sizeof(int);
    printf("In the list we have : \n");
    for(i = 0;i<size;i++)
        {
            printf("%d \n", list[i]);
        }
    value_to_find = 15;
    int index = binarySearch(list, size, value_to_find);

    if (index != -1) {
        printf("the value %d is found \n", value_to_find);
    } else {
        printf("the value %d is NOT found \n", value_to_find);
    }

    //

    printSecondsElapsed();

    return 0;

}


