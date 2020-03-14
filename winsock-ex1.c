/**
* Example winsock programming on Windows
* https://www.binarytides.com/winsock-socket-programming-tutorial/
* Compile using msys2 on windows 10
* $ gcc winsock-ex1.c -l"ws2_32" -o winsock-ex1
*/

#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock library

int main(int argc, char *argv[])
{
    WSADATA wsa;

    printf("\nInitializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
    {
        printf("Failed. Error Code: %d", WSAGetLastError());
        //perror("Error Initilize.");
        exit(EXIT_FAILURE);
    }

    printf("Sucessfully Initialized.");

    return 0;
}