#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr.sin_port=htons(2999);
socklen_t slen=sizeof(saddr);
while(1)
{
char b[1024];
printf("Enter any message:\n");
fgets(b,sizeof(b),stdin);
sendto(s,b,sizeof(b),0,(struct sockaddr*)&saddr,slen);
printf("Message sent\n");
recvfrom(s,b,sizeof(b),0,(struct sockaddr*)&saddr,&slen);
printf("Message recieved is: %s",b);
}
}
