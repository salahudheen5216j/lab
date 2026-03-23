#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(8080), inet_addr("127.0.0.1")};
    connect(s, (struct sockaddr *)&addr, sizeof(addr));

    if (fork() == 0) { // Child process: Receive
        char msg[256];
        while (recv(s, msg, 256, 0) > 0) printf("New Msg: %s", msg);
    } else {           // Parent process: Send
        char msg[256];
        while (fgets(msg, 256, stdin)) send(s, msg, 256, 0);
    }
    return 0;
}