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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
 * (https://www.gnu.org/software/bison/manual/html_node/Location-Default-Action.html).
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
    TOKEN_FOR = 319,
    TOKEN_FOREIGN = 320,
    TOKEN_FROM = 321,
    TOKEN_FULL = 322,
    TOKEN_GROUP = 323,
    TOKEN_HASH = 324,
    TOKEN_HAVING = 325,
    TOKEN_HOUR = 326,
    TOKEN_IN = 327,
    TOKEN_INDEX = 328,
    TOKEN_INNER = 329,
    TOKEN_INSERT = 330,
    TOKEN_INTEGER = 331,
    TOKEN_INTERVAL = 332,
    TOKEN_INTO = 333,
    TOKEN_JOIN = 334,
    TOKEN_KEY = 335,
    TOKEN_LAST = 336,
    TOKEN_LEFT = 337,
    TOKEN_LIMIT = 338,
    TOKEN_LONG = 339,
    TOKEN_MINUTE = 340,
    TOKEN_MONTH = 341,
    TOKEN_NULL = 342,
    TOKEN_NULLS = 343,
    TOKEN_OFF = 344,
    TOKEN_ON = 345,
    TOKEN_ORDER = 346,
    TOKEN_OUTER = 347,
    TOKEN_PARTITION = 348,
    TOKEN_PARTITIONS = 349,
    TOKEN_PERCENT = 350,
    TOKEN_PRIMARY = 351,
    TOKEN_QUIT = 352,
    TOKEN_RANGE = 353,
    TOKEN_REAL = 354,
    TOKEN_REFERENCES = 355,
    TOKEN_RIGHT = 356,
    TOKEN_ROW_DELIMITER = 357,
    TOKEN_SECOND = 358,
    TOKEN_SELECT = 359,
    TOKEN_SET = 360,
    TOKEN_SMA = 361,
    TOKEN_SMALLINT = 362,
    TOKEN_SUBSTRING = 363,
    TOKEN_TABLE = 364,
    TOKEN_THEN = 365,
    TOKEN_TIME = 366,
    TOKEN_TIMESTAMP = 367,
    TOKEN_TRUE = 368,
    TOKEN_TUPLESAMPLE = 369,
    TOKEN_UNIQUE = 370,
    TOKEN_UPDATE = 371,
    TOKEN_USING = 372,
    TOKEN_VALUES = 373,
    TOKEN_VARCHAR = 374,
    TOKEN_WHEN = 375,
    TOKEN_WHERE = 376,
    TOKEN_WITH = 377,
    TOKEN_WINDOW = 378,
    TOKEN_YEAR = 379,
    TOKEN_YEARMONTH = 380,
    TOKEN_EOF = 381,
    TOKEN_LEX_ERROR = 382
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

#line 417 "SqlParser_gen.cpp" /* yacc.c:355  */
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

#line 450 "SqlParser_gen.cpp" /* yacc.c:358  */

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
#define YYLAST   1515

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  273
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  505

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   382

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     134,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   138,     2,     2,
     135,   136,    23,    21,   137,    22,    27,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   133,
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
     130,   131,   132
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   606,   606,   610,   614,   618,   622,   625,   632,   635,
     638,   641,   644,   647,   650,   653,   656,   659,   665,   671,
     678,   684,   691,   700,   705,   714,   719,   724,   728,   734,
     739,   742,   745,   750,   753,   756,   759,   762,   765,   768,
     771,   774,   777,   789,   792,   795,   813,   833,   836,   839,
     844,   849,   855,   861,   870,   874,   880,   883,   888,   893,
     898,   905,   912,   916,   922,   925,   930,   933,   938,   941,
     946,   949,   968,   972,   978,   982,   988,   991,   994,   999,
    1002,  1009,  1014,  1025,  1030,  1034,  1038,  1044,  1047,  1053,
    1061,  1064,  1067,  1073,  1078,  1081,  1086,  1090,  1094,  1098,
    1104,  1109,  1114,  1118,  1124,  1130,  1133,  1138,  1143,  1147,
    1153,  1159,  1165,  1168,  1172,  1178,  1181,  1186,  1190,  1196,
    1199,  1202,  1207,  1212,  1217,  1220,  1223,  1228,  1231,  1234,
    1237,  1240,  1243,  1246,  1249,  1254,  1257,  1262,  1266,  1270,
    1273,  1277,  1280,  1285,  1288,  1293,  1296,  1301,  1305,  1311,
    1314,  1319,  1322,  1327,  1330,  1335,  1338,  1357,  1360,  1365,
    1370,  1375,  1378,  1383,  1388,  1393,  1397,  1403,  1410,  1413,
    1416,  1421,  1424,  1427,  1433,  1436,  1441,  1446,  1455,  1460,
    1469,  1474,  1477,  1482,  1485,  1490,  1496,  1502,  1505,  1508,
    1511,  1514,  1517,  1523,  1532,  1535,  1540,  1543,  1548,  1551,
    1556,  1559,  1562,  1565,  1568,  1571,  1574,  1577,  1582,  1586,
    1590,  1593,  1598,  1603,  1607,  1613,  1616,  1621,  1625,  1631,
    1636,  1640,  1646,  1651,  1654,  1659,  1663,  1669,  1672,  1675,
    1678,  1690,  1694,  1713,  1726,  1741,  1744,  1747,  1750,  1753,
    1756,  1761,  1765,  1771,  1774,  1779,  1783,  1790,  1793,  1796,
    1799,  1802,  1805,  1808,  1811,  1814,  1817,  1822,  1833,  1836,
    1841,  1844,  1847,  1853,  1857,  1863,  1866,  1874,  1877,  1880,
    1883,  1889,  1894,  1899
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
  "TOKEN_FLOAT", "TOKEN_FOR", "TOKEN_FOREIGN", "TOKEN_FROM", "TOKEN_FULL",
  "TOKEN_GROUP", "TOKEN_HASH", "TOKEN_HAVING", "TOKEN_HOUR", "TOKEN_IN",
  "TOKEN_INDEX", "TOKEN_INNER", "TOKEN_INSERT", "TOKEN_INTEGER",
  "TOKEN_INTERVAL", "TOKEN_INTO", "TOKEN_JOIN", "TOKEN_KEY", "TOKEN_LAST",
  "TOKEN_LEFT", "TOKEN_LIMIT", "TOKEN_LONG", "TOKEN_MINUTE", "TOKEN_MONTH",
  "TOKEN_NULL", "TOKEN_NULLS", "TOKEN_OFF", "TOKEN_ON", "TOKEN_ORDER",
  "TOKEN_OUTER", "TOKEN_PARTITION", "TOKEN_PARTITIONS", "TOKEN_PERCENT",
  "TOKEN_PRIMARY", "TOKEN_QUIT", "TOKEN_RANGE", "TOKEN_REAL",
  "TOKEN_REFERENCES", "TOKEN_RIGHT", "TOKEN_ROW_DELIMITER", "TOKEN_SECOND",
  "TOKEN_SELECT", "TOKEN_SET", "TOKEN_SMA", "TOKEN_SMALLINT",
  "TOKEN_SUBSTRING", "TOKEN_TABLE", "TOKEN_THEN", "TOKEN_TIME",
  "TOKEN_TIMESTAMP", "TOKEN_TRUE", "TOKEN_TUPLESAMPLE", "TOKEN_UNIQUE",
  "TOKEN_UPDATE", "TOKEN_USING", "TOKEN_VALUES", "TOKEN_VARCHAR",
  "TOKEN_WHEN", "TOKEN_WHERE", "TOKEN_WITH", "TOKEN_WINDOW", "TOKEN_YEAR",
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
  "substr_function", "case_expression", "simple_when_clause_list",
  "simple_when_clause", "searched_when_clause_list",
  "searched_when_clause", "opt_else_clause", "expression_list",
  "literal_value", "datetime_unit", "literal_value_commalist",
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
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,    59,    10,    40,    41,    44,    37
};
# endif

