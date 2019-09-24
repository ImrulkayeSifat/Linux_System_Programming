#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *ThreadFunc(void *args)
{
	int i;
	for(i=0;i<25;++i)
	{
		printf("This is from thread i=%d\n",i);
		sleep(1);
	}	
}

int main()
{
	pthread_t mythread;
	void *thread_result;
	int j=0;

	pthread_create(&mythread, NULL, ThreadFunc, NULL);	

	for(j=0;j<25;j++)
	{
		sleep(1);
		printf("this is from main or parent thread j=%d\n", j);
	}

	pthread_join(mythread, &thread_result);
	return 0;
}

