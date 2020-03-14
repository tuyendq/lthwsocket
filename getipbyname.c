#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("\nUsage: %s <hostname>\n", argv[0]);
        printf("\nExample: %s google.com\n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Argument 1: %s\n", argv[1]);
    // char *hostname = "www.google.com";
    char *hostname = argv[1];
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    if ((he = gethostbyname(hostname)) == NULL)
    {
        perror("Error gethostbyname");
        exit(EXIT_FAILURE);
    }

    addr_list = (struct in_addr **) he -> h_addr_list;

    for (i = 0; addr_list[i] != NULL; i++)
    {
        // Return the first address
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }

    printf("%s resolved to: %s\n", hostname, ip);

    return 0;
}