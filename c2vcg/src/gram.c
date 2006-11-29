/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELIPSIS = 303,
     RANGE = 304,
     CASE = 305,
     DEFAULT = 306,
     IF = 307,
     ELSE = 308,
     SWITCH = 309,
     WHILE = 310,
     DO = 311,
     FOR = 312,
     GOTO = 313,
     CONTINUE = 314,
     BREAK = 315,
     RETURN = 316,
     FILEEND = 317
   };
#endif
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define CONST 297
#define VOLATILE 298
#define VOID 299
#define STRUCT 300
#define UNION 301
#define ENUM 302
#define ELIPSIS 303
#define RANGE 304
#define CASE 305
#define DEFAULT 306
#define IF 307
#define ELSE 308
#define SWITCH 309
#define WHILE 310
#define DO 311
#define FOR 312
#define GOTO 313
#define CONTINUE 314
#define BREAK 315
#define RETURN 316
#define FILEEND 317




/* Copy the first part of user declarations.  */
#line 25 "gram.y"

#if HAVE_CONFIG_H
#  include <config.h>
#endif

# include <stdio.h>
# include <string.h>

# include "c2vcg.h"
# include "memmgm.h"
# include "output.h"


# define BEGINSUBGRPH(ntrml) if (pgmargs.forms & (01 << (ntrml - 1))) {\
                                nlindenting (subgrphdepth++, gdlout);\
                                fputs ("graph: {", gdlout);\
                                nlindenting (subgrphdepth, gdlout);\
                                fprintf (gdlout, "title: \"graph %d\"",\
                                         subgraph++);\
                             }

# define ENDSUBGRPH(ntrml)   if (pgmargs.forms & (01 << (ntrml - 1))) {\
                               nlindenting (subgrphdepth--, gdlout);\
                               fputs ("}", gdlout);\
                             }

