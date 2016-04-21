/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         quickstep_yyparse
#define yylex           quickstep_yylex
#define yyerror         quickstep_yyerror
#define yydebug         quickstep_yydebug
#define yynerrs         quickstep_yynerrs


/* Copy the first part of user declarations.  */
#line 35 "../SqlParser.ypp" /* yacc.c:339  */


/* Override the default definition, as we only need <first_line> and <first_column>. */
typedef struct YYLTYPE {
  int first_line;
  int first_column;
} YYLTYPE;

#define YYLTYPE_IS_DECLARED 1

/*
 * Modified from the default YYLLOC_DEFAULT
 * (http://www.gnu.org/software/bison/manual/html_node/Location-Default-Action.html).
 * The assignments for last_line and last_column are removed as they are not used.
 */
#define YYLLOC_DEFAULT(current, rhs, n)                         \
  do {                                                          \
    if (n) {                                                    \
      (current).first_line   = YYRHSLOC(rhs, 1).first_line;     \
      (current).first_column = YYRHSLOC(rhs, 1).first_column;   \
    } else {                                                    \
      /* empty RHS */                                           \
      (current).first_line = YYRHSLOC(rhs, 0).first_line;       \
      (current).first_column = YYRHSLOC(rhs, 0).first_column;   \
    }                                                           \
  } while (0)

#line 64 "../SqlParser.ypp" /* yacc.c:339  */

#include <cstdlib>
#include <string>
#include <utility>

#include "catalog/PartitionSchemeHeader.hpp"
#include "parser/ParseAssignment.hpp"
#include "parser/ParseAttributeDefinition.hpp"
#include "parser/ParseBasicExpressions.hpp"
#include "parser/ParseBlockProperties.hpp"
#include "parser/ParseCaseExpressions.hpp"
#include "parser/ParseExpression.hpp"
#include "parser/ParseGeneratorTableReference.hpp"
#include "parser/ParseGroupBy.hpp"
#include "parser/ParseHaving.hpp"
#include "parser/ParseJoinedTableReference.hpp"
#include "parser/ParseKeyValue.hpp"
#include "parser/ParseLimit.hpp"
#include "parser/ParseWindow.hpp"
#include "parser/ParseLiteralValue.hpp"
#include "parser/ParseOrderBy.hpp"
#include "parser/ParsePartitionClause.hpp"
#include "parser/ParsePredicate.hpp"
#include "parser/ParsePredicateExists.hpp"
#include "parser/ParsePredicateInTableQuery.hpp"
#include "parser/ParserUtil.hpp"
#include "parser/ParseSample.hpp"
#include "parser/ParseSelect.hpp"
#include "parser/ParseSelectionClause.hpp"
#include "parser/ParseSimpleTableReference.hpp"
#include "parser/ParseStatement.hpp"
#include "parser/ParseString.hpp"
#include "parser/ParseSubqueryExpression.hpp"
#include "parser/ParseSubqueryTableReference.hpp"
#include "parser/ParseTableReference.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "types/Type.hpp"
#include "types/TypeFactory.hpp"
#include "types/TypeID.hpp"
#include "types/operations/binary_operations/BinaryOperation.hpp"
#include "types/operations/binary_operations/BinaryOperationFactory.hpp"
#include "types/operations/binary_operations/BinaryOperationID.hpp"
#include "types/operations/comparisons/Comparison.hpp"
#include "types/operations/comparisons/ComparisonFactory.hpp"
#include "types/operations/comparisons/ComparisonID.hpp"
#include "types/operations/unary_operations/UnaryOperation.hpp"
#include "types/operations/unary_operations/UnaryOperationFactory.hpp"
#include "types/operations/unary_operations/UnaryOperationID.hpp"
#include "utility/PtrList.hpp"
#include "utility/PtrVector.hpp"

// Needed for Bison 2.6 and higher, which do not automatically provide this typedef.
typedef void* yyscan_t;

#line 155 "SqlParser_gen.cpp" /* yacc.c:339  */

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
   by #include "SqlParser_gen.hpp".  */
#ifndef YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED
# define YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int quickstep_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_COMMAND = 258,
    TOKEN_NAME = 259,
    TOKEN_STRING_SINGLE_QUOTED = 260,
    TOKEN_STRING_DOUBLE_QUOTED = 261,
    TOKEN_UNSIGNED_NUMVAL = 262,
    TOKEN_OR = 263,
    TOKEN_AND = 264,
    TOKEN_NOT = 265,
    TOKEN_EQ = 266,
    TOKEN_LT = 267,
    TOKEN_LEQ = 268,
    TOKEN_GT = 269,
    TOKEN_GEQ = 270,
    TOKEN_NEQ = 271,
    TOKEN_LIKE = 272,
    TOKEN_REGEXP = 273,
    TOKEN_BETWEEN = 274,
    TOKEN_IS = 275,
    UNARY_PLUS = 276,
    UNARY_MINUS = 277,
    TOKEN_ADD = 278,
    TOKEN_AGE = 279,
    TOKEN_ALL = 280,
    TOKEN_ALTER = 281,
    TOKEN_AS = 282,
    TOKEN_ASC = 283,
    TOKEN_BIGINT = 284,
    TOKEN_BIT = 285,
    TOKEN_BITWEAVING = 286,
    TOKEN_BLOCKPROPERTIES = 287,
    TOKEN_BLOCKSAMPLE = 288,
    TOKEN_BLOOM_FILTER = 289,
    TOKEN_CSB_TREE = 290,
    TOKEN_BY = 291,
    TOKEN_CASE = 292,
    TOKEN_CHARACTER = 293,
    TOKEN_CHECK = 294,
    TOKEN_COLUMN = 295,
    TOKEN_CONSTRAINT = 296,
    TOKEN_COPY = 297,
    TOKEN_CREATE = 298,
    TOKEN_DATE = 299,
    TOKEN_DATETIME = 300,
    TOKEN_DECIMAL = 301,
    TOKEN_DEFAULT = 302,
    TOKEN_DELETE = 303,
    TOKEN_DELIMITER = 304,
    TOKEN_DESC = 305,
    TOKEN_DISTINCT = 306,
    TOKEN_DOUBLE = 307,
    TOKEN_DROP = 308,
    TOKEN_ELSE = 309,
    TOKEN_END = 310,
    TOKEN_ESCAPE_STRINGS = 311,
    TOKEN_EMIT = 312,
    TOKEN_EXISTS = 313,
    TOKEN_EXTRACT = 314,
    TOKEN_FALSE = 315,
    TOKEN_FIRST = 316,
    TOKEN_FLOAT = 317,
    TOKEN_FOREIGN = 318,
    TOKEN_FROM = 319,
    TOKEN_FULL = 320,
    TOKEN_GROUP = 321,
    TOKEN_HASH = 322,
    TOKEN_HAVING = 323,
    TOKEN_IN = 324,
    TOKEN_INDEX = 325,
    TOKEN_INNER = 326,
    TOKEN_INSERT = 327,
    TOKEN_INTEGER = 328,
    TOKEN_INTERVAL = 329,
    TOKEN_INTO = 330,
    TOKEN_JOIN = 331,
    TOKEN_KEY = 332,
    TOKEN_LAST = 333,
    TOKEN_LEFT = 334,
    TOKEN_LIMIT = 335,
    TOKEN_LONG = 336,
    TOKEN_NULL = 337,
    TOKEN_NULLS = 338,
    TOKEN_OFF = 339,
    TOKEN_ON = 340,
    TOKEN_ORDER = 341,
    TOKEN_OUTER = 342,
    TOKEN_PARTITION = 343,
    TOKEN_PARTITIONS = 344,
    TOKEN_PERCENT = 345,
    TOKEN_PRIMARY = 346,
    TOKEN_QUIT = 347,
    TOKEN_RANGE = 348,
    TOKEN_REAL = 349,
    TOKEN_REFERENCES = 350,
    TOKEN_RIGHT = 351,
    TOKEN_ROW_DELIMITER = 352,
    TOKEN_SELECT = 353,
    TOKEN_SET = 354,
    TOKEN_SMA = 355,
    TOKEN_SMALLINT = 356,
    TOKEN_TABLE = 357,
    TOKEN_THEN = 358,
    TOKEN_TIME = 359,
    TOKEN_TIMESTAMP = 360,
    TOKEN_TRUE = 361,
    TOKEN_TUPLESAMPLE = 362,
    TOKEN_UNIQUE = 363,
    TOKEN_UPDATE = 364,
    TOKEN_USING = 365,
    TOKEN_VALUES = 366,
    TOKEN_VARCHAR = 367,
    TOKEN_WHEN = 368,
    TOKEN_WHERE = 369,
    TOKEN_WITH = 370,
    TOKEN_WINDOW = 371,
    TOKEN_YEARMONTH = 372,
    TOKEN_EOF = 373,
    TOKEN_LEX_ERROR = 374
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 119 "../SqlParser.ypp" /* yacc.c:355  */

  quickstep::ParseString *string_value_;

  quickstep::PtrList<quickstep::ParseString> *string_list_;

  bool boolean_value_;

  quickstep::NumericParseLiteralValue *numeric_literal_value_;
  quickstep::ParseLiteralValue *literal_value_;
  quickstep::PtrList<quickstep::ParseScalarLiteral> *literal_value_list_;

  quickstep::ParseExpression *expression_;

  quickstep::ParseScalarLiteral *scalar_literal_;
  quickstep::ParseAttribute *attribute_;
  quickstep::PtrList<quickstep::ParseAttribute> *attribute_list_;

  quickstep::ParsePredicate *predicate_;

  quickstep::ParseSubqueryExpression *subquery_expression_;

  quickstep::PtrVector<quickstep::ParseSimpleWhenClause> *simple_when_clause_list_;
  quickstep::ParseSimpleWhenClause *simple_when_clause_;

  quickstep::PtrVector<quickstep::ParseSearchedWhenClause> *searched_when_clause_list_;
  quickstep::ParseSearchedWhenClause *searched_when_clause_;

  quickstep::ParseSelectionClause *selection_;
  quickstep::ParseSelectionItem *selection_item_;
  quickstep::ParseSelectionList *selection_list_;

  quickstep::ParseTableReference *table_reference_;
  quickstep::PtrList<quickstep::ParseTableReference> *table_reference_list_;
  quickstep::ParseTableReferenceSignature *table_reference_signature_;

  quickstep::ParseJoinedTableReference::JoinType join_type_;

  quickstep::ParseDataType *data_type_;
  quickstep::ParseAttributeDefinition *attribute_definition_;
  quickstep::ParseColumnConstraint *column_constraint_;
  quickstep::PtrList<quickstep::ParseColumnConstraint> *column_constraint_list_;
  quickstep::PtrList<quickstep::ParseAttributeDefinition> *attribute_definition_list_;

  quickstep::ParseKeyValue *key_value_;
  quickstep::PtrList<quickstep::ParseKeyValue> *key_value_list_;
  quickstep::ParseKeyStringValue *key_string_value_;
  quickstep::ParseKeyStringList *key_string_list_;
  quickstep::ParseKeyIntegerValue *key_integer_value_;

  quickstep::ParseCopyFromParams *copy_from_params_;

  quickstep::ParseAssignment *assignment_;
  quickstep::PtrList<quickstep::ParseAssignment> *assignment_list_;

  quickstep::ParseCommand *command_;
  quickstep::PtrVector<quickstep::ParseString> *command_argument_list_;

  quickstep::ParseStatement *statement_;
  quickstep::ParseStatementSelect *select_statement_;
  quickstep::ParseStatementUpdate *update_statement_;
  quickstep::ParseStatementInsert *insert_statement_;
  quickstep::ParseStatementDelete *delete_statement_;
  quickstep::ParseStatementCopyFrom *copy_from_statement_;
  quickstep::ParseStatementCreateTable *create_table_statement_;
  quickstep::ParsePartitionClause *partition_clause_;
  quickstep::ParseBlockProperties *block_properties_;
  quickstep::ParseStatementDropTable *drop_table_statement_;
  quickstep::ParseStatementQuit *quit_statement_;

  const quickstep::Comparison *comparison_;
  const quickstep::UnaryOperation *unary_operation_;
  const quickstep::BinaryOperation *binary_operation_;

  quickstep::ParseFunctionCall *function_call_;
  quickstep::PtrList<quickstep::ParseExpression> *expression_list_;
  quickstep::PtrList<quickstep::ParseExpression> *window_partition_by_list_;

  quickstep::ParseSelect *select_query_;
  quickstep::ParseGroupBy *opt_group_by_clause_;
  quickstep::ParseHaving *opt_having_clause_;
  quickstep::ParseOrderBy *opt_order_by_clause_;
  bool *order_direction_;
  quickstep::ParseLimit *opt_limit_clause_;
  quickstep::ParseSample *opt_sample_clause_;
  quickstep::ParseWindow *opt_window_clause_;

  quickstep::PtrList<quickstep::ParseOrderByItem> *order_commalist_;
  quickstep::ParseOrderByItem *order_item_;

  quickstep::PtrVector<quickstep::ParseSubqueryTableReference> *with_list_;
  quickstep::ParseSubqueryTableReference *with_list_element_;

