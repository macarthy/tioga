/* makers.c */
/*
   Copyright (C) 2005  Bill Paxton

   This file is part of Tioga.

   Tioga is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Library Public License as published
   by the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   Tioga is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with Tioga; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "figures.h"


/* Lines */

   void c_private_make_spline_interpolated_points(FM *p, VALUE Xvec, VALUE Yvec, VALUE Xvec_data, VALUE Yvec_data,
        int start_clamped, double start_slope, int end_clamped, double end_slope) {
      int i, n_pts_data;
      double *As, *Bs, *Cs, *Ds;
      long xlen, ylen, xdlen, ydlen;
      double *Xs = Dvector_Data_for_Write(Xvec, &xlen);
      double *Ys = Dvector_Data_for_Write(Yvec, &ylen);
      double *X_data = Dvector_Data_for_Read(Xvec_data, &xdlen);
      double *Y_data = Dvector_Data_for_Read(Yvec_data, &ydlen);
      if (Xs == NULL || Ys == NULL || X_data == NULL || Y_data == NULL || xdlen != ydlen) {
         rb_raise(rb_eArgError, "Sorry: bad args for make_curves");
      }
      if (xlen == 0) return;
      n_pts_data = xdlen;
      As = Y_data;
      Bs = (double *)ALLOC_N(double, n_pts_data);
      Cs = (double *)ALLOC_N(double, n_pts_data);
      Ds = (double *)ALLOC_N(double, n_pts_data);
      c_dvector_create_spline_interpolant(n_pts_data, X_data, Y_data,
         start_clamped, start_slope, end_clamped, end_slope, Bs, Cs, Ds);
      Ys = Dvector_Data_Resize(Yvec, xlen);
      for (i = 0; i < xlen; i++)
         Ys[i] = c_dvector_spline_interpolate(Xs[i], n_pts_data, X_data, As, Bs, Cs, Ds);
      free(Ds); free(Cs); free(Bs);
      USE_P
      }
      
   VALUE FM_private_make_spline_interpolated_points(VALUE fmkr, VALUE Xvec, VALUE Yvec, VALUE Xvec_data, VALUE Yvec_data,
        VALUE start_slope, VALUE end_slope) {
      FM *p = Get_FM(fmkr);
      bool start_clamped = (start_slope != Qnil), end_clamped = (end_slope != Qnil);
      double start=0, end=0;
      if (start_clamped) {
         start_slope = rb_Float(start_slope);
         start = NUM2DBL(start_slope);
      }
      if (end_clamped) {
         end_slope = rb_Float(end_slope);
         end = NUM2DBL(end_slope);
      }
      c_private_make_spline_interpolated_points(p, Xvec, Yvec, Xvec_data, Yvec_data,
         start_clamped, start, end_clamped, end);
      return fmkr;
   }

   void c_make_steps(FM *p, VALUE Xvec, VALUE Yvec, VALUE Xvec_data, VALUE Yvec_data,
        double xfirst, double yfirst, double xlast, double ylast){
      double xnext, xprev, x;
      int n_pts_to_add;
      int i, j, n, old_length, new_length;
      long xlen, ylen, xdlen, ydlen;
      double *Xs = Dvector_Data_for_Write(Xvec, &xlen);
      double *Ys = Dvector_Data_for_Write(Yvec, &ylen);
      double *X_data = Dvector_Data_for_Read(Xvec_data, &xdlen);
      double *Y_data = Dvector_Data_for_Read(Yvec_data, &ydlen);
      if (Xs == NULL || Ys == NULL || X_data == NULL || Y_data == NULL
            || xdlen != ydlen || xlen != ylen) {
         rb_raise(rb_eArgError, "Sorry: bad args for make_steps");
      }
      n = xdlen;
      n_pts_to_add = 2*(n+1);
      old_length = xlen;
      new_length = old_length + n_pts_to_add;
      Xs = Dvector_Data_Resize(Xvec, new_length);
      Ys = Dvector_Data_Resize(Yvec, new_length);
      for (i = 0, j = 0; i <= n; i++, j += 2) {
         xprev = (i==0)? xfirst : X_data[i-1];
         xnext = (i==n)? xlast : X_data[i];
         x = 0.5*(xprev + xnext);
         Xs[j+old_length] = Xs[j+1+old_length] = x;
         }
      Ys[0] = yfirst;
      for (i = 0, j = 1; i < n; i++, j += 2) {
         Ys[j+old_length] = Ys[j+1+old_length] = Y_data[i];
         }
      Ys[n_pts_to_add-1+old_length] = ylast;
      USE_P
      }
      
   VALUE FM_private_make_steps(VALUE fmkr, VALUE Xvec, VALUE Yvec, VALUE Xvec_data, VALUE Yvec_data,
        VALUE xfirst, VALUE yfirst, VALUE xlast, VALUE ylast) {
      FM *p = Get_FM(fmkr);
      xfirst = rb_Float(xfirst);
      yfirst = rb_Float(yfirst);
      xlast = rb_Float(xlast);
      ylast = rb_Float(ylast);
      c_make_steps(p, Xvec, Yvec, Xvec_data, Yvec_data,
         NUM2DBL(xfirst), NUM2DBL(yfirst), NUM2DBL(xlast), NUM2DBL(ylast));
      return fmkr;
   }

