#ifndef INC__U_TYPE_STRING_HPP__
#define INC__U_TYPE_STRING_HPP__


#include "u_type_array.hpp"


namespace utl
{


/*!
 * \brief	The class wraps a const char within enum internally.
 */
template< wchar_t c >
struct u_ch
{
	enum { m_ch = c };
};


/*!
 * \brief	The class creates a regular string.
 *
 * A regular string is a string that has no u_ch<(wchar_t)0> inside and removes
 * the no type element (u_tarr_no_type__).
 */
template< class S >
struct u_regular_str
{
private:
	typedef typename S::string_t array_t;
	typedef typename u_tarr_push
	<
		array_t,
		u_ch< (wchar_t)0 >,
		u_tarr_length< array_t >::m_length
	>::array_t str_reg_arr_t;

	enum {m_end = u_tarr_index_of< str_reg_arr_t, u_ch< (wchar_t)0 > >::m_index};

public:
	typedef typename u_tarr_sub_arr< str_reg_arr_t, 0, m_end >::array_t string_t;
};



/*!
 * \brief	The class define a type array.
 */
template
<
	wchar_t c00 = (wchar_t)0,
	wchar_t c01 = (wchar_t)0,
	wchar_t c02 = (wchar_t)0,
	wchar_t c03 = (wchar_t)0,
	wchar_t c04 = (wchar_t)0,
	wchar_t c05 = (wchar_t)0,
	wchar_t c06 = (wchar_t)0,
	wchar_t c07 = (wchar_t)0,
	wchar_t c08 = (wchar_t)0,
	wchar_t c09 = (wchar_t)0,
	wchar_t c0A = (wchar_t)0,
	wchar_t c0B = (wchar_t)0,
	wchar_t c0C = (wchar_t)0,
	wchar_t c0D = (wchar_t)0,
	wchar_t c0E = (wchar_t)0,
	wchar_t c0F = (wchar_t)0/*,
	wchar_t c10 = (wchar_t)0,
	wchar_t c11 = (wchar_t)0,
	wchar_t c12 = (wchar_t)0,
	wchar_t c13 = (wchar_t)0,
	wchar_t c14 = (wchar_t)0,
	wchar_t c15 = (wchar_t)0,
	wchar_t c16 = (wchar_t)0,
	wchar_t c17 = (wchar_t)0,
	wchar_t c18 = (wchar_t)0,
	wchar_t c19 = (wchar_t)0,
	wchar_t c1A = (wchar_t)0,
	wchar_t c1B = (wchar_t)0,
	wchar_t c1C = (wchar_t)0,
	wchar_t c1D = (wchar_t)0,
	wchar_t c1E = (wchar_t)0,
	wchar_t c1F = (wchar_t)0,
	wchar_t c20 = (wchar_t)0,
	wchar_t c21 = (wchar_t)0,
	wchar_t c22 = (wchar_t)0,
	wchar_t c23 = (wchar_t)0,
	wchar_t c24 = (wchar_t)0,
	wchar_t c25 = (wchar_t)0,
	wchar_t c26 = (wchar_t)0,
	wchar_t c27 = (wchar_t)0,
	wchar_t c28 = (wchar_t)0,
	wchar_t c29 = (wchar_t)0,
	wchar_t c2A = (wchar_t)0,
	wchar_t c2B = (wchar_t)0,
	wchar_t c2C = (wchar_t)0,
	wchar_t c2D = (wchar_t)0,
	wchar_t c2E = (wchar_t)0,
	wchar_t c2F = (wchar_t)0,
	wchar_t c30 = (wchar_t)0,
	wchar_t c31 = (wchar_t)0,
	wchar_t c32 = (wchar_t)0,
	wchar_t c33 = (wchar_t)0,
	wchar_t c34 = (wchar_t)0,
	wchar_t c35 = (wchar_t)0,
	wchar_t c36 = (wchar_t)0,
	wchar_t c37 = (wchar_t)0,
	wchar_t c38 = (wchar_t)0,
	wchar_t c39 = (wchar_t)0,
	wchar_t c3A = (wchar_t)0,
	wchar_t c3B = (wchar_t)0,
	wchar_t c3C = (wchar_t)0,
	wchar_t c3D = (wchar_t)0,
	wchar_t c3E = (wchar_t)0,
	wchar_t c3F = (wchar_t)0*/
>
struct u_str
{
private:
	struct str__
	{
		typedef typename u_tarr
		<
			u_ch< c00 >,
			u_ch< c01 >,
			u_ch< c02 >,
			u_ch< c03 >,
			u_ch< c04 >,
			u_ch< c05 >,
			u_ch< c06 >,
			u_ch< c07 >,
			u_ch< c08 >,
			u_ch< c09 >,
			u_ch< c0A >,
			u_ch< c0B >,
			u_ch< c0C >,
			u_ch< c0D >,
			u_ch< c0E >,
			u_ch< c0F >/*,
			u_ch< c10 >,
			u_ch< c11 >,
			u_ch< c12 >,
			u_ch< c13 >,
			u_ch< c14 >,
			u_ch< c15 >,
			u_ch< c16 >,
			u_ch< c17 >,
			u_ch< c18 >,
			u_ch< c19 >,
			u_ch< c1A >,
			u_ch< c1B >,
			u_ch< c1C >,
			u_ch< c1D >,
			u_ch< c1E >,
			u_ch< c1F >,
			u_ch< c20 >,
			u_ch< c21 >,
			u_ch< c22 >,
			u_ch< c23 >,
			u_ch< c24 >,
			u_ch< c25 >,
			u_ch< c26 >,
			u_ch< c27 >,
			u_ch< c28 >,
			u_ch< c29 >,
			u_ch< c2A >,
			u_ch< c2B >,
			u_ch< c2C >,
			u_ch< c2D >,
			u_ch< c2E >,
			u_ch< c2F >,
			u_ch< c30 >,
			u_ch< c31 >,
			u_ch< c32 >,
			u_ch< c33 >,
			u_ch< c34 >,
			u_ch< c35 >,
			u_ch< c36 >,
			u_ch< c37 >,
			u_ch< c38 >,
			u_ch< c39 >,
			u_ch< c3A >,
			u_ch< c3B >,
			u_ch< c3C >,
			u_ch< c3D >,
			u_ch< c3E >,
			u_ch< c3F >*/
		>::array_t string_t;
	};
public:
	typedef typename u_regular_str< str__ >::string_t string_t;
};



/*!
 * \brief	Concat two strings.
 */
template< class S1, class S2 >
struct u_strcat
{
private:
	typedef typename S1::string_t array1_t;
	typedef typename S2::string_t array2_t;

