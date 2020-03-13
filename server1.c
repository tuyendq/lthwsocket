/** \brief
 * https://www.binarytides.com/socket-programming-c-linux-tutorial/
 * \param
 * \param
 * \return
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/socket.h>

 int main(int argc, char const *argv[])
 {
     // Create a socket
     int socket_desc;
     socket_desc = socket(AF_INET, SOCK_STREAM, 0);

     if (socket_desc == -1 )
     {
         perror("Create socket");
         exit(EXIT_FAILURE);
     }

     printf("Successfully create a socket.\n");

     return 0;
 }