/*
CONREC: A Contouring Subroutine
written by Paul Bourke
see: http://astronomy.swin.edu.au/~pbourke/projection/conrec/

Copyright (c) 1996-1997 Nicholas Yue

This software is copyrighted by Nicholas Yue. This code is base on the work of
Paul D. Bourke CONREC.F routine

The authors hereby grant permission to use, copy, and distribute this
software and its documentation for any purpose, provided that existing
copyright notices are retained in all copies and that this notice is included
verbatim in any distributions. Additionally, the authors grant permission to
modify this software and its documentation for any purpose, provided that
such modifications are not distributed without the explicit consent of the
authors and that existing copyright notices are retained in all copies. Some
of the algorithms implemented by this software are patented, observe all
applicable patent law.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/

//=============================================================================
//
//     CONREC is a contouring subroutine for rectangularily spaced data.
//
//     It emits calls to a line drawing subroutine supplied by the user
//     which draws a contour map corresponding to real*4data on a randomly
//     spaced rectangular grid. The coordinates emitted are in the same
//     units given in the x() and y() arrays.
//
//     Any number of contour levels may be specified but they must be
//     in order of increasing value.
//
//     As this code is ported from FORTRAN-77, please be very careful of the
//     various indices like ilb,iub,jlb and jub, remeber that C/C++ indices
//     starts from zero (0)
//
//=============================================================================
#include <stdio.h>
#include <math.h>

#define xsect(p1,p2) (h[p2]*xh[p1]-h[p1]*xh[p2])/(h[p2]-h[p1])
#define ysect(p1,p2) (h[p2]*yh[p1]-h[p1]*yh[p2])/(h[p2]-h[p1])
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)

#define PUSH_POINT(x,y,j) { \
   Dvector_Store_Double(dest_xs, j, x); \
   Dvector_Store_Double(dest_ys, j, y); \
   j++; }

int conrec(double **d,
	   int ilb,
	   int iub,
	   int jlb,
	   int jub,
	   double *x,
	   double *y,
	   int nc,
	   double *z,
	   VALUE dest_xs,
	   VALUE dest_ys,
	   VALUE gaps,
	   double x_limit,
	   double y_limit)
// d               ! matrix of data to contour
// ilb,iub,jlb,jub ! index bounds of data matrix
// x               ! data matrix column coordinates
// y               ! data matrix row coordinates
// nc              ! number of contour levels
// z               ! contour levels in increasing order
{
int num_pts = 0;
double x_prev=0.0, y_prev=0.0;
  int m1,m2,m3,case_value;
  double dmin,dmax,x1=0.0,x2=0.0,y1=0.0,y2=0.0;
  register int i,j,k,m;
  double h[5];
  int sh[5];
  double xh[5],yh[5];
  //===========================================================================
  // The indexing of im and jm should be noted as it has to start from zero
  // unlike the fortran counter part
  //===========================================================================
  int im[4] = {0,1,1,0},jm[4]={0,0,1,1};
  //===========================================================================
  // Note that castab is arranged differently from the FORTRAN code because
  // Fortran and C/C++ arrays are transposes of each other, in this case
  // it is more tricky as castab is in 3 dimension
  //===========================================================================
  int castab[3][3][3] =
  {
    {
      {0,0,8},{0,2,5},{7,6,9}
    },
    {
      {0,3,4},{1,3,1},{4,3,0}
    },
    {
      {9,6,7},{5,2,0},{8,0,0}
    }
  };
  for (j=(jub-1);j>=jlb;j--) {
    for (i=ilb;i<=iub-1;i++) {
      double temp1,temp2;
      temp1 = min(d[i][j],d[i][j+1]);
      temp2 = min(d[i+1][j],d[i+1][j+1]);
      dmin = min(temp1,temp2);
      temp1 = max(d[i][j],d[i][j+1]);
      temp2 = max(d[i+1][j],d[i+1][j+1]);
      dmax = max(temp1,temp2);
      if (dmax>=z[0]&&dmin<=z[nc-1]) {
	for (k=0;k<nc;k++) {
	  if (z[k]>=dmin&&z[k]<=dmax) {
	    for (m=4;m>=0;m--) {
	      if (m>0) {
		//=============================================================
		// The indexing of im and jm should be noted as it has to
		// start from zero
		//=============================================================
		h[m] = d[i+im[m-1]][j+jm[m-1]]-z[k];
		xh[m] = x[i+im[m-1]];
		yh[m] = y[j+jm[m-1]];
	      } else {
		h[0] = 0.25*(h[1]+h[2]+h[3]+h[4]);
		xh[0]=0.5*(x[i]+x[i+1]);
		yh[0]=0.5*(y[j]+y[j+1]);
	      }
	      if (h[m]>0.0) {
		sh[m] = 1;
	      } else if (h[m]<0.0) {
		sh[m] = -1;
	      } else
		sh[m] = 0;
	    }
	    //=================================================================
	    //
	    // Note: at this stage the relative heights of the corners and the
	    // centre are in the h array, and the corresponding coordinates are
	    // in the xh and yh arrays. The centre of the box is indexed by 0
	    // and the 4 corners by 1 to 4 as shown below.
	    // Each triangle is then indexed by the parameter m, and the 3
	    // vertices of each triangle are indexed by parameters m1,m2,and
	    // m3.
	    // It is assumed that the centre of the box is always vertex 2
	    // though this isimportant only when all 3 vertices lie exactly on
	    // the same contour level, in which case only the side of the box
	    // is drawn.
	    //
	    //
	    //      vertex 4 +-------------------+ vertex 3
	    //               | \               / |
	    //               |   \    m-3    /   |
	    //               |     \       /     |
	    //               |       \   /       |
	    //               |  m=2    X   m=2   |       the centre is vertex 0
	    //               |       /   \       |
	    //               |     /       \     |
	    //               |   /    m=1    \   |
	    //               | /               \ |
	    //      vertex 1 +-------------------+ vertex 2
	    //
	    //
	    //
	    //               Scan each triangle in the box
	    //
	    //=================================================================
	    for (m=1;m<=4;m++) {
	      m1 = m;
	      m2 = 0;
	      if (m!=4)
		m3 = m+1;
	      else
		m3 = 1;
	      case_value = castab[sh[m1]+1][sh[m2]+1][sh[m3]+1];
	      if (case_value!=0) {
		switch (case_value) {
		  //===========================================================
		  //     Case 1 - Line between vertices 1 and 2
		  //===========================================================
		case 1:
		  x1=xh[m1];
		  y1=yh[m1];
		  x2=xh[m2];
		  y2=yh[m2];
		  break;
		  //===========================================================
		  //     Case 2 - Line between vertices 2 and 3
		  //===========================================================
		case 2:
		  x1=xh[m2];
		  y1=yh[m2];
		  x2=xh[m3];
		  y2=yh[m3];
		  break;
		  //===========================================================
		  //     Case 3 - Line between vertices 3 and 1
		  //===========================================================
		case 3:
		  x1=xh[m3];
		  y1=yh[m3];
		  x2=xh[m1];
		  y2=yh[m1];
		  break;
		  //===========================================================
		  //     Case 4 - Line between vertex 1 and side 2-3
		  //===========================================================
		case 4:
		  x1=xh[m1];
		  y1=yh[m1];
		  x2=xsect(m2,m3);
		  y2=ysect(m2,m3);
		  break;
		  //===========================================================
		  //     Case 5 - Line between vertex 2 and side 3-1
		  //===========================================================
		case 5:
		  x1=xh[m2];
		  y1=yh[m2];
		  x2=xsect(m3,m1);
		  y2=ysect(m3,m1);
		  break;
		  //===========================================================
		  //     Case 6 - Line between vertex 3 and side 1-2
		  //===========================================================
		case 6:
		  x1=xh[m3];
		  y1=yh[m3];
		  x2=xsect(m1,m2);
		  y2=ysect(m1,m2);
		  break;
		  //===========================================================
		  //     Case 7 - Line between sides 1-2 and 2-3
		  //===========================================================
		case 7:
		  x1=xsect(m1,m2);
		  y1=ysect(m1,m2);
		  x2=xsect(m2,m3);
		  y2=ysect(m2,m3);
		  break;
		  //===========================================================
		  //     Case 8 - Line between sides 2-3 and 3-1
		  //===========================================================
		case 8:
		  x1=xsect(m2,m3);
		  y1=ysect(m2,m3);
		  x2=xsect(m3,m1);
		  y2=ysect(m3,m1);
		  break;
		  //===========================================================
		  //     Case 9 - Line between sides 3-1 and 1-2
		  //===========================================================
		case 9:
		  x1=xsect(m3,m1);
		  y1=ysect(m3,m1);
		  x2=xsect(m1,m2);
		  y2=ysect(m1,m2);
		  break;
		default:
		  break;
		}
		double dx = x1 - x_prev, dy = y1 - y_prev;
		if (dx < 0) dx = -dx; if (dy < 0) dy = -dy;
		if (num_pts == 0 || dx > x_limit || dy > y_limit) {
         if (num_pts > 0) rb_ary_push(gaps, INT2FIX(num_pts));
         PUSH_POINT(x1,y1,num_pts);
		}
		PUSH_POINT(x2,y2,num_pts);
		x_prev = x2; y_prev = y2;
	      }
	    }
	  }
	}
      }
    }
  }
  return 0;
}

/* end of conrec */








