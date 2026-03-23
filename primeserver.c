#include <netinet/in.h>
#include <unistd.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0), c, n, p = 1;
    struct sockaddr_in a = {AF_INET, htons(8080), INADDR_ANY};

    bind(s, (struct sockaddr *)&a, sizeof(a));
    listen(s, 1);
    c = accept(s, 0, 0);

    read(c, &n, sizeof(n));
    for (int i = 2; i * i <= n; i++) if (n % i == 0) p = 0;
    if (n < 2) p = 0;

    write(c, &p, sizeof(p));
    close(c); close(s);
}