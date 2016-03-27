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
#line 33 "../SqlParser.ypp" /* yacc.c:339  */


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

#line 62 "../SqlParser.ypp" /* yacc.c:339  */

#include <cstdlib>
#include <string>
#include <utility>

#include "catalog/PartitionScheme.hpp"
#include "parser/ParseAssignment.hpp"
#include "parser/ParseAttributeDefinition.hpp"
#include "parser/ParseBasicExpressions.hpp"
#include "parser/ParseBlockProperties.hpp"
#include "parser/ParseExpression.hpp"
#include "parser/ParseGeneratorTableReference.hpp"
#include "parser/ParseGroupBy.hpp"
#include "parser/ParseHaving.hpp"
#include "parser/ParseKeyValue.hpp"
#include "parser/ParseLimit.hpp"
#include "parser/ParseLiteralValue.hpp"
#include "parser/ParseOrderBy.hpp"
#include "parser/ParsePartitionClause.hpp"
#include "parser/ParsePredicate.hpp"
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

#line 150 "SqlParser_gen.cpp" /* yacc.c:339  */

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
    TOKEN_ALL = 279,
    TOKEN_ALTER = 280,
    TOKEN_AS = 281,
    TOKEN_ASC = 282,
    TOKEN_BIGINT = 283,
    TOKEN_BIT = 284,
    TOKEN_BLOCKPROPERTIES = 285,
    TOKEN_BLOCKSAMPLE = 286,
    TOKEN_BLOOM_FILTER = 287,
    TOKEN_CSB_TREE = 288,
    TOKEN_BY = 289,
    TOKEN_CHARACTER = 290,
    TOKEN_CHECK = 291,
    TOKEN_COLUMN = 292,
    TOKEN_CONSTRAINT = 293,
    TOKEN_COPY = 294,
    TOKEN_CREATE = 295,
    TOKEN_DATE = 296,
    TOKEN_DATETIME = 297,
    TOKEN_DECIMAL = 298,
    TOKEN_DEFAULT = 299,
    TOKEN_DELETE = 300,
    TOKEN_DELIMITER = 301,
    TOKEN_DESC = 302,
    TOKEN_DISTINCT = 303,
    TOKEN_DOUBLE = 304,
    TOKEN_DROP = 305,
    TOKEN_ESCAPE_STRINGS = 306,
    TOKEN_FALSE = 307,
    TOKEN_FIRST = 308,
    TOKEN_FLOAT = 309,
    TOKEN_FOREIGN = 310,
    TOKEN_FROM = 311,
    TOKEN_FULL = 312,
    TOKEN_GROUP = 313,
    TOKEN_HASH = 314,
    TOKEN_HAVING = 315,
    TOKEN_INDEX = 316,
    TOKEN_INNER = 317,
    TOKEN_INSERT = 318,
    TOKEN_INTEGER = 319,
    TOKEN_INTERVAL = 320,
    TOKEN_INTO = 321,
    TOKEN_JOIN = 322,
    TOKEN_KEY = 323,
    TOKEN_LAST = 324,
    TOKEN_LEFT = 325,
    TOKEN_LIMIT = 326,
    TOKEN_LONG = 327,
    TOKEN_NULL = 328,
    TOKEN_NULLS = 329,
    TOKEN_OFF = 330,
    TOKEN_ON = 331,
    TOKEN_ORDER = 332,
    TOKEN_OUTER = 333,
    TOKEN_PARTITION = 334,
    TOKEN_PARTITIONS = 335,
    TOKEN_PERCENT = 336,
    TOKEN_PRIMARY = 337,
    TOKEN_QUIT = 338,
    TOKEN_RANGE = 339,
    TOKEN_REAL = 340,
    TOKEN_REFERENCES = 341,
    TOKEN_RIGHT = 342,
    TOKEN_ROW_DELIMITER = 343,
    TOKEN_SELECT = 344,
    TOKEN_SET = 345,
    TOKEN_SMALLINT = 346,
    TOKEN_TABLE = 347,
    TOKEN_TIME = 348,
    TOKEN_TIMESTAMP = 349,
    TOKEN_TRUE = 350,
    TOKEN_TUPLESAMPLE = 351,
    TOKEN_UNIQUE = 352,
    TOKEN_UPDATE = 353,
    TOKEN_USING = 354,
    TOKEN_VALUES = 355,
    TOKEN_VARCHAR = 356,
    TOKEN_WHERE = 357,
    TOKEN_WITH = 358,
    TOKEN_YEARMONTH = 359,
    TOKEN_EOF = 360,
    TOKEN_LEX_ERROR = 361
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 112 "../SqlParser.ypp" /* yacc.c:355  */

  quickstep::ParseString *string_value_;

  quickstep::PtrList<quickstep::ParseString> *string_list_;

  bool boolean_value_;

  quickstep::NumericParseLiteralValue *numeric_literal_value_;
  quickstep::ParseLiteralValue *literal_value_;
  quickstep::PtrList<quickstep::ParseScalarLiteral> *literal_value_list_;

  quickstep::ParseExpression *expression_;

  quickstep::ParseScalarLiteral *scalar_literal_;
  quickstep::ParseAttribute *attribute_;

  quickstep::ParsePredicate *predicate_;

  quickstep::ParseSubqueryExpression *subquery_expression_;

  quickstep::ParseSelectionClause *selection_;
  quickstep::ParseSelectionItem *selection_item_;
  quickstep::ParseSelectionList *selection_list_;

  quickstep::ParseTableReference *table_reference_;
  quickstep::PtrList<quickstep::ParseTableReference> *table_reference_list_;
  quickstep::ParseTableReferenceSignature *table_reference_signature_;

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

  quickstep::ParseSelect *select_query_;
  quickstep::ParseGroupBy *opt_group_by_clause_;
  quickstep::ParseHaving *opt_having_clause_;
  quickstep::ParseOrderBy *opt_order_by_clause_;
  bool *order_direction_;
  quickstep::ParseLimit *opt_limit_clause_;
  
  quickstep::ParseSample *opt_sample_clause_;

  quickstep::PtrList<quickstep::ParseOrderByItem> *order_commalist_;
  quickstep::ParseOrderByItem *order_item_;

  quickstep::PtrVector<quickstep::ParseSubqueryTableReference> *with_list_;
  quickstep::ParseSubqueryTableReference *with_list_element_;

#line 380 "SqlParser_gen.cpp" /* yacc.c:355  */
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
#line 195 "../SqlParser.ypp" /* yacc.c:358  */

/* This header needs YYSTYPE, which is defined by the %union directive above */
#include "SqlLexer_gen.hpp"
void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature);

