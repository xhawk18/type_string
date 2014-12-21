#ifndef INC__U_TARR_CALL_TYPE_HPP__
#define INC__U_TARR_CALL_TYPE_HPP__
namespace utl
{





/*!
 * \brief	Call "call_type" in template F with the type indexed by index in
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
inline bool u_tarr_call_type( unsigned int index, P &param )
{
	return u_tarr_dyn_type< F, T, P >::call_type( index, param );
}



/*!
 * \brief	Call "filter_type" in template F with the type indexed by index in
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
	template< class, class > class F,
	unsigned int index,
	class T,
	class P
>
inline bool u_tarr_call_type( P &param )
{
	if ( index >= 0 && index < u_tarr_length<T>::m_length )
	{
		F< typename u_tarr_fix_type< index, T >::element_t, P >::filter_type( param );
		return true;
	}
	else
		return false;
}



}
#endif
