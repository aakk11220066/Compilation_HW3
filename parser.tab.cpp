/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */

	#include <iostream>
	#include <string>
	#include <list>
	using namespace std;
	#include "Framework.h"
	#include "Symbol.h"
	#include "Exceptions.h"

    class NonTerminal{
    	public:
    	    const string name = "";
    	    const string type = "";
    	    list<Variable> namesAndTypes = list<Variable>();
            list<string> arrguments_list = list<string>();
            NonTerminal() = default;
    	    NonTerminal(const string& name, const string& type) : name(name), type(type) {}
    	    NonTerminal& operator=(const NonTerminal& other){
    	     //  name = other.name;
    	     //  type = other.type;
    	     //  namesAndTypes = other.namesAndTypes;
    	     return *this;
    	    }
    	    void addParamToFunc(const string& name,const string& type){
                            this->namesAndTypes.push_back(Variable(name, type));
            }
    	};

    #define YYSTYPE NonTerminal
    extern list<string> varsListToTypesList(const list<Variable>& varList);

    //TODO: static function for the return issue
    extern int yylineno;
    extern YYSTYPE yylval;

    int yylex();
    void yyerror(const char*);



	//NonTerminal classes
    class Program : public NonTerminal{};
    class Funcs : public NonTerminal{};
    class FuncDecl : public NonTerminal{};
    class RetType : public NonTerminal{
    public:
        RetType(const string& type) : NonTerminal("", type) {}

    };
    class Formals : public NonTerminal{
        public:
        list<Variable> namesAndTypes;
        Formals(list<Variable>& namesAndTypes) : NonTerminal("", ""), namesAndTypes(namesAndTypes) {}
    };
    class FormalsList : public NonTerminal{
        public:
            list<Variable> namesAndTypes;
            FormalsList(const string& name, const string& type) : NonTerminal("", "") {
                namesAndTypes.push_back(Variable(name, type));
            }

    };
	class FormalDecl : public NonTerminal{
	public:
	    FormalDecl(const string& name, const string& type) : NonTerminal(name, type) {}
	};
    class Statements : public NonTerminal{
    public:
        Statements(const string& type): NonTerminal("", type){}
    };
	class Statement : public NonTerminal{
	    public:
            bool is_break;
            bool is_continue;
            Statement(const string& type): NonTerminal("", type), is_break(false), is_continue(false){}
            Statement(const string& type, bool is_break, bool is_continue): NonTerminal("", type), is_break(is_break), is_continue(is_continue){}
	};
	class Call : public NonTerminal{
	public:
	    Call(const string& name, const string& type) : NonTerminal(name, type){}

	};
	class ExpList : public NonTerminal{
	    public:
	    ExpList() : NonTerminal("", "")  {}
	};
    class Type : public NonTerminal{
        public:
        Type(const string& type) : NonTerminal("", type) {}
    };
    class Exp : public NonTerminal{
        public:
        Exp(const string& type) : NonTerminal("", type) {}
    };

    static string typeBinopAddChecking(string type1, string type2){
        if (type1 == "INT" || type2 == "INT"){
            return "INT";
        }
        if(type1 == "BYTE" || type2 == "BYTE"){
            return "BYTE";
        }
        if(type1 == "SET" && type2 == "SET"){
            throw Exceptions::MismatchException(yylineno);
        }
        return "SET";
    }

    string typeBinopMultiplicativeChecking(string type1, string type2){
        if(type1 == "SET" || type2 == "SET"){
            throw Exceptions::MismatchException(yylineno);
        }
        if (type1 == "INT" || type2 == "INT"){
            return "INT";
        }
        return "BYTE";
    }



