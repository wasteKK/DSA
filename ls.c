#include<dirent.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<stdio.h>


int main(){
	DIR *d;
	struct dirent *de;
	struct stat buf;
	int i,j;
	char P[10] = "rwxrwxrwx",AP[10] = "";
	struct passwd *p;
	struct group *g;
	struct tm *t;
	char time[26];
	d = opendir(".");
	while( dereaddir(d)!=NULL)
	{
		stat(de->d_name,&buf);
		
		if(S_ISDIR(buf.st_mode)) printf("d");
		else if(S_ISREG(buf.st_mode)) printf("-");
		else if(S_ISCHR(buf.st_mode)) printf("c");
		else if(S_ISBLK(buf.st_mode)) printf("b");
		else if(S_ISLNK(buf.st_mode)) printf("l");
		else if(S_ISFIFO(buf.st_mode)) printf("p");
		else if(S_ISSOCK(buf.st_mode)) printf("s");
		
		for(i = 0,j = (1<<8); i<9; i++,j<<=1)
	}
}
