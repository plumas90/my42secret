#include <stdio.h>
#include "ft_strjoin.c"
int main()
{
    char *strs[] = {"Hello", "world", "this", "is", "C"};
    char *sep = ", ";
    int size = 5;

    char *result = ft_strjoin(size, strs, sep);
    if (result)
    {
        printf("Joined string: %s\n", result);
        free(result);
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return 0;
}
