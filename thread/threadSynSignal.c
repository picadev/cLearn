/*************************************************************************
    > File Name: threadSynSignal.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月11日 星期一 23时13分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

#define SIZE 1024

void *thread_function(void *arg);
char buffer[SIZE];
sem_t  sem;

int main(){
	int res;
	pthread_t a_thread;
	void *thread_result;
	res=sem_init(&sem,0,0);
	if(res!=0){
       perror("sem init failed");
	   exit(EXIT_FAILURE);
	}

	res=pthread_create(&a_thread,NULL,thread_function,NULL);
	if(res!=0){
		perror("thread create failed");
		exit(EXIT_FAILURE);
	}

	printf("input some text,enter 'end' to finish\n");
	while(scanf("%s",buffer)){
         sem_post(&sem);
		 if(strncmp("end",buffer,3)){
			 break;
		 }

	}
	printf("\nwaitig for thread to finish..\n");
	res=pthread_join(a_thread,&thread_result);
	if(res!=0){
		perror("thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("thread join\n");
	sem_destroy(&sem);
	exit(EXIT_SUCCESS);
}

void  *thread_function(void *arg){
	sem_wait(&sem);
	while(strncmp("end",buffer,3)!=0){
		printf("you input %d characters\n",strlen(buffer));
		sem_wait(&sem);
	}
	pthread_exit(NULL);
}
