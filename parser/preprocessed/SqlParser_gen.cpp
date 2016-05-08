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
    TOKEN_DAY = 301,
    TOKEN_DECIMAL = 302,
    TOKEN_DEFAULT = 303,
    TOKEN_DELETE = 304,
    TOKEN_DELIMITER = 305,
    TOKEN_DESC = 306,
    TOKEN_DISTINCT = 307,
    TOKEN_DOUBLE = 308,
    TOKEN_DROP = 309,
    TOKEN_ELSE = 310,
    TOKEN_END = 311,
    TOKEN_ESCAPE_STRINGS = 312,
    TOKEN_EMIT = 313,
    TOKEN_EXISTS = 314,
    TOKEN_EXTRACT = 315,
    TOKEN_FALSE = 316,
    TOKEN_FIRST = 317,
    TOKEN_FLOAT = 318,
    TOKEN_FOREIGN = 319,
    TOKEN_FROM = 320,
    TOKEN_FULL = 321,
    TOKEN_GROUP = 322,
    TOKEN_HASH = 323,
    TOKEN_HAVING = 324,
    TOKEN_HOUR = 325,
    TOKEN_IN = 326,
    TOKEN_INDEX = 327,
    TOKEN_INNER = 328,
    TOKEN_INSERT = 329,
    TOKEN_INTEGER = 330,
    TOKEN_INTERVAL = 331,
    TOKEN_INTO = 332,
    TOKEN_JOIN = 333,
    TOKEN_KEY = 334,
    TOKEN_LAST = 335,
    TOKEN_LEFT = 336,
    TOKEN_LIMIT = 337,
    TOKEN_LONG = 338,
    TOKEN_MINUTE = 339,
    TOKEN_MONTH = 340,
    TOKEN_NULL = 341,
    TOKEN_NULLS = 342,
    TOKEN_OFF = 343,
    TOKEN_ON = 344,
    TOKEN_ORDER = 345,
    TOKEN_OUTER = 346,
    TOKEN_PARTITION = 347,
    TOKEN_PARTITIONS = 348,
    TOKEN_PERCENT = 349,
    TOKEN_PRIMARY = 350,
    TOKEN_QUIT = 351,
    TOKEN_RANGE = 352,
    TOKEN_REAL = 353,
    TOKEN_REFERENCES = 354,
    TOKEN_RIGHT = 355,
    TOKEN_ROW_DELIMITER = 356,
    TOKEN_SECOND = 357,
    TOKEN_SELECT = 358,
    TOKEN_SET = 359,
    TOKEN_SMA = 360,
    TOKEN_SMALLINT = 361,
    TOKEN_TABLE = 362,
    TOKEN_THEN = 363,
    TOKEN_TIME = 364,
    TOKEN_TIMESTAMP = 365,
    TOKEN_TRUE = 366,
    TOKEN_TUPLESAMPLE = 367,
    TOKEN_UNIQUE = 368,
    TOKEN_UPDATE = 369,
    TOKEN_USING = 370,
    TOKEN_VALUES = 371,
    TOKEN_VARCHAR = 372,
    TOKEN_WHEN = 373,
    TOKEN_WHERE = 374,
    TOKEN_WITH = 375,
    TOKEN_WINDOW = 376,
    TOKEN_YEAR = 377,
    TOKEN_YEARMONTH = 378,
    TOKEN_EOF = 379,
    TOKEN_LEX_ERROR = 380
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

#line 415 "SqlParser_gen.cpp" /* yacc.c:355  */
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
#line 213 "../SqlParser.ypp" /* yacc.c:358  */

/* This header needs YYSTYPE, which is defined by the %union directive above */
#include "SqlLexer_gen.hpp"
void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature);

#line 448 "SqlParser_gen.cpp" /* yacc.c:358  */

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
#define YYLAST   1187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  270
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  495

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   380

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     132,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   136,     2,     2,
     133,   134,    23,    21,   135,    22,    27,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   131,
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
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   603,   603,   607,   611,   615,   619,   622,   629,   632,
     635,   638,   641,   644,   647,   650,   653,   656,   662,   668,
     675,   681,   688,   697,   702,   711,   716,   721,   725,   731,
     736,   739,   742,   747,   750,   753,   756,   759,   762,   765,
     768,   771,   774,   786,   789,   792,   810,   830,   833,   836,
     841,   846,   852,   858,   867,   871,   877,   880,   885,   890,
     895,   902,   909,   913,   919,   922,   927,   930,   935,   938,
     943,   946,   965,   969,   975,   979,   985,   988,   991,   996,
     999,  1006,  1011,  1022,  1027,  1031,  1035,  1041,  1044,  1050,
    1058,  1061,  1064,  1070,  1075,  1078,  1083,  1087,  1091,  1095,
    1101,  1106,  1111,  1115,  1121,  1127,  1130,  1135,  1140,  1144,
    1150,  1156,  1162,  1165,  1169,  1175,  1178,  1183,  1187,  1193,
    1196,  1199,  1204,  1209,  1214,  1217,  1220,  1225,  1228,  1231,
    1234,  1237,  1240,  1243,  1246,  1251,  1254,  1259,  1263,  1267,
    1270,  1274,  1277,  1282,  1285,  1290,  1293,  1298,  1302,  1308,
    1311,  1316,  1319,  1324,  1327,  1332,  1335,  1354,  1357,  1362,
    1367,  1372,  1375,  1380,  1385,  1390,  1394,  1400,  1407,  1410,
    1413,  1418,  1421,  1424,  1430,  1433,  1438,  1443,  1452,  1457,
    1466,  1471,  1474,  1479,  1482,  1487,  1493,  1499,  1502,  1505,
    1508,  1511,  1514,  1520,  1529,  1532,  1537,  1540,  1545,  1548,
    1553,  1556,  1559,  1562,  1565,  1568,  1571,  1576,  1580,  1584,
    1587,  1592,  1597,  1600,  1605,  1609,  1615,  1620,  1624,  1630,
    1635,  1638,  1643,  1647,  1653,  1656,  1659,  1662,  1674,  1678,
    1697,  1710,  1725,  1728,  1731,  1734,  1737,  1740,  1745,  1749,
    1755,  1758,  1763,  1767,  1774,  1777,  1780,  1783,  1786,  1789,
    1792,  1795,  1798,  1801,  1806,  1817,  1820,  1825,  1828,  1831,
    1837,  1841,  1847,  1850,  1858,  1861,  1864,  1867,  1873,  1878,
    1883
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
  "TOKEN_CREATE", "TOKEN_DATE", "TOKEN_DATETIME", "TOKEN_DAY",
  "TOKEN_DECIMAL", "TOKEN_DEFAULT", "TOKEN_DELETE", "TOKEN_DELIMITER",
  "TOKEN_DESC", "TOKEN_DISTINCT", "TOKEN_DOUBLE", "TOKEN_DROP",
  "TOKEN_ELSE", "TOKEN_END", "TOKEN_ESCAPE_STRINGS", "TOKEN_EMIT",
  "TOKEN_EXISTS", "TOKEN_EXTRACT", "TOKEN_FALSE", "TOKEN_FIRST",
  "TOKEN_FLOAT", "TOKEN_FOREIGN", "TOKEN_FROM", "TOKEN_FULL",
  "TOKEN_GROUP", "TOKEN_HASH", "TOKEN_HAVING", "TOKEN_HOUR", "TOKEN_IN",
  "TOKEN_INDEX", "TOKEN_INNER", "TOKEN_INSERT", "TOKEN_INTEGER",
  "TOKEN_INTERVAL", "TOKEN_INTO", "TOKEN_JOIN", "TOKEN_KEY", "TOKEN_LAST",
  "TOKEN_LEFT", "TOKEN_LIMIT", "TOKEN_LONG", "TOKEN_MINUTE", "TOKEN_MONTH",
  "TOKEN_NULL", "TOKEN_NULLS", "TOKEN_OFF", "TOKEN_ON", "TOKEN_ORDER",
  "TOKEN_OUTER", "TOKEN_PARTITION", "TOKEN_PARTITIONS", "TOKEN_PERCENT",
  "TOKEN_PRIMARY", "TOKEN_QUIT", "TOKEN_RANGE", "TOKEN_REAL",
  "TOKEN_REFERENCES", "TOKEN_RIGHT", "TOKEN_ROW_DELIMITER", "TOKEN_SECOND",
  "TOKEN_SELECT", "TOKEN_SET", "TOKEN_SMA", "TOKEN_SMALLINT",
  "TOKEN_TABLE", "TOKEN_THEN", "TOKEN_TIME", "TOKEN_TIMESTAMP",
  "TOKEN_TRUE", "TOKEN_TUPLESAMPLE", "TOKEN_UNIQUE", "TOKEN_UPDATE",
  "TOKEN_USING", "TOKEN_VALUES", "TOKEN_VARCHAR", "TOKEN_WHEN",
  "TOKEN_WHERE", "TOKEN_WITH", "TOKEN_WINDOW", "TOKEN_YEAR",
  "TOKEN_YEARMONTH", "TOKEN_EOF", "TOKEN_LEX_ERROR", "';'", "'\\n'", "'('",
  "')'", "','", "'%'", "$accept", "start", "sql_statement",
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
  "expression_list", "literal_value", "datetime_unit",
  "literal_value_commalist", "attribute_ref", "attribute_ref_list",
  "comparison_operation", "unary_operation", "add_operation",
  "multiply_operation", "name_commalist", "any_name", "boolean_value",
  "command", "command_argument_list", YY_NULLPTR
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
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,    59,    10,    40,    41,    44,    37
};
# endif