	template< class T >
	struct u_str__
	{
		typedef T string_t;
	};
	typedef u_str__
	<
		typename u_tarr_push< array2_t, array1_t >::array_t
	> str_pair_t;

public:
	typedef typename u_regular_str< str_pair_t >::string_t string_t;
};


/*!
 * \brief	Get the length of string represented by m_length.
 */
template< class S >
struct u_strlen
{
private:
	typedef typename S::string_t array_t;
public:
	enum{ m_length = u_tarr_length< array_t >::m_length };
};

template< class S, unsigned int begin, unsigned int end = (unsigned int)-1 >
struct u_substr
{
private:
	typedef typename S::string_t array_t;
	template< class T >
	struct u_str__
	{
		typedef T string_t;
	};
	typedef u_str__< typename u_tarr_sub_arr< array_t, begin, end >::array_t > str_sub_t;
public:
	typedef typename u_regular_str< str_sub_t >::string_t string_t;
};


/*!
 * \brief	Get the char represented by m_ch at specified position.
 *
 * If position is out of the range, m_ch is (w_char)0
 */
template< class S, unsigned int position >
struct u_get_char_at
{
private:

	template< class >
	struct found__
	{
		typedef typename S::string_t array_t;
		typedef typename u_tarr_fix_type< position, array_t >::type_t converted_t;	
	};

	template< class >
	struct not_found__
	{
		typedef u_ch< (wchar_t)0 > converted_t;
	};

	typedef typename u_bool_template
	<
		S,
		found__,
		not_found__,
		( position< u_strlen< S >::m_length ? true : false )
	>::selected_t ch_t;
public:
	enum{ m_ch = ch_t::m_ch };
};


/*!
 * \brief	The class that contains the position of char represented by m_position.
 *
 * \param	S, the string.
 * \param	ch, the char to be searched in the string.
 * \return	If the char is found, m_position is the position, otherwise
 *          m_position is -1.
 */
template< class S, wchar_t ch >
struct u_strchr
{
private:
	typedef typename S::string_t array_t;
public:
	enum{ m_position = u_tarr_index_of< array_t, u_ch< ch > >::m_index };
};


/*!
 * \brief	The class that contains the last position of char represented by m_position.
 *
 * \param	S, the string.
 * \param	ch, the char to be searched in the string.
 * \return	If the char is found, m_position is the last position, otherwise
 *          m_position is -1.
 */
template< class S, wchar_t ch >
struct u_strrchr
{
private:
	typedef typename S::string_t array_t;
public:
	enum{ m_position = u_tarr_last_index_of< array_t, u_ch< ch > >::m_index };
};


/*!
 * \brief	The class that contains the position of string represented by m_position.
 *
 * \param	S, the string.
 * \param	I, the string to be searched in the string S.
 * \return	If the char is found, m_position is the position, otherwise
 *          m_position is -1.
 */
template< class S, class I >
struct u_strstr
{
private:
	typedef typename S::string_t string_t;
	typedef typename I::string_t in_string_t;
public:
	enum{ m_position = u_tarr_index_of< string_t, in_string_t >::m_index };
};


/*!
 * \brief	The class that contains the last position of string represented by m_position.
 *
 * \param	S, the string.
 * \param	I, the string to be searched in the string S.
 * \return	If the char is found, m_position is the last position, otherwise
 *          m_position is -1.
 */
template< class S, class I >
struct u_strrstr
{
private:
	typedef typename S::string_t string_t;
	typedef typename I::string_t in_string_t;
public:
	enum{ m_position = u_tarr_last_index_of< string_t, in_string_t >::m_index };
};


/*!
 * \brief	The class compairs the two strings and stores the result to m_is_equal.
 *
 * \param	S1, the 1st string
 * \param	S2, the 2nd string
 * \return	m_is_equal returns true if S1 == S2, otherwise returns false.
 */
template< class S1, class S2 >
struct u_str_equal
{
private:
	typedef typename S1::string_t string1_t;
	typedef typename S2::string_t string2_t;
public:
	enum{ m_is_equal = u_same_class< string1_t, string2_t >::m_is_same };
};






template< class T, bool parent_const, class P, unsigned int position >
struct ptr_ch__
{
	inline static void filter_type( P &param )
	{
		printf( "%c - %d\n", T::m_ch, position );
		//printf( "%c", T::m_ch );
	}
};



template< typename S >
inline void prt_str( )
{
	typedef typename S::string_t string_t;

	u_tarr_for_each_range< ptr_ch__, string_t, const int, 0, u_strlen< S >::m_length >( 0 );
}


}
#endif