#define YYPACT_NINF -230

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-230)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     257,  -230,  -230,   -56,   127,   -41,    36,   -35,    35,  -230,
      37,   127,   127,  -230,    91,    95,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,   -33,  -230,    50,   134,
     127,  -230,  -230,    84,   127,   127,   127,   127,   127,  -230,
    -230,   740,    69,    55,  -230,   174,    62,  -230,  -230,  -230,
     125,  -230,  -230,  -230,  -230,    29,   205,   148,    94,   121,
    -230,    80,  -230,  -230,   244,   250,  -230,  -230,  -230,   844,
     129,  -230,   185,  -230,  -230,   136,  -230,  -230,   274,  -230,
    -230,  -230,  -230,   152,  -230,  -230,   167,   219,   959,   308,
     254,   178,  -230,  -230,   203,    27,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  1178,    -3,   127,   127,   184,   127,
     127,   195,   204,   194,   127,   127,   636,  -230,  -230,   192,
     127,  -230,  -230,  -230,   636,    43,    -5,  -230,   324,  -230,
     123,   123,  1282,   329,  -230,   202,    18,  -230,    16,   121,
    1282,  -230,  -230,   127,  1282,  -230,  -230,  -230,  -230,  1282,
     250,  -230,   127,   417,   -44,  -230,   328,  -230,   231,  -230,
     117,  -230,   231,   127,   101,   127,   127,   206,  -230,   207,
    -230,   119,  1385,  1074,   184,   521,   335,   337,  -230,  -230,
     501,   330,  1332,   126,    21,  1282,    48,  -230,  1282,  -230,
     283,   212,  -230,  -230,  -230,  -230,  -230,  -230,   278,  -230,
      24,   215,  -230,  -230,    15,    77,   132,  -230,   216,    77,
     -22,   279,  -230,  -230,    27,  -230,  -230,   218,  1282,  -230,
     248,   137,   127,  -230,  1282,  -230,   127,  -230,  -230,   220,
     273,   276,   228,  -230,  -230,  -230,    34,   127,   242,   101,
     127,  -230,    75,  -230,  -230,    17,   605,   636,   636,    52,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  1282,   234,
    1282,    25,  -230,   141,   247,  1282,    31,  -230,   310,   248,
    -230,  -230,  1282,   366,  -230,   106,   127,  -230,  -230,   277,
    -230,   280,   282,   291,    16,  -230,   369,   373,    77,   340,
     307,  -230,   145,  -230,  1282,  -230,   248,  -230,   636,   251,
     252,   127,   378,   -17,   149,  -230,   153,   358,    87,  -230,
     253,   262,  -230,   299,   259,  1332,  -230,   311,   127,  -230,
    -230,    75,  -230,  -230,   337,  -230,  -230,  -230,  1282,   260,
     161,   959,  -230,   248,   300,  -230,  -230,  1332,   263,   248,
    1282,  -230,    22,     6,  -230,  -230,  -230,  -230,  -230,    16,
     132,   297,   301,  -230,  1282,   636,   303,  -230,   248,    20,
     127,   127,   155,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
     165,  -230,   127,  -230,  -230,  -230,  -230,   267,   101,   367,
     305,  -230,   636,  -230,  -230,   270,  -230,   166,   959,  -230,
    1282,   157,  -230,  -230,  1332,   248,  -230,   399,  -230,   312,
    -230,  -230,   271,   335,   370,   322,  -230,   159,   162,  -230,
     407,   -17,  -230,   127,  -230,  -230,   284,   372,  -230,    28,
     127,  1282,   171,   248,  -230,   173,   281,   636,  1282,   408,
     286,   313,  -230,  -230,  -230,   181,  -230,  -230,  -230,  -230,
       8,   127,   -11,  -230,   289,   248,  -230,  -230,  -230,   335,
     290,  -230,    65,  -230,  1332,  -230,   325,   127,  -230,   127,
    -230,  -230,   127,  -230,   187,  -230,  -230,   293,  -230,  1282,
    -230,  -230,   333,  -230,   127,   331,   295,  -230,   193,  -230,
     127,  -230,    -6,  -230,  -230,   390,   371,   127,  -230,   196,
    -230,  -230,  1282,  1332,   403,   198,   334,   271,  -230,  1332,
    -230,  -230,   428,  -230,  -230
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     6,   273,     0,     0,     0,     0,     0,     0,    18,
     112,     0,     0,     7,     0,     0,    15,     8,    10,    11,
      13,    14,     9,    17,    12,    16,     0,   105,     0,   271,
       0,   265,   266,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,   107,   108,     0,   145,     1,     3,     2,
       0,   106,     5,     4,   272,     0,     0,     0,     0,   174,
      25,     0,   231,   228,     0,   257,   115,    40,    29,     0,
       0,    30,    31,    34,    36,     0,    37,    39,     0,    41,
     227,    35,    38,     0,    32,    33,     0,     0,     0,     0,
       0,   116,   117,   207,   121,   195,   197,   199,   202,   203,
     204,   205,   201,   200,     0,   243,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,   101,   175,     0,
       0,    91,   229,   230,     0,     0,   223,   220,     0,    43,
       0,   232,     0,     0,    44,     0,     0,   234,     0,   174,
       0,   258,   259,     0,     0,   120,   261,   262,   260,     0,
       0,   198,     0,     0,   174,   103,     0,   109,     0,   110,
       0,   263,     0,     0,     0,     0,     0,     0,    93,    66,
      27,     0,     0,     0,     0,     0,   176,   178,   180,   182,
       0,   200,     0,     0,     0,     0,   223,   217,     0,   221,
       0,     0,   237,   238,   239,   236,   240,   235,     0,   233,
       0,     0,   123,   206,     0,     0,   147,   136,   122,   141,
     124,   149,   118,   119,   194,   196,   244,     0,     0,   208,
     225,     0,     0,   100,     0,   146,     0,    92,    19,     0,
       0,     0,     0,    20,    21,    22,     0,     0,     0,    64,
       0,    42,    56,   181,   189,     0,     0,     0,     0,     0,
     247,   249,   250,   251,   252,   248,   253,   255,     0,     0,
       0,     0,   241,     0,     0,     0,     0,   218,     0,   224,
     216,    45,     0,     0,    46,   127,     0,   137,   143,   133,
     128,   129,   131,     0,     0,   140,     0,     0,   139,     0,
     151,   209,     0,   210,     0,   102,   104,   264,     0,     0,
       0,     0,     0,     0,     0,   245,     0,   243,     0,    63,
      65,    68,    28,     0,     0,     0,    47,     0,     0,    49,
      55,    57,    26,   188,   177,   179,   254,   256,     0,     0,
       0,     0,   190,   187,     0,   186,    90,     0,     0,   222,
       0,   215,     0,     0,   142,   144,   134,   130,   132,     0,
     148,     0,     0,   138,     0,     0,   153,   211,   226,     0,
       0,     0,     0,    96,   269,   270,   268,   267,    97,    95,
       0,    67,     0,    83,    84,    85,    86,    87,     0,     0,
      70,    48,     0,    51,    50,     0,    54,     0,     0,   192,
       0,     0,   185,   242,     0,   219,   212,     0,   213,     0,
     125,   126,   150,   152,     0,   155,    61,     0,     0,    58,
       0,     0,   246,     0,    24,    62,     0,     0,    23,     0,
       0,     0,     0,   183,   191,     0,     0,     0,     0,     0,
     157,     0,    59,    98,    99,     0,    74,    76,    77,    78,
       0,     0,     0,    52,     0,   184,   193,    89,   214,   135,
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
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -140,  -230,
     272,   122,  -230,  -230,  -229,  -230,  -230,  -230,  -230,  -230,
    -230,     4,   -13,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,   225,  -230,  -230,  -230,   341,
       1,  -230,  -230,  -230,   302,  -230,   -90,  -230,  -230,  -162,
     100,  -153,    -8,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,   -19,  -230,  -230,   -80,  -230,
    -121,   209,   213,   292,   -28,   318,   314,   350,  -132,  -230,
    -230,  -230,  -230,   285,  -230,   342,   287,  -216,  -171,   326,
      78,  -107,  -230,  -230,  -230,  -230,  -230,  -115,    -4,    66,
    -230,  -230
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,   170,   171,
      89,   320,   321,   322,   233,   310,   311,   238,   380,   418,
     467,   435,   436,   437,   438,   439,   377,   414,    21,    22,
     168,   304,    23,    24,   154,   155,    25,    26,    43,    44,
     135,    41,    90,    91,    92,   139,    93,   288,   283,   206,
     207,   277,   278,   208,   290,   356,   405,   430,   455,   456,
     475,   486,   494,   500,   450,   451,   472,   483,   117,   118,
     176,   177,   178,   179,   180,    95,    96,    97,    98,    99,
     100,   101,   186,   187,   126,   127,   190,   221,   102,   198,
     263,   103,   306,   260,   104,   144,   149,   160,   105,   368,
      28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    27,   292,   184,    45,   183,   209,    42,    46,   181,
     309,   262,    31,    94,    32,   460,   286,   181,   159,    31,
      31,    32,    32,   228,   152,   247,    55,    51,   247,   247,
      57,    58,    59,    60,    61,   334,   247,    34,   461,   141,
     142,   125,   275,   141,   142,   141,   142,    50,   205,   364,
     146,   147,   141,   142,   245,   188,   285,   111,    30,   211,
     136,   490,   121,   465,   141,   142,   181,    39,   181,   326,
     327,   328,   209,    35,   223,   397,    10,   365,   366,    37,
     491,    31,   116,    32,   244,   313,   141,   142,   112,   302,
     145,    47,   466,   222,    40,   273,   303,   287,   470,    45,
     312,   367,   156,    46,   200,   161,   162,    36,   188,   276,
     169,   172,    94,   153,   205,   391,   161,   335,    38,   314,
     124,   471,   350,   373,    10,   220,   374,   375,   315,   329,
     305,    31,   153,    32,   210,   353,   265,    54,   402,   213,
     181,   181,   398,   462,   383,   229,   340,   246,   216,   415,
     204,   204,   209,   323,   203,    56,   406,   266,   396,   172,
     269,   234,   235,   227,   443,   148,   393,   316,   185,   332,
     390,   230,   422,   185,   192,   421,   317,   359,   279,   106,
     318,    52,   141,   142,    53,   280,   362,   141,   142,    10,
     220,   181,   107,   281,   205,   319,   296,   109,   376,   193,
     210,    46,   231,   119,   279,    46,   108,    31,   110,    32,
     113,   280,   282,   194,   195,   120,  -127,   209,   156,   281,
     410,   232,   297,   262,   141,   142,    48,   411,    49,   115,
     330,   196,   333,   307,   403,   143,   172,   339,   282,   389,
     163,   164,   344,   114,   342,   407,   408,   116,   181,   165,
     166,   122,   197,   225,   226,   239,   240,   123,     1,   205,
       2,   419,   264,   226,   128,   412,   358,   129,   345,   141,
     142,   130,    46,   293,   294,   181,   497,   336,   337,   131,
     210,   357,   294,   473,    46,   369,   370,   132,     3,   371,
     372,   409,   226,   424,   294,   431,   226,   161,   432,   226,
     387,   134,   133,   220,     4,     5,   449,   446,   294,   447,
     337,     6,   395,   137,   385,   140,     7,   458,   459,   158,
     181,   167,   498,   479,   459,   138,   220,   182,   503,   488,
     226,   191,   496,   226,   501,   226,   201,     8,   202,   224,
      10,   236,   237,   247,   270,   210,   248,   478,   271,   272,
     261,   274,   289,   284,   291,   298,   161,   161,   299,     9,
     220,   300,   423,   301,   308,   489,    10,   484,   307,   331,
     338,   341,   495,   343,   346,   349,   351,   347,    11,   348,
     352,   354,   355,   363,    12,   152,   360,   361,    13,   379,
     378,   381,   392,   445,   382,   388,   384,   400,   394,   404,
     452,   401,   413,   417,   416,   420,   426,   427,   294,   440,
     429,   428,   433,   442,   454,   453,   444,   448,   457,   441,
     474,    31,    62,    32,    63,   468,   482,   469,   480,   485,
     487,   492,   499,   502,   493,   504,   463,   440,    64,    65,
     217,   452,   212,   386,   242,   464,   477,   295,   157,   399,
     481,    67,    68,   476,   151,   440,   324,   199,   161,    69,
      70,   325,   214,   215,   220,   243,    71,    72,   189,    73,
     307,   267,   425,   268,   218,    74,   161,   434,     0,     0,
       0,     0,    75,   161,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
       0,     0,     0,     0,     0,     0,    79,     0,     0,    80,
       0,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    81,   141,   142,     0,    31,    62,    32,    63,    82,
      83,   173,     0,    84,    85,     0,     0,     0,     0,     0,
       0,    86,    64,    65,     0,     0,     0,    87,     0,     0,
       0,     0,    88,   219,     0,    67,    68,     0,     0,     0,
       0,     0,     0,    69,    70,     0,     0,     0,     0,     0,
      71,    72,     0,    73,     0,     0,     0,     0,   259,    74,
       0,     0,     0,     0,     0,   174,    75,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,     0,     0,     0,     0,     0,     0,
      79,     0,     0,    80,     0,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    81,   141,   142,     0,     0,
      10,     0,     0,    82,    83,     0,     0,    84,    85,     0,
      31,    62,    32,    63,     0,    86,   173,     0,     0,     0,
       0,    87,     0,     0,     0,     0,   175,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,     0,     0,     0,     0,     0,     0,    69,    70,
       0,     0,   259,     0,     0,    71,    72,     0,    73,     0,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
     174,    75,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,     0,
       0,     0,     0,     0,     0,    79,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,   203,     0,     0,    31,    62,    32,    63,    82,    83,
       0,     0,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    64,    65,    66,     0,     0,    87,     0,     0,     0,
       0,   175,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,    69,    70,     0,     0,     0,     0,     0,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,    75,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,     0,     0,     0,     0,     0,     0,    79,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,    31,    62,
      32,    63,    82,    83,     0,     0,    84,    85,     0,     0,
       0,     0,     0,     0,    86,    64,    65,     0,     0,     0,
      87,     0,     0,     0,     0,    88,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,    69,    70,     0,     0,
       0,     0,     0,    71,    72,     0,    73,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,    75,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,     0,     0,     0,
       0,     0,     0,    79,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    82,    83,     0,     0,
      84,    85,     0,    31,    62,    32,    63,     0,    86,   124,
       0,     0,     0,     0,    87,     0,     0,     0,     0,    88,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,     0,     0,     0,     0,     0,
       0,    69,    70,     0,     0,     0,     0,     0,    71,    72,
       0,    73,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,    75,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,     0,     0,     0,     0,     0,     0,    79,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,    10,     0,
       0,    82,    83,     0,     0,    84,    85,     0,    31,    62,
      32,    63,     0,    86,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,    88,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,    69,    70,     0,     0,
       0,     0,     0,    71,    72,     0,    73,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,   174,    75,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,     0,     0,     0,
       0,     0,     0,    79,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,     0,    31,    62,    32,    63,    82,    83,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,    86,    64,
     150,     0,     0,     0,    87,     0,     0,     0,     0,   175,
       0,     0,    67,    68,     0,     0,     0,     0,     0,     0,
      69,    70,     0,     0,     0,     0,     0,    71,    72,     0,
      73,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,    75,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,     0,     0,     0,     0,     0,     0,    79,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,    31,    62,    32,    63,
      82,    83,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,    86,    64,    65,     0,     0,     0,    87,     0,
       0,     0,     0,    88,     0,     0,    67,    68,     0,     0,
       0,     0,     0,     0,    69,    70,     0,     0,     0,     0,
       0,    71,    72,     0,    73,     0,     0,    62,     0,    63,
      74,     0,     0,     0,     0,     0,     0,    75,     0,     0,
      76,     0,     0,    64,   150,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,     0,    67,    68,     0,     0,
       0,    79,     0,     0,    80,    70,     0,     0,     0,     0,
       0,    71,    72,     0,    73,     0,    81,     0,     0,     0,
      74,     0,     0,     0,    82,    83,     0,     0,    84,    85,
      76,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,    87,    77,    78,     0,     0,    88,     0,    67,
      68,    79,     0,     0,    80,     0,     0,     0,    70,     0,
       0,     0,     0,     0,    71,    72,    81,    73,     0,     0,
       0,     0,     0,    74,    82,     0,     0,     0,    84,    85,
       0,     0,     0,    76,     0,     0,    86,     0,     0,     0,
       0,     0,    87,     0,     0,     0,    77,   241,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,    87
};

