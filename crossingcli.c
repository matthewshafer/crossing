#include "lib/crossing.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
	crossing_data userdata;
	char c;
	int flags = 0;
	
	while((c = getopt(argc, argv, "u:p:f:m:")) != -1)
	{
		switch(c)
		{
			case 'u':
				userdata.username = optarg;
				flags += 1000;
				break;
			// currently not using this one
			case 'p':
				userdata.password = optarg;
				flags += 100;
				break;
			case 'f':
				userdata.from = optarg;
				flags += 10;
				break;
			case 'm':
				userdata.message = optarg;
				flags += 1;
				break;
		}
	}
	
	if(flags == 1111)
	{
		crossing_send_notification(&userdata);
	}
	else
	{
		printf("not enough args\n");
	}
	
	
	return 0;
}