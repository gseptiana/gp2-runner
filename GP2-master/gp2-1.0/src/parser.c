/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 56 "parser.y"

#include "common.h"

int yylex(void);

void yyerror(const char *error_message);
void report_warning(const char *error_message);

/* Flags used in the AST construction. */
bool is_root = false;
bool is_bidir = false;

/* Pointers to data structures constructed by the parser. */
struct List *gp_program = NULL; 
int host_nodes = 0, host_edges = 0;

bool syntax_error = false;

#line 89 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 42 "parser.y"

#include "ast.h"

#line 136 "parser.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN = 258,
    IF = 259,
    TRY = 260,
    THEN = 261,
    ELSE = 262,
    SKIP = 263,
    FAIL = 264,
    BREAK = 265,
    WHERE = 266,
    EDGETEST = 267,
    INDEG = 268,
    OUTDEG = 269,
    _LENGTH = 270,
    INT = 271,
    CHARACTER = 272,
    STRING = 273,
    ATOM = 274,
    LIST = 275,
    INTERFACE = 276,
    _EMPTY = 277,
    INJECTIVE = 278,
    MARK = 279,
    ANY_MARK = 280,
    ARROW = 281,
    NEQ = 282,
    GTEQ = 283,
    LTEQ = 284,
    NUM = 285,
    DNUM = 286,
    STR = 287,
    PROCID = 288,
    ID = 289,
    ROOT = 290,
    BIDIRECTIONAL = 291,
    GP_PROGRAM = 292,
    GP_GRAPH = 293,
    GP_RULE = 294,
    OR = 295,
    AND = 296,
    NOT = 297,
    UMINUS = 298
  };
#endif
/* Tokens.  */
#define MAIN 258
#define IF 259
#define TRY 260
#define THEN 261
#define ELSE 262
#define SKIP 263
#define FAIL 264
#define BREAK 265
#define WHERE 266
#define EDGETEST 267
#define INDEG 268
#define OUTDEG 269
#define _LENGTH 270
#define INT 271
#define CHARACTER 272
#define STRING 273
#define ATOM 274
#define LIST 275
#define INTERFACE 276
#define _EMPTY 277
#define INJECTIVE 278
#define MARK 279
#define ANY_MARK 280
#define ARROW 281
#define NEQ 282
#define GTEQ 283
#define LTEQ 284
#define NUM 285
#define DNUM 286
#define STR 287
#define PROCID 288
#define ID 289
#define ROOT 290
#define BIDIRECTIONAL 291
#define GP_PROGRAM 292
#define GP_GRAPH 293
#define GP_RULE 294
#define OR 295
#define AND 296
#define NOT 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "parser.y"
  
  int num;   /* value of NUM token. */
  double dnum; /* value of DNUM token. */
  char *str; /* value of STRING and CHAR tokens. */
  char *id;  /* value of PROCID and ID tokens. */
  int mark;  /* enum MarkTypes, value of MARK token. */
#line 110 "parser.y"
  
  struct List *list; 
  struct GPDeclaration *decl;
  struct GPCommand *command;
  struct GPProcedure *proc;
  struct GPRule *rule;
  struct GPGraph *graph;
  struct GPNode *node;
  struct GPEdge *edge;
  struct GPPos *pos;
  struct GPCondition *cond_exp;
  struct GPLabel *label;  
  struct GPAtom *atom_exp;

  int list_type; /* enum ListType */
  int check_type; /* enum CondExpType */

#line 258 "parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);
/* "%code provides" blocks.  */
#line 47 "parser.y"

extern List *gp_program; 
extern int yylineno;
extern string yytext;
extern FILE *yyin;
extern bool syntax_error;

#line 293 "parser.c"

#endif /* !YY_YY_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   435

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  347

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    63,     2,     2,     2,     2,
      55,    56,    45,    43,    54,    44,    48,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    53,
      61,    50,    62,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    60,    59,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   220,   220,   221,   222,   225,   227,   230,   231,   232,
     234,   236,   240,   245,   252,   253,   255,   258,   259,   261,
     266,   267,   268,   270,   273,   277,   279,   281,   283,   287,
     288,   292,   293,   294,   295,   296,   297,   299,   300,   301,
     303,   306,   308,   310,   313,   318,   326,   329,   333,   342,
     349,   354,   360,   362,   365,   366,   369,   372,   374,   377,
     378,   379,   380,   381,   385,   386,   387,   388,   389,   390,
     393,   394,   396,   399,   403,   404,   406,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   422,   423,   425,   426,
     430,   431,   433,   435,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   449,   450,   451,   452,   454,   455,
     458,   459,   461,   464,   465,   466,   467,   469,   470,   471,
     472,   474,   476,   477,   478,   479,   480,   481,   482,   483,
     486,   487,   488,   489,   497,   498,   506,   510,   511,   512,
     513,   515,   517,   520,   521,   523,   525,   528,   529,   531,
     534,   536,   537,   539,   540,   541,   542,   544,   545,   546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "IF", "TRY", "THEN", "ELSE",
  "SKIP", "FAIL", "BREAK", "WHERE", "EDGETEST", "INDEG", "OUTDEG",
  "_LENGTH", "INT", "CHARACTER", "STRING", "ATOM", "LIST", "INTERFACE",
  "_EMPTY", "INJECTIVE", "MARK", "ANY_MARK", "ARROW", "NEQ", "GTEQ",
  "LTEQ", "NUM", "DNUM", "STR", "PROCID", "ID", "ROOT", "BIDIRECTIONAL",
  "GP_PROGRAM", "GP_GRAPH", "GP_RULE", "OR", "AND", "NOT", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "'.'", "':'", "'='", "'['", "']'", "';'", "','",
  "'('", "')'", "'!'", "'{'", "'}'", "'|'", "'<'", "'>'", "'#'", "$accept",
  "Initialise", "Program", "Declaration", "MainDecl", "ProcDecl",
  "LocalDecls", "ComSeq", "Command", "Block", "SimpleCommand",
  "RuleSetCall", "IDList", "RuleDecl", "VarDecls", "VarList", "Inter",
  "NodeIDList", "Type", "Graph", "NodeList", "Node", "EdgeList", "Edge",
  "Position", "RootNode", "Bidirection", "CondDecl", "Condition",
  "Subtype", "LabelArg", "Label", "List", "AtomExp", "ProcID", "RuleID",
  "NodeID", "EdgeID", "Variable", "HostGraph", "HostNodeList", "HostNode",
  "HostEdgeList", "HostEdge", "HostID", "HostLabel", "HostList", "HostExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    43,    45,    42,    47,   298,    46,    58,
      61,    91,    93,    59,    44,    40,    41,    33,   123,   125,
     124,    60,    62,    35
};
# endif