static const yytype_int16 yycheck[] =
{
       4,     0,   218,   124,    12,   120,   138,    11,    12,   116,
     239,   182,     4,    41,     6,     7,    38,   124,   108,     4,
       4,     6,     6,   163,    27,     8,    30,    26,     8,     8,
      34,    35,    36,    37,    38,    10,     8,    78,    30,    21,
      22,    69,   204,    21,    22,    21,    22,    80,   138,    66,
      23,    24,    21,    22,   175,    60,   209,    28,   114,   139,
      88,    67,    61,    74,    21,    22,   173,    30,   175,    17,
      18,    19,   204,   114,   154,    69,   109,    94,    95,   114,
      86,     4,   126,     6,   174,    10,    21,    22,    59,    55,
      94,     0,   103,   137,    57,    71,    62,   119,    33,   107,
     240,   118,   106,   107,   132,   109,   110,    71,    60,    32,
     114,   115,   140,   135,   204,   331,   120,    92,    83,    44,
     125,    56,   284,    36,   109,   153,    39,    40,    53,    77,
     237,     4,   135,     6,   138,   288,   115,     3,   354,   143,
     247,   248,   136,   135,   315,    44,   115,   175,   152,   378,
     135,   135,   284,   136,   136,    71,   136,   185,   136,   163,
     188,   165,   166,   162,   136,   138,   337,    92,   125,   259,
       9,    70,   388,   125,    51,     9,   101,   298,    72,   110,
     105,   131,    21,    22,   134,    79,   301,    21,    22,   109,
     218,   298,   137,    87,   284,   120,   224,   135,   111,    76,
     204,   205,   101,   123,    72,   209,    32,     4,    83,     6,
       5,    79,   106,    90,    91,   135,    84,   349,   222,    87,
      55,   120,   226,   394,    21,    22,   131,    62,   133,   135,
     258,   108,   260,   237,   355,    32,   240,   265,   106,   329,
      45,    46,   136,    95,   272,   360,   361,   126,   355,    45,
      46,     7,   129,   136,   137,   136,   137,     7,     1,   349,
       3,   382,   136,   137,   135,   372,   294,    82,   276,    21,
      22,   135,   276,   136,   137,   382,   492,   136,   137,     5,
     284,   136,   137,   454,   288,   136,   137,   135,    31,   136,
     137,   136,   137,   136,   137,   136,   137,   301,   136,   137,
     328,    82,   135,   331,    47,    48,   427,   136,   137,   136,
     137,    54,   340,     5,   318,   137,    59,   136,   137,   135,
     427,   127,   493,   136,   137,    71,   354,   135,   499,   136,
     137,     7,   136,   137,   136,   137,     7,    80,   136,    11,
     109,   135,   135,     8,    61,   349,     9,   462,   136,    71,
      20,   136,    73,   137,   136,   135,   360,   361,    85,   102,
     388,    85,   390,   135,   122,   480,   109,   474,   372,   135,
     123,    61,   487,     7,    97,    84,     7,    97,   121,    97,
       7,    41,    75,     5,   127,    27,   135,   135,   131,   127,
     137,    92,    92,   421,   135,   135,    85,   100,   135,    96,
     428,   100,   135,    98,    37,   135,     7,    95,   137,   413,
      88,    41,     5,    41,   128,     7,   420,   136,   105,   135,
      95,     4,     5,     6,     7,   136,    93,   137,   135,    98,
     135,    41,    29,    99,    63,     7,   440,   441,    21,    22,
      23,   469,   140,   321,   172,   441,   459,   222,   107,   349,
     469,    34,    35,   457,   104,   459,   247,   131,   462,    42,
      43,   248,   144,   149,   492,   173,    49,    50,   126,    52,
     474,   186,   394,   186,    57,    58,   480,   411,    -1,    -1,
      -1,    -1,    65,   487,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   104,    21,    22,    -1,     4,     5,     6,     7,   112,
     113,    10,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    21,    22,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,   135,   136,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    52,    -1,    -1,    -1,    -1,    77,    58,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   104,    21,    22,    -1,    -1,
     109,    -1,    -1,   112,   113,    -1,    -1,   116,   117,    -1,
       4,     5,     6,     7,    -1,   124,    10,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,   135,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    77,    -1,    -1,    49,    50,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   136,    -1,    -1,     4,     5,     6,     7,   112,   113,
      -1,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
     124,    21,    22,    23,    -1,    -1,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,     4,     5,
       6,     7,   112,   113,    -1,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    21,    22,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
     116,   117,    -1,     4,     5,     6,     7,    -1,   124,   125,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,    -1,
      -1,   112,   113,    -1,    -1,   116,   117,    -1,     4,     5,
       6,     7,    -1,   124,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,   135,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,     4,     5,     6,     7,   112,   113,    -1,    -1,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,    21,
      22,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,     4,     5,     6,     7,
     112,   113,    -1,    -1,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    21,    22,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    -1,     5,    -1,     7,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    34,    35,    -1,    -1,
      -1,    89,    -1,    -1,    92,    43,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,   104,    -1,    -1,    -1,
      58,    -1,    -1,    -1,   112,   113,    -1,    -1,   116,   117,
      68,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,   130,    81,    82,    -1,    -1,   135,    -1,    34,
      35,    89,    -1,    -1,    92,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,   104,    52,    -1,    -1,
      -1,    -1,    -1,    58,   112,    -1,    -1,    -1,   116,   117,
      -1,    -1,    -1,    68,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,   130
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    31,    47,    48,    54,    59,    80,   102,
     109,   121,   127,   131,   140,   141,   142,   143,   144,   145,
     146,   167,   168,   171,   172,   175,   176,   179,   239,   240,
     114,     4,     6,   237,    78,   114,    71,   114,    83,    30,
      57,   180,   237,   177,   178,   191,   237,     0,   131,   133,
      80,   179,   131,   134,     3,   237,    71,   237,   237,   237,
     237,   237,     5,     7,    21,    22,    23,    34,    35,    42,
      43,    49,    50,    52,    58,    65,    68,    81,    82,    89,
      92,   104,   112,   113,   116,   117,   124,   130,   135,   149,
     181,   182,   183,   185,   213,   214,   215,   216,   217,   218,
     219,   220,   227,   230,   233,   237,   110,   137,    32,   135,
      83,    28,    59,     5,    95,   135,   126,   207,   208,   123,
     135,   179,     7,     7,   125,   213,   223,   224,   135,    82,
     135,     5,   135,   135,    82,   179,   213,     5,    71,   184,
     137,    21,    22,    32,   234,   237,    23,    24,   138,   235,
      22,   216,    27,   135,   173,   174,   237,   178,   135,   185,
     236,   237,   237,    45,    46,    45,    46,   127,   169,   237,
     147,   148,   237,    10,    64,   135,   209,   210,   211,   212,
     213,   230,   135,   236,   209,   125,   221,   222,    60,   224,
     225,     7,    51,    76,    90,    91,   108,   129,   228,   228,
     213,     7,   136,   136,   135,   185,   188,   189,   192,   217,
     237,   207,   183,   237,   214,   215,   237,    23,    57,   136,
     213,   226,   137,   207,    11,   136,   137,   179,   147,    44,
      70,   101,   120,   153,   237,   237,   135,   135,   156,   136,
     137,    82,   149,   212,   185,   209,   213,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    77,
     232,    20,   227,   229,   136,   115,   213,   222,   225,   213,
      61,   136,    71,    71,   136,   188,    32,   190,   191,    72,
      79,    87,   106,   187,   137,   190,    38,   119,   186,    73,
     193,   136,   226,   136,   137,   174,   213,   237,   135,    85,
      85,   135,    55,    62,   170,   230,   231,   237,   122,   153,
     154,   155,   147,    10,    44,    53,    92,   101,   105,   120,
     150,   151,   152,   136,   210,   211,    17,    18,    19,    77,
     213,   135,   185,   213,    10,    92,   136,   137,   123,   213,
     115,    61,   213,     7,   136,   191,    97,    97,    97,    84,
     188,     7,     7,   190,    41,    75,   194,   136,   213,   209,
     135,   135,   236,     5,    66,    94,    95,   118,   238,   136,
     137,   136,   137,    36,    39,    40,   111,   165,   137,   127,
     157,    92,   135,   227,    85,   237,   150,   213,   135,   185,
       9,   226,    92,   227,   135,   213,   136,    69,   136,   189,
     100,   100,   226,   209,    96,   195,   136,   236,   236,   136,
      55,    62,   230,   135,   166,   153,    37,    98,   158,   209,
     135,     9,   226,   213,   136,   229,     7,    95,    41,    88,
     196,   136,   136,     5,   238,   160,   161,   162,   163,   164,
     237,   135,    41,   136,   237,   213,   136,   136,   136,   209,
     203,   204,   213,     7,   128,   197,   198,   105,   136,   137,
       7,    30,   135,   237,   160,    74,   103,   159,   136,   137,
      33,    56,   205,   227,    95,   199,   237,   161,   236,   136,
     135,   204,    93,   206,   230,    98,   200,   135,   136,   236,
      67,    86,    41,    63,   201,   236,   136,   226,   227,    29,
     202,   136,    99,   227,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   139,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   142,   143,
     143,   143,   143,   144,   145,   146,   147,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   152,   153,   153,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     158,   158,   159,   159,   160,   160,   161,   161,   161,   162,
     162,   163,   164,   165,   165,   165,   165,   166,   166,   167,
     167,   167,   167,   168,   169,   169,   170,   170,   170,   170,
     171,   172,   173,   173,   174,   175,   175,   176,   177,   177,
     178,   179,   180,   180,   180,   181,   181,   182,   182,   183,
     183,   183,   184,   185,   186,   186,   186,   187,   187,   187,
     187,   187,   187,   187,   187,   188,   188,   189,   189,   189,
     189,   189,   189,   190,   190,   191,   191,   192,   192,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     199,   200,   200,   201,   202,   203,   203,   204,   205,   205,
     205,   206,   206,   206,   207,   207,   208,   209,   209,   210,
     210,   211,   211,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   213,   213,   214,   214,   215,   215,
     216,   216,   216,   216,   216,   216,   216,   216,   217,   217,
     217,   217,   218,   219,   219,   220,   220,   221,   221,   222,
     223,   223,   224,   225,   225,   226,   226,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   228,   228,   228,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   233,   234,   234,
     235,   235,   235,   236,   236,   237,   237,   238,   238,   238,
     238,   239,   240,   240
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
       1,     1,     1,     1,     1,     1,     3,     1,     3,     4,
       4,     5,     6,     6,     8,     5,     4,     1,     2,     4,
       1,     2,     4,     0,     2,     1,     3,     1,     1,     2,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     0
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
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1983 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOKEN_NAME  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1993 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOKEN_STRING_SINGLE_QUOTED  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2003 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOKEN_STRING_DOUBLE_QUOTED  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2013 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOKEN_UNSIGNED_NUMVAL  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 2023 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 141: /* sql_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 2033 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 142: /* quit_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).quit_statement_) != nullptr) {
    delete ((*yyvaluep).quit_statement_);
  }
}
#line 2043 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 143: /* alter_table_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 2053 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 144: /* create_table_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).create_table_statement_) != nullptr) {
    delete ((*yyvaluep).create_table_statement_);
  }
}
#line 2063 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 145: /* create_index_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 2073 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 146: /* drop_table_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).drop_table_statement_) != nullptr) {
    delete ((*yyvaluep).drop_table_statement_);
  }
}
#line 2083 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 147: /* column_def  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_);
  }
}
#line 2093 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 148: /* column_def_commalist  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_list_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_list_);
  }
}
#line 2103 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 149: /* data_type  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).data_type_) != nullptr) {
    delete ((*yyvaluep).data_type_);
  }
}
#line 2113 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 150: /* column_constraint_def  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_) != nullptr) {
    delete ((*yyvaluep).column_constraint_);
  }
}
#line 2123 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 151: /* column_constraint_def_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2133 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 152: /* opt_column_constraint_def_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2143 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 156: /* opt_column_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2153 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 157: /* opt_block_properties  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).block_properties_) != nullptr) {
    delete ((*yyvaluep).block_properties_);
  }
}
#line 2163 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 158: /* opt_partition_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).partition_clause_) != nullptr) {
    delete ((*yyvaluep).partition_clause_);
  }
}
#line 2173 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 159: /* partition_type  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2183 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 160: /* key_value_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2193 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 161: /* key_value  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_) != nullptr) {
    delete ((*yyvaluep).key_value_);
  }
}
#line 2203 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 162: /* key_string_value  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_value_) != nullptr) {
    delete ((*yyvaluep).key_string_value_);
  }
}
#line 2213 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 163: /* key_string_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_list_) != nullptr) {
    delete ((*yyvaluep).key_string_list_);
  }
}
#line 2223 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 164: /* key_integer_value  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_integer_value_) != nullptr) {
    delete ((*yyvaluep).key_integer_value_);
  }
}
#line 2233 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 165: /* index_type  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2243 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 166: /* opt_index_properties  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2253 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 167: /* insert_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).insert_statement_) != nullptr) {
    delete ((*yyvaluep).insert_statement_);
  }
}
#line 2263 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 168: /* copy_from_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_statement_) != nullptr) {
    delete ((*yyvaluep).copy_from_statement_);
  }
}
#line 2273 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 169: /* opt_copy_from_params  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2283 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 170: /* copy_from_params  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2293 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 171: /* update_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).update_statement_) != nullptr) {
    delete ((*yyvaluep).update_statement_);
  }
}
#line 2303 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 172: /* delete_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).delete_statement_) != nullptr) {
    delete ((*yyvaluep).delete_statement_);
  }
}
#line 2313 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 173: /* assignment_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_list_) != nullptr) {
    delete ((*yyvaluep).assignment_list_);
  }
}
#line 2323 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 174: /* assignment_item  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_) != nullptr) {
    delete ((*yyvaluep).assignment_);
  }
}
#line 2333 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 175: /* select_statement  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_statement_) != nullptr) {
    delete ((*yyvaluep).select_statement_);
  }
}
#line 2343 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 176: /* with_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2353 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 177: /* with_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2363 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 178: /* with_list_element  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_element_) != nullptr) {
    delete ((*yyvaluep).with_list_element_);
  }
}
#line 2373 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 179: /* select_query  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_query_) != nullptr) {
    delete ((*yyvaluep).select_query_);
  }
}
#line 2383 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 181: /* selection  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_) != nullptr) {
    delete ((*yyvaluep).selection_);
  }
}
#line 2393 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 182: /* selection_item_commalist  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_list_) != nullptr) {
    delete ((*yyvaluep).selection_list_);
  }
}
#line 2403 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 183: /* selection_item  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_item_) != nullptr) {
    delete ((*yyvaluep).selection_item_);
  }
}
#line 2413 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 184: /* from_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2423 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 185: /* subquery_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).subquery_expression_) != nullptr) {
    delete ((*yyvaluep).subquery_expression_);
  }
}
#line 2433 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 186: /* opt_sample_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_sample_clause_) != nullptr) {
    delete ((*yyvaluep).opt_sample_clause_);
  }
}
#line 2443 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 187: /* join_type  */
#line 595 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2449 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 188: /* joined_table_reference  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2459 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 189: /* table_reference  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2469 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 190: /* table_reference_signature  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2479 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 191: /* table_reference_signature_primary  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2489 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 192: /* joined_table_reference_commalist  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2499 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 193: /* opt_group_by_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_group_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_group_by_clause_);
  }
}
#line 2509 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 194: /* opt_having_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_having_clause_) != nullptr) {
    delete ((*yyvaluep).opt_having_clause_);
  }
}
#line 2519 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 195: /* opt_order_by_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_order_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_order_by_clause_);
  }
}
#line 2529 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 196: /* opt_limit_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_limit_clause_) != nullptr) {
    delete ((*yyvaluep).opt_limit_clause_);
  }
}
#line 2539 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 197: /* opt_window_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_window_clause_) != nullptr) {
    delete ((*yyvaluep).opt_window_clause_);
  }
}
#line 2549 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 198: /* window_duration  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2559 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 199: /* window_attribute  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2569 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 200: /* opt_window_partition  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_partition_by_list_) != nullptr) {
    delete ((*yyvaluep).window_partition_by_list_);
  }
}
#line 2579 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 201: /* emit_duration  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2589 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 202: /* age_duration  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2599 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 203: /* order_commalist  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_commalist_) != nullptr) {
    delete ((*yyvaluep).order_commalist_);
  }
}
#line 2609 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 204: /* order_item  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_item_) != nullptr) {
    delete ((*yyvaluep).order_item_);
  }
}
#line 2619 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 205: /* opt_order_direction  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2629 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 206: /* opt_nulls_first  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2639 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 207: /* opt_where_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2649 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 208: /* where_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2659 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 209: /* or_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2669 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 210: /* and_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2679 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 211: /* not_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2689 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 212: /* predicate_expression_base  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2699 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 213: /* add_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2709 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 214: /* multiply_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2719 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 215: /* unary_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2729 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 216: /* expression_base  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2739 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 217: /* function_call  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).function_call_) != nullptr) {
    delete ((*yyvaluep).function_call_);
  }
}
#line 2749 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 218: /* extract_function  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2759 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 219: /* substr_function  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2769 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 220: /* case_expression  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2779 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 221: /* simple_when_clause_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_list_);
  }
}
#line 2789 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 222: /* simple_when_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_);
  }
}
#line 2799 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 223: /* searched_when_clause_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_list_);
  }
}
#line 2809 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 224: /* searched_when_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_);
  }
}
#line 2819 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 225: /* opt_else_clause  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2829 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 226: /* expression_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_list_) != nullptr) {
    delete ((*yyvaluep).expression_list_);
  }
}
#line 2839 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 227: /* literal_value  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2849 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 228: /* datetime_unit  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2859 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 229: /* literal_value_commalist  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_list_) != nullptr) {
    delete ((*yyvaluep).literal_value_list_);
  }
}
#line 2869 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 230: /* attribute_ref  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2879 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 231: /* attribute_ref_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2889 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 232: /* comparison_operation  */
#line 592 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2895 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 233: /* unary_operation  */
#line 593 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2901 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 234: /* add_operation  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2907 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 235: /* multiply_operation  */
#line 594 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2913 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 236: /* name_commalist  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 2923 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 237: /* any_name  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2933 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 238: /* boolean_value  */
#line 591 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2939 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 239: /* command  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_) != nullptr) {
    delete ((*yyvaluep).command_);
  }
}
#line 2949 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 240: /* command_argument_list  */
#line 597 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_argument_list_) != nullptr) {
    delete ((*yyvaluep).command_argument_list_);
  }
}
#line 2959 "SqlParser_gen.cpp" /* yacc.c:1257  */
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
#line 606 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3256 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 610 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3265 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 614 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3274 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 618 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3283 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 622 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    YYABORT;
  }
