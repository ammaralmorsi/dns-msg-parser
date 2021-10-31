#include "flag_values.h"

struct dns_header
{
	unsigned short ID;
	unsigned char  QR;
	unsigned char  OP;
	unsigned char  AA;
	unsigned char  TC;
	unsigned char  RD;
	unsigned char  RA;
	unsigned char  RC;
	unsigned short QDC;
	unsigned short ANC;
	unsigned short NSC;
	unsigned short ARC;
};

