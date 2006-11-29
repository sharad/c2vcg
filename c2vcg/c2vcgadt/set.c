/* @(#)set.c -- Special type of Set Data Structure using "linked basic
		data types" head keeps the initial (number / size of
		bowl), while bowl keep at rest value ( number - head *
		size of bowl) bit position in bowl.

   Copyright (C) 2006 Sharad Pratap

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.
  
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
  
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
*/

# if HAVE_CONFIG_H
#   include <config.h>
# endif
# include "set.h"
# include <stdio.h>
# include <stdlib.h>



# define LOG2STATYPE 2



struct llset  {
  SETP  head;		  /* How much large int could be supported. */
  SETSPACE bowl [LOG2STATYPE];/* Used for bitwise or/and-ing.*/
  struct llset *next;
};

static unsigned int bowlsize = 8 * sizeof (SETSPACE);

static ttyp checkelem (int nu, SETSPACE bowl [])
{
  unsigned int retval = 0;
  int i;
/*   ttyp tmp = 01; */
/*   if (stattype > (tmp <<= (LOG2STATYPE - 1) ) ) */
/*     stattype = tmp; */

  for (i = 0; i < LOG2STATYPE; i++)
    if (bowl [i] & (01 << nu))
      retval |= (01<<i);

  return (ttyp) retval;
}

static ttyp setelem (ttyp stattype, int nu, SETSPACE bowl [])
{
  //  unsigned int stattype = stattype;
  int i;
  //  ttyp tmp = 01;

  if (stattype > (01<<LOG2STATYPE) - 1) { /* new added */
    stattype = (01<<LOG2STATYPE) - 1;     /* if enum sttype used elsewhere */
  }                                       /* than sketchout_edgs may be */
                                          /* LOG2STATYPE = 2 is not useful */
                                          /* as well as if clause also. */
  fflush (stderr);

  for (i = 0; i < LOG2STATYPE; i++)
      if (stattype & (01<<i))
	bowl [i] |= (01<<nu);
      else
	bowl [i] &= ~(01<<nu);

  return (ttyp) stattype;
}

static ttyp clearelem (int nu, SETSPACE bowl [])
{
  return setelem (0, nu, bowl);
}

static ptrSet search_element (SETP ele, ptrSet dest) /* Search ele */
{		       /* On Success return pointer to pointer node */
		       /* In Failure return *ptrSet == NULL            */
  ptrSet itr;
  SETP elm = ele / bowlsize;

  for (itr = dest;
       *itr && !( (*itr) -> head >= elm );
       itr = &((*itr) -> next))
    ;

  return itr;
}


/*  
 *
 */
int insert (ttyp eletype, SETP ele, ptrSet dest)
{

  ttyp k;

# ifdef UNESSARY_CODE
  if (eletype && ele < 0) {
    fprintf (sdterr, "\n%d -tive value "
	     "can not be inserted in Set"
	     , ele);
    exit (-11);
  }
# endif

  ptrSet tmp = search_element (ele, dest);

  if (*tmp == NULL || (*tmp) -> head > ele / bowlsize) {
    int i;
    PosSet hold = (PosSet) malloc (sizeof (struct llset));
    hold -> head = ele / bowlsize;

    for (i = 0; i < LOG2STATYPE; i++)
      hold -> bowl [i] = 0;

  //    hold -> bowl = 0;		/* believing it make all bits = zero */
    hold -> next = *tmp;
    *tmp = hold;
  }

# ifdef CHECKREQ
  if (k = checkelem (ele - (*tmp) -> head * bowlsize, (*tmp)->bowl)) {
    fprintf (stderr, "node %d, stat type %d already in Set", ele, k);
    return ;
  }
# endif

  setelem (eletype, ele - (*tmp) -> head * bowlsize, (*tmp)->bowl);

  return ;			/*  */
}

int delete (SETP ele, ptrSet dest)
{
  SETSPACE bowl = 0;
  ttyp k;
  int i;

  ptrSet tmp = search_element (ele, dest);
  if (*tmp == NULL || (*tmp) -> head > ele / bowlsize) {
# ifdef CHECKREQ
    fprintf (stderr, "%d not in ptrSet", ele);
# endif
    return ;
  } 

# ifdef CHECKREQ
  if ( !(k = checkelem (ele - (*tmp) -> head * bowlsize, (*tmp)->bowl)) ) {
    fprintf (stderr, "%d (%d) already not in ptrSet", ele, k);
    return ;
  }
# endif

  k = clearelem (ele - (*tmp) -> head * bowlsize, (*tmp)->bowl);

# ifdef DEBUG
  fprintf (stderr, "Clearing value %d for %d", k, ele);
# endif

  for (i = 0; i < LOG2STATYPE; i++)
    bowl |= (*tmp) -> bowl [i]; 

  if (bowl == 0) {	  /* check tmp -> bowl 's all bits are off. */
    PosSet freelink = *tmp;
    *tmp = (*tmp) -> next;
# ifdef UNESSARY_CODE
    freelink -> next = NULL;
# endif
    free (freelink);
  }

  return ;
}


