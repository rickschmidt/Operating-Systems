#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]){
	float factor;
	if (argv[1]==NULL){
		factor=1;
	}
	else{
		factor=atof(argv[1]);
	}
	time_t start,end;
	time(&start);
	printf("Starting IO..\n");
	FILE *fp;
	float i;
	float j;
	while(i<(100000*factor)){
		fp = fopen ("/tmp/hw3.txt","w");
		
			fprintf(fp,"%s\n","This is a io bound process"); /*writes*/ 
		
		fclose(fp);
		i++;
	}
	time(&end);
	double diff;
	diff=difftime(end,start);
	printf("Delta Time CPU: %.21f\n",diff);
	exit(0);	
}