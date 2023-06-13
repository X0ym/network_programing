#include <stdio.h>
#define BUF_SZIE 3

int main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    char buf[BUF_SZIE];

    fp1 = fopen("news.txt", "r");
    if (fp1 == NULL) 
    {
        printf("open news.txt err.\n");
        return 0;
    }

    fp2 = fopen("cpy.txt", "w");
    if (fp2 == NULL)
    {
        printf("open cpy.txt err.\n");
        return 0;
    }

    while (fgets(buf, BUF_SZIE, fp1) != NULL)
        fputs(buf, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}