
#ifndef ESQLC_H
#define ESQLC_H

#include <stdint.h>
#include <string>
#include <map>
#include <sqlda.h>


class esqlc {
public:

	static int32_t connect( const char * connid, const char * database, const char * username = 0, const char * password = 0 );
	static int32_t prepare( const char * stmtid, const char * stmtstr, ifx_sqlda_t * &insqlda, ifx_sqlda_t * &outsqlda );
	static int32_t exec( const char * stmtid, ifx_sqlda_t * insqlda, int32_t * serial );
	static int32_t exec( const char * stmtid, const char * curid, ifx_sqlda_t * insqlda );
	static int32_t fetch( const char * curid, ifx_sqlda_t * outsqlda );
	static int32_t close( const char * curid );
	static int32_t free( const char * stmtid );
	static int32_t disconnect( const char * connid );

	static int32_t acquire( const char * connid );
	static int32_t release( const char * connid );

	static std::string errmsg( int32_t code );
	static const char * sqlstate();

};

#endif /* !ESQLC_H */

