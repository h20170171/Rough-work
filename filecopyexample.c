#include<fcntl.h>
int version=1;
int main(int argc,char *argv[])
{
int fdold,fdnew,pid;
pid=getpid();
printf("I am a child process with PID =%d\n",pid);
if (argc !=3)
{
printf("Usage : copy<oldfile> <newfile>\n");
exit(1);
}
fdold=open(argv[1],0_RDONLY);
if(fdold==-1)
{
printf("cannot open source file\n");
exit(1);
}
fdnew=create(argv[2],0666);
if(fdnew==-1)
{
printf("cannot create file %s \n",argv[2]);
exit(1);
}
copy(fdold,fdnew);
exit(0);
}
copy(int old,int new)
{
int count;
while(count=read(old,buffer,sizeof(buffer)))>0)
write(new,buffer,count);
}