#line 413 "SqlParser_gen.cpp" /* yacc.c:358  */

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   865

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  439

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     113,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     114,   115,    23,    21,   116,    22,    27,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   112,
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
     110,   111
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   530,   530,   534,   538,   542,   546,   549,   556,   559,
     562,   565,   568,   571,   574,   577,   580,   583,   589,   595,
     602,   608,   615,   624,   629,   634,   639,   644,   648,   654,
     659,   662,   665,   670,   673,   676,   679,   682,   685,   688,
     691,   694,   697,   709,   712,   715,   733,   753,   756,   759,
     764,   769,   775,   781,   790,   794,   800,   803,   808,   813,
     818,   825,   832,   836,   842,   845,   850,   853,   861,   864,
     869,   872,   891,   895,   901,   905,   911,   914,   917,   922,
     925,   932,   937,   948,   952,   958,   961,   967,   975,   980,
     985,   988,   993,   997,  1001,  1005,  1011,  1016,  1021,  1025,
    1031,  1037,  1042,  1045,  1050,  1054,  1060,  1066,  1072,  1075,
    1079,  1085,  1088,  1093,  1097,  1103,  1106,  1109,  1114,  1119,
    1122,  1128,  1132,  1138,  1144,  1150,  1156,  1162,  1168,  1174,
    1180,  1188,  1193,  1196,  1199,  1204,  1208,  1212,  1215,  1219,
    1224,  1227,  1232,  1235,  1240,  1244,  1250,  1253,  1258,  1261,
    1266,  1269,  1274,  1277,  1296,  1300,  1306,  1313,  1316,  1319,
    1324,  1327,  1330,  1336,  1339,  1344,  1349,  1358,  1363,  1372,
    1377,  1380,  1385,  1388,  1393,  1399,  1405,  1408,  1414,  1417,
    1422,  1425,  1430,  1433,  1438,  1441,  1444,  1447,  1452,  1456,
    1460,  1465,  1469,  1475,  1478,  1481,  1484,  1496,  1500,  1519,
    1534,  1538,  1544,  1547,  1553,  1556,  1559,  1562,  1565,  1568,
    1571,  1574,  1577,  1580,  1585,  1596,  1599,  1604,  1607,  1613,
    1617,  1623,  1626,  1634,  1637,  1640,  1643,  1649,  1654,  1659
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
  "TOKEN_ADD", "TOKEN_ALL", "TOKEN_ALTER", "TOKEN_AS", "TOKEN_ASC",
  "TOKEN_BIGINT", "TOKEN_BIT", "TOKEN_BLOCKPROPERTIES",
  "TOKEN_BLOCKSAMPLE", "TOKEN_BLOOM_FILTER", "TOKEN_CSB_TREE", "TOKEN_BY",
  "TOKEN_CHARACTER", "TOKEN_CHECK", "TOKEN_COLUMN", "TOKEN_CONSTRAINT",
  "TOKEN_COPY", "TOKEN_CREATE", "TOKEN_DATE", "TOKEN_DATETIME",
  "TOKEN_DECIMAL", "TOKEN_DEFAULT", "TOKEN_DELETE", "TOKEN_DELIMITER",
  "TOKEN_DESC", "TOKEN_DISTINCT", "TOKEN_DOUBLE", "TOKEN_DROP",
  "TOKEN_ESCAPE_STRINGS", "TOKEN_FALSE", "TOKEN_FIRST", "TOKEN_FLOAT",
  "TOKEN_FOREIGN", "TOKEN_FROM", "TOKEN_FULL", "TOKEN_GROUP", "TOKEN_HASH",
  "TOKEN_HAVING", "TOKEN_INDEX", "TOKEN_INNER", "TOKEN_INSERT",
  "TOKEN_INTEGER", "TOKEN_INTERVAL", "TOKEN_INTO", "TOKEN_JOIN",
  "TOKEN_KEY", "TOKEN_LAST", "TOKEN_LEFT", "TOKEN_LIMIT", "TOKEN_LONG",
  "TOKEN_NULL", "TOKEN_NULLS", "TOKEN_OFF", "TOKEN_ON", "TOKEN_ORDER",
  "TOKEN_OUTER", "TOKEN_PARTITION", "TOKEN_PARTITIONS", "TOKEN_PERCENT",
  "TOKEN_PRIMARY", "TOKEN_QUIT", "TOKEN_RANGE", "TOKEN_REAL",
  "TOKEN_REFERENCES", "TOKEN_RIGHT", "TOKEN_ROW_DELIMITER", "TOKEN_SELECT",
  "TOKEN_SET", "TOKEN_SMALLINT", "TOKEN_TABLE", "TOKEN_TIME",
  "TOKEN_TIMESTAMP", "TOKEN_TRUE", "TOKEN_TUPLESAMPLE", "TOKEN_UNIQUE",
  "TOKEN_UPDATE", "TOKEN_USING", "TOKEN_VALUES", "TOKEN_VARCHAR",
  "TOKEN_WHERE", "TOKEN_WITH", "TOKEN_YEARMONTH", "TOKEN_EOF",
  "TOKEN_LEX_ERROR", "';'", "'\\n'", "'('", "')'", "','", "$accept",
  "start", "sql_statement", "quit_statement", "alter_table_statement",
  "create_table_statement", "create_index_statement",
  "drop_table_statement", "column_def", "column_def_commalist",
  "data_type", "column_constraint_def", "column_constraint_def_list",
  "opt_column_constraint_def_list", "table_constraint_def",
  "table_constraint_def_commalist", "opt_table_constraint_def_commalist",
  "opt_column_list", "opt_block_properties", "opt_partition_clause",
  "partition_type", "key_value_list", "key_value", "key_string_value",
  "key_string_list", "key_integer_value", "index_type",
  "opt_index_properties", "insert_statement", "copy_from_statement",
  "opt_copy_from_params", "copy_from_params", "update_statement",
  "delete_statement", "assignment_list", "assignment_item",
  "select_statement", "opt_with_clause", "with_list", "with_list_element",
  "select_query", "opt_all_distinct", "selection",
  "selection_item_commalist", "selection_item", "from_clause",
  "opt_join_chain", "join_chain", "join", "subquery_expression",
  "opt_sample_clause", "table_reference", "table_reference_signature",
  "table_reference_signature_primary", "table_reference_commalist",
  "opt_group_by_clause", "opt_having_clause", "opt_order_by_clause",
  "opt_limit_clause", "order_commalist", "order_item",
  "opt_order_direction", "opt_nulls_first", "opt_where_clause",
  "where_clause", "or_expression", "and_expression", "not_expression",
  "predicate_expression_base", "add_expression", "multiply_expression",
  "unary_expression", "expression_base", "function_call",
  "expression_list", "literal_value", "literal_value_commalist",
  "attribute_ref", "comparison_operation", "unary_operation",
  "add_operation", "multiply_operation", "name_commalist", "any_name",
  "boolean_value", "command", "command_argument_list", YY_NULLPTR
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
     360,   361,    59,    10,    40,    41,    44
};
# endif

#define YYPACT_NINF -182

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-182)))

