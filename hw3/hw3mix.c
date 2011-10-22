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
	time_t start,end;
	time(&start);
	pidholder=fork();
	
	
		if(pidholder==0){
			//Child Process
			cpu_process(cpu_factor);

		}
		else{
			//Parent Process
			io_process(io_factor);
		}
		time(&end);
		double diff;
		diff=difftime(end,start);
		printf("Delta Time Mix: %.21f\n",diff);
}


void cpu_process(float cpu_factor){
	float i=1;
	float j;


	
	printf("Starting CPU Mix..\n");
	while(i<(100000*cpu_factor)){
		for(j=0;j<i;j++){
			i/j;
		}
		i++;
	}

}

void io_process(float io_factor){
	
	
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


}