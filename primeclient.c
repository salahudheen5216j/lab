#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0), n = 17, res;
    struct sockaddr_in a = {AF_INET, htons(8080)};
    inet_pton(AF_INET, "127.0.0.1", &a.sin_addr);

    connect(s, (struct sockaddr *)&a, sizeof(a));
    write(s, &n, sizeof(n));
    read(s, &res, sizeof(res));

    printf("Result: %s\n", res ? "Prime" : "Not Prime");
    close(s);
}