#define YYPACT_NINF -226

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-226)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     972,  -226,  -226,   -56,    82,   -31,    -8,   -18,    29,  -226,
     145,    82,    82,  -226,   123,    58,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,   -21,  -226,   -77,   129,
      82,  -226,  -226,    65,    82,    82,    82,    82,    82,  -226,
    -226,   562,    74,    85,  -226,   146,   103,  -226,  -226,  -226,
     176,  -226,  -226,  -226,  -226,    26,   237,   154,   121,   139,
    -226,   131,  -226,  -226,   263,   269,  -226,  -226,  -226,   657,
     147,  -226,   197,  -226,  -226,   158,  -226,  -226,   303,  -226,
    -226,  -226,  -226,  -226,  -226,   177,   236,   752,   316,   255,
     193,  -226,  -226,   213,   -10,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,   902,    15,    82,    82,   220,    82,    82,   163,
     166,   230,    82,    82,   507,  -226,  -226,   231,    82,  -226,
    -226,  -226,   507,    39,   -11,  -226,   359,  -226,   116,   116,
     362,  -226,   233,    19,  -226,    31,   139,   957,  -226,  -226,
      82,   957,  -226,  -226,  -226,  -226,   957,   269,  -226,    82,
     277,    -5,  -226,   373,  -226,   278,  -226,   112,  -226,   278,
      82,   107,    82,    82,   252,  -226,   254,  -226,   134,  1059,
     807,   220,   412,   382,   384,  -226,  -226,   360,   374,  1007,
     151,    14,   957,    56,  -226,   957,  -226,   334,   262,  -226,
    -226,  -226,  -226,  -226,  -226,   327,  -226,   264,  -226,  -226,
      21,    60,   144,  -226,   265,    60,     0,   330,  -226,  -226,
     -10,  -226,  -226,   270,   957,  -226,   229,   153,    82,  -226,
     957,  -226,    82,  -226,  -226,   273,   319,   323,   276,  -226,
    -226,  -226,   118,    82,   292,   107,    82,  -226,     6,  -226,
    -226,     7,    61,   507,   507,   181,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,   957,   280,   957,    43,  -226,   155,
     293,   957,    47,  -226,   354,   229,  -226,  -226,   957,  -226,
      99,    82,  -226,  -226,   324,  -226,   325,   328,   340,    31,
    -226,   418,   419,    60,   389,   357,  -226,   160,  -226,   957,
    -226,   229,  -226,   507,   299,   302,    82,   432,   100,   167,
    -226,   169,   411,    59,  -226,   304,   315,  -226,   350,   309,
    1007,  -226,   365,    82,  -226,  -226,     6,  -226,  -226,   384,
    -226,  -226,  -226,   957,   311,   244,   752,  -226,   229,   366,
    -226,  -226,  1007,   317,   229,   957,  -226,    23,  -226,  -226,
    -226,  -226,  -226,    31,   144,   352,   364,  -226,   957,   507,
     358,  -226,   229,    10,    82,    82,   172,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,   148,  -226,    82,  -226,  -226,  -226,
    -226,   326,   107,   421,   368,  -226,   507,  -226,  -226,   335,
    -226,   251,   752,  -226,   957,   180,  -226,  -226,  1007,   229,
    -226,   375,  -226,  -226,   321,   382,   426,   385,  -226,   189,
     196,  -226,   466,   100,  -226,    82,  -226,  -226,   341,   434,
    -226,    12,    82,   957,   198,   229,  -226,   202,   507,   957,
     471,   353,   377,  -226,  -226,  -226,   206,  -226,  -226,  -226,
    -226,    17,    82,    20,  -226,   348,   229,  -226,  -226,   382,
     349,  -226,    69,  -226,  1007,  -226,   391,    82,  -226,    82,
    -226,  -226,    82,  -226,   209,  -226,  -226,   355,  -226,   957,
    -226,  -226,   394,  -226,    82,   386,   356,  -226,   212,  -226,
      82,  -226,    96,  -226,  -226,   446,   427,    82,  -226,   214,
    -226,  -226,   957,  1007,   462,   226,   396,   321,  -226,  1007,
    -226,  -226,   488,  -226,  -226
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     6,   270,     0,     0,     0,     0,     0,     0,    18,
     112,     0,     0,     7,     0,     0,    15,     8,    10,    11,
      13,    14,     9,    17,    12,    16,     0,   105,     0,   268,
       0,   262,   263,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,   107,   108,     0,   145,     1,     3,     2,
       0,   106,     5,     4,   269,     0,     0,     0,     0,   174,
      25,     0,   228,   225,     0,   254,   115,    40,    29,     0,
       0,    30,    31,    34,    36,     0,    37,    39,     0,    41,
     224,    35,    38,    32,    33,     0,     0,     0,     0,     0,
     116,   117,   206,   121,   195,   197,   199,   202,   203,   204,
     201,   200,     0,   240,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,   101,   175,     0,     0,    91,
     226,   227,     0,     0,   220,   217,     0,    43,     0,   229,
       0,    44,     0,     0,   231,     0,   174,     0,   255,   256,
       0,     0,   120,   258,   259,   257,     0,     0,   198,     0,
       0,   174,   103,     0,   109,     0,   110,     0,   260,     0,
       0,     0,     0,     0,     0,    93,    66,    27,     0,     0,
       0,     0,     0,   176,   178,   180,   182,     0,   200,     0,
       0,     0,     0,   220,   214,     0,   218,     0,     0,   234,
     235,   236,   233,   237,   232,     0,   230,     0,   123,   205,
       0,     0,   147,   136,   122,   141,   124,   149,   118,   119,
     194,   196,   241,     0,     0,   207,   222,     0,     0,   100,
       0,   146,     0,    92,    19,     0,     0,     0,     0,    20,
      21,    22,     0,     0,     0,    64,     0,    42,    56,   181,
     189,     0,     0,     0,     0,     0,   244,   246,   247,   248,
     249,   245,   250,   252,     0,     0,     0,     0,   238,     0,
       0,     0,     0,   215,     0,   221,   213,    45,     0,    46,
     127,     0,   137,   143,   133,   128,   129,   131,     0,     0,
     140,     0,     0,   139,     0,   151,   208,     0,   209,     0,
     102,   104,   261,     0,     0,     0,     0,     0,     0,     0,
     242,     0,   240,     0,    63,    65,    68,    28,     0,     0,
       0,    47,     0,     0,    49,    55,    57,    26,   188,   177,
     179,   251,   253,     0,     0,     0,     0,   190,   187,     0,
     186,    90,     0,     0,   219,     0,   212,     0,   142,   144,
     134,   130,   132,     0,   148,     0,     0,   138,     0,     0,
     153,   210,   223,     0,     0,     0,     0,    96,   266,   267,
     265,   264,    97,    95,     0,    67,     0,    83,    84,    85,
      86,    87,     0,     0,    70,    48,     0,    51,    50,     0,
      54,     0,     0,   192,     0,     0,   185,   239,     0,   216,
     211,     0,   125,   126,   150,   152,     0,   155,    61,     0,
       0,    58,     0,     0,   243,     0,    24,    62,     0,     0,
      23,     0,     0,     0,     0,   183,   191,     0,     0,     0,
       0,   157,     0,    59,    98,    99,     0,    74,    76,    77,
      78,     0,     0,     0,    52,     0,   184,   193,    89,   135,
     154,   165,   168,   156,     0,   111,     0,     0,    88,     0,
      82,    80,     0,    79,     0,    72,    73,     0,    53,     0,
     169,   170,   171,   159,     0,   161,     0,    75,     0,    69,
       0,   166,     0,   167,   160,     0,     0,     0,    81,     0,
     172,   173,     0,     0,     0,     0,     0,   162,   163,     0,
     158,    60,     0,   164,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -131,  -226,
     329,   183,  -226,  -226,  -225,  -226,  -226,  -226,  -226,  -226,
    -226,    64,    48,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,   283,  -226,  -226,  -226,   397,
       2,  -226,  -226,  -226,   367,  -226,   -87,  -226,  -226,  -164,
     162,  -162,    -9,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,    49,  -226,  -226,    35,  -226,
    -121,   266,   272,   336,   -30,   369,   361,   416,  -130,  -226,
    -226,  -226,   338,  -226,   395,   339,  -208,  -167,   401,   136,
    -105,  -226,  -226,  -226,  -226,  -226,  -114,    -4,   122,  -226,
    -226
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,   167,   168,
      88,   315,   316,   317,   229,   305,   306,   234,   374,   410,
     457,   426,   427,   428,   429,   430,   371,   406,    21,    22,
     165,   299,    23,    24,   151,   152,    25,    26,    43,    44,
     132,    41,    89,    90,    91,   136,    92,   283,   278,   202,
     203,   272,   273,   204,   285,   350,   397,   421,   445,   446,
     465,   476,   484,   490,   440,   441,   462,   473,   115,   116,
     173,   174,   175,   176,   177,    94,    95,    96,    97,    98,
      99,   183,   184,   124,   125,   187,   217,   100,   195,   259,
     101,   301,   256,   102,   141,   146,   157,   103,   362,    28,
      29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   181,    27,    45,   180,   205,   287,    42,    46,   178,
     304,    93,   258,   143,   144,   243,   308,   178,   243,   156,
     243,    31,   243,    32,   450,    31,    55,    32,    51,   224,
      57,    58,    59,    60,    61,    31,   270,    32,   281,   123,
     138,   139,   149,   280,   138,   139,    34,   451,   201,   185,
     309,   241,    52,   329,   109,    53,    30,   133,    50,   310,
     138,   139,    36,   119,    31,   178,    32,   178,   138,   139,
     205,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    35,   138,   139,   240,   110,    31,    10,    32,   142,
     138,   139,   271,   455,    37,   367,    45,   311,   368,   369,
     153,    46,   460,   158,   159,   307,   312,    93,   166,   169,
     313,    38,   122,   201,   158,   344,   185,   282,   385,   114,
     216,   347,   456,    47,   314,   461,   145,   261,   300,    10,
     218,   206,    54,   150,   330,    56,   209,   255,   178,   178,
     394,   318,   242,   377,   398,   212,   434,   407,   150,   205,
     452,   225,   262,   199,   200,   265,   169,   390,   230,   231,
     335,   223,   182,   480,   200,   387,   358,   189,   327,   370,
     274,   207,   353,   297,   414,    39,   226,   275,   106,   182,
     298,   481,   356,   104,   216,   276,   219,    48,   178,    49,
     291,   190,   201,   359,   360,   199,   206,    46,   321,   322,
     323,    46,    40,   402,   277,   191,   192,   227,   160,   161,
     403,   162,   163,   205,   153,   274,   361,    31,   292,    32,
     105,   258,   275,   193,   325,   228,   328,  -127,   395,   302,
     276,   334,   169,   338,   138,   139,   107,   383,   337,    10,
     399,   400,   111,   194,   178,   140,   221,   222,   112,   277,
     138,   139,   117,   384,   113,   411,   201,   324,   108,   352,
     413,   404,   339,   114,   118,   138,   139,    46,   235,   236,
     120,   178,   138,   139,   487,   206,   121,   463,   127,    46,
     126,    31,    62,    32,    63,   260,   222,   288,   289,   331,
     332,   128,   158,   381,   351,   289,   216,   439,    64,    65,
     213,   363,   364,   365,   366,   389,   401,   222,   129,   379,
     130,    67,    68,   178,   416,   289,   488,   131,   216,    69,
      70,   134,   493,   422,   222,   135,    71,    72,   137,    73,
     423,   222,   437,   289,   214,    74,   438,   332,   468,   206,
     448,   449,    75,   469,   449,    76,   478,   222,   486,   222,
     158,   158,   216,   155,   415,   164,   479,    77,    78,   474,
     491,   222,   302,   485,   179,    79,   188,   198,    80,   197,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      81,   138,   139,   436,   220,   232,    10,   233,    82,   442,
     243,    83,    84,   244,   257,   266,   267,   268,   269,    85,
     279,   431,   284,   294,   286,    86,   293,   295,   435,   296,
      87,   215,   303,   326,   333,   336,    31,    62,    32,    63,
     340,   341,   170,   343,   342,   345,   346,   453,   431,   442,
     348,   349,   354,    64,    65,   355,   255,   357,   149,   372,
     373,   375,   376,   466,   382,   431,    67,    68,   158,   378,
     388,   392,   216,   396,    69,    70,   289,   386,   408,   405,
     302,    71,    72,   393,    73,   409,   158,   419,   412,   418,
      74,   424,   420,   158,   432,   433,   171,    75,   443,   444,
      76,   447,   458,   475,   459,   464,   472,   482,   470,   477,
     483,   489,    77,    78,   492,   494,   454,   467,   238,   380,
      79,   290,   154,    80,   208,   391,   239,   211,   471,   319,
     210,    31,    62,    32,    63,    81,   320,   170,   148,   186,
      10,   263,   264,    82,   417,   425,    83,    84,    64,    65,
     196,     0,     0,     0,    85,     0,     0,     0,     0,     0,
      86,    67,    68,     0,     0,   172,     0,     0,     0,    69,
      70,     0,     0,     0,     0,     0,    71,    72,     0,    73,
       0,     0,     0,     0,     0,    74,    31,    62,    32,    63,
       0,   171,    75,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    77,    78,     0,
       0,     0,     0,     0,     0,    79,    67,    68,    80,     0,
       0,     0,     0,     0,    69,    70,     0,     0,     0,     0,
      81,    71,    72,     0,    73,     0,     0,     0,    82,     0,
      74,    83,    84,     0,     0,     0,     0,    75,     0,    85,
      76,     0,     0,     0,     0,    86,     0,     0,     0,     0,
     172,     0,    77,    78,     0,     0,     0,     0,     0,     0,
      79,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,    31,    62,    32,    63,    81,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,    83,    84,    64,    65,
       0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
      86,    67,    68,     0,     0,    87,     0,     0,     0,    69,
      70,     0,     0,     0,     0,     0,    71,    72,     0,    73,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,    75,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,     0,
       0,     0,     0,     0,     0,    79,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,    31,    62,    32,    63,
      81,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,    83,    84,    64,    65,     0,     0,     0,     0,    85,
     122,     0,     0,     0,     0,    86,    67,    68,     0,     0,
      87,     0,     0,     0,    69,    70,     0,     0,     0,     0,
       0,    71,    72,     0,    73,     0,     0,     0,     0,     0,
      74,    31,    62,    32,    63,     0,     0,    75,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,    64,    65,
       0,     0,    77,    78,     0,     0,     0,     0,     0,     0,
      79,    67,    68,    80,     0,     0,     0,     0,     0,    69,
      70,     0,     0,     0,     0,    81,    71,    72,     0,    73,
      10,     0,     0,    82,     0,    74,    83,    84,     0,     0,
       0,   171,    75,     0,    85,    76,     0,     0,     0,     0,
      86,     0,     0,     0,     0,    87,     0,    77,    78,     0,
       0,     0,     0,     0,     0,    79,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,    31,    62,    32,    63,
      81,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,    83,    84,    64,   147,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,    86,    67,    68,     0,     0,
     172,     0,     0,     0,    69,    70,     0,     0,     0,     0,
       0,    71,    72,     0,    73,     0,     0,     0,     0,     0,
      74,    31,    62,    32,    63,     0,     0,    75,     0,     0,
      76,     0,     0,     1,     0,     2,     0,     0,    64,    65,
       0,     0,    77,    78,     0,     0,     0,     0,     0,     0,
      79,    67,    68,    80,     0,     0,     0,     0,     0,    69,
      70,     0,     0,     3,     0,    81,    71,    72,     0,    73,
       0,     0,    62,    82,    63,    74,    83,    84,     0,     4,
       5,     0,    75,     0,    85,    76,     6,     0,    64,   147,
      86,     7,     0,     0,     0,    87,     0,    77,    78,     0,
       0,    67,    68,     0,     0,    79,     0,     0,    80,     0,
      70,     8,     0,     0,     0,     0,    71,    72,     0,    73,
      81,     0,     0,     0,     0,    74,     0,     0,    82,     0,
       0,    83,    84,     9,     0,    76,     0,     0,     0,    85,
      10,     0,     0,     0,     0,    86,     0,    77,    78,     0,
      87,    11,     0,    67,    68,    79,     0,    12,    80,     0,
       0,    13,    70,     0,     0,     0,     0,     0,    71,    72,
      81,    73,     0,     0,     0,     0,     0,    74,    82,     0,
       0,    83,    84,     0,     0,     0,     0,    76,     0,    85,
       0,     0,     0,     0,     0,    86,     0,     0,     0,    77,
     237,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
       4,   122,     0,    12,   118,   135,   214,    11,    12,   114,
     235,    41,   179,    23,    24,     8,    10,   122,     8,   106,
       8,     4,     8,     6,     7,     4,    30,     6,    26,   160,
      34,    35,    36,    37,    38,     4,   200,     6,    38,    69,
      21,    22,    27,   205,    21,    22,    77,    30,   135,    60,
      44,   172,   129,    10,    28,   132,   112,    87,    79,    53,
      21,    22,    70,    61,     4,   170,     6,   172,    21,    22,
     200,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   112,    21,    22,   171,    59,     4,   108,     6,    93,
      21,    22,    32,    73,   112,    36,   105,    91,    39,    40,
     104,   105,    33,   107,   108,   236,   100,   137,   112,   113,
     104,    82,   123,   200,   118,   279,    60,   117,   326,   124,
     150,   283,   102,     0,   118,    56,   136,   113,   233,   108,
     135,   135,     3,   133,    91,    70,   140,    76,   243,   244,
     348,   134,   172,   310,   134,   149,   134,   372,   133,   279,
     133,    44,   182,   134,   133,   185,   160,   134,   162,   163,
     113,   159,   123,    67,   133,   332,    66,    51,   255,   110,
      71,   136,   293,    55,   382,    30,    69,    78,    32,   123,
      62,    85,   296,   109,   214,    86,   151,   129,   293,   131,
     220,    75,   279,    93,    94,   134,   200,   201,    17,    18,
      19,   205,    57,    55,   105,    89,    90,   100,    45,    46,
      62,    45,    46,   343,   218,    71,   116,     4,   222,     6,
     135,   388,    78,   107,   254,   118,   256,    83,   349,   233,
      86,   261,   236,   134,    21,    22,   133,   324,   268,   108,
     354,   355,     5,   127,   349,    32,   134,   135,    94,   105,
      21,    22,   121,     9,   133,   376,   343,    76,    82,   289,
       9,   366,   271,   124,   133,    21,    22,   271,   134,   135,
       7,   376,    21,    22,   482,   279,     7,   444,    81,   283,
     133,     4,     5,     6,     7,   134,   135,   134,   135,   134,
     135,   133,   296,   323,   134,   135,   326,   418,    21,    22,
      23,   134,   135,   134,   135,   335,   134,   135,     5,   313,
     133,    34,    35,   418,   134,   135,   483,    81,   348,    42,
      43,     5,   489,   134,   135,    70,    49,    50,   135,    52,
     134,   135,   134,   135,    57,    58,   134,   135,   452,   343,
     134,   135,    65,   134,   135,    68,   134,   135,   134,   135,
     354,   355,   382,   133,   384,   125,   470,    80,    81,   464,
     134,   135,   366,   477,   133,    88,     7,   134,    91,     7,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     103,    21,    22,   413,    11,   133,   108,   133,   111,   419,
       8,   114,   115,     9,    20,    61,   134,    70,   134,   122,
     135,   405,    72,    84,   134,   128,   133,    84,   412,   133,
     133,   134,   120,   133,   121,    61,     4,     5,     6,     7,
      96,    96,    10,    83,    96,     7,     7,   431,   432,   459,
      41,    74,   133,    21,    22,   133,    76,     5,    27,   135,
     125,    91,   133,   447,   133,   449,    34,    35,   452,    84,
     133,    99,   482,    95,    42,    43,   135,    91,    37,   133,
     464,    49,    50,    99,    52,    97,   470,    41,   133,    94,
      58,     5,    87,   477,   133,    41,    64,    65,     7,   126,
      68,   104,   134,    97,   135,    94,    92,    41,   133,   133,
      63,    29,    80,    81,    98,     7,   432,   449,   169,   316,
      88,   218,   105,    91,   137,   343,   170,   146,   459,   243,
     141,     4,     5,     6,     7,   103,   244,    10,   102,   124,
     108,   183,   183,   111,   388,   403,   114,   115,    21,    22,
     129,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
     128,    34,    35,    -1,    -1,   133,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    58,     4,     5,     6,     7,
      -1,    64,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    34,    35,    91,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
     103,    49,    50,    -1,    52,    -1,    -1,    -1,   111,    -1,
      58,   114,   115,    -1,    -1,    -1,    -1,    65,    -1,   122,
      68,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
     133,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,   114,   115,    21,    22,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
     128,    34,    35,    -1,    -1,   133,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,   114,   115,    21,    22,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,   128,    34,    35,    -1,    -1,
     133,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      58,     4,     5,     6,     7,    -1,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    34,    35,    91,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,   103,    49,    50,    -1,    52,
     108,    -1,    -1,   111,    -1,    58,   114,   115,    -1,    -1,
      -1,    64,    65,    -1,   122,    68,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,   133,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,   114,   115,    21,    22,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,   128,    34,    35,    -1,    -1,
     133,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      58,     4,     5,     6,     7,    -1,    -1,    65,    -1,    -1,
      68,    -1,    -1,     1,    -1,     3,    -1,    -1,    21,    22,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    34,    35,    91,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    31,    -1,   103,    49,    50,    -1,    52,
      -1,    -1,     5,   111,     7,    58,   114,   115,    -1,    47,
      48,    -1,    65,    -1,   122,    68,    54,    -1,    21,    22,
     128,    59,    -1,    -1,    -1,   133,    -1,    80,    81,    -1,
      -1,    34,    35,    -1,    -1,    88,    -1,    -1,    91,    -1,
      43,    79,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
     103,    -1,    -1,    -1,    -1,    58,    -1,    -1,   111,    -1,
      -1,   114,   115,   101,    -1,    68,    -1,    -1,    -1,   122,
     108,    -1,    -1,    -1,    -1,   128,    -1,    80,    81,    -1,
     133,   119,    -1,    34,    35,    88,    -1,   125,    91,    -1,
      -1,   129,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
     103,    52,    -1,    -1,    -1,    -1,    -1,    58,   111,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,    68,    -1,   122,
      -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    31,    47,    48,    54,    59,    79,   101,
     108,   119,   125,   129,   138,   139,   140,   141,   142,   143,
     144,   165,   166,   169,   170,   173,   174,   177,   236,   237,
     112,     4,     6,   234,    77,   112,    70,   112,    82,    30,
      57,   178,   234,   175,   176,   189,   234,     0,   129,   131,
      79,   177,   129,   132,     3,   234,    70,   234,   234,   234,
     234,   234,     5,     7,    21,    22,    23,    34,    35,    42,
      43,    49,    50,    52,    58,    65,    68,    80,    81,    88,
      91,   103,   111,   114,   115,   122,   128,   133,   147,   179,
     180,   181,   183,   211,   212,   213,   214,   215,   216,   217,
     224,   227,   230,   234,   109,   135,    32,   133,    82,    28,
      59,     5,    94,   133,   124,   205,   206,   121,   133,   177,
       7,     7,   123,   211,   220,   221,   133,    81,   133,     5,
     133,    81,   177,   211,     5,    70,   182,   135,    21,    22,
      32,   231,   234,    23,    24,   136,   232,    22,   214,    27,
     133,   171,   172,   234,   176,   133,   183,   233,   234,   234,
      45,    46,    45,    46,   125,   167,   234,   145,   146,   234,
      10,    64,   133,   207,   208,   209,   210,   211,   227,   133,
     233,   207,   123,   218,   219,    60,   221,   222,     7,    51,
      75,    89,    90,   107,   127,   225,   225,     7,   134,   134,
     133,   183,   186,   187,   190,   215,   234,   205,   181,   234,
     212,   213,   234,    23,    57,   134,   211,   223,   135,   205,
      11,   134,   135,   177,   145,    44,    69,   100,   118,   151,
     234,   234,   133,   133,   154,   134,   135,    81,   147,   210,
     183,   207,   211,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    76,   229,    20,   224,   226,
     134,   113,   211,   219,   222,   211,    61,   134,    70,   134,
     186,    32,   188,   189,    71,    78,    86,   105,   185,   135,
     188,    38,   117,   184,    72,   191,   134,   223,   134,   135,
     172,   211,   234,   133,    84,    84,   133,    55,    62,   168,
     227,   228,   234,   120,   151,   152,   153,   145,    10,    44,
      53,    91,   100,   104,   118,   148,   149,   150,   134,   208,
     209,    17,    18,    19,    76,   211,   133,   183,   211,    10,
      91,   134,   135,   121,   211,   113,    61,   211,   134,   189,
      96,    96,    96,    83,   186,     7,     7,   188,    41,    74,
     192,   134,   211,   207,   133,   133,   233,     5,    66,    93,
      94,   116,   235,   134,   135,   134,   135,    36,    39,    40,
     110,   163,   135,   125,   155,    91,   133,   224,    84,   234,
     148,   211,   133,   183,     9,   223,    91,   224,   133,   211,
     134,   187,    99,    99,   223,   207,    95,   193,   134,   233,
     233,   134,    55,    62,   227,   133,   164,   151,    37,    97,
     156,   207,   133,     9,   223,   211,   134,   226,    94,    41,
      87,   194,   134,   134,     5,   235,   158,   159,   160,   161,
     162,   234,   133,    41,   134,   234,   211,   134,   134,   207,
     201,   202,   211,     7,   126,   195,   196,   104,   134,   135,
       7,    30,   133,   234,   158,    73,   102,   157,   134,   135,
      33,    56,   203,   224,    94,   197,   234,   159,   233,   134,
     133,   202,    92,   204,   227,    97,   198,   133,   134,   233,
      67,    85,    41,    63,   199,   233,   134,   223,   224,    29,
     200,   134,    98,   224,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   137,   138,   138,   138,   138,   138,   138,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   141,
     141,   141,   141,   142,   143,   144,   145,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   148,   148,   148,
     148,   148,   148,   148,   149,   149,   150,   150,   151,   151,
     151,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   160,
     160,   161,   162,   163,   163,   163,   163,   164,   164,   165,
     165,   165,   165,   166,   167,   167,   168,   168,   168,   168,
     169,   170,   171,   171,   172,   173,   173,   174,   175,   175,
     176,   177,   178,   178,   178,   179,   179,   180,   180,   181,
     181,   181,   182,   183,   184,   184,   184,   185,   185,   185,
     185,   185,   185,   185,   185,   186,   186,   187,   187,   187,
     187,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     197,   198,   198,   199,   200,   201,   201,   202,   203,   203,
     203,   204,   204,   204,   205,   205,   206,   207,   207,   208,
     208,   209,   209,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   211,   211,   212,   212,   213,   213,
     214,   214,   214,   214,   214,   214,   214,   215,   215,   215,
     215,   216,   217,   217,   218,   218,   219,   220,   220,   221,
     222,   222,   223,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   225,   225,   225,   225,   225,   225,   226,   226,
     227,   227,   228,   228,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   230,   231,   231,   232,   232,   232,
     233,   233,   234,   234,   235,   235,   235,   235,   236,   237,
     237
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
       1,     1,     1,     1,     1,     3,     1,     3,     4,     4,
       5,     6,     5,     4,     1,     2,     4,     1,     2,     4,
       0,     2,     1,     3,     1,     1,     2,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       0
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
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1911 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOKEN_NAME  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1921 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOKEN_STRING_SINGLE_QUOTED  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1931 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOKEN_STRING_DOUBLE_QUOTED  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1941 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOKEN_UNSIGNED_NUMVAL  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 1951 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 139: /* sql_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1961 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 140: /* quit_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).quit_statement_) != nullptr) {
    delete ((*yyvaluep).quit_statement_);
  }
}
#line 1971 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 141: /* alter_table_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1981 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 142: /* create_table_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).create_table_statement_) != nullptr) {
    delete ((*yyvaluep).create_table_statement_);
  }
}
#line 1991 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 143: /* create_index_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 2001 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 144: /* drop_table_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).drop_table_statement_) != nullptr) {
    delete ((*yyvaluep).drop_table_statement_);
  }
}
#line 2011 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 145: /* column_def  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_);
  }
}
#line 2021 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 146: /* column_def_commalist  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_list_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_list_);
  }
}
#line 2031 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 147: /* data_type  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).data_type_) != nullptr) {
    delete ((*yyvaluep).data_type_);
  }
}
#line 2041 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 148: /* column_constraint_def  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_) != nullptr) {
    delete ((*yyvaluep).column_constraint_);
  }
}
#line 2051 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 149: /* column_constraint_def_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2061 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 150: /* opt_column_constraint_def_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2071 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 154: /* opt_column_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2081 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 155: /* opt_block_properties  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).block_properties_) != nullptr) {
    delete ((*yyvaluep).block_properties_);
  }
}
#line 2091 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 156: /* opt_partition_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).partition_clause_) != nullptr) {
    delete ((*yyvaluep).partition_clause_);
  }
}
#line 2101 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 157: /* partition_type  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2111 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 158: /* key_value_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2121 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 159: /* key_value  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_) != nullptr) {
    delete ((*yyvaluep).key_value_);
  }
}
#line 2131 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 160: /* key_string_value  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_value_) != nullptr) {
    delete ((*yyvaluep).key_string_value_);
  }
}
#line 2141 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 161: /* key_string_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_list_) != nullptr) {
    delete ((*yyvaluep).key_string_list_);
  }
}
#line 2151 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 162: /* key_integer_value  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_integer_value_) != nullptr) {
    delete ((*yyvaluep).key_integer_value_);
  }
}
#line 2161 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 163: /* index_type  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2171 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 164: /* opt_index_properties  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2181 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 165: /* insert_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).insert_statement_) != nullptr) {
    delete ((*yyvaluep).insert_statement_);
  }
}
#line 2191 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 166: /* copy_from_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_statement_) != nullptr) {
    delete ((*yyvaluep).copy_from_statement_);
  }
}
#line 2201 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 167: /* opt_copy_from_params  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2211 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 168: /* copy_from_params  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2221 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 169: /* update_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).update_statement_) != nullptr) {
    delete ((*yyvaluep).update_statement_);
  }
}
#line 2231 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 170: /* delete_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).delete_statement_) != nullptr) {
    delete ((*yyvaluep).delete_statement_);
  }
}
#line 2241 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 171: /* assignment_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_list_) != nullptr) {
    delete ((*yyvaluep).assignment_list_);
  }
}
#line 2251 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 172: /* assignment_item  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_) != nullptr) {
    delete ((*yyvaluep).assignment_);
  }
}
#line 2261 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 173: /* select_statement  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_statement_) != nullptr) {
    delete ((*yyvaluep).select_statement_);
  }
}
#line 2271 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 174: /* with_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2281 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 175: /* with_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2291 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 176: /* with_list_element  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_element_) != nullptr) {
    delete ((*yyvaluep).with_list_element_);
  }
}
#line 2301 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 177: /* select_query  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_query_) != nullptr) {
    delete ((*yyvaluep).select_query_);
  }
}
#line 2311 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 179: /* selection  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_) != nullptr) {
    delete ((*yyvaluep).selection_);
  }
}
#line 2321 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 180: /* selection_item_commalist  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_list_) != nullptr) {
    delete ((*yyvaluep).selection_list_);
  }
}
#line 2331 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 181: /* selection_item  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_item_) != nullptr) {
    delete ((*yyvaluep).selection_item_);
  }
}
#line 2341 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 182: /* from_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2351 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 183: /* subquery_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).subquery_expression_) != nullptr) {
    delete ((*yyvaluep).subquery_expression_);
  }
}
#line 2361 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 184: /* opt_sample_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_sample_clause_) != nullptr) {
    delete ((*yyvaluep).opt_sample_clause_);
  }
}
#line 2371 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 185: /* join_type  */
#line 592 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2377 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 186: /* joined_table_reference  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2387 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 187: /* table_reference  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2397 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 188: /* table_reference_signature  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2407 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 189: /* table_reference_signature_primary  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2417 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 190: /* joined_table_reference_commalist  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2427 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 191: /* opt_group_by_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_group_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_group_by_clause_);
  }
}
#line 2437 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 192: /* opt_having_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_having_clause_) != nullptr) {
    delete ((*yyvaluep).opt_having_clause_);
  }
}
#line 2447 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 193: /* opt_order_by_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_order_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_order_by_clause_);
  }
}
#line 2457 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 194: /* opt_limit_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_limit_clause_) != nullptr) {
    delete ((*yyvaluep).opt_limit_clause_);
  }
}
#line 2467 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 195: /* opt_window_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_window_clause_) != nullptr) {
    delete ((*yyvaluep).opt_window_clause_);
  }
}
#line 2477 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 196: /* window_duration  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2487 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 197: /* window_attribute  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2497 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 198: /* opt_window_partition  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_partition_by_list_) != nullptr) {
    delete ((*yyvaluep).window_partition_by_list_);
  }
}
#line 2507 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 199: /* emit_duration  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2517 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 200: /* age_duration  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2527 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 201: /* order_commalist  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_commalist_) != nullptr) {
    delete ((*yyvaluep).order_commalist_);
  }
}
#line 2537 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 202: /* order_item  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_item_) != nullptr) {
    delete ((*yyvaluep).order_item_);
  }
}
#line 2547 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 203: /* opt_order_direction  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2557 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 204: /* opt_nulls_first  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2567 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 205: /* opt_where_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2577 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 206: /* where_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2587 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 207: /* or_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2597 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 208: /* and_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2607 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 209: /* not_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2617 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 210: /* predicate_expression_base  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2627 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 211: /* add_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2637 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 212: /* multiply_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2647 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 213: /* unary_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2657 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 214: /* expression_base  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2667 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 215: /* function_call  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).function_call_) != nullptr) {
    delete ((*yyvaluep).function_call_);
  }
}
#line 2677 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 216: /* extract_function  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2687 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 217: /* case_expression  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2697 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 218: /* simple_when_clause_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_list_);
  }
}
#line 2707 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 219: /* simple_when_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_);
  }
}
#line 2717 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 220: /* searched_when_clause_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_list_);
  }
}
#line 2727 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 221: /* searched_when_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_);
  }
}
#line 2737 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 222: /* opt_else_clause  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2747 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 223: /* expression_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_list_) != nullptr) {
    delete ((*yyvaluep).expression_list_);
  }
}
#line 2757 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 224: /* literal_value  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2767 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 225: /* datetime_unit  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2777 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 226: /* literal_value_commalist  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_list_) != nullptr) {
    delete ((*yyvaluep).literal_value_list_);
  }
}
#line 2787 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 227: /* attribute_ref  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2797 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 228: /* attribute_ref_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2807 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 229: /* comparison_operation  */
#line 589 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2813 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 230: /* unary_operation  */
#line 590 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2819 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 231: /* add_operation  */
#line 591 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2825 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 232: /* multiply_operation  */
#line 591 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2831 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 233: /* name_commalist  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 2841 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 234: /* any_name  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2851 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 235: /* boolean_value  */
#line 588 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2857 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 236: /* command  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_) != nullptr) {
    delete ((*yyvaluep).command_);
  }
}
#line 2867 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 237: /* command_argument_list  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_argument_list_) != nullptr) {
    delete ((*yyvaluep).command_argument_list_);
  }
}
#line 2877 "SqlParser_gen.cpp" /* yacc.c:1257  */
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
#line 603 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3174 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 607 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3183 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 611 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3192 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 615 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3201 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 619 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    YYABORT;
  }