# ifdef DEBUG

static int printpset (PosSet t)
{
  SETSPACE b; //scratchpad = t -> bowl;
  SETSPACE count = 0;
  ttyp k;

# ifdef DEBUG
  //  print ("itr -> bowl :   %d", itr -> bowl);
# endif
  printf ("[%d](", t->head);
/*       for (b = 0; scratchpad != 0; scratchpad >>= 1, b++) */
/* 	if (scratchpad & 01) { */
/* 	  printf ("%d,", b  + t -> head * bowlsize); */
/* 	  count ++; */
/* 	} */
  for (b = 0; b < bowlsize; b++)
    if (k = checkelem (b, t -> bowl))
      printf ("%d,", b  + t -> head * bowlsize);

  printf (")");

      return count;
}

static int printlistset (PosSet t)
{
  putchar ('\n');
  for (;t != NULL; t = t->next){
    printpset (t);
    printf (" -> ");
  }
  printf ("NULL\n"); 
}

static int printplist (ptrSet t1, ptrSet t2)
{
  PosSet itr;
  for (itr = *t1; itr != *t2; itr = itr -> next) {
    printpset (itr);
    printf (" -> ");
  }

}

# endif


ptrSet setunion (ptrSet src, ptrSet dest) /* dest will be NULL */
{

  ptrSet itr;
  ptrSet dend = dest;

  ptrSet desttmp = dest;

  PosSet tmp;
  PosSet tmp1;

  //  printlistset (*dest);


  if (!*dest && !*src) return src;
  if (!(*dest && *src)) {
    if (*src) {
      src = dest;
      *dest = NULL;
      return src;
    }
  }
  if (dest == src) {
    printf ("Both are same.");
    printset (*src);
    exit (-11);
    return src;
  }
  //  for (itr = src; *itr != NULL; itr = &((*itr) -> next) ) {
  itr = src; 
  while (*itr != NULL) {

    int i;

    if ( *dest == NULL ) break;

    if ( (*dest) -> head == (*itr) -> head ) {

      for (i = 0; i < LOG2STATYPE; i++)
	(*itr) -> bowl [i] |= (*dest) -> bowl [i];


      //      (*itr) -> bowl |= (*dest) -> bowl;
      tmp = (*dest) -> next;
      free(*dest);
      *dest = tmp;

      itr = &((*itr) -> next);
      continue;
    }
 
    if ( *dest == NULL ) break;

    if ((*dest) -> head < (*itr) -> head) {

      while (*dend != NULL && (*dend) -> head < (*itr) -> head)
	dend = &((*dend) -> next);

      tmp = *itr;
      *itr = *dest;		/* src ok */
      tmp1 = *dend;
      *dend= tmp;		/* src */

      itr = dend;
      dend = dest = &tmp1;		/* later loop */
      continue;
    }

    itr = &((*itr) -> next);
  }

  if (*itr == NULL) *itr = *dest;		/* check */

  *desttmp = NULL;
  return src;
}


int printset (PosSet src)
{
  PosSet itr;
  //  SETSPACE scratchpad;
  SETSPACE b;
  SETSPACE count = 0;
  ttyp k;

  for (itr = src; itr != NULL; itr = itr -> next)
      for (b = 0; b < bowlsize; b++)
	if (k = checkelem (b, itr -> bowl)) {
	    printf ("%d,", b  + itr -> head * bowlsize);
	    count ++;
	    }

  return count;
}

SETP setwalk (int freemem, ptrSet src,
	      unsigned int trgedge,
	      unsigned int trg,
	      unsigned int reverse,
	      int (*action) (int, ttyp, unsigned int,
			     unsigned int, unsigned int))
{
  PosSet itr, tmp;
  int b;
  SETP count = 0;
  ttyp k;


  itr = *src ;
  while (itr != NULL) {
    for (b = 0; b < bowlsize; b++)
      if (k = checkelem (b, itr -> bowl)) {
	action (b  + itr -> head * bowlsize, k, trgedge, trg, reverse);
	count ++;
      }

    tmp = itr;
    itr = itr ->  next;
    
    if (free != 0)
      free (tmp);
  }

  *src = NULL;
  return count;
}


SETP setwalkfree (ptrSet src,
		  unsigned int trgedge,
		  unsigned int trg,
		  unsigned int reverse,
		  int (*action) (int, ttyp, unsigned int,
				 unsigned int, unsigned int))
{
  return setwalk (1, src, trgedge, trg, reverse, action);
}
