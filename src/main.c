//this exists only to make xenomai happy. 

#include <stdio.h>
int main()
{
    printf("don't run this. it's an empty main function to make xenomai happy when building a static library!\n");
    return 0;
}