#line 3209 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 622 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Regular yyparse() return codes are non-negative, so use a negative one here.
    return -1;
  }
#line 3218 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 629 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3226 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 632 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].copy_from_statement_);
  }
#line 3234 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 635 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].create_table_statement_);
  }
#line 3242 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 638 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3250 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 641 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].delete_statement_);
  }
#line 3258 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 644 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].drop_table_statement_);
  }
#line 3266 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 647 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].insert_statement_);
  }
#line 3274 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 650 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].quit_statement_);
  }
#line 3282 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 653 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].select_statement_);
  }
#line 3290 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 656 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].update_statement_);
  }
#line 3298 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 662 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.quit_statement_) = new quickstep::ParseStatementQuit((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3306 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 668 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].attribute_definition_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3318 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 675 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3329 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 681 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3341 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 688 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3353 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 697 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.create_table_statement_) = new quickstep::ParseStatementCreateTable((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].attribute_definition_list_), (yyvsp[-1].block_properties_), (yyvsp[0].partition_clause_));
  }
#line 3361 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 702 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].key_value_list_)) {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_), (yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].key_value_list_));
    } else {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_));
    }
  }
#line 3373 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 711 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.drop_table_statement_) = new quickstep::ParseStatementDropTable((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_));
  }
#line 3381 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 716 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_) = new quickstep::ParseAttributeDefinition((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].data_type_), (yyvsp[0].column_constraint_list_));
  }