# define FUNSFRM   1
# define STATSFRM  2
/* # define ALLSFRM     3 */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 56 "gram.y"
typedef union YYSTYPE { Stat *stat; } YYSTYPE;
/* Line 191 of yacc.c.  */
#line 233 "gram.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 245 "gram.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1308

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  72
/* YYNRULES -- Number of rules. */
#define YYNRULES  227
/* YYNRULES -- Number of states. */
#define YYNSTATES  380

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,     2,     2,    63,    70,     2,
      77,    78,    71,    66,    67,    65,    85,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    68,
      83,    79,    82,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    84,    76,    86,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    19,
      23,    25,    28,    31,    35,    37,    40,    42,    45,    47,
      50,    52,    55,    57,    59,    61,    63,    65,    67,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    93,    99,   104,   107,   109,   111,   113,   116,   118,
     122,   124,   128,   132,   134,   137,   139,   142,   144,   148,
     150,   153,   157,   162,   168,   171,   173,   177,   179,   183,
     185,   188,   190,   194,   198,   203,   207,   212,   217,   219,
     222,   225,   229,   231,   234,   236,   240,   242,   246,   249,
     252,   254,   256,   260,   262,   266,   271,   273,   277,   279,
     282,   284,   286,   289,   293,   296,   300,   304,   309,   312,
     316,   320,   325,   326,   329,   331,   333,   335,   337,   339,
     341,   344,   349,   353,   355,   358,   361,   365,   369,   374,
     376,   379,   385,   393,   394,   401,   407,   415,   422,   430,
     438,   447,   455,   464,   473,   483,   487,   490,   493,   496,
     500,   502,   504,   506,   510,   512,   516,   518,   520,   522,
     524,   526,   528,   530,   532,   534,   536,   538,   540,   546,
     548,   550,   554,   556,   560,   562,   566,   568,   572,   574,
     578,   580,   584,   588,   590,   594,   598,   602,   606,   608,
     612,   616,   618,   622,   626,   628,   632,   636,   640,   642,
     647,   649,   652,   655,   658,   661,   666,   668,   670,   672,
     674,   676,   678,   680,   685,   689,   694,   698,   702,   705,
     708,   710,   712,   714,   718,   720,   723,   725
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
      88,     0,    -1,    89,    -1,    88,    89,    -1,    -1,    90,
      91,    -1,    92,    -1,    94,    -1,   112,    93,    -1,    96,
     112,    93,    -1,   130,    -1,    95,   130,    -1,    96,    68,
      -1,    96,   103,    68,    -1,    94,    -1,    95,    94,    -1,
      97,    -1,    97,    96,    -1,    98,    -1,    98,    96,    -1,
      99,    -1,    99,    96,    -1,    29,    -1,    30,    -1,    31,
      -1,    32,    -1,    33,    -1,    44,    -1,    34,    -1,    35,
      -1,    36,    -1,    37,    -1,    40,    -1,    41,    -1,    38,
      -1,    39,    -1,   100,    -1,   109,    -1,    28,    -1,    42,
      -1,    43,    -1,   101,   136,    75,   102,    76,    -1,   101,
      75,   102,    76,    -1,   101,   136,    -1,    45,    -1,    46,
      -1,   105,    -1,   102,   105,    -1,   104,    -1,   103,    67,
     104,    -1,   112,    -1,   112,    79,   120,    -1,   106,   107,
      68,    -1,    98,    -1,    98,   106,    -1,    99,    -1,    99,
     106,    -1,   108,    -1,   107,    67,   108,    -1,   112,    -1,
      69,   141,    -1,   112,    69,   141,    -1,    47,    75,   110,
      76,    -1,    47,   136,    75,   110,    76,    -1,    47,   136,
      -1,   111,    -1,   110,    67,   111,    -1,   136,    -1,   136,
      79,   141,    -1,   113,    -1,   114,   113,    -1,   136,    -1,
      77,   112,    78,    -1,   113,    73,    74,    -1,   113,    73,
     141,    74,    -1,   113,    77,    78,    -1,   113,    77,   116,
      78,    -1,   113,    77,   119,    78,    -1,    71,    -1,    71,
     115,    -1,    71,   114,    -1,    71,   115,   114,    -1,    99,
      -1,   115,    99,    -1,   117,    -1,   117,    67,    48,    -1,
     118,    -1,   117,    67,   118,    -1,    96,   112,    -1,    96,
     123,    -1,    96,    -1,   136,    -1,   119,    67,   136,    -1,
     138,    -1,    75,   121,    76,    -1,    75,   121,    67,    76,
      -1,   120,    -1,   121,    67,   120,    -1,   106,    -1,   106,
     123,    -1,   114,    -1,   124,    -1,   114,   124,    -1,    77,
     123,    78,    -1,    73,    74,    -1,    73,   141,    74,    -1,
     124,    73,    74,    -1,   124,    73,   141,    74,    -1,    77,
      78,    -1,    77,   116,    78,    -1,   124,    77,    78,    -1,
     124,    77,   116,    78,    -1,    -1,   126,   127,    -1,   128,
      -1,   129,    -1,   130,    -1,   132,    -1,   134,    -1,   135,
      -1,   136,    69,    -1,    50,   141,    69,   125,    -1,    51,
      69,   125,    -1,    68,    -1,   137,    68,    -1,    75,    76,
      -1,    75,   131,    76,    -1,    75,    95,    76,    -1,    75,
      95,   131,    76,    -1,   125,    -1,   131,   125,    -1,    52,
      77,   137,    78,   125,    -1,    52,    77,   137,    78,   125,
      53,   125,    -1,    -1,   133,    54,    77,   137,    78,   125,
      -1,    55,    77,   137,    78,   125,    -1,    56,   125,    55,
      77,   137,    78,    68,    -1,    57,    77,    68,    68,    78,
     125,    -1,    57,    77,    68,    68,   137,    78,   125,    -1,
      57,    77,    68,   137,    68,    78,   125,    -1,    57,    77,
      68,   137,    68,   137,    78,   125,    -1,    57,    77,   137,
      68,    68,    78,   125,    -1,    57,    77,   137,    68,    68,
     137,    78,   125,    -1,    57,    77,   137,    68,   137,    68,
      78,   125,    -1,    57,    77,   137,    68,   137,    68,   137,
      78,   125,    -1,    58,   136,    68,    -1,    59,    68,    -1,
      60,    68,    -1,    61,    68,    -1,    61,   137,    68,    -1,
       3,    -1,    28,    -1,   138,    -1,   137,    67,   138,    -1,
     140,    -1,   153,   139,   138,    -1,    79,    -1,    18,    -1,
      19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,   142,    -1,
     142,    81,   137,    69,   140,    -1,   140,    -1,   143,    -1,
     142,    17,   143,    -1,   144,    -1,   143,    16,   144,    -1,
     145,    -1,   144,    84,   145,    -1,   146,    -1,   145,    72,
     146,    -1,   147,    -1,   146,    70,   147,    -1,   148,    -1,
     147,    14,   148,    -1,   147,    15,   148,    -1,   149,    -1,
     148,    83,   149,    -1,   148,    82,   149,    -1,   148,    12,
     149,    -1,   148,    13,   149,    -1,   150,    -1,   149,    10,
     150,    -1,   149,    11,   150,    -1,   151,    -1,   150,    66,
     151,    -1,   150,    65,   151,    -1,   152,    -1,   151,    71,
     152,    -1,   151,    80,   152,    -1,   151,    63,   152,    -1,
     153,    -1,    77,   122,    78,   152,    -1,   155,    -1,     8,
     153,    -1,     9,   153,    -1,   154,   152,    -1,     6,   153,
      -1,     6,    77,   122,    78,    -1,    70,    -1,    71,    -1,
      66,    -1,    65,    -1,    86,    -1,    64,    -1,   156,    -1,
     155,    73,   137,    74,    -1,   155,    77,    78,    -1,   155,
      77,   158,    78,    -1,   155,    85,   136,    -1,   155,     7,
     136,    -1,   155,     8,    -1,   155,     9,    -1,   136,    -1,
       4,    -1,   157,    -1,    77,   137,    78,    -1,     5,    -1,
     157,     5,    -1,   138,    -1,   158,    67,   138,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   113,   113,   115,   119,   119,   125,   127,   140,   164,
     188,   190,   195,   199,   208,   212,   218,   221,   227,   229,
     235,   237,   246,   247,   248,   249,   250,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   269,
     270,   274,   278,   281,   287,   288,   292,   294,   300,   302,
     308,   310,   316,   322,   324,   328,   330,   336,   338,   344,
     346,   349,   355,   359,   363,   369,   371,   377,   379,   385,
     387,   393,   395,   398,   401,   404,   407,   410,   417,   419,
     422,   425,   431,   433,   439,   441,   447,   449,   455,   458,
     461,   467,   469,   475,   477,   480,   486,   488,   496,   498,
     509,   511,   513,   521,   525,   527,   531,   535,   539,   541,
     545,   549,   561,   561,   567,   568,   569,   570,   571,   572,
     576,   601,   632,   665,   670,   680,   690,   692,   711,   726,
     728,   751,   783,   807,   807,   880,   899,   932,   958,   993,
    1024,  1055,  1088,  1123,  1157,  1201,  1218,  1227,  1236,  1244,
    1257,  1259,  1263,  1265,  1272,  1274,  1282,  1290,  1291,  1292,
    1293,  1294,  1295,  1296,  1297,  1298,  1299,  1303,  1305,  1313,
    1317,  1319,  1328,  1330,  1339,  1341,  1349,  1351,  1360,  1362,
    1370,  1372,  1379,  1388,  1390,  1395,  1400,  1407,  1416,  1418,
    1425,  1434,  1436,  1442,  1451,  1453,  1459,  1465,  1473,  1475,
    1483,  1485,  1491,  1497,  1503,  1509,  1517,  1519,  1521,  1523,
    1525,  1527,  1532,  1534,  1540,  1543,  1549,  1554,  1561,  1567,
    1575,  1577,  1580,  1582,  1586,  1588,  1602,  1604
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELIPSIS", "RANGE",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "FILEEND", "'%'", "'!'", "'-'", "'+'",
  "','", "';'", "':'", "'&'", "'*'", "'^'", "'['", "']'", "'{'", "'}'",
  "'('", "')'", "'='", "'/'", "'?'", "'>'", "'<'", "'|'", "'.'", "'~'",
  "$accept", "translation_unit", "external_declaration", "@1",
  "external_declaration0", "function_definition", "function_body",
  "declaration", "declaration_list", "declaration_specifiers",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "init_declarator_list", "init_declarator",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "@2", "statement0",
  "labeled_statement", "expression_statement", "compound_statement",
  "statement_list", "selection_statement", "@3", "iteration_statement",
  "jump_statement", "identifier", "expr", "assignment_expr",
  "assignment_operator", "conditional_expr", "constant_expr",
  "logical_or_expr", "logical_and_expr", "inclusive_or_expr",
  "exclusive_or_expr", "and_expr", "equality_expr", "relational_expr",
  "shift_expr", "additive_expr", "multiplicative_expr", "cast_expr",
  "unary_expr", "unary_operator", "postfix_expr", "primary_expr",
  "string_litr", "argument_expr_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    37,    33,    45,    43,    44,    59,    58,
      38,    42,    94,    91,    93,   123,   125,    40,    41,    61,
      47,    63,    62,    60,   124,    46,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    87,    88,    88,    90,    89,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   106,   106,   106,   106,   107,   107,   108,
     108,   108,   109,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   119,   119,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   126,   125,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   129,   129,   130,   130,   130,   130,   131,
     131,   132,   132,   133,   132,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   140,   140,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     149,   150,   150,   150,   151,   151,   151,   151,   152,   152,
     153,   153,   153,   153,   153,   153,   154,   154,   154,   154,
     154,   154,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   156,   156,   156,   157,   157,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     3,
       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     2,     1,     1,     1,     2,     1,     3,
       1,     3,     3,     1,     2,     1,     2,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       2,     1,     3,     3,     4,     3,     4,     4,     1,     2,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     1,     3,     4,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     1,     2,     2,     3,     3,     4,     1,
       2,     5,     7,     0,     6,     5,     7,     6,     7,     7,
       8,     7,     8,     8,     9,     3,     2,     2,     2,     3,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     4,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     2,
       1,     1,     1,     3,     1,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       4,     4,     2,     0,     1,     3,   150,   151,    22,    23,
      24,    25,    26,    28,    29,    30,    31,    34,    35,    32,
      33,    39,    40,    27,    44,    45,     0,    78,     0,     5,
       6,     7,     0,    16,    18,    20,    36,     0,    37,     0,
      69,     0,    71,   151,     0,    64,    82,    80,    79,     0,
      12,     0,    48,    50,    38,    17,    19,    21,     0,    43,
     112,     8,    14,     0,     0,    10,     0,     0,    70,     0,
      65,    67,     0,    83,    81,    72,     0,    13,     0,     9,
      53,    55,     0,    46,     0,     0,   125,   112,   129,   133,
     112,    15,    11,    50,   221,   224,     0,     0,     0,   211,
     209,   208,   206,   207,    73,     0,   210,   220,   169,     0,
     167,   170,   172,   174,   176,   178,   180,   183,   188,   191,
     194,   198,     0,   200,   212,   222,    75,    90,     0,    84,
      86,     0,    91,     0,    62,     0,     0,    49,     0,    51,
      93,   154,   198,    54,    56,    42,    47,     0,     0,    57,
      59,     0,   127,   112,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,   123,   113,   114,   115,   116,   117,
       0,   118,   119,   220,     0,   152,   126,   130,     0,   204,
       0,   201,   202,    98,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,   218,   219,
       0,     0,     0,   225,     0,     0,    88,   100,    89,   101,
      76,     0,     0,    77,    66,    68,    63,    96,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   156,
       0,    60,     0,    52,     0,    41,   128,     0,   112,     0,
       0,     0,     0,     0,   146,   147,   148,     0,     0,   120,
       0,   124,     0,     0,   100,    99,     0,   223,   171,     0,
     173,   175,   177,   179,   181,   182,   186,   187,   185,   184,
     189,   190,   193,   192,   197,   195,   196,   217,     0,   214,
     226,     0,   216,   104,     0,   108,     0,     0,   102,     0,
       0,    85,    87,    92,     0,    94,   155,    58,    61,   112,
     122,     0,     0,     0,     0,     0,   145,   149,     0,   153,
     205,   199,     0,   213,     0,   215,   105,   109,   103,   106,
       0,   110,     0,    95,    97,   121,   112,   112,     0,     0,
       0,     0,     0,   168,   227,   107,   111,   131,   135,     0,
     112,     0,     0,     0,     0,   112,   112,     0,   137,   112,
     112,     0,   112,     0,     0,   134,   132,   136,   138,   139,
     112,   141,   112,   112,     0,   140,   142,   143,   112,   144
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,     3,    29,    30,    61,    62,    63,    64,
      33,    34,    35,    36,    37,    82,    51,    52,    83,    84,
     148,   149,    38,    69,    70,    49,    40,    41,    48,   296,
     129,   130,   131,   139,   228,   184,   297,   219,    88,    89,
     165,   166,   167,    65,    90,   169,   170,   171,   172,   107,
     185,   175,   240,   141,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   291
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -209
static const short int yypact[] =
{
    -209,    39,  -209,   958,  -209,  -209,  -209,   836,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,    15,   -19,   174,  -209,
    -209,  -209,    35,  1261,  1261,  1261,  -209,    43,  -209,  1213,
     169,    79,  -209,  -209,    19,   -33,  -209,  -209,   -19,   -21,
    -209,    85,  -209,   978,  -209,  -209,  -209,  -209,  1002,   -30,
    1101,  -209,  -209,  1213,    35,  -209,   398,   907,   169,    -9,
    -209,   -17,    19,  -209,  -209,  -209,   174,  -209,   448,  -209,
    1002,  1002,  1144,  -209,   164,  1002,  -209,  1121,  -209,   364,
      11,  -209,  -209,     0,  -209,  -209,    45,   751,   751,  -209,
    -209,  -209,  -209,  -209,  -209,   319,  -209,  -209,  -209,    31,
       4,   109,    44,    82,    89,   170,   133,    49,   158,    84,
    -209,  -209,   777,     3,  -209,   161,  -209,   210,    93,   159,
    -209,    22,  -209,    19,  -209,   777,   134,  -209,   448,  -209,
    -209,  -209,   948,  -209,  -209,  -209,  -209,   777,   221,  -209,
     168,  1164,  -209,   163,   777,   183,   178,   187,  -209,   199,
      19,   218,   236,   474,  -209,  -209,  -209,  -209,  -209,  -209,
     260,  -209,  -209,   257,   228,  -209,  -209,  -209,   319,  -209,
     777,  -209,  -209,   202,   253,    30,  -209,   777,   777,   777,
     777,   777,   777,   777,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,   777,   777,  -209,    19,  -209,  -209,
     777,   488,    19,  -209,   527,   887,  -209,    71,  -209,   177,
    -209,  1233,    19,  -209,  -209,  -209,  -209,  -209,   152,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
     777,  -209,   164,  -209,   777,  -209,  -209,   265,  -209,   777,
     777,   280,   567,   270,  -209,  -209,  -209,   239,   262,  -209,
     777,  -209,   263,  1030,   188,  -209,   777,  -209,   109,   -42,
      44,    82,    89,   170,   133,   133,    49,    49,    49,    49,
     158,   158,    84,    84,  -209,  -209,  -209,  -209,    66,  -209,
    -209,    54,  -209,  -209,   268,  -209,   267,   271,   177,   575,
    1050,  -209,  -209,  -209,   372,  -209,  -209,  -209,  -209,  -209,
    -209,    91,   108,   266,   602,   241,  -209,  -209,   777,  -209,
    -209,  -209,   777,  -209,   777,  -209,  -209,  -209,  -209,  -209,
     272,  -209,   273,  -209,  -209,  -209,  -209,  -209,   777,   619,
     244,   654,   126,  -209,  -209,  -209,  -209,   295,  -209,   127,
    -209,   131,   672,   698,   249,  -209,  -209,   282,  -209,  -209,
    -209,   136,  -209,   139,   724,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,   144,  -209,  -209,  -209,  -209,  -209
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -209,  -209,   351,  -209,  -209,  -209,   318,     5,   314,    -3,
    -209,   115,    56,  -209,  -209,   294,  -209,   306,   -53,   -65,
    -209,   145,  -209,   316,   258,     2,   -37,    -7,  -209,   -60,
    -209,   165,  -209,  -132,  -209,   215,  -108,  -208,   -88,  -209,
    -209,  -209,  -209,    -8,   307,  -209,  -209,  -209,  -209,    98,
     -20,   -77,  -209,   -63,  -121,  -209,   208,   209,   207,   217,
     219,    76,   104,   130,   135,  -109,   -61,  -209,  -209,  -209,
    -209,  -209
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -39
static const short int yytable[] =
{
      32,   140,   177,   108,    68,    39,   227,   128,    31,   298,
     207,   208,   209,   206,   225,   143,   144,   142,     6,   218,
      47,   187,     6,    21,    22,   260,   241,   322,   142,   146,
      55,    56,    57,   247,    53,   179,   181,   182,     6,     4,
     183,    74,    72,    43,   142,    85,     6,    43,     6,    94,
      95,    96,    27,    97,    98,    92,   298,    75,   133,   199,
     200,   140,   135,    43,   127,   177,    93,   134,    91,   174,
     251,    43,   108,    43,     6,   265,   210,   142,    93,    78,
     211,   168,     6,    46,   108,   188,   150,   176,   212,   222,
      44,   108,    91,   294,   284,   285,   286,   260,   146,    43,
     223,    42,   142,    50,    73,   186,    27,    43,   267,    99,
     100,   101,    28,   183,    81,   102,   103,   142,    58,   142,
     217,   324,   178,   308,    45,   189,    42,   142,   190,   216,
      42,   106,   325,   260,   290,    59,    81,    81,    81,    42,
     323,    81,    71,   257,   214,   195,   196,   203,   215,   142,
     142,   108,    76,    77,   191,   204,    28,   321,   260,   192,
     310,    81,    42,   306,   205,   132,   213,     6,   269,   336,
      71,   220,   334,    80,    42,   260,   264,     6,   330,   142,
      68,   108,    42,   319,   193,   194,   337,   173,   142,   142,
     288,   142,    43,   260,   260,    80,    80,    80,   260,   142,
      80,   133,    43,   260,   355,   357,   260,    81,   217,   359,
     226,   260,   127,     6,   370,   197,   198,   372,   127,   304,
      80,   335,   378,   201,   202,    42,   221,   140,   305,   311,
     312,    71,   315,   147,    81,    27,   108,   244,    43,   246,
     332,    28,    66,   142,   150,    27,    67,   344,   347,   348,
     299,    28,   248,   142,   300,   249,   264,   142,   253,   343,
     127,   214,   358,   142,   250,   263,    80,   365,   366,   274,
     275,   368,   369,    27,   371,   214,   252,   142,   142,   263,
     142,    27,   375,   214,   376,   377,   254,   215,   242,   243,
     379,   142,   142,    80,   340,   260,   261,   127,   342,   276,
     277,   278,   279,   142,   255,   287,   260,   317,   260,   341,
     292,   260,   352,    42,   258,    42,   260,   364,   349,   351,
     303,   354,     6,    94,    95,    96,   259,    97,    98,   280,
     281,   266,   361,   363,   309,   313,   282,   283,   316,   318,
      42,   320,   326,   338,   374,   327,   345,     7,   356,   328,
     367,   346,     5,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     6,    94,    95,
      96,    79,    97,    98,    87,     6,    94,    95,    96,   151,
      97,    98,   137,    99,   100,   101,   302,   307,   136,   102,
     103,   224,    43,   262,   153,   268,   105,   271,   270,     0,
      43,     6,    94,    95,    96,   106,    97,    98,   272,     0,
       0,   273,     0,     0,   154,   155,   156,     0,     0,   157,
     158,   159,   160,   161,   162,   163,    43,     0,    99,   100,
     101,     0,   164,     0,   102,   103,    99,   100,   101,    60,
       0,   105,   102,   103,     0,     0,     0,   138,   333,   105,
     106,     6,    94,    95,    96,     0,    97,    98,   106,     0,
       0,     0,    99,   100,   101,     0,     0,     0,   102,   103,
       0,     0,   104,     0,     0,   105,    43,     6,    94,    95,
      96,     0,    97,    98,   106,     0,     0,     0,     0,     0,
       0,     6,    94,    95,    96,     0,    97,    98,     0,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,    43,     0,   102,   103,
       0,     0,     0,   138,     0,   105,     0,     0,     0,     0,
       6,    94,    95,    96,   106,    97,    98,     0,    99,   100,
     101,     0,   256,     0,   102,   103,     0,     0,     0,     0,
       0,   105,    99,   100,   101,    43,     0,     0,   102,   103,
     106,     0,     0,     0,     0,   105,   289,     0,     0,     0,
       6,    94,    95,    96,   106,    97,    98,     0,     6,    94,
      95,    96,     0,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,    43,     0,   102,   103,     0,
       0,   293,     0,    43,   105,     6,    94,    95,    96,     0,
      97,    98,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     6,    94,    95,    96,     0,    97,    98,     0,
      43,    99,   100,   101,     0,   314,     0,   102,   103,    99,
     100,   101,     0,     0,   105,   102,   103,    43,     0,   329,
       0,     0,   105,   106,     0,     0,     0,     6,    94,    95,
      96,   106,    97,    98,     0,     0,    99,   100,   101,     0,
     339,     0,   102,   103,     0,     6,    94,    95,    96,   105,
      97,    98,    43,    99,   100,   101,     0,     0,   106,   102,
     103,     0,     0,     0,     0,     0,   105,   350,     0,     0,
      43,     6,    94,    95,    96,   106,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   353,     0,   102,   103,    43,     6,    94,    95,
      96,   105,    97,    98,     0,     0,    99,   100,   101,     0,
     106,     0,   102,   103,     0,     0,     0,     0,     0,   105,
     360,     0,    43,     0,     6,    94,    95,    96,   106,    97,
      98,     0,    99,   100,   101,     0,     0,     0,   102,   103,
       0,     0,     0,     0,     0,   105,   362,     0,     0,    43,
       6,    94,    95,    96,   106,    97,    98,     0,    99,   100,
     101,     0,     0,     0,   102,   103,     0,     0,     0,     0,
       0,   105,   373,     0,     0,    43,     0,     0,     0,     0,
     106,     0,     0,     0,     0,    99,   100,   101,     0,     0,
       0,   102,   103,     0,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,   -38,
       0,    99,   100,   101,     0,     0,     0,   102,   103,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -38,   -38,     0,     0,   -38,     0,   -38,
       6,     0,     0,   -38,   -38,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,    27,     0,
     214,     6,     0,     0,   215,   295,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    54,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,   239,     0,    27,
      54,     0,     0,     0,     0,    28,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,    60,     0,     0,     0,    78,    54,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    54,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,    27,     0,   214,     0,     0,     0,   263,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,    54,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    54,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,    54,     0,     0,     0,     0,    86,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    54,     0,     0,     0,     0,   152,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,    54,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    54,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   301,     0,     0,     0,     0,     0,     0,    60,    54,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26
};

static const short int yycheck[] =
{
       3,    78,    90,    66,    41,     3,   138,    67,     3,   217,
       7,     8,     9,   122,   135,    80,    81,    78,     3,   127,
      27,    17,     3,    42,    43,    67,   147,    69,    89,    82,
      33,    34,    35,   154,    32,    96,    97,    98,     3,     0,
     105,    48,    75,    28,   105,    75,     3,    28,     3,     4,
       5,     6,    71,     8,     9,    63,   264,    78,    67,    10,
      11,   138,    79,    28,    67,   153,    64,    76,    63,    89,
     158,    28,   135,    28,     3,   183,    73,   138,    76,    79,
      77,    89,     3,    27,   147,    81,    84,    76,    85,    67,
      75,   154,    87,   214,   203,   204,   205,    67,   151,    28,
      78,     3,   163,    68,    48,    74,    71,    28,    78,    64,
      65,    66,    77,   178,    58,    70,    71,   178,    75,   180,
     127,    67,    77,   244,    26,    16,    28,   188,    84,   127,
      32,    86,    78,    67,   211,    37,    80,    81,    82,    41,
      74,    85,    44,   163,    73,    12,    13,    63,    77,   210,
     211,   214,    67,    68,    72,    71,    77,   266,    67,    70,
     248,   105,    64,   240,    80,    67,     5,     3,   188,    78,
      72,    78,   304,    58,    76,    67,   183,     3,   299,   240,
     217,   244,    84,   260,    14,    15,    78,    89,   249,   250,
     210,   252,    28,    67,    67,    80,    81,    82,    67,   260,
      85,    67,    28,    67,    78,    78,    67,   151,   215,    78,
      76,    67,   215,     3,    78,    82,    83,    78,   221,    67,
     105,   309,    78,    65,    66,   127,    67,   304,    76,   249,
     250,   133,   252,    69,   178,    71,   299,    69,    28,    76,
     300,    77,    73,   304,   242,    71,    77,   324,   336,   337,
      73,    77,    69,   314,    77,    77,   263,   318,   160,   322,
     263,    73,   350,   324,    77,    77,   151,   355,   356,   193,
     194,   359,   360,    71,   362,    73,    77,   338,   339,    77,
     341,    71,   370,    73,   372,   373,    68,    77,    67,    68,
     378,   352,   353,   178,   314,    67,    68,   300,   318,   195,
     196,   197,   198,   364,    68,   207,    67,    68,    67,    68,
     212,    67,    68,   215,    54,   217,    67,    68,   338,   339,
     222,   341,     3,     4,     5,     6,    69,     8,     9,   199,
     200,    78,   352,   353,    69,    55,   201,   202,    68,    77,
     242,    78,    74,    77,   364,    78,    74,    28,    53,    78,
      68,    78,     1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,     4,     5,
       6,    53,     8,     9,    60,     3,     4,     5,     6,    85,
       8,     9,    76,    64,    65,    66,   221,   242,    72,    70,
      71,   133,    28,   178,    87,   187,    77,   190,   189,    -1,
      28,     3,     4,     5,     6,    86,     8,     9,   191,    -1,
      -1,   192,    -1,    -1,    50,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    28,    -1,    64,    65,
      66,    -1,    68,    -1,    70,    71,    64,    65,    66,    75,
      -1,    77,    70,    71,    -1,    -1,    -1,    75,    76,    77,
      86,     3,     4,     5,     6,    -1,     8,     9,    86,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    -1,    74,    -1,    -1,    77,    28,     3,     4,     5,
       6,    -1,     8,     9,    86,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    28,    -1,    70,    71,
      -1,    -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    86,     8,     9,    -1,    64,    65,
      66,    -1,    68,    -1,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    64,    65,    66,    28,    -1,    -1,    70,    71,
      86,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,
       3,     4,     5,     6,    86,     8,     9,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    28,    -1,    70,    71,    -1,
      -1,    74,    -1,    28,    77,     3,     4,     5,     6,    -1,
       8,     9,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      28,    64,    65,    66,    -1,    68,    -1,    70,    71,    64,
      65,    66,    -1,    -1,    77,    70,    71,    28,    -1,    74,
      -1,    -1,    77,    86,    -1,    -1,    -1,     3,     4,     5,
       6,    86,     8,     9,    -1,    -1,    64,    65,    66,    -1,
      68,    -1,    70,    71,    -1,     3,     4,     5,     6,    77,
       8,     9,    28,    64,    65,    66,    -1,    -1,    86,    70,
      71,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      28,     3,     4,     5,     6,    86,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    68,    -1,    70,    71,    28,     3,     4,     5,
       6,    77,     8,     9,    -1,    -1,    64,    65,    66,    -1,
      86,    -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,    28,    -1,     3,     4,     5,     6,    86,     8,
       9,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    28,
       3,     4,     5,     6,    86,     8,     9,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,     3,
      -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    -1,    73,
       3,    -1,    -1,    77,    78,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    71,    -1,
      73,     3,    -1,    -1,    77,    78,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    79,    -1,    71,
      28,    -1,    -1,    -1,    -1,    77,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    79,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    71,    -1,    73,    -1,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    76,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    28,    -1,    -1,    -1,    -1,    76,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    75,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    88,    89,    90,     0,    89,     3,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    71,    77,    91,
      92,    94,    96,    97,    98,    99,   100,   101,   109,   112,
     113,   114,   136,    28,    75,   136,    99,   114,   115,   112,
      68,   103,   104,   112,    28,    96,    96,    96,    75,   136,
      75,    93,    94,    95,    96,   130,    73,    77,   113,   110,
     111,   136,    75,    99,   114,    78,    67,    68,    79,    93,
      98,    99,   102,   105,   106,    75,    76,    95,   125,   126,
     131,    94,   130,   112,     4,     5,     6,     8,     9,    64,
      65,    66,    70,    71,    74,    77,    86,   136,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    78,    96,   116,   117,
     118,   119,   136,    67,    76,    79,   110,   104,    75,   120,
     138,   140,   153,   106,   106,    76,   105,    69,   107,   108,
     112,   102,    76,   131,    50,    51,    52,    55,    56,    57,
      58,    59,    60,    61,    68,   127,   128,   129,   130,   132,
     133,   134,   135,   136,   137,   138,    76,   125,    77,   153,
      77,   153,   153,   106,   122,   137,    74,    17,    81,    16,
      84,    72,    70,    14,    15,    12,    13,    82,    83,    10,
      11,    65,    66,    63,    71,    80,   152,     7,     8,     9,
      73,    77,    85,     5,    73,    77,   112,   114,   123,   124,
      78,    67,    67,    78,   111,   141,    76,   120,   121,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    79,
     139,   141,    67,    68,    69,    76,    76,   141,    69,    77,
      77,   125,    77,   136,    68,    68,    68,   137,    54,    69,
      67,    68,   122,    77,   114,   123,    78,    78,   143,   137,
     144,   145,   146,   147,   148,   148,   149,   149,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   136,   137,    78,
     138,   158,   136,    74,   141,    78,   116,   123,   124,    73,
      77,    48,   118,   136,    67,    76,   138,   108,   141,    69,
     125,   137,   137,    55,    68,   137,    68,    68,    77,   138,
      78,   152,    69,    74,    67,    78,    74,    78,    78,    74,
     141,    78,   116,    76,   120,   125,    78,    78,    77,    68,
     137,    68,   137,   140,   138,    74,    78,   125,   125,   137,
      78,   137,    68,    68,   137,    78,    53,    78,   125,    78,
      78,   137,    78,   137,    68,   125,   125,    68,   125,   125,
      78,   125,    78,    78,   137,   125,   125,   125,    78,   125
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 119 "gram.y"
    { BEGINSUBGRPH(FUNSFRM) }
    break;

  case 5:
#line 121 "gram.y"
    { yyval.stat = yyvsp[0].stat; { ENDSUBGRPH(FUNSFRM) } }
    break;

  case 6:
#line 125 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 7:
#line 127 "gram.y"
    {
	                sketch_node (++ node, (yyval.stat = yyvsp[0].stat)->copy, NULL, NULL);
	                yyval.stat->copy = NULL;  
	               }
    break;

  case 8:
#line 141 "gram.y"
    {
		  int ret = 0;

		  sketch_edge (EDGE, ++ node, yyvsp[0].stat->flows->entry, NULL, NULL);

		  ret = sketchout_edges (PASS, &(yyvsp[0].stat->flows->outs), node + 1,
				     FORWARD);
		  sketch_node (node,
			   copyfmt ("Enter: %s", ret ?
				     strdup ((yyval.stat = yyvsp[-1].stat)->copy) : yyval.stat->copy),
			   NULL, "34");

		  if (ret)
		    sketch_node (++node, copyfmt ( "End: %s", yyval.stat->copy),
			     NULL, "34"); // end node.

		  yyval.stat->copy = NULL;
		  yyval.stat->flows = get_flows (node - (ret&1), SIMPLE,
					ret ? yyvsp[0].stat->flows->entry : NULLNODE);
		  
		  freestat (yyvsp[0].stat); 
		}
    break;

  case 9:
#line 165 "gram.y"
    {
		  int ret = 0;
		  (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ("%s %s", yyvsp[-2].stat->copy, freestat (yyvsp[-1].stat));

		  sketch_edge (EDGE, ++node, yyvsp[0].stat->flows->entry, NULL, NULL);
		  ret = sketchout_edges (PASS, &(yyvsp[0].stat->flows->outs), node + 1, FORWARD);

		  sketch_node (node, copyfmt ("Enter: %s", ret ? 
					  strdup (yyval.stat->copy) : yyval.stat->copy),
			   NULL, "34");

		  if (ret)
		    sketch_node (++node, copyfmt ( "End: %s", strdup (yyval.stat->copy)),
			     NULL, "34"); // end node.

		  yyval.stat->copy = NULL;
		  yyval.stat->flows = get_flows (node - (ret & 1), SIMPLE,
					ret ? yyvsp[0].stat->flows->entry : NULLNODE);
		  freestat (yyvsp[0].stat);
		}
    break;

  case 10:
#line 188 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 11:
#line 190 "gram.y"
    {yyval.stat = yyvsp[-1].stat;}
    break;

  case 12:
#line 195 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s;", yyvsp[-1].stat->copy);
		}
    break;

  case 13:
#line 199 "gram.y"
    {
	  (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s %s;", yyvsp[-2].stat->copy, freestat (yyvsp[-1].stat));
	  if (!strncmp (yyval.stat->copy, "typedef", 7))
	    gettypedef (yyval.stat->copy);  // magic
		
	}
    break;

  case 14:
#line 208 "gram.y"
    {
	        yyval.stat = yyvsp[0].stat;
	  //$$->copy = copyfmt (NULL, $1->copy);
		}
    break;

  case 15:
#line 212 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s\n%s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 16:
#line 219 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 17:
#line 222 "gram.y"
    {
		    (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, 
						freestat (yyvsp[0].stat));
		  }
    break;

  case 18:
#line 227 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 19:
#line 230 "gram.y"
    {
		    (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, 
						freestat (yyvsp[0].stat));
		  }
    break;

  case 20:
#line 235 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 21:
#line 238 "gram.y"
    { 
		    (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy,
						freestat (yyvsp[0].stat));
		  }
    break;

  case 22:
#line 246 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 23:
#line 247 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 24:
#line 248 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 25:
#line 249 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 26:
#line 250 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 27:
#line 254 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 28:
#line 255 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 29:
#line 256 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 30:
#line 257 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 31:
#line 258 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 32:
#line 259 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 33:
#line 260 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 34:
#line 261 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 35:
#line 262 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 36:
#line 263 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 37:
#line 264 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 38:
#line 265 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 39:
#line 269 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 40:
#line 270 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 41:
#line 274 "gram.y"
    {
	        (yyval.stat = yyvsp[-4].stat)->copy = copyfmt ( "%s %s {%s}", yyvsp[-4].stat->copy,
					    freestat (yyvsp[-3].stat), freestat (yyvsp[-1].stat));
		}
    break;

  case 42:
#line 278 "gram.y"
    {
	        (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ( "%s {%s}", yyvsp[-3].stat->copy, freestat(yyvsp[-1].stat));
		}
    break;

  case 43:
#line 281 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 44:
#line 287 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 45:
#line 288 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 46:
#line 292 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 47:
#line 294 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 48:
#line 300 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 49:
#line 302 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 50:
#line 308 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 51:
#line 310 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s=%s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 52:
#line 316 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s %s;", yyvsp[-2].stat->copy, freestat (yyvsp[-1].stat));
		}
    break;

  case 53:
#line 322 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 54:
#line 324 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 55:
#line 328 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 56:
#line 330 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 57:
#line 336 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 58:
#line 338 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 59:
#line 344 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 60:
#line 346 "gram.y"
    {
	        (yyval.stat = yyvsp[0].stat)->copy = copyfmt ( ": %s", yyvsp[0].stat->copy);
		}
    break;

  case 61:
#line 349 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s: %s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 62:
#line 355 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s {%s}",
					    freestat (yyvsp[-3].stat), yyvsp[-1].stat->copy);
		}
    break;

  case 63:
#line 359 "gram.y"
    {
	        (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ( "%s %s {%s}", freestat (yyvsp[-4].stat),
				     yyvsp[-3].stat->copy, freestat (yyvsp[-1].stat));
		}
    break;

  case 64:
#line 363 "gram.y"
    {
	        (yyval.stat = yyvsp[0].stat)->copy = copyfmt ( "%s %s", freestat (yyvsp[-1].stat), yyvsp[0].stat->copy);
		}
    break;

  case 65:
#line 369 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 66:
#line 371 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 67:
#line 377 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 68:
#line 379 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s=%s", yyvsp[-2].stat->copy, freestat(yyvsp[0].stat));
		}
    break;

  case 69:
#line 385 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 70:
#line 387 "gram.y"
    {
	        (yyval.stat = yyvsp[0].stat)->copy = copyfmt ( "%s%s", freestat(yyvsp[-1].stat), yyvsp[0].stat->copy);
		}
    break;

  case 71:
#line 393 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 72:
#line 395 "gram.y"
    {
	        (yyval.stat =yyvsp[-1].stat)->copy = copyfmt ( "(%s)", yyvsp[-1].stat->copy);
		}
    break;

  case 73:
#line 398 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s[]", yyvsp[-2].stat->copy);
		}
    break;

  case 74:
