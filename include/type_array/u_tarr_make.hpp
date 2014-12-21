#ifndef INC__U_TARR_MAKER_HPP__
#define INC__U_TARR_MAKER_HPP__
namespace utl
{



u_void
inline u_tarr_make( )
{
	return u_void( );
}


template
<
	class T_00
>
inline 
T_00
u_tarr_make(
	T_00 const &t_00
	)
{
	return t_00;
}


template
<
	class T_00,
	class T_01
>
inline 
std::pair< T_00,
		   T_01 >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01
	)
{
	return
		std::make_pair( t_00,
						t_01 );
}


template
<
	class T_00,
	class T_01,
	class T_02
>
inline 
std::pair< T_00,
std::pair< T_01,
		   T_02 > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
						t_02 ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
		   T_03 > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
						t_03 ) ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
		   T_04 > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
						t_04 ) ) ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
		   T_05 > > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
						t_05 ) ) ) ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
		   T_06 > > > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
						t_06 ) ) ) ) ) );
}



template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
		   T_07 > > > > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
						t_07 ) ) ) ) ) ) );
}




template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
		   T_08 > > > > > > >
			  >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
						t_08 ) ) ) ) ) ) )
						   );
}



template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08,
	class T_09
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
std::pair< T_08,
		   T_09 > > > > > > >
			  > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08, T_09 const &t_09
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
		std::make_pair( t_08,
						t_09 ) ) ) ) ) ) )
						   ) );
}



template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08,
	class T_09,
	class T_0A
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
std::pair< T_08,
std::pair< T_09,
		   T_0A > > > > > > >
			  > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08, T_09 const &t_09, T_0A const &t_0A
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
		std::make_pair( t_08,
		std::make_pair( t_09,
						t_0A ) ) ) ) ) ) )
						   ) ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08,
	class T_09,
	class T_0A,
	class T_0B
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
std::pair< T_08,
std::pair< T_09,
std::pair< T_0A,
		   T_0B > > > > > > >
			  > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08, T_09 const &t_09, T_0A const &t_0A, T_0B const &t_0B
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
		std::make_pair( t_08,
		std::make_pair( t_09,
		std::make_pair( t_0A,
						t_0B ) ) ) ) ) ) )
						   ) ) ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08,
	class T_09,
	class T_0A,
	class T_0B,
	class T_0C
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
std::pair< T_08,
std::pair< T_09,
std::pair< T_0A,
std::pair< T_0B,
		   T_0C > > > > > > >
			  > > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08, T_09 const &t_09, T_0A const &t_0A, T_0B const &t_0B,
	T_0C const &t_0C
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
		std::make_pair( t_08,
		std::make_pair( t_09,
		std::make_pair( t_0A,
		std::make_pair( t_0B,
						t_0C ) ) ) ) ) ) )
						   ) ) ) ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08,
	class T_09,
	class T_0A,
	class T_0B,
	class T_0C,
	class T_0D
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
std::pair< T_08,
std::pair< T_09,
std::pair< T_0A,
std::pair< T_0B,
std::pair< T_0C,
		   T_0D > > > > > > >
			  > > > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08, T_09 const &t_09, T_0A const &t_0A, T_0B const &t_0B,
	T_0C const &t_0C, T_0D const &t_0D
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
		std::make_pair( t_08,
		std::make_pair( t_09,
		std::make_pair( t_0A,
		std::make_pair( t_0B,
		std::make_pair( t_0C,
						t_0D ) ) ) ) ) ) )
						   ) ) ) ) ) );
}



template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08,
	class T_09,
	class T_0A,
	class T_0B,
	class T_0C,
	class T_0D,
	class T_0E
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
std::pair< T_08,
std::pair< T_09,
std::pair< T_0A,
std::pair< T_0B,
std::pair< T_0C,
std::pair< T_0D,
		   T_0E > > > > > > >
			  > > > > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08, T_09 const &t_09, T_0A const &t_0A, T_0B const &t_0B,
	T_0C const &t_0C, T_0D const &t_0D, T_0E const &t_0E
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
		std::make_pair( t_08,
		std::make_pair( t_09,
		std::make_pair( t_0A,
		std::make_pair( t_0B,
		std::make_pair( t_0C,
		std::make_pair( t_0D,
						t_0E ) ) ) ) ) ) )
						   ) ) ) ) ) ) );
}


template
<
	class T_00,
	class T_01,
	class T_02,
	class T_03,
	class T_04,
	class T_05,
	class T_06,
	class T_07,
	class T_08,
	class T_09,
	class T_0A,
	class T_0B,
	class T_0C,
	class T_0D,
	class T_0E,
	class T_0F
>
inline
std::pair< T_00,
std::pair< T_01,
std::pair< T_02,
std::pair< T_03,
std::pair< T_04,
std::pair< T_05,
std::pair< T_06,
std::pair< T_07,
std::pair< T_08,
std::pair< T_09,
std::pair< T_0A,
std::pair< T_0B,
std::pair< T_0C,
std::pair< T_0D,
std::pair< T_0E,
		   T_0F > > > > > > >
			  > > > > > > > >
u_tarr_make(
	T_00 const &t_00, T_01 const &t_01, T_02 const &t_02, T_03 const &t_03,
	T_04 const &t_04, T_05 const &t_05, T_06 const &t_06, T_07 const &t_07,
	T_08 const &t_08, T_09 const &t_09, T_0A const &t_0A, T_0B const &t_0B,
	T_0C const &t_0C, T_0D const &t_0D, T_0E const &t_0E, T_0F const &t_0F
	)
{
	return
		std::make_pair( t_00,
		std::make_pair( t_01,
		std::make_pair( t_02,
		std::make_pair( t_03,
		std::make_pair( t_04,
		std::make_pair( t_05,
		std::make_pair( t_06,
		std::make_pair( t_07,
		std::make_pair( t_08,
		std::make_pair( t_09,
		std::make_pair( t_0A,
		std::make_pair( t_0B,
		std::make_pair( t_0C,
		std::make_pair( t_0D,
		std::make_pair( t_0E,
						t_0F ) ) ) ) ) ) )
						   ) ) ) ) ) ) ) );
}


template< class L, class R >
inline
typename u_tarr_regular< std::pair< L, R > >::array_t
u_tarr_make( std::pair< L, R > const &t	)
{
	return u_tarr_make( t.first, t.second );
}


template< class L, class M, class R >
inline
typename u_tarr_regular< std::pair< std::pair< L, M >, R > >::array_t
u_tarr_make( std::pair< L, M > const &left, R const &right )
{
	return u_tarr_make( left.first, u_tarr_make( left.second, right ) );
}


template< class L, class M, class R >
inline
typename u_tarr_regular< std::pair< L, std::pair< M, R > > >::array_t
u_tarr_make( L const &left, std::pair< M, R > const &right )
{
	return std::make_pair( left, u_tarr_make( right ) );
}


template< class L1, class L2, class R1, class R2 >
inline
typename u_tarr_regular< std::pair< std::pair< L1, L2 >, std::pair< R1, R2 > > >::array_t
u_tarr_make( std::pair< L1, L2 > const &left, std::pair< R1, R2 > const &right )
{
	return u_tarr_make( left.first, u_tarr_make( left.second, u_tarr_make( right.first, right.second ) ) );
}


}
#endif
