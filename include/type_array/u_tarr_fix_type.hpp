#ifndef INC__U_TARR_FIX_TYPE_HPP__
#define INC__U_TARR_FIX_TYPE_HPP__
namespace utl
{






/*!
 * \brief	The class that contains the very type indexed by index in type array..
 */
template< unsigned int index, class T >
struct u_tarr_fix_type
{
private:
	template< class ERR_T, bool is_valid_index >
	struct index_check_t;

	template< class ERR_T >
	struct index_check_t< ERR_T, true >
	{
		enum{ ERR = 0 };
	};

	template< class ERR_T >
	struct index_check_t< ERR_T, false >
	{
		enum{ ERR = 1 };
		//Force the compiler to produce a error message.
		typename ERR_T::Please_check_if_the_index_is_out_of_the_range_of_type_array no_this_type;
	};

	enum{ ERR = index_check_t< int, ( index < u_tarr_length< T >::m_length ? true : false ) >::ERR };


	template< class T_, bool parent_const, class P_, unsigned int position >
	struct filter__
	{
		struct converted_t
		{
			typedef T_ type_t;
			enum { m_parent_const = parent_const };
		};

		enum{ m_selected = ( position == index ? true : false ) };
	};

	typedef typename u_tarr_filter< filter__, T >::array_t array_t;
public:
	enum { m_parent_const = array_t::m_parent_const };

	/*! type_t is the type in the fixed position in type array. */
	typedef typename array_t::type_t							type_t;
	/*! element_t is the type with const modifer that maybe comes from parent structures .*/
	typedef typename u_const< type_t, m_parent_const >::type_t	element_t;
};



}
#endif
