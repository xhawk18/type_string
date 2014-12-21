#ifndef INC__U_SAME_CLASS_HPP__
#define INC__U_SAME_CLASS_HPP__
namespace utl
{


/*!
 * \brief	The class decides if the two class is the same.
 *
 * u_same_class< T1, T2 >::m_is_same is true if T1 and T2 are the same classes,
 * u_same_class< T1, T2 >::m_is_same is false if T1 and T2 are defferent classes
 */
template< class T1, class T2 >
struct u_same_class
{
	enum { m_is_same = false };
};

template< class T >
struct u_same_class< T, T >
{
	enum { m_is_same = true };
};




}
#endif
