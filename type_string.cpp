#include <cstdio>
#include <cstring>
#include <typeinfo>
#include "include/pt_test.h"
#include "include/u_type_string.hpp"



int main( int argc, char **argv )
{
	/* Define a string */
	typedef utl::u_str< 'a', 'b', 'c', 'd', 'a', 'b' >	str;

	/* Test u_strcat */
	typedef utl::u_strcat< str, utl::u_str< '1', '2' > >	str_strcat0;
	typedef utl::u_str< 'a', 'b', 'c', 'd', 'a', 'b', '1', '2' >	str_strcat1;
	PT_TEST( ( strcmp( typeid( str_strcat0::string_t ).name( ), typeid( str_strcat1::string_t ).name( ) ) == 0 ) );

	/* Test u_strlen */
	PT_TEST( utl::u_strlen< str >::m_length == 6 );

	/* Test u_get_char_at */
	PT_TEST( ( utl::u_get_char_at< str, 0 >::m_ch == 'a' ) );
	PT_TEST( ( utl::u_get_char_at< str, 1 >::m_ch == 'b' ) );
	PT_TEST( ( utl::u_get_char_at< str, 2 >::m_ch == 'c' ) );
	PT_TEST( ( utl::u_get_char_at< str, 3 >::m_ch == 'd' ) );
	PT_TEST( ( utl::u_get_char_at< str, 4 >::m_ch == 'a' ) );
	PT_TEST( ( utl::u_get_char_at< str, 5 >::m_ch == 'b' ) );

	/* Test u_strchr */
	PT_TEST( ( utl::u_strchr< str, 'a' >::m_position == 0 ) );
	PT_TEST( ( utl::u_strchr< str, 'b' >::m_position == 1 ) );
	PT_TEST( ( utl::u_strchr< str, 'c' >::m_position == 2 ) );
	PT_TEST( ( utl::u_strchr< str, 'd' >::m_position == 3 ) );
	PT_TEST( ( utl::u_strchr< str, '1' >::m_position == -1 ) );

	/* Test u_strrchr */
	PT_TEST( ( utl::u_strrchr< str, 'a' >::m_position == 4 ) );
	PT_TEST( ( utl::u_strrchr< str, 'b' >::m_position == 5 ) );
	PT_TEST( ( utl::u_strrchr< str, 'c' >::m_position == 2 ) );
	PT_TEST( ( utl::u_strrchr< str, 'd' >::m_position == 3 ) );
	PT_TEST( ( utl::u_strrchr< str, '1' >::m_position == -1 ) );

	/* Test u_strstr */
	PT_TEST( ( utl::u_strstr< str, utl::u_str< 'a', 'b' > >::m_position == 0 ) );
	PT_TEST( ( utl::u_strstr< str, utl::u_str< 'a', 'b', 'c' > >::m_position == 0 ) );
	PT_TEST( ( utl::u_strstr< str, utl::u_str< 'b', 'c' > >::m_position == 1 ) );
	PT_TEST( ( utl::u_strstr< str, utl::u_str< 'b', '1' > >::m_position == -1 ) );

	/* Test u_strrstr */
	PT_TEST( ( utl::u_strrstr< str, utl::u_str< 'a', 'b' > >::m_position == 4 ) );
	PT_TEST( ( utl::u_strrstr< str, utl::u_str< 'a', 'b', 'c' > >::m_position == 0 ) );
	PT_TEST( ( utl::u_strrstr< str, utl::u_str< 'b', 'c' > >::m_position == 1 ) );
	PT_TEST( ( utl::u_strrstr< str, utl::u_str< 'b', '1' > >::m_position == -1 ) );

	/* Test u_str_equal */
	PT_TEST( ( utl::u_str_equal< str, utl::u_str< 'a', 'b' > >::m_is_equal == false ) );
	PT_TEST( ( utl::u_str_equal< str, str >::m_is_equal != false ) );

	/* Printf str */
	utl::prt_str< str >( );

	return 0;
}