#line 3389 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 721 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = new quickstep::PtrList<quickstep::ParseAttributeDefinition>();
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3398 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 725 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = (yyvsp[-2].attribute_definition_list_);
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3407 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 731 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "BIT data type");
    YYERROR;
  }
#line 3417 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 736 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3425 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 739 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3433 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 742 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "TIME data type");
    YYERROR;
  }
#line 3443 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 747 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3451 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 750 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3459 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 753 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3467 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 756 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3475 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 759 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kFloat));
  }
#line 3483 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 762 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3491 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 765 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3499 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 768 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3507 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 771 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3515 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 774 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3532 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 786 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetimeInterval));
  }
#line 3540 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 789 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kYearMonthInterval));
  }
#line 3548 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 792 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3571 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 810 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3594 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 830 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNull((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3602 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 833 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNotNull((yylsp[-1]).first_line, (yylsp[-1]).first_column);
  }
#line 3610 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 836 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "Column Constraints (UNIQUE)");
    YYERROR;
  }
#line 3620 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 841 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3630 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 846 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[0].literal_value_);
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (DEFAULT)");
    YYERROR;
  }
#line 3641 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 852 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Column Constraints (CHECK)");
    YYERROR;
  }
#line 3652 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 858 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_value_);
    NotSupported(&(yylsp[-4]), yyscanner, "Foreign Keys");
    YYERROR;
  }