#line 401 "gram.y"
    {
	        (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ( "%s [%s]", yyvsp[-3].stat->copy, freestat(yyvsp[-1].stat));
		}
    break;

  case 75:
#line 404 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s ()", yyvsp[-2].stat->copy);
		}
    break;

  case 76:
#line 407 "gram.y"
    {
	        (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ( "%s (%s)", yyvsp[-3].stat->copy, freestat(yyvsp[-1].stat));
		}
    break;

  case 77:
#line 410 "gram.y"
    {
	        (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ( "%s (%s)", yyvsp[-3].stat->copy, freestat(yyvsp[-1].stat));
		}
    break;

  case 78:
#line 417 "gram.y"
    { yyval.stat = get_stat (strdup ("*"), NULL); }
    break;

  case 79:
#line 419 "gram.y"
    {
	        (yyval.stat = yyvsp[0].stat)->copy = copyfmt ( "*%s", yyvsp[0].stat->copy);
		}
    break;

  case 80:
#line 422 "gram.y"
    {
	        (yyval.stat =yyvsp[0].stat)->copy = copyfmt ( "*%s", yyvsp[0].stat->copy);
		}
    break;

  case 81:
#line 425 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "*%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 82:
#line 431 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 83:
#line 433 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 84:
#line 439 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 85:
#line 441 "gram.y"
    {
		(yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 86:
#line 447 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 87:
#line 449 "gram.y"
    {
		(yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 88:
#line 455 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 89:
#line 458 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s %s", yyvsp[-1].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 90:
#line 461 "gram.y"
    {
	                (yyval.stat = yyvsp[0].stat)->copy = copyfmt(NULL, yyvsp[0].stat->copy);
			}
    break;

  case 91:
#line 467 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 92:
#line 469 "gram.y"
    {
		(yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		}
    break;

  case 93:
#line 475 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 94:
#line 477 "gram.y"
    {
		(yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "{%s}", yyvsp[-1].stat->copy);
		}
    break;

  case 95:
#line 480 "gram.y"
    {
		(yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "{%s,} ", yyvsp[-2].stat->copy);
		}
    break;

  case 96:
#line 486 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 97:
#line 489 "gram.y"
    { 
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy,
						freestat (yyvsp[0].stat));
		    }
    break;

  case 98:
#line 496 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 99:
#line 499 "gram.y"
    { 
		    (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s%s", yyvsp[-1].stat->copy,
						freestat (yyvsp[0].stat));
		    //$$ = $1;
		    //$$->copy = copyfmt ( "%s %s", $1->copy, $2->copy);
		    //freestat ($2);
		    }
    break;

  case 100:
#line 509 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 101:
#line 511 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 102:
#line 514 "gram.y"
    { 
		    (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "%s%s", yyvsp[-1].stat->copy,
						freestat (yyvsp[0].stat));
		  }
    break;

  case 103:
#line 521 "gram.y"
    {
		(yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "(%s)", yyvsp[-1].stat->copy);
		}
    break;

  case 104:
#line 525 "gram.y"
    { yyval.stat = get_stat (strdup ("[]"), NULL); }
    break;

  case 105:
#line 527 "gram.y"
    {
		(yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "[%s]", yyvsp[-1].stat->copy);
		}
    break;

  case 106:
#line 531 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s[]", yyvsp[-2].stat->copy);
		}
    break;

  case 107:
#line 535 "gram.y"
    {
	  (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ( "%s[%s]", yyvsp[-3].stat->copy, freestat (yyvsp[-1].stat));
	        }
    break;

  case 108:
#line 539 "gram.y"
    { yyval.stat = get_stat (strdup ("()"), NULL); }
    break;

  case 109:
#line 541 "gram.y"
    {
	        (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ( "(%s)", yyvsp[-1].stat->copy);
		}
    break;

  case 110:
#line 545 "gram.y"
    {
	        (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s()", yyvsp[-2].stat->copy);
		}
    break;

  case 111:
#line 549 "gram.y"
    {
	        (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ( "%s(%s)", yyvsp[-3].stat->copy,
					    freestat (yyvsp[-1].stat));
		}
    break;

  case 112:
#line 561 "gram.y"
    { BEGINSUBGRPH(STATSFRM) }
    break;

  case 113:
#line 562 "gram.y"
    { yyval.stat = yyvsp[0].stat; { ENDSUBGRPH(STATSFRM) } }
    break;

  case 114:
#line 567 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 115:
#line 568 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 116:
#line 569 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 117:
#line 570 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 118:
#line 571 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 119:
#line 572 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 120:
#line 577 "gram.y"
    {
		  char *ident = strdup (yyvsp[-1].stat->copy);
		  int edgecount;

		  sketch_node (++node, copyfmt ("%s:", (yyval.stat = yyvsp[-1].stat)->copy),
			   NULL, NULL);
		  //sketch_edge (NEAR, node, $3->flows->entry, NULL, NULL);
		  //$$ = $3;
		  yyval.stat->flows = get_flows (node,  LABL, node);
				/* must be set to this node, */
				/* check some else solution. */
		  yyval.stat->copy = NULL;
		  //if ( (idlabel = 
		  //addsearch_label (ident, node);
		  
			  //)
			  //		      -> lablnode < 0) {
			  //idlabel->lablnode = node;
		  edgecount = sketchout_edges (EDGE,
					       put_lable_node (ident, node),
					       node, FORWARD);
			//}
		  //free (ident);
		}
    break;

  case 121:
#line 602 "gram.y"
    {
		  (yyval.stat = yyvsp[0].stat)->copy = copyfmt ("%s %s:", freestat (yyvsp[-3].stat),
					     freestat (yyvsp[-2].stat));

		  /* if (pgmargs.caseq == 0)  */
/* 		    sketch_node (++node, $$->copy, NULL, NULL);		   */
/* 		  else */
		  if (yyvsp[0].stat->flows->sttyp == CAS && pgmargs.casejoin) {
		    char *cas_copy;
		    unsigned int tmp = pop (&cas_copy, &caseroot);
		    push (tmp, copyfmt (pgmargs.casejoin > 0 ?
					"%s\n%s" : "%s %s",
					yyval.stat->copy, cas_copy),
			  &caseroot);
		  } else /* no joining */
		    push (++node, yyval.stat->copy, &caseroot);



		  if (!(yyvsp[0].stat->flows->sttyp == CAS && pgmargs.casejoin)) {
/* 		    insert (CAS, node, &($$->flows->cas)); */
		    sketch_edge (pgmargs.caseq ? EDGE : NEAR, node,
				 yyvsp[0].stat->flows->entry, NULL, NULL);
		  }
		  //if ($$->flows->sttyp == LOOP) forincase = 1;

		  //$$->copy = NULL; // so never try to statement->copy

		  yyval.stat->flows->sttyp = CAS; // must belowest.
		}
    break;

  case 122:
#line 633 "gram.y"
    {
		  (yyval.stat = yyvsp[0].stat)->copy = copyfmt ("%s:", freestat (yyvsp[-2].stat));

/* 		  if (pgmargs.caseq == 0)  */
/* 		    sketch_node (++node, $$->copy /\*"default:"*\/, NULL, NULL); */
/* 		  else */
		  if (yyvsp[0].stat->flows->sttyp == CAS && pgmargs.casejoin) {
		    char *cas_copy;
		    unsigned int tmp = pop (&cas_copy, &caseroot);
		    push (tmp, copyfmt (pgmargs.casejoin > 0 ?
					"%s\n%s" : "%s %s",
					yyval.stat->copy, cas_copy),
			  &caseroot);

		  } else
		    push (++node, yyval.stat->copy, &caseroot);


		  
		  
		  if (!(yyvsp[0].stat->flows->sttyp == CAS && pgmargs.casejoin)) {
/* 		    insert (CAS, node, &($$->flows->cas)); */
		    sketch_edge (pgmargs.caseq ? EDGE : NEAR, node, yyvsp[0].stat->flows->entry, NULL, NULL);
		  }
		  //if ($$->flows->sttyp == LOOP) forincase = 1;

		  yyval.stat->copy = NULL; // so never try to statement->copy
		  yyval.stat->flows->sttyp = CAS; // must belowest.
		}
    break;

  case 123:
#line 666 "gram.y"
    {
			sketch_node (++node, strdup (";"), NULL, NULL);
			yyval.stat = get_stat (NULL, get_flows (node, SIMPLE, node));
		}
    break;

  case 124:
#line 671 "gram.y"
    {
		  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s",
					   yyvsp[-1].stat->copy), NULL, NULL);
		  yyval.stat->copy = NULL;
		  (yyval.stat = yyvsp[-1].stat)->flows = get_flows (node, SIMPLE, node);
		}
    break;

  case 125:
#line 681 "gram.y"
    {
		  // if (showemptybody) {
		    yyval.stat = get_stat (strdup ("{  }"), NULL);
		    sketch_node (++node, yyval.stat->copy, NULL, NULL);
		    yyval.stat->copy = NULL;
		    yyval.stat->flows = get_flows (node, SIMPLE, node);
		    // } else
		    // $$ = NULL;
                }
    break;

  case 126:
#line 690 "gram.y"
    {yyval.stat = yyvsp[-1].stat;}
    break;

  case 127:
#line 693 "gram.y"
    {
		  sketch_node (++node, (yyval.stat = yyvsp[-1].stat)->copy, NULL, NULL);
		  yyval.stat->copy = NULL;
		  yyval.stat->flows = get_flows (node, SIMPLE, node);
		  /* new added */
#ifdef DEBUG
		if (yyval.stat->flows) {
		    fprintf (logfile, "\n$$->flow exist in declaration_list"
			     "You may see here Segment fault.");
		    fflush (logfile);
		  }
#endif
		//	$$->flows = get_flows (node, crtnodtyp (node, SIMPLE));
		//have done above
			//$$->flows->entry = node;
			//$$->flows->outs = crtnodtyp (2, node, -1);
		}
    break;

  case 128:
#line 712 "gram.y"
    {
		  sketch_node (++node, freestat (yyvsp[-2].stat), NULL, NULL);     //search
		  sketch_edge (EDGE, node, yyvsp[-1].stat->flows->entry, NULL, NULL);
		  //$$->flows->entry = node;
		  (yyval.stat = yyvsp[-1].stat)->copy = NULL;

		  yyval.stat->flows->entry = node;
				/* carefully see what had happened. */
				/* find same happening around in it */
		}
    break;

  case 129:
#line 726 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 130:
#line 728 "gram.y"
    { /* check it. crucial point deleteme*/

	  /*int i = */sketchout_edges (PASS, &(yyvsp[-1].stat->flows->outs),
			       yyvsp[0].stat->flows->entry, FORWARD);

	  (yyval.stat = yyvsp[-1].stat)->flows->outs = yyvsp[0].stat->flows->outs;
	  setunion (&(yyval.stat->flows->brk), &(yyvsp[0].stat->flows->brk));
	  setunion (&(yyval.stat->flows->cnt), &(yyvsp[0].stat->flows->cnt));
/* 	  setunion (&($$->flows->cas), &($2->flows->cas)); */

	  yyvsp[0].stat->flows->outs = yyvsp[0].stat->flows->brk = yyvsp[0].stat->flows->cnt = NULL; 
/* 	  $2->flows->cas = NULL;  */

	  free (yyvsp[0].stat->flows);
	  //showflows ($$->flows->outs, "statlist stat: Joining:");
	  freestat (yyvsp[0].stat);
	  /* here make sure to free one non-terminal. -- sharad */
	  	//$$->flows->entry = $1->flows->entry; /* search flows */
	}
    break;

  case 131:
#line 753 "gram.y"
    {
	  //printf ("\n COPY %s", $5->copy); fflush (stdout);
	  //showflows ($5->flows->outs, "if ex stat:");
	  //sketch_node (++node, copyfmt ( "if\\n%s", freestat ($3)),
	  sketch_node (++node, copyfmt ( "if\\n%s", freestat (yyvsp[-2].stat)),
		       "rhomb", "33");
	  sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, "true", NULL);
	  
	  (yyval.stat = yyvsp[0].stat)->flows->entry = node;
	  yyval.stat->flows->sttyp = SEL; // see if it is SEL.
	  //free ($$->copy);
	  yyval.stat->copy = NULL;

	  insert (SEL, node, &(yyval.stat->flows->outs));



	  //freestat ($3);
#ifdef DEBUG
	  if (yyval.stat->copy)
	    {
	      fprintf (logfile, "\n$$->copy exist %s"
		       "You may see here Segment fault."
		       "\n\t\tGood Bye", yyval.stat->copy);
	      fflush (logfile);
	      free (yyval.stat->copy);
	      yyval.stat->copy = NULL;
	    }
#endif
	}
    break;

  case 132:
#line 785 "gram.y"
    {
		  sketch_node (++node, copyfmt ("if\\n%s", freestat (yyvsp[-4].stat)),
			   "rhomb", "33");
		  //$$->flows->entry = node;

		  sketch_edge (BENTNEAR, node, yyvsp[-2].stat->flows->entry, "true", NULL);
		  sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, "false",NULL);
		  
		  (yyval.stat = yyvsp[-2].stat)->flows->entry = node;
		  yyval.stat->flows->sttyp = SIMPLE; // see if it is SEL.
		  //free ($$->copy);
		  yyval.stat->copy = NULL;

		  setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->outs));
		  setunion (&(yyval.stat->flows->brk), &(yyvsp[0].stat->flows->brk));
		  setunion (&(yyval.stat->flows->cnt), &(yyvsp[0].stat->flows->cnt));
/* 		  setunion (&($$->flows->cas), &($7->flows->cas)); */
		  
		  free (yyvsp[0].stat->flows);
		  freestat (yyvsp[0].stat);
		}
    break;

  case 133:
#line 807 "gram.y"
    { push (-11, NULL, &caseroot); }
    break;

  case 134:
#line 809 "gram.y"
    {
		int cascount = 0;
		int prev_casnode = 0;	/* add Sat May 20 */
		int casnode;
		char *cas_copy;

	  	sketch_node (/*$$->flows->entry = */++node,
			 copyfmt ( "switch\\n%s", freestat (yyvsp[-2].stat)),
			 "triangle", "42");

		if (yyvsp[0].stat->flows->sttyp != CAS)
		  sketch_edge (EDGE, node, yyvsp[0].stat->flows->entry, NULL, NULL);


		/* if (pgmargs.caseq != 0) /\* non 0 caseq means parallel *\/ */
/* 		  cascount =  sketchout_edges (BENTNEAR, */
/* 					       &($6->flows->cas), */
/* 					       node, */
/* 					       REVERSE); */


		while (/*cascount-- &&  what to do. */
		       ( (casnode
			  = pop (&cas_copy, &caseroot) ) >= 0)) {

		  if (prev_casnode && pgmargs.caseq >= 0)
		    if (pgmargs.caseq == 0)
		      sketch_edge (EDGE, casnode, prev_casnode,
				   NULL, NULL);
		    else 
		      sketch_edge (NEAR, casnode, prev_casnode,
				   NULL, "invisible");
		  /* added Sat May 20, see effect by setting
		     pgmargs.caseq 0 or > 0 Do not worry about
		     it, it will not sketch edge between 0 and
		     casnode, because of above if expression.*/

		  if (pgmargs.caseq != 0) /* new added. */
		    sketch_edge (BENTNEAR, node, casnode, NULL, NULL);

		  sketch_node (prev_casnode = casnode, cas_copy, NULL, NULL);

		}

		if (pgmargs.caseq == 0)
		  sketch_edge (NEAR, node, prev_casnode, NULL, NULL);


		(yyval.stat = yyvsp[0].stat)->flows->entry = node;
		yyval.stat->flows->sttyp = SIMPLE;
		yyval.stat->copy = NULL;

		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));

		yyval.stat->flows->brk = NULL; //must done.
		

             /* must be done. otherwise in recursive switch case:
	      * switch previous switch consider it as CAS
	      * statement. and creating problems by expecting or
	      * seeing for *($$->flows->cas->node)
	      */


	     /* Yes we are doing for condition pgmargs.casejoin
	      * is non zero the reason is that
	      */
	}
    break;

  case 135:
#line 882 "gram.y"
    {
	  	sketch_node (++node, copyfmt ( "while\\n%s", freestat (yyvsp[-2].stat)),
			 "rhomb", "33");
		sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, "true", NULL);
		sketchout_edges (BACK/*EDGE*/, &(yyvsp[0].stat->flows->outs), node, FORWARD);
		sketchout_edges (BACK, &(yyvsp[0].stat->flows->cnt), node, FORWARD);

		(yyval.stat = yyvsp[0].stat)->flows->entry = node;
		yyval.stat->flows->sttyp = LOOP;
		yyval.stat->copy = NULL;

		insert (LOOP, node, &(yyval.stat->flows->outs) );
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;
		// for continue statement.

	  }
    break;

  case 136:
