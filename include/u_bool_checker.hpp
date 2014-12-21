#ifndef INC__U_BOOL_CHECKER_HPP__
#define INC__U_BOOL_CHECKER_HPP__
namespace utl
{


/*!
 * \brief	The class decides to define true type ( T< E >::converted_t )
 *          or false type ( T< F >::converted_t ).
 *
 * u_bool_checker< T, F, true >::selected_t is T< E >::converted_t
 * u_bool_checker< T, F, false >::selected_t is F< E >::converted_t
 */
template
<
	class E,
	template< class > class T,
	template< class > class F,
	bool is_true
>
struct u_bool_template;

template
<
	class E,
	template< class > class T,
	template< class > class F
>
struct u_bool_template< E, T, F, true > 
{
	typedef typename T< E >::converted_t selected_t;
};

template
<
	class E,
	template< class > class T,
	template< class > class F
>
struct u_bool_template< E, T, F, false > 
{
	typedef typename F< E >::converted_t selected_t;
};



/*!
 * \brief	The class decides to define true type ( T ) or false type ( F ).
 *
 * u_bool_checker< T, F, true >::selected_t is T
 * u_bool_checker< T, F, false >::selected_t is F
 */
template< class T, class F, bool is_true >
struct u_bool_checker
{
private:
	template< class >
	struct true__
	{
		typedef T converted_t;
	};
	template< class >
	struct false__
	{
		typedef F converted_t;
	};
public:
	typedef typename u_bool_template
	<
		void,
		true__,
		false__,
		is_true
	>::selected_t selected_t;
};





}
#endif
