/* @(#)setmain.c
 */

/* # include <stdio.h> */

/* # include <readline/readline.h> */
/* # include <readline/history.h> */

typedef struct llset *PosSet;

PosSet list0 = NULL;
PosSet list1 = NULL;



main  ()
{
  char *itr, lista [6];
  char prompt [] = "list [0]";
  char *line;
  int i, list, tmp;
  list = 0;
  line = NULL;
  do {
    //    sprintf (//"[I]nsert, [D]elete, [U]nion, [P]rint, [C]hange"
    //	    "list [%d]: ", list);
    free (line);
    line = readline (prompt);
    //    scanf ("%c", &c);
    for (itr = line; *itr == ' '; itr++);
 
    switch (*itr)
      {
      case 'i':
	putchar ('\t'); putchar ('\t');
	while (1) {
	  scanf ("%d", &i );
	  if (i < 0) break;
	  insert (3, i, list ? &list1 : &list0);
	}
	putchar ('\n');
	break;
      case 'd':
	putchar ('\t'); putchar ('\t');
	printf ("delete: ");
	scanf ("%d", &i );
	delete (i, list ? &list1 : &list0);
	break;
      case 'p':
	putchar ('\t'); putchar ('\t');
	//	printset (list ? &list1 : &list0);
	printf ("\ttotal %d in list [%d]",
		printset (list ? &list1 : &list0),
		list);
	putchar ('\n');
	break;
      case 'c':
	list = (list ? 0 : 1); 
	sprintf (prompt, "list [%d]: ", list);
/* 	putchar ('\t'); putchar ('\t');	 */
/* 	scanf ("%s", lista); tmp = atoi (lista); */
/* 	if (list == 0 || list == 1) { */
/* 	  list = tmp; */
/* 	  sprintf (prompt, "list [%d]: ", list);  */
/* 	} */
	//else
	//  printf ("taking [%d] as current list", list);
	break;
      case 'u':
	setunion (&list0, &list1);
	putchar ('\n');
	break;
      case 'q': case 'Q': 
	exit (0);
      }
    //    if (c != '\n') getchar ();
  } while (*itr != 'q');
}

