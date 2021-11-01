#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../src/header_parser.h"

int main(void)
{
	struct dns_header* p_dns_header;
	char *s;
	unsigned char header[12];

	read(0, header, 12);
	
	get_dns_header(header, &p_dns_header);
	write_dns_header(&s, p_dns_header);
	free_dns_header(p_dns_header);
	printf("%s\n", s);
	free(s); 
	
	return 0;
}