#line 408 "SqlParser_gen.cpp" /* yacc.c:355  */
};
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



int quickstep_yyparse (yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement);

#endif /* !YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 212 "../SqlParser.ypp" /* yacc.c:358  */

/* This header needs YYSTYPE, which is defined by the %union directive above */
#include "SqlLexer_gen.hpp"
void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature);

#line 441 "SqlParser_gen.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1047

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  131
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  262
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  487

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     126,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   130,     2,     2,
     127,   128,    23,    21,   129,    22,    27,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   125,
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
      15,    16,    17,    18,    19,    20,    25,    26,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   595,   595,   599,   603,   607,   611,   614,   621,   624,
     627,   630,   633,   636,   639,   642,   645,   648,   654,   660,
     667,   673,   680,   689,   694,   703,   708,   713,   717,   723,
     728,   731,   734,   739,   742,   745,   748,   751,   754,   757,
     760,   763,   766,   778,   781,   784,   802,   822,   825,   828,
     833,   838,   844,   850,   859,   863,   869,   872,   877,   882,
     887,   894,   901,   905,   911,   914,   919,   922,   927,   930,
     935,   938,   957,   961,   967,   971,   977,   980,   983,   988,
     991,   998,  1003,  1014,  1019,  1023,  1027,  1033,  1036,  1042,
    1050,  1053,  1056,  1062,  1067,  1070,  1075,  1079,  1083,  1087,
    1093,  1098,  1103,  1107,  1113,  1119,  1122,  1127,  1132,  1136,
    1142,  1148,  1154,  1157,  1161,  1167,  1170,  1175,  1179,  1185,
    1188,  1191,  1196,  1201,  1206,  1209,  1212,  1217,  1220,  1223,
    1226,  1229,  1232,  1235,  1238,  1243,  1246,  1251,  1255,  1259,
    1262,  1266,  1269,  1274,  1277,  1282,  1285,  1290,  1294,  1300,
    1303,  1308,  1311,  1316,  1319,  1324,  1327,  1346,  1349,  1354,
    1359,  1364,  1367,  1372,  1377,  1382,  1386,  1392,  1399,  1402,
    1405,  1410,  1413,  1416,  1422,  1425,  1430,  1435,  1444,  1449,
    1458,  1463,  1466,  1471,  1474,  1479,  1485,  1491,  1494,  1497,
    1500,  1503,  1506,  1512,  1521,  1524,  1529,  1532,  1537,  1540,
    1545,  1548,  1551,  1554,  1557,  1560,  1565,  1569,  1573,  1576,
    1581,  1586,  1589,  1594,  1598,  1604,  1609,  1613,  1619,  1624,
    1627,  1632,  1636,  1642,  1645,  1648,  1651,  1663,  1667,  1686,
    1701,  1705,  1711,  1714,  1719,  1723,  1730,  1733,  1736,  1739,
    1742,  1745,  1748,  1751,  1754,  1757,  1762,  1773,  1776,  1781,
    1784,  1787,  1793,  1797,  1803,  1806,  1814,  1817,  1820,  1823,
    1829,  1834,  1839
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_COMMAND", "TOKEN_NAME",
  "TOKEN_STRING_SINGLE_QUOTED", "TOKEN_STRING_DOUBLE_QUOTED",
  "TOKEN_UNSIGNED_NUMVAL", "TOKEN_OR", "TOKEN_AND", "TOKEN_NOT",
  "TOKEN_EQ", "TOKEN_LT", "TOKEN_LEQ", "TOKEN_GT", "TOKEN_GEQ",
  "TOKEN_NEQ", "TOKEN_LIKE", "TOKEN_REGEXP", "TOKEN_BETWEEN", "TOKEN_IS",
  "'+'", "'-'", "'*'", "'/'", "UNARY_PLUS", "UNARY_MINUS", "'.'",
  "TOKEN_ADD", "TOKEN_AGE", "TOKEN_ALL", "TOKEN_ALTER", "TOKEN_AS",
  "TOKEN_ASC", "TOKEN_BIGINT", "TOKEN_BIT", "TOKEN_BITWEAVING",
  "TOKEN_BLOCKPROPERTIES", "TOKEN_BLOCKSAMPLE", "TOKEN_BLOOM_FILTER",
  "TOKEN_CSB_TREE", "TOKEN_BY", "TOKEN_CASE", "TOKEN_CHARACTER",
  "TOKEN_CHECK", "TOKEN_COLUMN", "TOKEN_CONSTRAINT", "TOKEN_COPY",
  "TOKEN_CREATE", "TOKEN_DATE", "TOKEN_DATETIME", "TOKEN_DECIMAL",
  "TOKEN_DEFAULT", "TOKEN_DELETE", "TOKEN_DELIMITER", "TOKEN_DESC",
  "TOKEN_DISTINCT", "TOKEN_DOUBLE", "TOKEN_DROP", "TOKEN_ELSE",
  "TOKEN_END", "TOKEN_ESCAPE_STRINGS", "TOKEN_EMIT", "TOKEN_EXISTS",
  "TOKEN_EXTRACT", "TOKEN_FALSE", "TOKEN_FIRST", "TOKEN_FLOAT",
  "TOKEN_FOREIGN", "TOKEN_FROM", "TOKEN_FULL", "TOKEN_GROUP", "TOKEN_HASH",
  "TOKEN_HAVING", "TOKEN_IN", "TOKEN_INDEX", "TOKEN_INNER", "TOKEN_INSERT",
  "TOKEN_INTEGER", "TOKEN_INTERVAL", "TOKEN_INTO", "TOKEN_JOIN",
  "TOKEN_KEY", "TOKEN_LAST", "TOKEN_LEFT", "TOKEN_LIMIT", "TOKEN_LONG",
  "TOKEN_NULL", "TOKEN_NULLS", "TOKEN_OFF", "TOKEN_ON", "TOKEN_ORDER",
  "TOKEN_OUTER", "TOKEN_PARTITION", "TOKEN_PARTITIONS", "TOKEN_PERCENT",
  "TOKEN_PRIMARY", "TOKEN_QUIT", "TOKEN_RANGE", "TOKEN_REAL",
  "TOKEN_REFERENCES", "TOKEN_RIGHT", "TOKEN_ROW_DELIMITER", "TOKEN_SELECT",
  "TOKEN_SET", "TOKEN_SMA", "TOKEN_SMALLINT", "TOKEN_TABLE", "TOKEN_THEN",
  "TOKEN_TIME", "TOKEN_TIMESTAMP", "TOKEN_TRUE", "TOKEN_TUPLESAMPLE",
  "TOKEN_UNIQUE", "TOKEN_UPDATE", "TOKEN_USING", "TOKEN_VALUES",
  "TOKEN_VARCHAR", "TOKEN_WHEN", "TOKEN_WHERE", "TOKEN_WITH",
  "TOKEN_WINDOW", "TOKEN_YEARMONTH", "TOKEN_EOF", "TOKEN_LEX_ERROR", "';'",
  "'\\n'", "'('", "')'", "','", "'%'", "$accept", "start", "sql_statement",
  "quit_statement", "alter_table_statement", "create_table_statement",
  "create_index_statement", "drop_table_statement", "column_def",
  "column_def_commalist", "data_type", "column_constraint_def",
  "column_constraint_def_list", "opt_column_constraint_def_list",
  "table_constraint_def", "table_constraint_def_commalist",
  "opt_table_constraint_def_commalist", "opt_column_list",
  "opt_block_properties", "opt_partition_clause", "partition_type",
  "key_value_list", "key_value", "key_string_value", "key_string_list",
  "key_integer_value", "index_type", "opt_index_properties",
  "insert_statement", "copy_from_statement", "opt_copy_from_params",
  "copy_from_params", "update_statement", "delete_statement",
  "assignment_list", "assignment_item", "select_statement", "with_clause",
  "with_list", "with_list_element", "select_query", "opt_all_distinct",
  "selection", "selection_item_commalist", "selection_item", "from_clause",
  "subquery_expression", "opt_sample_clause", "join_type",
  "joined_table_reference", "table_reference", "table_reference_signature",
  "table_reference_signature_primary", "joined_table_reference_commalist",
  "opt_group_by_clause", "opt_having_clause", "opt_order_by_clause",
  "opt_limit_clause", "opt_window_clause", "window_duration",
  "window_attribute", "opt_window_partition", "emit_duration",
  "age_duration", "order_commalist", "order_item", "opt_order_direction",
  "opt_nulls_first", "opt_where_clause", "where_clause", "or_expression",
  "and_expression", "not_expression", "predicate_expression_base",
  "add_expression", "multiply_expression", "unary_expression",
  "expression_base", "function_call", "extract_function",
  "case_expression", "simple_when_clause_list", "simple_when_clause",
  "searched_when_clause_list", "searched_when_clause", "opt_else_clause",
  "expression_list", "literal_value", "literal_value_commalist",
  "attribute_ref", "attribute_ref_list", "comparison_operation",
  "unary_operation", "add_operation", "multiply_operation",
  "name_commalist", "any_name", "boolean_value", "command",
  "command_argument_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    43,    45,    42,    47,   276,   277,    46,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,    59,    10,    40,    41,    44,
      37
};
# endif

