#include  "unp.h"


void dg_cli(FILE *fp,int sockfd,const SA *pservaddr,socklen_t servlen)
{
    int n;
    char sendline[MAXLINE],recvline[MAXLINE + 1];
    Connect(sockfd,(SA *)pservaddr,servlen);
    while(Fgets(sendline,MAXLINE,fp)!=NULL)
    {
        Write(sockfd,sendline,strlen(sendline));
        n = Recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
        recvline[n] = 0;
        Fputs(recvline,stdout);
    }
}