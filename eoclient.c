#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct sockaddr_in a = {AF_INET, htons(8080)};
    a.sin_addr.s_addr = inet_addr("127.0.0.1");
    int s = socket(AF_INET, SOCK_STREAM, 0), n; char b[5];
    
    connect(s, (struct sockaddr*)&a, 16);
    
    scanf("%d", &n); 
    write(s, &n, sizeof(n));
    
    write(1, b, read(s, b, 5));
}