#line 3664 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 867 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[-1].column_constraint_list_);
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3673 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 871 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = new quickstep::PtrList<quickstep::ParseColumnConstraint>();
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3682 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 877 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = nullptr;
  }
#line 3690 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 880 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[0].column_constraint_list_);
  }
#line 3698 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 885 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (UNIQUE)");
    YYERROR;
  }
#line 3708 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 890 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-4]), yyscanner, "Table Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3718 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 895 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-6].string_list_);
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-9]), yyscanner, "Table Constraints (FOREIGN KEY)");
    YYERROR;
  }
#line 3730 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 902 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (CHECK)");
    YYERROR;
  }
#line 3740 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 909 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[-2]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3749 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 913 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3758 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 919 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3766 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 922 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = $1; */
  }
#line 3774 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 927 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = nullptr;
  }
#line 3782 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 930 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = (yyvsp[-1].attribute_list_);
  }
#line 3790 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 935 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = nullptr;
  }
#line 3798 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 938 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = new quickstep::ParseBlockProperties((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].key_value_list_));
  }
#line 3806 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 943 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.partition_clause_) = nullptr;
  }
#line 3814 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 946 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3836 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 965 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionSchemeHeader::PartitionType::kHash));
  }
#line 3845 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 969 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionSchemeHeader::PartitionType::kRange));
  }