#line 900 "gram.y"
    {
	    sketch_node (++node, strdup ("do"), NULL, NULL);   //search 
	    sketch_edge (EDGE, node, yyvsp[-5].stat->flows->entry, NULL, NULL);
	    sketch_node (++node, copyfmt ( "while\\n%s", yyvsp[-2].stat->copy),
		     "rhomb", "33");
	    sketchout_edges (EDGE, &(yyvsp[-5].stat->flows->outs), node, FORWARD);
	    sketchout_edges (EDGE, &(yyvsp[-5].stat->flows->cnt), node, FORWARD);
	    sketch_edge (BENTNEAR, node, node - 1, NULL, NULL);
	    /* check BACK is better than BENTNEAR */

	    (yyval.stat = yyvsp[-5].stat)->flows->entry = node - 1;
	    yyval.stat->flows->sttyp = LOOP;
	    //free ($$->copy);
	    yyval.stat->copy = NULL;

	    insert (LOOP, node, &(yyval.stat->flows->outs));
	    setunion (&(yyval.stat->flows->outs), &(yyvsp[-5].stat->flows->brk));
	    yyval.stat->flows->brk = NULL;



#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "\nWell: do {..} while () l"
			   "oops 's cnt flows is NULL");
		else
		  fprintf (logfile, "\nWell: do {..} while () l"
			   "oops 's cnt flows is NOT - NULL");