#line 3291 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 625 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Regular yyparse() return codes are non-negative, so use a negative one here.
    return -1;
  }
#line 3300 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 632 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3308 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 635 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].copy_from_statement_);
  }
#line 3316 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 638 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].create_table_statement_);
  }
#line 3324 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 641 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3332 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 644 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].delete_statement_);
  }
#line 3340 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 647 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].drop_table_statement_);
  }
#line 3348 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 650 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].insert_statement_);
  }
#line 3356 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 653 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].quit_statement_);
  }
#line 3364 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 656 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].select_statement_);
  }
#line 3372 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 659 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].update_statement_);
  }
#line 3380 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 665 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.quit_statement_) = new quickstep::ParseStatementQuit((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3388 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 671 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].attribute_definition_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3400 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 678 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3411 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 684 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3423 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 691 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3435 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 700 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.create_table_statement_) = new quickstep::ParseStatementCreateTable((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].attribute_definition_list_), (yyvsp[-1].block_properties_), (yyvsp[0].partition_clause_));
  }
#line 3443 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 705 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].key_value_list_)) {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_), (yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].key_value_list_));
    } else {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_));
    }
  }
#line 3455 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 714 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.drop_table_statement_) = new quickstep::ParseStatementDropTable((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_));
  }
#line 3463 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 719 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_) = new quickstep::ParseAttributeDefinition((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].data_type_), (yyvsp[0].column_constraint_list_));
  }