#define YYPACT_NINF -221

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-221)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,  -221,  -221,   -78,   191,   -48,    12,   -42,   -11,  -221,
      18,   191,   191,  -221,    73,    82,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,   -21,  -221,    62,   112,
     191,  -221,  -221,    57,   191,   191,   191,   191,   191,  -221,
    -221,   511,    59,    41,  -221,   147,    75,  -221,  -221,  -221,
     146,  -221,  -221,  -221,  -221,    52,   203,   138,   106,   120,
    -221,    87,  -221,  -221,   235,   237,  -221,  -221,  -221,   565,
     130,  -221,   168,  -221,  -221,   134,  -221,  -221,   260,  -221,
    -221,  -221,  -221,  -221,  -221,   140,   192,   791,   273,   220,
     166,  -221,   247,    17,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,   845,    -3,   191,   191,   169,   191,   191,   153,   167,
     180,   191,   191,   457,  -221,  -221,   182,   191,  -221,  -221,
    -221,   457,    46,    -7,  -221,   309,  -221,   191,  -221,   321,
    -221,    21,  -221,    31,   120,   791,  -221,  -221,   191,   791,
    -221,  -221,  -221,  -221,   791,   237,  -221,   191,   367,   -15,
    -221,   330,  -221,   242,  -221,   102,  -221,   242,   191,   128,
     191,   191,   221,  -221,   222,  -221,   127,   925,   651,   169,
     457,   339,   342,  -221,  -221,   348,   333,   899,   131,    20,
     791,     1,  -221,   791,  -221,   295,   228,   299,   248,  -221,
      19,   178,   162,  -221,   249,   178,     0,   306,  -221,  -221,
      17,  -221,  -221,   251,   791,  -221,   253,   148,   191,  -221,
     791,   252,  -221,   191,  -221,  -221,   256,   302,   303,   259,
    -221,  -221,  -221,    36,   191,   272,   128,   191,  -221,   149,
    -221,  -221,     4,   308,   457,   457,    74,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,   791,   264,   791,    34,  -221,
     152,   276,   791,    25,  -221,   334,   253,  -221,  -221,   791,
    -221,    99,   191,  -221,  -221,   304,  -221,   305,   307,   314,
      31,  -221,   391,   396,   178,   363,   332,  -221,   154,  -221,
     791,  -221,   253,  -221,  -221,   457,   279,   280,   191,   403,
     129,   158,  -221,   163,   384,    47,  -221,   283,   293,  -221,
     327,   288,   899,  -221,   343,   191,  -221,  -221,   149,  -221,
    -221,   342,  -221,  -221,  -221,   791,   300,    54,   705,  -221,
     253,   341,  -221,  -221,   899,   311,   253,   791,  -221,    33,
    -221,  -221,  -221,  -221,  -221,    31,   162,   331,   335,  -221,
     791,   457,   338,  -221,   253,     7,   191,   191,   165,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,    55,  -221,   191,  -221,
    -221,  -221,  -221,   312,   128,   395,   340,  -221,   457,  -221,
    -221,   315,  -221,    63,   705,  -221,   791,   170,  -221,  -221,
     899,   253,  -221,   351,  -221,  -221,   318,   339,   402,   364,
    -221,   174,   176,  -221,   443,   129,  -221,   191,  -221,  -221,
     323,   410,  -221,     8,   191,   791,   179,   253,  -221,   184,
     457,   791,   448,   336,   356,  -221,  -221,  -221,   186,  -221,
    -221,  -221,  -221,    15,   191,    94,  -221,   344,   253,  -221,
    -221,   339,   345,  -221,   156,  -221,   899,  -221,   369,   191,
    -221,   191,  -221,  -221,   191,  -221,   205,  -221,  -221,   353,
    -221,   791,  -221,  -221,   372,  -221,   191,   375,   354,  -221,
     207,  -221,   191,  -221,   -13,  -221,  -221,   428,   408,   191,
    -221,   209,  -221,  -221,   791,   899,   442,   211,   381,   318,
    -221,   899,  -221,  -221,   475,  -221,  -221
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     6,   262,     0,     0,     0,     0,     0,     0,    18,
     112,     0,     0,     7,     0,     0,    15,     8,    10,    11,
      13,    14,     9,    17,    12,    16,     0,   105,     0,   260,
       0,   254,   255,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,   107,   108,     0,   145,     1,     3,     2,
       0,   106,     5,     4,   261,     0,     0,     0,     0,   174,
      25,     0,   227,   224,     0,   246,   115,    40,    29,     0,
       0,    30,    31,    34,    36,     0,    37,    39,     0,    41,
     223,    35,    38,    32,    33,     0,     0,     0,     0,     0,
     116,   117,   121,   195,   197,   199,   202,   203,   204,   201,
     200,     0,   232,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,   101,   175,     0,     0,    91,   225,
     226,     0,     0,   219,   216,     0,    43,     0,   228,     0,
      44,     0,   229,     0,   174,     0,   247,   248,     0,     0,
     120,   250,   251,   249,     0,     0,   198,     0,     0,   174,
     103,     0,   109,     0,   110,     0,   252,     0,     0,     0,
       0,     0,     0,    93,    66,    27,     0,     0,     0,     0,
       0,   176,   178,   180,   182,     0,   200,     0,     0,     0,
       0,   219,   213,     0,   217,     0,     0,     0,     0,   205,
       0,     0,   147,   136,   122,   141,   124,   149,   118,   119,
     194,   196,   233,     0,     0,   206,   221,     0,     0,   100,
       0,     0,   146,     0,    92,    19,     0,     0,     0,     0,
      20,    21,    22,     0,     0,     0,    64,     0,    42,    56,
     181,   189,     0,     0,     0,     0,     0,   236,   238,   239,
     240,   241,   237,   242,   244,     0,     0,     0,     0,   230,
       0,     0,     0,     0,   214,     0,   220,   212,    45,     0,
      46,   127,     0,   137,   143,   133,   128,   129,   131,     0,
       0,   140,     0,     0,   139,     0,   151,   207,     0,   208,
       0,   102,   104,   123,   253,     0,     0,     0,     0,     0,
       0,     0,   234,     0,   232,     0,    63,    65,    68,    28,
       0,     0,     0,    47,     0,     0,    49,    55,    57,    26,
     188,   177,   179,   243,   245,     0,     0,     0,     0,   190,
     187,     0,   186,    90,     0,     0,   218,     0,   211,     0,
     142,   144,   134,   130,   132,     0,   148,     0,     0,   138,
       0,     0,   153,   209,   222,     0,     0,     0,     0,    96,
     258,   259,   257,   256,    97,    95,     0,    67,     0,    83,
      84,    85,    86,    87,     0,     0,    70,    48,     0,    51,
      50,     0,    54,     0,     0,   192,     0,     0,   185,   231,
       0,   215,   210,     0,   125,   126,   150,   152,     0,   155,
      61,     0,     0,    58,     0,     0,   235,     0,    24,    62,
       0,     0,    23,     0,     0,     0,     0,   183,   191,     0,
       0,     0,     0,   157,     0,    59,    98,    99,     0,    74,
      76,    77,    78,     0,     0,     0,    52,     0,   184,   193,
      89,   135,   154,   165,   168,   156,     0,   111,     0,     0,
      88,     0,    82,    80,     0,    79,     0,    72,    73,     0,
      53,     0,   169,   170,   171,   159,     0,   161,     0,    75,
       0,    69,     0,   166,     0,   167,   160,     0,     0,     0,
      81,     0,   172,   173,     0,     0,     0,     0,     0,   162,
     163,     0,   158,    60,     0,   164,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -138,  -221,
     316,   177,  -221,  -221,  -220,  -221,  -221,  -221,  -221,  -221,
    -221,    64,    45,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,   282,  -221,  -221,  -221,   383,
      10,  -221,  -221,  -221,   358,  -221,   -91,  -221,  -221,  -172,
     161,  -137,   -10,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,    50,  -221,  -221,   -72,  -221,
    -120,   263,   267,   337,   -30,   359,   360,   409,  -129,  -221,
    -221,  -221,   322,  -221,   386,   346,  -201,  -164,   132,  -104,
    -221,  -221,  -221,  -221,  -221,  -112,    -4,   116,  -221,  -221
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,   165,   166,
      88,   307,   308,   309,   220,   297,   298,   225,   366,   402,
     449,   418,   419,   420,   421,   422,   363,   398,    21,    22,
     163,   291,    23,    24,   149,   150,    25,    26,    43,    44,
     211,    41,    89,    90,    91,   134,   191,   274,   269,   192,
     193,   263,   264,   194,   276,   342,   389,   413,   437,   438,
     457,   468,   476,   482,   432,   433,   454,   465,   114,   115,
     171,   172,   173,   174,   175,    93,    94,    95,    96,    97,
      98,   181,   182,   123,   124,   185,   207,    99,   250,   100,
     293,   247,   101,   139,   144,   155,   102,   354,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   179,    45,   278,   195,   178,   296,    42,    46,   176,
      27,    92,   234,   249,   154,   234,   234,   176,   261,    31,
     215,    32,   442,    31,   147,    32,    55,    34,   234,    30,
      57,    58,    59,    60,    61,    31,    51,    32,   272,   122,
     141,   142,   136,   137,   321,   443,   136,   137,    39,     1,
     232,     2,   183,   472,   136,   137,    50,   131,   271,    35,
     183,   195,   197,   376,   176,    37,   176,   136,   137,    38,
     473,   118,   405,    47,    40,   136,   137,   209,   231,     3,
     108,    36,    10,   359,   136,   137,   360,   361,   140,   299,
     289,   313,   314,   315,    45,     4,     5,   290,   336,   151,
      46,     6,   156,   157,   113,    92,     7,   164,   167,   394,
     109,   121,   273,   156,   208,    54,   395,   377,   206,   180,
     292,   322,    10,   187,   148,     8,    56,   148,   252,   196,
     176,   176,   310,   327,   199,   390,   426,   339,   369,   386,
     233,   195,   444,   202,   399,     9,   190,   143,   316,   189,
     253,    10,   362,   256,   167,   319,   221,   222,   190,   300,
     379,   382,    11,   103,   180,   345,   447,   214,    12,   265,
     104,    13,   216,   406,   206,   266,   348,   136,   137,   105,
     282,   176,    31,   267,    32,    52,   196,    46,    53,   452,
      10,    46,   448,   301,   350,    31,   217,    32,   158,   159,
     268,   302,   106,   116,   151,    48,   195,    49,   110,   284,
     262,   453,   160,   161,   117,   317,   249,   320,   351,   352,
     294,   387,   326,   167,   218,   375,   107,   330,   111,   329,
     212,   213,   265,   112,   391,   392,   303,   176,   266,   113,
     353,   219,   119,  -127,   120,   304,   267,   126,   403,   305,
     344,    31,   331,    32,   396,   226,   227,   125,    46,   251,
     213,   127,   306,   268,   176,   128,   196,   129,   136,   137,
      46,   130,   455,   479,   136,   137,   279,   280,   132,   138,
     323,   324,   343,   280,   156,   373,   355,   356,   206,   133,
     431,   357,   358,   393,   213,   135,   153,   381,   408,   280,
     162,   371,   414,   213,   415,   213,   176,   429,   280,   177,
     206,   480,   430,   324,   440,   441,   186,   485,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   188,   136,
     137,   196,   460,   461,   441,   470,   213,   478,   213,   483,
     213,   210,   156,   156,   206,    10,   407,   234,   223,   224,
     471,   235,   466,   248,   294,   257,   258,   477,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   259,   136,
     137,    31,    62,    32,    63,   428,   260,   275,   270,   277,
     283,   434,   246,   285,   286,   287,   288,   295,    64,    65,
     203,   318,   325,   423,   328,   335,   332,   333,   337,   334,
     427,    67,    68,   338,   340,   341,   346,   347,   349,    69,
      70,   147,   364,   365,   367,   368,    71,    72,    73,   445,
     423,   434,   246,   204,    74,   370,   384,   374,   378,   388,
     385,    75,   400,   401,    76,   458,   189,   423,   380,   397,
     156,   410,   404,   411,   206,    77,    78,   280,   416,   412,
     424,   425,   294,    79,    80,   435,   439,   436,   156,   456,
     464,    31,    62,    32,    63,   156,    81,   168,   467,   474,
     475,   481,   450,    82,   451,   484,    83,    84,    64,    65,
     462,   469,   486,   229,    85,   372,   459,   152,   446,    86,
     281,    67,    68,   198,    87,   205,   383,   311,   200,    69,
      70,   463,   312,   254,   201,   230,    71,    72,    73,   184,
     146,   417,   409,     0,    74,    31,    62,    32,    63,     0,
     169,    75,     0,     0,    76,     0,     0,   255,     0,     0,
       0,     0,    64,    65,    66,    77,    78,     0,     0,     0,
       0,     0,     0,    79,    80,    67,    68,     0,     0,     0,
       0,     0,     0,    69,    70,     0,    81,     0,     0,     0,
      71,    72,    73,    82,     0,     0,    83,    84,    74,    31,
      62,    32,    63,     0,    85,    75,     0,     0,    76,    86,
       0,     0,     0,     0,   170,     0,    64,    65,     0,    77,
      78,     0,     0,     0,     0,     0,     0,    79,    80,    67,
      68,     0,     0,     0,     0,     0,     0,    69,    70,     0,
      81,     0,     0,     0,    71,    72,    73,    82,     0,     0,
      83,    84,    74,     0,     0,     0,     0,     0,    85,    75,
       0,     0,    76,    86,     0,     0,     0,     0,    87,     0,
       0,     0,     0,    77,    78,     0,     0,     0,     0,     0,
       0,    79,    80,     0,     0,    31,    62,    32,    63,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,    82,    64,    65,    83,    84,     0,     0,     0,     0,
       0,     0,    85,   121,     0,    67,    68,    86,     0,     0,
       0,     0,    87,    69,    70,     0,     0,     0,     0,     0,
      71,    72,    73,     0,     0,     0,     0,     0,    74,    31,
      62,    32,    63,     0,   169,    75,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    64,    65,     0,    77,
      78,     0,     0,     0,     0,     0,     0,    79,    80,    67,
      68,     0,     0,     0,     0,     0,     0,    69,    70,     0,
      81,     0,     0,     0,    71,    72,    73,    82,     0,     0,
      83,    84,    74,     0,     0,     0,     0,     0,    85,    75,
       0,     0,    76,    86,     0,     0,     0,     0,   170,     0,
       0,     0,     0,    77,    78,     0,     0,     0,     0,     0,
       0,    79,    80,     0,     0,    31,    62,    32,    63,     0,
       0,     0,     0,     0,    81,     0,     0,     0,    10,     0,
       0,    82,    64,    65,    83,    84,     0,     0,     0,     0,
       0,     0,    85,     0,     0,    67,    68,    86,     0,     0,
       0,     0,    87,    69,    70,     0,     0,     0,     0,     0,
      71,    72,    73,     0,     0,     0,     0,     0,    74,    31,
      62,    32,    63,     0,     0,    75,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,    64,   145,     0,    77,
      78,     0,     0,     0,     0,     0,     0,    79,    80,    67,
      68,     0,     0,     0,     0,     0,     0,    69,    70,     0,
      81,     0,     0,     0,    71,    72,    73,    82,     0,     0,
      83,    84,    74,     0,    62,     0,    63,     0,    85,    75,
       0,     0,    76,    86,     0,     0,     0,     0,    87,     0,
      64,   145,     0,    77,    78,     0,     0,     0,     0,     0,
       0,    79,    80,    67,    68,     0,     0,     0,     0,     0,
       0,     0,    70,     0,    81,     0,     0,     0,    71,    72,
      73,    82,     0,     0,    83,    84,    74,     0,     0,    67,
      68,     0,    85,     0,     0,     0,    76,    86,    70,     0,
       0,     0,    87,     0,    71,    72,    73,    77,    78,     0,
       0,     0,    74,     0,     0,    79,    80,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,    77,   228,    82,     0,     0,    83,    84,
       0,    79,     0,     0,     0,     0,    85,     0,     0,     0,
       0,    86,     0,     0,    81,     0,     0,     0,     0,     0,
       0,    82,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
       4,   121,    12,   204,   133,   117,   226,    11,    12,   113,
       0,    41,     8,   177,   105,     8,     8,   121,   190,     4,
     158,     6,     7,     4,    27,     6,    30,    75,     8,   107,
      34,    35,    36,    37,    38,     4,    26,     6,    38,    69,
      23,    24,    21,    22,    10,    30,    21,    22,    30,     1,
     170,     3,    59,    66,    21,    22,    77,    87,   195,   107,
      59,   190,   134,     9,   168,   107,   170,    21,    22,    80,
      83,    61,     9,     0,    56,    21,    22,   149,   169,    31,
      28,    69,   103,    36,    21,    22,    39,    40,    92,   227,
      54,    17,    18,    19,   104,    47,    48,    61,   270,   103,
     104,    53,   106,   107,   119,   135,    58,   111,   112,    54,
      58,   118,   112,   117,   129,     3,    61,   318,   148,   118,
     224,    87,   103,   127,   127,    77,    69,   127,   108,   133,
     234,   235,   128,   108,   138,   128,   128,   274,   302,   340,
     170,   270,   127,   147,   364,    97,   127,   130,    74,   128,
     180,   103,   105,   183,   158,   246,   160,   161,   127,    10,
     324,   128,   114,   104,   118,   285,    72,   157,   120,    70,
     129,   123,    44,   374,   204,    76,   288,    21,    22,    32,
     210,   285,     4,    84,     6,   123,   190,   191,   126,    33,
     103,   195,    98,    44,    65,     4,    68,     6,    45,    46,
     101,    52,   127,   116,   208,   123,   335,   125,     5,   213,
      32,    55,    45,    46,   127,   245,   380,   247,    89,    90,
     224,   341,   252,   227,    96,   316,    80,   128,    90,   259,
     128,   129,    70,   127,   346,   347,    87,   341,    76,   119,
     111,   113,     7,    81,     7,    96,    84,    79,   368,   100,
     280,     4,   262,     6,   358,   128,   129,   127,   262,   128,
     129,   127,   113,   101,   368,     5,   270,   127,    21,    22,
     274,    79,   436,   474,    21,    22,   128,   129,     5,    32,
     128,   129,   128,   129,   288,   315,   128,   129,   318,    69,
     410,   128,   129,   128,   129,   129,   127,   327,   128,   129,
     120,   305,   128,   129,   128,   129,   410,   128,   129,   127,
     340,   475,   128,   129,   128,   129,     7,   481,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     7,    21,
      22,   335,   444,   128,   129,   128,   129,   128,   129,   128,
     129,    11,   346,   347,   374,   103,   376,     8,   127,   127,
     462,     9,   456,    20,   358,    60,   128,   469,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    69,    21,
      22,     4,     5,     6,     7,   405,   128,    71,   129,   128,
     128,   411,    74,   127,    82,    82,   127,   115,    21,    22,
      23,   127,   116,   397,    60,    81,    92,    92,     7,    92,
     404,    34,    35,     7,    41,    73,   127,   127,     5,    42,
      43,    27,   129,   120,    87,   127,    49,    50,    51,   423,
     424,   451,    74,    56,    57,    82,    95,   127,    87,    91,
      95,    64,    37,    93,    67,   439,   128,   441,   127,   127,
     444,    90,   127,    41,   474,    78,    79,   129,     5,    85,
     127,    41,   456,    86,    87,     7,   100,   121,   462,    90,
      88,     4,     5,     6,     7,   469,    99,    10,    93,    41,
      62,    29,   128,   106,   129,    94,   109,   110,    21,    22,
     127,   127,     7,   167,   117,   308,   441,   104,   424,   122,
     208,    34,    35,   135,   127,   128,   335,   234,   139,    42,
      43,   451,   235,   181,   144,   168,    49,    50,    51,   123,
     101,   395,   380,    -1,    57,     4,     5,     6,     7,    -1,
      63,    64,    -1,    -1,    67,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    21,    22,    23,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    99,    -1,    -1,    -1,
      49,    50,    51,   106,    -1,    -1,   109,   110,    57,     4,
       5,     6,     7,    -1,   117,    64,    -1,    -1,    67,   122,
      -1,    -1,    -1,    -1,   127,    -1,    21,    22,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      99,    -1,    -1,    -1,    49,    50,    51,   106,    -1,    -1,
     109,   110,    57,    -1,    -1,    -1,    -1,    -1,   117,    64,
      -1,    -1,    67,   122,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    21,    22,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    34,    35,   122,    -1,    -1,
      -1,    -1,   127,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,     4,
       5,     6,     7,    -1,    63,    64,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      99,    -1,    -1,    -1,    49,    50,    51,   106,    -1,    -1,
     109,   110,    57,    -1,    -1,    -1,    -1,    -1,   117,    64,
      -1,    -1,    67,   122,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,
      -1,   106,    21,    22,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    34,    35,   122,    -1,    -1,
      -1,    -1,   127,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,     4,
       5,     6,     7,    -1,    -1,    64,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      99,    -1,    -1,    -1,    49,    50,    51,   106,    -1,    -1,
     109,   110,    57,    -1,     5,    -1,     7,    -1,   117,    64,
      -1,    -1,    67,   122,    -1,    -1,    -1,    -1,   127,    -1,
      21,    22,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    99,    -1,    -1,    -1,    49,    50,
      51,   106,    -1,    -1,   109,   110,    57,    -1,    -1,    34,
      35,    -1,   117,    -1,    -1,    -1,    67,   122,    43,    -1,
      -1,    -1,   127,    -1,    49,    50,    51,    78,    79,    -1,
      -1,    -1,    57,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    78,    79,   106,    -1,    -1,   109,   110,
      -1,    86,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,   122
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    31,    47,    48,    53,    58,    77,    97,
     103,   114,   120,   123,   132,   133,   134,   135,   136,   137,
     138,   159,   160,   163,   164,   167,   168,   171,   229,   230,
     107,     4,     6,   227,    75,   107,    69,   107,    80,    30,
      56,   172,   227,   169,   170,   183,   227,     0,   123,   125,
      77,   171,   123,   126,     3,   227,    69,   227,   227,   227,
     227,   227,     5,     7,    21,    22,    23,    34,    35,    42,
      43,    49,    50,    51,    57,    64,    67,    78,    79,    86,
      87,    99,   106,   109,   110,   117,   122,   127,   141,   173,
     174,   175,   205,   206,   207,   208,   209,   210,   211,   218,
     220,   223,   227,   104,   129,    32,   127,    80,    28,    58,
       5,    90,   127,   119,   199,   200,   116,   127,   171,     7,
       7,   118,   205,   214,   215,   127,    79,   127,     5,   127,
      79,   205,     5,    69,   176,   129,    21,    22,    32,   224,
     227,    23,    24,   130,   225,    22,   208,    27,   127,   165,
     166,   227,   170,   127,   177,   226,   227,   227,    45,    46,
      45,    46,   120,   161,   227,   139,   140,   227,    10,    63,
     127,   201,   202,   203,   204,   205,   220,   127,   226,   201,
     118,   212,   213,    59,   215,   216,     7,   227,     7,   128,
     127,   177,   180,   181,   184,   209,   227,   199,   175,   227,
     206,   207,   227,    23,    56,   128,   205,   217,   129,   199,
      11,   171,   128,   129,   171,   139,    44,    68,    96,   113,
     145,   227,   227,   127,   127,   148,   128,   129,    79,   141,
     204,   177,   201,   205,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    74,   222,    20,   218,
     219,   128,   108,   205,   213,   216,   205,    60,   128,    69,
     128,   180,    32,   182,   183,    70,    76,    84,   101,   179,
     129,   182,    38,   112,   178,    71,   185,   128,   217,   128,
     129,   166,   205,   128,   227,   127,    82,    82,   127,    54,
      61,   162,   220,   221,   227,   115,   145,   146,   147,   139,
      10,    44,    52,    87,    96,   100,   113,   142,   143,   144,
     128,   202,   203,    17,    18,    19,    74,   205,   127,   177,
     205,    10,    87,   128,   129,   116,   205,   108,    60,   205,
     128,   183,    92,    92,    92,    81,   180,     7,     7,   182,
      41,    73,   186,   128,   205,   201,   127,   127,   226,     5,
      65,    89,    90,   111,   228,   128,   129,   128,   129,    36,
      39,    40,   105,   157,   129,   120,   149,    87,   127,   218,
      82,   227,   142,   205,   127,   177,     9,   217,    87,   218,
     127,   205,   128,   181,    95,    95,   217,   201,    91,   187,
     128,   226,   226,   128,    54,    61,   220,   127,   158,   145,
      37,    93,   150,   201,   127,     9,   217,   205,   128,   219,
      90,    41,    85,   188,   128,   128,     5,   228,   152,   153,
     154,   155,   156,   227,   127,    41,   128,   227,   205,   128,
     128,   201,   195,   196,   205,     7,   121,   189,   190,   100,
     128,   129,     7,    30,   127,   227,   152,    72,    98,   151,
     128,   129,    33,    55,   197,   218,    90,   191,   227,   153,
     226,   128,   127,   196,    88,   198,   220,    93,   192,   127,
     128,   226,    66,    83,    41,    62,   193,   226,   128,   217,
     218,    29,   194,   128,    94,   218,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   131,   132,   132,   132,   132,   132,   132,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   134,   135,
     135,   135,   135,   136,   137,   138,   139,   140,   140,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   142,   142,   142,
     142,   142,   142,   142,   143,   143,   144,   144,   145,   145,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   153,   154,
     154,   155,   156,   157,   157,   157,   157,   158,   158,   159,
     159,   159,   159,   160,   161,   161,   162,   162,   162,   162,
     163,   164,   165,   165,   166,   167,   167,   168,   169,   169,
     170,   171,   172,   172,   172,   173,   173,   174,   174,   175,
     175,   175,   176,   177,   178,   178,   178,   179,   179,   179,
     179,   179,   179,   179,   179,   180,   180,   181,   181,   181,
     181,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   186,   186,   187,   187,   188,   188,   189,   189,   190,
     191,   192,   192,   193,   194,   195,   195,   196,   197,   197,
     197,   198,   198,   198,   199,   199,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   205,   205,   206,   206,   207,   207,
     208,   208,   208,   208,   208,   208,   209,   209,   209,   209,
     210,   211,   211,   212,   212,   213,   214,   214,   215,   216,
     216,   217,   217,   218,   218,   218,   218,   218,   218,   218,
     219,   219,   220,   220,   221,   221,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   223,   224,   224,   225,
     225,   225,   226,   226,   227,   227,   228,   228,   228,   228,
     229,   230,   230
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       6,     6,     6,     9,     9,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     4,     1,     2,     1,
       2,     2,     4,     5,     2,     1,     0,     1,     4,     5,
      10,     4,     3,     1,     0,     1,     0,     3,     0,     5,
       0,     8,     1,     1,     1,     3,     1,     1,     1,     2,
       2,     4,     2,     1,     1,     1,     1,     0,     3,    10,
       7,     4,     5,     5,     0,     4,     2,     2,     4,     4,
       5,     4,     3,     1,     3,     1,     2,     2,     1,     3,
       3,    10,     0,     1,     1,     1,     1,     1,     3,     3,
       2,     1,     2,     3,     0,     3,     3,     0,     1,     1,
       2,     1,     2,     1,     2,     6,     1,     2,     3,     2,
       2,     1,     3,     1,     2,     1,     4,     1,     3,     0,
       3,     0,     2,     0,     3,     0,     2,     0,     5,     2,
       2,     0,     3,     2,     2,     1,     3,     3,     0,     1,
       1,     0,     2,     2,     0,     1,     2,     3,     1,     3,
       1,     2,     1,     5,     6,     4,     3,     3,     3,     2,
       3,     5,     4,     6,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     4,     5,
       6,     5,     4,     1,     2,     4,     1,     2,     4,     0,
       2,     1,     3,     1,     1,     2,     2,     1,     2,     2,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     0
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
      yyerror (&yylloc, yyscanner, parsedStatement, YY_("syntax error: cannot back up")); \
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
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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
                  Type, Value, Location, yyscanner, parsedStatement); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (yyscanner);
  YYUSE (parsedStatement);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, yyscanner, parsedStatement);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , yyscanner, parsedStatement);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, yyscanner, parsedStatement); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (yyscanner);
  YYUSE (parsedStatement);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* TOKEN_COMMAND  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1865 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOKEN_NAME  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1875 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOKEN_STRING_SINGLE_QUOTED  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1885 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOKEN_STRING_DOUBLE_QUOTED  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1895 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOKEN_UNSIGNED_NUMVAL  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 1905 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 133: /* sql_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1915 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 134: /* quit_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).quit_statement_) != nullptr) {
    delete ((*yyvaluep).quit_statement_);
  }
}
#line 1925 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 135: /* alter_table_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1935 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 136: /* create_table_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).create_table_statement_) != nullptr) {
    delete ((*yyvaluep).create_table_statement_);
  }
}
#line 1945 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 137: /* create_index_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1955 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 138: /* drop_table_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).drop_table_statement_) != nullptr) {
    delete ((*yyvaluep).drop_table_statement_);
  }
}
#line 1965 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 139: /* column_def  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_);
  }
}
#line 1975 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 140: /* column_def_commalist  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_list_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_list_);
  }
}
#line 1985 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 141: /* data_type  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).data_type_) != nullptr) {
    delete ((*yyvaluep).data_type_);
  }
}
#line 1995 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 142: /* column_constraint_def  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_) != nullptr) {
    delete ((*yyvaluep).column_constraint_);
  }
}
#line 2005 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 143: /* column_constraint_def_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2015 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 144: /* opt_column_constraint_def_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2025 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 148: /* opt_column_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2035 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 149: /* opt_block_properties  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).block_properties_) != nullptr) {
    delete ((*yyvaluep).block_properties_);
  }
}
#line 2045 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 150: /* opt_partition_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).partition_clause_) != nullptr) {
    delete ((*yyvaluep).partition_clause_);
  }
}
#line 2055 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 151: /* partition_type  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2065 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 152: /* key_value_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2075 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 153: /* key_value  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_) != nullptr) {
    delete ((*yyvaluep).key_value_);
  }
}
#line 2085 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 154: /* key_string_value  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_value_) != nullptr) {
    delete ((*yyvaluep).key_string_value_);
  }
}
#line 2095 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 155: /* key_string_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_list_) != nullptr) {
    delete ((*yyvaluep).key_string_list_);
  }
}
#line 2105 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 156: /* key_integer_value  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_integer_value_) != nullptr) {
    delete ((*yyvaluep).key_integer_value_);
  }
}
#line 2115 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 157: /* index_type  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2125 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 158: /* opt_index_properties  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2135 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 159: /* insert_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).insert_statement_) != nullptr) {
    delete ((*yyvaluep).insert_statement_);
  }
}
#line 2145 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 160: /* copy_from_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_statement_) != nullptr) {
    delete ((*yyvaluep).copy_from_statement_);
  }
}
#line 2155 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 161: /* opt_copy_from_params  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2165 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 162: /* copy_from_params  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2175 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 163: /* update_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).update_statement_) != nullptr) {
    delete ((*yyvaluep).update_statement_);
  }
}
#line 2185 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 164: /* delete_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).delete_statement_) != nullptr) {
    delete ((*yyvaluep).delete_statement_);
  }
}
#line 2195 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 165: /* assignment_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_list_) != nullptr) {
    delete ((*yyvaluep).assignment_list_);
  }
}
#line 2205 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 166: /* assignment_item  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_) != nullptr) {
    delete ((*yyvaluep).assignment_);
  }
}
#line 2215 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 167: /* select_statement  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_statement_) != nullptr) {
    delete ((*yyvaluep).select_statement_);
  }
}
#line 2225 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 168: /* with_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2235 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 169: /* with_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2245 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 170: /* with_list_element  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_element_) != nullptr) {
    delete ((*yyvaluep).with_list_element_);
  }
}
#line 2255 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 171: /* select_query  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_query_) != nullptr) {
    delete ((*yyvaluep).select_query_);
  }
}
#line 2265 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 173: /* selection  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_) != nullptr) {
    delete ((*yyvaluep).selection_);
  }
}
#line 2275 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 174: /* selection_item_commalist  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_list_) != nullptr) {
    delete ((*yyvaluep).selection_list_);
  }
}
#line 2285 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 175: /* selection_item  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_item_) != nullptr) {
    delete ((*yyvaluep).selection_item_);
  }
}
#line 2295 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 176: /* from_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2305 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 177: /* subquery_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).subquery_expression_) != nullptr) {
    delete ((*yyvaluep).subquery_expression_);
  }
}
#line 2315 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 178: /* opt_sample_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_sample_clause_) != nullptr) {
    delete ((*yyvaluep).opt_sample_clause_);
  }
}
#line 2325 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 179: /* join_type  */
#line 584 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2331 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 180: /* joined_table_reference  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2341 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 181: /* table_reference  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2351 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 182: /* table_reference_signature  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2361 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 183: /* table_reference_signature_primary  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2371 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 184: /* joined_table_reference_commalist  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2381 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 185: /* opt_group_by_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_group_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_group_by_clause_);
  }
}
#line 2391 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 186: /* opt_having_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_having_clause_) != nullptr) {
    delete ((*yyvaluep).opt_having_clause_);
  }
}
#line 2401 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 187: /* opt_order_by_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_order_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_order_by_clause_);
  }
}
#line 2411 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 188: /* opt_limit_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_limit_clause_) != nullptr) {
    delete ((*yyvaluep).opt_limit_clause_);
  }
}
#line 2421 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 189: /* opt_window_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_window_clause_) != nullptr) {
    delete ((*yyvaluep).opt_window_clause_);
  }
}
#line 2431 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 190: /* window_duration  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2441 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 191: /* window_attribute  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2451 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 192: /* opt_window_partition  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_partition_by_list_) != nullptr) {
    delete ((*yyvaluep).window_partition_by_list_);
  }
}
#line 2461 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 193: /* emit_duration  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2471 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 194: /* age_duration  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2481 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 195: /* order_commalist  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_commalist_) != nullptr) {
    delete ((*yyvaluep).order_commalist_);
  }
}
#line 2491 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 196: /* order_item  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_item_) != nullptr) {
    delete ((*yyvaluep).order_item_);
  }
}
#line 2501 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 197: /* opt_order_direction  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2511 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 198: /* opt_nulls_first  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2521 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 199: /* opt_where_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2531 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 200: /* where_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2541 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 201: /* or_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2551 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 202: /* and_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2561 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 203: /* not_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2571 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 204: /* predicate_expression_base  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2581 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 205: /* add_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2591 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 206: /* multiply_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2601 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 207: /* unary_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2611 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 208: /* expression_base  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2621 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 209: /* function_call  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).function_call_) != nullptr) {
    delete ((*yyvaluep).function_call_);
  }
}
#line 2631 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 210: /* extract_function  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2641 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 211: /* case_expression  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2651 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 212: /* simple_when_clause_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_list_);
  }
}
#line 2661 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 213: /* simple_when_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_);
  }
}
#line 2671 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 214: /* searched_when_clause_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_list_);
  }
}
#line 2681 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 215: /* searched_when_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_);
  }
}
#line 2691 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 216: /* opt_else_clause  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2701 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 217: /* expression_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_list_) != nullptr) {
    delete ((*yyvaluep).expression_list_);
  }
}
#line 2711 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 218: /* literal_value  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2721 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 219: /* literal_value_commalist  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_list_) != nullptr) {
    delete ((*yyvaluep).literal_value_list_);
  }
}
#line 2731 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 220: /* attribute_ref  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2741 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 221: /* attribute_ref_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2751 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 222: /* comparison_operation  */
#line 581 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2757 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 223: /* unary_operation  */
#line 582 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2763 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 224: /* add_operation  */
#line 583 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2769 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 225: /* multiply_operation  */
#line 583 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2775 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 226: /* name_commalist  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 2785 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 227: /* any_name  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2795 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 228: /* boolean_value  */
#line 580 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2801 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 229: /* command  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_) != nullptr) {
    delete ((*yyvaluep).command_);
  }
}
#line 2811 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 230: /* command_argument_list  */
#line 586 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_argument_list_) != nullptr) {
    delete ((*yyvaluep).command_argument_list_);
  }
}
#line 2821 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, yyscanner);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 595 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3118 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 599 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3127 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 603 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3136 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 607 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3145 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 611 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    YYABORT;
  }
