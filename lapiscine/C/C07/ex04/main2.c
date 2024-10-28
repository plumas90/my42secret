#include "ft_convert_base.c"
#include "ft_convert_base2.c"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    //char *nbr = "   -+2A";   // -42
    // char *nbr = "   -+-2A";  // 42
    // char *nbr = "-80000000"; //int min
    // char *nbr = "-0";
   //  char *nbr = "7FFFFFFF";  //int max
     char *nbr = "   -+  2A"; // not working
   // char *nbr = "--";
     //char *nbr = "B1327E5"; // 16 to bonus 
    char *base_from = "0123456789ABCDEF";
    //char *base_to = "01"; //itoa test
     char *base_to = "0123456789"; //atoi test
    // char *base_to = "lIe ouvy"; // bonus
    
    printf("%s\n", ft_convert_base(nbr,base_from,base_to));

    return 0;
}
