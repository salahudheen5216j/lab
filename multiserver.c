#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int clients[10], n = 0;

void *handle(void *p) {
    int fd = *(int*)p;
    char msg[256];
    while (recv(fd, msg, 256, 0) > 0) {
        for (int i = 0; i < n; i++) // Broadcast to all
            if (clients[i] != fd) send(clients[i], msg, 256, 0);
    }
    return NULL;
}

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(8080), INADDR_ANY};
    bind(s, (struct sockaddr *)&addr, sizeof(addr));
    listen(s, 5);

    while (1) {
        int c = accept(s, 0, 0);
        clients[n++] = c;
        pthread_t t;
        pthread_create(&t, NULL, handle, &clients[n-1]);
    }
}