#line 3153 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 614 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Regular yyparse() return codes are non-negative, so use a negative one here.
    return -1;
  }
#line 3162 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 621 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3170 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 624 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].copy_from_statement_);
  }
#line 3178 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 627 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].create_table_statement_);
  }
#line 3186 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 630 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3194 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 633 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].delete_statement_);
  }
#line 3202 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 636 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].drop_table_statement_);
  }
#line 3210 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 639 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].insert_statement_);
  }
#line 3218 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 642 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].quit_statement_);
  }
#line 3226 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 645 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].select_statement_);
  }
#line 3234 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 648 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].update_statement_);
  }
#line 3242 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 654 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.quit_statement_) = new quickstep::ParseStatementQuit((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3250 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 660 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].attribute_definition_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3262 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 667 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3273 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 673 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3285 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 680 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3297 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 689 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.create_table_statement_) = new quickstep::ParseStatementCreateTable((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].attribute_definition_list_), (yyvsp[-1].block_properties_), (yyvsp[0].partition_clause_));
  }
#line 3305 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 694 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].key_value_list_)) {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_), (yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].key_value_list_));
    } else {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_));
    }
  }
#line 3317 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 703 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.drop_table_statement_) = new quickstep::ParseStatementDropTable((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_));
  }
#line 3325 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 708 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_) = new quickstep::ParseAttributeDefinition((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].data_type_), (yyvsp[0].column_constraint_list_));
  }
