#ifndef INC__U_TARR_DYN_TYPE_HPP__
#define INC__U_TARR_DYN_TYPE_HPP__
namespace utl
{



template
<
	template< class, class > class F,
	class T, 
	class P
>
class u_tarr_dyn_type
{
private:
	template< unsigned int num, class TP__ >
	struct F_type__
	{
		inline static void callback( TP__ &param )
		{
			F< typename u_tarr_fix_type< num, T >::element_t, TP__ >::filter_type( param );
		}
	};

public:
	inline static bool call_type( unsigned int index, P &param )
	{
		return u_convert_variable_to_value
		<
			0,
			u_tarr_length< T >::m_length,
			F_type__,
			P
		>( index, param );
	}
};


}
#endif
