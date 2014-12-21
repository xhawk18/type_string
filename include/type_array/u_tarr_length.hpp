#ifndef INC__U_TARR_LENGTH_HPP__
#define INC__U_TARR_LENGTH_HPP__
namespace utl
{


/*!
 * \brief	The class that contains the count of types in type array..
 */
template< class T >
struct u_tarr_length
{
	enum
	{
		m_length = 1	/*!< Count of types.*/
	};
};

template< >
struct u_tarr_length< u_void >
{
	enum {m_length = 0};
};

template< >
struct u_tarr_length< u_void const >
{
	enum {m_length = 0};
};


template< class T1, class T2 >
struct u_tarr_length< std::pair< T1, T2 > >
{
	enum{ m_length = u_tarr_length< T1 >::m_length + u_tarr_length< T2 >::m_length };
};


template< class T1, class T2 >
struct u_tarr_length< std::pair< T1, T2 > const >
{
	enum{ m_length = u_tarr_length< T1 const >::m_length + u_tarr_length< T2 const >::m_length };
};


}
#endif
