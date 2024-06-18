#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	int hour, minute, second;
	printf("Type in the clock time, the format must be H M S\n");
	scanf("%d", &hour);
	scanf("%d", &minute);
	scanf("%d", &second);
	while(1)
	{
		printf("%02d:%02d:%02d", hour, minute, second);
		second = second - 1;

		if(hour == 0 && minute == 0 && second == -1)
		{
			sleep(1);
			printf("\nTime is up!\a");
			break;
		}
		if(second == -1)
		{
			if(minute == 0)
			{
				hour--;
				second = 59;
				minute = 59;
			}
			else
			{
				minute --;
				second = 59;
			}
			if(minute == -1 && hour != 0)
			{
				hour--;
				minute = 59;
			}
		}
		sleep(1);
		#ifdef _WIN32
		{system("cls");}
		#else
		{system("clear");}
		#endif	
	}
	return 0;
}