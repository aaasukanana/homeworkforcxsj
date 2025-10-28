/***************************************************************************
 *   Copyright (C) 2012 by Process Control Engineers                       *
 *   Author Kyle Hayes  kylehayes@processcontrolengineers.com              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

 /**************************************************************************
  * CHANGE LOG                                                             *
  *                                                                        *
  * 2012-02-27  KRH - Created file.                                        *
  *                                                                        *
  **************************************************************************/


#ifndef __LIBPLCTAG_AB_DATA_H__
#define __LIBPLCTAG_AB_DATA_H__



#include <stdint.h>
#include <libplctag_tag.h>
#include <platform.h>
#include <util/attr.h>


#define MAX_SESSION_HOST 	(128)
#define MAX_CONN_PATH 		(128)
#define MAX_MSG_SIZE		(1024)
#define MAX_TAG_NAME 		(64)
#define MAX_TAG_TYPE_INFO 	(64)
#define MAX_REQ_RESP_SIZE	(768) /* enough? */
#define MAX_EIP_PACKET_SIZE	(540) /*
								   * AB says somewhere that you must
								   * support packets of 544 bytes.  We support 768.  That should
								   * be good for now.  The maximum we've seen is 540.  We'll
								   * use that.
								   *
								   * Hopefully 540 is safe.  This should be checked.
								   */

#define MAX_PCCC_PACKET_SIZE (244) /*
									* That's what the docs say.
									*
									* Needs more testing.
									*/

#define DEFAULT_MAX_REQUESTS (10)	/* number of requests and request sizes to allocate by default. */


/* AB Constants*/
#define AB_EIP_OK   (0)
#define AB_EIP_VERSION ((uint16_t)0x0001)

/* in milliseconds */
#define AB_EIP_DEFAULT_TIMEOUT 2000 /* in ms */

/* AB Commands */
#define AB_EIP_REGISTER_SESSION 	((uint16_t)0x0065)
#define AB_EIP_UNREGISTER_SESSION 	((uint16_t)0x0066)
#define AB_EIP_READ_RR_DATA 		((uint16_t)0x006F)
#define AB_EIP_CONNECTED_SEND 		((uint16_t)0x0070)

/* AB packet info */
#define AB_EIP_DEFAULT_PORT 44818

/* specific sub-commands */
#define AB_EIP_CMD_PCCC_EXECUTE     	((uint8_t)0x4B)
#define AB_EIP_CMD_FORWARD_CLOSE    	((uint8_t)0x4E)
#define AB_EIP_CMD_UNCONNECTED_SEND 	((uint8_t)0x52)
#define AB_EIP_CMD_FORWARD_OPEN     	((uint8_t)0x54)

/* CIP embedded packet commands */
#define AB_EIP_CMD_CIP_READ         	((uint8_t)0x4C)
#define AB_EIP_CMD_CIP_WRITE        	((uint8_t)0x4D)
#define AB_EIP_CMD_CIP_READ_FRAG		((uint8_t)0x52)
#define AB_EIP_CMD_CIP_WRITE_FRAG		((uint8_t)0x53)

/* flag set when command is OK */
#define AB_EIP_CMD_CIP_OK           	((uint8_t)0x80)

#define AB_CIP_STATUS_OK				((uint8_t)0x00)
#define AB_CIP_STATUS_FRAG				((uint8_t)0x06)

/* PCCC commands */
#define AB_EIP_PCCC_TYPED_CMD ((uint8_t)0x0F)
#define AB_EIP_PCCC_TYPED_READ_FUNC ((uint8_t)0x68)
#define AB_EIP_PCCC_TYPED_WRITE_FUNC ((uint8_t)0x67)


/* PCCC defs */
#define AB_PCCC_DATA_BIT            1
#define AB_PCCC_DATA_BIT_STRING     2
#define AB_PCCC_DATA_BYTE_STRING    3
#define AB_PCCC_DATA_INT            4
#define AB_PCCC_DATA_TIMER          5
#define AB_PCCC_DATA_COUNTER        6
#define AB_PCCC_DATA_CONTROL        7
#define AB_PCCC_DATA_REAL           8
#define AB_PCCC_DATA_ARRAY          9
#define AB_PCCC_DATA_ADDRESS        15
#define AB_PCCC_DATA_BCD            16