#define YYTABLE_NINF -103

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      77,  -182,  -182,   -72,   205,   -47,   -19,   -42,     3,  -182,
     205,   205,  -182,   110,   109,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,    20,    80,   163,   205,  -182,
    -182,   121,   205,   205,   205,   205,   205,    39,    83,  -182,
     171,    91,  -182,  -182,  -182,    19,  -182,  -182,  -182,  -182,
      92,   207,   155,   104,   122,  -182,    46,   205,   205,   136,
     205,  -182,  -182,   395,   180,   184,   156,   205,   205,   506,
    -182,  -182,   142,   205,    52,  -182,   252,  -182,    20,  -182,
     115,  -182,  -182,  -182,   264,   266,  -182,  -182,  -182,   175,
    -182,   215,  -182,  -182,  -182,  -182,   288,  -182,  -182,  -182,
    -182,  -182,  -182,   181,   226,   552,   293,   246,   192,  -182,
     127,   209,  -182,  -182,  -182,  -182,  -182,   631,   -17,   205,
      96,   205,   205,   195,  -182,   196,  -182,   119,   710,   677,
     506,   303,   304,  -182,  -182,   826,   295,   756,   123,   205,
    -182,   552,   202,  -182,   205,  -182,  -182,   313,  -182,  -182,
     314,  -182,    15,  -182,    11,   122,   552,  -182,  -182,   205,
     552,  -182,  -182,  -182,   552,   266,  -182,   205,   391,  -182,
     208,   251,   253,   216,  -182,  -182,  -182,   145,   205,   225,
      96,   205,  -182,   126,  -182,    -3,    73,   506,   506,   197,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,   552,   552,
       4,  -182,   129,   227,  -182,   220,  -182,  -182,   218,   219,
    -182,    62,  -182,   -15,    62,    -1,   268,  -182,  -182,   209,
    -182,  -182,   222,  -182,   220,   131,   506,   224,   229,   205,
     331,   -41,   133,   137,   221,  -182,   223,   232,  -182,   263,
     230,   756,  -182,   272,   205,  -182,  -182,   126,  -182,  -182,
     304,  -182,  -182,  -182,   552,   148,   220,   270,  -182,  -182,
     756,   235,  -182,  -182,   205,  -182,  -182,    71,   274,   205,
      81,   101,    11,  -182,   114,  -182,  -182,   343,   345,    62,
     316,   292,  -182,  -182,   552,    13,   205,   205,   146,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,   152,  -182,  -182,  -182,
     245,    96,   326,   279,  -182,   506,  -182,  -182,   254,  -182,
     170,   552,  -182,  -182,   756,  -182,   205,   294,   205,   -58,
     205,   299,   205,   300,  -182,  -182,   281,   287,  -182,   552,
     506,   283,   220,  -182,   151,   162,  -182,   369,   -41,   205,
    -182,  -182,   261,   337,  -182,    14,   205,   552,   220,   165,
     -55,   205,   -54,   506,   -43,   205,   -37,   205,  -182,  -182,
     269,   303,   338,   306,   289,  -182,  -182,  -182,   176,  -182,
    -182,  -182,  -182,     5,   205,   -18,  -182,   271,   220,  -182,
     506,   -14,   506,   303,   506,    -5,   506,    28,   552,   372,
    -182,   205,  -182,   205,  -182,  -182,   205,  -182,   185,  -182,
    -182,   276,  -182,   303,   506,   303,   303,   506,   303,   506,
     275,  -182,   120,  -182,   290,  -182,   187,  -182,   196,   303,
     303,   303,   552,  -182,  -182,   305,   205,  -182,   273,  -182,
      -9,  -182,   190,   308,  -182,  -182,  -182,   396,  -182
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,   229,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     7,     0,     0,    15,     8,    10,    11,    13,
      14,     9,    17,    12,    16,     0,     0,   227,     0,   221,
     222,     0,     0,     0,     0,     0,     0,     0,   103,   104,
       0,   142,     1,     3,     2,   108,   101,     5,     4,   228,
       0,     0,     0,     0,   163,    25,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,    90,     0,     0,     0,
      97,   164,     0,     0,   163,    99,     0,   105,     0,   106,
       0,   219,   197,   194,     0,   214,   111,    40,    29,     0,
      30,    31,    34,    36,    37,    39,     0,    41,   193,    35,
      38,    32,    33,     0,     0,     0,     0,     0,   112,   113,
     117,   179,   181,   183,   186,   185,   184,     0,   202,     0,
       0,     0,     0,     0,    89,    66,    27,     0,     0,     0,
       0,   165,   167,   169,   171,     0,   184,     0,     0,     0,
      96,     0,     0,   143,     0,   195,   196,     0,    43,   198,
       0,    44,     0,   199,     0,   163,     0,   215,   216,     0,
       0,   116,   217,   218,     0,     0,   182,     0,     0,    19,
       0,     0,     0,     0,    20,    21,    22,     0,     0,     0,
      64,     0,    42,    56,   170,     0,     0,     0,     0,     0,
     204,   206,   207,   208,   209,   205,   210,   212,     0,     0,
       0,   200,     0,     0,    98,   100,   131,   220,     0,     0,
     187,     0,   144,   119,   139,   132,   146,   114,   115,   178,
     180,   203,     0,   188,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    65,    68,    28,     0,
       0,     0,    47,     0,     0,    49,    55,    57,    26,   177,
     166,   168,   211,   213,     0,     0,   176,     0,   175,    88,
       0,     0,    45,    46,     0,   135,   140,     0,     0,     0,
       0,     0,     0,   118,   120,   122,   138,     0,     0,   137,
       0,   148,   189,   190,     0,     0,     0,     0,     0,    92,
     225,   226,   224,   223,    93,    91,     0,    67,    83,    84,
      85,     0,     0,    70,    48,     0,    51,    50,     0,    54,
       0,     0,   174,   201,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   121,     0,     0,   136,     0,
       0,   150,   192,    61,     0,     0,    58,     0,     0,     0,
      24,    62,     0,     0,    23,     0,     0,     0,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,   134,
     147,   149,     0,   152,     0,    59,    94,    95,     0,    74,
      76,    77,    78,     0,     0,     0,    52,     0,   173,    87,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
     107,     0,    86,     0,    82,    80,     0,    79,     0,    72,
      73,     0,    53,   130,     0,   123,   126,     0,   128,     0,
     151,   154,   157,   153,     0,    75,     0,    69,    66,   129,
     125,   127,     0,   158,   159,   160,     0,    81,     0,   155,
       0,   156,     0,     0,   161,   162,    60,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -106,  -182,
     277,   159,  -182,  -182,  -178,  -182,  -182,   -11,  -182,  -182,
    -182,    34,    16,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,   280,  -182,  -182,  -182,   352,
     333,  -182,  -182,  -182,   259,  -182,  -182,  -182,   147,   361,
    -182,   154,  -181,    -7,  -182,  -182,  -182,  -182,  -182,  -182,
       1,  -182,  -182,   -56,  -182,  -110,   240,   242,   307,   -60,
     284,   282,   315,  -146,   105,  -136,   134,   -26,  -182,  -182,
    -182,  -182,   -32,    -4,    95,  -182,  -182
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    19,   126,   127,
     106,   246,   247,   248,   174,   236,   237,   179,   303,   344,
     401,   368,   369,   370,   371,   372,   300,   340,    20,    21,
     124,   232,    22,    23,    74,    75,    24,    25,    38,    39,
      46,    63,   107,   108,   109,   155,   273,   274,   275,   211,
     279,   212,   265,   266,   213,   281,   331,   363,   390,   410,
     411,   425,   431,    70,    71,   131,   132,   133,   134,   135,
     111,   112,   113,   114,   225,   115,   202,   116,   199,   117,
     160,   164,    80,   118,   294,    26,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   201,   235,   110,    40,   187,    37,    41,   214,    29,
     167,    30,   394,   169,   257,    29,   290,    30,   140,    32,
     185,   187,   187,   353,    50,    28,   380,   382,    52,    53,
      54,    55,    56,   276,   395,   277,   157,   158,   384,   291,
     292,   138,    34,   136,   386,   152,   399,   267,    61,   434,
      33,    40,   268,    76,    41,    35,    81,   269,   144,   293,
     270,   144,   144,   125,   128,   435,    29,   404,    30,    81,
     186,   400,    62,   144,    36,   238,   407,   271,     1,   144,
       2,   205,   258,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   264,   157,   158,   110,   168,   328,   216,
     278,   272,   144,   136,   136,   306,   161,     3,   224,   409,
      42,   144,   249,   168,    45,   128,   285,   175,   176,   396,
      64,     4,     5,   341,   313,    78,   214,     6,   333,   376,
     210,    29,     7,    30,    57,    76,   239,   170,   255,   256,
     207,   157,   158,   316,   144,     8,   233,    65,   157,   158,
     215,    72,   423,   320,   317,   218,   171,   311,   159,    69,
      73,   136,   136,   221,   321,     9,    49,   240,   139,   157,
     158,  -102,   424,   322,    81,   241,   267,   128,   201,   347,
      10,   268,    51,   172,   323,    11,   269,    12,   210,   270,
      47,   157,   158,    48,   310,   345,   230,   288,   173,    58,
     136,   231,    59,   337,   242,    60,   271,    41,   338,    29,
      41,    30,    66,   243,   252,   253,   254,   244,    68,    43,
     361,    44,   119,   120,   332,    81,   121,   122,   245,    69,
     143,   144,   162,   163,   180,   181,    67,   319,   203,   144,
     308,   157,   158,   383,   259,   260,   283,   284,   295,   296,
      78,   348,   297,   144,   334,   335,   137,   315,   298,   299,
      41,   336,   144,   141,   123,    81,   364,   144,   215,   224,
     403,   145,   405,   146,   406,    41,   408,   365,   144,   136,
     379,   260,    81,    81,   350,   148,   352,   378,   354,   147,
     356,   392,   393,   149,   419,   150,   151,   420,   153,   421,
     417,   393,   427,   144,   136,   436,   144,   154,   156,   177,
     178,   187,    81,   188,    81,   200,    81,   206,    81,   381,
     208,   209,   226,   385,   227,   387,   228,   136,   412,   234,
     229,   280,   261,   262,   263,   373,   289,   282,   286,   301,
     302,   304,   377,   287,   305,   307,   318,    81,   312,   314,
     326,    81,   327,    81,   136,   329,   136,   330,   136,   339,
     136,   342,   412,   343,   416,   362,   351,   358,   346,   397,
     373,   355,   357,   359,   366,   374,   375,   388,   136,   413,
     391,   136,   389,   136,   430,   284,   402,   414,   433,   373,
     418,   422,    81,   437,   432,    29,    82,    30,    83,    29,
      82,    30,    83,   438,   426,   183,   309,   428,   398,   415,
      77,   142,    84,    85,   222,   217,    84,    85,    86,   204,
      79,   325,    81,   429,    87,    88,   324,   250,    87,    88,
     251,    89,   166,   367,   360,    89,   184,    90,    91,    92,
       0,    90,    91,    92,   219,    93,   220,     0,   349,    93,
      94,     0,     0,     0,    94,     0,     0,     0,     0,     0,
      95,    96,     0,     0,    95,    96,     0,     0,    97,    98,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,    99,     0,   100,     0,   101,
     102,   100,     0,   101,   102,     0,     0,   103,     0,     0,
     104,   103,     0,     0,   104,   105,   223,     0,     0,   105,
      29,    82,    30,    83,     0,     0,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    90,    91,    92,     0,    29,    82,    30,    83,
      93,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    87,    88,     0,     0,     0,
       0,     0,    89,     0,     0,     0,    99,     0,    90,    91,
      92,     0,   100,     0,   101,   102,    93,     0,     0,     0,
       0,    94,   103,     0,     0,   104,     0,     0,     0,     0,
     130,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,    29,    82,    30,    83,     0,
       0,     0,    99,     0,     0,     0,     0,     0,   100,     0,
     101,   102,    84,   165,     0,     0,     0,     0,   103,     0,
       0,   104,     0,     0,    87,    88,   105,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,    90,    91,    92,
       0,    29,    82,    30,    83,    93,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      95,    96,     0,     0,     0,     0,     0,     0,    97,    98,
      87,    88,     0,     0,     0,     0,     0,    89,     0,     0,
       0,    99,     0,    90,    91,    92,     0,   100,     0,   101,
     102,    93,     0,     0,     0,     0,    94,   103,     0,     0,
     104,     0,     0,    87,    88,   105,    95,    96,     0,     0,
      89,     0,     0,     0,    97,    98,    90,    91,    92,     0,
       0,    82,     0,    83,    93,     0,     0,    99,     0,    94,
       0,     0,     0,   100,     0,   101,   102,    84,   165,    95,
     182,     0,     0,   103,     0,     0,   104,    97,     0,    87,
      88,   130,     0,     0,     0,     0,    89,     0,     0,     0,
      99,     0,    90,    91,    92,     0,   100,     0,   101,   102,
      93,     0,     0,     0,     0,    94,   103,     0,     0,   104,
       0,     0,     0,     0,     0,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    99,   157,   158,     0,
       0,     0,   100,     0,   101,   102,     0,     0,     0,     0,
       0,     0,   103,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
       4,   137,   180,    63,    11,     8,    10,    11,   154,     4,
      27,     6,     7,   119,    10,     4,    57,     6,    74,    66,
     130,     8,     8,    81,    28,    97,    81,    81,    32,    33,
      34,    35,    36,   214,    29,    36,    21,    22,    81,    80,
      81,    73,    61,    69,    81,   105,    64,    62,    29,    58,
      97,    58,    67,    57,    58,    97,    60,    72,   116,   100,
      75,   116,   116,    67,    68,    74,     4,    81,     6,    73,
     130,    89,    53,   116,    71,   181,    81,    92,     1,   116,
       3,   141,    78,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    31,    21,    22,   156,   114,   279,   155,
     101,   116,   116,   129,   130,   241,   110,    30,   168,    81,
       0,   116,   115,   114,    94,   119,   226,   121,   122,   114,
      28,    44,    45,   301,   260,   114,   272,    50,   115,   115,
     115,     4,    55,     6,    95,   139,    10,    41,   198,   199,
     144,    21,    22,    72,   116,    68,   178,    55,    21,    22,
     154,   105,    32,    72,    83,   159,    60,     9,    31,   107,
     114,   187,   188,   167,    83,    88,     3,    41,   116,    21,
      22,    94,    52,    72,   178,    49,    62,   181,   314,     9,
     103,    67,    61,    87,    83,   108,    72,   110,   115,    75,
     110,    21,    22,   113,   254,   305,    51,   229,   102,   116,
     226,    56,    31,    51,    78,   114,    92,   211,    56,     4,
     214,     6,     5,    87,    17,    18,    19,    91,   114,   110,
     330,   112,    42,    43,   284,   229,    42,    43,   102,   107,
     115,   116,    23,    24,   115,   116,    81,   269,   115,   116,
     244,    21,    22,   353,   115,   116,   115,   116,   115,   116,
     114,   311,   115,   116,   286,   287,   114,   264,    37,    38,
     264,   115,   116,    11,   108,   269,   115,   116,   272,   329,
     380,     7,   382,     7,   384,   279,   386,   115,   116,   305,
     115,   116,   286,   287,   316,    70,   318,   347,   320,   114,
     322,   115,   116,     5,   404,   114,    70,   407,     5,   409,
     115,   116,   115,   116,   330,   115,   116,    61,   116,   114,
     114,     8,   316,     9,   318,    20,   320,   115,   322,   351,
       7,     7,   114,   355,    73,   357,    73,   353,   388,   104,
     114,    63,   105,   115,   115,   339,     5,   115,   114,   116,
     108,    78,   346,   114,   114,    73,    72,   351,    78,   114,
       7,   355,     7,   357,   380,    39,   382,    65,   384,   114,
     386,    35,   422,    84,   396,    82,    72,    86,   114,   373,
     374,    72,    72,    86,     5,   114,    39,    39,   404,     7,
      91,   407,    76,   409,    79,   116,   115,   391,   115,   393,
     114,   116,   396,    85,   426,     4,     5,     6,     7,     4,
       5,     6,     7,     7,   114,   128,   247,   418,   374,   393,
      58,    78,    21,    22,    23,   156,    21,    22,    23,   139,
      59,   274,   426,   422,    33,    34,   272,   187,    33,    34,
     188,    40,   117,   338,   329,    40,   129,    46,    47,    48,
      -1,    46,    47,    48,   160,    54,   164,    -1,   314,    54,
      59,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      69,    70,    -1,    -1,    69,    70,    -1,    -1,    77,    78,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    90,    -1,    96,    -1,    98,
      99,    96,    -1,    98,    99,    -1,    -1,   106,    -1,    -1,
     109,   106,    -1,    -1,   109,   114,   115,    -1,    -1,   114,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,     4,     5,     6,     7,
      54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    90,    -1,    46,    47,
      48,    -1,    96,    -1,    98,    99,    54,    -1,    -1,    -1,
      -1,    59,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,
     114,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,     4,     5,     6,     7,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      98,    99,    21,    22,    -1,    -1,    -1,    -1,   106,    -1,
      -1,   109,    -1,    -1,    33,    34,   114,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,     4,     5,     6,     7,    54,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      33,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    90,    -1,    46,    47,    48,    -1,    96,    -1,    98,
      99,    54,    -1,    -1,    -1,    -1,    59,   106,    -1,    -1,
     109,    -1,    -1,    33,    34,   114,    69,    70,    -1,    -1,
      40,    -1,    -1,    -1,    77,    78,    46,    47,    48,    -1,
      -1,     5,    -1,     7,    54,    -1,    -1,    90,    -1,    59,
      -1,    -1,    -1,    96,    -1,    98,    99,    21,    22,    69,
      70,    -1,    -1,   106,    -1,    -1,   109,    77,    -1,    33,
      34,   114,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      90,    -1,    46,    47,    48,    -1,    96,    -1,    98,    99,
      54,    -1,    -1,    -1,    -1,    59,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    90,    21,    22,    -1,
      -1,    -1,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,   109
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    30,    44,    45,    50,    55,    68,    88,
     103,   108,   110,   118,   119,   120,   121,   122,   123,   124,
     145,   146,   149,   150,   153,   154,   202,   203,    97,     4,
       6,   200,    66,    97,    61,    97,    71,   200,   155,   156,
     170,   200,     0,   110,   112,    94,   157,   110,   113,     3,
     200,    61,   200,   200,   200,   200,   200,    95,   116,    31,
     114,    29,    53,   158,    28,    55,     5,    81,   114,   107,
     180,   181,   105,   114,   151,   152,   200,   156,   114,   166,
     199,   200,     5,     7,    21,    22,    23,    33,    34,    40,
      46,    47,    48,    54,    59,    69,    70,    77,    78,    90,
      96,    98,    99,   106,   109,   114,   127,   159,   160,   161,
     186,   187,   188,   189,   190,   192,   194,   196,   200,    42,
      43,    42,    43,   108,   147,   200,   125,   126,   200,    10,
     114,   182,   183,   184,   185,   186,   194,   114,   199,   116,
     180,    11,   157,   115,   116,     7,     7,   114,    70,     5,
     114,    70,   186,     5,    61,   162,   116,    21,    22,    31,
     197,   200,    23,    24,   198,    22,   189,    27,   114,   125,
      41,    60,    87,   102,   131,   200,   200,   114,   114,   134,
     115,   116,    70,   127,   185,   182,   186,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   195,
      20,   192,   193,   115,   152,   186,   115,   200,     7,     7,
     115,   166,   168,   171,   190,   200,   180,   161,   200,   187,
     188,   200,    23,   115,   186,   191,   114,    73,    73,   114,
      51,    56,   148,   199,   104,   131,   132,   133,   125,    10,
      41,    49,    78,    87,    91,   102,   128,   129,   130,   115,
     183,   184,    17,    18,    19,   186,   186,    10,    78,   115,
     116,   105,   115,   115,    31,   169,   170,    62,    67,    72,
      75,    92,   116,   163,   164,   165,   169,    36,   101,   167,
      63,   172,   115,   115,   116,   182,   114,   114,   199,     5,
      57,    80,    81,   100,   201,   115,   116,   115,    37,    38,
     143,   116,   108,   135,    78,   114,   192,    73,   200,   128,
     186,     9,    78,   192,   114,   170,    72,    83,    72,   199,
      72,    83,    72,    83,   168,   165,     7,     7,   169,    39,
      65,   173,   186,   115,   199,   199,   115,    51,    56,   114,
     144,   131,    35,    84,   136,   182,   114,     9,   186,   193,
     199,    72,   199,    81,   199,    72,   199,    72,    86,    86,
     191,   182,    82,   174,   115,   115,     5,   201,   138,   139,
     140,   141,   142,   200,   114,    39,   115,   200,   186,   115,
      81,   199,    81,   182,    81,   199,    81,   199,    39,    76,
     175,    91,   115,   116,     7,    29,   114,   200,   138,    64,
      89,   137,   115,   182,    81,   182,   182,    81,   182,    81,
     176,   177,   186,     7,   200,   139,   199,   115,   114,   182,
     182,   182,   116,    32,    52,   178,   114,   115,   134,   177,
      79,   179,   199,   115,    58,    74,   115,    85,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   121,
     121,   121,   121,   122,   123,   124,   125,   126,   126,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   128,
     128,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   139,   140,
     140,   141,   142,   143,   143,   144,   144,   145,   145,   146,
     147,   147,   148,   148,   148,   148,   149,   150,   151,   151,
     152,   153,   154,   154,   155,   155,   156,   157,   158,   158,
     158,   159,   159,   160,   160,   161,   161,   161,   162,   163,
     163,   164,   164,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   167,   167,   167,   168,   168,   168,   168,   168,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   177,   178,   178,   178,
     179,   179,   179,   180,   180,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   185,   185,   185,   185,   186,   186,
     187,   187,   188,   188,   189,   189,   189,   189,   190,   190,
     190,   191,   191,   192,   192,   192,   192,   192,   192,   192,
     193,   193,   194,   194,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   196,   197,   197,   198,   198,   199,
     199,   200,   200,   201,   201,   201,   201,   202,   203,   203
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
       2,     4,     2,     1,     1,     0,     3,    10,     7,     5,
       0,     4,     2,     2,     4,     4,     5,     4,     3,     1,
       3,     2,     0,     2,     1,     3,     3,     9,     0,     1,
       1,     1,     1,     1,     3,     3,     2,     1,     3,     0,
       1,     2,     1,     5,     4,     6,     5,     6,     5,     6,
       5,     3,     0,     3,     3,     2,     3,     2,     2,     1,
       1,     2,     1,     4,     1,     3,     0,     3,     0,     2,
       0,     3,     0,     2,     1,     3,     3,     0,     1,     1,
       0,     2,     2,     0,     1,     2,     3,     1,     3,     1,
       2,     1,     5,     6,     4,     3,     3,     3,     3,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     3,     4,
       4,     1,     3,     1,     1,     2,     2,     1,     2,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     0
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
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1762 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOKEN_NAME  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1772 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOKEN_STRING_SINGLE_QUOTED  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1782 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOKEN_STRING_DOUBLE_QUOTED  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1792 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOKEN_UNSIGNED_NUMVAL  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 1802 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 119: /* sql_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1812 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 120: /* quit_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).quit_statement_) != nullptr) {
    delete ((*yyvaluep).quit_statement_);
  }
}
#line 1822 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 121: /* alter_table_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1832 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 122: /* create_table_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).create_table_statement_) != nullptr) {
    delete ((*yyvaluep).create_table_statement_);
  }
}
#line 1842 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 123: /* create_index_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1852 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 124: /* drop_table_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).drop_table_statement_) != nullptr) {
    delete ((*yyvaluep).drop_table_statement_);
  }
}
#line 1862 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 125: /* column_def  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_);
  }
}
#line 1872 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 126: /* column_def_commalist  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_list_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_list_);
  }
}
#line 1882 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 127: /* data_type  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).data_type_) != nullptr) {
    delete ((*yyvaluep).data_type_);
  }
}
#line 1892 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 128: /* column_constraint_def  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_) != nullptr) {
    delete ((*yyvaluep).column_constraint_);
  }
}
#line 1902 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 129: /* column_constraint_def_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 1912 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 130: /* opt_column_constraint_def_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 1922 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 134: /* opt_column_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 1932 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 135: /* opt_block_properties  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).block_properties_) != nullptr) {
    delete ((*yyvaluep).block_properties_);
  }
}
#line 1942 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 136: /* opt_partition_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).partition_clause_) != nullptr) {
    delete ((*yyvaluep).partition_clause_);
  }
}
#line 1952 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 137: /* partition_type  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1962 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 138: /* key_value_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 1972 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 139: /* key_value  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_) != nullptr) {
    delete ((*yyvaluep).key_value_);
  }
}
#line 1982 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 140: /* key_string_value  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_value_) != nullptr) {
    delete ((*yyvaluep).key_string_value_);
  }
}
#line 1992 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 141: /* key_string_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_list_) != nullptr) {
    delete ((*yyvaluep).key_string_list_);
  }
}
#line 2002 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 142: /* key_integer_value  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_integer_value_) != nullptr) {
    delete ((*yyvaluep).key_integer_value_);
  }
}
#line 2012 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 143: /* index_type  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2022 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 144: /* opt_index_properties  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2032 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 145: /* insert_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).insert_statement_) != nullptr) {
    delete ((*yyvaluep).insert_statement_);
  }
}
#line 2042 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 146: /* copy_from_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_statement_) != nullptr) {
    delete ((*yyvaluep).copy_from_statement_);
  }
}
#line 2052 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 147: /* opt_copy_from_params  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2062 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 148: /* copy_from_params  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2072 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 149: /* update_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).update_statement_) != nullptr) {
    delete ((*yyvaluep).update_statement_);
  }
}
#line 2082 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 150: /* delete_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).delete_statement_) != nullptr) {
    delete ((*yyvaluep).delete_statement_);
  }
}
#line 2092 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 151: /* assignment_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_list_) != nullptr) {
    delete ((*yyvaluep).assignment_list_);
  }
}
#line 2102 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 152: /* assignment_item  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_) != nullptr) {
    delete ((*yyvaluep).assignment_);
  }
}
#line 2112 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 153: /* select_statement  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_statement_) != nullptr) {
    delete ((*yyvaluep).select_statement_);
  }
}
#line 2122 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 154: /* opt_with_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2132 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 155: /* with_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2142 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 156: /* with_list_element  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_element_) != nullptr) {
    delete ((*yyvaluep).with_list_element_);
  }
}
#line 2152 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 157: /* select_query  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_query_) != nullptr) {
    delete ((*yyvaluep).select_query_);
  }
}
#line 2162 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 159: /* selection  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_) != nullptr) {
    delete ((*yyvaluep).selection_);
  }
}
#line 2172 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 160: /* selection_item_commalist  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_list_) != nullptr) {
    delete ((*yyvaluep).selection_list_);
  }
}
#line 2182 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 161: /* selection_item  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_item_) != nullptr) {
    delete ((*yyvaluep).selection_item_);
  }
}
#line 2192 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 162: /* from_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2202 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 166: /* subquery_expression  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).subquery_expression_) != nullptr) {
    delete ((*yyvaluep).subquery_expression_);
  }
}
#line 2212 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 167: /* opt_sample_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_sample_clause_) != nullptr) {
    delete ((*yyvaluep).opt_sample_clause_);
  }
}
#line 2222 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 168: /* table_reference  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2232 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 169: /* table_reference_signature  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2242 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 170: /* table_reference_signature_primary  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2252 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 171: /* table_reference_commalist  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2262 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 172: /* opt_group_by_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_group_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_group_by_clause_);
  }
}
#line 2272 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 173: /* opt_having_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_having_clause_) != nullptr) {
    delete ((*yyvaluep).opt_having_clause_);
  }
}
#line 2282 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 174: /* opt_order_by_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_order_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_order_by_clause_);
  }
}
#line 2292 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 175: /* opt_limit_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_limit_clause_) != nullptr) {
    delete ((*yyvaluep).opt_limit_clause_);
  }
}
#line 2302 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 176: /* order_commalist  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_commalist_) != nullptr) {
    delete ((*yyvaluep).order_commalist_);
  }
}
#line 2312 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 177: /* order_item  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_item_) != nullptr) {
    delete ((*yyvaluep).order_item_);
  }
}
#line 2322 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 178: /* opt_order_direction  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2332 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 179: /* opt_nulls_first  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2342 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 180: /* opt_where_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2352 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 181: /* where_clause  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2362 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 182: /* or_expression  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2372 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 183: /* and_expression  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2382 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 184: /* not_expression  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2392 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 185: /* predicate_expression_base  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2402 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 186: /* add_expression  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2412 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 187: /* multiply_expression  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2422 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 188: /* unary_expression  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2432 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 189: /* expression_base  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2442 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 190: /* function_call  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).function_call_) != nullptr) {
    delete ((*yyvaluep).function_call_);
  }
}
#line 2452 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 191: /* expression_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_list_) != nullptr) {
    delete ((*yyvaluep).expression_list_);
  }
}
#line 2462 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 192: /* literal_value  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2472 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 193: /* literal_value_commalist  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_list_) != nullptr) {
    delete ((*yyvaluep).literal_value_list_);
  }
}
#line 2482 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 194: /* attribute_ref  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2492 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 195: /* comparison_operation  */
#line 517 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2498 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 196: /* unary_operation  */
#line 518 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2504 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 197: /* add_operation  */
#line 519 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2510 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 198: /* multiply_operation  */
#line 519 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2516 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 199: /* name_commalist  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 2526 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 200: /* any_name  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2536 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 201: /* boolean_value  */
#line 516 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2542 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 202: /* command  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_) != nullptr) {
    delete ((*yyvaluep).command_);
  }
}
#line 2552 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 203: /* command_argument_list  */
#line 521 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_argument_list_) != nullptr) {
    delete ((*yyvaluep).command_argument_list_);
  }
}
#line 2562 "SqlParser_gen.cpp" /* yacc.c:1257  */
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
#line 530 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 2859 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 534 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 2868 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 538 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 2877 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 542 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 2886 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 546 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    YYABORT;
  }