#line 3471 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 724 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = new quickstep::PtrList<quickstep::ParseAttributeDefinition>();
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3480 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 728 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = (yyvsp[-2].attribute_definition_list_);
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3489 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 734 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "BIT data type");
    YYERROR;
  }
#line 3499 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 739 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3507 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 742 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3515 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 745 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "TIME data type");
    YYERROR;
  }
#line 3525 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 750 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3533 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 753 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3541 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 756 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3549 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 759 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3557 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 762 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kFloat));
  }
#line 3565 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 765 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3573 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 768 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3581 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 771 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3589 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 774 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3597 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 777 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3614 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 789 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetimeInterval));
  }
#line 3622 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 792 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kYearMonthInterval));
  }
#line 3630 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 795 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3653 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 813 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3676 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 833 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNull((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3684 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 836 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNotNull((yylsp[-1]).first_line, (yylsp[-1]).first_column);
  }
#line 3692 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 839 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "Column Constraints (UNIQUE)");
    YYERROR;
  }
#line 3702 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 844 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3712 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 849 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[0].literal_value_);
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (DEFAULT)");
    YYERROR;
  }
#line 3723 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 855 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Column Constraints (CHECK)");
    YYERROR;
  }
#line 3734 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 861 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_value_);
    NotSupported(&(yylsp[-4]), yyscanner, "Foreign Keys");
    YYERROR;
  }