#endif
	    // make sure $2->flows->cnt is null and check it.

	}
    break;

  case 137:
#line 933 "gram.y"
    {
		sketch_node (++node, strdup ("for (;;)"), "rhomb", NULL);
		sketch_edge (EDGE, node, yyvsp[0].stat->flows->entry, NULL, NULL);
		sketchout_edges (BENTNEAR/*EDGE*/, &(yyvsp[0].stat->flows->outs), node, FORWARD);	 // should work well
		//if ($6->flows->cnt)
		//sketchout_edges (EDGE, &($6->flows->cnt), node, 0); R
 		sketchout_edges (BACK, &(yyvsp[0].stat->flows->cnt), node, FORWARD); 
		 
		yyval.stat = yyvsp[0].stat;
		yyval.stat->flows->entry = node;
		yyval.stat->flows->sttyp = LOOP;
		insert (LOOP, node, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "\nWell: for (;;) loops 's cnt"
			   "flows is NULL");
		else
		  fprintf (logfile, "\nWell: for (;;) loops 's cnt flows"
			   "is NOT - NULL");
#endif
	}
    break;

  case 138:
#line 959 "gram.y"
    {
		sketch_node (++node, strdup ("for ; ;"), "rhomb", NULL);

		//sketch_edge (EDGE, node, $7->flows->entry, NULL, NULL); R
		sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, NULL, NULL);
		sketch_node (++node, yyvsp[-2].stat->copy, NULL, NULL);
		//		$5->flows->entry = node;
		//sketchout_edges (EDGE, &($7->flows->outs), node, 0);
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->outs), node, FORWARD);
		sketch_edge (BACK/*EDGE*/, node, node - 1, NULL, NULL); //working well
		//if ($7->flows->cnt)
		//  sketchout_edges (EDGE, &($7->flows->cnt), node - 1, 0); R
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->cnt), node, FORWARD);
		// for continue statement.
		(yyval.stat = yyvsp[0].stat)->flows->entry = node - 1;
		yyval.stat->flows->sttyp = LOOP;
		//free ($$->copy);
		yyval.stat->copy = NULL;

		insert (LOOP, node - 1, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "\nWell: for (;;s) loops 's cnt"
			   " flows is NULL");
		else
		  fprintf (logfile, "\nWell: for (;;s) loops 's cnt flows"
			   "is NOT - NULL");
