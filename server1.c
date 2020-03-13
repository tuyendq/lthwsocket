/** \brief
 * https://www.binarytides.com/socket-programming-c-linux-tutorial/
 * \param
 * \param
 * \return
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>    // strlen
 #include <sys/socket.h>
 #include <arpa/inet.h> //inet_addr
 #define PORT 80

 int main(int argc, char const *argv[])
 {
     // 1. Create a socket
     // SOCK_STREAM: TCP protocol, SOCK_DGRAM: UDP protocol
     // IPPROTO_IP: 0 - IP protocol
     int socket_desc;
     socket_desc = socket(AF_INET, SOCK_STREAM, 0);

     if (socket_desc == -1 )
     {
         perror("Error Create socket");
         exit(EXIT_FAILURE);
     }

     printf("Successfully create a socket.\n");

    // 2. Connect socket to a server
    // 74.125.235.20: google.com
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("172.217.194.138");
    server.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Error Connect to server");
        exit(EXIT_FAILURE);
    }
    printf("Successfully connect to server: %u\n", server.sin_addr.s_addr);

    // 3. Send data over socket
    char *message;
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0)
    {
        perror("Error Send data");
        exit(EXIT_FAILURE);
    }
    printf("Successfully data sent.\n");

    return 0;
 }

