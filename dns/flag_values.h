/* 
* Created by:
    ___                                      _   __                         
   /   |  ____ ___  ____ ___  ____ ______   / | / /___ ______________  _____
  / /| | / __ `__ \/ __ `__ \/ __ `/ ___/  /  |/ / __ `/ ___/ ___/ _ \/ ___/
 / ___ |/ / / / / / / / / / / /_/ / /     / /|  / /_/ (__  |__  )  __/ /    
/_/  |_/_/ /_/ /_/_/ /_/ /_/\__,_/_/     /_/ |_/\__,_/____/____/\___/_/   
	on 31/10/21
*/

/* This file contains SOME of the common flags values in a typical DNS msg. */

/* QR VALUES */
/*
** Query/Response: Differentiates between queries and responses.
** Set to 0 when the query is generated, and then changed to 1 
** when that query is changed to a response by a replying server.
**
*/
#define QR_QUERY    0
#define QR_RESPONSE 1

/* OPCODE VALUES */
/*
** A standard query
*/
#define OP_QUERY  0
/*
** An inverse query.
*/
#define OP_IQUERY 1
/*
** A server status request.
*/
#define OP_STATUS 2
/*
** Special messages.
*/
#define OP_NOTIFY 4
#define OP_UPDATE 5

/* AA VALUES */
/*
** Authoritative Answer: This bit is set to 1 in a response to indicate that
** the server that created the response is authoritaive for the zone in which
** the domain name specified in the Question section is located. If it is 0, 
** the response is non-authoritavie.
*/
#define AA_NONAUTH    0
#define AA_AUTH       1

/* TC VALUES */
/*
** Truncation Flag: When set to 1, indicates that the messsage was truncated 
** due to its length being longer than the maximum permitted for the type of 
** transport mechanism used. UDP messages are limited to 512 bytes, so this bit 
** being sent usually is an indication that the message was sent using UDP and 
** was too long to fit. The client may issue an error, or establish a TCP session
** to get the full message.
*/
#define TC_NOTRUNC       0
#define TC_TRUNC         1

/* RD VALUES  */
/*
** Recursion Desired: When set in a query, requests that the server receiving the 
** query attempt to answer the query recursizely, if the server supports recursive 
** resolution. The value of this bit is NOT CHANGED IN THE RESPONSE.
*/
#define RD_NORECDES 0
#define RD_RECDES   1

/* RA VALUES */
/*
** Recursion Available: Set to 1 or cleared to 0 IN A RESPONSE to indicate whether 
** the server creating the response supports recursive queries.
*/
#define RA_RECNOTAVAIL  0
#define RA_RECAVAIL     1

/* RCODE VALUES */
/* 
** No erro occurred. 
*/
#define RC_NOERRO     0
/*
** The server was unable to respond to the query due to a problem with how it was
** constructed.
*/
#define RC_FORMATERRO 1
/*
** The server was unable to respond to the query due to a problem with the server
** itself.
*/
#define RC_SERVFAIL   2
/*
** The name specified in the query does not exist in the domain.
*/
#define RC_NAMERRO    3
/*
** The server refused to process the query.
*/
#define RC_REFUSED    5

/* End for flag definitions */

