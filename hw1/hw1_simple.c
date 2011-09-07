/*
Rick Schmidt
Comp 410
HW1
*/

/*
I began the project trying to create my own tree structure with structs.  I used the information at 
http://publications.gbdirect.co.uk/c_book/chapter6/structures.html#section-3
as a starting point after my first attempts.  After some headaches dealing with pointers I re-read the assignment 
and saw that we were creating "nodes" and not nodes and that the crux of the assignment was working with pipes and 
system calls.  I was able to quickly adapt my earlier failed attempts into a much simpler design that prints a "tree" 
and not a tree.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
     	FILE *fp;

  	char line[100];			
	fp = popen("ps -axl", "r");

    

	char cmd[200];
	char pid[200];
	int ppid;
	char c[200]="PID";
	/*These 'extra' variables hold onto the cases on minix when the ps command prints an empty column that is not read by sscanf
		Example:  Sometimes the line may be pid ppid extra?  command  and sometimes pid pppid command.  
	The extras hold onto the info just in case and they are checked in the main print loop.
	These extra command are only needed because of the limits of the ps command on minix.
	ON OSX you can pass in exactly what column types you want ps to print.  
		Example: 	fp = popen("ps -ax -c -o pid,ppid,command", "r");
		
		The following command was used to simulate the minix 'full' output during some development work on OSX.
			fp = popen("ps -ax -c -o uid,uid,uid,uid,uid,uid,pid,ppid,uid,uid,uid,command", "r");
		
	*/
	char extra[200];  
	char extra2[200];
	char extra3[200];

     
	while ( fgets( line, sizeof line, fp)){  //fgets grabs from the file stream until a \n character is reached and stores the result in line.  

		sscanf(line,"%*s %*s %*s %s %d %*s %s  %*s %s %s  %s",pid,&ppid,extra,extra3,extra2,cmd); //sscanf scans the line and places the interesting content into the proper variables.  


	

	if(strcmp(pid,c)==0){
		 //Ignores header
		}
	else{	

		int i;
		for(i=0;i<(ppid);i++){
			printf("-\t");
		}
		if(strncmp(cmd,"",1)==0){  //handles cases when there is an extra column type on certain lines in minix
			printf("%s,%s\n",extra2,pid);
		}
		else if(strncmp(cmd,"0:",2)==0){  //handles cases of the time being 'expanded' on a line in minix
			printf("%s,%s\n",extra3,pid);
		}
		else{
			printf("%s,%s\n",cmd,pid);  //Most lines are processed here
		}
		}
	
		
	}
	return(0);
}
