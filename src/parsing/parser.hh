// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file /home/tom/nilang/src/parsing/parser.hh
 ** Define the  Ni ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_HOME_TOM_NILANG_SRC_PARSING_PARSER_HH_INCLUDED
# define YY_YY_HOME_TOM_NILANG_SRC_PARSING_PARSER_HH_INCLUDED
// //                    "%code requires" blocks.
#line 11 "parser.y" // lalr1.cc:377

#include <iostream>
#include <string>

#include "ast/AST.h"
#include "codegen/Visitor.h"
using namespace std;


#ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

void yyerror(const char *s);

namespace Ni {
	class Lexer;
	class Driver;
}


#line 70 "/home/tom/nilang/src/parsing/parser.hh" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"

#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 9 "parser.y" // lalr1.cc:377
namespace  Ni  {
#line 147 "/home/tom/nilang/src/parsing/parser.hh" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class  Parser 
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // item_dec
      // expr
      char dummy1[sizeof(AST::ASTNode*)];

      // ty
      char dummy2[sizeof(AST::Types)];

      // BOOL
      char dummy3[sizeof(bool)];

      // DOUBLE
      char dummy4[sizeof(double)];

      // INT
      char dummy5[sizeof(long)];

      // IDENTIFIER
      // STRING
      char dummy6[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOKEN_EOF = 0,
        TOKEN_DEF = 258,
        TOKEN_RETURN = 259,
        TOKEN_CLASS = 260,
        TOKEN_PUB = 261,
        TOKEN_USE = 262,
        TOKEN_SELF = 263,
        TOKEN_IF = 264,
        TOKEN_ELSE = 265,
        TOKEN_ELIF = 266,
        TOKEN_SWITCH = 267,
        TOKEN_CASE = 268,
        TOKEN_INTERFACE = 269,
        TOKEN_OVERRIDE = 270,
        TOKEN_EXTENDS = 271,
        TOKEN_IMPLEMENTS = 272,
        TOKEN_TYPE = 273,
        TOKEN_END_STATEMENT = 274,
        TOKEN_LEFTPAR = 275,
        TOKEN_RIGHTPAR = 276,
        TOKEN_LEFTBRACE = 277,
        TOKEN_RIGHTBRACE = 278,
        TOKEN_MINUS = 279,
        TOKEN_MINUSEQ = 280,
        TOKEN_PLUS = 281,
        TOKEN_PLUSEQ = 282,
        TOKEN_MUL = 283,
        TOKEN_MULEQ = 284,
        TOKEN_DIV = 285,
        TOKEN_DIVEQ = 286,
        TOKEN_EQEQ = 287,
        TOKEN_EQ = 288,
        TOKEN_NE = 289,
        TOKEN_NOT = 290,
        TOKEN_LE = 291,
        TOKEN_LT = 292,
        TOKEN_GE = 293,
        TOKEN_GT = 294,
        TOKEN_ANDAND = 295,
        TOKEN_AND = 296,
        TOKEN_OROR = 297,
        TOKEN_OR = 298,
        TOKEN_INT = 299,
        TOKEN_DOUBLE = 300,
        TOKEN_BOOL = 301,
        TOKEN_IDENTIFIER = 302,
        TOKEN_STRING = 303
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t);

  basic_symbol (typename Base::kind_type t, const AST::ASTNode* v);

  basic_symbol (typename Base::kind_type t, const AST::Types v);

  basic_symbol (typename Base::kind_type t, const bool v);

  basic_symbol (typename Base::kind_type t, const double v);

  basic_symbol (typename Base::kind_type t, const long v);

  basic_symbol (typename Base::kind_type t, const std::string v);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_EOF ();

    static inline
    symbol_type
    make_DEF ();

    static inline
    symbol_type
    make_RETURN ();

    static inline
    symbol_type
    make_CLASS ();

    static inline
    symbol_type
    make_PUB ();

    static inline
    symbol_type
    make_USE ();

    static inline
    symbol_type
    make_SELF ();

    static inline
    symbol_type
    make_IF ();

    static inline
    symbol_type
    make_ELSE ();

