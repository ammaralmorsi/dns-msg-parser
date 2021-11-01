/* 
* Created by:
    ___                                      _   __                         
   /   |  ____ ___  ____ ___  ____ ______   / | / /___ ______________  _____
  / /| | / __ `__ \/ __ `__ \/ __ `/ ___/  /  |/ / __ `/ ___/ ___/ _ \/ ___/
 / ___ |/ / / / / / / / / / / /_/ / /     / /|  / /_/ (__  |__  )  __/ /    
/_/  |_/_/ /_/ /_/_/ /_/ /_/\__,_/_/     /_/ |_/\__,_/____/____/\___/_/   
	on 01/11/21
*/
#define gdh_success    0
#define gdh_mem_error  1

#include "../dns/dns_header.h"

/*
** get_dns_header() interpret a 12 sequence of bytes and construct a 
** dns_header to store the result.
** write_dns_header() interpret a valid dns_header structure to 
** a meaningful text stored in dest.
** After done with dns_header free_dns_header() must be called to
** avoid memory leaks.
*/

/*
** get_dns_header() takes header as its input and return a dns_header as
** its output.
** return 0 on success, 1 for error.
*/
int get_dns_header(const unsigned char* header, struct dns_header* *result);

/*
** The caller must call free()on the returned string after done 
** to avoid mem leak. A NULL is set to *dest to indicate an error.
*/
void write_dns_header(char* *dest, struct dns_header *src);

/*
** Free dns_header structure created by get_dns_header()
*/
void free_dns_header(struct dns_header* header);

