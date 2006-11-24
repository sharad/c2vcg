/* @(#)list.c -- maintain lists of types with forward pointer fields
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
# include "list.h"

/** @start 1 */

/* List * */
/* list_new (void *userdata) */
/* { */
/*   List *new = XMALLOC (List, 1); */

/*   new->next = NULL; */
/*   new->userdata = userdata; */

/*   return new; */
/* } */

List *
list_cons (List *head, List *tail)
{
  head->next = tail;
  return head;
}

List *
list_app (List *tail, List *head)
{
  List **tmp;
  for (tmp = &head; *tmp != NULL; tmp = &((*tmp) -> next))
    ;
  *tmp = tail;
  return head;
}

/* List * */
/* list_tail (List *head) */
/* { */
/*   return head->next; */
/* } */

/* size_t */
/* list_length (List *head) */
/* { */
/*   size_t n; */
  
/*   for (n = 0; head; ++n) */
/*     head = head->next; */

/*   return n; */
/* } */

/* int list_print (List *head, void (*action) (void *)) */
/* { */
/*   int count = 0; */
/*   List *tmp; */
/*   for (tmp = head; tmp != NULL; tmp = tmp -> next) { */
/*     action (tmp); */
/*     count ++; */
/*   } */
/*   return count; */
/* } */
/* /\** @end 1 *\/ */


/* typedef struct foo_s foot; */

/* struct foo { */
/*   struct foo *next; */
/*   int i; */
/* }; */


/* struct foo *foo_new (int  userdata) */
/* { */
/*   struct foo *new = (struct foo *) XMALLOC (struct foo, 1); */

/*   new->next = NULL; */
/*   new->i = userdata; */

/*   return new; */
/* } */

/* void print_foo (struct foo *tfoo) */
/* { */
/*   printf ("%d, ", tfoo->i); */
/* } */


/* # include <readline/readline.h> */
/* # include <readline/history.h> */

/* main () */
/* { */

/*   struct foo *list0 = NULL; */
/*   struct foo *list1 = NULL; */
/*   char *itr, lista [6]; */
/*   char prompt [] = "list [0]"; */
/*   char *line; */
/*   int i, list, tmp; */
/*   list = 0; */
/*   line = NULL; */
/*   do { */

/*     free (line); */
/*     line = readline (prompt); */

/*     for (itr = line; *itr == ' '; itr++); */
 
/*     switch (*itr) */
/*       { */
/*       case 'i': */
/* 	putchar ('\t'); putchar ('\t'); */
/* 	while (1) { */
/* 	  scanf ("%d", &i ); */
/* 	  if (i < 0) break; */

/* 	  if (list) */
/* 	    list1 = (struct foo *) list_cons ((List *) foo_new (i), list1); */
/* 	  else */
/* 	    list0 = (struct foo *) list_cons ((List *) foo_new (i), list0); */
/* 	} */
/* 	putchar ('\n'); */
/* 	break; */
/*       case 'd': */
/* 	putchar ('\t'); putchar ('\t'); */
/* 	printf ("delete: "); */
/* 	scanf ("%d", &i ); */
/* 	//delete (i, list ? &list1 : &list0); */
/* 	break; */
/*       case 'p': */
/* 	putchar ('\t'); putchar ('\t'); */
/* 	//	printset (list ? &list1 : &list0); */
/* 	printf ("\ttotal %d in list [%d]", */
/* 		list_print (list ? list1 : list0, print_foo), */
/* 		list); */
/* 	putchar ('\n'); */
/* 	break; */
/*       case 'c': */
/* 	list = (list ? 0 : 1);  */
/* 	sprintf (prompt, "list [%d]: ", list); */
/* 	break; */
/*       case 'u': */
/* 	//setunion (&list0, &list1); */
/* 	putchar ('\n'); */
/* 	break; */
/*       case 'q': case 'Q':  */
/* 	exit (0); */
/*       } */
/*     //    if (c != '\n') getchar (); */
/*   } while (*itr != 'q'); */
/* } */
