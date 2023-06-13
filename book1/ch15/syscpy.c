#include <stdio.h>
#include <fcntl.h>
#define BUF_SIZE 3

int main()
{
    int fd1, fd2;
    int len;
    char buf[BUF_SIZE];

    fd1 = open("news.txt", O_RDONLY);
    if (fd1 == -1)
    {
        printf("open news.txt err.\n");
        return 0;
    }

    fd2 = open("cpy.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd2 == -1)
    {
        printf("open cpy.txt err.\n");
        return 0;
    }

    while ((len = read(fd1, buf, sizeof(buf))) > 0)
        write(fd2, buf, len);

    close(fd1);
    close(fd2);

    return 0;
}