#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	float i=1;
	float j;
	while(i<200000){
		for(j=0;j<i;j++){
			i/j;
		}
		i++;
	}
	exit(0);
}