#include <stdio.h>
#include <string.h>

int main(void)
{

    char input[20]; //this limit can be increased but fgets maxcount also needs to be increased
    if(fgets(input, 20, stdin) == NULL){return -1;}
    else{
        input[strcspn(input, "\n")] = '\0';
    }

    int len = strlen(input);

    int emptyspace[10]; //this has to be half of the increased limit.
    emptyspace[0] = -1;
    int countempty = 1;

    for(int i = 0; i < len; i++){
        if(input[i] == ' '){
            emptyspace[countempty] = i;
            countempty++;
        }
    }
    emptyspace[countempty] = len+1;
    countempty++;

    /*
    for(int i = 0; i < countempty; i++){
        printf("emptyspace element %d: %d\n", i, emptyspace[i]);
    }
    printf("\nlen: %d\ncountempty: %d\n", len, countempty);
    */

    int arr[countempty-1];
    int copy[countempty];
    for(int i = 0; i < countempty; i++)
    {
        copy[i] = emptyspace[i];
    }
    int a = 0;
    int max = 0;
    for(int i = 1; i <= countempty-1; i++)
    {
        arr[a] = copy[i] - copy[i-1] - 1;
        if(a != 0 && a != countempty-2){arr[a]++;}
        copy[i]++;
        a++;
    }
    /*
    for(int i = 0; i < a; i++)
    {
        printf("arr %d. element: %d\n", i+1, arr[i]);
    }
    */
    for(int i = 0; i < countempty-1; i++)
    {
        if(arr[i] > max){max = arr[i];}
    }
    //printf("MAX IS: %i\n", max);

    char all_words[countempty-1][max];
    int count = 1;
    int words = 0;
    int car;
again:

    if(words == countempty-1){goto ex;}
    car = 0;
    for(int i = emptyspace[count-1]+1; i < emptyspace[count]; i++)
    {
        if(count == 0){i++;}
        all_words[words][car] = input[i];
        car++;
    }
    count++;
    words++;
    goto again;
ex:
//fill the weird spaces with empty space ( )
    for(int i = 0; i < countempty - 1; i++)
    {
        for(int j = 1; j <= max - arr[i]; j++)
        {
            all_words[i][max-j] = ' ';
        }
    }
    /*
    for(int i = 0 ; i < countempty-1; i++)
    {
        for(int j = 0; j < max; j++){printf("%c", all_words[i][j]);}
        printf("\n");
    }
    */
    int x = 0; //X CONTROLS THE nth word
    int y = 0; //Y CONTROLS THE nth character in word
lesgo:
    printf("%c ", all_words[x][y]);
    if(++x == countempty-1){
        x = 0;
        y++;
        printf("\n");
        if(y == max){goto end;}
    }

    goto lesgo;
end:
    return 0;

}
/*
 *
 *  k h
 *  r a
 *  a t
 *  n
 *
 */