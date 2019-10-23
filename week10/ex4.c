#include "sys/types.h"
#include <dirent.h>
#include <libgen.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
   #include <stdlib.h>

int has_2_hard_links( struct stat stats ){

    if ( stats.st_nlink == 2 ){
    	return 1;
    }
    else
    	return 0;

}


char *read_file_info( char* file){

		struct stat st;

	    if ((stat(file, &st) == 0) && has_2_hard_links(st) && strcmp(file, "./tmp/." ))
    {
		printf("File %s has two links: \n",file );
		
		fflush(stdout);

		char cmd[70];
		sprintf(cmd, "find ~ -inum %d",st.st_ino);
		system(cmd);

		printf("\n");
		fflush(stdout);
    }
}

int main(){




	char *path = "./tmp/";
	char path2[1000];
	DIR *dirp = opendir(path);
	if (dirp == NULL) { return (228); }
	
	struct dirent *dp;
	while ((dp = readdir(dirp)) != NULL) {
		if ( dp ){
			memset(path2,0,sizeof(path2));
			strcat(path2, path);
			strcat(path2,dp->d_name);
			read_file_info(path2) ;
		}
	}
	(void)closedir(dirp); 



	return 0;
}