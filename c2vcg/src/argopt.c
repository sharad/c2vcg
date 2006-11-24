/* @(#)argopt.c -- 
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

#if HAVE_CONFIG_H
#  include <config.h>
#endif


# include <stdlib.h>
# include <error.h>
# include <argp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "c2vcg.h"		/* for PROGNAMEV */

#include <system.h>

#define EXIT_FAILURE 1

#if ENABLE_NLS
# include <libintl.h>
# define _(Text) gettext (Text)
#else
# define textdomain(Domain)
# define _(Text) Text
#endif
#define N_(Text) Text

/* char *xmalloc (); */
/* char *xrealloc (); */
/* char *xstrdup (); */

//# define ARGP_NO_EXIT 10

//const char *argp_program_bug_address = PROGBUGADD;//c2vcg_bug_address;
//"sh4r4d@gmail.com";
/* The argp functions examine these global variables.  */
const char *argp_program_bug_address = "<sh4r4d@gmail.com>";

static error_t parse_opt (int key, char *arg, struct argp_state *state);
static void show_version (FILE *stream, struct argp_state *state);

void (*argp_program_version_hook) (FILE *, struct argp_state *) = show_version;



/* Program documentation. */
static char doc[] = PACKAGE" -- Expresses C program in Graphical Control "
                    "Flow Chart in VCG GDL, with the major help of VCG."
                    "\vSee the manual of VCG for Displaying it good and"
                    " see the log.c2vcg seeing the debugging output, as"
                    " well as see ChangLog.";

/* static char doc[] = PACKAGE" -- Display graphically Control Flow Graph/" */
/*                     "Chart of C programs with the major help of VCG." */
/*                     "\vSee the manual of VCG for Displaying it good and" */
/*                     " see the log.c2vcg seeing the debugging output, as" */
/*                     " well as see ChangLog."; */

/* A description of the arguments we accept. */
static char args_doc[] = "infile";
//static char args_doc[] = "ARG1 [string...]";

/* Keys for options without short-options. */
# define OPT_ABORT  1            /* -abort */
# define OPT_GONEDG 2

/* The options we understand. */
static struct argp_option options[] = {
  {"verbose",  'v', 0, 0, "Produce verbose output" },
  {"quiet",    'q', 0, 0, "Don't produce any output" },
  //  {"silent",   's', 0,       OPTION_ALIAS },
  {"output",   'o', "outfile",  0,
   "Output to outfile instead of standard output" },
  {"node",     'n', "+number", 0, "+ve Node number"},
  {"xspace",   'x', "+number", 0, "+ve X length"},
  {"yspace",   'y', "+number", 0, "+ve Y length"},
  {"semicol",  's', "0|1", /* 0 */ OPTION_ARG_OPTIONAL, "Show semicolon"},
  {"caseq",   'c', "+[number]|0|-[number]", /*0*/ OPTION_ARG_OPTIONAL,
   "0 for sequential flow in switch statement,"
   "non zero for parallel flow from switch to "
   "case's, -/+ve for not/fixing case box on s"
   "ame level."
  },
  {"pnode",    'p', "0|1", /* 0 */ OPTION_ARG_OPTIONAL, "Print node number"},
  {"gonedge",  OPT_GONEDG, "0|1", /* 0 */ OPTION_ARG_OPTIONAL, "Set goto -> stat nearedge"},
# ifdef DEBUG
  {"debug",    'D', "FILE",  0, "Debugging Output File"},
# endif

  {"joincase",  'j', "+[number]|0|-[number]", /* 0 */ OPTION_ARG_OPTIONAL,
   "non zero for joining consecutive case's, -"
   "/+ve for joining on same/seperate line, case's"
  },
  {"subgraph",  'g', "0|1|2|3", /*0*/ OPTION_ARG_OPTIONAL,
   "enable subgraph, 0 no subgraph,1 statement "
   "only subgraph, 2 external declaration subgr"
   "aph (functions, declaration/definiti"
   "on of global variables, 3 both."
  },
  {"hight",    'h', "+number", 0 /*OPTION_ARG_OPTIONAL*/, "Graph hight"},
  {"width",    'w', "+number", 0 /*OPTION_ARG_OPTIONAL*/, "Graph width"},
  {"include",  'I', "directory", OPTION_ARG_OPTIONAL, "Include directory"},
  {"echo",     'e', "outfile", OPTION_ARG_OPTIONAL, "Echo C Sources"},
  {0,0,0,0, "The following options should be grouped together:" },

  {"repeat",   'r', "COUNT", OPTION_ARG_OPTIONAL,
   "Repeat the output COUNT (default 10) times"},
  {"abort",    OPT_ABORT, 0, 0, "Abort before showing any output"},
  
  { 0 }
};

/* static struct argp argp = */
/* { */
/*   options, parse_opt, N_("[FILE...]"), */
/*   N_("express C program in Graphical Flow Chart in VCG GDL."), */
/*   NULL, NULL, NULL */
/* }; */

