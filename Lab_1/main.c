#include <stdio.h>
#include <math.h>

int main(void) {

    int i;

    for (i = 100; i < 1000; i++) {

        int num_1 = i % 10;
        int num_2 = i / 10 % 10;
        int num_3 = i / 10 / 10;

        if (i == (int) pow(num_1, 3) + (int) pow(num_2, 3) + (int) pow(num_3, 3)) {
            printf("%i with %i %i %i\n", i, num_3, num_2, num_1);
        }
    }

    return 0;
}
