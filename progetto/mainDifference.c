#include "website.c"
#include "filedistance.h"
#include <time.h>

int main(void)
{
    edit *script;
    char *input1 = loadFile("input1.txt");
    char *input2 = loadFile("input2.txt");
    int distance = levenshtein_distance(input1, input2);
    script=levenshtein_matrix_calculate;
  for (int i = 0; i < 100; i++) {
        print(&script[i]);
    }

    return 0;
}