#line 187 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    OR = 259,
    AND = 260,
    RELOP_EQUALITY = 261,
    RELOP_RELATIONAL = 262,
    BINOP_ADDITIVE = 263,
    BINOP_MULTIPLICATIVE = 264,
    NOT = 265,
    SC = 266,
    RPAREN = 267,
    RBRACE = 268,
    RBRACKET = 269,
    LBRACE = 270,
    LPAREN = 271,
    LBRACKET = 272,
    COMMA = 273,
    WHILE = 274,
    ELSE = 275,
    IF = 276,
    TRUE = 277,
    FALSE = 278,
    RETURN = 279,
    BREAK = 280,
    CONTINUE = 281,
    DOTS = 282,
    ID = 283,
    NUM = 284,
    STRING = 285,
    SET = 286,
    INT = 287,
    BYTE = 288,
    B = 289,
    BOOL = 290,
    VOID = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   149,   150,   151,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   181,   191,   200,   205,   210,   225,
     235,   239,   240,   241,   242,   243,   244,   245,   249,   253,
     263,   264,   265,   266,   267,   268,   269,   277,   285,   293,
     301,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "OR", "AND", "RELOP_EQUALITY",
  "RELOP_RELATIONAL", "BINOP_ADDITIVE", "BINOP_MULTIPLICATIVE", "NOT",
  "SC", "RPAREN", "RBRACE", "RBRACKET", "LBRACE", "LPAREN", "LBRACKET",
  "COMMA", "WHILE", "ELSE", "IF", "TRUE", "FALSE", "RETURN", "BREAK",
  "CONTINUE", "DOTS", "ID", "NUM", "STRING", "SET", "INT", "BYTE", "B",
  "BOOL", "VOID", "$accept", "Program", "Funcs", "FuncDecl", "RetType",
  "Formals", "FormalsList", "FormalDecl", "Statements", "Statement",
  "Call", "ExpList", "Type", "Exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    -3,   -36,   -36,   -36,   -36,    15,   -36,     6,     5,
     -36,     7,   -36,   -36,    41,    31,   -25,    35,    48,   -36,
      49,    38,    56,    57,   -25,   -36,   -36,   103,   -36,   103,
      55,    68,   129,    72,    74,     1,    67,   -36,    76,    61,
      88,   153,   153,   153,   -36,    46,   -36,   -36,    78,    62,
     -36,   -36,   205,   -36,   -36,   153,   132,   -36,   -36,   -36,
       0,   -36,    22,   187,   -36,    85,   196,   -36,   153,   153,
     153,   153,   153,   153,   -36,   213,   -36,    92,   180,   153,
     -36,   103,   103,   153,   -36,   159,   164,    11,    36,    81,
     -36,   -36,   -36,   153,   221,   -36,    86,   -36,   -36,   -36,
     103,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    32,    33,    34,     7,     0,     2,     3,     0,
       6,     0,     1,     4,     0,     0,     8,     0,     0,     9,
      10,     0,     0,     0,     0,    12,    35,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,     0,    21,     0,    44,    45,    39,    41,
      43,    40,     0,    26,    27,     0,     0,     5,    15,    20,
       0,    16,     0,     0,    46,     0,     0,    42,     0,     0,
       0,     0,     0,     0,    22,     0,    29,     0,    30,     0,
      17,     0,     0,     0,    36,    48,    47,    50,    49,    37,
      38,    19,    28,     0,     0,    25,    23,    51,    31,    18,
       0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,    97,   -36,   -36,   -36,    84,   -36,    82,   -35,
     -27,    17,    16,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    18,    19,    20,    36,    37,
      51,    77,    39,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    58,    38,    79,    55,    58,     1,     2,     3,    38,
       4,    80,    52,    38,    11,    12,    10,    56,    71,    72,
      73,    62,    63,    64,    10,    66,    68,    69,    70,    71,
      72,    73,    21,    14,    81,    75,    15,     1,     2,     3,
      21,     4,     5,    -1,    72,    73,    95,    96,    85,    86,
      87,    88,    89,    90,    38,    38,    43,    16,    17,    94,
      23,    65,    45,    97,    22,   101,    25,    24,    46,    47,
      26,    41,    27,    38,    48,    49,    50,     1,     2,     3,
      57,     4,    29,    53,    42,    54,    30,    59,    31,    60,
      73,    32,    33,    34,    56,    35,    67,    83,     1,     2,
       3,    61,     4,    29,    92,    13,   100,    30,    28,    31,
      98,    40,    32,    33,    34,     0,    35,     0,    29,     1,
       2,     3,    30,     4,    31,     0,     0,    32,    33,    34,
       0,    35,     0,     0,     1,     2,     3,     0,     4,    43,
      44,     0,    43,     0,    76,    45,     0,     0,    45,     0,
       0,    46,    47,     0,    46,    47,     0,    48,    49,    50,
      48,    49,    50,    43,    69,    70,    71,    72,    73,    45,
      70,    71,    72,    73,     0,    46,    47,     0,     0,     0,
       0,    48,    49,    50,    68,    69,    70,    71,    72,    73,
       0,    68,    69,    70,    71,    72,    73,     0,    93,    82,
      68,    69,    70,    71,    72,    73,     0,     0,    84,    68,
      69,    70,    71,    72,    73,     0,    74,    68,    69,    70,
      71,    72,    73,     0,    91,    68,    69,    70,    71,    72,
      73,     0,    99
};