#line 3854 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 975 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = new quickstep::PtrList<quickstep::ParseKeyValue>();
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3863 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 979 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-2].key_value_list_);
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3872 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 985 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_value_);
  }
#line 3880 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 988 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_list_);
  }
#line 3888 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 991 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_integer_value_);
  }
#line 3896 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 996 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].string_value_));
  }
#line 3904 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 999 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // This is a special case to handle the COMPRESS ALL option of the BLOCK PROPERTIES.
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_),
        new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, "ALL"));
  }
#line 3914 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1006 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_list_) = new quickstep::ParseKeyStringList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 3922 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1011 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.key_integer_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Value must be an integer");
      YYERROR;
    }
    (yyval.key_integer_value_) = new quickstep::ParseKeyIntegerValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].numeric_literal_value_));
  }
#line 3936 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1022 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Defaults to BitWeavingV, but IndexProperties can change this to H.
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBitWeavingV));
  }
#line 3946 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1027 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBloomFilter));
  }
#line 3955 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1031 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kCSBTree));
  }
#line 3964 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1035 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kSMA));
  }
#line 3973 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1041 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = nullptr;
  }
#line 3981 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1044 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-1].key_value_list_);
  }
#line 3989 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1050 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-7].string_value_);
    delete (yyvsp[-5].string_list_);
    delete (yyvsp[-1].literal_value_list_);
    (yyval.insert_statement_) = nullptr;
    NotSupported(&(yylsp[-6]), yyscanner, "list of column names in INSERT statement");
    YYERROR;
  }
