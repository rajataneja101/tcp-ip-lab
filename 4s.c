#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(2999);
socklen_t slen=sizeof(saddr);
bind(s,(struct sockaddr*)&saddr,slen);
while(1)
{
char b[1024];

recvfrom(s,b,sizeof(b),0,(struct sockaddr*)&saddr,&slen);
printf("Message recieved is: %s",b);
printf("Enter any message:\n");
fgets(b,sizeof(b),stdin);
sendto(s,b,sizeof(b),0,(struct sockaddr*)&saddr,slen);
printf("Message sent\n");
}
}
