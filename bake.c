#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// The following function is to be called at the the beginning of bake to open the bakefile

bool open_bakefile() {
	int Bakefile;
	int bakefile;
	const char *filename = "/Bakefile";
	const char *filename1 = "/bakefile";
	Bakefile = access(filename, F_OK);
	bakefile = access(filename1, F_OK);
	
	if(Bakefile == 0) {
		FILE * open_file;
		
		open_file = fopen("Bakefile", "r");
		return TRUE;
	}
	elseif(bakefile == 0) {
		FILE * open_file;
		
		open_file = fopen("bakefile", "r");
		return TRUE;
	}
	else {
		printf("check if a Bakefile or bakefile exists in current directory!");
		return FALSE;
	}
}

//The following function disregards any lines in Bakefile or bakefile that start with a #

void comment_check(FILE * open_file) {
	char buffer[15000];
	FILE * buffer_file = fopen("Bufferfile.txt", "a");
	while(1) {
		if(fgets(buffer, sizeof(buffer), open_file)==NULL) break;
		if (buffer[0] != '#') {
			fprintf(buffer_file,"%s",buffer);
			}
		else {
			continue;
		}
	}
}


//The following function is to extract the various text lines within Bakefile or bakefile

 void read_bakefile() {
	if(open_bakefile() != TRUE) {
		fprint("can't run without a Bakefile or a bakefile!");
	}
	else {
		comment_check(open_file);
	}
}

void main() {
	open_bakefile();
	read_bakefile();
}