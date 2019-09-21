#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signum){
    printf("Alarm delivered signum is %d\n",signum);
    system("/bin/ls");
    //exit(0);
}

int main()
{
    alarm(5);
    signal(SIGALRM,sig_handler);

    for(;;){
        sleep(1);
    }
    return 0;
}
