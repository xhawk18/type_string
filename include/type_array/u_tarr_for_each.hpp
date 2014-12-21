#ifndef INC__U_TARR_FOR_EACH_HPP__
#define INC__U_TARR_FOR_EACH_HPP__
namespace utl
{

template
<
	template
	<
		class, bool, class, unsigned int
	> class F,						/*!< The filter. */
	class T,						/*!< The types array. */
	class P							/*!< The parameter type for filter_type type. */
>
class u_tarr_for_each__
{
private:
	template< class T_, bool parent_const_, class P_, unsigned int index_ >
	struct filter_for_each__
	{
		typedef F< T_, parent_const_, P_, index_ > converted_t;
		enum{ m_selected = converted_t::m_selected };
		static void filter_type( P_ &param )
		{
			converted_t::filter_type( param );
		}

		static void filter_object( typename utl::u_const< T_, parent_const_ >::type_t &object, P_ &param )
		{
			converted_t::filter_object( object, param );
		}

	};

public:
	static void filter_type( P &param )
	{
		u_tarr_filter< filter_for_each__, T, P >::filter_type( param );
	}

	static void filter_object( T &object, P &param )
	{
		u_tarr_filter< filter_for_each__, T, P >::filter_object( object, param );
	}
};

/*!
 * \brief	Process each type in type array.
 *
 * If F< T, parent_const, P, position >::m_selected is true, u_tarr_for_each calls
 *   F< T, parent_const, P, position >::filter_type( param );
 */
template
<
	template
	<
		class, bool, class, unsigned int
	> class F,						/*!< The filter. */
	class T,						/*!< The types array. */
	class P							/*!< The parameter type for filter_type type. */
>
inline void u_tarr_for_each( P &param )
{
	u_tarr_for_each__< F, T, P >::filter_type( param );
}


template
<
	template
	<
		class, bool, class, unsigned int
	> class F,						/*!< The filter. */
	class T,						/*!< The types array. */
	class P							/*!< The parameter type for callback type. */
>
inline void u_tarr_for_each( T &object, P &param )
{
	u_tarr_for_each__< F, T, P >::filter_object( object, param );
}


template
<
	template< class, bool, class, unsigned int > class F,
	class T,
	class P,
	unsigned int begin,
	unsigned int end
>
struct u_tarr_for_each_range__
{
private:
	template< class TT__, bool parent_const_, class TP__, unsigned int position >
	struct range_filter__
	{
		inline static void filter_type( TP__ &param )
		{
			F< TT__, parent_const_, TP__, position >::filter_type( param );
		}
		inline static void filter_object( typename u_const< TT__, parent_const_ >::type_t &object, TP__ &param )
		{
			F< TT__, parent_const_, TP__, position >::filter_object( object, param );
		}
		typedef TT__ converted_t;
		enum{ m_selected = (position >= begin && position < end) };
	};
public:
	inline static void for_each( P &param )
	{
		u_tarr_for_each< range_filter__, T, P >( param );
	}

	inline static void for_each( T &object, P &param )
	{
		u_tarr_for_each< range_filter__, T, P >( object, param );
	}
};


/*!
 * \brief	Process each type in the range of type array.
 *
 * If the position of types is in the range [from, to), u_tarr_for_each_range calls
 *   F< T, parent_const, P, position >::filter_type( param );
 */
template
<
	template< class, bool, class, unsigned int > class F,
	class T,
	class P,
	unsigned int from,
	unsigned int to
>
inline void u_tarr_for_each_range( P &param )
{
	u_tarr_for_each_range__< F, T, P, from, to >::for_each( param );
}


/*!
 * \brief	Process each type in the range of type array.
 *
 * If the position of types is in the range [from, to), u_tarr_for_each_range calls
 *   F< T, parent_const, P, position >::filter_object( object, param );
 */
template
<
	template< class, bool, class, unsigned int > class F,
	class T,
	class P,
	unsigned int from,
	unsigned int to
>
inline void u_tarr_for_each_range( T &object, P &param )
{
	u_tarr_for_each_range__< F, T, P, from, to >::for_each( object, param );
}



}
#endif
