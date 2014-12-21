#ifndef INC__PT_TEST_H__
#define INC__PT_TEST_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#ifdef __cplusplus
#	include <exception>
#	include <stdexcept>
#	define PT_CPP_BEGIN_CATCH try{

#	define PT_CPP_END_CATCH \
	} \
	catch( std::domain_error const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught domain_error: %s\n", error.what( ) ); \
	} \
	catch( std::invalid_argument const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught invalid_argument: %s\n", error.what( ) ); \
	} \
	catch( std::length_error const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught length_error: %s\n", error.what( ) ); \
	} \
	catch( std::out_of_range const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught out_of_range: %s\n", error.what( ) ); \
	} \
	catch( std::logic_error const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught logic_error: %s\n", error.what( ) ); \
	} \
	catch( std::overflow_error const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught overflow_error: %s\n", error.what( ) ); \
	} \
	catch( std::range_error const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught range_error: %s\n", error.what( ) ); \
	} \
	catch( std::underflow_error const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught underflow_error: %s\n", error.what( ) ); \
	} \
	catch( std::runtime_error const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught runtime_error: %s\n", error.what( ) ); \
	} \
	catch( std::exception const &error ) \
	{ \
		fprintf( stderr, "[u:error] Caught exception: %s\n", error.what( ) ); \
	}

#else
#	define PT_CPP_BEGIN_CATCH do{ } while( 0 )
#	define PT_CPP_END_CATCH do{ } while( 0 )
#endif


/* Assert and quit application if failed. */
#define PT_TEST(expr) \
	do { \
		PT_CPP_BEGIN_CATCH; \
		if( (expr) ) \
		{ \
		} \
		else \
		{ \
			fprintf( stderr, "[u:error] Test %s\n-> File: %s, line: %d\n", #expr, __FILE__, __LINE__ ); \
			exit( 1 ); \
		} \
		PT_CPP_END_CATCH; \
	} \
	while( 0 )



/* Assert and continue the application. */
#define PT_TEST_GO(expr) \
	do { \
		PT_CPP_BEGIN_CATCH; \
		if( (expr) ) \
		{ \
		} \
		else \
		{ \
			fprintf( stderr, "[u:error] Test %s\n-> File: %s, line: %d\n", #expr, __FILE__, __LINE__ ); \
		} \
		PT_CPP_END_CATCH; \
	} \
	while( 0 )



/* Trace running */
#define PTT do { printf ("[u:run]: %s %s(%d)\n", __func__, __FILE__, __LINE__); } while( 0 )



/* Report not implement. */
#ifdef NDEBUG
#	define PT_NO_IMP do{ ; } while( 0 );
#else
#	define PT_NO_IMP do \
{ \
	const char *func = __func__; \
    assert( ( func, false ) ); \
    throw std::runtime_error( func ); \
} while( 0 )
#endif



#endif

