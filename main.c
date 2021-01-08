#include <stdio.h>

size_t      ft_strlen(char *str);
ssize_t     ft_write(int fd, char *buffer, size_t len);
int         strcmp(const char *s1, const char *s2);

int main()
{
    char string[50] = "hello world";
    int len = ft_strlen(string);
    printf("%d\n", len);

    ft_write(1, NULL, len);
    return 0;
}