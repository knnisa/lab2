#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char name[];

void childTask(){
printf("Please enter my name : ");
scanf("%s" ,name);
printf("\name is %s.PPID:%d PID:%d\n", name, getppid(), getpid());
}

int main(void) {
for (int i=1; i<5; i++){
pid_t pid = fork();

if(pid==0){
printf("%d.", i);
childTask();
exit(0);
}

else{
wait(NULL);
printf("next child process\n");
}
}

printf("Job is done\n");
return EXIT_SUCCESS;
}

