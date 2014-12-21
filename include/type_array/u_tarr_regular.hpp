#ifndef INC__U_TARR_REGULAR_HPP__
#define INC__U_TARR_REGULAR_HPP__
namespace utl
{




template< class T >
struct u_tarr_wrap_const
{
	typedef T array_t;
};

template< class T1, class T2 >
struct u_tarr_wrap_const< std::pair< T1, T2 > >
{
	typedef std::pair
	<
		typename u_tarr_wrap_const< T1 >::array_t,
		typename u_tarr_wrap_const< T2 >::array_t
	> array_t;
};

template< class T1, class T2 >
struct u_tarr_wrap_const< std::pair< T1, T2 > const >
{
	typedef std::pair
	<
		typename u_tarr_wrap_const< T1 const >::array_t,
		typename u_tarr_wrap_const< T2 const >::array_t
	> array_t;
};




template< class T >
struct u_tarr_remove_no_type
{
	typedef T array_t;
};



template< class T1__, class T2__ >
struct u_tarr_remove_no_type__;


template< class T1, class T2 >
struct u_tarr_remove_no_type< std::pair< T1, T2 > >
{
private:
	typedef typename u_tarr_remove_no_type< T1 >::array_t array1_t;
	typedef typename u_tarr_remove_no_type< T2 >::array_t array2_t;

public:
	typedef typename u_tarr_remove_no_type__< array1_t, array2_t >::array_t array_t;
};


template< class T1__, class T2__ >
struct u_tarr_remove_no_type__
{
	typedef std::pair< T1__, T2__ > array_t;
};

template< class T__ >
struct u_tarr_remove_no_type__< T__, u_void >
{
	typedef typename u_tarr_remove_no_type< T__ >::array_t array_t;
};
template< class T__ >
struct u_tarr_remove_no_type__< T__, u_void const >
{
	typedef typename u_tarr_remove_no_type< T__ >::array_t array_t;
};

template< class T__ >
struct u_tarr_remove_no_type__< u_void, T__ >
{
	typedef typename u_tarr_remove_no_type< T__ >::array_t array_t;
};
template< class T__ >
struct u_tarr_remove_no_type__< u_void const, T__ >
{
	typedef typename u_tarr_remove_no_type< T__ >::array_t array_t;
};

template< >
struct u_tarr_remove_no_type__< u_void, u_void >
{
	typedef u_void array_t;
};
template< >
struct u_tarr_remove_no_type__< u_void const, u_void >
{
	typedef u_void const array_t;
};
template< >
struct u_tarr_remove_no_type__< u_void, u_void const >
{
	typedef u_void const array_t;
};
template< >
struct u_tarr_remove_no_type__< u_void const, u_void const >
{
	typedef u_void const array_t;
};



template< class T >
struct u_tarr_sort_in_pair
{
	typedef T array_t;
};

template< class L, class M, class R >
struct u_tarr_sort_in_pair< std::pair< std::pair< L, M >, R > >
{
private:
	typedef typename u_tarr_sort_in_pair< std::pair< M, R > >::array_t right_t;
public:
	typedef typename u_tarr_sort_in_pair< std::pair< L, right_t > >::array_t array_t;
};

template< class L, class M, class R >
struct u_tarr_sort_in_pair< std::pair< L, std::pair< M, R > > >
{
private:
	typedef typename u_tarr_sort_in_pair< std::pair< M, R > >::array_t right_t;
public:
	typedef typename std::pair< L, right_t >  array_t;
};

template< class L1, class L2, class R1, class R2 >
struct u_tarr_sort_in_pair< std::pair< std::pair< L1, L2 >, std::pair< R1, R2 > > >
{
private:
	typedef typename u_tarr_sort_in_pair< std::pair< R1, R2 > >::array_t right_t;
public:
	typedef typename u_tarr_sort_in_pair< std::pair< L2, right_t > >::array_t to_right_t;
	typedef typename u_tarr_sort_in_pair< std::pair< L1, to_right_t > >::array_t array_t;
};



/*!
 * \brief	The class is used to remove the u_void in a type array.
 *
 * u_tarr_regular< T >::array_t contains the types array that has no u_void
 * if one or more types in the types array, otherwise it contains only one u_void.
 * u_tarr_regular< T >::array_t has sorted std::pair inside.
 * u_tarr_regular< T >::array_t binds const onto types inside std::pair if the original 
 * std::pair have const modifiers.
 */
template< class T >
struct u_tarr_regular
{
private:
	typedef typename u_tarr_wrap_const< T >::array_t				wrap_const_t;
	typedef typename u_tarr_remove_no_type< wrap_const_t >::array_t	remove_notype_t;
public:
	typedef typename u_tarr_sort_in_pair <remove_notype_t>::array_t	array_t;
};





}
#endif