#line 3746 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 870 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[-1].column_constraint_list_);
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3755 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 874 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = new quickstep::PtrList<quickstep::ParseColumnConstraint>();
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3764 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 880 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = nullptr;
  }
#line 3772 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 883 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[0].column_constraint_list_);
  }
#line 3780 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 888 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (UNIQUE)");
    YYERROR;
  }
#line 3790 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 893 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-4]), yyscanner, "Table Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3800 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 898 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-6].string_list_);
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-9]), yyscanner, "Table Constraints (FOREIGN KEY)");
    YYERROR;
  }
#line 3812 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 905 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (CHECK)");
    YYERROR;
  }
#line 3822 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 912 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[-2]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3831 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 916 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3840 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 922 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3848 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 925 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = $1; */
  }
#line 3856 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 930 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = nullptr;
  }
#line 3864 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 933 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = (yyvsp[-1].attribute_list_);
  }
#line 3872 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 938 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = nullptr;
  }
#line 3880 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 941 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = new quickstep::ParseBlockProperties((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].key_value_list_));
  }
#line 3888 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 946 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.partition_clause_) = nullptr;
  }
#line 3896 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 949 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3918 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 968 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionSchemeHeader::PartitionType::kHash));
  }
#line 3927 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 972 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionSchemeHeader::PartitionType::kRange));
  }