#line 3333 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 713 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = new quickstep::PtrList<quickstep::ParseAttributeDefinition>();
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3342 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 717 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = (yyvsp[-2].attribute_definition_list_);
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3351 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 723 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "BIT data type");
    YYERROR;
  }
#line 3361 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 728 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3369 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 731 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3377 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 734 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "TIME data type");
    YYERROR;
  }
#line 3387 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 739 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3395 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 742 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3403 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 745 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3411 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 748 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3419 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 751 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kFloat));
  }
#line 3427 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 754 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3435 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 757 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3443 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 760 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3451 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 763 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3459 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 766 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This pattern exhibits a shift/reduce conflict with the
     * TOKEN_INTERVAL case in 'literal_value'. Bison prefers to shift rather
     * than reduce, so the case in 'literal_value' has precedence over this.
     **/
    (yyval.data_type_) = nullptr;
    quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr,
        "INTERVAL is ambiguous as a column type. Specify either DATETIME INTERVAL "
        "or YEARMONTH INTERVAL");
    YYERROR;
  }
#line 3476 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 778 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetimeInterval));
  }
#line 3484 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 781 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kYearMonthInterval));
  }
#line 3492 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 784 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].numeric_literal_value_)->float_like()) {
      delete (yyvsp[-1].numeric_literal_value_);
      (yyval.data_type_) = NULL;
      quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Non-integer length supplied for CHAR type");
      YYERROR;
    } else {
      if ((yyvsp[-1].numeric_literal_value_)->long_value() <= 0) {
        delete (yyvsp[-1].numeric_literal_value_);
        (yyval.data_type_) = NULL;
        quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Length for CHAR type must be at least 1");
        YYERROR;
      } else {
        (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kChar, (yyvsp[-1].numeric_literal_value_)->long_value(), false));
        delete (yyvsp[-1].numeric_literal_value_);
      }
    }
  }