/* base data type byte values */
#define AB_CIP_DATA_BIT         ((uint8_t)0xC1)	/* Boolean value, 1 bit */
#define AB_CIP_DATA_SINT 		((uint8_t)0xC2)	/* Signed 8–bit integer value */
#define AB_CIP_DATA_INT 		((uint8_t)0xC3) /* Signed 16–bit integer value */
#define AB_CIP_DATA_DINT 		((uint8_t)0xC4)	/* Signed 32–bit integer value */
#define AB_CIP_DATA_LINT 		((uint8_t)0xC5)	/* Signed 64–bit integer value */
#define AB_CIP_DATA_USINT 		((uint8_t)0xC6)	/* Unsigned 8–bit integer value */
#define AB_CIP_DATA_UINT 		((uint8_t)0xC7)	/* Unsigned 16–bit integer value */
#define AB_CIP_DATA_UDINT		((uint8_t)0xC8)	/* Unsigned 32–bit integer value */
#define AB_CIP_DATA_ULINT		((uint8_t)0xC9)	/* Unsigned 64–bit integer value */
#define AB_CIP_DATA_REAL		((uint8_t)0xCA)	/* 32–bit floating point value, IEEE format */
#define AB_CIP_DATA_LREAL		((uint8_t)0xCB)	/* 64–bit floating point value, IEEE format */
#define AB_CIP_DATA_STIME 		((uint8_t)0xCC)	/* Synchronous time value */
#define AB_CIP_DATA_DATE		((uint8_t)0xCD)	/* Date value */
#define AB_CIP_DATA_TIME_OF_DAY	((uint8_t)0xCE) /* Time of day value */
#define AB_CIP_DATA_DATE_AND_TIME ((uint8_t)0xCF) /* Date and time of day value */
#define AB_CIP_DATA_STRING		((uint8_t)0xD0)	/* Character string, 1 byte per character */
#define AB_CIP_DATA_BYTE		((uint8_t)0xD1)	/* 8-bit bit string */
#define AB_CIP_DATA_WORD 		((uint8_t)0xD2)	/* 16-bit bit string */
#define AB_CIP_DATA_DWORD	 	((uint8_t)0xD3)	/* 32-bit bit string */
#define AB_CIP_DATA_LWORD 		((uint8_t)0xD4) /* 64-bit bit string */
#define AB_CIP_DATA_STRING2		((uint8_t)0xD5) /* Wide char character string, 2 bytes per character */
#define AB_CIP_DATA_FTIME		((uint8_t)0xD6) /* High resolution duration value */
#define AB_CIP_DATA_LTIME 		((uint8_t)0xD7)	/* Medium resolution duration value */
#define AB_CIP_DATA_ITIME 		((uint8_t)0xD8)	/* Low resolution duration value */
#define AB_CIP_DATA_STRINGN 	((uint8_t)0xD9) /* N-byte per char character string */
#define AB_CIP_DATA_SHORT_STRING ((uint8_t)0xDA) /* Counted character sting with 1 byte per character and 1 byte length indicator */
#define AB_CIP_DATA_TIME		((uint8_t)0xDB)	/* Duration in milliseconds */
#define AB_CIP_DATA_EPATH 		((uint8_t)0xDC) /* CIP path segment(s) */
#define AB_CIP_DATA_ENGUNIT 	((uint8_t)0xDD)	/* Engineering units */
#define AB_CIP_DATA_STRINGI		((uint8_t)0xDE)	/* International character string (encoding?) */

/* aggregate data type byte values */
#define AB_CIP_DATA_ABREV_STRUCT	((uint8_t)0xA0)	/* Data is an abbreviated struct type, i.e. a CRC of the actual type descriptor */
#define AB_CIP_DATA_ABREV_ARRAY		((uint8_t)0xA1)	/* Data is an abbreviated array type. The limits are left off */
#define AB_CIP_DATA_FULL_STRUCT		((uint8_t)0xA2) /* Data is a struct type descriptor */
#define AB_CIP_DATA_FULL_ARRAY		((uint8_t)0xA3)	/* Data is an array type descriptor */


/* transport class */
#define AB_EIP_TRANSPORT_CLASS_T3   ((uint8_t)0xA3)


#define AB_EIP_SECS_PER_TICK 0x0A
#define AB_EIP_TIMEOUT_TICKS 0x05
#define AB_EIP_VENDOR_ID 0xF33D /*tres 1337 */
#define AB_EIP_VENDOR_SN 0x21504345  /* the string !PCE */
#define AB_EIP_TIMEOUT_MULTIPLIER 0x01
#define AB_EIP_RPI  1000
#define AB_EIP_PLC5_PARAM 0x4302
#define AB_EIP_SLC_PARAM 0x4302
#define AB_EIP_LGX_PARAM 0x43F8
#define AB_EIP_TRANSPORT 0xA3


