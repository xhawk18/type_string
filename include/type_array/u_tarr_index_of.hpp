#ifndef INC__U_TARR_INDEX_OF_HPP__
#define INC__U_TARR_INDEX_OF_HPP__
namespace utl
{



template <class T, class E>
struct u_tarr_index_of_element
{
private:

	template <class TT__, bool parent_const, class TP__, unsigned int position>
	struct filter__
	{
		struct converted_t
		{
			enum {m_index = position};
		};
		enum {m_selected = (u_same_class <E, TT__>::m_is_same)};
	};

	typedef typename u_tarr_filter <filter__, T>::array_t filter_t;



	template <class TE__>
	struct found_first__
	{
		typedef typename u_tarr_fix_type <0, TE__>::type_t converted_t;
	};

	template <class TE__>
	struct not_found__
	{
		struct converted_t
		{
			enum {m_index = -1};
		};
	};

	typedef typename u_bool_template
	<
		filter_t,
		found_first__,
		not_found__,
		(u_tarr_length <filter_t>::m_length > 0 ? true : false )
	>::selected_t element_t;

public:
	enum {m_index = element_t::m_index};
};



template <class T, class S, unsigned int begin, unsigned int substr_length>
struct u_tarr_index_of_arr__
{
private:
	typedef typename u_tarr_sub_arr <T, begin, substr_length + begin>::array_t substr_t;
	enum {m_is_same = u_same_class <substr_t, S>::m_is_same};


	template <class>
	struct found__
	{
		struct converted_t
		{
			enum {m_index = begin};
		};
	};

	template <class>
	struct not_found__
	{
		template <class>
		struct check__
		{
			struct converted_t
			{
				enum {m_index = u_tarr_index_of_arr__<T, S, begin + 1, substr_length>::m_index};
			};
		};

		template <class>
		struct not_check__
		{
			struct converted_t
			{
				enum {m_index = -1};
			};
		};

		struct converted_t
		{
			typedef typename u_bool_template
			<
				void,
				check__,
				not_check__,
				(begin < u_tarr_length <T>::m_length ? true : false)
			>::selected_t checker_t;
			enum
			{
				m_index = checker_t::m_index
			};

		};
	};

	typedef typename u_bool_template
	<
		void,
		found__,
		not_found__,
		m_is_same
	>::selected_t selected_t;

public:
	enum {m_index = selected_t::m_index};
};

template <class T, class S>
struct u_tarr_index_of_arr
{
private:
	enum {m_substr_length = u_tarr_length <S>::m_length};
public:
	enum {m_index = u_tarr_index_of_arr__<T, S, 0, m_substr_length>::m_index};
};



/*!
 * \brief	The class that contains the index of type represented by m_index.
 *
 * \param	T, the types array.
 * \param	E, the type to be searched in the types array.
 * \return	If the type E is found, m_index is the index of type E, otherwise
 *          m_index is -1.
 */
template <class T, class E>
struct u_tarr_index_of
{
	enum {m_index = u_tarr_index_of_element <T, E>::m_index};
};

template <class T, class S1, class S2>
struct u_tarr_index_of <T, std::pair <S1, S2> >
{
	enum {m_index = u_tarr_index_of_arr <T, std::pair <S1, S2> >::m_index};
};




}
#endif
