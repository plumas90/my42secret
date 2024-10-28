#include "ft_print_memory.c"

int main() {
    char data[] = "Bonjour les aminches\t\n\tc  est fou\t\n tout ce qu on peut faire avec\n\tprint_memory\n\n\n\tlol.lol\n ";
    ft_print_memory(data, sizeof(data) - 1);
    return 0;
}