/* EIP Item Types */
#define AB_EIP_ITEM_NAI ((uint16_t)0x0000) /* NULL Address Item */
#define AB_EIP_ITEM_CAI ((uint16_t)0x00A1) /* connected address item */
#define AB_EIP_ITEM_CDI ((uint16_t)0x00B1) /* connected data item */
#define AB_EIP_ITEM_UDI ((uint16_t)0x00B2) /* Unconnected data item */


/* Types of AB protocols */
#define AB_PROTOCOL_PLC     1
#define AB_PROTOCOL_MLGX    2
#define AB_PROTOCOL_LGX     3


/* AB/EIP protocol specific version of the protocol struct */

/*typedef struct ab_protocol_t *ab_protocol;
#define AB_PROTOCOL_NULL ((ab_protocol)NULL)*/

typedef struct ab_session_t *ab_session_p;
#define AB_SESSION_NULL ((ab_session_p)NULL)

typedef struct ab_connection_t *ab_connection_old;
#define AB_CONNECTION_NULL ((ab_connection_old)NULL)

typedef struct ab_tag_t *ab_tag_p;
#define AB_TAG_NULL ((ab_tag_p)NULL)


typedef struct ab_request_t *ab_request_p;
#define AB_REQUEST_NULL ((ab_request_p)NULL)


/*struct ab_protocol_t {
    struct plc_protocol_t p_protocol;

    ab_session sessions;
};*/



#define MAX_REQS_IN_FLIGHT	(20)

struct ab_session_t {
    ab_session_p next;
    ab_session_p prev;

    /* gateway connection related info */
    char host[MAX_SESSION_HOST];
    int port;
    sock_p sock;
    int is_connected;

    /* registration info */
    uint32_t session_handle;

    /* Sequence ID for requests. */
    uint64_t session_seq_id;

    /* a list of the connections on this session */
    //ab_connection connections;

    /* current request being sent, only one at a time */
    ab_request_p current_request;

    /* list of outstanding requests for this session */
    ab_request_p requests;

    /* counter for number of messages in flight */
    int num_reqs_in_flight;

    /* data for receiving messages */
    uint64_t resp_seq_id;
    int has_response;
    int recv_offset;
    uint8_t recv_data[MAX_REQ_RESP_SIZE];

    /*int recv_size;*/

    /* tags for this session */
    ab_tag_p tags;
};

/*#define session_buf_clear(sess,size) do { if(sess) memset(sess->buf,0,size); } while(0)*/


struct ab_connection_t_old {
    //ab_connection next;
    //ab_connection prev;

    char *path;

    ab_session_p session;

    int is_connected;
    uint32_t targ_connection_id; /* the ID the target uses for this connection. */
    uint32_t orig_connection_id; /* the ID we use for this connection */
    uint16_t packet;
    uint16_t conn_serial_number;
    uint16_t conn_seq_num;

    /* need to save the connection path for later */
    uint8_t conn_path[MAX_CONN_PATH];
    uint8_t conn_path_size;

    /* how do we talk to this device? */
    int protocol_type;
    int use_dhp_direct;
    uint8_t dhp_src;
    uint8_t dhp_dest;

    ab_tag_p tags;
};


struct ab_tag_t {
    /*struct plc_tag_t p_tag;*/
	TAG_BASE_STRUCT;

    ab_tag_p next;
    ab_tag_p prev;

    //attr attributes;

    /* how do we talk to this device? */
    int protocol_type;
    int use_dhp_direct;
    uint8_t dhp_src;
    uint8_t dhp_dest;

    /* pointers back to session */
    ab_session_p session;

    /* this contains the encoded name */
    uint8_t encoded_name[MAX_TAG_NAME];
    int encoded_name_size;

    /* the connection IOI path */
    uint8_t conn_path[MAX_CONN_PATH];
    uint8_t conn_path_size;

    uint8_t routing_path[MAX_CONN_PATH];
    uint8_t routing_path_size;

    /* storage for the encoded type. */
    uint8_t encoded_type_info[MAX_TAG_TYPE_INFO];
    int encoded_type_info_size;

    /* number of elements and size of each in the tag. */
    int elem_count;
    int elem_size;

    /* requests */
    int pre_write_read;
    int first_read;
    int num_read_requests; /* number of read requests */
    int num_write_requests; /* number of write requests */
    int max_requests; /* how many can we have without reallocating? */
    int *read_req_sizes;
    int *write_req_sizes;

    ab_request_p *reqs;

    /* flags for operations */
    int read_in_progress;
    int write_in_progress;
    int connect_in_progress;
};


/*
 * this structure contains data necessary to set up a request and hold
 * the resulting response.
 */