#line 2894 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 549 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Regular yyparse() return codes are non-negative, so use a negative one here.
    return -1;
  }
#line 2903 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 556 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 2911 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 559 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].copy_from_statement_);
  }
#line 2919 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 562 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].create_table_statement_);
  }
#line 2927 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 565 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 2935 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 568 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].delete_statement_);
  }
#line 2943 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 571 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].drop_table_statement_);
  }
#line 2951 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 574 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].insert_statement_);
  }
#line 2959 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 577 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].quit_statement_);
  }
#line 2967 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 580 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].select_statement_);
  }
#line 2975 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 583 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].update_statement_);
  }
#line 2983 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 589 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.quit_statement_) = new quickstep::ParseStatementQuit((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 2991 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 595 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].attribute_definition_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3003 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 602 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3014 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 608 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3026 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 615 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3038 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 624 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.create_table_statement_) = new quickstep::ParseStatementCreateTable((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].attribute_definition_list_), (yyvsp[-1].block_properties_), (yyvsp[0].partition_clause_));
  }
#line 3046 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 629 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].string_list_), (yyvsp[-1].string_value_), (yyvsp[0].key_value_list_));
  }
#line 3054 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 634 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.drop_table_statement_) = new quickstep::ParseStatementDropTable((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_));
  }