#line 3936 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 978 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = new quickstep::PtrList<quickstep::ParseKeyValue>();
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3945 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 982 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-2].key_value_list_);
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3954 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 988 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_value_);
  }
#line 3962 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 991 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_list_);
  }
#line 3970 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 994 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_integer_value_);
  }
#line 3978 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 999 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].string_value_));
  }
#line 3986 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1002 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // This is a special case to handle the COMPRESS ALL option of the BLOCK PROPERTIES.
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_),
        new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, "ALL"));
  }
#line 3996 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1009 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_list_) = new quickstep::ParseKeyStringList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4004 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1014 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.key_integer_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Value must be an integer");
      YYERROR;
    }
    (yyval.key_integer_value_) = new quickstep::ParseKeyIntegerValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].numeric_literal_value_));
  }
#line 4018 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1025 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Defaults to BitWeavingV, but IndexProperties can change this to H.
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBitWeavingV));
  }
#line 4028 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1030 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBloomFilter));
  }
#line 4037 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1034 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kCSBTree));
  }
#line 4046 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1038 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kSMA));
  }
#line 4055 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1044 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = nullptr;
  }
#line 4063 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1047 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-1].key_value_list_);
  }
#line 4071 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1053 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-7].string_value_);
    delete (yyvsp[-5].string_list_);
    delete (yyvsp[-1].literal_value_list_);
    (yyval.insert_statement_) = nullptr;
    NotSupported(&(yylsp[-6]), yyscanner, "list of column names in INSERT statement");
    YYERROR;
  }
#line 4084 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1061 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertTuple((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].string_value_), (yyvsp[-1].literal_value_list_));
  }
#line 4092 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1064 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-3]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), nullptr);
  }
#line 4100 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1067 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-4]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), (yyvsp[-4].with_list_));
  }
#line 4108 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1073 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_statement_) = new quickstep::ParseStatementCopyFrom((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_value_), (yyvsp[0].copy_from_params_));
  }
#line 4116 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1078 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = nullptr;
  }
#line 4124 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1081 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-1].copy_from_params_);
  }
#line 4132 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1086 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4141 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1090 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4150 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1094 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4159 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1098 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4168 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1104 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.update_statement_) = new quickstep::ParseStatementUpdate((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].assignment_list_), (yyvsp[0].predicate_));
  }
#line 4176 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1109 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.delete_statement_) = new quickstep::ParseStatementDelete((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].predicate_));
  }
#line 4184 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1114 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = (yyvsp[-2].assignment_list_);
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4193 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1118 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = new quickstep::PtrList<quickstep::ParseAssignment>();
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4202 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1124 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_) = new quickstep::ParseAssignment((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[0].expression_));
  }
#line 4210 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1130 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].select_query_), nullptr);
  }
#line 4218 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1133 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].select_query_), (yyvsp[-1].with_list_));
  }
#line 4226 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1138 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[0].with_list_);
  }
#line 4234 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1143 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = new quickstep::PtrVector<quickstep::ParseSubqueryTableReference>();
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4243 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1147 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[-2].with_list_);
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4252 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1153 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_element_) = new quickstep::ParseSubqueryTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].subquery_expression_));
    (yyval.with_list_element_)->set_table_reference_signature((yyvsp[-2].table_reference_signature_));
  }
#line 4261 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1160 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_query_) = new quickstep::ParseSelect((yylsp[-9]).first_line, (yylsp[-9]).first_column, (yyvsp[-7].selection_), (yyvsp[-6].table_reference_list_), (yyvsp[-5].predicate_), (yyvsp[-4].opt_group_by_clause_), (yyvsp[-3].opt_having_clause_), (yyvsp[-2].opt_order_by_clause_), (yyvsp[-1].opt_limit_clause_), (yyvsp[0].opt_window_clause_));
  }
#line 4269 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1165 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 4277 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1168 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "ALL in selection");
    YYERROR;
  }
#line 4286 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1172 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "DISTINCT in selection");
    YYERROR;
  }
#line 4295 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1178 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = new quickstep::ParseSelectionStar((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 4303 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1181 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = (yyvsp[0].selection_list_);
  }
#line 4311 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1186 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = new quickstep::ParseSelectionList((yylsp[0]).first_line, (yylsp[0]).first_column);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4320 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1190 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = (yyvsp[-2].selection_list_);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4329 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1196 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[0].string_value_));
  }
#line 4337 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1199 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].expression_), (yyvsp[0].string_value_));
  }
#line 4345 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1202 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].expression_));
  }
#line 4353 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1207 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[0].table_reference_list_);
  }
#line 4361 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1212 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.subquery_expression_) = new quickstep::ParseSubqueryExpression((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].select_query_));
  }
#line 4369 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1217 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = NULL;
  }
#line 4377 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1220 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, true, (yyvsp[-1].numeric_literal_value_));
  }
#line 4385 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1223 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].numeric_literal_value_));
  }
#line 4393 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1228 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4401 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1231 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4409 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1234 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4417 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1237 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4425 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1240 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4433 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1243 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4441 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1246 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4449 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1249 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4457 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1254 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseJoinedTableReference((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].join_type_), (yyvsp[-5].table_reference_), (yyvsp[-2].table_reference_), (yyvsp[0].predicate_));
  }
#line 4465 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1257 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = (yyvsp[0].table_reference_);
  }
#line 4473 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1262 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSubqueryTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].subquery_expression_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4482 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1266 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].opt_sample_clause_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4491 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1270 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].opt_sample_clause_));
  }
#line 4499 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1273 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].function_call_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4508 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1277 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].function_call_));
  }
#line 4516 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1280 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = (yyvsp[-1].table_reference_);
  }
#line 4524 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1285 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4532 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1288 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4540 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1293 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4548 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1296 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4556 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1301 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = new quickstep::PtrList<quickstep::ParseTableReference>();
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4565 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1305 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[-2].table_reference_list_);
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4574 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1311 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = nullptr;
  }
#line 4582 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1314 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = new quickstep::ParseGroupBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].expression_list_));
  }
#line 4590 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1319 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = nullptr;
  }
#line 4598 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1322 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = new quickstep::ParseHaving((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4606 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1327 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = nullptr;
  }
#line 4614 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1330 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = new quickstep::ParseOrderBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].order_commalist_));
  }
#line 4622 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1335 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_limit_clause_) = nullptr;
  }
#line 4630 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1338 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 4652 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1357 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = nullptr;
  }
#line 4660 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1360 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = new quickstep::ParseWindow((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].attribute_), (yyvsp[-2].window_partition_by_list_), (yyvsp[-4].literal_value_), (yyvsp[-1].literal_value_), (yyvsp[0].literal_value_));
  }