struct ab_request_t {
	ab_request_p next; 	/* for linked list */

	int req_id; 		/* which request is this for the tag? */
	int data_size; 		/* how many bytes did we get? */

	/* flags for communicating with background thread */
	int send_request;
	int send_in_progress;
	int resp_received;
	int recv_in_progress;
	int abort_request;

	int status;
	int debug;

	/* used when processing a response */
	int processed;

	ab_session_p session;

	uint64_t session_seq_id;
	uint32_t conn_id;
	uint16_t conn_seq;

	/* used by the background thread for incrementally getting data */
	int current_offset;
	int request_size; /* total bytes, not just data */
	uint8_t data[MAX_REQ_RESP_SIZE];
};



/*********************************************************************
 ************************ AB EIP Structures **************************
 ********************************************************************/


/* EIP Encapsulation Header */
START_PACK typedef struct {
    uint16_t encap_command;
    uint16_t encap_length;
    uint32_t encap_session_handle;
    uint32_t encap_status;
    uint64_t encap_sender_context;
    uint32_t encap_options;
} END_PACK eip_encap_t;

/* Session Registration Request */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;         /* ALWAYS 0x0065 Register Session*/
    uint16_t encap_length;   /* packet size in bytes - 24 */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;  /* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t encap_options;         /* 0, reserved for future use */

    /* session registration request */
    uint16_t eip_version;
    uint16_t option_flags;
} END_PACK eip_session_reg_req;


/* Forward Open Request */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x006f Unconnected Send*/
    uint16_t encap_length;   /* packet size in bytes - 24 */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;  /* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t encap_options;         /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds */

    /* Common Packet Format - CPF Unconnected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_nai_item_type;     /* ALWAYS 0 */
    uint16_t cpf_nai_item_length;   /* ALWAYS 0 */
    uint16_t cpf_udi_item_type;     /* ALWAYS 0x00B2 - Unconnected Data Item */
    uint16_t cpf_udi_item_length;   /* REQ: fill in with length of remaining data. */

    /* CM Service Request - Connection Manager */
    uint8_t cm_service_code;        /* ALWAYS 0x54 Forward Open Request */
    uint8_t cm_req_path_size;       /* ALWAYS 2, size in words of path, next field */
    uint8_t cm_req_path[4];         /* ALWAYS 0x20,0x06,0x24,0x01 for CM, instance 1*/

    /* Forward Open Params */
    uint8_t secs_per_tick;       	/* seconds per tick */
    uint8_t timeout_ticks;       	/* timeout = srd_secs_per_tick * src_timeout_ticks */
    uint32_t orig_to_targ_conn_id;  /* 0, returned by target in reply. */
    uint32_t targ_to_orig_conn_id;  /* what is _our_ ID for this connection, use ab_connection ptr as id ? */
    uint16_t conn_serial_number;    /* our connection serial number ?? */
    uint16_t orig_vendor_id;        /* our unique vendor ID */
    uint32_t orig_serial_number;    /* our unique serial number */
    uint8_t conn_timeout_multiplier;/* timeout = mult * RPI */
    uint8_t reserved[3];            /* reserved, set to 0 */
    uint32_t orig_to_targ_rpi;      /* us to target RPI - Request Packet Interval in microseconds */
    uint16_t orig_to_targ_conn_params; /* some sort of identifier of what kind of PLC we are??? */
    uint32_t targ_to_orig_rpi;      /* target to us RPI, in microseconds */
    uint16_t targ_to_orig_conn_params; /* some sort of identifier of what kind of PLC the target is ??? */
    uint8_t transport_class;        /* ALWAYS 0xA3, server transport, class 3, application trigger */
    uint8_t path_size;              /* size of connection path in 16-bit words
                                     * connection path from MSG instruction.
                                     *
                                     * EG LGX with 1756-ENBT and CPU in slot 0 would be:
                                     * 0x01 - backplane port of 1756-ENBT
                                     * 0x00 - slot 0 for CPU
                                     * 0x20 - class
                                     * 0x02 - MR Message Router
                                     * 0x24 - instance
                                     * 0x01 - instance #1.
                                     */

    uint8_t conn_path[ZLA_SIZE];    /* connection path as above */
} END_PACK eip_forward_open_request;


