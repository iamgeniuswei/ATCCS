// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef ATCCSPLAN_ODB_HXX
#define ATCCSPLAN_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "atccsplan.h"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // atccsplan
  //
  template <>
  struct class_traits< ::atccsplan >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::atccsplan >
  {
    public:
    typedef ::atccsplan object_type;
    typedef ::atccsplan* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // atccsplan
  //
  template <typename A>
  struct query_columns< ::atccsplan, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    id_type_;

    static const id_type_ id;

    // user
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    user_type_;

    static const user_type_ user;

    // project
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    project_type_;

    static const project_type_ project;

    // target
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    target_type_;

    static const target_type_ target;

    // filter
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    filter_type_;

    static const filter_type_ filter;

    // sec
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    sec_type_;

    static const sec_type_ sec;

    // msec
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    msec_type_;

    static const msec_type_ msec;

    // result
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    result_type_;

    static const result_type_ result;

    // percent
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    percent_type_;

    static const percent_type_ percent;

    // at
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    at_type_;

    static const at_type_ at;

    // type
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    type_type_;

    static const type_type_ type;

    // epoch
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    epoch_type_;

    static const epoch_type_ epoch;

    // exposureCount
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    exposureCount_type_;

    static const exposureCount_type_ exposureCount;

    // gain
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    gain_type_;

    static const gain_type_ gain;

    // bin
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    bin_type_;

    static const bin_type_ bin;

    // readout
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        unsigned int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    readout_type_;

    static const readout_type_ readout;

    // exposureTime
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    exposureTime_type_;

    static const exposureTime_type_ exposureTime;

    // rightAscension
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    rightAscension_type_;

    static const rightAscension_type_ rightAscension;

    // declination
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    declination_type_;

    static const declination_type_ declination;

    // delayTime
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    delayTime_type_;

    static const delayTime_type_ delayTime;
  };

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::id_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::user_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  user (A::table_name, "\"user\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::project_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  project (A::table_name, "\"project\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::target_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  target (A::table_name, "\"target\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::filter_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  filter (A::table_name, "\"filter\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::sec_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  sec (A::table_name, "\"sec\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::msec_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  msec (A::table_name, "\"msec\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::result_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  result (A::table_name, "\"result\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::percent_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  percent (A::table_name, "\"percent\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::at_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  at (A::table_name, "\"at\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::type_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  type (A::table_name, "\"type\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::epoch_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  epoch (A::table_name, "\"epoch\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::exposureCount_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  exposureCount (A::table_name, "\"exposureCount\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::gain_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  gain (A::table_name, "\"gain\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::bin_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  bin (A::table_name, "\"bin\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::readout_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  readout (A::table_name, "\"readout\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::exposureTime_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  exposureTime (A::table_name, "\"exposureTime\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::rightAscension_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  rightAscension (A::table_name, "\"rightAscension\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::declination_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  declination (A::table_name, "\"declination\"", 0);

  template <typename A>
  const typename query_columns< ::atccsplan, id_pgsql, A >::delayTime_type_
  query_columns< ::atccsplan, id_pgsql, A >::
  delayTime (A::table_name, "\"delayTime\"", 0);

  template <typename A>
  struct pointer_query_columns< ::atccsplan, id_pgsql, A >:
    query_columns< ::atccsplan, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::atccsplan, id_pgsql >:
    public access::object_traits< ::atccsplan >
  {
    public:
    struct id_image_type
    {
      int id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // _id
      //
      int _id_value;
      bool _id_null;

      // _user
      //
      int _user_value;
      bool _user_null;

      // _project
      //
      details::buffer _project_value;
      std::size_t _project_size;
      bool _project_null;

      // _target
      //
      details::buffer _target_value;
      std::size_t _target_size;
      bool _target_null;

      // _filter
      //
      details::buffer _filter_value;
      std::size_t _filter_size;
      bool _filter_null;

      // _sec
      //
      int _sec_value;
      bool _sec_null;

      // _msec
      //
      int _msec_value;
      bool _msec_null;

      // _result
      //
      int _result_value;
      bool _result_null;

      // _percent
      //
      int _percent_value;
      bool _percent_null;

      // _at
      //
      int _at_value;
      bool _at_null;

      // _type
      //
      int _type_value;
      bool _type_null;

      // _epoch
      //
      int _epoch_value;
      bool _epoch_null;

      // _exposureCount
      //
      int _exposureCount_value;
      bool _exposureCount_null;

      // _gain
      //
      int _gain_value;
      bool _gain_null;

      // _bin
      //
      int _bin_value;
      bool _bin_null;

      // _readout
      //
      int _readout_value;
      bool _readout_null;

      // _exposureTime
      //
      double _exposureTime_value;
      bool _exposureTime_null;

      // _rightAscension
      //
      double _rightAscension_value;
      bool _rightAscension_null;

      // _declination
      //
      double _declination_value;
      bool _declination_null;

      // _delayTime
      //
      double _delayTime_value;
      bool _delayTime_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 20UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::atccsplan, id_common >:
    public access::object_traits_impl< ::atccsplan, id_pgsql >
  {
  };

  // atccsplan
  //
}

#include "atccsplan-odb.ixx"

#include <odb/post.hxx>

#endif // ATCCSPLAN_ODB_HXX
