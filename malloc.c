#include <stdlib.h>
#include <unistd.h>

#define ARR_SIZE 1000000

int main()
{
        sleep (15);
        int *arr = (int *)malloc (ARR_SIZE * sizeof(int));

        for (int i = 0; i < ARR_SIZE; i++) {
                arr[i] = 4;
        }
        return 0;
}
