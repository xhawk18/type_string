#ifndef INC__U_VARIABLE_TO_VALUE_HPP__
#define INC__U_VARIABLE_TO_VALUE_HPP__
namespace utl
{



/*!
 * \brief Convert the variable num to template const parameter
 *
 * If argument the range of num is "min_num <= num < max_num", the function
 * calls functor F< num,P >( param ). Usually you can not call F< num,P >( param )
 * directly because that num is not a const value but a variable.
 *
 * \param	min_num	Minimum number
 * \param	max_max Maximum number
 * \param	F		The callback object that should privide function "callback",
 *					which is to be called with parameter "param" and the value
 *					of number.
 * \param	P		The type of callback parameter for the callback template.
 * \param	num		The number to be converted to const value.
 * \param	param	The prameter used by callback object F.
 *
 * \return	true if "min_num <= num < max_num", otherwise false.
 */
#if 0
	
template
<
	unsigned int min_num,
	unsigned int max_num,
	template< unsigned int, class > class F,
	class P
>
inline bool u_convert_variable_to_value( unsigned int num, P &param )
{
#if 1
	if ( min_num >= max_num )
		return false;	/* No this type! */

	if ( num < min_num || num >= max_num )
		return false;	/* No this type! */
	
	if ( num == min_num )
	{
		typedef F< min_num, P > convertor_t;
		convertor_t::callback( param );
		return true;
	}

	if ( num < (min_num + max_num) / 2 )
		return u_convert_variable_to_value< min_num, ( min_num + max_num ) / 2, F, P >( num, param );
	else
		return u_convert_variable_to_value< ( min_num + max_num ) / 2, max_num, F, P >( num, param );
#else
	/* The effect of the following code is the same as the above, avoid warning in Intel C++. */
	if ( min_num >= max_num )
		return false;	/* No this type! */

	if ( ( min_num > 0 && num < min_num )
		|| !( max_num > 0 && num < max_num ) )
		return false;	/* No this type! */
	
	if ( num == min_num )
	{
		typedef F< min_num, P > convertor_t;
		convertor_t::callback( param );
		return true;
	}

	if ( ( min_num + max_num ) / 2 > 0 && num < ( min_num + max_num ) / 2 )
		return u_convert_variable_to_value< min_num, ( min_num + max_num ) / 2, F, P >( num, param );
	else
		return u_convert_variable_to_value< ( min_num + max_num ) / 2, max_num, F, P >( num, param );
#endif
}


#else


template
<
	unsigned int min_num,
	unsigned int index,
	template< unsigned int, class > class F,
	class P
>
struct u_cvv_caller__
{
	void (*m_callback)( P &param );
	static void callback( P &param )
	{
		typedef F< min_num + index, P > convertor_t;
		convertor_t::callback( param );
	}
	u_cvv_caller__( )
	:	m_callback( &u_cvv_caller__::callback )
	{
	}
};


template
<
	unsigned int min_num,
	unsigned int size,
	template< unsigned int, class > class F,
	class P
>
struct u_cvv_caller_array__
{
	std::pair
	<
		u_cvv_caller_array__< min_num, size - 1, F, P >,
		u_cvv_caller__< min_num, size - 1, F, P >
	> m_array;
};

template
<
	unsigned int min_num,
	template< unsigned int, class > class F,
	class P
>
struct u_cvv_caller_array__< min_num, 1, F, P >
{
	u_cvv_caller__< min_num, 0, F, P > m_array;
};


template
<
	unsigned int min_num,
	unsigned int max_num,
	template< unsigned int, class > class F,
	class P
>
inline bool u_convert_variable_to_value( unsigned int num, P &param )
{
	if ( num < min_num || num >= max_num )
		return false;

	static u_cvv_caller_array__< min_num, max_num - min_num, F, P > array;
	reinterpret_cast< u_cvv_caller__< min_num, 0, F, P > * >( &array )[ num - min_num ].m_callback( param );
	return true;
}


#endif



}
#endif