#line 4002 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1058 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertTuple((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].string_value_), (yyvsp[-1].literal_value_list_));
  }
#line 4010 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1061 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-3]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), nullptr);
  }
#line 4018 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1064 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-4]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), (yyvsp[-4].with_list_));
  }
#line 4026 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1070 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_statement_) = new quickstep::ParseStatementCopyFrom((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_value_), (yyvsp[0].copy_from_params_));
  }
#line 4034 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1075 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = nullptr;
  }
#line 4042 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1078 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-1].copy_from_params_);
  }
#line 4050 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1083 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4059 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1087 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4068 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1091 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4077 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1095 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4086 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1101 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.update_statement_) = new quickstep::ParseStatementUpdate((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].assignment_list_), (yyvsp[0].predicate_));
  }
#line 4094 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1106 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.delete_statement_) = new quickstep::ParseStatementDelete((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].predicate_));
  }
#line 4102 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1111 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = (yyvsp[-2].assignment_list_);
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4111 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1115 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = new quickstep::PtrList<quickstep::ParseAssignment>();
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4120 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1121 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_) = new quickstep::ParseAssignment((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[0].expression_));
  }
#line 4128 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1127 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].select_query_), nullptr);
  }
#line 4136 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1130 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].select_query_), (yyvsp[-1].with_list_));
  }
#line 4144 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1135 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[0].with_list_);
  }
#line 4152 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1140 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = new quickstep::PtrVector<quickstep::ParseSubqueryTableReference>();
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4161 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1144 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[-2].with_list_);
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4170 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1150 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_element_) = new quickstep::ParseSubqueryTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].subquery_expression_));
    (yyval.with_list_element_)->set_table_reference_signature((yyvsp[-2].table_reference_signature_));
  }
#line 4179 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1157 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_query_) = new quickstep::ParseSelect((yylsp[-9]).first_line, (yylsp[-9]).first_column, (yyvsp[-7].selection_), (yyvsp[-6].table_reference_list_), (yyvsp[-5].predicate_), (yyvsp[-4].opt_group_by_clause_), (yyvsp[-3].opt_having_clause_), (yyvsp[-2].opt_order_by_clause_), (yyvsp[-1].opt_limit_clause_), (yyvsp[0].opt_window_clause_));
  }
#line 4187 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1162 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 4195 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1165 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "ALL in selection");
    YYERROR;
  }
#line 4204 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1169 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "DISTINCT in selection");
    YYERROR;
  }
#line 4213 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1175 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = new quickstep::ParseSelectionStar((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 4221 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1178 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = (yyvsp[0].selection_list_);
  }
#line 4229 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1183 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = new quickstep::ParseSelectionList((yylsp[0]).first_line, (yylsp[0]).first_column);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4238 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1187 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = (yyvsp[-2].selection_list_);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4247 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1193 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[0].string_value_));
  }
#line 4255 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1196 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].expression_), (yyvsp[0].string_value_));
  }
#line 4263 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1199 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].expression_));
  }
#line 4271 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1204 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[0].table_reference_list_);
  }
#line 4279 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1209 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.subquery_expression_) = new quickstep::ParseSubqueryExpression((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].select_query_));
  }
#line 4287 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1214 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = NULL;
  }
#line 4295 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1217 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, true, (yyvsp[-1].numeric_literal_value_));
  }
#line 4303 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1220 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].numeric_literal_value_));
  }
#line 4311 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1225 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4319 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1228 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4327 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1231 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4335 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1234 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4343 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1237 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4351 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1240 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4359 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1243 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4367 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1246 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4375 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1251 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseJoinedTableReference((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].join_type_), (yyvsp[-5].table_reference_), (yyvsp[-2].table_reference_), (yyvsp[0].predicate_));
  }
#line 4383 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1254 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = (yyvsp[0].table_reference_);
  }
#line 4391 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1259 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSubqueryTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].subquery_expression_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4400 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1263 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].opt_sample_clause_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4409 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1267 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].opt_sample_clause_));
  }
#line 4417 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1270 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].function_call_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4426 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1274 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].function_call_));
  }
#line 4434 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1277 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = (yyvsp[-1].table_reference_);
  }
#line 4442 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1282 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4450 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1285 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4458 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1290 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4466 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1293 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4474 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1298 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = new quickstep::PtrList<quickstep::ParseTableReference>();
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4483 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1302 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[-2].table_reference_list_);
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4492 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1308 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = nullptr;
  }
#line 4500 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1311 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = new quickstep::ParseGroupBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].expression_list_));
  }
#line 4508 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1316 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = nullptr;
  }
#line 4516 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1319 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = new quickstep::ParseHaving((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4524 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1324 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = nullptr;
  }
#line 4532 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1327 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = new quickstep::ParseOrderBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].order_commalist_));
  }