// the following code is from Gri




#include <math.h>
#include <stdio.h>
#include <string.h>

// globals to this file
static int      nx_1, ny_1, iGT, jGT, iLE, jLE;

static void     free_space_for_curve();
static void     get_space_for_curve();
static void     draw_the_contour(
	   VALUE dest_xs,
	   VALUE dest_ys,
	   VALUE gaps);

static bool     trace_contour(double z0,
			      double *x,
			      double *y,
                  double **z,
			      double **legit,
			      VALUE dest_xs,
			      VALUE dest_ys,
			      VALUE gaps);
                  
static int      FLAG(int ni, int nj, int ind);
static int      append_segment(double xr, double yr, double zr, double OKr,
			       double xs, double ys, double zs, double OKs,
			       double z0);

// Space for curve, shared by several routines
static double  *xcurve, *ycurve;
static bool *legitcurve;
#define INITIAL_CURVE_SIZE 100
static int      num_in_curve, max_in_curve, num_in_path;
static bool     curve_storage_exists = false;


static void
free_space_for_curve()
{
	if (curve_storage_exists) {
		free(xcurve);
		free(ycurve);
		free(legitcurve);
		curve_storage_exists = false;
	}
	num_in_curve = 0;
	num_in_path = 0;
}

static void
get_space_for_curve()
{
	max_in_curve = INITIAL_CURVE_SIZE;
	if(curve_storage_exists) {
		rb_raise(rb_eArgError, "storage is messed up (internal error)");
		return;			// will not execute
	}
	xcurve = ALLOC_N(double, max_in_curve);
	ycurve = ALLOC_N(double, max_in_curve);
	legitcurve = ALLOC_N(bool, max_in_curve);
	curve_storage_exists = true;
	num_in_curve = 0;
	num_in_path = 0;
}