/* Forward Open Response */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x006f Unconnected Send*/
    uint16_t encap_length;   /* packet size in bytes - 24 */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t options;               /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds */

    /* Common Packet Format - CPF Unconnected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_nai_item_type;     /* ALWAYS 0 */
    uint16_t cpf_nai_item_length;   /* ALWAYS 0 */
    uint16_t cpf_udi_item_type;     /* ALWAYS 0x00B2 - Unconnected Data Item */
    uint16_t cpf_udi_item_length;   /* REQ: fill in with length of remaining data. */

    /* Forward Open Reply */
    uint8_t resp_service_code;      /* returned as 0xD4 */
    uint8_t reserved1;               /* returned as 0x00? */
    uint8_t general_status;         /* 0 on success */
    uint8_t status_size;            /* number of 16-bit words of extra status, 0 if success */
    uint32_t orig_to_targ_conn_id;  /* target's connection ID for us, save this. */
    uint32_t targ_to_orig_conn_id;  /* our connection ID back for reference */
    uint16_t conn_serial_number;    /* our connection serial number from request */
    uint16_t orig_vendor_id;        /* our unique vendor ID from request*/
    uint32_t orig_serial_number;    /* our unique serial number from request*/
    uint32_t orig_to_targ_api;      /* Actual packet interval, microsecs */
    uint32_t targ_to_orig_api;      /* Actual packet interval, microsecs */
    uint8_t app_data_size;          /* size in 16-bit words of send_data at end */
    uint8_t reserved2;
    uint8_t app_data[ZLA_SIZE];
} END_PACK eip_forward_open_response;



/* Forward Close Request */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x006f Unconnected Send*/
    uint16_t encap_length;   /* packet size in bytes - 24 */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t encap_options;         /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds */

    /* Common Packet Format - CPF Unconnected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_nai_item_type;     /* ALWAYS 0 */
    uint16_t cpf_nai_item_length;   /* ALWAYS 0 */
    uint16_t cpf_udi_item_type;     /* ALWAYS 0x00B2 - Unconnected Data Item */
    uint16_t cpf_udi_item_length;   /* REQ: fill in with length of remaining data. */

    /* CM Service Request - Connection Manager */
    uint8_t cm_service_code;        /* ALWAYS 0x4E Forward Close Request */
    uint8_t cm_req_path_size;       /* ALWAYS 2, size in words of path, next field */
    uint8_t cm_req_path[4];         /* ALWAYS 0x20,0x06,0x24,0x01 for CM, instance 1*/

    /* Forward Open Params */
    uint8_t secs_per_tick;       /* seconds per tick */
    uint8_t timeout_ticks;       /* timeout = srd_secs_per_tick * src_timeout_ticks */
    uint16_t conn_serial_number;    /* our connection serial number ?? */
    uint16_t orig_vendor_id;        /* our unique vendor ID */
    uint32_t orig_serial_number;    /* our unique serial number */
    uint8_t path_size;              /* size of connection path in 16-bit words*/
    uint8_t reserved;               /* ALWAYS 0 */
    uint8_t conn_path[ZLA_SIZE];
} END_PACK eip_forward_close_req;



/* Forward Close Response */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x006f Unconnected Send*/
    uint16_t encap_length;   /* packet size in bytes - 24 */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t encap_options;         /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds */

    /* Common Packet Format - CPF Unconnected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_nai_item_type;     /* ALWAYS 0 */
    uint16_t cpf_nai_item_length;   /* ALWAYS 0 */
    uint16_t cpf_udi_item_type;     /* ALWAYS 0x00B2 - Unconnected Data Item */
    uint16_t cpf_udi_item_length;   /* REQ: fill in with length of remaining data. */

    /* Forward Close Response */
    uint8_t resp_service_code;      /* returned as 0xCE */
    uint8_t reserved1;               /* returned as 0x00? */
    uint8_t general_status;         /* 0 on success */
    uint8_t status_size;            /* number of 16-bit words of extra status, 0 if success */
    uint16_t conn_serial_number;    /* our connection serial number ?? */
    uint16_t orig_vendor_id;        /* our unique vendor ID */
    uint32_t orig_serial_number;    /* our unique serial number */
    uint8_t path_size;              /* size of connection path in 16-bit words*/
    uint8_t reserved;               /* ALWAYS 0 */
    uint8_t conn_path[ZLA_SIZE];
} END_PACK eip_forward_close_resp;






