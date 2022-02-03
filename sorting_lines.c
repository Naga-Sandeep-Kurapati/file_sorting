#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt;
void* read_data_from_file(char *file_name);
void sort(char (*buf)[100]);
void write_data_into_file(char (*buf)[100],char *filename);
int main(int argc,char **argv)
{
	if(argc<2)
	{
		printf("error");
		return 0;
	}
	char (*buf)[100];
	buf=read_data_from_file(argv[1]);
	sort(buf);
	write_data_into_file(buf,argv[1]);
}
void* read_data_from_file(char *file_name)
{
	FILE *fp;
	char temp[100];
	char (*buf)[100]=NULL;
	fp=fopen(file_name,"r");
	if(fp==NULL)
	{
		printf("no");
		exit(0);
	}
	while(fgets(temp,100,fp))
	{
		temp[strlen(temp)-1]=0;
		buf=realloc(buf,(cnt+1)*(sizeof(*buf)));

		strcpy(buf[cnt],temp);
		cnt++;
	}
	fclose(fp);
	return buf;
}
void sort(char (*buf)[100])
{
	char temp[100];
	for(int i=cnt-1;i>0;i--)
		for(int j=0;j<i;j++)//to sort lines
			if(strcmp(buf[j],buf[j+1])>0)
			{
				strcpy(temp,buf[j]);
				strcpy(buf[j],buf[j+1]);
				strcpy(buf[j+1],temp);
			}
}
void write_data_into_file(char (*buf)[100],char *filename)
{
	FILE *fp;
	fp=fopen(filename,"w");
	for(int i=0;i<cnt;i++)
	{
		fputs(buf[i],fp);
		fputc(10,fp);
	}
	fclose(fp);
}