#line 3515 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 802 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].numeric_literal_value_)->float_like()) {
      delete (yyvsp[-1].numeric_literal_value_);
      (yyval.data_type_) = NULL;
      quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Non-integer length supplied for VARCHAR type");
      YYERROR;
    } else {
      if ((yyvsp[-1].numeric_literal_value_)->long_value() < 0) {
        delete (yyvsp[-1].numeric_literal_value_);
        (yyval.data_type_) = NULL;
        quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Negative length supplied for VARCHAR type");
        YYERROR;
      } else {
        (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kVarChar, (yyvsp[-1].numeric_literal_value_)->long_value(), false));
        delete (yyvsp[-1].numeric_literal_value_);
      }
    }
  }
#line 3538 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 822 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNull((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3546 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 825 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNotNull((yylsp[-1]).first_line, (yylsp[-1]).first_column);
  }
#line 3554 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 828 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "Column Constraints (UNIQUE)");
    YYERROR;
  }
#line 3564 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 833 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3574 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 838 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[0].literal_value_);
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (DEFAULT)");
    YYERROR;
  }
#line 3585 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 844 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Column Constraints (CHECK)");
    YYERROR;
  }
#line 3596 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 850 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_value_);
    NotSupported(&(yylsp[-4]), yyscanner, "Foreign Keys");
    YYERROR;
  }
