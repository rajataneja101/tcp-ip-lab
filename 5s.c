#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<time.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
bind(s,(struct sockaddr*)&saddr,slen);
listen(s,5);
printf("Server is running..\n");
int a=accept(s,(struct sockaddr*)NULL,NULL);
while(1)
{
char b[1024];
time_t t1=time(NULL);
snprintf(b,sizeof(b),"%24s\r\n",ctime(&t1));
send(a,b,sizeof(b),0);
}

}