//  gr_contour() -- draw contour line for gridded data
//  
//  DESCRIPTION: Draws a contour for the value z0, through data z[i][j] defined
//  on the rectangular grid x[i] and y[j] (where 0<=i<nx and 0<=j<ny).  That
//  the grid is rectangular but needn't be square or regular. Contours are
//  drawn only in triangular regions surrounded by 3 good points (ie, 3 points
//  with legit[i][j] != 0.0).
//  
//  The contour is labelled, with the string// lab, at intervals of
//  contour_space_later centimeters, starting with a space of
//  contour_space_first from the beginning of the trace.
//  
//  CONTOUR_VALUE MISSING_VALUE
static void
gr_contour(
	   double *x,
	   double *y,
	   double **z,
	   double **legit,
	   int nx,
	   int ny, 
	   double z0,
	   VALUE dest_xs,
	   VALUE dest_ys,
	   VALUE gaps)
{
	register int    i, j;
	// Test for errors
	if (nx <= 0) rb_raise(rb_eArgError, "nx<=0 (internal error)");
	if (ny <= 0) rb_raise(rb_eArgError, "ny<=0 (internal error)");
	// Save some globals
	nx_1 = nx - 1;
	ny_1 = ny - 1;
	// Clear  all switches.
	FLAG(nx, ny, -1);
	// Get space for the curve.
	get_space_for_curve();
    
	// Search for a contour intersecting various places on the grid. Whenever
	// a contour is found to be between two grid points, call trace_contour()
	// after defining the global variables iLE,jLE,iGT,jGT so that
	// z[iLE]jLE] <= z0 < z[iGT][jGT], where legit[iLE][jLE] != 0
	// and legit[iGT][jGT] != 0.
	//
	// NOTE: always start a contour running upwards (to greater j), between
	// two sideways neighboring points (same j).  Later, in trace_contour(),
	// test 'locate' for value 5.  If it's 5, it means that the same geometry
	// obtains, so set a flag and check whether already set.  If already
	// set, it means we've traced this contour before, so trace_contour()
	// knows to stop then.

	// Search bottom
	for (i = 1; i < nx; i++) {
		j = 0;
		while (j < ny_1) {
			// move north to first legit point
			while (j < ny_1 
			       && (legit == NULL || !(legit[i][j] != 0.0 && legit[i - 1][j] != 0.0))
				) {
				j++;
			}
			// trace a contour if it hits here
			if (j < ny_1 && z[i][j] > z0 && z[i - 1][j] <= z0) {
				iLE = i - 1;
				jLE = j;
				iGT = i;
				jGT = j;
				trace_contour(z0, x, y, z, legit, dest_xs, dest_ys, gaps);
			}
			// Space through legit points, that is, skipping through good
			// data looking for another island of bad data which will
			// thus be a new 'bottom edge'.
			while (j < ny_1 && (legit == NULL || (legit[i][j] != 0.0 && legit[i - 1][j] != 0.0)))
				j++;
		}
	}

	// search right edge
	for (j = 1; j < ny; j++) {
		i = nx_1;
		while (i > 0) {
			// move west to first legit point
			while (i > 0 && (legit == NULL || !(legit[i][j] != 0.0 && legit[i][ j - 1] != 0.0)))
				i--;
			// trace a contour if it hits here
			if (i > 0 && z[i][j] > z0 && z[i][j - 1] <= z0) {
				iLE = i;
				jLE = j - 1;
				iGT = i;
				jGT = j;
				trace_contour(z0, x, y, z, legit, dest_xs, dest_ys, gaps);
			}
			// space through legit points
			while (i > 0 && (legit == NULL || legit[i][j] != 0.0 && legit[i][ j - 1] != 0.0))
				i--;
		}
	}

	// search top edge
	for (i = nx_1 - 1; i > -1; i--) {
		j = ny_1;
		while (j > 0) {
			while (j > 0 && (legit == NULL || !(legit[i][j] != 0.0 && legit[i + 1][ j] != 0.0)))
				j--;
			// trace a contour if it hits here
			if (j > 0 && z[i][j] > z0 && z[i + 1][ j] <= z0) {
				iLE = i + 1;
				jLE = j;
				iGT = i;
				jGT = j;
				trace_contour(z0, x, y, z, legit, dest_xs, dest_ys, gaps);
			}
			// space through legit points
			while (j > 0 && (legit == NULL || legit[i][j] != 0.0 && legit[i + 1][ j] != 0.0))
				j--;
		}
	}

	// search left edge
	for (j = ny_1 - 1; j > -1; j--) {
		i = 0;
		while (i < nx_1) {
			while (i < nx_1 && (legit == NULL || !(legit[i][j] != 0.0 && legit[i][ j + 1] != 0.0)))
				i++;
			// trace a contour if it hits here
			if (i < nx_1 && z[i][j] > z0 && z[i][j + 1] <= z0) {
				iLE = i;
				jLE = j + 1;
				iGT = i;
				jGT = j;
				trace_contour(z0, x, y, z, legit, dest_xs, dest_ys, gaps);
			}
			// space through legit points
			while (i < nx_1 && (legit == NULL || legit[i][j] != 0.0 && legit[i][ j + 1] != 0.0))
				i++;
		}
	}

	// Search interior. Pass up from bottom (starting at left), through all
	// interior points. Look for contours which enter, with high to right,
	// between iLE on left and iGT on right.
	for (j = 1; j < ny_1; j++) {
		int             flag_is_set;
		for (i = 1; i < nx; i++) {
			// trace a contour if it hits here
			flag_is_set = FLAG(i, j, 0);
			if (flag_is_set < 0)
				rb_raise(rb_eArgError, "ran out of storage (internal error)");
			if (!flag_is_set
			    && (legit == NULL || legit[i][j] != 0.0)
			    && z[i][j] > z0
			    && (legit == NULL || legit[i - 1][j] != 0.0)
			    && z[i - 1][j] <= z0) {
				iLE = i - 1;
				jLE = j;
				iGT = i;
				jGT = j;
				trace_contour(z0, x, y, z, legit, dest_xs, dest_ys, gaps);
			}
		}
	}
	// Free up space.
	free_space_for_curve();
	FLAG(nx, ny, 2);
}