static const yytype_int8 yycheck[] =
{
      27,    36,    29,     3,     3,    40,    31,    32,    33,    36,
      35,    11,    32,    40,    17,     0,     0,    16,     7,     8,
       9,    41,    42,    43,     8,    45,     4,     5,     6,     7,
       8,     9,    16,    28,    12,    55,    29,    31,    32,    33,
      24,    35,    36,     7,     8,     9,    81,    82,    68,    69,
      70,    71,    72,    73,    81,    82,    10,    16,    27,    79,
      12,    45,    16,    83,    29,   100,    28,    18,    22,    23,
      14,    16,    15,   100,    28,    29,    30,    31,    32,    33,
      13,    35,    15,    11,    16,    11,    19,    11,    21,    28,
       9,    24,    25,    26,    16,    28,    34,    12,    31,    32,
      33,    13,    35,    15,    12,     8,    20,    19,    24,    21,
      93,    29,    24,    25,    26,    -1,    28,    -1,    15,    31,
      32,    33,    19,    35,    21,    -1,    -1,    24,    25,    26,
      -1,    28,    -1,    -1,    31,    32,    33,    -1,    35,    10,
      11,    -1,    10,    -1,    12,    16,    -1,    -1,    16,    -1,
      -1,    22,    23,    -1,    22,    23,    -1,    28,    29,    30,
      28,    29,    30,    10,     5,     6,     7,     8,     9,    16,
       6,     7,     8,     9,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,     4,     5,     6,     7,     8,     9,
      -1,     4,     5,     6,     7,     8,     9,    -1,    18,    12,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,     4,
       5,     6,     7,     8,     9,    -1,    11,     4,     5,     6,
       7,     8,     9,    -1,    11,     4,     5,     6,     7,     8,
       9,    -1,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    35,    36,    38,    39,    40,    41,
      49,    17,     0,    39,    28,    29,    16,    27,    42,    43,
      44,    49,    29,    12,    18,    28,    14,    15,    43,    15,
      19,    21,    24,    25,    26,    28,    45,    46,    47,    49,
      45,    16,    16,    10,    11,    16,    22,    23,    28,    29,
      30,    47,    50,    11,    11,     3,    16,    13,    46,    11,
      28,    13,    50,    50,    50,    49,    50,    34,     4,     5,
       6,     7,     8,     9,    11,    50,    12,    48,    50,     3,
      11,    12,    12,    12,    12,    50,    50,    50,    50,    50,
      50,    11,    12,    18,    50,    46,    46,    50,    48,    11,
      20,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     8,     1,     1,     0,     1,
       1,     3,     2,     2,     1,     2,     3,     3,     5,     4,
       2,     2,     3,     5,     7,     5,     2,     2,     4,     3,
       1,     3,     1,     1,     1,     6,     3,     3,     3,     1,
       1,     1,     2,     1,     1,     1,     2,     3,     3,     3,
       3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 148 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1446 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 149 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1452 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 150 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1458 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 151 "parser.ypp" /* yacc.c:1646  */
    {
                    Framework::getInstance().addFunction(Function((yyvsp[-6]).name,(yyvsp[-7]).type, (yyvsp[-4]).namesAndTypes));
                }
#line 1466 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = RetType((yyvsp[0]).type);}
#line 1472 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 155 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = RetType((yyvsp[0]).type);}
#line 1478 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1484 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 157 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = Formals((yyvsp[0]).namesAndTypes);}
#line 1490 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 158 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = FormalsList((yyvsp[0]).name, (yyvsp[0]).type);}
#line 1496 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 159 "parser.ypp" /* yacc.c:1646  */
    {(yyval).addParamToFunc((yyvsp[-2]).name,(yyvsp[-2]).type);}
#line 1502 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 160 "parser.ypp" /* yacc.c:1646  */
    {FormalDecl((yyvsp[-1]).type, (yyvsp[0]).name);}
#line 1508 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "parser.ypp" /* yacc.c:1646  */
    {FormalDecl((yyvsp[-1]).type, (yyvsp[0]).name);}
#line 1514 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = Statements((yyvsp[0]).type);}
#line 1520 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 163 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1526 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 164 "parser.ypp" /* yacc.c:1646  */
    {Framework::getInstance().addScope(Scope::BLOCK);}
#line 1532 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 165 "parser.ypp" /* yacc.c:1646  */
    { Framework::getInstance().insertVariableIntoTopScope(Variable((yyvsp[-1]).name,(yyvsp[-2]).type));}
#line 1538 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 166 "parser.ypp" /* yacc.c:1646  */
    { Framework::getInstance().insertVariableIntoTopScope(Variable((yyvsp[-3]).name,(yyvsp[-4]).type));}
#line 1544 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 167 "parser.ypp" /* yacc.c:1646  */
    {printf("------=-------");}
#line 1550 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 168 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1556 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = Statement("VOID");}
#line 1562 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 170 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = Statement((yyvsp[-1]).type);}
#line 1568 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 171 "parser.ypp" /* yacc.c:1646  */
    {
                        printf("-----------if-------------");
                        if ((yyvsp[-2]).type == "BOOL"){
                            Framework::getInstance().addScope(Scope::IF);
                        }
                        else{
                             throw Exceptions::MismatchException(yylineno);
                        }

                    }
#line 1583 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {
                        if ((yyvsp[-4]).type == "BOOL"){
                            Framework::getInstance().addScope(Scope::IF);
                            Framework::getInstance().addScope(Scope::IF);
                        }
                        else{
                             throw Exceptions::MismatchException(yylineno);
                        }

                    }
