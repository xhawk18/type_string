#ifndef INC__U_TARR_PUSH_HPP__
#define INC__U_TARR_PUSH_HPP__
namespace utl
{


/*!
 * \brief	Insert a type before the position represented by index..
 */
template< class T, class E, unsigned int index = 0 >
class u_tarr_push
{
public:
	typedef E element_t;
	typedef typename u_tarr_regular
	<
		std::pair
		<
			typename u_tarr_sub_arr <T, 0, index>::array_t,
			std::pair
			<
				E,
				typename u_tarr_sub_arr <T, index>::array_t
			>
		>
	>::array_t array_t;
};




}
#endif
