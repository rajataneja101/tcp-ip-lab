#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr,caddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
socklen_t clen=sizeof(caddr);
bind(s,(struct sockaddr*)&saddr,slen);
listen(s,5);
int a=accept(s,(struct sockaddr*)&caddr,&clen);
printf("Client connected");
pid_t cpid=fork();
char b[10000];
if(cpid==0)
{
while(1)
{
 //bzero(&b,sizeof(b)); 
recv(a,b,sizeof(b),0);
printf("Message recieved is: %s\n",b);
}
}
else
{
while(1)
{
//bzero(&b,sizeof(b)); 
printf("Enter the message to be send\n");
fgets(b,10000,stdin);
send(a,b,sizeof(b)+1,0);
printf("Message sent\n");
}
}
close(s);
}

