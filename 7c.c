#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
connect(s,(struct sockaddr*)&saddr,slen);
pid_t cpid=fork();
char b[10000];
if(cpid==0)
{
while(1)
{
//bzero(&b,sizeof(b)); 
printf("Enter the message to be send\n");
fgets(b,10000,stdin);
send(s,b,sizeof(b)+1,0);
printf("Message sent\n");
}
}//int n=1;
else
{
while(1)
{
//bzero(&b,sizeof(b)); 
recv(s,b,sizeof(b),0);
printf("Message recieved is: %s\n",b);
//n+=1;
}
}
close(s);
}

