#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

size_t      ft_strlen(char *str);
ssize_t     ft_write(int fd, char *buffer, size_t len);
int         ft_strcmp(const char *s1, const char *s2);
char        *ft_strcpy(char *dst, const char *src);
ssize_t     ft_read(int fildes, void *buf, size_t nbyte);
char        *strdup(const char *s1);

void check_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");

	printf("%-20s: \"%s\"\n", "Test", empty);
	printf("%-20s: %zu\n", "strlen", strlen(empty));	
	printf("%-20s: %zu\n", "ft_strlen", ft_strlen(empty));

	printf("\n------------------------------\n\n");

	printf("%-20s: \"%s\"\n", "Test", hello_world);
	printf("%-20s: %zu\n", "strlen", strlen(hello_world));	
	printf("%-20s: %zu\n", "ft_strlen", ft_strlen(hello_world));

    printf("\n------------------------------\n\n");

	printf("%-20s: \"%s\"\n", "Test", alphabet);
	printf("%-20s: %zu\n", "strlen", strlen(alphabet));	
	printf("%-20s: %zu\n", "ft_strlen", ft_strlen(alphabet));
}

void check_write()
{
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    size_t ret;

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");

    printf("%-20s: (1, \"%s\", %zu)\n", "Test", alphabet, strlen(alphabet));
    printf("%-20s:\n", "write");
    ret = write(1, alphabet, strlen(alphabet));
	printf("%20zu\n", ret);
    printf("%-20s:\n", "ft_write");
    ret = ft_write(1, alphabet, strlen(alphabet));
	printf("%20zu\n", ret);

	printf("\n------------------------------\n\n");

    printf("%-20s: (1, \"%s\", %d)\n", "Test", alphabet, 10);
    printf("%-20s:\n", "write");
    ret = write(1, alphabet, 10);
	printf("%20zu\n", ret);
    printf("%-20s:\n", "ft_write");
    ret = ft_write(1, alphabet, 10);
	printf("%20zu\n", ret);

    printf("\n------------------------------\n\n");

    printf("%-20s: (1, \"%s\", %d)\n", "Test", alphabet, 0);
    printf("%-20s:\n", "write");
    ret = write(1, alphabet, 0);
	printf("%20zu\n", ret);
    printf("%-20s:\n", "ft_write");
    ret = ft_write(1, alphabet, 0);
	printf("%20zu\n", ret);
	
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void check_strcpy()
{
	char buffer[50];
	
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");

	printf("%-20s: \"%s\"\n", "Test", empty);
	printf("%-20s: buffer[50]\n", "destination");
	printf("%-20s: \"%s\"\n", "strcpy", strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "ft_strcpy", ft_strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	
	printf("\n------------------------------\n\n");
	
	printf("%-20s: \"%s\"\n", "Test", hello_world);
	printf("%-20s: buffer[50]\n", "destination");
	printf("%-20s: \"%s\"\n", "strcpy", strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "ft_strcpy", ft_strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	
	printf("\n------------------------------\n\n");
	
	printf("%-20s: \"%s\"\n", "Test", alphabet);
	printf("%-20s: buffer[50]\n", "destination");
	printf("%-20s: \"%s\"\n", "strcpy", strcpy(buffer, alphabet));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "ft_strcpy", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	
	printf("\n------------------------------\n\n");
}

void check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";
	
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "Test", hello_world);
	printf("%-20s: \"%s\"\n", "compared with", hello_human);
	printf("%-20s: \"%d\"\n", "strcmp", strcmp(hello_world, hello_human));
	printf("%-20s: \"%d\"\n", "ft_strcmp", ft_strcmp(hello_world, hello_human));
	
	printf("\n------------------------------\n\n");
	
	printf("%-20s: \"%s\"\n", "Test", hello_world);
	printf("%-20s: \"%s\"\n", "compared with", hello_world2);
	printf("%-20s: \"%d\"\n", "strcmp", strcmp(hello_world, hello_world2));
	printf("%-20s: \"%d\"\n", "ft_strcmp", ft_strcmp(hello_world, hello_world2));
	
	printf("\n------------------------------\n\n");
	
	printf("%-20s: \"%s\"\n", "Test", hello_world2);
	printf("%-20s: \"%s\"\n", "compared with", empty);
	printf("%-20s: \"%d\"\n", "strcmp", strcmp(hello_world2, empty));
	printf("%-20s: \"%d\"\n", "ft_strcmp", ft_strcmp(hello_world2, empty));
	
	printf("\n------------------------------\n\n");
	

}

void check_read()
{
	int fd = open("file.txt", O_RDONLY);
	char buff1[1024];
	int ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");

	printf("%-20s: \n", "header file.txt | read ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n[%s]\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("file.txt", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header file.txt | ft_read ");
	printf("%-20s: \n", "header file.txt | ft_read ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n[%s]\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	// fd = open("test", O_RDONLY);
	// printf("%-20s: \n", "file test | libc ");
	// ret = read(fd, buff1, 890);
	// buff1[ret] = 0;
	// printf("[return : %d]\n|%s|\n", ret, buff1);
	// printf("\n");
	// close(fd);
	// fd = open("test", O_RDONLY);
	// clear_buffer(buff1, 891);
	// printf("%-20s: \n", "file test | libasm ");
	// ret = ft_read(fd, buff1, 890);
	// buff1[ret] = 0;
	// printf("[return : %d]\n|%s|\n", ret, buff1);
	// printf("\n");
	// clear_buffer(buff1, 891);
	// close(fd);

	// fd = open("wrong", O_RDONLY);
	// printf("%-20s: \n", "wrong | libc ");
	// ret = read(fd, buff1, 890);
	// buff1[ret] = 0;
	// printf("[return : %d]\n|%s|\n", ret, buff1);
	// printf("\n");
	// close(fd);
	// fd = open("wrong", O_RDONLY);
	// clear_buffer(buff1, 891);
	// printf("%-20s: \n", "wrong | libasm ");
	// ret = ft_read(fd, buff1, 890);
	// buff1[ret] = 0;
	// printf("[return : %d]\n|%s|\n", ret, buff1);
	// printf("\n");
	// clear_buffer(buff1, 891);
	// close(fd);
}

// void check_strdup()
// {
// 	char *hello_world = "Hello world !";
// 	char *empty = "";
// 	char *save;
// 	char *save2;
	
// 	printf("\n================================\n");
// 	printf("========== FT_STRDUP ===========\n");
// 	printf("================================\n\n");
// 	printf("%-20s: \"%s\"\n", "char *", hello_world);
// 	save = strdup(hello_world);
// 	printf("%-20s: \"%s\"\n", "libc", save);
// 	free(save);
// 	save = NULL;
// 	save2 = ft_strdup(hello_world);
// 	printf("%-20s: \"%s\"\n", "libasm", save2);
// 	free(save2);
// 	save2 = NULL;
// 	printf("\n");

// 	printf("%-20s: \"%s\"\n", "char *", empty);
// 	save = strdup(empty);
// 	printf("%-20s: \"%s\"\n", "libc", save);
// 	free(save);
// 	save = NULL;
// 	save2 = ft_strdup(empty);
// 	printf("%-20s: \"%s\"\n", "libasm", save2);
// 	free(save2);
// 	save2 = NULL;
// 	printf("\n");

// 	// ------- NULL = SEGFAULT
// 	// printf("%-20s: NULL\n", "char *");
// 	// save = strdup(NULL);
// 	// printf("%-20s: \"%s\"\n", "libc", save);
// 	// free(save);
// 	// save = NULL;
// 	// save2 = ft_strdup(NULL);
// 	// printf("%-20s: \"%s\"\n", "libasm", save2);
// 	// free(save2);
// 	// save2 = NULL;
// 	// printf("\n");
// }

void stop()
{
	char skip[10];
	printf("\nClick any button to contunue: ");
    scanf(" %s", skip);
}

int main()
{
    

	// check_strlen();
    // stop();

	// check_write();
    // stop();
    
	// check_strcpy();
    // stop();

	// check_strcmp();
	// stop();

	check_read();
	// stop();
	// check_strdup();
}