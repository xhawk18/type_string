#ifndef INC__U_TARR_FILTER_HPP__
#define INC__U_TARR_FILTER_HPP__
namespace utl
{



template
<
	template< class, bool, class, unsigned int > class F,
	class T,
	bool parent_const,
	unsigned int in_index,
	class P
>
struct u_tarr_filter__
{
private:
	template< class >
	struct selected__
	{
		struct converted_t
		{
			typedef F< T, parent_const, P, in_index >	filter_t;
			typedef filter_t							fun_t;
			typedef typename filter_t::converted_t		new_type_t;
		};
	};
	template< class >
	struct not_selected__
	{
		struct converted_t
		{
			struct fun_t
			{
				inline static void filter_type( P &param )
				{
				}
				inline static void filter_object( typename u_const< T, parent_const >::type_t &object, P &param )
				{
				}
				inline static u_void filter_array( typename u_const< T, parent_const >::type_t &object, P &param )
				{
					return u_void( );
				}
			};
			typedef u_void	new_type_t;
		};
	};

	typedef typename u_bool_template
	<
		u_void,
		selected__,
		not_selected__,
		F<T, parent_const, P, in_index>::m_selected
	>::selected_t filter_t;

public:
	typedef typename filter_t::new_type_t	array_t;
	typedef typename filter_t::fun_t		fun_t;

	inline static void filter_type( P &param )
	{
		fun_t::filter_type( param );
	}

	inline static void filter_object( typename u_const< T, parent_const >::type_t &object, P &param )
	{
		fun_t::filter_object( object, param );
	}

	inline static array_t filter_array( typename u_const< T, parent_const >::type_t &object, P &param )
	{
		return fun_t::filter_array( object, param );
	}

};



template
<
	template< class, bool, class, unsigned int > class F,
	bool parent_const,
	unsigned int in_index,
	class P
>
struct u_tarr_filter__< F, u_void, parent_const, in_index, P >
{
	typedef u_void array_t;
	inline static void filter_type( P &param )
	{
	}
	inline static void filter_object( typename u_const< u_void, parent_const >::type_t &object, P &param )
	{
	}
	inline static array_t filter_array( typename u_const< u_void, parent_const >::type_t &object, P &param )
	{
		return object;
	}
};


template
<
	template< class, bool, class, unsigned int > class F,
	bool parent_const,
	unsigned int in_index,
	class P
>
struct u_tarr_filter__< F, u_void const, parent_const, in_index, P >
{
	typedef u_void const array_t;
	inline static void filter_type( P &param )
	{
	}
	inline static void filter_object( u_void const &object, P &param )
	{
	}
	inline static array_t filter_array( u_void const &object, P &param )
	{
		return object;
	}

};


template
<
	template< class, bool, class, unsigned int > class F,
	class T1,
	class T2,
	bool parent_const,
	unsigned int in_index,
	class P
>
struct u_tarr_filter__< F, std::pair< T1, T2 >, parent_const, in_index, P >
{
private:
	typedef u_tarr_filter__
	<
		F,
		T1,
		parent_const,
		in_index,
		P
	> filter1_t;
	typedef typename filter1_t::array_t result1_t;

	typedef u_tarr_filter__
	<
		F,
		T2,
		parent_const,
		in_index + u_tarr_length <T1>::m_length,
		P
	> filter2_t;
	typedef typename filter2_t::array_t result2_t;
public:
	typedef std::pair< result1_t, result2_t > array_t;
	inline static void filter_type( P &param )
	{
		filter1_t::filter_type( param );
		filter2_t::filter_type( param );
	}

	inline static void filter_object( typename u_const< std::pair <T1, T2>, parent_const >::type_t &object, P &param )
	{
		filter1_t::filter_object( object.first, param );
		filter2_t::filter_object( object.second, param );
	}

	inline static array_t filter_array( typename u_const< std::pair <T1, T2>, parent_const >::type_t &object, P &param )
	{
		return std::pair< result1_t, result2_t >
		(
			filter1_t::filter_array( object.first, param ),
			filter2_t::filter_array( object.second, param )
		);
	}
};


template
<
	template< class, bool, class, unsigned int > class F,
	class T1,
	class T2,
	bool parent_const,
	unsigned int in_index,
	class P
>
struct u_tarr_filter__< F, std::pair< T1, T2 > const, parent_const, in_index, P >
{
private:
	typedef u_tarr_filter__
	<
		F,
		T1,
		true,
		in_index,
		P
	> filter1_t;
	typedef typename filter1_t::array_t result1_t;

	typedef u_tarr_filter__
	<
		F,
		T2,
		true,
		in_index + u_tarr_length <T1>::m_length,
		P
	> filter2_t;
	typedef typename filter2_t::array_t result2_t;
public:
	typedef std::pair< result1_t, result2_t > const array_t;
	inline static void filter_type( P &param )
	{
		filter1_t::filter_type( param );
		filter2_t::filter_type( param );
	}

	inline static void filter_object( std::pair< T1, T2 > const &object, P &param )
	{
		filter1_t::filter_object( object.first, param );
		filter2_t::filter_object( object.second, param );
	}

	inline static array_t filter_array( std::pair< T1, T2 > const &object, P &param )
	{
		return std::pair< result1_t, result2_t >
		(
			filter1_t::filter_array( object.first, param ),
			filter2_t::filter_array( object.second, param )
		);
	}
};


/*!
 * \brief	Check each the type in the type array.
 *
 * If F<T, parent_const, P, position>::m_selected is true, u_tarr_filter put
 * the F<T, parent_const, P, position>::converted_t into the result type array. The result type array is
 * u_tarr_filter<T, F, P>::array_t
 */
template
<
	template< class, bool, class, unsigned int > class F,	/*!< The filter. */
	class T,												/*!< The types array. */
	class P = u_void										/*!< The parameter type used by filter function. */
>
struct u_tarr_filter
{
private:
	typedef u_tarr_filter__< F, T, false, 0, P >	filter_t;
public:
	typedef typename u_tarr_regular
	<
		typename filter_t::array_t
	>::array_t	array_t;

	inline static void filter_type( P &param )
	{
		filter_t::filter_type( param );
	}

	inline static void filter_object( T &object, P &param )
	{
		filter_t::filter_object( object, param );
	}

	inline static array_t filter_array( T &object, P &param )
	{
		return filter_t::filter_array( object, param );
	}
};


}
#endif