#endif

		}
    break;

  case 139:
#line 994 "gram.y"
    {
		sketch_node (++node, yyvsp[-3].stat->copy, /*fmtvcg ($4->copy),*/
			   "rhomb", "33");
		//$$->flows->entry = node;

		sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, "true", NULL);
		sketchout_edges (BACK/*EDGE*/, &(yyvsp[0].stat->flows->outs), node, FORWARD); // should work well
		//if ($7->flows->cnt)
		sketchout_edges (BACK, &(yyvsp[0].stat->flows->cnt), node, FORWARD);
		// check n - 1 or n
		// for continue statement.
		(yyval.stat = yyvsp[0].stat)->flows->entry = node;
		yyval.stat->flows->sttyp = LOOP;
		//free ($$->copy);
		yyval.stat->copy = NULL;

		insert (LOOP, node, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "Well: for ( ;ex; ) loops 's "
			   "cnt flows is NULL");
		else
		  fprintf (logfile, "Well: for ( ;ex; ) loops 's cnt flows"
			   "is NOT - NULL");
#endif
	   }
    break;

  case 140:
#line 1025 "gram.y"
    {
		sketch_node (++node, yyvsp[-4].stat->copy, "rhomb", "33");

		sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, "true", NULL);
		sketch_node (++node, yyvsp[-2].stat->copy, NULL, NULL);
		//$6->flows->entry = node;
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->outs), node, FORWARD);
		sketch_edge (BACK/*EDGE*/, node, node - 1, NULL, NULL); // working well
		//if ($8->flows->cnt)
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->cnt), node, FORWARD);
		// for continue statement.
		(yyval.stat = yyvsp[0].stat)->flows->entry = node - 1;
		yyval.stat->flows->sttyp = LOOP;
		//free ($$->copy);
		yyval.stat->copy = NULL;

		insert (LOOP, node - 1, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "Well: for ( ;ex;ex) loops "
			   "'s cnt flows is NULL");
		else
		  fprintf (logfile, "Well: for ( ;ex;ex) loops "
			   "'s cnt flows is NOT - NULL");
