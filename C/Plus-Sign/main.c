#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void func(int x)
{
    char star;
    char empty;
    if (x < 0){
        printf("You entered a negative number. I'll do something different.\n\n");
        star = ' ';
        empty = '*';
    }
    else{
        star = '*';
        empty = ' ';
    }
    x = -x;
    if (x % 2 == 0){                            //if user puts an even number, it would look ugly
        x+=1;
        printf("Because you entered an even number, the plus would look ugly so it will be bigger.\n\n");
    }
    int mid = (x/2) + 1;                        //to determine when to print the plus sign
    for(int line = 1; line <= x; line++){

        for(int column = 1; column <= x; column++){
            if(line == mid){
                printf("%c", star);
            }

            else if (column == mid){
                printf("%c", star);
            }

            else{
                printf("%c", empty);
            }
        }
        printf("\n");
    }
}
int main(void) {
    char num[3];
    short flag = 0;
    char * ePtr;
    if(fgets(num, 4, stdin) != NULL){}

    int len = strtol(num, &ePtr, 10);
    if(len == 0)
    {
        printf("you either entered 0 or a wrong value. please try again.");
        exit(1);
    }

    func(len);
}