/* Our argp parser. */
//extern struct argp argp;
static struct argp argp = { options, parse_opt, args_doc, doc };


int check_ofile (const char *filename);

/* Parse a single option. */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  /* Get the `input' argument from `argp_parse', which we
     know is a pointer to our arguments structure. */
  void enqueue (char *ptr, void **ptrclg);
  //  int isnum (char *num);
  int numval;
  int isarg = 0;
  char *tofree;

  struct arguments *ptrargs = state->input;
  
  switch (key)
    {
    case 'q':
      ptrargs->silent = 1;
      break;

    case 'v':
      ptrargs->verbose = 1;
      break;

    case 's':
      if (!arg)
	ptrargs->semicolon = 0;
      else if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) && numval != 1)
	argp_error (state, "option reuired a 0 or 1 numeric"
		    " argument -- %c", key);
      else
	ptrargs->semicolon = numval;
      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

    case 'p':
      if (!arg)
	ptrargs->print_node = 1;
      else if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) && numval != 1)
	argp_error (state, "option reuired a 0 or 1 numeric"
		    " argument -- %c", key);
      //	argp_usage (state);
      else
	ptrargs->print_node = numval;

      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

/*     case 'c': */
/*       if (isarg = isalpha (*arg) || isdigit (*arg) &&  */
/* 	  (numval = atoi (arg)) && numval != 1) */
/* 	argp_error (state, "option reuired a 0 or 1 numeric" */
/* 		    " argument -- %c", key); */
/*       //	argp_usage (state); */
/*       else */
/* 	ptrargs->caseq = numval; */
/*       if (isarg) enqueue (arg, &(ptrargs->clg)); */
/*       break; */

    case OPT_GONEDG:
      if (!arg)
	ptrargs->gotonear = 0;
      else if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) && numval != 1)
	argp_error (state, "option reuired 0 or 1 numeric"
		    " argument -- %c", key);
      //	argp_usage (state);
      else
	ptrargs->gotonear = numval;
      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

    case 'n':
      if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) < 0)
	argp_error (state, "option reuired a non-negative numeric"
		    " argument -- %c", key);
	//	argp_usage (state);
      else
	ptrargs->node = numval;
      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

    case 'x':
      if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) < 0)
	argp_error (state, "option reuired a non-negative numeric"
		    " argument -- %c", key);
	//	argp_usage (state);
      else
	ptrargs->xspace = numval;
      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

    case 'y':
      if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) < 0)
	argp_error (state, "option reuired a non-negative numeric"
		    " argument -- %c", key);
	//	argp_usage (state);
      else
	ptrargs->yspace = numval;
      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

    case 'j':
      //      if (isarg = isalpha (*arg) || !isdigit (*arg))
      //      if (isarg = isalpha (*arg) || !isnum (arg))
      if (!arg)
	ptrargs -> casejoin = 0;
      else if (isarg = isalpha (*arg)
	       || ! ( isdigit (*arg) || *arg == '+' || *arg == '-'))
	argp_error (state, "option reuired a [+num|0|-num] numeric"
		    " argument -- %c", key);
      else if (!isdigit (*arg))
	ptrargs->casejoin = 44 - *arg;
      else
	ptrargs->casejoin = atoi (arg);
      
      if (isarg) enqueue (arg, &(ptrargs->clg));

      break;

    case 'c':
      //      if (isarg = isalpha (*arg) || !isdigit (*arg))
      //      if (isarg = isalpha (*arg) || !isnum (arg))
      if (!arg)
	ptrargs->caseq = -1;
      else if (isarg = isalpha (*arg)
	  || ! ( isdigit (*arg) || *arg == '+' || *arg == '-'))
	argp_error (state, "option reuired a [+num|0|-num] numeric"
		    " argument -- %c", key);
      else if (!isdigit (*arg))
	ptrargs->caseq = 44 - *arg;
      else
	ptrargs->caseq = atoi (arg);
      
      if (isarg) enqueue (arg, &(ptrargs->clg));

      break;

    case 'g':
      if (!arg)
	ptrargs -> forms = 3;
      else if (isarg = isalpha (*arg)
	  || !(*arg > 47 && *arg < 52))
	argp_error (state, "option reuired a 0|1|2|3 numeric"
		    " argument -- %c", key);
      else
	ptrargs->forms = *arg - 48;

      if (isarg) enqueue (arg, &(ptrargs->clg));

      break;

    case 'h':
      if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) < 0)
	argp_error (state, "option reuired a non-negative numeric"
		    " argument -- %c", key);
	//	argp_usage (state);
      else
	ptrargs->hight = atoi (arg);
      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

    case 'w':
      if (isarg = isalpha (*arg) || isdigit (*arg) && 
	  (numval = atoi (arg)) < 0)
	argp_error (state, "option reuired a non-negative numeric"
		    " argument -- %c", key);
	//	argp_usage (state);
      else
      ptrargs->width = atoi (arg);
      if (isarg) enqueue (arg, &(ptrargs->clg));
      break;

    case 'o':
      pgmargs.gdl2file = 1;
      //if (!strcmp (arg, "-") || check_ofile (arg))
      if (strcmp (arg, "-"))
	ptrargs->output_file = arg;
      //      else
      //	exit (0);
      break;

    case 'I':
      //      pgmargs.prepx = 1;
      tofree = ptrargs -> ppinclude;
      if (arg) {
	asprintf (&(ptrargs->ppinclude), "%s -I%s",
			 ptrargs->ppinclude ? 
			 ptrargs->ppinclude : "", arg);
	free (tofree);
      } else
	asprintf (&(ptrargs->ppinclude), "%s -I.",
		  ptrargs->ppinclude ? 
		  ptrargs->ppinclude : "");

      break;