#line 3062 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 639 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_) = new quickstep::ParseAttributeDefinition((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].data_type_), (yyvsp[0].column_constraint_list_));
  }
#line 3070 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 644 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = new quickstep::PtrList<quickstep::ParseAttributeDefinition>();
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3079 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 648 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = (yyvsp[-2].attribute_definition_list_);
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3088 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 654 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "BIT data type");
    YYERROR;
  }
#line 3098 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 659 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3106 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 662 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3114 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 665 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "TIME data type");
    YYERROR;
  }
#line 3124 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 670 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3132 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 673 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3140 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 676 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3148 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 679 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3156 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 682 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kFloat));
  }
#line 3164 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 685 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3172 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 688 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3180 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 691 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3188 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 694 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3196 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 697 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3213 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 709 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetimeInterval));
  }
#line 3221 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 712 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kYearMonthInterval));
  }
#line 3229 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 715 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3252 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 733 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3275 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 753 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNull((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3283 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 756 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNotNull((yylsp[-1]).first_line, (yylsp[-1]).first_column);
  }
#line 3291 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 759 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "Column Constraints (UNIQUE)");
    YYERROR;
  }
#line 3301 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 764 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3311 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 769 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[0].literal_value_);
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (DEFAULT)");
    YYERROR;
  }
