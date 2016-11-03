/*************************************************************************
    > File Name: lthread.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月11日 星期一 21时48分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
void print_currentTime(int *a){
	time_t ct;
	ct=time(NULL);
	printf("current time is :'%s',%d",ctime(&ct),a);
	pthread_exit("time thread finished!\n");
}

int main(){
	int ret;
	void *thread_result;
	pthread_t new_thread;
	int arg=9;
	ret=pthread_create(&new_thread,NULL,(void*)print_currentTime,&arg);
	if(ret!=0){
		perror("thread creation failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("waiting for new thread ..\n");
	ret=pthread_join(new_thread,&thread_result);
	if(ret!=0){
        perror("thread foin failed\n");
		exit(EXIT_FAILURE);
	}

	printf("thread joined ,returned :%s\n",(char *)thread_result);
	return 0;
}
