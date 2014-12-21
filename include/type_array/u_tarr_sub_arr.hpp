#ifndef INC__U_TARR_SUB_ARR_H__
#define INC__U_TARR_SUB_ARR_H__
namespace utl
{


/*!
 * \brief	The class returns sub array by array_t.
 */
template <class T, unsigned int begin, unsigned int end = (unsigned int) -1>
class u_tarr_sub_arr
{
private:
	template <class TT__, bool parent_const, class TP__, unsigned int position>
	struct range_filter__
	{
		typedef TT__ converted_t;
		enum {m_selected = (position >= begin && position < end)};
	};

public:
	typedef typename u_tarr_filter
	<
		range_filter__,
		T,
		const int
	>::array_t array_t;
};






}
#endif