#line 3608 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 859 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[-1].column_constraint_list_);
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3617 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 863 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = new quickstep::PtrList<quickstep::ParseColumnConstraint>();
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3626 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 869 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = nullptr;
  }
#line 3634 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 872 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[0].column_constraint_list_);
  }
#line 3642 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 877 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (UNIQUE)");
    YYERROR;
  }
#line 3652 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 882 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-4]), yyscanner, "Table Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3662 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 887 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-6].string_list_);
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-9]), yyscanner, "Table Constraints (FOREIGN KEY)");
    YYERROR;
  }
#line 3674 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 894 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (CHECK)");
    YYERROR;
  }
#line 3684 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 901 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[-2]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3693 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 905 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3702 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 911 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3710 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 914 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = $1; */
  }
#line 3718 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 919 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = nullptr;
  }
#line 3726 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 922 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = (yyvsp[-1].attribute_list_);
  }
#line 3734 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 927 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = nullptr;
  }
#line 3742 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 930 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = new quickstep::ParseBlockProperties((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].key_value_list_));
  }
#line 3750 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 935 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.partition_clause_) = nullptr;
  }
#line 3758 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 938 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.partition_clause_) = NULL;
      quickstep_yyerror(&(yylsp[0]), yyscanner, NULL, "NUMBER OF PARTITIONS must be an integer");
      YYERROR;
    } else {
      if ((yyvsp[0].numeric_literal_value_)->long_value() <= 0 || (yyvsp[0].numeric_literal_value_)->long_value() > 64) {
        delete (yyvsp[0].numeric_literal_value_);
        (yyval.partition_clause_) = NULL;
        quickstep_yyerror(&(yylsp[0]), yyscanner, NULL, "NUMBER OF PARITIONS must be between 1 and 64");
        YYERROR;
      } else {
        (yyval.partition_clause_) = new quickstep::ParsePartitionClause((yylsp[-7]).first_line, (yylsp[-7]).first_column, (yyvsp[-5].string_value_), (yyvsp[-3].string_list_), (yyvsp[0].numeric_literal_value_));
      }
    }
  }
#line 3780 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 957 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionSchemeHeader::PartitionType::kHash));
  }
#line 3789 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 961 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionSchemeHeader::PartitionType::kRange));
  }
#line 3798 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 967 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = new quickstep::PtrList<quickstep::ParseKeyValue>();
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3807 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 971 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-2].key_value_list_);
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3816 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 977 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_value_);
  }
#line 3824 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 980 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_list_);
  }
#line 3832 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 983 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_integer_value_);
  }
#line 3840 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 988 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].string_value_));
  }
#line 3848 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 991 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // This is a special case to handle the COMPRESS ALL option of the BLOCK PROPERTIES.
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_),
        new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, "ALL"));
  }
#line 3858 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 998 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_list_) = new quickstep::ParseKeyStringList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 3866 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1003 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.key_integer_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Value must be an integer");
      YYERROR;
    }
    (yyval.key_integer_value_) = new quickstep::ParseKeyIntegerValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].numeric_literal_value_));
  }
#line 3880 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1014 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Defaults to BitWeavingV, but IndexProperties can change this to H.
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBitWeavingV));
  }
#line 3890 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1019 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBloomFilter));
  }
#line 3899 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1023 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kCSBTree));
  }
#line 3908 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1027 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kSMA));
  }
#line 3917 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1033 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = nullptr;
  }
#line 3925 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1036 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-1].key_value_list_);
  }
#line 3933 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1042 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-7].string_value_);
    delete (yyvsp[-5].string_list_);
    delete (yyvsp[-1].literal_value_list_);
    (yyval.insert_statement_) = nullptr;
    NotSupported(&(yylsp[-6]), yyscanner, "list of column names in INSERT statement");
    YYERROR;
  }
#line 3946 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1050 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertTuple((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].string_value_), (yyvsp[-1].literal_value_list_));
  }
#line 3954 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1053 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-3]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), nullptr);
  }
#line 3962 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1056 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-4]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), (yyvsp[-4].with_list_));
  }
#line 3970 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1062 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_statement_) = new quickstep::ParseStatementCopyFrom((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_value_), (yyvsp[0].copy_from_params_));
  }
#line 3978 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1067 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = nullptr;
  }
#line 3986 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1070 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-1].copy_from_params_);
  }
#line 3994 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1075 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4003 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1079 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4012 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1083 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4021 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1087 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4030 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1093 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.update_statement_) = new quickstep::ParseStatementUpdate((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].assignment_list_), (yyvsp[0].predicate_));
  }
#line 4038 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1098 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.delete_statement_) = new quickstep::ParseStatementDelete((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].predicate_));
  }
#line 4046 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1103 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = (yyvsp[-2].assignment_list_);
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4055 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1107 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = new quickstep::PtrList<quickstep::ParseAssignment>();
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4064 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1113 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_) = new quickstep::ParseAssignment((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[0].expression_));
  }
#line 4072 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1119 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].select_query_), nullptr);
  }
#line 4080 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1122 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].select_query_), (yyvsp[-1].with_list_));
  }
#line 4088 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1127 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[0].with_list_);
  }
#line 4096 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1132 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = new quickstep::PtrVector<quickstep::ParseSubqueryTableReference>();
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4105 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1136 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[-2].with_list_);
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4114 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1142 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_element_) = new quickstep::ParseSubqueryTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].subquery_expression_));
    (yyval.with_list_element_)->set_table_reference_signature((yyvsp[-2].table_reference_signature_));
  }
#line 4123 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1149 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_query_) = new quickstep::ParseSelect((yylsp[-9]).first_line, (yylsp[-9]).first_column, (yyvsp[-7].selection_), (yyvsp[-6].table_reference_list_), (yyvsp[-5].predicate_), (yyvsp[-4].opt_group_by_clause_), (yyvsp[-3].opt_having_clause_), (yyvsp[-2].opt_order_by_clause_), (yyvsp[-1].opt_limit_clause_), (yyvsp[0].opt_window_clause_));
  }
#line 4131 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1154 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 4139 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1157 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "ALL in selection");
    YYERROR;
  }
#line 4148 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1161 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "DISTINCT in selection");
    YYERROR;
  }
#line 4157 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1167 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = new quickstep::ParseSelectionStar((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 4165 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1170 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = (yyvsp[0].selection_list_);
  }
#line 4173 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1175 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = new quickstep::ParseSelectionList((yylsp[0]).first_line, (yylsp[0]).first_column);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4182 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1179 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = (yyvsp[-2].selection_list_);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4191 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1185 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[0].string_value_));
  }
#line 4199 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1188 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].expression_), (yyvsp[0].string_value_));
  }
#line 4207 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1191 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].expression_));
  }
#line 4215 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1196 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[0].table_reference_list_);
  }
#line 4223 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1201 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.subquery_expression_) = new quickstep::ParseSubqueryExpression((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].select_query_));
  }
#line 4231 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1206 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = NULL;
  }
#line 4239 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1209 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, true, (yyvsp[-1].numeric_literal_value_));
  }
#line 4247 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1212 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].numeric_literal_value_));
  }
#line 4255 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1217 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4263 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1220 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4271 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1223 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4279 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1226 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4287 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1229 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4295 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1232 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4303 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1235 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4311 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1238 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4319 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1243 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseJoinedTableReference((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].join_type_), (yyvsp[-5].table_reference_), (yyvsp[-2].table_reference_), (yyvsp[0].predicate_));
  }
#line 4327 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1246 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = (yyvsp[0].table_reference_);
  }
#line 4335 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1251 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSubqueryTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].subquery_expression_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4344 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1255 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].opt_sample_clause_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4353 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1259 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].opt_sample_clause_));
  }
#line 4361 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1262 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].function_call_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4370 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1266 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].function_call_));
  }
#line 4378 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1269 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = (yyvsp[-1].table_reference_);
  }
#line 4386 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1274 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4394 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1277 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4402 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1282 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4410 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1285 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4418 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1290 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = new quickstep::PtrList<quickstep::ParseTableReference>();
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4427 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1294 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[-2].table_reference_list_);
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4436 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1300 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = nullptr;
  }
