#include <stdio.h>
#include <arpa/inet.h>

int main()
{
	char *addr1 = "1.2.3.4";
    char *addr2 = "1.2.3.256";

    unsigned long conv_addr = inet_addr(addr1);
    if (conv_addr == INADDR_NONE)
        printf("inet_addr error \n");
    else
        printf("Network Ordered Integer addr: %#lx \n", conv_addr);

    conv_addr = inet_addr(addr2);
    if (conv_addr == INADDR_NONE)
        printf("inet_addr error \n");
    else
        printf("Network Ordered Integer addr: %#lx \n", conv_addr);

    return 0;
}

/*
result:
Network Ordered Integer addr: 0x4030201 
inet_addr error

*/