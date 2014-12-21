#ifndef INC__U_TARR_CALL_OBJECT_HPP__
#define INC__U_TARR_CALL_OBJECT_HPP__
namespace utl
{




/*!
 * \brief	Call "callback" in template F with the type indexed by index in
 *			type array T.
 *
 * \param	F		The callback object that should privide function "callback",
 *					which is to be called with parameter "param" and the indexed
 *					type.
 * \param	T		The type array.
 * \param	P		The type of callback parameter for the callback template.
 * \param	index	Index of the type in type array.
 * \param	param	The prameter used by callback object F.
 * \return	true if callback is called, otherwise false.
 */
template
<
	template< class, class > class F,
	class T, 
	class P
>
inline bool u_tarr_call_object( unsigned int index, T &object, P &param )
{
	return u_tarr_dyn_object< F, T, P >::call_object( index, object, param );
}



template
<
	template< class, class > class F,
	unsigned int index,
	class T,
	class P
>
struct u_tarr_call_object__
{
	template< class T__, bool parent_const, class P__, unsigned int index__ >
	struct filter__
	{
		enum{ m_selected = ( index == index__ ? true : false ) };
		struct converted_t
		{
		};
		inline static void filter_object( typename u_const< T__, parent_const >::type_t &object, P &param )
		{
			F< typename u_const< T__, parent_const >::type_t, P__ >::filter_object( object, param );
		}
	};

	static inline bool call_object( T &object, P &param )
	{
		if (index >= 0 && index < u_tarr_length<T>::m_length)
		{
			u_tarr_filter< filter__, T, P >::filter_object( object, param );
			return true;
		}
		else
			return false;
	}
};


/*!
 * \brief	Call "callback" in template F with the type indexed by index in
 *			type array T.
 *
 * \param	F		The callback object that should privide function "callback",
 *					which is to be called with parameter "param" and the indexed
 *					type.
 * \param	index	Index of the type in type array.
 * \param	T		The type array.
 * \param	P		The type of callback parameter for the callback template.
 * \param	param	The prameter used by callback object F.
 * \return	true if callback is called, otherwise false.
 */
template
<
	template <class, class> class F,
	unsigned int index,
	class T,
	class P
>
inline bool u_tarr_call_object( T &object, P &param )
{
	return u_tarr_call_object__< F, index, T, P >::call_object( object, param );
}





}
#endif
