#ifndef INC__U_CONST_HPP__
#define INC__U_CONST_HPP__
namespace utl
{


/*!
 * \brief	Const modifier.
 */
template< class T, bool parent_const >
struct u_const
{
	typedef T type_t;
};

template< class T >
struct u_const< T, true >
{
	typedef T const type_t;
};

template< class T >
struct u_const< T const, true >
{
	typedef T const type_t;
};

template< class T >
struct u_const< T const, false >
{
	typedef T const type_t;
};


template< class T >
struct u_is_const
{
	typedef T no_const_type_t;
	enum { m_is_const = false };
};

template< class T >
struct u_is_const< const T >
{
	typedef T no_const_type_t;
	enum { m_is_const = true };
};


};
#endif