#line 4668 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1365 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4676 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1370 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = (yyvsp[0].attribute_);
  }
#line 4684 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1375 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = nullptr;
  }
#line 4692 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1378 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = (yyvsp[0].expression_list_);
  }
#line 4700 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1383 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4708 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1388 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4716 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1393 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = new quickstep::PtrList<quickstep::ParseOrderByItem>();
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4725 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1397 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = (yyvsp[-2].order_commalist_);
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4734 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1403 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_item_) = new quickstep::ParseOrderByItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[-1].order_direction_), (yyvsp[0].order_direction_));
    delete (yyvsp[-1].order_direction_);
    delete (yyvsp[0].order_direction_);
  }
#line 4744 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1410 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4752 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1413 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4760 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1416 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4768 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1421 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4776 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1424 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4784 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1427 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4792 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1433 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = nullptr;
  }
#line 4800 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1436 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4808 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1441 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4816 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1446 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kDisjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateDisjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4830 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1455 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4838 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1460 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kConjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateConjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4852 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1469 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4860 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1474 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4868 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1477 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4876 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1482 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4884 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1485 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line, (yylsp[-4]).first_column,
        new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_)));
  }
#line 4894 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1490 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4905 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1496 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4916 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1502 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateComparison((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].comparison_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4924 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1505 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[-1].predicate_);
  }
#line 4932 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1508 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateExists((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].subquery_expression_));
  }
#line 4940 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1511 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].expression_), (yyvsp[0].subquery_expression_));
  }
#line 4948 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1514 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-1].expression_list_));
  }
#line 4956 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1517 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-2]).first_line,
        (yylsp[-2]).first_column,
        new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-3].expression_), (yyvsp[0].subquery_expression_)));
  }
#line 4967 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1523 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line,
        (yylsp[-4]).first_column,
        new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-1].expression_list_)));
  }
#line 4978 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1532 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4986 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1535 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4994 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1540 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 5002 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1543 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5010 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1548 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseUnaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].unary_operation_), (yyvsp[0].expression_));
  }
#line 5018 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1551 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5026 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1556 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].attribute_);
  }
#line 5034 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1559 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_));
  }
#line 5042 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1562 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].function_call_);
  }
#line 5050 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1565 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5058 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1568 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5066 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1571 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5074 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1574 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[-1].expression_);
  }
#line 5082 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1577 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].subquery_expression_);
  }
#line 5090 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1582 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-2].string_value_), new quickstep::PtrList<quickstep::ParseExpression>());
  }
#line 5099 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1586 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), new quickstep::ParseStar((yylsp[-1]).first_line, (yylsp[-1]).first_column));
  }
#line 5108 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1590 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-3]).first_line, (yylsp[-3]).first_column, false, (yyvsp[-3].string_value_), (yyvsp[-1].expression_list_));
  }
#line 5116 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1593 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-4]).first_line, (yylsp[-4]).first_column, true, (yyvsp[-4].string_value_), (yyvsp[-1].expression_list_));
  }
#line 5124 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1598 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseExtractFunction((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].expression_));
  }
#line 5132 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1603 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSubstringFunction(
        (yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-3].expression_), (yyvsp[-1].numeric_literal_value_)->long_value());
  }
#line 5141 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1607 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSubstringFunction(
        (yylsp[-7]).first_line, (yylsp[-7]).first_column, (yyvsp[-5].expression_), (yyvsp[-3].numeric_literal_value_)->long_value(), (yyvsp[-1].numeric_literal_value_)->long_value());
  }
#line 5150 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1613 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSimpleCaseExpression((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].expression_), (yyvsp[-2].simple_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 5158 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1616 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseSearchedCaseExpression((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].searched_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 5166 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1621 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSimpleWhenClause>;
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5175 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1625 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_list_) = (yyvsp[-1].simple_when_clause_list_);
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5184 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1631 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.simple_when_clause_) = new quickstep::ParseSimpleWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 5192 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1636 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSearchedWhenClause>;
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5201 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1640 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_list_) = (yyvsp[-1].searched_when_clause_list_);
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5210 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1646 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.searched_when_clause_) = new quickstep::ParseSearchedWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].predicate_), (yyvsp[0].expression_));
  }
#line 5218 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1651 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = NULL;
  }
#line 5226 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1654 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5234 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1659 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = new quickstep::PtrList<quickstep::ParseExpression>();
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5243 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1663 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = (yyvsp[-2].expression_list_);
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5252 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1669 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::NullParseLiteralValue((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 5260 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1672 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5268 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1675 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5276 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1678 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 5293 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1690 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_),
                                                nullptr);  // No explicit type.
  }
#line 5302 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1694 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 5326 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1713 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 5344 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1726 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 5362 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1741 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("YEAR"));
  }
#line 5370 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1744 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("MONTH"));
  }
#line 5378 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1747 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("DAY"));
  }
#line 5386 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1750 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("HOUR"));
  }
#line 5394 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1753 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("MINUTE"));
  }
#line 5402 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1756 "../SqlParser.ypp" /* yacc.c:1646  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("SECOND"));
  }
#line 5410 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1761 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = new quickstep::PtrList<quickstep::ParseScalarLiteral>();
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5419 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1765 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = (yyvsp[-2].literal_value_list_);
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5428 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1771 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 5436 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1774 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_), (yyvsp[-2].string_value_));
  }
#line 5444 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1779 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = new quickstep::PtrList<quickstep::ParseAttribute>();
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5453 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1783 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_list_) = (yyvsp[-2].attribute_list_);
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5462 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1790 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kEqual);
  }
#line 5470 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1793 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotEqual);
  }
#line 5478 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1796 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLess);
  }
#line 5486 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1799 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLessOrEqual);
  }
#line 5494 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1802 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreater);
  }
#line 5502 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1805 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreaterOrEqual);
  }
#line 5510 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1808 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLike);
  }
#line 5518 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1811 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotLike);
  }
#line 5526 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1814 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kRegexMatch);
  }
#line 5534 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1817 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotRegexMatch);
  }
#line 5542 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1822 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * '-' TOKEN_UNSIGNED_NUMVAL case in 'literal_value'. Because Bison prefers
     * to shift rather than reduce, the case in 'literal_value' has precedence
     * over this one.
     **/
    (yyval.unary_operation_) = &quickstep::UnaryOperationFactory::GetUnaryOperation(quickstep::UnaryOperationID::kNegate);
  }
#line 5556 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1833 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kAdd);
  }
#line 5564 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1836 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kSubtract);
  }
#line 5572 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1841 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kModulo);
  }
#line 5580 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1844 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kMultiply);
  }
#line 5588 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1847 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kDivide);
  }
#line 5596 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1853 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = new quickstep::PtrList<quickstep::ParseString>();
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5605 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1857 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = (yyvsp[-2].string_list_);
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5614 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1863 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5622 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1866 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].string_value_)->value().empty()) {
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Zero-length identifier");
    }
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5633 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1874 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 5641 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1877 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 5649 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1880 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 5657 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1883 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 5665 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1889 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.command_) = new quickstep::ParseCommand((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].command_argument_list_));
  }
#line 5673 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1894 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::PtrVector<quickstep::ParseString> *argument_list = (yyvsp[-1].command_argument_list_);
    argument_list->push_back((yyvsp[0].string_value_));
    (yyval.command_argument_list_) = argument_list;
  }
#line 5683 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1899 "../SqlParser.ypp" /* yacc.c:1646  */
    { /* Epsilon, an empy match. */
    (yyval.command_argument_list_) = new quickstep::PtrVector<quickstep::ParseString>();
  }
#line 5691 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;


#line 5695 "SqlParser_gen.cpp" /* yacc.c:1646  */
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
#line 1903 "../SqlParser.ypp" /* yacc.c:1906  */


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
