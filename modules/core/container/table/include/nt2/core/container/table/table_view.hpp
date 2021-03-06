//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_TABLE_TABLE_VIEW_HPP_INCLUDED
#define NT2_CORE_CONTAINER_TABLE_TABLE_VIEW_HPP_INCLUDED

#include <nt2/core/container/dsl/forward.hpp>
#include <nt2/sdk/memory/container_ref.hpp>
#include <nt2/sdk/memory/container_shared_ref.hpp>
#include <boost/dispatch/dsl/semantic_of.hpp>

namespace nt2 { namespace container
{
  /* table_view; an expression of a container_ref terminal.
   * allows construction from an expression of a container terminal */
  template<class T, class S = nt2::settings()>
  struct table_view
       : expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container_ref<T, S> >, 0l >
                   , memory::container<T, S>&
                   >
  {
    typedef memory::container_ref<T, S> container_ref;
    typedef boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term<container_ref>, 0l > basic_expr;
    typedef memory::container<T, S>& semantic;
    typedef expression<basic_expr, semantic> nt2_expression;

    typedef typename container_ref::iterator iterator;
    typedef typename container_ref::const_iterator const_iterator;

    iterator begin() const
    {
      return boost::proto::value(*this).begin();
    }

    iterator end() const
    {
      return boost::proto::value(*this).end();
    }

    BOOST_FORCEINLINE
    table_view()
    {
    }

    BOOST_FORCEINLINE
    table_view( nt2_expression const& expr )
              : nt2_expression(expr)
    {
    }

    BOOST_FORCEINLINE
    table_view( expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container<T, S> >, 0l >
                          , memory::container<T, S>
                          > & expr
              )
              : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    BOOST_FORCEINLINE
    table_view( expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container<T, S>& >, 0l >
                          , memory::container<T, S>&
                          > const& expr
              )
              : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    template<class S2>
    BOOST_FORCEINLINE
    table_view( table_view<T, S2> const& expr )
              : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    using nt2_expression::operator=;
  };

  template<class T, class S>
  struct table_view<T const, S>
       : expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container_ref<T const, S> >, 0l >
                   , memory::container<T, S> const&
                   >
  {
    typedef memory::container_ref<T const, S> container_ref;
    typedef boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term<container_ref>, 0l > basic_expr;
    typedef memory::container<T, S> const& semantic;
    typedef expression<basic_expr, semantic> nt2_expression;

    typedef typename container_ref::iterator iterator;
    typedef typename container_ref::const_iterator const_iterator;

    iterator begin() const
    {
      return boost::proto::value(*this).begin();
    }

    iterator end() const
    {
      return boost::proto::value(*this).end();
    }

    BOOST_FORCEINLINE
    table_view()
    {
    }

    BOOST_FORCEINLINE
    table_view( nt2_expression const& expr )
              : nt2_expression(expr)
    {
    }

    BOOST_FORCEINLINE
    table_view( expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container<T, S> >, 0l >
                          , memory::container<T, S>
                          > const& expr
              )
              : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    BOOST_FORCEINLINE
    table_view( expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container<T, S> const& >, 0l >
                          , memory::container<T, S> const&
                          > const& expr
              )
              : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    template<class U, class S2>
    BOOST_FORCEINLINE
    table_view( table_view<U, S2> const& expr )
              : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    using nt2_expression::operator=;
  };

  /* table_shared_view; an expression of a container_shared_ref terminal.
   * allows construction from an expression of a container_shared_ref terminal */
  template<class T, class S = nt2::settings()>
  struct table_shared_view
       : expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container_shared_ref< T, S, false > >, 0l >
                   , memory::container<T, S>&
                   >
  {
    typedef memory::container_shared_ref< T, S, false > container_ref;
    typedef boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term<container_ref>, 0l > basic_expr;
    typedef memory::container<T, S>& semantic;
    typedef expression<basic_expr, semantic> nt2_expression;

    typedef typename container_ref::iterator iterator;
    typedef typename container_ref::const_iterator const_iterator;

    iterator begin() const
    {
      return boost::proto::value(*this).begin();
    }

    iterator end() const
    {
      return boost::proto::value(*this).end();
    }

    BOOST_FORCEINLINE
    table_shared_view()
    {
    }

    BOOST_FORCEINLINE
    table_shared_view( nt2_expression const& expr )
                     : nt2_expression(expr)
    {
    }

    template<class S2, bool Own>
    BOOST_FORCEINLINE
    table_shared_view( expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container_shared_ref< T, S2, Own > >, 0l >
                                 , memory::container<T, S2>&
                                 > const& expr
                     )
                     : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    using nt2_expression::operator=;
  };

  template<class T, class S>
  struct table_shared_view<T const, S>
       : expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container_shared_ref< T const, S, false > >, 0l >
                   , memory::container<T, S> const&
                   >
  {
    typedef memory::container_shared_ref< T const, S, false > container_ref;
    typedef boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term<container_ref>, 0l > basic_expr;
    typedef memory::container<T, S> const& semantic;
    typedef expression<basic_expr, semantic> nt2_expression;

    typedef typename container_ref::iterator iterator;
    typedef typename container_ref::const_iterator const_iterator;

    iterator begin() const
    {
      return boost::proto::value(*this).begin();
    }

    iterator end() const
    {
      return boost::proto::value(*this).end();
    }

    BOOST_FORCEINLINE
    table_shared_view()
    {
    }

    BOOST_FORCEINLINE
    table_shared_view( nt2_expression const& expr )
                     : nt2_expression(expr)
    {
    }

    template<class U, class S2, bool Own>
    BOOST_FORCEINLINE
    table_shared_view( expression< boost::proto::basic_expr< boost::proto::tag::terminal, boost::proto::term< memory::container_shared_ref< U, S2, Own > >, 0l >
                                 , memory::container<U, S2> /*const?*/&
                                 > const& expr
                     )
                     : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    using nt2_expression::operator=;
  };

} }

namespace boost { namespace dispatch { namespace meta
{
  template<class T, class S>
  struct semantic_of< nt2::container::table_view<T, S> >
  {
    typedef typename nt2::container::table_view<T, S>::semantic type;
  };

  template<class T, class S>
  struct semantic_of< nt2::container::table_shared_view<T, S> >
  {
    typedef typename nt2::container::table_shared_view<T, S>::semantic type;
  };
} } }

namespace nt2
{
  using nt2::container::table_view;
  using nt2::container::table_shared_view;
}

#endif
