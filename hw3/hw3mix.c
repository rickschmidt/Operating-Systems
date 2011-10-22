#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cpu_process(float cpu_factor);
void io_process(float io_factor);
int main(int argc, char* argv[]){
	float cpu_factor;
	cpu_factor=atof(argv[1]);
	float io_factor;
	io_factor=atof(argv[2]);
	pid_t pidholder;
	pidholder=fork();
	
	
		if(pidholder==0){
			//Child Process
			cpu_process(cpu_factor);

		}
		else{
			//Parent Process
			io_process(io_factor);
		}


}


void cpu_process(float cpu_factor){
	float i=1;
	float j;


	time_t start,end;
	time(&start);
	printf("Starting CPU Mix..\n");
	while(i<(100000*cpu_factor)){
		for(j=0;j<i;j++){
			i/j;
		}
		i++;
	}
	time(&end);
	double diff;
	diff=difftime(end,start);
	printf("Delta Time CPU Mix: %.21f\n",diff);
}

void io_process(float io_factor){
	time_t start,end;
	time(&start);
	
	printf("Starting IO Mix..\n");
	FILE *fp;
	float i;
	float j;
	while(i<(100000*io_factor)){
		fp = fopen ("/tmp/hw3.txt","w");
		
			fprintf(fp,"%s\n","This is a io bound process"); /*writes*/ 
		
		fclose(fp);
		i++;
	}
	time(&end);
	double diff;
	diff=difftime(end,start);
	printf("Delta Time IO Mix: %.21f\n",diff);

}