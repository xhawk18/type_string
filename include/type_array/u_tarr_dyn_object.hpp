#ifndef INC__U_TARR_DYN_OBJECT_HPP__
#define INC__U_TARR_DYN_OBJECT_HPP__
namespace utl
{



template
<
	template< class, class > class F,
	unsigned int index,
	class T,
	class P
>
bool u_tarr_call_object( T &object, P &param );



template
<
	template< class, class > class F,
	class T, 
	class P
>
class u_tarr_dyn_object
{
private:
	template< class T1, class T2 >
	struct ref_pair
	{
		ref_pair( T1 &t1, T2 &t2 )
			: first( t1 ), second( t2 )
		{
		}
		T1 &first;
		T2 &second;
	};

	template <unsigned int num, class TP__>
	struct F_object__
	{
		inline static void callback (TP__ &param)
		{
			utl::u_tarr_call_object< F, num, T , P >( param.first, param.second );
		}
	};
public:
	inline static bool call_object( unsigned int index, T &object, P &param )
	{
		ref_pair< T, P > params( object, param );
		return u_convert_variable_to_value
		<
			0,
			u_tarr_length<T>::m_length,
			F_object__,
			ref_pair< T, P >
		>( index, params );
	}
};


}
#endif