/* PCCC Request */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x0070 Connected Send */
    uint16_t encap_length;   /* packet size in bytes less the header size, which is 24 bytes */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t options;               /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, zero for Connected Sends! */

    /* Common Packet Format - CPF Connected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_cai_item_type;     /* ALWAYS 0x00A1 Connected Address Item */
    uint16_t cpf_cai_item_length;   /* ALWAYS 2 ? */
    uint32_t cpf_targ_conn_id;           /* the connection id from Forward Open */
    uint16_t cpf_cdi_item_type;     /* ALWAYS 0x00B1, Connected Data Item type */
    uint16_t cpf_cdi_item_length;   /* length in bytes of the rest of the packet */

    /* Connection sequence number */
    uint16_t cpf_conn_seq_num;      /* connection sequence ID, inc for each message */

    /* PCCC Command Req Routing */
    uint8_t service_code;           /* ALWAYS 0x4B, Execute PCCC */
    uint8_t req_path_size;          /* ALWAYS 0x02, in 16-bit words */
    uint8_t req_path[4];            /* ALWAYS 0x20,0x67,0x24,0x01 for PCCC */
    uint8_t request_id_size;        /* ALWAYS 7 */
    uint16_t vendor_id;             /* Our CIP Vendor ID */
    uint32_t vendor_serial_number;  /* Our CIP Vendor Serial Number */

    /* PCCC Command */
    uint8_t pccc_command;           /* CMD read, write etc. */
    uint8_t pccc_status;            /* STS 0x00 in request */
    uint16_t pccc_seq_num;          /* TNS transaction/sequence id */
    uint8_t pccc_function;          /* FNC sub-function of command */
    uint16_t pccc_offset;           /* offset of requested in total request */
    uint16_t pccc_transfer_size;    /* total number of words requested */
    uint8_t pccc_data[ZLA_SIZE];   /* send_data for request */
} END_PACK eip_pccc_req_old;




/* PCCC Response */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x0070 Connected Send */
    uint16_t encap_length;   /* packet size in bytes less the header size, which is 24 bytes */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t options;               /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, zero for Connected Sends! */

    /* Common Packet Format - CPF Connected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_cai_item_type;     /* ALWAYS 0x00A1 Connected Address Item */
    uint16_t cpf_cai_item_length;   /* ALWAYS 2 ? */
    uint32_t cpf_targ_conn_id;           /* the connection id from Forward Open */
    uint16_t cpf_cdi_item_type;     /* ALWAYS 0x00B1, Connected Data Item type */
    uint16_t cpf_cdi_item_length;   /* length in bytes of the rest of the packet */

    /* connection ID from request */
    uint16_t cpf_conn_seq_num;      /* connection sequence ID, inc for each message */

    /* PCCC Reply */
    uint8_t reply_service;          /* 0xCB Execute PCCC Reply */
    uint8_t reserved;               /* 0x00 in reply */
    uint8_t general_status;         /* 0x00 for success */
    uint8_t status_size;            /* number of 16-bit words of extra status, 0 if success */

    /* PCCC Command Req Routing */
    uint8_t request_id_size;        /* ALWAYS 7 */
    uint16_t vendor_id;             /* Our CIP Vendor ID */
    uint32_t vendor_serial_number;  /* Our CIP Vendor Serial Number */

    /* PCCC Command */
    uint8_t pccc_command;           /* CMD read, write etc. */
    uint8_t pccc_status;            /* STS 0x00 in request */
    uint16_t pccc_seq_num;          /* TNSW transaction/connection sequence number */
    uint8_t pccc_data[ZLA_SIZE];    /* data for PCCC request. */
} END_PACK eip_pccc_resp_old;



/* PCCC Request PLC5 DH+ Only */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x0070 Connected Send */
    uint16_t encap_length;   /* packet size in bytes less the header size, which is 24 bytes */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;  /* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t options;               /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, zero for Connected Sends! */

    /* Common Packet Format - CPF Connected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_cai_item_type;     /* ALWAYS 0x00A1 Connected Address Item */
    uint16_t cpf_cai_item_length;   /* ALWAYS 2 ? */
    uint32_t cpf_targ_conn_id;           /* the connection id from Forward Open */
    uint16_t cpf_cdi_item_type;     /* ALWAYS 0x00B1, Connected Data Item type */
    uint16_t cpf_cdi_item_length;   /* length in bytes of the rest of the packet */

    /* Connection sequence number */
    //uint16_t cpf_conn_seq_num;      /* connection sequence ID, inc for each message */

    /* PLC5 DH+ Routing */
    uint8_t dest_link;
    uint8_t dest_node;
    uint8_t src_link;
    uint8_t src_node;

    /* PCCC Command */
    uint8_t pccc_command;           /* CMD read, write etc. */
    uint8_t pccc_status;            /* STS 0x00 in request */
    uint16_t pccc_seq_num;         /* TNSW transaction/sequence id */
    uint8_t pccc_function;          /* FNC sub-function of command */
    uint16_t pccc_pad;              /* what is this?? */
    uint16_t pccc_transfer_size;    /* number of words requested */
    uint8_t pccc_data[ZLA_SIZE];   /* send_data for request */
} END_PACK eip_pccc_dhp_req_old;