    static inline
    symbol_type
    make_ELIF ();

    static inline
    symbol_type
    make_SWITCH ();

    static inline
    symbol_type
    make_CASE ();

    static inline
    symbol_type
    make_INTERFACE ();

    static inline
    symbol_type
    make_OVERRIDE ();

    static inline
    symbol_type
    make_EXTENDS ();

    static inline
    symbol_type
    make_IMPLEMENTS ();

    static inline
    symbol_type
    make_TYPE ();

    static inline
    symbol_type
    make_END_STATEMENT ();

    static inline
    symbol_type
    make_LEFTPAR ();

    static inline
    symbol_type
    make_RIGHTPAR ();

    static inline
    symbol_type
    make_LEFTBRACE ();

    static inline
    symbol_type
    make_RIGHTBRACE ();

    static inline
    symbol_type
    make_MINUS ();

    static inline
    symbol_type
    make_MINUSEQ ();

    static inline
    symbol_type
    make_PLUS ();

    static inline
    symbol_type
    make_PLUSEQ ();

    static inline
    symbol_type
    make_MUL ();

    static inline
    symbol_type
    make_MULEQ ();

    static inline
    symbol_type
    make_DIV ();

    static inline
    symbol_type
    make_DIVEQ ();

    static inline
    symbol_type
    make_EQEQ ();

    static inline
    symbol_type
    make_EQ ();

    static inline
    symbol_type
    make_NE ();

    static inline
    symbol_type
    make_NOT ();

    static inline
    symbol_type
    make_LE ();

    static inline
    symbol_type
    make_LT ();

    static inline
    symbol_type
    make_GE ();

    static inline
    symbol_type
    make_GT ();

    static inline
    symbol_type
    make_ANDAND ();

    static inline
    symbol_type
    make_AND ();

    static inline
    symbol_type
    make_OROR ();

    static inline
    symbol_type
    make_OR ();

    static inline
    symbol_type
    make_INT (const long& v);

    static inline
    symbol_type
    make_DOUBLE (const double& v);

    static inline
    symbol_type
    make_BOOL (const bool& v);

    static inline
    symbol_type
    make_IDENTIFIER (const std::string& v);

    static inline
    symbol_type
    make_STRING (const std::string& v);