#line 3322 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 775 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Column Constraints (CHECK)");
    YYERROR;
  }
#line 3333 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 781 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_value_);
    NotSupported(&(yylsp[-4]), yyscanner, "Foreign Keys");
    YYERROR;
  }
#line 3345 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 790 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[-1].column_constraint_list_);
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3354 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 794 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = new quickstep::PtrList<quickstep::ParseColumnConstraint>();
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3363 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 800 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = nullptr;
  }
#line 3371 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 803 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[0].column_constraint_list_);
  }
#line 3379 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 808 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (UNIQUE)");
    YYERROR;
  }
#line 3389 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 813 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-4]), yyscanner, "Table Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3399 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 818 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-6].string_list_);
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-9]), yyscanner, "Table Constraints (FOREIGN KEY)");
    YYERROR;
  }
#line 3411 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 825 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (CHECK)");
    YYERROR;
  }
#line 3421 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 832 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[-2]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3430 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 836 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3439 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 842 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3447 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 845 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = $1; */
  }
#line 3455 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 850 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = nullptr;
  }
#line 3463 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 853 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    (yyval.string_list_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "list of column names in CREATE INDEX statement");
    YYERROR;
  }
#line 3474 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 861 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = nullptr;
  }
#line 3482 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 864 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = new quickstep::ParseBlockProperties((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].key_value_list_));
  }
