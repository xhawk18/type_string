#ifndef INC__U_TYPES_HPP__
#define INC__U_TYPES_HPP__
namespace utl
{

/*!
 * \brief	Null type.
 */
struct u_void
{
};



/*!
 * \brief	priority
 */
struct u_priority_e
{
	enum type
	{
		low		= -1,
		normal	= 0,
		high	= 1,
		urgent	= 2
	};
};



}
#endif

