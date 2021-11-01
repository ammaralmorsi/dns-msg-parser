/* 
* Created by:
    ___                                      _   __                         
   /   |  ____ ___  ____ ___  ____ ______   / | / /___ ______________  _____
  / /| | / __ `__ \/ __ `__ \/ __ `/ ___/  /  |/ / __ `/ ___/ ___/ _ \/ ___/
 / ___ |/ / / / / / / / / / / /_/ / /     / /|  / /_/ (__  |__  )  __/ /    
/_/  |_/_/ /_/ /_/_/ /_/ /_/\__,_/_/     /_/ |_/\__,_/____/____/\___/_/   
	on 01/11/21
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "header_parser.h"

int
get_dns_header(const unsigned char* header, struct dns_header* *result)
{
	*result = (struct dns_header*)malloc(sizeof(struct dns_header));
	if(*result == NULL)
		return gdh_mem_error;

	memset(*result, 0, sizeof(struct dns_header));
	
	(*result)->ID  = ( ( header[0] & 0xff ) << 8 ) + ( header[1] & 0xff );
	(*result)->QR  = ( header[2] & 0x80 ) >> 7;
	(*result)->OP  = ( header[2] & 0x78 ) >> 3;
	(*result)->AA  = ( header[2] & 0x04 ) >> 2;
	(*result)->TC  = ( header[2] & 0x02 ) >> 1;
	(*result)->RD  = ( header[2] & 0x01 ) >> 0;
	(*result)->RA  = ( header[3] & 0x80 ) >> 7;
	(*result)->RC  = ( header[3] & 0x0f ) >> 0;
	(*result)->QDC = ( ( header[4] & 0xff ) << 8 ) + ( header[5] & 0xff );
	(*result)->ANC = ( ( header[6] & 0xff ) << 8 ) + ( header[7] & 0xff );
	(*result)->NSC = ( ( header[8] & 0xff ) << 8 ) + ( header[9] & 0xff );
	(*result)->ARC = ( ( header[10] & 0xff ) << 8 ) + ( header[11] & 0xff);

	return gdh_success;
}

void
free_dns_header(struct dns_header* header)
{
	if(header != NULL)
		free(header);

	return;
}

void
write_dns_header(char* *dest, struct dns_header *src)
{
	char num_hold[8];
	if(src == NULL)
	{
		*dest = NULL;
		return;
	}

	*dest = (char *) malloc(1024*sizeof(char));
	if(*dest == NULL)
		return;
	
	strcpy(*dest, "");

	strcat(*dest, "ID: ");
	sprintf(num_hold, "%d",src->ID);
	strcat(*dest, num_hold);

	strcat(*dest, "\nQR: ");
	if( src->QR == QR_QUERY ) strcat(*dest, "Query");
	else /* src->QR == QR_RESPONSE */ strcat(*dest, "Response");

	strcat(*dest, "\nOP: ");
	if     ( src->OP == OP_QUERY  ) strcat(*dest, "Standard Query");
	else if( src->OP == OP_IQUERY ) strcat(*dest, "Inverse Query");
	else if( src->OP == OP_STATUS ) strcat(*dest, "Status request");
	else if( src->OP == OP_NOTIFY ) strcat(*dest, "Notify");
	else /* src->OP == OP_UPDATE */ strcat(*dest, "Update");
	
	strcat(*dest, "\nAA: ");
	if( src->AA == AA_NONAUTH ) strcat(*dest, "Non Authoritative response");
	else /* src->AA == AA_AUTH */ strcat(*dest, "Authoritative response");

	strcat(*dest, "\nTC: ");
	if( src->TC == TC_NOTRUNC ) strcat(*dest, "No Truncation");
	else /* src->TC == TC_TRUNC */ strcat(*dest, "Truncation");

	strcat(*dest, "\nRD: ");
	if( src->RD == RD_NORECDES ) strcat(*dest, "No recursion desired");
	else /* src->RD == RD_RECDES */ strcat(*dest, "Recursion desired");

	strcat(*dest, "\nRA: ");
	if( src->RA == RA_RECNOTAVAIL ) strcat(*dest, "Recursion not available");
	else /* src->RA == RA_RECAVAIL */ strcat(*dest, "Recursion available");

	strcat(*dest, "\nRC: ");
	if     ( src->RC == RC_NOERRO ) strcat(*dest, "No error");
	else if( src->RC == RC_FORMATERRO ) strcat(*dest, "Format error");
	else if( src->RC == RC_SERVFAIL ) strcat(*dest, "Server fail");
	else if( src->RC == RC_NOERRO ) strcat(*dest, "Name does not exit");
	else /* src->RC == RC_REFUSED */ strcat(*dest, "Server refused");

	strcat(*dest, "\nNumber of Questions: ");
	sprintf(num_hold, "%d", src->QDC);
	strcat(*dest, num_hold);

	strcat(*dest, "\nNumber of Answers: ");
	sprintf(num_hold, "%d", src->ANC);
	strcat(*dest, num_hold);
	
	strcat(*dest, "\nAuthority Record Count: ");
	sprintf(num_hold, "%d", src->NSC);
	strcat(*dest, num_hold);

	strcat(*dest, "\nAdditional Record Count: ");
	sprintf(num_hold, "%d", src->ARC);
	strcat(*dest, num_hold);

	return;
}

