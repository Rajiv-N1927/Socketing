#include "unp.h"

int main(int argc, char** argv) {
    int sockfd, n;
    char recvline[MAXLINE +1];
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("Usage: a.out <IPaddress>");

    if ( (sockfd = Socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("Socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);

    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

    while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        Fputs(recvline, stdout);
    }
    if ( n < 0 )
        err_sys("read error");

    exit(0);
}
