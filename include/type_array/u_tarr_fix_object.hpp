#ifndef INC__U_TARR_FIX_OBJECT_HPP__
#define INC__U_TARR_FIX_OBJECT_HPP__
namespace utl
{



#if 0
template
<
	unsigned int index,
	class T
>
struct u_tarr_fix_type_select__
{
	template< class T__, bool parent_const, class P__, unsigned int index__ >
	struct filter__
	{
		template< class >
		struct selected__
		{
			struct converted_t
			{
				inline static void filter_object( typename u_const< T__, parent_const >::type_t &object, P__ &param )
				{
					param = &object;
				}
			};
		};
		template< class >
		struct not_selected__
		{
			struct converted_t
			{
				inline static void filter_object( typename u_const< T__, parent_const >::type_t &object, P &param )
				{
				}
			};
		};

		enum{ m_selected = ( index == index__ ? true : false ) };
		typedef typename u_bool_template
		<
			std::pair< T__, P__ >,
			selected__,
			not_selected__,
			m_selected
		>::selected_t converted_t;

		inline static void filter_object( typename u_const< T__, parent_const >::type_t &object, P__ &param )
		{
			converted_t::filter_object( object, param );
		}
	};

	static inline bool call_object( T &objects, typename u_tarr_fix_type< index, T >::element_t *&object )
	{
		if (index >= 0 && index < u_tarr_length< T >::m_length )
		{
			u_tarr_filter
			<
				filter__,
				T,
				typename u_tarr_fix_type< index, T >::element_t *
			>::filter_object( objects, object );
			return true;
		}
		else
			return false;
	}
};




/*!
 * \brief	The class get the reference of object at fixed position in type array.
 */
template< unsigned int index, class T >
inline typename u_tarr_fix_type< index, T >::element_t &u_tarr_fix_object( T &objects )
{
	typename u_tarr_fix_type< index, T >::element_t *object = NULL;
	u_tarr_fix_type_select__< index, T >::call_object( objects, object );
	assert( object != NULL );
	return *object;
}


#else




/*!
 * \brief	The class that contains the count of types in type array..
 */
template< unsigned int index, class T >
struct u_tarr_fix_type_offset__
{
	enum
	{
		m_length = 1	/*!< Count of types.*/
	};
	enum{ m_offset = 0 };
};

template< unsigned int index >
struct u_tarr_fix_type_offset__< index, u_void >
{
	enum{ m_length = 0 };
	enum{ m_offset = 0 };
};

template< unsigned int index >
struct u_tarr_fix_type_offset__< index, u_void const >
{
	enum{ m_length = 0 };
	enum{ m_offset = 0 };
};


template< unsigned int index, class T1, class T2 >
struct u_tarr_fix_type_offset__< index, std::pair< T1, T2 > >
{
	enum
	{
		m_length
			= u_tarr_fix_type_offset__< index, T1 >::m_length
			+ u_tarr_fix_type_offset__< index - u_tarr_fix_type_offset__< index, T1 >::m_length, T2 >::m_length
	};
	enum
	{
		/*
		 * If the indexed object is on the right branch on the std::pair,
		 * it is required to calculate the offset of the right branch.
		 * We are sure that in any case, with or without alignment, the acture size that T2 occupied in 
		 * std::pair< T1, T2 > is:
		 *	AS = sizeof( std::pair< T1, T2 >, T2 > ) - sizeof( std::pair< T1, T2 > )
		 * So the offset of T2 is:
		 *	sizeof( std::pair< T1, T2 > ) - AS
		 * = sizeof( std::pair< T1, T2 > ) * 2 - sizeof( std::pair< T1, T2 >, T2 > )
		 */
		m_offset
			= index < u_tarr_fix_type_offset__< index, T1 >::m_length
			? u_tarr_fix_type_offset__< index, T1 >::m_offset
			: sizeof( std::pair< T1, T2 > ) * 2 - sizeof( std::pair< std::pair< T1, T2 >, T2 > )
			+ u_tarr_fix_type_offset__< index - u_tarr_fix_type_offset__< index, T1 >::m_length, T2 >::m_offset
	};
};


template< unsigned int index, class T1, class T2 >
struct u_tarr_fix_type_offset__< index, std::pair< T1, T2 > const >
{
	enum
	{
		m_length
			= u_tarr_fix_type_offset__< index, T1 const >::m_length
			+ u_tarr_fix_type_offset__< index - u_tarr_fix_type_offset__< index, T1 const >::m_length, T2 const >::m_length
	};
	enum
	{
		m_offset
			= index < u_tarr_fix_type_offset__< index, T1 const >::m_length
			? u_tarr_fix_type_offset__< index, T1 const >::m_offset
			: sizeof( std::pair< T1 const, T2 const > ) * 2 - sizeof( std::pair< std::pair< T1 const, T2 const >, T2 const > )
			+ u_tarr_fix_type_offset__< index - u_tarr_fix_type_offset__< index, T1 const >::m_length, T2 const >::m_offset
	};

};


/*!
 * \brief	The class get the reference of object at fixed position in type array.
 */
template< unsigned int index, class T >
inline typename u_tarr_fix_type< index, T >::element_t &u_tarr_fix_object( T &objects )
{
	return reinterpret_cast< typename u_tarr_fix_type< index, T >::element_t & >
	(
		*const_cast< char * >
		(
			&reinterpret_cast< char const & >( objects ) 
			+ u_tarr_fix_type_offset__< index, T >::m_offset
		)
	);
}

#endif

}
#endif