#line 1598 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 191 "parser.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[-2]).type == "BOOL"){
                        Framework::getInstance().addScope(Scope::LOOP);
                    }
                    else{
                        throw Exceptions::MismatchException(yylineno);
                    }

                    }
#line 1612 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 200 "parser.ypp" /* yacc.c:1646  */
    {
                        if(Framework::getInstance().getTopScope().getScopeType() != Scope::LOOP){
                             throw Exceptions::UnexpectedBreakException(yylineno);
                    }
                     }
#line 1622 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 205 "parser.ypp" /* yacc.c:1646  */
    {
                        if(Framework::getInstance().getTopScope().getScopeType() != Scope::LOOP){
                            throw Exceptions::UnexpectedContinueException(yylineno);
                        }
                    }
#line 1632 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "parser.ypp" /* yacc.c:1646  */
    {
                        //TODO: do not use symbol_table.operator[], instead use Framework.operator[].  And don't check if returned NULL, instead just catch IdentifierDoesNotExistException
                        try{
                            string type = Framework::getInstance()[(yyvsp[-3]).name].type; // check the syntax. need Framework::getInstance().symbol_table[$1.name] to be a "Function" struct
                            if(varsListToTypesList(dynamic_cast<Function&>(Framework::getInstance()[(yyvsp[-3]).name]).getParameters()) != (yyvsp[-1]).arrguments_list){
                                throw Exceptions::PrototypeMismatchException(yylineno,(yyvsp[-3]).name,dynamic_cast<Function&>(Framework::getInstance()[(yyvsp[-3]).name]).getParameters());
                            }
                            (yyval) = Call ((yyvsp[-3]).name, type);
                        }
                        catch(Exceptions::IdentifierDoesNotExistException &e){
                            throw Exceptions::UndefFuncException(yylineno, (yyvsp[-3]).name);
                        }


                    }
#line 1652 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 225 "parser.ypp" /* yacc.c:1646  */
    {

                        try{
                               string type = Framework::getInstance()[(yyvsp[-2]).name].type;
                               (yyval) = Call ((yyvsp[-2]).name, type);
                        }
                        catch(Exceptions::IdentifierDoesNotExistException &e){
                            throw Exceptions::UndefFuncException(yylineno, (yyvsp[-2]).name);
                        }
                    }
#line 1667 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 235 "parser.ypp" /* yacc.c:1646  */
    {   (yyval) = ExpList(); // making the one size list by adding the EXP type into the list
                        (yyval).arrguments_list.push_back((yyvsp[0]).type);

                     }