#line 4540 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1332 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_limit_clause_) = nullptr;
  }
#line 4548 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1335 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 4570 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1354 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = nullptr;
  }
#line 4578 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1357 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = new quickstep::ParseWindow((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].attribute_), (yyvsp[-2].window_partition_by_list_), (yyvsp[-4].literal_value_), (yyvsp[-1].literal_value_), (yyvsp[0].literal_value_));
  }
#line 4586 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1362 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4594 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1367 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = (yyvsp[0].attribute_);
  }
#line 4602 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1372 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = nullptr;
  }
#line 4610 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1375 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = (yyvsp[0].expression_list_);
  }
#line 4618 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1380 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4626 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1385 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4634 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1390 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = new quickstep::PtrList<quickstep::ParseOrderByItem>();
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4643 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1394 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = (yyvsp[-2].order_commalist_);
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4652 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1400 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_item_) = new quickstep::ParseOrderByItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[-1].order_direction_), (yyvsp[0].order_direction_));
    delete (yyvsp[-1].order_direction_);
    delete (yyvsp[0].order_direction_);
  }
#line 4662 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1407 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4670 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1410 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4678 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1413 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4686 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1418 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4694 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1421 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4702 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1424 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4710 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1430 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = nullptr;
  }
#line 4718 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1433 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4726 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1438 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4734 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1443 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kDisjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateDisjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4748 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1452 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4756 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1457 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kConjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateConjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4770 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1466 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4778 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1471 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4786 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1474 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4794 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1479 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4802 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1482 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line, (yylsp[-4]).first_column,
        new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_)));
  }
#line 4812 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1487 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4823 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1493 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4834 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1499 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateComparison((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].comparison_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4842 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1502 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[-1].predicate_);
  }
#line 4850 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1505 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateExists((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].subquery_expression_));
  }
#line 4858 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1508 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].expression_), (yyvsp[0].subquery_expression_));
  }
#line 4866 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1511 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-1].expression_list_));
  }
#line 4874 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1514 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-2]).first_line,
        (yylsp[-2]).first_column,
        new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-3].expression_), (yyvsp[0].subquery_expression_)));
  }
#line 4885 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1520 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line,
        (yylsp[-4]).first_column,
        new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-1].expression_list_)));
  }
#line 4896 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1529 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4904 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1532 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4912 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1537 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4920 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1540 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4928 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1545 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseUnaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].unary_operation_), (yyvsp[0].expression_));
  }
#line 4936 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1548 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4944 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1553 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].attribute_);
  }
#line 4952 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1556 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_));
  }
#line 4960 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1559 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].function_call_);
  }
#line 4968 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1562 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4976 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1565 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4984 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1568 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[-1].expression_);
  }
#line 4992 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1571 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].subquery_expression_);
  }
#line 5000 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1576 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-2].string_value_), new quickstep::PtrList<quickstep::ParseExpression>());
  }
#line 5009 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1580 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), new quickstep::ParseStar((yylsp[-1]).first_line, (yylsp[-1]).first_column));
  }
#line 5018 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1584 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-3]).first_line, (yylsp[-3]).first_column, false, (yyvsp[-3].string_value_), (yyvsp[-1].expression_list_));
  }
#line 5026 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1587 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-4]).first_line, (yylsp[-4]).first_column, true, (yyvsp[-4].string_value_), (yyvsp[-1].expression_list_));
  }
#line 5034 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1592 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseExtractFunction((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].expression_));
  }
#line 5042 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1597 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSimpleCaseExpression((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].expression_), (yyvsp[-2].simple_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 5050 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1600 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSearchedCaseExpression((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].searched_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 5058 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1605 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSimpleWhenClause>;
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5067 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1609 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_list_) = (yyvsp[-1].simple_when_clause_list_);
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5076 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1615 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_) = new quickstep::ParseSimpleWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 5084 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1620 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSearchedWhenClause>;
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5093 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1624 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_list_) = (yyvsp[-1].searched_when_clause_list_);
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5102 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1630 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_) = new quickstep::ParseSearchedWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].predicate_), (yyvsp[0].expression_));
  }
#line 5110 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1635 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = NULL;
  }
#line 5118 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1638 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5126 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1643 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = new quickstep::PtrList<quickstep::ParseExpression>();
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5135 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1647 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = (yyvsp[-2].expression_list_);
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5144 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1653 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::NullParseLiteralValue((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 5152 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1656 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5160 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1659 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5168 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1662 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 5185 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1674 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_),
                                                nullptr);  // No explicit type.
  }
#line 5194 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1678 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 5218 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1697 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::StringParseLiteralValue *parse_value;
    const std::string &datetime_type_value = (yyvsp[0].string_value_)->value();
    if (quickstep::StringParseLiteralValue::ParseAmbiguousInterval(
        &((yyvsp[-1].string_value_)->append((" " + datetime_type_value).c_str(), datetime_type_value.length() + 1)),
        &parse_value)) {
      (yyval.literal_value_) = parse_value;
    } else {
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    }
  }
#line 5236 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1710 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 5254 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1725 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("YEAR"));
  }
#line 5262 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1728 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("MONTH"));
  }
#line 5270 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1731 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("DAY"));
  }
#line 5278 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1734 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("HOUR"));
  }
#line 5286 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1737 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("MINUTE"));
  }
#line 5294 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1740 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("SECOND"));
  }
#line 5302 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1745 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = new quickstep::PtrList<quickstep::ParseScalarLiteral>();
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5311 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1749 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = (yyvsp[-2].literal_value_list_);
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5320 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1755 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 5328 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1758 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_), (yyvsp[-2].string_value_));
  }
#line 5336 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1763 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = new quickstep::PtrList<quickstep::ParseAttribute>();
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5345 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1767 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = (yyvsp[-2].attribute_list_);
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5354 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1774 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kEqual);
  }
#line 5362 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1777 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotEqual);
  }
#line 5370 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1780 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLess);
  }
#line 5378 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1783 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLessOrEqual);
  }
#line 5386 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1786 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreater);
  }
#line 5394 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1789 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreaterOrEqual);
  }
#line 5402 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1792 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLike);
  }
#line 5410 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1795 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotLike);
  }
#line 5418 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1798 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kRegexMatch);
  }
#line 5426 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1801 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotRegexMatch);
  }
#line 5434 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1806 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * '-' TOKEN_UNSIGNED_NUMVAL case in 'literal_value'. Because Bison prefers
     * to shift rather than reduce, the case in 'literal_value' has precedence
     * over this one.
     **/
    (yyval.unary_operation_) = &quickstep::UnaryOperationFactory::GetUnaryOperation(quickstep::UnaryOperationID::kNegate);
  }
#line 5448 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1817 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kAdd);
  }
#line 5456 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1820 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kSubtract);
  }
#line 5464 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1825 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kModulo);
  }
#line 5472 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1828 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kMultiply);
  }
#line 5480 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1831 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kDivide);
  }
#line 5488 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1837 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = new quickstep::PtrList<quickstep::ParseString>();
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5497 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1841 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = (yyvsp[-2].string_list_);
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5506 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1847 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5514 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1850 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].string_value_)->value().empty()) {
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Zero-length identifier");
    }
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5525 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1858 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 5533 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1861 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 5541 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1864 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 5549 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1867 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 5557 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1873 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.command_) = new quickstep::ParseCommand((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].command_argument_list_));
  }
#line 5565 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1878 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::PtrVector<quickstep::ParseString> *argument_list = (yyvsp[-1].command_argument_list_);
    argument_list->push_back((yyvsp[0].string_value_));
    (yyval.command_argument_list_) = argument_list;
  }
#line 5575 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1883 "../SqlParser.ypp" /* yacc.c:1646  */
    { /* Epsilon, an empy match. */
    (yyval.command_argument_list_) = new quickstep::PtrVector<quickstep::ParseString>();
  }
#line 5583 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;


#line 5587 "SqlParser_gen.cpp" /* yacc.c:1646  */
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
#line 1887 "../SqlParser.ypp" /* yacc.c:1906  */


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
