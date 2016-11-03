/*************************************************************************
    > File Name: threadSyn.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月11日 星期一 22时53分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int flag=1;
void *thread_function(void *arg);

int main(){
	int res;
	pthread_t a_thread;
	void *thread_result;
	int count=1;

	res=pthread_create(&a_thread,NULL,thread_function,NULL);
	if(res!=0){
        perror("thread creation faild");
		exit(EXIT_FAILURE);
	}

	while(count++<=20){
		if (flag==1){
			printf("1");
			flag=2;
		}else{
			sleep(1);
		}
	}

	printf("\nwaiting for thread to finish ...\n");

	res=pthread_join(a_thread,&thread_result);
	if(res!=0){
		perror("thread join failed");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
		
}

void *thread_function(void *arg){
	int count=1;
	while(count++<=20){
		if(flag==2){
          printf("2");
		  flag=1;
		}else {
			sleep(1);
		}
	}
}