/* PCCC PLC5 DH+ Only Response */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x0070 Connected Send */
    uint16_t encap_length;   /* packet size in bytes less the header size, which is 24 bytes */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;  /* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t options;               /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, zero for Connected Sends! */

    /* Common Packet Format - CPF Connected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_cai_item_type;     /* ALWAYS 0x00A1 Connected Address Item */
    uint16_t cpf_cai_item_length;   /* ALWAYS 2 ? */
    uint32_t cpf_targ_conn_id;           /* the connection id from Forward Open */
    uint16_t cpf_cdi_item_type;     /* ALWAYS 0x00B1, Connected Data Item type */
    uint16_t cpf_cdi_item_length;   /* length in bytes of the rest of the packet */

    /* connection ID from request */
    //uint16_t cpf_conn_seq_num;      /* connection sequence ID, inc for each message */

    /* PLC5 DH+ Routing */
    uint8_t dest_link;
    uint8_t dest_node;
    uint8_t src_link;
    uint8_t src_node;

    /* PCCC Command Req Routing */
    uint8_t request_id_size;        /* ALWAYS 7 */
    uint16_t vendor_id;             /* Our CIP Vendor ID */
    uint32_t vendor_serial_number;  /* Our CIP Vendor Serial Number */

    /* PCCC Command */
    uint8_t pccc_command;           /* CMD read, write etc. */
    uint8_t pccc_status;            /* STS 0x00 in request */
    uint16_t pccc_seq_num;         /* TNSW transaction/connection sequence number */
    uint8_t pccc_data[ZLA_SIZE];    /* data for PCCC request. */
} END_PACK eip_pccc_dhp_resp_old;



/* CIP "native" Request */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x0070 Connected Send */
    uint16_t encap_length;   /* packet size in bytes less the header size, which is 24 bytes */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;  /* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t options;               /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, zero for Connected Sends! */

    /* Common Packet Format - CPF Connected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_cai_item_type;     /* ALWAYS 0x00A1 Connected Address Item */
    uint16_t cpf_cai_item_length;   /* ALWAYS 2 ? */
    uint32_t cpf_targ_conn_id;           /* the connection id from Forward Open */
    uint16_t cpf_cdi_item_type;     /* ALWAYS 0x00B1, Connected Data Item type */
    uint16_t cpf_cdi_item_length;   /* length in bytes of the rest of the packet */

    /* Connection sequence number */
    uint16_t cpf_conn_seq_num;      /* connection sequence ID, inc for each message */

    /* CIP Service Info */
    uint8_t service_code;           /* ALWAYS 0x4C, CIP_READ */
    /*uint8_t req_path_size;*/          /* path size in words */
    uint8_t req_path[ZLA_SIZE];
} END_PACK eip_cip_req_old;




/* CIP Response */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    /* ALWAYS 0x0070 Connected Send */
    uint16_t encap_length;   /* packet size in bytes less the header size, which is 24 bytes */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t options;               /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, zero for Connected Sends! */

    /* Common Packet Format - CPF Connected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_cai_item_type;     /* ALWAYS 0x00A1 Connected Address Item */
    uint16_t cpf_cai_item_length;   /* ALWAYS 2 ? */
    uint32_t cpf_orig_conn_id;      /* our connection ID, NOT the target's */
    uint16_t cpf_cdi_item_type;     /* ALWAYS 0x00B1, Connected Data Item type */
    uint16_t cpf_cdi_item_length;   /* length in bytes of the rest of the packet */

    /* connection ID from request */
    uint16_t cpf_conn_seq_num;      /* connection sequence ID, inc for each message */

    /* CIP Reply */
    uint8_t reply_service;          /* 0xCC CIP READ Reply */
    uint8_t reserved;              	/* 0x00 in reply */
    uint8_t status;                 /* 0x00 for success */
    uint8_t num_status_words;	   	/* number of 16-bit words in status */

    /* CIP Data*/
    uint8_t resp_data[ZLA_SIZE];
} END_PACK eip_cip_resp_old;



