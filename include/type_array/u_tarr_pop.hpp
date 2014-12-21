#ifndef INC__U_TARR_POP_HPP__
#define INC__U_TARR_POP_HPP__
namespace utl
{

/*!
 * \brief	Pos a type at the position represented by index.
 */
template< class T, unsigned int index = 0 >
class u_tarr_pop
{
	typedef u_tarr_fix_type< index, T > fix_t;
public:
	enum { m_parent_const = fix_t::m_parent_const };
	typedef typename fix_t::type_t		type_t;
	typedef typename fix_t::element_t	element_t;
	typedef typename u_tarr_regular
	<
		std::pair
		<
			typename u_tarr_sub_arr< T, 0, index >::array_t,
			typename u_tarr_sub_arr< T, index + 1 >::array_t
		>
	>::array_t array_t;
};






}
#endif