#line 3490 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 869 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.partition_clause_) = nullptr;
  }
#line 3498 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 872 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 3520 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 891 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionScheme::PartitionType::kHash));
  }
#line 3529 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 895 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::PartitionScheme::PartitionType::kRange));
  }
#line 3538 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 901 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = new quickstep::PtrList<quickstep::ParseKeyValue>();
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3547 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 905 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-2].key_value_list_);
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3556 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 911 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_value_);
  }
#line 3564 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 914 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_list_);
  }
#line 3572 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 917 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_integer_value_);
  }
#line 3580 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 922 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].string_value_));
  }
#line 3588 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 925 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // This is a special case to handle the COMPRESS ALL option of the BLOCK PROPERTIES.
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), 
        new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, "ALL"));
  }
#line 3598 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 932 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_list_) = new quickstep::ParseKeyStringList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 3606 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 937 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.key_integer_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Value must be an integer");
      YYERROR;
    }
    (yyval.key_integer_value_) = new quickstep::ParseKeyIntegerValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].numeric_literal_value_));
  }
#line 3620 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 948 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBloomFilter));
  }
#line 3629 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 952 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kCSBTree));
  }
#line 3638 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 958 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = nullptr;
  }
#line 3646 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 961 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-1].key_value_list_);
  }
#line 3654 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 967 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-7].string_value_);
    delete (yyvsp[-5].string_list_);
    delete (yyvsp[-1].literal_value_list_);
    (yyval.insert_statement_) = nullptr;
    NotSupported(&(yylsp[-6]), yyscanner, "list of column names in INSERT statement");
    YYERROR;
  }
#line 3667 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 975 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsert((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].string_value_), (yyvsp[-1].literal_value_list_));
  }
#line 3675 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 980 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_statement_) = new quickstep::ParseStatementCopyFrom((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_value_), (yyvsp[0].copy_from_params_));
  }
#line 3683 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 985 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = nullptr;
  }
#line 3691 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 988 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-1].copy_from_params_);
  }
#line 3699 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 993 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 3708 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 997 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 3717 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1001 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 3726 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1005 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 3735 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1011 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.update_statement_) = new quickstep::ParseStatementUpdate((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].assignment_list_), (yyvsp[0].predicate_));
  }
#line 3743 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1016 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.delete_statement_) = new quickstep::ParseStatementDelete((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].predicate_));
  }
#line 3751 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1021 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = (yyvsp[-2].assignment_list_);
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 3760 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1025 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = new quickstep::PtrList<quickstep::ParseAssignment>();
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 3769 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1031 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_) = new quickstep::ParseAssignment((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[0].expression_));
  }
#line 3777 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1037 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].select_query_), (yyvsp[-1].with_list_));
  }
#line 3785 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1042 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = nullptr;
  }
#line 3793 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1045 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[0].with_list_);
  }
#line 3801 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1050 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = new quickstep::PtrVector<quickstep::ParseSubqueryTableReference>();
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 3810 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1054 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[-2].with_list_);
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 3819 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1060 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_element_) = new quickstep::ParseSubqueryTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].subquery_expression_));
    (yyval.with_list_element_)->set_table_reference_signature((yyvsp[-2].table_reference_signature_));
  }
