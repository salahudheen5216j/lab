#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, newfd;
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    char buffer[1024];
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    listen(sockfd, 1);

    printf("Waiting for connection...\n");

    newfd = accept(sockfd, (struct sockaddr*)&client, &len);

    fp = fopen("received.txt", "w");

    int n;
    while ((n = recv(newfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, n, fp);
    }

    printf("File received.\n");

    fclose(fp);
    close(newfd);
    close(sockfd);

    return 0;
}