/*
Rick Schmidt
Comp 410
HW1
*/


/*
=======

Thre program prints a matrix represenation of a tree.  The ppid is the column, a process prints its pid and command name in the column of its ppid.  
Example
ps output>
PPID PID CMD
0    1   init
1    2   idle
1    3   memory
2    4   swap

would result in...

1,init	-	-
-	2,idle	-
-	3,memory-
-	-	4,swap

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodes{
		char *ncmd; //Holds info for node
		char *npid;
		char *nppid;
	
		// std::vector<Nodes> children;
		struct Nodes *subtree;
		

		};
int insert(struct Nodes **n,  char *cmd, char *ppid, char *pid){
			
      // while(*tree){
      //                   if((*tree)->data == v)
      //                           return(1);
      //                   if((*tree)->data > v)
      //                           root = &((*tree)->left_p);
      //                   else
      //                           root = &((*tree)->right_p);
      //           }
     
    		
    			while(*n){
    					if(&((*n)->npid)!=NULL){
							printf("test: %s\n", (*n)->npid);
							// printf("size of npid %d\n",sizeof((*n)->npid));
							(*n)->npid="test";
							printf("test2: %s\n", (*n)->npid);
							printf("If %d\n",strcmp((*n)->npid,ppid));
							

								// if(strcmp((*n)->npid,ppid)==0){
    					    						printf("npid is %s and ppid is %s\n",((*n)->npid),ppid);
    					    					
    					    						return(1);
    					    						}
    					    						else if (strcmp((*n)->npid,ppid)>0){
    					    						// printf("npid is %s and ppid is %s\n",((*n)->npid),ppid);
    					    	
    					    						  n= &((*n)->subtree);
    					    						}
    					    						else if  (strcmp((*n)->npid,ppid)<0){
    					    	
    					    						  n= &((*n)->subtree);
    					    													printf("The cmd 3 in is %s\n",(*n)->ncmd);
    					    						}
    					    	

    				}
    				*n=malloc(100);
    				(*n)->ncmd=cmd;
    				(*n)->npid=pid;
    				(*n)->nppid=ppid;
    	//			printf("%s %s %s\n",((*n)->ncmd), ((*n)->nppid), ((*n)->npid));
    			// printf("The cmd 3 in is %s",(*n)->next->ncmd);
    					// printf("The cmd 3 in is %s",(*n)->next->next->next->next->ncmd);
    
					return(0);
}
int main(){
     	FILE *fp;

  	char line[100];			
	// fp = popen("ps -axl", "r");
	fp = popen("ps -ax -c -o uid,uid,uid,uid,uid,uid,pid,ppid,uid,uid,uid,command", "r");

    

	char cmd[200];
	char pid[200];
	char ppid[200];
	// char c[200]="PID";
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
	struct Nodes *tree;
	tree=malloc(100);
	printf("tree: %s\n", tree->ncmd);
	while ( fgets( line, sizeof line, fp)){  //fgets grabs from the file stream until a \n character is reached and stores the result in line.  

		// sscanf(line,"%*s %*s %*s %s %s %*s %s  %*s %s %s  %s",pid,ppid,extra,extra3,extra2,cmd); //sscanf scans the line and places the interesting content into the proper variables.  
	sscanf(line,"%*s %*s %*s %*s %*s %*s %s %s %*s %*s %*s  %s",pid,ppid,cmd); //sscanf scans the line and places the interesting content into the proper variables.  
		insert(&tree,cmd,ppid,pid);
	

	// if(strcmp(pid,c)==0){
	// 		 //Ignores header
	// 		}
	// 	else{	
	// 
	// 		int i;
	// 		for(i=0;i<(ppid);i++){
	// 			printf("-\t");
	// 		}
	// 		if(strncmp(cmd,"",1)==0){  //handles cases when there is an extra column type on certain lines in minix
	// 			printf("%s,%s\n",extra2,pid);
	// 		}
	// 		else if(strncmp(cmd,"0:",2)==0){  //handles cases of the time being 'expanded' on a line in minix
	// 			printf("%s,%s\n",extra3,pid);
	// 		}
	// 		else{
	// 			printf("%s,%s\n",cmd,pid);  //Most lines are processed here
	// 		}
	// 		}
	// 	
	// 		
		}
	return(0);
}