// trace_contour() -- trace_contour a contour line with high values of z to
// it's right.  Stores points in (*xcurve, *ycurve) and the legit flag is
// stored in *legitcurve; initially these must be empty; you must also free
// them after this call, so that the next call will work OK.
static          bool
trace_contour(double z0,
	      double *x,
	      double *y,
	      double **z,
	      double **legit,
	      VALUE dest_xs,
	      VALUE dest_ys,
	      VALUE gaps
)
{
	int             i, ii, j, jj;
	double          zp, vx, vy, zcentre;
	int             locate;
	// locate tells where delta-grid point is.  It codes as follows to
	// i_test[] and j_test[] 6 7 8 3 4 5 0 1 2
	static int      i_test[9] = {
		0, 1, 1,		// 6 7 8
		0, 9, 0,		// 3 4 5
		-1, -1, 0		// 0 1 2
	};
	static int      j_test[9] =
	{
		-1, 0, 0,		// 6 7 8
		-1, 9, 1,		// 3 4 5
		0, 0, 1			// 0 1 2
	};
	static int      dtest[9] =
	{
		0, 1, 0,		// 6 7 8
		1, 0, 1,		// 3 4 5
		0, 1, 0			// 0 1 2
	};


	// Trace the curve, storing results with append_segment() into *xcurve,
	// *ycurve, *legitcurve.  When done, call draw_the_contour(), which draws
	// the contour stored in these arrays.
	while (true) {
	
		append_segment(x[iLE], y[jLE], z[iLE][jLE], (legit == NULL)? 1.0: legit[iLE][jLE],
			       x[iGT], y[jGT], z[iGT][jGT], (legit == NULL)? 1.0: legit[iGT][jGT],
			       z0);
		// Find the next point to check through a table lookup.
		locate = 3 * (jGT - jLE) + (iGT - iLE) + 4;
		i = iLE + i_test[locate];
		j = jLE + j_test[locate];

	
		// Did it hit an edge?
		if (i > nx_1 || i < 0 || j > ny_1 || j < 0) {
			draw_the_contour(dest_xs, dest_ys, gaps);
			return true;		// all done
		}

		// Test if retracing an existing contour.  See explanation
		// above, in grcntour(), just before search starts. 
		if (locate == 5) {
			int             already_set = FLAG(iGT, jGT, 1);
			if (already_set < 0) {
				rb_raise(rb_eArgError, "ran out of storage (internal error)");
				return false;
			}
			if (already_set) {
				draw_the_contour(dest_xs, dest_ys, gaps);
				return true;	// all done
			}
		}

		// Following new for 2.1.13
		if (legit != NULL && legit[i][j] == 0.0) {
			draw_the_contour(dest_xs, dest_ys, gaps);
			return true;		// all done
		} 

		if (!dtest[locate]) {
			zp = z[i][j];
			if (zp > z0)
				iGT = i, jGT = j;
			else
				iLE = i, jLE = j;
			continue;
		}
		vx = (x[iGT] + x[i]) * 0.5;
		vy = (y[jGT] + y[j]) * 0.5;
		locate = 3 * (jGT - j) + iGT - i + 4;
		// Fourth point in rectangular boundary
		ii = i + i_test[locate];
		jj = j + j_test[locate];
		bool legit_diag = 
			(legit == NULL || (legit[iLE][jLE] != 0.0
			 && legit[iGT][jGT] != 0.0 
			 && legit[i][j] != 0.0
			 && legit[ii][jj] != 0.0)) ? true : false;
		zcentre = 0.25 * (z[iLE][jLE] + z[iGT][jGT] + z[i][j] + z[ii][jj]);

		if (zcentre <= z0) {
			append_segment(x[iGT], y[jGT], z[iGT][jGT], (legit == NULL)? 1.0: legit[iGT][jGT],
				       vx, vy, zcentre, legit_diag,
				       z0);
			if (z[ii][jj] <= z0) {
				iLE = ii, jLE = jj;
				continue;
			}
			append_segment(x[ii], y[jj], z[ii][jj], (legit == NULL)? 1.0: legit[ii][jj],
				       vx, vy, zcentre, legit_diag,
				       z0);
			if (z[i][j] <= z0) {
				iGT = ii, jGT = jj;
				iLE = i, jLE = j;
				continue;
			}
			append_segment(x[i], y[j], z[i][j], (legit == NULL)? 1.0: legit[i][j],
				       vx, vy, zcentre, legit_diag,
				       z0);
			iGT = i, jGT = j;
			continue;
		}
		append_segment(vx, vy, zcentre, legit_diag,
			       x[iLE], y[jLE], z[iLE][jLE], (legit == NULL)? 1.0: legit[iLE][jLE],
			       z0);
		if (z[i][j] > z0) {
			iGT = i, jGT = j;
			continue;
		}
		append_segment(vx, vy, zcentre, legit_diag,
			       x[i], y[j], z[i][j], (legit == NULL)? 1.0: legit[i][j],
			       z0);
		if (z[ii][jj] <= z0) {
			append_segment(vx, vy, zcentre, legit_diag,
				       x[ii], y[jj], z[ii][jj], (legit == NULL)? 1.0: legit[ii][jj],
				       z0);
			iLE = ii;
			jLE = jj;
			continue;
		}
		iLE = i;
		jLE = j;
		iGT = ii;
		jGT = jj;
	}
}

