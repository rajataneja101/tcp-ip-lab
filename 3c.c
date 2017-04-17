#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
connect(s,(struct sockaddr*)&saddr,slen);
while(1)
{
char b[1024];
printf("Enter the message\n");
fgets(b,sizeof(b),stdin);
send(s,b,sizeof(b),0);
printf("Message sent\n");
recv(s,b,sizeof(b),0);
printf("Message recv: %s",b);
}
close(s);
}
