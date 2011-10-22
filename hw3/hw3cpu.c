#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CPU Bound Process
//Performs some division in loops; nothing interesting
//The outside loop defaults to 100k iterations, and can be adjusted by passing a decimal % as an arg
//Example ./hw3 .1 for 10% of the 100k (10k)
int main(int argc, char* argv[]){
	float i=1;
	float j;
	float factor;
	if (argv[1]==NULL){
		factor=1;
	}
	else{
		factor=atof(argv[1]);
	}
	time_t start,end;
	time(&start);
	printf("Starting CPU..\n");
	while(i<(100000*factor)){
		for(j=0;j<i;j++){
			i/j;
		}
		i++;
	}
	time(&end);
	double diff;
	diff=difftime(end,start);
	printf("Delta Time CPU: %.21f\n",diff);
	exit(0);
}
