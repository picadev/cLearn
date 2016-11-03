/*************************************************************************
    > File Name: tcpClient.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月09日 星期六 21时03分37秒
 ************************************************************************/

#include<stdio.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<memory.h>
#include<arpa/inet.h>
#include<signal.h>


#define PORT 11910
#define buflen 1024

void process_conn_client(int s);
void sig_pipe(int signo);
int s;
int main(int argc,char *argv[]){
   sockaddr_in server_addr;
   int err;
   sighandler_t ret;
   char server_ip[50]="";
   s=socket(AF_INET,SOCK_STREAM,0);
   if(s<0){
          printf("client :create socket error\n");
		  return 1;
   }
   ret=signal(SIGTSTP,sig_pipe);
   if(SIG_ERR==ret){
	   printf("signal connect failed");
      return -1;
   }else {
	   printf("signal connect success");
   }

   memset(&server_addr,0,sizeof(server_addr));
   server_addr.sin_family=AF_INET;
   server_addr.sin_port=htons(PORT);
   server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
   printf("please input server ip address:\n");
   read(0,server_ip,50);
   server_addr.sin_addr.s_addr=inet_addr(server_ip);
   err=connect(s,(struct sockaddr *)&server_addr,sizeof(sockaddr));
   if(err==0){
      printf("client:connect to server\n");
   }else {
	   printf("client:connect error\n");
   }

   process_conn_client(s);
   close(s);

}

void process_conn_client(int s){
	ssize_t size=0;
	char buffer[buflen];
	for(;;){
		memset(buffer,'\0',buflen);
		size=read(0,buffer,buflen);
		if(size>0){

		
		write(s,buffer,strlen(buffer)+1);
		for(size=0;size==0;size=read(s,buffer,buflen));
		write(1,buffer,strlen(buffer)+1);
     	}
   }
}


 void sig_pipe(int signo){
	 printf("catch a signal\n");
	 if(signo==SIGTSTP){
		 printf("receve sigtstp signal\n");
		 int ret=close(s);
		 if(ret==0){
			 printf("success:close socket\n");
		 }else if(ret==-1){
			 printf("failed :close socket\n");
		 }

		 exit(1);
	 }
 }
