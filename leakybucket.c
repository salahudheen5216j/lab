#include <stdio.h>

int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int main() {
    int drop = 0, mini, nsec, cap, count = 0, i, inp[25], process;

    printf("Enter the bucket size: ");
    scanf("%d", &cap);
    
    printf("\nEnter the output rate: ");
    scanf("%d", &process);
    
    printf("\nEnter the no of sec you need to stimulate: ");
    scanf("%d", &nsec);
    
    for (i = 0; i < nsec; i++) {
        printf("\nEnter the size of the packet entering at %d sec: ", i + 1);
        scanf("%d", &inp[i]);
    }
    
    printf("\nTime | \tPacket recieved | \tPacket send from buc | \tPacket left in buc | \tPacket drop\n");
    
    // First loop: processing incoming packets
    for (i = 0; i < nsec; i++) {
        count += inp[i];
        if (count > cap) {
            drop = count - cap;
            count = cap;
        } else {
            drop = 0;
        }
        
        printf("%d", i + 1);
        printf("\t\t%d", inp[i]);
        
        mini = min(count, process);
        printf("\t\t%d", mini);
        
        count = count - mini;
        printf("\t\t%d", count);
        
        printf("\t\t%d\n", drop);
    }
    
    // Second loop: draining the remaining packets in the bucket
    for (; count != 0; i++) {
        if (count > cap) {
            drop = count - cap;
            count = cap;
        } else {
            drop = 0;
        }
        
        printf("%d", i + 1);
        printf("\t\t0");
        
        mini = min(count, process);
        printf("\t\t%d", mini);
        
        count = count - mini;
        printf("\t\t%d", count);
        
        printf("\t\t%d\n", drop);
    }
    
    return 0;
}