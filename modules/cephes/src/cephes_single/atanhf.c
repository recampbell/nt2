/*							atanhf.c
 *
 *	Inverse hyperbolic tangent
 *
 *
 *
 * SYNOPSIS:
 *
 * float x, y, cephes_atanhf();
 *
 * y = cephes_atanhf( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns inverse hyperbolic tangent of argument in the range
 * MINLOGF to MAXLOGF.
 *
 * If |x| < 0.5, a polynomial approximation is used.
 * Otherwise,
 *        atanh(x) = 0.5 * log( (1+x)/(1-x) ).
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -1,1        100000      1.4e-7      3.1e-8
 *
 */

/*						atanh.c	*/


/*
Cephes Math Library Release 2.2:  June, 1992
Copyright (C) 1987, 1992 by Stephen L. Moshier
Direct inquiries to 30 Frost Street, Cambridge, MA 02140
*/

/* Single precision inverse hyperbolic tangent
 * test interval: [-0.5, +0.5]
 * trials: 10000
 * peak relative error: 8.2e-8
 * rms relative error: 3.0e-8
 */
#include "mconf.h"
extern float MAXNUMF;

#ifdef ANSIC
float cephes_logf( float );

float cephes_atanhf( float xx )
#else
float cephes_logf();

float cephes_atanhf(xx)
double xx;
#endif
{
float x, z;

x = xx;
if( x < 0 )
	z = -x;
else
	z = x;
if( z >= 1.0f )
	{
	if( x == 1.0f )
		return( 1.0f/0.0f );
	if( x == -1.0f )
		return( -1.0f/0.0f );
	return( 0.0f/0.0f );
	}

if( z < 1.0e-4f )
	return(x);

if( z < 0.5f )
	{
	z = x * x;
	z =
	(((( 1.81740078349E-1f * z
	  + 8.24370301058E-2f) * z
	  + 1.46691431730E-1f) * z
	  + 1.99782164500E-1f) * z
	  + 3.33337300303E-1f) * z * x
	  + x;
	return z;
	}
 else if (z >=0.5f)
	{
	z = 0.5f * cephes_logf( (1.0f+x)/(1.0f-x) );
	return z;
	}
 return( 0.0f/0.0f);
}