#define YYPACT_NINF (-243)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     315,    15,    -5,   145,    61,    40,  -243,  -243,    15,  -243,
    -243,  -243,  -243,   -21,    51,   196,  -243,  -243,    42,    57,
    -243,   184,  -243,   116,   108,   105,    -2,   128,   135,    83,
     144,    86,  -243,   268,   189,   189,  -243,  -243,  -243,   184,
     145,   302,  -243,   155,   111,  -243,  -243,  -243,  -243,   302,
    -243,   276,   121,  -243,  -243,   164,   278,  -243,   192,  -243,
     165,   171,   207,   136,   281,  -243,  -243,  -243,   351,   353,
      27,   176,  -243,  -243,   184,   184,   189,  -243,    71,   108,
     164,   293,   108,    85,   203,   239,     3,   164,  -243,   205,
     142,   170,   213,   191,   186,  -243,   128,   283,  -243,   189,
     189,   189,   189,   212,   245,   245,  -243,  -243,  -243,  -243,
     184,  -243,  -243,   217,   257,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,   184,   100,   237,   230,  -243,   305,   164,   164,
     319,    35,   238,   308,   341,   310,   311,   344,   190,  -243,
     285,   322,  -243,  -243,   342,  -243,   368,  -243,  -243,  -243,
    -243,   302,   293,   164,   302,  -243,  -243,   192,  -243,   287,
    -243,   231,    32,   352,   164,  -243,  -243,  -243,   347,   246,
     -13,  -243,  -243,  -243,   317,  -243,  -243,   318,   320,   323,
     354,  -243,   289,   128,   189,   189,  -243,    32,   327,  -243,
     118,   291,  -243,   331,   266,   328,   336,   377,   164,    32,
    -243,  -243,   333,    78,   366,  -243,  -243,  -243,  -243,   329,
    -243,   338,  -243,  -243,   377,   125,  -243,  -243,   357,  -243,
    -243,  -243,   295,  -243,   337,   194,  -243,    32,   377,  -243,
    -243,  -243,  -243,  -243,   128,  -243,   343,   345,   346,  -243,
    -243,  -243,   240,   240,   267,   -11,   274,  -243,  -243,   340,
    -243,   296,    -3,   348,  -243,  -243,  -243,  -243,   194,   194,
     321,   349,    -7,   253,   377,  -243,   355,   100,   100,   108,
     358,   260,  -243,   356,   218,   339,   240,   240,   240,   240,
     240,   100,  -243,  -243,   233,  -243,   100,  -243,    95,   232,
     194,   194,   108,   125,   125,   240,   240,   240,   240,  -243,
      35,   359,   360,   361,  -243,  -243,  -243,   274,  -243,  -243,
     157,   157,   358,   358,  -243,   364,   100,  -243,   365,  -243,
     367,  -243,   369,   350,   350,   274,   274,   274,   274,   370,
    -243,  -243,  -243,   100,  -243,   100,  -243,  -243,   373,   374,
     125,   125,   375,   376,  -243,  -243,  -243
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,   130,   131,     2,     5,
       7,     8,     9,     0,     0,     0,     3,     4,     0,     0,
       1,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,    34,    35,    36,     0,
       0,    10,    17,    20,    32,    37,    39,    38,    14,    11,
     136,     0,     0,    52,    14,     0,     0,   150,    86,   137,
       0,     0,     0,     0,     0,   144,    31,    41,     0,    25,
       0,     0,    44,    42,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,   139,     0,     0,   147,     0,
       0,     0,     0,    29,     0,     0,    40,    18,    19,    21,
       0,    16,    15,     0,     0,    59,    60,    61,    62,    63,
      50,    53,     0,     0,     0,     0,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,   141,   148,    22,    24,    26,    27,    30,    45,
      43,    12,     0,     0,    13,   133,   132,    86,    64,     0,
      71,     0,     0,     0,     0,   155,   157,   159,     0,     0,
     151,   153,    78,    84,     0,    82,    77,     0,     0,     0,
       0,   140,     0,     0,     0,     0,    51,     0,     0,    66,
       0,     0,    74,     0,     0,     0,     0,    90,     0,     0,
     158,   145,     0,     0,     0,    79,    83,    80,    85,     0,
     142,     0,    23,    28,    90,     0,   135,   134,    88,    68,
      75,    65,     0,    56,     0,     0,    47,     0,    90,   146,
     156,   154,   152,    81,     0,    48,     0,     0,     0,   115,
     118,   119,     0,     0,     0,   110,   113,   117,    89,     0,
      67,     0,     0,     0,   104,   105,   106,   107,     0,     0,
      91,     0,     0,   113,    90,    46,     0,     0,     0,     0,
     123,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    54,     0,    57,     0,   100,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,   124,    73,   116,   114,   111,   112,
     125,   126,   127,   128,   129,     0,     0,    55,     0,   103,
     101,   102,     0,    95,    94,    97,    99,    98,    96,     0,
     120,   121,   122,     0,    58,     0,    92,   149,     0,   108,
       0,     0,     0,     0,   109,    93,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,  -243,   388,  -243,   247,   379,   -15,   292,   -31,
    -243,  -243,  -243,     4,   371,    23,  -152,  -243,   250,   -65,
     244,  -116,   185,  -174,   -83,   254,  -243,  -198,  -218,  -243,
    -243,    28,  -209,  -114,    20,    11,  -242,  -243,   -24,  -243,
     372,   -18,   270,   -86,   -91,   113,  -243,   211
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     8,     9,    10,    11,    78,    41,    42,    43,
      44,    45,    71,    12,    51,    52,   197,   284,   120,    85,
     125,   126,   191,   192,    30,    89,   249,   226,   260,   261,
     342,   244,   262,   246,    46,    47,   157,   218,   247,    16,
      31,    32,    97,    98,    58,   169,   170,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   127,    53,    68,    69,   141,   245,    17,    49,   160,
     285,   143,    14,    65,    19,   114,   235,   220,     5,    14,
     293,    13,   130,    18,    70,   301,   302,   155,    13,    23,
     265,   156,    50,   195,    24,   214,   203,    50,   274,   315,
     287,   288,   274,   294,   318,   109,    15,   228,     6,     7,
     204,    73,   275,   196,    55,    53,   283,   165,   121,   129,
      72,    20,    53,   162,   163,   166,   299,   167,   144,   145,
     146,   147,   320,   321,   334,   264,    65,   220,   160,   168,
      74,    75,   112,   103,   323,   324,   202,   112,   187,    14,
      21,   338,   211,   339,    14,   151,   143,    24,    13,   199,
     230,    25,   113,    13,     6,     7,    26,   154,   166,   113,
     167,   263,    26,    60,    61,   149,   150,    33,     6,     7,
      34,    35,   168,   110,    36,    37,    38,    62,   270,   271,
     155,   245,   245,   227,   156,   290,   291,   122,   236,   237,
     238,    27,    50,   266,   263,   289,    64,   239,   216,     6,
       7,   319,   217,   212,   213,   240,    54,   241,    57,    50,
     307,   273,   310,   311,   312,   313,   314,    48,    77,   242,
      81,    39,   132,   133,    40,    82,   263,   263,     6,     7,
     243,   325,   326,   327,   328,    33,   134,    59,    34,    35,
      33,    27,    36,    37,    38,    76,    93,    36,    37,    38,
     135,   136,   278,   279,    63,   280,   253,   236,   237,   238,
     254,   255,   256,   257,   137,    84,   239,     6,     7,    90,
     178,   179,     6,     7,   240,    91,   241,    88,    50,   104,
     105,   236,   237,   238,   180,   106,   258,    92,   242,    39,
     306,    27,    40,   139,    39,   303,   140,    40,   240,   259,
     241,    27,    50,   236,   237,   238,    28,    29,   123,   131,
     295,   296,   242,   124,    29,   128,   152,   138,   322,   148,
     240,    82,   241,   243,    50,   276,   277,   278,   279,     7,
     280,   295,   296,   153,   242,   123,   123,   316,   304,   158,
     159,   193,   317,   297,   298,   243,   276,   277,   278,   279,
     172,   280,   201,   276,   277,   278,   279,    29,   280,   115,
     116,   117,   118,   119,   297,   298,   304,   276,   277,   278,
     279,   123,   280,   272,    66,   111,   222,    67,    29,    79,
     111,    86,    80,    95,    87,   142,    96,   181,    96,   189,
      96,   210,   190,   219,    96,   164,   190,   250,   282,   184,
     190,   190,     1,     2,     3,    74,    75,    99,   100,   101,
     102,   290,   291,   308,   309,   161,   107,   108,   343,   344,
     173,   174,   175,   176,   177,   185,   183,   200,   198,   205,
     206,   215,   207,   221,   209,   208,   224,   223,   225,   229,
     232,   233,   234,   248,   281,   252,    22,    56,   267,   274,
     268,   269,   186,   286,   292,   194,   280,   251,   291,   300,
     182,   188,   305,   329,   231,   330,   331,   332,   333,   335,
       0,     0,     0,     0,     0,   336,   337,   340,   341,     0,
       0,   345,   346,    83,     0,    94
};

