#include "filedistance.h"

#include <time.h>

int main(void)
{
    
    char *input1 = loadFile("input1.txt");
    char *input2 = loadFile("input2.txt");
    clock_t t;
    t = clock();

    unsigned int distance = levenshtein_distance(input1, input2);
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("Distance is: %d\n", distance);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}