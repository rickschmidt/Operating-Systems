#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
	float i=1;
	float j;
	time_t start,end;
	time(&start);
	while(i<100000){
		for(j=0;j<i;j++){
			i/j;
		}
		i++;
	}
	time(&end);
	double diff;
	diff=difftime(end,start);
	printf("Time: %.21f\n",diff);
	exit(0);
}