static const yytype_int16 yycheck[] =
{
      24,    84,    26,    34,    35,    96,   215,     3,    23,   125,
     252,    97,     1,    31,     3,    80,   214,   191,     3,     8,
      27,     1,    87,     3,    39,   267,   268,    30,     8,    50,
     228,    34,    34,     1,    55,   187,    49,    34,    49,   281,
     258,   259,    49,    50,   286,    76,    51,   199,    33,    34,
      63,    40,    63,    21,    56,    79,    59,    22,    82,    56,
      40,     0,    86,   128,   129,    30,   264,    32,    99,   100,
     101,   102,   290,   291,   316,   227,    94,   251,   194,    44,
      53,    54,    78,    56,   293,   294,   169,    83,   153,    78,
      50,   333,   183,   335,    83,   110,   182,    55,    78,   164,
      22,    50,    79,    83,    33,    34,    55,   122,    30,    86,
      32,   225,    55,    30,    31,   104,   105,     1,    33,    34,
       4,     5,    44,    52,     8,     9,    10,    44,   242,   243,
      30,   340,   341,   198,    34,    40,    41,    52,    13,    14,
      15,    55,    34,   234,   258,   259,    60,    22,    30,    33,
      34,    56,    34,   184,   185,    30,    51,    32,    30,    34,
     274,   244,   276,   277,   278,   279,   280,    51,    57,    44,
      49,    55,    30,    31,    58,    54,   290,   291,    33,    34,
      55,   295,   296,   297,   298,     1,    44,    52,     4,     5,
       1,    55,     8,     9,    10,    40,    60,     8,     9,    10,
      30,    31,    45,    46,    60,    48,    12,    13,    14,    15,
      16,    17,    18,    19,    44,    51,    22,    33,    34,    54,
      30,    31,    33,    34,    30,    54,    32,    35,    34,    53,
      54,    13,    14,    15,    44,    59,    42,    30,    44,    55,
      22,    55,    58,    52,    55,   269,    60,    58,    30,    55,
      32,    55,    34,    13,    14,    15,    60,    61,    55,    54,
      28,    29,    44,    60,    61,    26,    49,    54,   292,    57,
      30,    54,    32,    55,    34,    43,    44,    45,    46,    34,
      48,    28,    29,    26,    44,    55,    55,    54,    56,    52,
      60,    60,    59,    61,    62,    55,    43,    44,    45,    46,
      62,    48,    56,    43,    44,    45,    46,    61,    48,    16,
      17,    18,    19,    20,    61,    62,    56,    43,    44,    45,
      46,    55,    48,    56,    56,    78,    60,    59,    61,    53,
      83,    53,    56,    52,    56,    52,    55,    52,    55,    52,
      55,    52,    55,    52,    55,    26,    55,    52,    52,     7,
      55,    55,    37,    38,    39,    53,    54,     6,     7,     6,
       7,    40,    41,    24,    25,    60,    74,    75,   340,   341,
      62,    30,    62,    62,    30,     7,    54,    30,    26,    62,
      62,    54,    62,    52,    30,    62,    50,    59,    11,    56,
      24,    62,    54,    36,    54,    58,     8,    26,    55,    49,
      55,    55,   152,    55,    55,   161,    48,   222,    41,    54,
     140,   157,    56,   300,   203,    56,    56,    56,    54,    54,
      -1,    -1,    -1,    -1,    -1,    56,    56,    54,    54,    -1,
      -1,    56,    56,    54,    -1,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,    38,    39,    65,     3,    33,    34,    66,    67,
      68,    69,    77,    98,    99,    51,   103,    77,    98,    99,
       0,    50,    67,    50,    55,    50,    55,    55,    60,    61,
      88,   104,   105,     1,     4,     5,     8,     9,    10,    55,
      58,    71,    72,    73,    74,    75,    98,    99,    51,    71,
      34,    78,    79,   102,    51,    56,    78,    30,   108,    52,
      30,    31,    44,    60,    60,   105,    56,    59,    73,    73,
      71,    76,    98,    99,    53,    54,    40,    57,    70,    53,
      56,    49,    54,    70,    51,    83,    53,    56,    35,    89,
      54,    54,    30,    60,   104,    52,    55,   106,   107,     6,
       7,     6,     7,    56,    53,    54,    59,    72,    72,    73,
      52,    69,    77,    79,    83,    16,    17,    18,    19,    20,
      82,   102,    52,    55,    60,    84,    85,    88,    26,    56,
      83,    54,    30,    31,    44,    30,    31,    44,    54,    52,
      60,   108,    52,   107,    73,    73,    73,    73,    57,    99,
      99,    71,    49,    26,    71,    30,    34,   100,    52,    60,
      85,    60,    83,    83,    26,    22,    30,    32,    44,   109,
     110,   111,    62,    62,    30,    62,    62,    30,    30,    31,
      44,    52,   106,    54,     7,     7,    82,    83,    89,    52,
      55,    86,    87,    60,    84,     1,    21,    80,    26,    83,
      30,    56,    88,    49,    63,    62,    62,    62,    62,    30,
      52,   108,    73,    73,    80,    54,    30,    34,   101,    52,
      87,    52,    60,    59,    50,    11,    91,    83,    80,    56,
      22,   111,    24,    62,    54,    91,    13,    14,    15,    22,
      30,    32,    44,    55,    95,    96,    97,   102,    36,    90,
      52,    86,    58,    12,    16,    17,    18,    19,    42,    55,
      92,    93,    96,    97,    80,    91,   108,    55,    55,    55,
      97,    97,    56,    88,    49,    63,    43,    44,    45,    46,
      48,    54,    52,    59,    81,   100,    55,    92,    92,    97,
      40,    41,    55,    27,    50,    28,    29,    61,    62,    91,
      54,   100,   100,   102,    56,    56,    22,    97,    24,    25,
      97,    97,    97,    97,    97,   100,    54,    59,   100,    56,
      92,    92,   102,    96,    96,    97,    97,    97,    97,   109,
      56,    56,    56,    54,   100,    54,    56,    56,   100,   100,
      54,    54,    94,    95,    95,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    66,    66,    67,    67,    67,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      75,    75,    76,    76,    76,    76,    77,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    99,   100,   100,   101,   101,   102,   103,   103,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     2,     1,     1,     1,
       3,     3,     6,     6,     0,     2,     2,     1,     3,     3,
       1,     3,     4,     6,     4,     2,     4,     4,     6,     3,
       4,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     3,     1,     3,     9,     8,     9,    10,
       3,     5,     1,     3,     4,     5,     2,     1,     3,     1,
       1,     1,     1,     1,     3,     5,     4,     6,     5,     7,
       1,     2,     6,     7,     1,     2,    10,     5,     5,     6,
       6,     7,     5,     6,     5,     6,     0,     1,     0,     1,
       0,     2,     4,     7,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     0,     2,
       1,     3,     3,     1,     3,     1,     3,     1,     1,     1,
       4,     4,     4,     2,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     4,
       6,     5,     7,     1,     2,     6,     7,     1,     2,     9,
       1,     1,     3,     1,     3,     1,     3,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 32: /* STR  */
#line 149 "parser.y"
            { free(((*yyvaluep).str)); }
#line 1521 "parser.c"
        break;

    case 33: /* PROCID  */
#line 149 "parser.y"
            { free(((*yyvaluep).id)); }
#line 1527 "parser.c"
        break;

    case 34: /* ID  */
#line 149 "parser.y"
            { free(((*yyvaluep).id)); }
#line 1533 "parser.c"
        break;

    case 66: /* Program  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1539 "parser.c"
        break;

    case 67: /* Declaration  */
#line 151 "parser.y"
            { freeASTDeclaration(((*yyvaluep).decl)); }
#line 1545 "parser.c"
        break;

    case 68: /* MainDecl  */
#line 152 "parser.y"
            { freeASTCommand(((*yyvaluep).command)); }
#line 1551 "parser.c"
        break;

    case 70: /* LocalDecls  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1557 "parser.c"
        break;

    case 71: /* ComSeq  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1563 "parser.c"
        break;

    case 72: /* Command  */
#line 152 "parser.y"
            { freeASTCommand(((*yyvaluep).command)); }
#line 1569 "parser.c"
        break;

    case 73: /* Block  */
#line 152 "parser.y"
            { freeASTCommand(((*yyvaluep).command)); }
#line 1575 "parser.c"
        break;

    case 74: /* SimpleCommand  */
#line 152 "parser.y"
            { freeASTCommand(((*yyvaluep).command)); }
#line 1581 "parser.c"
        break;

    case 75: /* RuleSetCall  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1587 "parser.c"
        break;

    case 76: /* IDList  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1593 "parser.c"
        break;

    case 77: /* RuleDecl  */
#line 153 "parser.y"
            { freeASTRule(((*yyvaluep).rule)); }
#line 1599 "parser.c"
        break;

    case 78: /* VarDecls  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1605 "parser.c"
        break;

    case 79: /* VarList  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1611 "parser.c"
        break;

    case 80: /* Inter  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1617 "parser.c"
        break;

    case 81: /* NodeIDList  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1623 "parser.c"
        break;

    case 83: /* Graph  */
#line 154 "parser.y"
            { freeASTGraph(((*yyvaluep).graph)); }
#line 1629 "parser.c"
        break;

    case 84: /* NodeList  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1635 "parser.c"
        break;

    case 85: /* Node  */
#line 155 "parser.y"
            { freeASTNode(((*yyvaluep).node)); }
#line 1641 "parser.c"
        break;

    case 86: /* EdgeList  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1647 "parser.c"
        break;

    case 87: /* Edge  */
#line 156 "parser.y"
            { freeASTEdge(((*yyvaluep).edge)); }
#line 1653 "parser.c"
        break;

    case 91: /* CondDecl  */
#line 157 "parser.y"
            { freeASTCondition(((*yyvaluep).cond_exp)); }
#line 1659 "parser.c"
        break;

    case 92: /* Condition  */
#line 157 "parser.y"
            { freeASTCondition(((*yyvaluep).cond_exp)); }
#line 1665 "parser.c"
        break;

    case 94: /* LabelArg  */
#line 158 "parser.y"
            { freeASTLabel(((*yyvaluep).label)); }
#line 1671 "parser.c"
        break;

    case 95: /* Label  */
#line 158 "parser.y"
            { freeASTLabel(((*yyvaluep).label)); }
#line 1677 "parser.c"
        break;

    case 96: /* List  */
#line 150 "parser.y"
            { freeAST(((*yyvaluep).list)); }
#line 1683 "parser.c"
        break;

    case 97: /* AtomExp  */
#line 159 "parser.y"
            { freeASTAtom(((*yyvaluep).atom_exp)); }
#line 1689 "parser.c"
        break;

    case 98: /* ProcID  */
#line 149 "parser.y"
            { free(((*yyvaluep).id)); }
#line 1695 "parser.c"
        break;

    case 99: /* RuleID  */
#line 149 "parser.y"
            { free(((*yyvaluep).id)); }
#line 1701 "parser.c"
        break;

    case 100: /* NodeID  */
#line 149 "parser.y"
            { free(((*yyvaluep).id)); }
#line 1707 "parser.c"
        break;

    case 101: /* EdgeID  */
#line 149 "parser.y"
            { free(((*yyvaluep).id)); }
#line 1713 "parser.c"
        break;

    case 102: /* Variable  */
#line 149 "parser.y"
            { free(((*yyvaluep).id)); }
#line 1719 "parser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 220 "parser.y"
                                        { gp_program = (yyvsp[0].list); }
#line 2015 "parser.c"
    break;

  case 3:
#line 221 "parser.y"
                                        { }
#line 2021 "parser.c"
    break;

  case 4:
#line 222 "parser.y"
                                          { if ((yyvsp[0].rule)) freeASTRule((yyvsp[0].rule)); }
#line 2027 "parser.c"
    break;

  case 5:
#line 225 "parser.y"
                                        { (yyval.list) = addASTDecl(GLOBAL_DECLARATIONS, 
                                               (yylsp[0]), (yyvsp[0].decl), NULL); }
#line 2034 "parser.c"
    break;

  case 6:
#line 227 "parser.y"
                                        { (yyval.list) = addASTDecl(GLOBAL_DECLARATIONS, 
                                               (yylsp[0]), (yyvsp[0].decl), (yyvsp[-1].list)); }
#line 2041 "parser.c"
    break;

  case 7:
#line 230 "parser.y"
                                        { (yyval.decl) = newASTMainDecl((yyloc), (yyvsp[0].command)); }
#line 2047 "parser.c"
    break;

  case 8:
#line 231 "parser.y"
                                        { (yyval.decl) = newASTProcedureDecl((yyloc), (yyvsp[0].proc)); }
#line 2053 "parser.c"
    break;

  case 9:
#line 232 "parser.y"
                                        { (yyval.decl) = newASTRuleDecl((yyloc), (yyvsp[0].rule)); }
#line 2059 "parser.c"
    break;

  case 10:
#line 234 "parser.y"
                                        { (yyval.command) = newASTCommandSequence((yylsp[-2]), (yyvsp[0].list)); }
#line 2065 "parser.c"
    break;

  case 11:
#line 236 "parser.y"
                                        { (yyval.proc) = newASTProcedure((yylsp[-2]), (yyvsp[-2].id), NULL, 
                                               newASTCommandSequence((yylsp[0]) ,(yyvsp[0].list)));
					  if((yyvsp[-2].id)) free((yyvsp[-2].id)); }
#line 2073 "parser.c"
    break;

  case 12:
#line 241 "parser.y"
                                        { (yyval.proc) = newASTProcedure((yylsp[-5]), (yyvsp[-5].id), (yyvsp[-2].list), 
                                               newASTCommandSequence((yylsp[0]), (yyvsp[0].list)));
				          if((yyvsp[-5].id)) free((yyvsp[-5].id)); }
#line 2081 "parser.c"
    break;

  case 13:
#line 246 "parser.y"
                                        { (yyval.proc) = newASTProcedure((yylsp[-5]), (yyvsp[-5].id), (yyvsp[-2].list), 
                                               newASTCommandSequence((yylsp[0]), (yyvsp[0].list)));
                                          report_warning("Procedure names must "
 					   "start with an upper-case letter."); 
					  if((yyvsp[-5].id)) free((yyvsp[-5].id)); }
#line 2091 "parser.c"
    break;

  case 14:
#line 252 "parser.y"
                                        { (yyval.list) = NULL; }
#line 2097 "parser.c"
    break;

  case 15:
#line 253 "parser.y"
                                        { (yyval.list) = addASTDecl(LOCAL_DECLARATIONS, (yylsp[0]), 
                                               newASTRuleDecl((yylsp[0]), (yyvsp[0].rule)), (yyvsp[-1].list)); }
#line 2104 "parser.c"
    break;

  case 16:
#line 255 "parser.y"
                                        { (yyval.list) = addASTDecl(LOCAL_DECLARATIONS, (yylsp[0]),
                                               newASTProcedureDecl((yylsp[0]), (yyvsp[0].proc)), (yyvsp[-1].list)); }
#line 2111 "parser.c"
    break;

  case 17:
#line 258 "parser.y"
                                        { (yyval.list) = addASTCommand((yylsp[0]), (yyvsp[0].command), NULL); }
#line 2117 "parser.c"
    break;

  case 18:
#line 259 "parser.y"
                                        { (yyval.list) = addASTCommand((yylsp[0]), (yyvsp[0].command), (yyvsp[-2].list)); }
#line 2123 "parser.c"
    break;

  case 19:
#line 261 "parser.y"
                                        { (yyval.list) = addASTCommand((yylsp[0]), (yyvsp[0].command), (yyvsp[-2].list));
                                          report_warning("Incorrect use of comma "
					    "to separate commands. Perhaps you "
					    "meant to use a semicolon?"); }
#line 2132 "parser.c"
    break;

  case 21:
#line 267 "parser.y"
                                        { (yyval.command) = newASTOrStmt((yyloc), (yyvsp[-2].command), (yyvsp[0].command)); }
#line 2138 "parser.c"
    break;

  case 22:
#line 268 "parser.y"
                                        { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[-2].command), (yyvsp[0].command), newASTSkip((yyloc))); }
