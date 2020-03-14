/** C socket programming
 *  https://www.binarytides.com/socket-programming-c-linux-tutorial/
*/

#include <stdio.h>  //printf
#include <string.h> //strcpy
#include <sys/socket.h>
#include <netdb.h>  //hostent
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *hostname = "www.google.com";
    char ip[100];
    struct hosten *he;
    struct in_addr **addr_list;
    int i;

    if ((he = gethostbyname(hostname)) == NULL)
    {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for (i = 0; addr_list[i] != NULL; i++)
    {
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }

    printf("%s resolved to: %s\n", hostname, ip);

    return 0;
}
