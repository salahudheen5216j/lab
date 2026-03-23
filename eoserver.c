#include <arpa/inet.h>
#include <unistd.h>

int main() {
    struct sockaddr_in a = {AF_INET, htons(8080), 0};
    int s = socket(AF_INET, SOCK_STREAM, 0), c, n;
    
    bind(s, (struct sockaddr*)&a, 16); listen(s, 1);
    
    read(c = accept(s, 0, 0), &n, sizeof(n));
    write(c, n % 2 ? "Odd\n" : "Even\n", 5);
}