    /// Build a parser object.
     Parser  (Ni::Lexer &lexer_yyarg, Ni::Visitor &visitor_yyarg, Ni::Driver &driver_yyarg);
    virtual ~ Parser  ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
     Parser  (const  Parser &);
     Parser & operator= (const  Parser &);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const signed char yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const signed char yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 47,     ///< Last index in yytable_.
      yynnts_ = 6,  ///< Number of nonterminal symbols.
      yyfinal_ = 7, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 49  ///< Number of tokens.
    };


    // User arguments.
    Ni::Lexer &lexer;
    Ni::Visitor &visitor;
    Ni::Driver &driver;
  };

  // Symbol number corresponding to token number t.
  inline
   Parser ::token_number_type
   Parser ::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    const unsigned int user_token_number_max_ = 303;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
   Parser ::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
    {
      case 52: // item_dec
      case 54: // expr
        value.copy< AST::ASTNode* > (other.value);
        break;

      case 53: // ty
        value.copy< AST::Types > (other.value);
        break;

      case 46: // BOOL
        value.copy< bool > (other.value);
        break;

      case 45: // DOUBLE
        value.copy< double > (other.value);
        break;

      case 44: // INT
        value.copy< long > (other.value);
        break;

      case 47: // IDENTIFIER
      case 48: // STRING
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
    {
      case 52: // item_dec
      case 54: // expr
        value.copy< AST::ASTNode* > (v);
        break;

      case 53: // ty
        value.copy< AST::Types > (v);
        break;

      case 46: // BOOL
        value.copy< bool > (v);
        break;

      case 45: // DOUBLE
        value.copy< double > (v);
        break;

      case 44: // INT
        value.copy< long > (v);
        break;

      case 47: // IDENTIFIER
      case 48: // STRING
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AST::ASTNode* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AST::Types v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const bool v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const double v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const long v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 52: // item_dec
      case 54: // expr
        value.template destroy< AST::ASTNode* > ();
        break;

      case 53: // ty
        value.template destroy< AST::Types > ();
        break;

      case 46: // BOOL
        value.template destroy< bool > ();
        break;

      case 45: // DOUBLE
        value.template destroy< double > ();
        break;

      case 44: // INT
        value.template destroy< long > ();
        break;

      case 47: // IDENTIFIER
      case 48: // STRING
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
   Parser ::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 52: // item_dec
      case 54: // expr
        value.move< AST::ASTNode* > (s.value);
        break;

      case 53: // ty
        value.move< AST::Types > (s.value);
        break;

      case 46: // BOOL
        value.move< bool > (s.value);
        break;

      case 45: // DOUBLE
        value.move< double > (s.value);
        break;

      case 44: // INT
        value.move< long > (s.value);
        break;

      case 47: // IDENTIFIER
      case 48: // STRING
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
   Parser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
   Parser ::by_type::type_get () const
  {
    return type;
  }

  inline
   Parser ::token_type
   Parser ::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
   Parser ::symbol_type
   Parser ::make_EOF ()
  {
    return symbol_type (token::TOKEN_EOF);
  }

   Parser ::symbol_type
   Parser ::make_DEF ()
  {
    return symbol_type (token::TOKEN_DEF);
  }

   Parser ::symbol_type
   Parser ::make_RETURN ()
  {
    return symbol_type (token::TOKEN_RETURN);
  }

   Parser ::symbol_type
   Parser ::make_CLASS ()
  {
    return symbol_type (token::TOKEN_CLASS);
  }

   Parser ::symbol_type
   Parser ::make_PUB ()
  {
    return symbol_type (token::TOKEN_PUB);
  }

   Parser ::symbol_type
   Parser ::make_USE ()
  {
    return symbol_type (token::TOKEN_USE);
  }

   Parser ::symbol_type
   Parser ::make_SELF ()
  {
    return symbol_type (token::TOKEN_SELF);
  }

   Parser ::symbol_type
   Parser ::make_IF ()
  {
    return symbol_type (token::TOKEN_IF);
  }

   Parser ::symbol_type
   Parser ::make_ELSE ()
  {
    return symbol_type (token::TOKEN_ELSE);
  }

   Parser ::symbol_type
   Parser ::make_ELIF ()
  {
    return symbol_type (token::TOKEN_ELIF);
  }

   Parser ::symbol_type
   Parser ::make_SWITCH ()
  {
    return symbol_type (token::TOKEN_SWITCH);
  }

   Parser ::symbol_type
   Parser ::make_CASE ()
  {
    return symbol_type (token::TOKEN_CASE);
  }

   Parser ::symbol_type
   Parser ::make_INTERFACE ()
  {
    return symbol_type (token::TOKEN_INTERFACE);
  }

   Parser ::symbol_type
   Parser ::make_OVERRIDE ()
  {
    return symbol_type (token::TOKEN_OVERRIDE);
  }

   Parser ::symbol_type
   Parser ::make_EXTENDS ()
  {
    return symbol_type (token::TOKEN_EXTENDS);
  }

   Parser ::symbol_type
   Parser ::make_IMPLEMENTS ()
  {
    return symbol_type (token::TOKEN_IMPLEMENTS);
  }

   Parser ::symbol_type
   Parser ::make_TYPE ()
  {
    return symbol_type (token::TOKEN_TYPE);
  }

   Parser ::symbol_type
   Parser ::make_END_STATEMENT ()
  {
    return symbol_type (token::TOKEN_END_STATEMENT);
  }

   Parser ::symbol_type
   Parser ::make_LEFTPAR ()
  {
    return symbol_type (token::TOKEN_LEFTPAR);
  }

   Parser ::symbol_type
   Parser ::make_RIGHTPAR ()
  {
    return symbol_type (token::TOKEN_RIGHTPAR);
  }

   Parser ::symbol_type
   Parser ::make_LEFTBRACE ()
  {
    return symbol_type (token::TOKEN_LEFTBRACE);
  }

   Parser ::symbol_type
   Parser ::make_RIGHTBRACE ()
  {
    return symbol_type (token::TOKEN_RIGHTBRACE);
  }

   Parser ::symbol_type
   Parser ::make_MINUS ()
  {
    return symbol_type (token::TOKEN_MINUS);
  }

   Parser ::symbol_type
   Parser ::make_MINUSEQ ()
  {
    return symbol_type (token::TOKEN_MINUSEQ);
  }

   Parser ::symbol_type
   Parser ::make_PLUS ()
  {
    return symbol_type (token::TOKEN_PLUS);
  }

   Parser ::symbol_type
   Parser ::make_PLUSEQ ()
  {
    return symbol_type (token::TOKEN_PLUSEQ);
  }

   Parser ::symbol_type
   Parser ::make_MUL ()
  {
    return symbol_type (token::TOKEN_MUL);
  }

   Parser ::symbol_type
   Parser ::make_MULEQ ()
  {
    return symbol_type (token::TOKEN_MULEQ);
  }

   Parser ::symbol_type
   Parser ::make_DIV ()
  {
    return symbol_type (token::TOKEN_DIV);
  }

   Parser ::symbol_type
   Parser ::make_DIVEQ ()
  {
    return symbol_type (token::TOKEN_DIVEQ);
  }

   Parser ::symbol_type
   Parser ::make_EQEQ ()
  {
    return symbol_type (token::TOKEN_EQEQ);
  }

   Parser ::symbol_type
   Parser ::make_EQ ()
  {
    return symbol_type (token::TOKEN_EQ);
  }

   Parser ::symbol_type
   Parser ::make_NE ()
  {
    return symbol_type (token::TOKEN_NE);
  }

   Parser ::symbol_type
   Parser ::make_NOT ()
  {
    return symbol_type (token::TOKEN_NOT);
  }

   Parser ::symbol_type
   Parser ::make_LE ()
  {
    return symbol_type (token::TOKEN_LE);
  }

   Parser ::symbol_type
   Parser ::make_LT ()
  {
    return symbol_type (token::TOKEN_LT);
  }

   Parser ::symbol_type
   Parser ::make_GE ()
  {
    return symbol_type (token::TOKEN_GE);
  }

   Parser ::symbol_type
   Parser ::make_GT ()
  {
    return symbol_type (token::TOKEN_GT);
  }

   Parser ::symbol_type
   Parser ::make_ANDAND ()
  {
    return symbol_type (token::TOKEN_ANDAND);
  }

   Parser ::symbol_type
   Parser ::make_AND ()
  {
    return symbol_type (token::TOKEN_AND);
  }

   Parser ::symbol_type
   Parser ::make_OROR ()
  {
    return symbol_type (token::TOKEN_OROR);
  }

   Parser ::symbol_type
   Parser ::make_OR ()
  {
    return symbol_type (token::TOKEN_OR);
  }

   Parser ::symbol_type
   Parser ::make_INT (const long& v)
  {
    return symbol_type (token::TOKEN_INT, v);
  }

   Parser ::symbol_type
   Parser ::make_DOUBLE (const double& v)
  {
    return symbol_type (token::TOKEN_DOUBLE, v);
  }

   Parser ::symbol_type
   Parser ::make_BOOL (const bool& v)
  {
    return symbol_type (token::TOKEN_BOOL, v);
  }

   Parser ::symbol_type
   Parser ::make_IDENTIFIER (const std::string& v)
  {
    return symbol_type (token::TOKEN_IDENTIFIER, v);
  }

   Parser ::symbol_type
   Parser ::make_STRING (const std::string& v)
  {
    return symbol_type (token::TOKEN_STRING, v);
  }


#line 9 "parser.y" // lalr1.cc:377
} //  Ni 
#line 1557 "/home/tom/nilang/src/parsing/parser.hh" // lalr1.cc:377




#endif // !YY_YY_HOME_TOM_NILANG_SRC_PARSING_PARSER_HH_INCLUDED