#endif
	  }
    break;

  case 141:
#line 1056 "gram.y"
    {
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, yyvsp[-4].stat->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, strdup ("for\n;;"), "rhomb", "33");

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, NULL, NULL);
		sketchout_edges (BACK/*EDGE*/, &(yyvsp[0].stat->flows->outs), node, FORWARD); //should work well
		//if ($7->flows->cnt)
		sketchout_edges (BACK, &(yyvsp[0].stat->flows->cnt), node, FORWARD);
		// for continue statement.
		yyval.stat = yyvsp[0].stat;
		yyval.stat->flows->entry = node - 1;
		yyval.stat->flows->sttyp = LOOP;
		//free ($$->copy);
		yyval.stat->copy = NULL;

		insert (LOOP, node, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "Well: for (ex;;) loops 's cnt"
			   "flows is NULL");
		else
		  fprintf (logfile, "Well: for (ex;;) loops 's cnt"
			   " flows is NOT - NULL");
#endif
	 }
    break;

  case 142:
#line 1089 "gram.y"
    {
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, yyvsp[-5].stat->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, strdup("for\n;;"), "rhomb", "33");

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (EDGE, node, yyvsp[0].stat->flows->entry, NULL, NULL);
		sketch_node (++node, yyvsp[-2].stat->copy, NULL, NULL);
		//$6->flows->entry = node;   //donot delete.
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->outs), node, FORWARD);
		sketch_edge (BACK/*EDGE*/, node, node - 1, NULL, NULL); // should work well
		//if ($8->flows->cnt)
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->cnt), node, FORWARD);
		// for continue statement.
		(yyval.stat = yyvsp[0].stat)->flows->entry = node - 1;
		yyval.stat->flows->sttyp = LOOP;
		//free ($$->copy);
		yyval.stat->copy = NULL;

		insert (LOOP, node, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "Well: for (ex; ;ex) loops 's "
			   "cnt flows is NULL");//, $3->copy, $6->copy);
	        else
		  fprintf (logfile, "Well: for (ex; ;ex) loops 's "
			   "cnt flows is NOT - NULL");//, $3->copy, $6->copy);
#endif
	 }
    break;

  case 143:
#line 1124 "gram.y"
    {
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, yyvsp[-5].stat->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, yyvsp[-3].stat->copy, "rhomb", "33");
		//$5->flows->entry = node;

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, "true", NULL);
		sketchout_edges (BACK/*EDGE*/, &(yyvsp[0].stat->flows->outs), node, FORWARD); //should work well
		//if ($8->flows->cnt)
		  sketchout_edges (BACK, &(yyvsp[0].stat->flows->cnt), node, FORWARD);
		// for continue statement.
		yyval.stat = yyvsp[0].stat;
		yyval.stat->flows->entry = node - 1;
		yyval.stat->flows->sttyp = LOOP;
		//free ($$->copy);
		yyval.stat->copy = NULL;

		insert (LOOP, node, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "Well: for (ex;ex; ) loops '"
			   "s cnt flows is NULL");//, $3->copy, $5->copy);
		else
		  fprintf (logfile, "Well: for (ex;ex; ) loops 's"
			   " cnt flows is NOT - NULL");//, $3->copy, $5->copy);
#endif
	}
    break;

  case 144:
#line 1158 "gram.y"
    {
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, yyvsp[-6].stat->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, yyvsp[-4].stat->copy, "rhomb", "33");
		//$5->flows->entry = node;

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (BENTNEAR, node, yyvsp[0].stat->flows->entry, "true", NULL);
		sketch_node (++node, yyvsp[-2].stat->copy, NULL, NULL);
		//$7->flows->entry = node; // donot delete.
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->outs), node, FORWARD); //should work well
		sketch_edge (BACK, node, node - 1, NULL, NULL);
		//if ($9->flows->cnt)
		sketchout_edges (/*BENTNEAR*/EDGE, &(yyvsp[0].stat->flows->cnt), node, FORWARD);
		// for continue statement.


		(yyval.stat = yyvsp[0].stat)->flows->entry = node - 2;
		yyval.stat->flows->sttyp = LOOP;
		//free ($$->copy);
		yyval.stat->copy = NULL;

		//we are reusing flows struct and $$->flows->outs is NULL here.

		insert (LOOP, node - 1, &(yyval.stat->flows->outs));
		setunion (&(yyval.stat->flows->outs), &(yyvsp[0].stat->flows->brk));
		yyval.stat->flows->brk = NULL;


#ifdef DEBUG
		if (!(yyval.stat->flows->cnt))
		  fprintf (logfile, "Well: for (ex;ex;ex) loops "
			   "'s cnt flows is NULL");
		else
		  fprintf (logfile, "Well: for (ex;ex;ex) loops "
			   "'s cnt flows is NOT - NULL");
#endif
		freestat (yyvsp[-8].stat); freestat (yyvsp[-6].stat); freestat (yyvsp[-4].stat); freestat (yyvsp[-2].stat);
	}
    break;

  case 145:
#line 1202 "gram.y"
    {
			  int label;
			  char *ident = strdup (yyvsp[-1].stat->copy); /* used to send */
			  /* handle function. */
			  sketch_node (++node,
				   copyfmt ( pgmargs.semicolon ? "goto %s;":
					     "goto %s", yyvsp[-1].stat->copy),
				   NULL, NULL);
			  yyval.stat = yyvsp[-1].stat;
			  yyval.stat->copy = NULL;
			  yyval.stat->flows = get_flows (node, NONODE, NULLNODE); /* entry is */
			  /* here, but no outs, except to (int label) */
			  if ((label = put_out_node (ident, node)) >= 0)
			    sketch_edge (BACK, node, label, NULL, NULL);
			  freestat (yyvsp[-2].stat); // free it $1->copy also.
			}
    break;

  case 146:
#line 1219 "gram.y"
    {
			  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s", yyvsp[-1].stat->copy),
				   NULL, NULL);
			  yyval.stat = yyvsp[-1].stat;
			  yyval.stat->copy = NULL;
			  yyval.stat->flows = get_flows (node, NONODE, NULLNODE);
			  insert (JUMP, node, &(yyval.stat->flows->cnt));
			}
    break;

  case 147:
#line 1228 "gram.y"
    {
			  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s", yyvsp[-1].stat->copy),
				   NULL, NULL);
			  yyval.stat = yyvsp[-1].stat;
			  yyval.stat->copy = NULL;
			  yyval.stat->flows = get_flows (node, NONODE, NULLNODE);
			  insert (JUMP, node, &(yyval.stat->flows->brk));
			}
    break;

  case 148:
#line 1237 "gram.y"
    {
			  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s", yyvsp[-1].stat->copy),
				   NULL, NULL);
			  yyval.stat = yyvsp[-1].stat;
			  yyval.stat->copy = NULL;
			  yyval.stat->flows = get_flows (node, NONODE, NULLNODE);
			}
    break;

  case 149:
#line 1245 "gram.y"
    {
			  sketch_node (++node,
				   copyfmt ( pgmargs.semicolon ? "return %s;" : "return %s", yyvsp[-1].stat->copy),
				   NULL, NULL);
			  yyval.stat = yyvsp[-1].stat;
			  yyval.stat->copy = NULL;
			  yyval.stat->flows = get_flows (node, NONODE, NULLNODE);
			  freestat (yyvsp[-2].stat);
			}
    break;

  case 150:
#line 1257 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 151:
#line 1259 "gram.y"
    { yyval.stat = yyvsp[0].stat; }
    break;

  case 152:
#line 1263 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 153:
#line 1266 "gram.y"
    { yyval.stat = yyvsp[-2].stat;
		   yyval.stat->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy, yyvsp[0].stat->copy);
		   freestat (yyvsp[0].stat); }
    break;

  case 154:
#line 1272 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 155:
#line 1275 "gram.y"
    { 
		     (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s%s%s", yyvsp[-2].stat->copy,
					  freestat (yyvsp[-1].stat), freestat (yyvsp[0].stat));
		   }
    break;

  case 156:
#line 1282 "gram.y"
    { yyval.stat = get_stat (strdup ("="), NULL); }
    break;

  case 157:
#line 1290 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 158:
#line 1291 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 159:
#line 1292 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 160:
#line 1293 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 161:
#line 1294 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 162:
#line 1295 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 163:
#line 1296 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 164:
#line 1297 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 165:
#line 1298 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 166:
#line 1299 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 167:
#line 1303 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 168:
#line 1306 "gram.y"
    {
		    (yyval.stat = yyvsp[-4].stat)->copy = copyfmt ( "%s ? %s:%s", yyvsp[-4].stat->copy,
						freestat (yyvsp[-2].stat), freestat (yyvsp[0].stat));
		  }
    break;

  case 169:
#line 1313 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 170:
#line 1317 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 171:
#line 1320 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s||%s",
					       yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		   free(freestat (yyvsp[-1].stat));
		 }
    break;

  case 172:
#line 1328 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 173:
#line 1331 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s&&%s",
					       yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		   free(freestat (yyvsp[-1].stat));
		 }
    break;

  case 174:
#line 1339 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 175:
#line 1342 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s|%s",
						yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		  }
    break;

  case 176:
#line 1349 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 177:
#line 1352 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s^%s",
						yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		    //free(freestat ($2));
		  }
    break;

  case 178:
#line 1360 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 179:
#line 1363 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s&%s",
						yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		  }
    break;

  case 180:
#line 1370 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 181:
#line 1373 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ("%s==%s",
					       yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		   free(freestat (yyvsp[-1].stat));		 
		 }
    break;

  case 182:
#line 1380 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ("%s!=%s",
					       yyvsp[-2].stat->copy, freestat (yyvsp[0].stat));
		   free(freestat (yyvsp[-1].stat));
		 }
    break;

  case 183:
#line 1388 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 184:
#line 1391 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ("%s<%s",yyvsp[-2].stat->copy,
					       freestat (yyvsp[0].stat)); }
    break;

  case 185:
#line 1396 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s>%s", yyvsp[-2].stat->copy,
						freestat (yyvsp[0].stat)); }
    break;

  case 186:
#line 1401 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s<=%s", yyvsp[-2].stat->copy,
					       freestat (yyvsp[0].stat));
		   free(freestat (yyvsp[-1].stat));
		 }
    break;

  case 187:
#line 1408 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s>=%s", yyvsp[-2].stat->copy,
					       freestat (yyvsp[0].stat));
		   free(freestat (yyvsp[-1].stat));
		 }
    break;

  case 188:
#line 1416 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 189:
#line 1419 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s<<%s", yyvsp[-2].stat->copy,
					       freestat (yyvsp[0].stat));
		   free (freestat (yyvsp[-1].stat));
		 }
    break;

  case 190:
#line 1426 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s>>%s", yyvsp[-2].stat->copy,
					       freestat (yyvsp[0].stat));
		   free (freestat (yyvsp[-1].stat));
		 }
    break;

  case 191:
#line 1434 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 192:
#line 1437 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s+%s", yyvsp[-2].stat->copy,
						freestat (yyvsp[0].stat));
		  }
    break;

  case 193:
#line 1443 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s-%s", yyvsp[-2].stat->copy,
						freestat (yyvsp[0].stat));
		  }
    break;

  case 194:
#line 1451 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 195:
#line 1454 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s*%s", yyvsp[-2].stat->copy,
						freestat (yyvsp[0].stat));
		  }
    break;

  case 196:
#line 1460 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s/%s", yyvsp[-2].stat->copy,
						freestat (yyvsp[0].stat));
		  }
    break;

  case 197:
#line 1466 "gram.y"
    {
		    (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s%%%s", yyvsp[-2].stat->copy,
						freestat (yyvsp[0].stat));
		  }
    break;

  case 198:
#line 1473 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 199:
#line 1476 "gram.y"
    {
			 (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ("(%s)%s", yyvsp[-2].stat->copy,
						     freestat (yyvsp[0].stat));
		       }
    break;

  case 200:
#line 1483 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 201:
#line 1486 "gram.y"
    {
			  (yyval.stat = yyvsp[0].stat)->copy = copyfmt ("++%s", yyvsp[0].stat->copy);
			  free (freestat (yyvsp[-1].stat));
			}
    break;

  case 202:
#line 1492 "gram.y"
    {
			  (yyval.stat = yyvsp[0].stat)->copy = copyfmt ("--%s", yyvsp[0].stat->copy);
			  free (freestat (yyvsp[-1].stat));
			}
    break;

  case 203:
#line 1498 "gram.y"
    {
			(yyval.stat = yyvsp[0].stat)->copy = copyfmt ("%s%s", freestat (yyvsp[-1].stat),
						    yyvsp[0].stat->copy);
		      }
    break;

  case 204:
#line 1504 "gram.y"
    {
			(yyval.stat = yyvsp[0].stat)->copy = copyfmt ( "sizeof %s", yyvsp[0].stat->copy);
		        free (freestat (yyvsp[-1].stat));
		      }
    break;

  case 205:
#line 1510 "gram.y"
    {
			(yyval.stat = yyvsp[-1].stat)->copy = copyfmt ("sizeof (%s)", yyvsp[-1].stat->copy);
		        free (freestat (yyvsp[-3].stat));
		      }
    break;

  case 206:
#line 1517 "gram.y"
    { yyval.stat = get_stat (strdup ("&"), NULL); }
    break;

  case 207:
#line 1519 "gram.y"
    { yyval.stat = get_stat (strdup ("*"), NULL); }
    break;

  case 208:
#line 1521 "gram.y"
    { yyval.stat = get_stat (strdup ("+"), NULL); }
    break;

  case 209:
#line 1523 "gram.y"
    { yyval.stat = get_stat (strdup ("-"), NULL); }
    break;

  case 210:
#line 1525 "gram.y"
    { yyval.stat = get_stat (strdup ("~"), NULL); }
    break;

  case 211:
#line 1527 "gram.y"
    { yyval.stat = get_stat (strdup ("!"), NULL); }
    break;

  case 212:
#line 1532 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 213:
#line 1535 "gram.y"
    {
		      (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ("%s [%s]", yyvsp[-3].stat->copy,
						 freestat (yyvsp[-1].stat));
		    }
    break;

  case 214:
#line 1541 "gram.y"
    { (yyval.stat =yyvsp[-2].stat)->copy = copyfmt ("%s ()", yyvsp[-2].stat->copy); }
    break;

  case 215:
#line 1544 "gram.y"
    {
		      (yyval.stat = yyvsp[-3].stat)->copy = copyfmt ("%s (%s)", yyvsp[-3].stat->copy,
						 freestat (yyvsp[-1].stat));
		    }
    break;

  case 216:
#line 1550 "gram.y"
    {
		      (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ("%s.%s", yyvsp[-2].stat->copy,
						 freestat (yyvsp[0].stat)); }
    break;

  case 217:
#line 1555 "gram.y"
    {
		      (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ("%s->%s", yyvsp[-2].stat->copy,
						 freestat (yyvsp[0].stat));
		      free (freestat (yyvsp[-1].stat));
		    }
    break;

  case 218:
#line 1562 "gram.y"
    {
			   (yyval.stat =yyvsp[-1].stat)->copy = copyfmt ( "%s++", yyvsp[-1].stat->copy);
			   free (freestat (yyvsp[0].stat));
			 }
    break;

  case 219:
#line 1568 "gram.y"
    {
			   (yyval.stat =yyvsp[-1].stat)->copy = copyfmt ( "%s--", yyvsp[-1].stat->copy);
			   free (freestat (yyvsp[0].stat));
			 }
    break;

  case 220:
#line 1575 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 221:
#line 1577 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 222:
#line 1580 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 223:
#line 1582 "gram.y"
    { (yyval.stat = yyvsp[-1].stat)->copy = copyfmt ("(%s)", yyvsp[-1].stat->copy); }
    break;

  case 224:
#line 1586 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 225:
#line 1588 "gram.y"
    { /* changed to be compitable with multi */
	                             char *ptr;	/* ".." strings. */
	                             yyvsp[-1].stat->copy [strlen (yyvsp[-1].stat->copy) - 2]
				       = '\0';
				     ptr = strdup ((yyvsp[0].stat->copy) + 2);

				     free (freestat (yyvsp[0].stat));

	                             (yyval.stat = yyvsp[-1].stat)->copy =
				       copyfmt ( "%s%s", yyvsp[-1].stat->copy, ptr);
                                     }
    break;

  case 226:
#line 1602 "gram.y"
    {yyval.stat = yyvsp[0].stat;}
    break;

  case 227:
#line 1605 "gram.y"
    {
		   (yyval.stat = yyvsp[-2].stat)->copy = copyfmt ( "%s, %s", yyvsp[-2].stat->copy,
					       freestat (yyvsp[0].stat));
		 }
    break;


    }

/* Line 1010 of yacc.c.  */
#line 3704 "gram.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
	  yychar = YYEMPTY;

	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1616 "gram.y"

/* 	//extern char yytext[]; */
/* 	//extern int column; */