/* CIP "native" Unconnected Request */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    		/* ALWAYS 0x006f Unconnected Send*/
    uint16_t encap_length;   		/* packet size in bytes - 24 */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;	/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t encap_options;         /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, 5 or 10 seems to be good.*/

    /* Common Packet Format - CPF Unconnected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_nai_item_type;     /* ALWAYS 0 */
    uint16_t cpf_nai_item_length;   /* ALWAYS 0 */
    uint16_t cpf_udi_item_type;     /* ALWAYS 0x00B2 - Unconnected Data Item */
    uint16_t cpf_udi_item_length;   /* REQ: fill in with length of remaining data. */

    /* CM Service Request - Connection Manager */
    uint8_t cm_service_code;        /* ALWAYS 0x52 Unconnected Send */
    uint8_t cm_req_path_size;       /* ALWAYS 2, size in words of path, next field */
    uint8_t cm_req_path[4];         /* ALWAYS 0x20,0x06,0x24,0x01 for CM, instance 1*/

    /* Unconnected send */
    uint8_t secs_per_tick;       	/* seconds per tick */
    uint8_t timeout_ticks;       	/* timeout = src_secs_per_tick * src_timeout_ticks */

    /* size ? */
    uint16_t uc_cmd_length;			/* length of embedded packet */

    /* CIP read/write request, embedded packet */

    /* IOI path to target device, connection IOI */
} END_PACK eip_cip_uc_req;




/* CIP "native" Unconnected Response */
START_PACK typedef struct {
    /* encap header */
    uint16_t encap_command;    		/* ALWAYS 0x006f Unconnected Send*/
    uint16_t encap_length;   		/* packet size in bytes - 24 */
    uint32_t encap_session_handle;  /* from session set up */
    uint32_t encap_status;          /* always _sent_ as 0 */
    uint64_t encap_sender_context;	/* whatever we want to set this to, used for
                                     * identifying responses when more than one
                                     * are in flight at once.
                                     */
    uint32_t encap_options;         /* 0, reserved for future use */

    /* Interface Handle etc. */
    uint32_t interface_handle;      /* ALWAYS 0 */
    uint16_t router_timeout;        /* in seconds, 5 or 10 seems to be good.*/

    /* Common Packet Format - CPF Unconnected */
    uint16_t cpf_item_count;        /* ALWAYS 2 */
    uint16_t cpf_nai_item_type;     /* ALWAYS 0 */
    uint16_t cpf_nai_item_length;   /* ALWAYS 0 */
    uint16_t cpf_udi_item_type;     /* ALWAYS 0x00B2 - Unconnected Data Item */
    uint16_t cpf_udi_item_length;   /* REQ: fill in with length of remaining data. */

    /* CIP read/write response, embedded packet */
    uint8_t reply_service;          /*  */
    uint8_t reserved;              	/* 0x00 in reply */
    uint8_t status;                 /* 0x00 for success */
    uint8_t num_status_words;	   	/* number of 16-bit words in status */

} END_PACK eip_cip_uc_resp;



START_PACK typedef struct {
    /* PCCC Command Req Routing */
    uint8_t service_code;           /* ALWAYS 0x4B, Execute PCCC */
    uint8_t req_path_size;          /* ALWAYS 0x02, in 16-bit words */
    uint8_t req_path[4];            /* ALWAYS 0x20,0x67,0x24,0x01 for PCCC */
    uint8_t request_id_size;        /* ALWAYS 7 */
    uint16_t vendor_id;             /* Our CIP Vendor ID */
    uint32_t vendor_serial_number;  /* Our CIP Vendor Serial Number */

    /* PCCC Command */
    uint8_t pccc_command;           /* CMD read, write etc. */
    uint8_t pccc_status;            /* STS 0x00 in request */
    uint16_t pccc_seq_num;          /* TNS transaction/sequence id */
    uint8_t pccc_function;          /* FNC sub-function of command */
    uint16_t pccc_offset;           /* offset of requested in total request */
    uint16_t pccc_transfer_size;    /* total number of words requested */
    uint8_t pccc_data[ZLA_SIZE];   /* send_data for request */
} END_PACK pccc_req;



START_PACK typedef struct {
    /* PCCC Reply */
    uint8_t reply_code;          /* 0xCB Execute PCCC Reply */
    uint8_t reserved;               /* 0x00 in reply */
    uint8_t general_status;         /* 0x00 for success */
    uint8_t status_size;            /* number of 16-bit words of extra status, 0 if success */

    /* PCCC Command Req Routing */
    uint8_t request_id_size;        /* ALWAYS 7 */
    uint16_t vendor_id;             /* Our CIP Vendor ID */
    uint32_t vendor_serial_number;  /* Our CIP Vendor Serial Number */

    /* PCCC Command */
    uint8_t pccc_command;           /* CMD read, write etc. */
    uint8_t pccc_status;            /* STS 0x00 in request */
    uint16_t pccc_seq_num;          /* TNSW transaction/connection sequence number */
    uint8_t pccc_data[ZLA_SIZE];    /* data for PCCC response. */
} END_PACK pccc_resp;






#endif
