#include "my.h"
int main()
{    int _pipe[2];
    if(pipe(_pipe)==-1)
    {
        printf("pipe error\n");
        return 1;
    }
    int ret;
    int count=0;
    int flag=fcntl(_pipe[1],F_GETFL);
    fcntl(_pipe[1],F_SETFL,flag|O_NONBLOCK);
    while(1)
    {
        ret=write(_pipe[1],"A",1);
        if(ret==-1)
        {
            printf("error %s\n",strerror(errno));
            break;
        }
        count++;
    }
    printf("count=%d\n",count);
    return 0;
}

