// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

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
// //                    "%code top" blocks.
#line 39 "parser.y" // lalr1.cc:397

	# ifndef YY_NULLPTR
	#  if defined __cplusplus && 201103L <= __cplusplus
	#   define YY_NULLPTR nullptr
	#  else
	#   define YY_NULLPTR 0
	#  endif
	# endif
	#include <iostream>
	#include "parsing/lexer.h"
	#include "parser.hh"
	static Ni::Parser::symbol_type yylex(Ni::Lexer &lexer, Ni::Driver &driver) {
		return lexer.get_next_token();
	}
	
	static bool visit = true;
	static AST::BlockNode* ext_blk(AST::BlockNode* node, AST::ASTNode* ext)
	{	
		node->Extend(ext);
		return node;
	}
	
	static AST::ArgsNode* ext_args(AST::ArgsNode* args, AST::ArgNode* arg)
	{
		args->Extend(arg);
		return args;
	}

	using namespace Ni;

#line 65 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:397


// First part of user declarations.

#line 70 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 84 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "parser.y" // lalr1.cc:479
namespace  Ni  {
#line 170 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
   Parser :: Parser  (Ni::Lexer &lexer_yyarg, Ni::Visitor &visitor_yyarg, Ni::Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      visitor (visitor_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
   Parser ::by_state::by_state ()
    : state (empty_state)
  {}

  inline
   Parser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   Parser ::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
   Parser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   Parser ::symbol_number_type
   Parser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
   Parser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   Parser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 56: // args
      case 60: // block_item
      case 63: // expr
      case 64: // term
      case 65: // factor
      case 66: // litnum
      case 67: // lit
        value.move< AST::ASTNode* > (that.value);
        break;

      case 58: // block
      case 59: // block_items
        value.move< AST::BlockNode* > (that.value);
        break;

      case 53: // item_dec
        value.move< AST::DeclarationNode* > (that.value);
        break;

      case 55: // fn
        value.move< AST::FunctionNode* > (that.value);
        break;

      case 61: // return
        value.move< AST::ReturnNode* > (that.value);
        break;

      case 54: // ty
        value.move< AST::Types > (that.value);
        break;

      case 62: // var
        value.move< AST::VarNode* > (that.value);
        break;

      case 46: // BOOL
        value.move< bool > (that.value);
        break;

      case 45: // DOUBLE
        value.move< double > (that.value);
        break;

      case 44: // INT
        value.move< long > (that.value);
        break;

      case 47: // IDENTIFIER
      case 48: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 56: // args
      case 60: // block_item
      case 63: // expr
      case 64: // term
      case 65: // factor
      case 66: // litnum
      case 67: // lit
        value.copy< AST::ASTNode* > (that.value);
        break;

      case 58: // block
      case 59: // block_items
        value.copy< AST::BlockNode* > (that.value);
        break;

      case 53: // item_dec
        value.copy< AST::DeclarationNode* > (that.value);
        break;

      case 55: // fn
        value.copy< AST::FunctionNode* > (that.value);
        break;

      case 61: // return
        value.copy< AST::ReturnNode* > (that.value);
        break;

      case 54: // ty
        value.copy< AST::Types > (that.value);
        break;

      case 62: // var
        value.copy< AST::VarNode* > (that.value);
        break;

      case 46: // BOOL
        value.copy< bool > (that.value);
        break;

      case 45: // DOUBLE
        value.copy< double > (that.value);
        break;

      case 44: // INT
        value.copy< long > (that.value);
        break;

      case 47: // IDENTIFIER
      case 48: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   Parser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   Parser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   Parser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (lexer, driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 56: // args
      case 60: // block_item
      case 63: // expr
      case 64: // term
      case 65: // factor
      case 66: // litnum
      case 67: // lit
        yylhs.value.build< AST::ASTNode* > ();
        break;

      case 58: // block
      case 59: // block_items
        yylhs.value.build< AST::BlockNode* > ();
        break;

      case 53: // item_dec
        yylhs.value.build< AST::DeclarationNode* > ();
        break;

      case 55: // fn
        yylhs.value.build< AST::FunctionNode* > ();
        break;

      case 61: // return
        yylhs.value.build< AST::ReturnNode* > ();
        break;

      case 54: // ty
        yylhs.value.build< AST::Types > ();
        break;

      case 62: // var
        yylhs.value.build< AST::VarNode* > ();
        break;

      case 46: // BOOL
        yylhs.value.build< bool > ();
        break;

      case 45: // DOUBLE
        yylhs.value.build< double > ();
        break;

      case 44: // INT
        yylhs.value.build< long > ();
        break;

      case 47: // IDENTIFIER
      case 48: // STRING
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 6:
#line 162 "parser.y" // lalr1.cc:859
    { yystack_[0].value.as< AST::DeclarationNode* > ()->global = true; visitor.Visit(yystack_[0].value.as< AST::DeclarationNode* > (), visit);}
#line 703 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 167 "parser.y" // lalr1.cc:859
    {yylhs.value.as< AST::DeclarationNode* > () = new AST::DeclarationNode(yystack_[4].value.as< AST::Types > (), yystack_[3].value.as< std::string > (), yystack_[1].value.as< AST::ASTNode* > ()); }
#line 709 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 171 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::Types > () = AST::StringToType(yystack_[0].value.as< std::string > ()); }
#line 715 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 175 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::FunctionNode* > () = new AST::FunctionNode(true, yystack_[4].value.as< std::string > (), yystack_[5].value.as< AST::Types > (), yystack_[2].value.as< AST::ASTNode* > (), yystack_[0].value.as< AST::BlockNode* > ()); }
#line 721 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 176 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::FunctionNode* > () = new AST::FunctionNode(false, yystack_[4].value.as< std::string > (), yystack_[5].value.as< AST::Types > (), yystack_[2].value.as< AST::ASTNode* > (), yystack_[0].value.as< AST::BlockNode* > ()); }
#line 727 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 180 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = nullptr; }
#line 733 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 181 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = nullptr; }
#line 739 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 189 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::BlockNode* > () = yystack_[0].value.as< AST::BlockNode* > (); }
#line 745 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 193 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::BlockNode* > () = new AST::BlockNode(yystack_[0].value.as< AST::ASTNode* > ()); }
#line 751 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 194 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::BlockNode* > () = ext_blk(yystack_[1].value.as< AST::BlockNode* > (), yystack_[0].value.as< AST::ASTNode* > ()); }
#line 757 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 199 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[0].value.as< AST::DeclarationNode* > (); }
#line 763 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 200 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[0].value.as< AST::ReturnNode* > (); }
#line 769 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 201 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::BlockNode(new AST::IntNode(10)); }
#line 775 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 205 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ReturnNode* > () = new ReturnNode(yystack_[1].value.as< AST::ASTNode* > ()); }
#line 781 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 206 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ReturnNode* > () = new ReturnNode(yystack_[1].value.as< AST::VarNode* > ()); }
#line 787 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 210 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::VarNode* > () = new VarNode(yystack_[0].value.as< std::string > ()); }
#line 793 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 215 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::BinOpNode("+", yystack_[2].value.as< AST::ASTNode* > (), yystack_[0].value.as< AST::ASTNode* > ()); }
#line 799 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 216 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::BinOpNode("-", yystack_[2].value.as< AST::ASTNode* > (), yystack_[0].value.as< AST::ASTNode* > ()); }
#line 805 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 217 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[0].value.as< AST::ASTNode* > (); }
#line 811 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 218 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[0].value.as< AST::ASTNode* > (); }
#line 817 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 222 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::BinOpNode("*", yystack_[2].value.as< AST::ASTNode* > (), yystack_[0].value.as< AST::ASTNode* > ()); }
#line 823 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 223 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::BinOpNode("/", yystack_[2].value.as< AST::ASTNode* > (), yystack_[0].value.as< AST::ASTNode* > ()); }
#line 829 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 224 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[0].value.as< AST::ASTNode* > (); }
#line 835 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 229 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[1].value.as< AST::ASTNode* > (); }
#line 841 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 230 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[0].value.as< AST::ASTNode* > (); }
#line 847 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 231 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = yystack_[0].value.as< AST::ASTNode* > (); }
#line 853 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 235 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::IntNode(yystack_[0].value.as< long > ());}
#line 859 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 236 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::DoubleNode(yystack_[0].value.as< double > ()); }
#line 865 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 243 "parser.y" // lalr1.cc:859
    { 
	yystack_[0].value.as< std::string > ().erase(0, 1);
	yystack_[0].value.as< std::string > ().erase(yystack_[0].value.as< std::string > ().size() -1);
	yylhs.value.as< AST::ASTNode* > () = new AST::StringNode(yystack_[0].value.as< std::string > ()); 
}
#line 875 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 248 "parser.y" // lalr1.cc:859
    { yylhs.value.as< AST::ASTNode* > () = new AST::BoolNode(yystack_[0].value.as< bool > ()); }
#line 881 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
    break;


#line 885 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  Parser ::yypact_ninf_ = -41;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
       0,   -41,   -15,     4,   -41,    43,    -2,   -41,   -41,    -1,
     -41,     9,   -15,   -41,   -41,    21,    37,    11,     7,   -15,
      39,     7,   -11,   -41,   -41,   -41,   -41,    -5,    14,   -41,
     -41,   -41,    13,    40,   -41,   -15,     2,   -41,   -41,   -11,
     -11,   -11,   -11,   -41,    41,    44,   -41,    14,    14,   -41,
     -41,     1,   -41,    41,    -8,   -41,   -41,     1,   -41,   -41,
     -41,   -41,    45,    -4,   -41,   -41,   -41
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     5,     0,     0,     9,     0,     2,     3,     6,     0,
       7,     0,     0,     1,     4,     0,     0,     0,     0,    13,
       0,     0,     0,    34,    35,    37,    36,     0,    26,    30,
      33,    27,     0,     0,    12,    13,     0,    32,     8,     0,
       0,     0,     0,    14,     0,     0,    31,    25,    24,    28,
      29,     0,    11,     0,     0,    20,    18,    15,    16,    19,
      10,    23,     0,     0,    17,    22,    21
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -41,   -41,   -41,    56,   -40,     6,   -41,    31,   -41,    15,
     -41,    12,   -41,   -41,   -19,    10,   -12,   -41,   -41
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     5,     6,     7,     8,     9,    10,    33,    34,    52,
      57,    58,    59,    62,    27,    28,    29,    30,    31
  };

  const unsigned char
   Parser ::yytable_[] =
  {
       1,     2,    36,     2,     3,    54,     3,    12,    11,    21,
      37,    56,    21,    22,    38,    66,    22,    56,    17,    39,
      39,    40,    40,    46,    55,    32,    39,    21,    40,    49,
      50,    22,     4,    23,    24,    63,    23,    24,    25,    61,
      26,    32,    41,    13,    42,     4,    15,     4,     4,    47,
      48,    23,    24,    25,    18,    26,    16,    19,    20,    35,
      43,    44,    14,    51,    65,    53,    45,     0,    60,    64
  };

  const signed char
   Parser ::yycheck_[] =
  {
       0,     3,    21,     3,     6,     4,     6,     3,     2,    20,
      22,    51,    20,    24,    19,    19,    24,    57,    12,    24,
      24,    26,    26,    21,    23,    19,    24,    20,    26,    41,
      42,    24,    47,    44,    45,    54,    44,    45,    46,    47,
      48,    35,    28,     0,    30,    47,    47,    47,    47,    39,
      40,    44,    45,    46,    33,    48,    47,    20,    47,    20,
      47,    21,     6,    22,    19,    21,    35,    -1,    53,    57
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     0,     3,     6,    47,    50,    51,    52,    53,    54,
      55,    54,     3,     0,    52,    47,    47,    54,    33,    20,
      47,    20,    24,    44,    45,    46,    48,    63,    64,    65,
      66,    67,    54,    56,    57,    20,    63,    65,    19,    24,
      26,    28,    30,    47,    21,    56,    21,    64,    64,    65,
      65,    22,    58,    21,     4,    23,    53,    59,    60,    61,
      58,    47,    62,    63,    60,    19,    19
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    49,    50,    51,    51,    51,    52,    52,    53,    54,
      55,    55,    56,    56,    57,    58,    59,    59,    60,    60,
      60,    61,    61,    62,    63,    63,    63,    63,    64,    64,
      64,    65,    65,    65,    66,    66,    67,    67
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     5,     1,
       8,     7,     1,     0,     2,     2,     1,     2,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     1,     3,     3,
       1,     3,     2,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "EOF", "error", "$undefined", "DEF", "RETURN", "CLASS", "PUB", "USE",
  "SELF", "IF", "ELSE", "ELIF", "SWITCH", "CASE", "INTERFACE", "OVERRIDE",
  "EXTENDS", "IMPLEMENTS", "TYPE", "END_STATEMENT", "LEFTPAR", "RIGHTPAR",
  "LEFTBRACE", "RIGHTBRACE", "MINUS", "MINUSEQ", "PLUS", "PLUSEQ", "MUL",
  "MULEQ", "DIV", "DIVEQ", "EQEQ", "EQ", "NE", "NOT", "LE", "LT", "GE",
  "GT", "ANDAND", "AND", "OROR", "OR", "INT", "DOUBLE", "BOOL",
  "IDENTIFIER", "STRING", "$accept", "program", "items", "item",
  "item_dec", "ty", "fn", "args", "arg", "block", "block_items",
  "block_item", "return", "var", "expr", "term", "factor", "litnum", "lit", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,   151,   151,   155,   156,   157,   162,   163,   167,   171,
     175,   176,   180,   181,   185,   189,   193,   194,   199,   200,
     201,   205,   206,   210,   215,   216,   217,   218,   222,   223,
     224,   229,   230,   231,   235,   236,   242,   248
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 9 "parser.y" // lalr1.cc:1167
} //  Ni 
#line 1296 "/home/tom/nilang/src/parsing/parser.cc" // lalr1.cc:1167
#line 250 "parser.y" // lalr1.cc:1168


#include "driver/rang.hpp"
void Ni::Parser::error(const location &loc, const std::string &message)
{
	cerr << rang::style::bold << rang::fg::red << "error: " << rang::style::reset << message << rang::style::bold << rang::fg::red <<  " at " << rang::style::reset << loc << endl;
}