// append_segment() -- append a line segment on the contour
static double   xplot_last, yplot_last;
static int
append_segment(double xr, double yr, double zr, double OKr,
	       double xs, double ys, double zs, double OKs,
	       double z0)
{
	if (zr == zs) rb_raise(rb_eArgError, "Contouring problem: zr = zs, which is illegal");
	double frac = (zr - z0) / (zr - zs);
	if (frac < 0.0) rb_raise(rb_eArgError, "Contouring problem: frac < 0");
	if (frac > 1.0) rb_raise(rb_eArgError, "Contouring problem: frac > 1");
	double xplot = xr - frac * (xr - xs);
	double yplot = yr - frac * (yr - ys);
	// Avoid replot, which I suppose must be possible, given this code
	if (num_in_curve > 0 && xplot == xplot_last && yplot == yplot_last)
		return 1;
	if (num_in_curve > max_in_curve - 1) {
		// Get new storage if running on empty.  Better to
		// do this with an STL vector class
		max_in_curve *= 2;
		int i;
		double *tmp = ALLOC_N(double, num_in_curve);
		for (i = 0; i < num_in_curve; i++) tmp[i] = xcurve[i];
		free(xcurve); xcurve = ALLOC_N(double, max_in_curve);
		for (i = 0; i < num_in_curve; i++) xcurve[i] = tmp[i];
		for (i = 0; i < num_in_curve; i++) tmp[i] = ycurve[i];
		free(ycurve); ycurve = ALLOC_N(double, max_in_curve);
		for (i = 0; i < num_in_curve; i++) ycurve[i] = tmp[i];
		free(tmp);
		bool *tmpl = ALLOC_N(bool, num_in_curve);
		for (i = 0; i < num_in_curve; i++)	tmpl[i] = legitcurve[i];
		free(legitcurve); legitcurve = ALLOC_N(bool, max_in_curve);
		for (i = 0; i < num_in_curve; i++)	legitcurve[i] = tmpl[i];
		free(tmpl);
	}
	// A segment is appended only if both the present point and the last
	// point came by interpolating between OK points.
	xcurve[num_in_curve] = xplot;
	ycurve[num_in_curve] = yplot;
    if (OKr != 0.0 && OKs != 0.0)
        legitcurve[num_in_curve] = true;
    else
        legitcurve[num_in_curve] = false;
	num_in_curve++;
	xplot_last = xplot;
	yplot_last = yplot;
	return 1;
}