#line 2145 "parser.c"
    break;

  case 23:
#line 270 "parser.y"
                                        { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[-4].command), (yyvsp[-2].command), (yyvsp[0].command)); }
#line 2152 "parser.c"
    break;

  case 24:
#line 273 "parser.y"
                                        { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[-2].command), newASTSkip((yyloc)), (yyvsp[0].command));
                                          report_warning("No 'then' clause in if "
						         "statement."); }
#line 2161 "parser.c"
    break;

  case 25:
#line 277 "parser.y"
                                        { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[0].command), newASTSkip((yyloc)), newASTSkip((yyloc))); }
#line 2168 "parser.c"
    break;

  case 26:
#line 279 "parser.y"
                                        { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[-2].command), (yyvsp[0].command), newASTSkip((yyloc))); }
#line 2175 "parser.c"
    break;

  case 27:
#line 281 "parser.y"
                                        { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[-2].command), newASTSkip((yyloc)), (yyvsp[0].command)); }
#line 2182 "parser.c"
    break;

  case 28:
#line 283 "parser.y"
                                         { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                                (yyvsp[-4].command), (yyvsp[-2].command), (yyvsp[0].command)); }
#line 2189 "parser.c"
    break;

  case 29:
#line 287 "parser.y"
                                        { (yyval.command) = newASTCommandSequence((yyloc), (yyvsp[-1].list)); }
