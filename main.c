#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * Vous pouvez avoir une variable globale pour gérer vos allocations et une pour le
 * thread-safe.
 */

void        *ft_malloc(size_t size)
{
    void    *ret;
    
    if      size <= tiny_size();
    ret = mmap(0, tiny_size(),);
    return (ret);
}

int         main(int ac, char **av)
{
    int     i;
    int     nb;
    char    c;
    char    *str;

    (void)ac;
    i = 0;
    nb = atoi(av[2]);
    c = av[1][0];
    str = (char *)mmap(0, nb + 1, PROT_READ | PROT_WRITE,
            MAP_ANON | MAP_PRIVATE, -1, 0);

    while (i < nb)
    {
        str[i] = c;
        i++;
    }
        str[i] = '\0';
    printf("%s\n", str);
    printf("%d\n", getpagesize()); // ce truc renvoie 4096
    return (0);
}