#line 1676 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 239 "parser.ypp" /* yacc.c:1646  */
    { (yyval).arrguments_list.push_back((yyvsp[-2]).type);}
#line 1682 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 240 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = Type("INT");}
#line 1688 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 241 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Type("BYTE");}
#line 1694 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 242 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Type("BOOL");}
#line 1700 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 243 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = Type("SET");}
#line 1706 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 244 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Exp((yyvsp[-1]).type);}
#line 1712 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 245 "parser.ypp" /* yacc.c:1646  */
    {
                        string res_type = typeBinopAddChecking((yyvsp[-2]).type, (yyvsp[0]).type);
                        (yyval) = Exp(res_type);
                        }
#line 1721 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 249 "parser.ypp" /* yacc.c:1646  */
    {
                        string res_type = typeBinopMultiplicativeChecking((yyvsp[-2]).type, (yyvsp[0]).type);
                        (yyval) = Exp(res_type);
                    }
#line 1730 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 253 "parser.ypp" /* yacc.c:1646  */
    {
                            try{
                                (yyval) =  Exp(Framework::getInstance()[(yyvsp[0]).name].type);
                            }
                            catch(Exceptions::IdentifierDoesNotExistException &e){
                                throw Exceptions::UndefException(yylineno, (yyvsp[0]).name);
                            }


                      }
#line 1745 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 263 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Exp((yyvsp[0]).type);}
#line 1751 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 264 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = Exp("INT");}
#line 1757 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 265 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Exp("BYTE");}
#line 1763 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 266 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Exp("STRING");}
#line 1769 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Exp("BOOL");}
#line 1775 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "parser.ypp" /* yacc.c:1646  */
    {(yyval) =  Exp("BOOL");}
#line 1781 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 269 "parser.ypp" /* yacc.c:1646  */
    {
                        if((yyvsp[0]).type != "BOOL"){
                            throw Exceptions::MismatchException(yylineno);
                        }
                        else{
                            (yyval) =  Exp("BOOL");
                        }
                    }
#line 1794 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 277 "parser.ypp" /* yacc.c:1646  */
    {
                        if((yyvsp[-2]).type != "BOOL" || (yyvsp[0]).type != "BOOL"){
                           throw Exceptions::MismatchException(yylineno);
                       }
                       else{
                           (yyval) =  Exp("BOOL");
                       }
                    }
#line 1807 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 285 "parser.ypp" /* yacc.c:1646  */
    {
                        if((yyvsp[-2]).type != "BOOL" || (yyvsp[0]).type != "BOOL"){
                           throw Exceptions::MismatchException(yylineno);
                       }
                       else{
                           (yyval) =  Exp("BOOL");
                       }
                    }
#line 1820 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 293 "parser.ypp" /* yacc.c:1646  */
    {
                        if(((yyvsp[-2]).type != "INT" && (yyvsp[-2]).type != "BYTE") || ((yyvsp[-1]).type != "INT" && (yyvsp[-1]).type != "BYTE")){
                            throw Exceptions::MismatchException(yylineno);
                        }
                        else{
                            (yyval) =  Exp ("BOOL");
                        }
                    }
#line 1833 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 301 "parser.ypp" /* yacc.c:1646  */
    {
                        if(((yyvsp[-2]).type != "INT" && (yyvsp[-2]).type != "BYTE") || ((yyvsp[-1]).type != "INT" && (yyvsp[-1]).type != "BYTE")){
                          throw Exceptions::MismatchException(yylineno);
                      }
                      else{
                          (yyval) =  Exp ("BOOL");
                      }
                    }
#line 1846 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 309 "parser.ypp" /* yacc.c:1646  */
    {
                        if((yyvsp[-2]).type != "INT" || (yyvsp[0]).type !="SET"){
                            throw Exceptions::MismatchException(yylineno);
                        }
                        else{
                            (yyval) =  Exp("INT");
                        }

                    }
#line 1860 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1864 "parser.tab.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */ //
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 319 "parser.ypp" /* yacc.c:1906  */

void yyerror(const char*){
	output::errorSyn(yylineno);
}

int main(){
    try{
    	yyparse();
	    if (!Framework::getInstance().mainExists) throw Exceptions::NoMainException();
    }
    catch (Exceptions::HW3_Exception& e){
        e.printError();
    }
}
