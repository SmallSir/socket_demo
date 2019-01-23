#include "unp.h"

typedef long long LL;

void str_cli(FILE *fp,int sockfd){
    char sendline[MAXLINE],recvline[MAXLINE];
    while(Fgets(sendline,MAXLINE,fp)!=NULL)
    {
        if(Readline(sockfd,recvline,MAXLINE) == 0)
            err_quit("str_cli：server terminated prematurely");
        Fputs(recvline,stdout);
    }
}