// Draw contour stored in (xcurve[],ycurve[],legitcurve[]), possibly with
// labels (depending on global Label_contours).
// 
// CONTOUR_VALUE MISSING_VALUE
#define FACTOR 3.0 // contour must be FACTOR*len long to be labelled
static void
draw_the_contour(
	   VALUE dest_xs,
	   VALUE dest_ys,
	   VALUE gaps)
{
	if (num_in_curve == 1) {
		num_in_curve = 0;
		return;
	}
	int    i, k;
    for (i = 0, k = 0; i < num_in_curve; i++) {
        if (legitcurve[i] == true) {
            // PUSH_POINT does num_in_path++
            PUSH_POINT(xcurve[i],ycurve[i],num_in_path);
        } else {
            if (num_in_path > 0 && num_in_path != k) rb_ary_push(gaps, INT2FIX(num_in_path));
            k = num_in_path;
            }
    }
    rb_ary_push(gaps, INT2FIX(num_in_path));
    num_in_curve = 0;
}

// FLAG() -- check flag for gr_contour() and trace_contour()
// ni = row (or, if ind==-1, number of rows)
// nj = col (or, if ind==-1, number of cols)
// if (ind == -1), get flag storage space; initialize flags to 0
// if (ind == 1), check flag and then set it
// if (ind == 2), clear the flag storage space
// if (ind == 0), check flag, return value
// RETURN VALUE: Normally, the flag value (0 or 1).  If the storage is
// exhausted, return a number <0.
#define	NBITS		32
static int
FLAG(int ni, int nj, int ind)
{
	static bool     flag_storage_exists = false;
	static unsigned long *flag, mask[NBITS];
	static int      size;
	static int      ni_max;	// x-dimension is saved
	int             i, ipos, iword, ibit, return_value;
	switch (ind) {
	case -1:
		// Allocate storage for flag array
		if (flag_storage_exists)
			rb_raise(rb_eArgError, "storage is messed up (internal error)");
		size = 1 + ni * nj / NBITS;	// total storage array length
		flag = ALLOC_N(unsigned long, size);
		// Create mask
		mask[0] = 1;
		for (i = 1; i < NBITS; i++)
			mask[i] = 2 * mask[i - 1];
		for (i = 0; i < size; i++)	// Zero out flag
			flag[i] = 0;
		ni_max = ni;		// Save for later
		flag_storage_exists = true;
		return 0;
	case 2:
		if (!flag_storage_exists)
			rb_raise(rb_eArgError, "No flag storage exists");
		free(flag);
		flag_storage_exists = false;
		return 0;
	default:
		if (!flag_storage_exists)
			rb_raise(rb_eArgError, "No flag storage exists");
		break;
	}
	// ind was not -1 or 2
	// Find location of bit.
	ipos = nj * ni_max + ni;
	iword = ipos / NBITS;
	ibit = ipos - iword * NBITS;
	// Check for something being broken here, causing to run out of space.
	// This should never happen, but may as well check.
	if (iword >= size)
		return (-99);		// no space
	// Get flag.
	return_value = (0 != (*(flag + iword) & mask[ibit]));
	// If ind=1 and flag wasn't set, set the flag
	if (ind == 1 && !return_value)
		flag[iword] |= mask[ibit];
	// Return the flag value
	return return_value;
}
#undef NBITS