#line 2195 "parser.c"
    break;

  case 30:
#line 288 "parser.y"
                                        { (yyval.command) = newASTAlap((yyloc), 
                                               newASTCommandSequence((yylsp[-2]), (yyvsp[-2].list))); }
#line 2202 "parser.c"
    break;

  case 31:
#line 292 "parser.y"
                                        { (yyval.command) = NULL; }
#line 2208 "parser.c"
    break;

  case 33:
#line 294 "parser.y"
                                        { (yyval.command) = newASTAlap((yyloc), (yyvsp[-1].command)); }
#line 2214 "parser.c"
    break;

  case 34:
#line 295 "parser.y"
                                        { (yyval.command) = newASTSkip((yyloc)); }
#line 2220 "parser.c"
    break;

  case 35:
#line 296 "parser.y"
                                        { (yyval.command) = newASTFail((yyloc)); }
#line 2226 "parser.c"
    break;

  case 36:
#line 297 "parser.y"
                                        { (yyval.command) = newASTBreak((yyloc)); }
#line 2232 "parser.c"
    break;

  case 37:
#line 299 "parser.y"
                                        { (yyval.command) = newASTRuleSetCall((yyloc), (yyvsp[0].list)); }
#line 2238 "parser.c"
    break;

  case 38:
#line 300 "parser.y"
                                        { (yyval.command) = newASTRuleCall((yyloc), (yyvsp[0].id)); if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2244 "parser.c"
    break;

  case 39:
#line 301 "parser.y"
                                        { (yyval.command) = newASTProcCall((yyloc), (yyvsp[0].id)); if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2250 "parser.c"
    break;

  case 40:
#line 303 "parser.y"
                                        { (yyval.list) = (yyvsp[-1].list); }
#line 2256 "parser.c"
    break;

  case 41:
#line 306 "parser.y"
                                        { (yyval.list) = NULL; }
#line 2262 "parser.c"
    break;

  case 42:
#line 308 "parser.y"
                                        { (yyval.list) = addASTRule((yylsp[0]), (yyvsp[0].id), NULL);
					  if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2269 "parser.c"
    break;

  case 43:
#line 310 "parser.y"
                                        { (yyval.list) = addASTRule((yylsp[0]), (yyvsp[0].id), (yyvsp[-2].list)); 
					  if((yyvsp[0].id)) free((yyvsp[0].id));}
#line 2276 "parser.c"
    break;

  case 44:
#line 313 "parser.y"
                                        { (yyval.list) = addASTRule((yylsp[0]), (yyvsp[0].id), NULL);
                                          report_warning("Procedure name used in "
					   "a rule set. Rule names must start "
					   "with a lower-case letter.");
				          if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2286 "parser.c"
    break;

  case 45:
#line 318 "parser.y"
                                        { (yyval.list) = addASTRule((yylsp[0]), (yyvsp[0].id), (yyvsp[-2].list));
                                          report_warning("Incorrect use of semicolon "
					   "in a rule set. Perhaps you meant to "
					   "use a comma?"); 
					  if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2296 "parser.c"
    break;

  case 46:
#line 327 "parser.y"
                                        { (yyval.rule) = newASTRule((yylsp[-8]), (yyvsp[-8].id), (yyvsp[-6].list), (yyvsp[-4].graph), (yyvsp[-2].graph), (yyvsp[-1].list), (yyvsp[0].cond_exp)); 
					  if((yyvsp[-8].id)) free((yyvsp[-8].id)); }
#line 2303 "parser.c"
    break;

  case 47:
#line 330 "parser.y"
                                        { (yyval.rule) = newASTRule((yylsp[-7]), (yyvsp[-7].id), NULL, (yyvsp[-4].graph), (yyvsp[-2].graph), (yyvsp[-1].list), (yyvsp[0].cond_exp));
					  if((yyvsp[-7].id)) free((yyvsp[-7].id)); }
#line 2310 "parser.c"
    break;

  case 48:
#line 334 "parser.y"
                                        { (yyval.rule) = newASTRule((yylsp[-8]), (yyvsp[-8].id), (yyvsp[-6].list), (yyvsp[-4].graph), (yyvsp[-2].graph), (yyvsp[-1].list), (yyvsp[0].cond_exp)); 
                                          report_warning("Rule names must "
 					   "start with a lower-case letter."
				 	   "letter.");
					  if((yyvsp[-8].id)) free((yyvsp[-8].id)); }
#line 2320 "parser.c"
    break;

  case 49:
#line 343 "parser.y"
                                        { (yyval.rule) = newASTRule((yylsp[-9]), (yyvsp[-9].id), (yyvsp[-7].list), (yyvsp[-4].graph), (yyvsp[-2].graph), (yyvsp[-1].list), (yyvsp[0].cond_exp));  
                                          report_warning("Semicolon at the end "
					    "of a rule's variable list");
					  if((yyvsp[-9].id)) free((yyvsp[-9].id)); }
#line 2329 "parser.c"
    break;

  case 50:
#line 349 "parser.y"
                                        { (yyval.list) = addASTVariableDecl((yyvsp[0].list_type), (yyloc), (yyvsp[-2].list), NULL); }
#line 2335 "parser.c"
    break;

  case 51:
#line 354 "parser.y"
                                        { (yyloc).first_column = (yylsp[-2]).first_column;
				          (yyloc).first_line = (yylsp[-2]).first_line;
					  (yyloc).last_column = (yylsp[0]).last_column;
				          (yyloc).last_column = (yylsp[0]).last_column;
					  (yyval.list) = addASTVariableDecl((yyvsp[0].list_type), (yyloc), (yyvsp[-2].list), (yyvsp[-4].list)); }
#line 2345 "parser.c"
    break;

  case 52:
#line 360 "parser.y"
                                        { (yyval.list) = addASTVariable((yylsp[0]), (yyvsp[0].id), NULL); 
					  if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2352 "parser.c"
    break;

  case 53:
#line 362 "parser.y"
                                        { (yyval.list) = addASTVariable((yylsp[0]), (yyvsp[0].id), (yyvsp[-2].list)); 
		 	                  if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2359 "parser.c"
    break;

  case 54:
#line 365 "parser.y"
                                        { (yyval.list) = NULL; }
#line 2365 "parser.c"
    break;

  case 55:
#line 366 "parser.y"
                                        { (yyval.list) = (yyvsp[-1].list); }
#line 2371 "parser.c"
    break;

  case 56:
#line 369 "parser.y"
                                        { report_warning("Error in an interface list.");  
                                          (yyval.list) = NULL; }
#line 2378 "parser.c"
    break;

  case 57:
#line 372 "parser.y"
                                        { (yyval.list) = addASTNodeID((yylsp[0]), (yyvsp[0].id), NULL); 
					  if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2385 "parser.c"
    break;

  case 58:
#line 374 "parser.y"
                                        { (yyval.list) = addASTNodeID((yylsp[0]), (yyvsp[0].id), (yyvsp[-2].list));
					  if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2392 "parser.c"
    break;

  case 59:
#line 377 "parser.y"
                                        { (yyval.list_type) = INT_DECLARATIONS; }
#line 2398 "parser.c"
    break;

  case 60:
#line 378 "parser.y"
                                        { (yyval.list_type) = CHAR_DECLARATIONS; }
#line 2404 "parser.c"
    break;

  case 61:
#line 379 "parser.y"
                                        { (yyval.list_type) = STRING_DECLARATIONS; }
#line 2410 "parser.c"
    break;

  case 62:
#line 380 "parser.y"
                                        { (yyval.list_type) = ATOM_DECLARATIONS; }
#line 2416 "parser.c"
    break;

  case 63:
#line 381 "parser.y"
                                        { (yyval.list_type) = LIST_DECLARATIONS; }
#line 2422 "parser.c"
    break;

  case 64:
#line 385 "parser.y"
                                         { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
#line 2428 "parser.c"
    break;

  case 65:
#line 386 "parser.y"
                                         { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
#line 2434 "parser.c"
    break;

  case 66:
#line 387 "parser.y"
                                         { (yyval.graph) = newASTGraph((yyloc), (yyvsp[-2].list), NULL); }
#line 2440 "parser.c"
    break;

  case 67:
#line 388 "parser.y"
                                         { (yyval.graph) = newASTGraph((yyloc), (yyvsp[-2].list), NULL); }
#line 2446 "parser.c"
    break;

  case 68:
#line 389 "parser.y"
                                         { (yyval.graph) = newASTGraph((yyloc), (yyvsp[-3].list), (yyvsp[-1].list)); }
#line 2452 "parser.c"
    break;

  case 69:
#line 391 "parser.y"
                                         { (yyval.graph) = newASTGraph((yyloc), (yyvsp[-3].list), (yyvsp[-1].list)); }
#line 2458 "parser.c"
    break;

  case 70:
#line 393 "parser.y"
                                        { (yyval.list) = addASTNode((yylsp[0]), (yyvsp[0].node), NULL); }
#line 2464 "parser.c"
    break;

  case 71:
#line 394 "parser.y"
                                        { (yyval.list) = addASTNode((yylsp[0]), (yyvsp[0].node), (yyvsp[-1].list)); }
#line 2470 "parser.c"
    break;

  case 72:
#line 396 "parser.y"
                                        { (yyval.node) = newASTNode((yylsp[-4]), is_root, (yyvsp[-4].id), (yyvsp[-1].label)); 
 					  is_root = false; 	
					  if((yyvsp[-4].id)) free((yyvsp[-4].id)); }
#line 2478 "parser.c"
    break;

  case 73:
#line 400 "parser.y"
                                        { (yyval.node) = newASTNode((yylsp[-5]), is_root, (yyvsp[-5].id), (yyvsp[-2].label)); 
 					  is_root = false; 	
					  if((yyvsp[-5].id)) free((yyvsp[-5].id)); }
#line 2486 "parser.c"
    break;

  case 74:
#line 403 "parser.y"
                                        { (yyval.list) = addASTEdge((yylsp[0]), (yyvsp[0].edge), NULL); }
#line 2492 "parser.c"
    break;

  case 75:
#line 404 "parser.y"
                                        { (yyval.list) = addASTEdge((yylsp[0]), (yyvsp[0].edge), (yyvsp[-1].list)); }
#line 2498 "parser.c"
    break;

  case 76:
#line 407 "parser.y"
                                        { (yyval.edge) = newASTEdge((yylsp[-8]), is_bidir, (yyvsp[-8].id), (yyvsp[-5].id), (yyvsp[-3].id), (yyvsp[-1].label));
                                          is_bidir = false; if((yyvsp[-8].id)) free((yyvsp[-8].id)); 
					  if((yyvsp[-5].id)) free((yyvsp[-5].id)); if((yyvsp[-3].id)) free((yyvsp[-3].id)); }
#line 2506 "parser.c"
    break;

  case 77:
#line 412 "parser.y"
                                        { }
#line 2512 "parser.c"
    break;

  case 78:
#line 413 "parser.y"
                                        { }
#line 2518 "parser.c"
    break;

  case 79:
#line 414 "parser.y"
                                        { }
#line 2524 "parser.c"
    break;

  case 80:
#line 415 "parser.y"
                                        { }
#line 2530 "parser.c"
    break;

  case 81:
#line 416 "parser.y"
                                        { }
#line 2536 "parser.c"
    break;

  case 82:
#line 417 "parser.y"
                                        { }
#line 2542 "parser.c"
    break;

  case 83:
#line 418 "parser.y"
                                        { }
#line 2548 "parser.c"
    break;

  case 84:
#line 419 "parser.y"
                                        { }
#line 2554 "parser.c"
    break;

  case 85:
#line 420 "parser.y"
                                        { }
#line 2560 "parser.c"
    break;

  case 87:
#line 423 "parser.y"
                                        { is_root = true; }
#line 2566 "parser.c"
    break;

  case 89:
#line 426 "parser.y"
                                        { is_bidir = true; }
#line 2572 "parser.c"
    break;

  case 90:
#line 430 "parser.y"
                                        { (yyval.cond_exp) = NULL; }
#line 2578 "parser.c"
    break;

  case 91:
#line 431 "parser.y"
                                        { (yyval.cond_exp) = (yyvsp[0].cond_exp); }
#line 2584 "parser.c"
    break;

  case 92:
#line 433 "parser.y"
                                        { (yyval.cond_exp) = newASTSubtypePred((yyvsp[-3].check_type), (yyloc), (yyvsp[-1].id)); 
					  if((yyvsp[-1].id)) free((yyvsp[-1].id)); }
#line 2591 "parser.c"
    break;

  case 93:
#line 436 "parser.y"
                                        { (yyval.cond_exp) = newASTEdgePred((yyloc), (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[-1].label)); 
					  if((yyvsp[-4].id)) free((yyvsp[-4].id)); if((yyvsp[-2].id)) free((yyvsp[-2].id)); }
#line 2598 "parser.c"
    break;

  case 94:
#line 438 "parser.y"
                                        { (yyval.cond_exp) = newASTListComparison(EQUAL, (yyloc), (yyvsp[-2].list), (yyvsp[0].list)); }
#line 2604 "parser.c"
    break;

  case 95:
#line 439 "parser.y"
                                        { (yyval.cond_exp) = newASTListComparison(NOT_EQUAL, (yyloc), (yyvsp[-2].list), (yyvsp[0].list)); }
#line 2610 "parser.c"
    break;

  case 96:
#line 440 "parser.y"
                                        { (yyval.cond_exp) = newASTAtomComparison(GREATER, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2616 "parser.c"
    break;

  case 97:
#line 441 "parser.y"
                                        { (yyval.cond_exp) = newASTAtomComparison(GREATER_EQUAL, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2622 "parser.c"
    break;

  case 98:
#line 442 "parser.y"
                                        { (yyval.cond_exp) = newASTAtomComparison(LESS, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2628 "parser.c"
    break;

  case 99:
#line 443 "parser.y"
                                        { (yyval.cond_exp) = newASTAtomComparison(LESS_EQUAL, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2634 "parser.c"
    break;

  case 100:
#line 444 "parser.y"
                                        { (yyval.cond_exp) = newASTNotExp((yyloc), (yyvsp[0].cond_exp)); }
#line 2640 "parser.c"
    break;

  case 101:
#line 445 "parser.y"
                                        { (yyval.cond_exp) = newASTBinaryExp(BOOL_OR, (yyloc), (yyvsp[-2].cond_exp), (yyvsp[0].cond_exp)); }
#line 2646 "parser.c"
    break;

  case 102:
#line 446 "parser.y"
                                        { (yyval.cond_exp) = newASTBinaryExp(BOOL_AND, (yyloc), (yyvsp[-2].cond_exp), (yyvsp[0].cond_exp)); }
#line 2652 "parser.c"
    break;

  case 103:
#line 447 "parser.y"
                                        { (yyval.cond_exp) = (yyvsp[-1].cond_exp); }
#line 2658 "parser.c"
    break;

  case 104:
#line 449 "parser.y"
                                        { (yyval.check_type) = INT_CHECK; }
#line 2664 "parser.c"
    break;

  case 105:
#line 450 "parser.y"
                                        { (yyval.check_type) = CHAR_CHECK; }
#line 2670 "parser.c"
    break;

  case 106:
#line 451 "parser.y"
                                        { (yyval.check_type) = STRING_CHECK; }
#line 2676 "parser.c"
    break;

  case 107:
#line 452 "parser.y"
                                        { (yyval.check_type) = ATOM_CHECK; }
#line 2682 "parser.c"
    break;

  case 108:
#line 454 "parser.y"
                                        { (yyval.label) = NULL; }
#line 2688 "parser.c"
    break;

  case 109:
#line 455 "parser.y"
                                        { (yyval.label) = (yyvsp[0].label); }
#line 2694 "parser.c"
    break;

  case 110:
#line 458 "parser.y"
                                        { (yyval.label) = newASTLabel((yyloc), NONE, (yyvsp[0].list)); }
#line 2700 "parser.c"
    break;

  case 111:
#line 459 "parser.y"
                                        { (yyval.label) = newASTLabel((yyloc), (yyvsp[0].mark), (yyvsp[-2].list)); }
#line 2706 "parser.c"
    break;

  case 112:
#line 461 "parser.y"
                                        { (yyval.label) = newASTLabel((yyloc), (yyvsp[0].mark), (yyvsp[-2].list)); }
#line 2712 "parser.c"
    break;

  case 113:
#line 464 "parser.y"
                                        { (yyval.list) = addASTAtom((yylsp[0]), (yyvsp[0].atom_exp), NULL); }
#line 2718 "parser.c"
    break;

  case 114:
#line 465 "parser.y"
                                        { (yyval.list) = addASTAtom((yylsp[0]), (yyvsp[0].atom_exp), (yyvsp[-2].list)); }
#line 2724 "parser.c"
    break;

  case 115:
#line 466 "parser.y"
                                        { (yyval.list) = NULL; }
#line 2730 "parser.c"
    break;

  case 117:
#line 469 "parser.y"
                                        { (yyval.atom_exp) = newASTVariable((yyloc), (yyvsp[0].id)); if((yyvsp[0].id)) free((yyvsp[0].id)); }
#line 2736 "parser.c"
    break;

  case 118:
#line 470 "parser.y"
                                        { (yyval.atom_exp) = newASTNumber((yyloc), (yyvsp[0].num)); }
#line 2742 "parser.c"
    break;

  case 119:
#line 471 "parser.y"
                                        { (yyval.atom_exp) = newASTString((yyloc), (yyvsp[0].str)); if((yyvsp[0].str)) free((yyvsp[0].str)); }
#line 2748 "parser.c"
    break;

  case 120:
#line 472 "parser.y"
                                        { (yyval.atom_exp) = newASTDegreeOp(INDEGREE, (yyloc), (yyvsp[-1].id)); 
					  if((yyvsp[-1].id)) free((yyvsp[-1].id)); }
#line 2755 "parser.c"
    break;

  case 121:
#line 474 "parser.y"
                                        { (yyval.atom_exp) = newASTDegreeOp(OUTDEGREE, (yyloc), (yyvsp[-1].id)); 
				 	  if((yyvsp[-1].id)) free((yyvsp[-1].id)); }
#line 2762 "parser.c"
    break;

  case 122:
#line 476 "parser.y"
                                        { (yyval.atom_exp) = newASTLength((yyloc), (yyvsp[-1].id)); if((yyvsp[-1].id)) free((yyvsp[-1].id)); }
#line 2768 "parser.c"
    break;

  case 123:
#line 477 "parser.y"
                                        { (yyval.atom_exp) = newASTNegExp((yyloc), (yyvsp[0].atom_exp)); }
#line 2774 "parser.c"
    break;

  case 124:
#line 478 "parser.y"
                                        { (yyval.atom_exp) = (yyvsp[-1].atom_exp); }
#line 2780 "parser.c"
    break;

  case 125:
#line 479 "parser.y"
                                        { (yyval.atom_exp) = newASTBinaryOp(ADD, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp));  }
#line 2786 "parser.c"
    break;

  case 126:
#line 480 "parser.y"
                                        { (yyval.atom_exp) = newASTBinaryOp(SUBTRACT, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2792 "parser.c"
    break;

  case 127:
#line 481 "parser.y"
                                        { (yyval.atom_exp) = newASTBinaryOp(MULTIPLY, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2798 "parser.c"
    break;

  case 128:
#line 482 "parser.y"
                                        { (yyval.atom_exp) = newASTBinaryOp(DIVIDE, (yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2804 "parser.c"
    break;

  case 129:
#line 483 "parser.y"
                                        { (yyval.atom_exp) = newASTConcat((yyloc), (yyvsp[-2].atom_exp), (yyvsp[0].atom_exp)); }
#line 2810 "parser.c"
    break;

  case 133:
#line 489 "parser.y"
                                        { char id[64]; int write;
					  write = snprintf(id, 64, "%d", (yyvsp[0].num));
				          if(write < 0) {
					    yyerror("Node ID conversion failed.");
					    exit(1);
					  }
					  else (yyval.id) = strdup(id);
					}
#line 2823 "parser.c"
    break;

  case 135:
#line 498 "parser.y"
                                        { char id[64]; int write;
					  write = snprintf(id, 64, "%d", (yyvsp[0].num));
				          if(write < 0) {
					    yyerror("Edge ID conversion failed.");
					    exit(1);
					  }
					  else (yyval.id) = strdup(id);
					}
#line 2836 "parser.c"
    break;

  case 137:
#line 510 "parser.y"
                                        { }
#line 2842 "parser.c"
    break;

  case 138:
#line 511 "parser.y"
                                        { }
#line 2848 "parser.c"
    break;

  case 139:
#line 512 "parser.y"
                                        { }
#line 2854 "parser.c"
    break;

  case 140:
#line 514 "parser.y"
                                        { }
#line 2860 "parser.c"
    break;

  case 141:
#line 516 "parser.y"
                                        { }
#line 2866 "parser.c"
    break;

  case 142:
#line 518 "parser.y"
                                        { }
#line 2872 "parser.c"
    break;

  case 143:
#line 520 "parser.y"
                                        { }
#line 2878 "parser.c"
    break;

  case 144:
#line 521 "parser.y"
                                        { }
#line 2884 "parser.c"
    break;

  case 147:
#line 528 "parser.y"
                                        { }
#line 2890 "parser.c"
    break;

  case 148:
#line 529 "parser.y"
                                        { }
#line 2896 "parser.c"
    break;

  case 151:
#line 536 "parser.y"
                                        { }
#line 2902 "parser.c"
    break;

  case 152:
#line 537 "parser.y"
                                        { }
#line 2908 "parser.c"
    break;

  case 153:
#line 539 "parser.y"
                                        { }
#line 2914 "parser.c"
    break;

  case 154:
#line 540 "parser.y"
                                        { }
#line 2920 "parser.c"
    break;

  case 155:
#line 541 "parser.y"
                                        { }
#line 2926 "parser.c"
    break;

  case 156:
#line 542 "parser.y"
                                        { }
#line 2932 "parser.c"
    break;

  case 157:
#line 544 "parser.y"
                                        { }
#line 2938 "parser.c"
    break;

  case 158:
#line 545 "parser.y"
                                        { }
#line 2944 "parser.c"
    break;

  case 159:
#line 546 "parser.y"
                                        { if((yyvsp[0].str)) free((yyvsp[0].str)); }
#line 2950 "parser.c"
    break;


#line 2954 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 548 "parser.y"


/* Bison calls yyerror whenever it encounters an error. It prints error
 * messages to stderr and log_file. */
void yyerror(const char *error_message)
{
   fprintf(stderr, "Error at line %d: %s\n", yylineno, error_message);
   fprintf(log_file, "%d.%d-%d.%d: Error at '%s': %s\n", 
           yylloc.first_line, yylloc.first_column, yylloc.last_line, 
           yylloc.last_column, yytext, error_message);
}

/* report_warning is identical to yyerror except that it doesn't refer to yytext.
 * This is called in the action code of error-catching Bison rules in which
 * the value of yytext may be misleading. */
void report_warning(const char *error_message)
{
   fprintf(stderr, "Error: %s\n", error_message);
   fprintf(log_file, "%d.%d-%d.%d: Error: %s\n", 
           yylloc.first_line, yylloc.first_column, yylloc.last_line, 
           yylloc.last_column, error_message);
   syntax_error = true;
}