#line 3828 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1067 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_query_) = new quickstep::ParseSelect((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].selection_), (yyvsp[-5].table_reference_list_), (yyvsp[-4].predicate_), (yyvsp[-3].opt_group_by_clause_), (yyvsp[-2].opt_having_clause_), (yyvsp[-1].opt_order_by_clause_), (yyvsp[0].opt_limit_clause_));
  }
#line 3836 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1072 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3844 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1075 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "ALL in selection");
    YYERROR;
  }
#line 3853 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1079 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "DISTINCT in selection");
    YYERROR;
  }
#line 3862 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1085 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = new quickstep::ParseSelectionStar((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3870 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1088 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = (yyvsp[0].selection_list_);
  }
#line 3878 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1093 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = new quickstep::ParseSelectionList((yylsp[0]).first_line, (yylsp[0]).first_column);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 3887 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1097 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = (yyvsp[-2].selection_list_);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 3896 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1103 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[0].string_value_));
  }
#line 3904 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1106 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].expression_), (yyvsp[0].string_value_));
  }
#line 3912 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1109 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].expression_));
  }
#line 3920 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1114 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[-1].table_reference_list_);
  }
#line 3928 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1119 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3936 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1122 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3945 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1128 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[-1]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3954 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1132 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3963 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1138 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3974 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1144 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3985 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1150 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-5]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 3996 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1156 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4007 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1162 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-5]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4018 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1168 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4029 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1174 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-5]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4040 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1180 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4051 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1188 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.subquery_expression_) = new quickstep::ParseSubqueryExpression((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].select_query_));
  }
#line 4059 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1193 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = NULL;
  }
#line 4067 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1196 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, true, (yyvsp[-1].numeric_literal_value_));
  }
#line 4075 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1199 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].numeric_literal_value_));
  }
#line 4083 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1204 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSubqueryTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].subquery_expression_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4092 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1208 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].opt_sample_clause_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4101 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1212 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].opt_sample_clause_));
  }
#line 4109 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1215 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].function_call_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4118 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1219 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].function_call_));
  }
#line 4126 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1224 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4134 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1227 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4142 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1232 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4150 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1235 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4158 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1240 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = new quickstep::PtrList<quickstep::ParseTableReference>();
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4167 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1244 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[-2].table_reference_list_);
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4176 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1250 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = nullptr;
  }
#line 4184 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1253 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = new quickstep::ParseGroupBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].expression_list_));
  }
#line 4192 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1258 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = nullptr;
  }
#line 4200 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1261 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = new quickstep::ParseHaving((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4208 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1266 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = nullptr;
  }
#line 4216 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1269 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = new quickstep::ParseOrderBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].order_commalist_));
  }
#line 4224 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1274 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_limit_clause_) = nullptr;
  }
#line 4232 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1277 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 4254 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1296 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = new quickstep::PtrList<quickstep::ParseOrderByItem>();
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4263 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1300 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = (yyvsp[-2].order_commalist_);
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4272 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1306 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_item_) = new quickstep::ParseOrderByItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[-1].order_direction_), (yyvsp[0].order_direction_));
    delete (yyvsp[-1].order_direction_);
    delete (yyvsp[0].order_direction_);
  }
#line 4282 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1313 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4290 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1316 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4298 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1319 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4306 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1324 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4314 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1327 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4322 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1330 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4330 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1336 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = nullptr;
  }
#line 4338 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1339 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4346 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1344 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4354 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1349 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kDisjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateDisjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4368 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1358 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4376 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1363 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kConjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateConjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4390 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1372 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4398 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1377 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4406 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1380 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4414 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1385 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4422 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1388 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line, (yylsp[-4]).first_column,
        new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_)));
  }
#line 4432 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1393 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4443 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1399 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4454 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1405 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateComparison((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].comparison_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4462 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1408 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[-1].predicate_);
  }
#line 4470 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1414 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4478 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1417 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4486 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1422 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4494 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1425 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4502 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1430 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseUnaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].unary_operation_), (yyvsp[0].expression_));
  }
#line 4510 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1433 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4518 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1438 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].attribute_);
  }
#line 4526 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1441 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_));
  }
#line 4534 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1444 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].function_call_);
  }
#line 4542 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1447 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[-1].expression_);
  }
#line 4550 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1452 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), new quickstep::PtrList<quickstep::ParseExpression>());
  }
#line 4559 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1456 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), new quickstep::ParseStar((yylsp[-1]).first_line, (yylsp[-1]).first_column));
  }
#line 4568 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1460 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].expression_list_));
  }
#line 4576 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1465 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = new quickstep::PtrList<quickstep::ParseExpression>();
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 4585 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1469 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = (yyvsp[-2].expression_list_);
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 4594 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1475 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::NullParseLiteralValue((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 4602 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1478 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 4610 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1481 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 4618 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1484 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 4635 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1496 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_),
                                                nullptr);  // No explicit type.
  }
#line 4644 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1500 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 4668 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1519 "../SqlParser.ypp" /* yacc.c:1646  */
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
#line 4686 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1534 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = new quickstep::PtrList<quickstep::ParseScalarLiteral>();
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 4695 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1538 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = (yyvsp[-2].literal_value_list_);
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 4704 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1544 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4712 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1547 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_), (yyvsp[-2].string_value_));
  }
#line 4720 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1553 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kEqual);
  }
#line 4728 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1556 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotEqual);
  }
#line 4736 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1559 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLess);
  }
#line 4744 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1562 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLessOrEqual);
  }
#line 4752 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1565 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreater);
  }
#line 4760 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1568 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreaterOrEqual);
  }
#line 4768 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1571 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLike);
  }
#line 4776 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1574 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotLike);
  }
#line 4784 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1577 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kRegexMatch);
  }
#line 4792 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1580 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotRegexMatch);
  }
#line 4800 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1585 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * '-' TOKEN_UNSIGNED_NUMVAL case in 'literal_value'. Because Bison prefers
     * to shift rather than reduce, the case in 'literal_value' has precedence
     * over this one.
     **/
    (yyval.unary_operation_) = &quickstep::UnaryOperationFactory::GetUnaryOperation(quickstep::UnaryOperationID::kNegate);
  }
#line 4814 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1596 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kAdd);
  }
#line 4822 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1599 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kSubtract);
  }
#line 4830 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1604 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kMultiply);
  }
#line 4838 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1607 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kDivide);
  }
#line 4846 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1613 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = new quickstep::PtrList<quickstep::ParseString>();
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 4855 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1617 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = (yyvsp[-2].string_list_);
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 4864 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1623 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 4872 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1626 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].string_value_)->value().empty()) {
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Zero-length identifier");
    }
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 4883 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1634 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 4891 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1637 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 4899 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1640 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 4907 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1643 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 4915 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1649 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.command_) = new quickstep::ParseCommand((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].command_argument_list_));
  }
#line 4923 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1654 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::PtrVector<quickstep::ParseString> *argument_list = (yyvsp[-1].command_argument_list_);
    argument_list->push_back((yyvsp[0].string_value_));
    (yyval.command_argument_list_) = argument_list;
  }
#line 4933 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1659 "../SqlParser.ypp" /* yacc.c:1646  */
    { /* Epsilon, an empy match. */
    (yyval.command_argument_list_) = new quickstep::PtrVector<quickstep::ParseString>();
  }
#line 4941 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;


#line 4945 "SqlParser_gen.cpp" /* yacc.c:1646  */
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
#line 1663 "../SqlParser.ypp" /* yacc.c:1906  */


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