// end of contour code from Gri



   void c_make_contour(FM *p, VALUE dest_xs, VALUE dest_ys, VALUE gaps,
         VALUE xs, VALUE ys,  VALUE zs_data, double z_level,  VALUE legit_data, int use_conrec) {
      long xlen, ylen, num_columns, num_rows;
      double *x_coords = Dvector_Data_for_Read(xs, &xlen);
      double *y_coords = Dvector_Data_for_Read(ys, &ylen);
      double **zs = Dtable_Ptr(zs_data, &num_columns, &num_rows);
      double **legit = Dtable_Ptr(legit_data, &num_columns, &num_rows);
      if (x_coords == NULL || gaps == Qnil || zs == NULL || y_coords == NULL) {
         rb_raise(rb_eArgError, "Sorry: bad args for make_contour.  Need to provide xs, ys, gaps, and zs.");
      }
      if (xlen != num_columns || ylen != num_rows) {
         rb_raise(rb_eArgError, "Sorry: bad args for make_contour.  Needs xs.size == num columns and ys.size == num rows.");
      }
      double x_limit, y_limit;
      x_limit = 0.001*(x_coords[xlen-1] - x_coords[0])/xlen;
      if (x_limit < 0) x_limit = -x_limit;
      y_limit = 0.001*(y_coords[ylen-1] - y_coords[0])/ylen;
      if (y_limit < 0) y_limit = -y_limit;
      
      // NOTE: conrec data is TRANSPOSE of our data, so we switch x's and y's in the call
      if (use_conrec == 1) 
        conrec(zs, 0, num_rows-1, 0, num_columns-1, y_coords, x_coords, 1, &z_level, dest_ys, dest_xs, gaps, y_limit, x_limit);
      else 
        gr_contour(y_coords, x_coords, zs, legit, num_rows, num_columns, z_level, dest_ys, dest_xs, gaps);
      
   }
   
   VALUE FM_private_make_contour(VALUE fmkr,
         VALUE dest_xs, VALUE dest_ys, VALUE gaps, // these Dvectors get the results
         VALUE xs, VALUE ys, // data x coordinates and y coordinates
         VALUE zs, VALUE z_level, // the Dtable of values and the desired contour level
         VALUE legit, // the Dtable of flags (nonzero means okay)
         VALUE method // int == 1 means CONREC
         ) {
      FM *p = Get_FM(fmkr);
      z_level = rb_Float(z_level);
      c_make_contour(p, dest_xs, dest_ys, gaps, xs, ys, zs, NUM2DBL(z_level), legit, NUM2INT(method));
      return fmkr;
   }