# ifdef DEBUG
    case 'D':
      //      pgmargs.prepx = 1;
      ptrargs->debug_ofile = arg;
      break;
# endif

    case 'e':
      //      pgmargs.prepx = 1;
      ptrargs->echo = 1;
      if (arg) ptrargs->echo_file = arg;
      break;

    case 'r':
      ptrargs->repeat_count = arg ? atoi (arg) : 10;
      break;

    case OPT_ABORT:
      ptrargs->abort = 1;
      break;
      
    case ARGP_KEY_NO_ARGS:
      argp_usage (state);
      
    case ARGP_KEY_ARG:
      /* Here we know that `state->arg_num == 0', since we
	 force argument parsing to end before any more argu can
	 get here. */
      /* argu->clg = */ enqueue (arg, &(ptrargs->clg));
      
      /* Now we consume all the rest of the argu.
	 `state->next' is the index in `state->argv' of the
	 next argument to be parsed, which is the first string
	 we're interested in, so we can just use
	 `&state->argv[state->next]' as the value for
	 argu->strings.
	 
	 _In addition_, by setting `state->next' to the end
	 of the argu, we can force argp to stop parsing here and
	 return. */
    //      ptrargs->strings = &state->argv[state->next];
    //      state->next = state->argc;
      
      break;
      
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

int parseclg (int ac, char **av)
{
    
    /* Default values. */
  pgmargs.silent  = 0;
  pgmargs.verbose = 0;
  pgmargs.node = ~0;
  pgmargs.semicolon = pgmargs.gotonear = 1;
  pgmargs.echo = 0;
  pgmargs.echo_file = "-";
  pgmargs.print_node = 0;

  pgmargs.casejoin = 1;
  pgmargs.caseq = 0;
  pgmargs.forms = 1;

  pgmargs.xspace = 34;
  pgmargs.yspace = 50;
  pgmargs.hight = 700;
  pgmargs.width = 700;
  pgmargs.gdl2file = 0;
  pgmargs.output_file = "-";
  pgmargs.debug_ofile = NULL;
  pgmargs.ppinclude = NULL;
  pgmargs.repeat_count = 1;
  pgmargs.abort = 0;
  
  
  /* Parse our argu; every option seen by `parse_opt' will be
     reflected in `argu'. */
  argp_parse (&argp, ac, av, 0/*ARGP_NO_EXIT*/, 0, &pgmargs);
  
  if (pgmargs.abort)
    error (10, 0, "ABORTED");
}

/* Show the version number and copyright information.  */
static void
show_version (FILE *stream, struct argp_state *state)
{
  (void) state;
  /* Print in small parts whose localizations can hopefully be copied
     from other programs.  */
  fputs(PACKAGE" "VERSION"\n", stream);
  fprintf(stream, _("Written by %s.\n\n"), "Sharad Pratap");
  fprintf(stream, _("Copyright (C) %s %s\n"), "2006", "Sharad Pratap");
  fputs(_("\
This program is free software; you may redistribute it under the terms of\n\
the GNU General Public License.  This program has absolutely no warranty.\n"),
	stream);
}


# include <list.h>

struct cmlarg {
  struct cmlarg *next;
  char *copy;
};

//void push (unsigned int node, char *ptr, struct casnode **ptrcasroot)
void enqueue (char *ptr, void **ptrclg)
{
  struct cmlarg *tmp = XMALLOC (struct cmlarg, 1);
  tmp -> next = NULL;
  tmp -> copy = ptr;

  *ptrclg = list_app ((List *) tmp, (List *) *ptrclg);
}

//unsigned int pop (char **string, struct casnode **ptrcasroot)
char *dequeue (void **ptrclg)
{
  struct cmlarg *retval =  *ptrclg;
  //char *retstring;
  if (retval == NULL) return NULL; /* stack finish */

  *ptrclg = ((struct cmlarg *) (*ptrclg)) -> next;
  //*string = retval -> copy;
  //XFREE (retval);
  //return retstring;
  return retval -> copy;			
}

/* int isnum (char *num) */
/* { */
/*   while (num) { */
/*     //if ( ! (num != '-'|| num  != '+' || !isdigit (*num)) ) */
/*     if (num == '-'&& num  == '+'  && isdigit (*num))  */
/*       return 0; */
/*     num++; */
/*   } */
/*   return 1; */
/* } */
