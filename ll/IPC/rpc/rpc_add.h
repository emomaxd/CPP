/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPC_ADD_H_RPCGEN
#define _RPC_ADD_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct numbers {
	int a;
	int b;
};
typedef struct numbers numbers;

#define MYAPP_PROG 0x12345
#define MYAPP_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define add 1
extern  int * add_1(numbers *, CLIENT *);
extern  int * add_1_svc(numbers *, struct svc_req *);
extern int myapp_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define add 1
extern  int * add_1();
extern  int * add_1_svc();
extern int myapp_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_numbers (XDR *, numbers*);

#else /* K&R C */
extern bool_t xdr_numbers ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPC_ADD_H_RPCGEN */