#line 4444 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1303 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = new quickstep::ParseGroupBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].expression_list_));
  }
#line 4452 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1308 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = nullptr;
  }
#line 4460 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1311 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = new quickstep::ParseHaving((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4468 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1316 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = nullptr;
  }
#line 4476 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1319 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = new quickstep::ParseOrderBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].order_commalist_));
  }
#line 4484 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1324 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_limit_clause_) = nullptr;
  }
#line 4492 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1327 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.opt_limit_clause_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "LIMIT value must be an integer");
      YYERROR;
    } else {
      if ((yyvsp[0].numeric_literal_value_)->long_value() <= 0) {
        delete (yyvsp[0].numeric_literal_value_);
        (yyval.opt_limit_clause_) = nullptr;
        quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "LIMIT value must be positive");
        YYERROR;
      } else {
        (yyval.opt_limit_clause_) = new quickstep::ParseLimit((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].numeric_literal_value_));
      }
    }
  }
#line 4514 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1346 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = nullptr;
  }
#line 4522 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1349 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = new quickstep::ParseWindow((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].attribute_), (yyvsp[-2].window_partition_by_list_), (yyvsp[-4].literal_value_), (yyvsp[-1].literal_value_), (yyvsp[0].literal_value_));
  }
#line 4530 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1354 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4538 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1359 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = (yyvsp[0].attribute_);
  }
#line 4546 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1364 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = nullptr;
  }
#line 4554 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1367 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = (yyvsp[0].expression_list_);
  }
#line 4562 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1372 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4570 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1377 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4578 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1382 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = new quickstep::PtrList<quickstep::ParseOrderByItem>();
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4587 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1386 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = (yyvsp[-2].order_commalist_);
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4596 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1392 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_item_) = new quickstep::ParseOrderByItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[-1].order_direction_), (yyvsp[0].order_direction_));
    delete (yyvsp[-1].order_direction_);
    delete (yyvsp[0].order_direction_);
  }
#line 4606 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1399 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4614 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1402 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4622 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1405 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4630 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1410 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4638 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1413 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4646 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1416 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4654 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1422 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = nullptr;
  }
#line 4662 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1425 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4670 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1430 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4678 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1435 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kDisjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateDisjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4692 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1444 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4700 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1449 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kConjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateConjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4714 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1458 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4722 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1463 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4730 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1466 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4738 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1471 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4746 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1474 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line, (yylsp[-4]).first_column,
        new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_)));
  }
#line 4756 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1479 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4767 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1485 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4778 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1491 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateComparison((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].comparison_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4786 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1494 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[-1].predicate_);
  }
#line 4794 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1497 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateExists((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].subquery_expression_));
  }
#line 4802 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1500 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].expression_), (yyvsp[0].subquery_expression_));
  }
#line 4810 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1503 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-1].expression_list_));
  }
#line 4818 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1506 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-2]).first_line,
        (yylsp[-2]).first_column,
        new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-3].expression_), (yyvsp[0].subquery_expression_)));
  }
#line 4829 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1512 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line,
        (yylsp[-4]).first_column,
        new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-1].expression_list_)));
  }
#line 4840 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1521 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4848 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1524 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4856 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1529 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4864 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1532 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4872 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1537 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseUnaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].unary_operation_), (yyvsp[0].expression_));
  }
#line 4880 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1540 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4888 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1545 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].attribute_);
  }
#line 4896 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1548 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_));
  }
#line 4904 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1551 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].function_call_);
  }
#line 4912 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1554 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4920 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1557 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4928 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1560 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[-1].expression_);
  }
#line 4936 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1565 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-2].string_value_), new quickstep::PtrList<quickstep::ParseExpression>());
  }
#line 4945 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1569 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), new quickstep::ParseStar((yylsp[-1]).first_line, (yylsp[-1]).first_column));
  }
#line 4954 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1573 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-3]).first_line, (yylsp[-3]).first_column, false, (yyvsp[-3].string_value_), (yyvsp[-1].expression_list_));
  }
#line 4962 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1576 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-4]).first_line, (yylsp[-4]).first_column, true, (yyvsp[-4].string_value_), (yyvsp[-1].expression_list_));
  }
#line 4970 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1581 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseExtractFunction((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].expression_));
  }
#line 4978 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1586 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSimpleCaseExpression((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].expression_), (yyvsp[-2].simple_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 4986 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1589 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSearchedCaseExpression((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].searched_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 4994 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1594 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSimpleWhenClause>;
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5003 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1598 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_list_) = (yyvsp[-1].simple_when_clause_list_);
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5012 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1604 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_) = new quickstep::ParseSimpleWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 5020 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1609 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSearchedWhenClause>;
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5029 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1613 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_list_) = (yyvsp[-1].searched_when_clause_list_);
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5038 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1619 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_) = new quickstep::ParseSearchedWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].predicate_), (yyvsp[0].expression_));
  }
#line 5046 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1624 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = NULL;
  }
#line 5054 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1627 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5062 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1632 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = new quickstep::PtrList<quickstep::ParseExpression>();
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5071 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1636 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = (yyvsp[-2].expression_list_);
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5080 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1642 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::NullParseLiteralValue((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 5088 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1645 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5096 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1648 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5104 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1651 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * minus character as a 'unary_operation' followed by a numeric literal.
     * Because Bison prefers to shift rather than reduce, this case has
     * precedence (i.e. the parser will prefer to interpret the ambiguous
     * pattern as a negative number literal rather than a unary minus operation
     * applied to a non-negative number literal).
     **/
    (yyvsp[0].numeric_literal_value_)->prependMinus();
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5121 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1663 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_),
                                                nullptr);  // No explicit type.
  }
#line 5130 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1667 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * plain TOKEN_INTERVAL case in 'data_type' reduced and used in the case
     * below. Because Bison prefers to shift rather than reduce, this case has
     * precedence (i.e. the special
     * StringParseLiteralValue::ParseAmbiguousInterval() method will be used to
     * parse the string as either one of the interval types, rather than an
     * error being emitted because of an ambiguous type).
     **/
    quickstep::StringParseLiteralValue *parse_value;
    if (quickstep::StringParseLiteralValue::ParseAmbiguousInterval((yyvsp[0].string_value_), &parse_value)) {
      (yyval.literal_value_) = parse_value;
    } else {
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    }
  }
#line 5154 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1686 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::StringParseLiteralValue *parse_value
        = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_), &((yyvsp[-1].data_type_)->getType()));
    delete (yyvsp[-1].data_type_);
    if (!parse_value->tryExplicitTypeParse()) {
      delete parse_value;
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    } else {
      (yyval.literal_value_) = parse_value;
    }
  }
#line 5172 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1701 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = new quickstep::PtrList<quickstep::ParseScalarLiteral>();
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5181 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1705 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = (yyvsp[-2].literal_value_list_);
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5190 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1711 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 5198 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1714 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_), (yyvsp[-2].string_value_));
  }
#line 5206 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1719 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = new quickstep::PtrList<quickstep::ParseAttribute>();
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5215 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1723 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = (yyvsp[-2].attribute_list_);
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5224 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1730 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kEqual);
  }
#line 5232 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1733 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotEqual);
  }
#line 5240 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1736 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLess);
  }
#line 5248 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1739 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLessOrEqual);
  }
#line 5256 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1742 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreater);
  }
#line 5264 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1745 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreaterOrEqual);
  }
#line 5272 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1748 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLike);
  }
#line 5280 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1751 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotLike);
  }
#line 5288 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1754 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kRegexMatch);
  }
#line 5296 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1757 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotRegexMatch);
  }
#line 5304 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1762 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * '-' TOKEN_UNSIGNED_NUMVAL case in 'literal_value'. Because Bison prefers
     * to shift rather than reduce, the case in 'literal_value' has precedence
     * over this one.
     **/
    (yyval.unary_operation_) = &quickstep::UnaryOperationFactory::GetUnaryOperation(quickstep::UnaryOperationID::kNegate);
  }
#line 5318 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1773 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kAdd);
  }
#line 5326 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1776 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kSubtract);
  }
#line 5334 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1781 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kModulo);
  }
#line 5342 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1784 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kMultiply);
  }
#line 5350 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1787 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kDivide);
  }
#line 5358 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1793 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = new quickstep::PtrList<quickstep::ParseString>();
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5367 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1797 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = (yyvsp[-2].string_list_);
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5376 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1803 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5384 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1806 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].string_value_)->value().empty()) {
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Zero-length identifier");
    }
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5395 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1814 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 5403 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1817 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 5411 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1820 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 5419 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1823 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 5427 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1829 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.command_) = new quickstep::ParseCommand((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].command_argument_list_));
  }
#line 5435 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1834 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::PtrVector<quickstep::ParseString> *argument_list = (yyvsp[-1].command_argument_list_);
    argument_list->push_back((yyvsp[0].string_value_));
    (yyval.command_argument_list_) = argument_list;
  }
#line 5445 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1839 "../SqlParser.ypp" /* yacc.c:1646  */
    { /* Epsilon, an empy match. */
    (yyval.command_argument_list_) = new quickstep::PtrVector<quickstep::ParseString>();
  }
#line 5453 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;


#line 5457 "SqlParser_gen.cpp" /* yacc.c:1646  */
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
      yyerror (&yylloc, yyscanner, parsedStatement, YY_("syntax error"));
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
        yyerror (&yylloc, yyscanner, parsedStatement, yymsgp);
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
                      yytoken, &yylval, &yylloc, yyscanner, parsedStatement);
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

  yyerror_range[1] = yylsp[1-yylen];
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
                  yystos[yystate], yyvsp, yylsp, yyscanner, parsedStatement);
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
  yyerror (&yylloc, yyscanner, parsedStatement, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, yyscanner, parsedStatement);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, yyscanner, parsedStatement);
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
#line 1843 "../SqlParser.ypp" /* yacc.c:1906  */


void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature) {
  std::string msg;
  msg.append(feature);
  msg.append(" is not supported yet");

  quickstep_yyerror(location, yyscanner, nullptr, msg.c_str());
}

int quickstep_yyget_line_number(const YYLTYPE *yyloc) {
  return yyloc->first_line;
}

int quickstep_yyget_column_number(const YYLTYPE *yyloc) {
  return yyloc->first_column;
}
