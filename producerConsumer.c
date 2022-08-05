#include<stdio.h>
#include<stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int Wait (int s){
    return --s;
}

int Signal (int s){
    return ++s;
}

void producer(){
    mutex = Wait(mutex);
    full = Signal(full);
    empty = Wait(empty);
    ++x;
    printf("PRODUCER -- Produced item %d\n", x);
    mutex = Signal(mutex);
}

void consumer(){
    mutex = Wait(mutex);
    empty = Signal(empty);
    full = Wait(full);
    printf("CONSUMER -- Consumed item %d\n", x);
    --x;
    mutex = Signal(mutex);
}

void main(){
    int ch;
    while(1){
        printf("1. To produce\n2. To consume\n");
        scanf("%d", &ch);

        switch (ch){
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is full\n");
                break;

            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else  
                    printf("Buffer is empty\n");
                break;

            default:
                exit(1);
        }
    }
}