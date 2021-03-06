// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef AT60FILTERSTATUS_ODB_HXX
#define AT60FILTERSTATUS_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "at60filterstatus.h"

#include "atccsfilterstatus-odb.hxx"
#include "atccspublicstatus-odb.hxx"

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
  // at60filterstatus
  //
  template <>
  struct class_traits< ::at60filterstatus >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::at60filterstatus >
  {
    public:
    typedef ::at60filterstatus object_type;
    typedef ::at60filterstatus* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef object_traits< ::atccspublicstatus >::id_type id_type;

    static const bool auto_id = object_traits< ::atccspublicstatus >::auto_id;

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
  // at60filterstatus
  //
  template <typename A>
  struct query_columns< ::at60filterstatus, id_pgsql, A >:
    query_columns< ::atccsfilterstatus, id_pgsql, A >
  {
    // atccsfilterstatus
    //
    typedef query_columns< ::atccsfilterstatus, id_pgsql, A > atccsfilterstatus;
  };

  template <typename A>
  struct pointer_query_columns< ::at60filterstatus, id_pgsql, A >:
    query_columns< ::at60filterstatus, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::at60filterstatus, id_pgsql >:
    public access::object_traits< ::at60filterstatus >
  {
    public:
    typedef object_traits_impl< ::atccspublicstatus, id_pgsql >::id_image_type id_image_type;

    struct image_type: object_traits_impl< ::atccsfilterstatus, id_pgsql >::image_type
    {
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

    static const std::size_t column_count = 11UL;
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
  class access::object_traits_impl< ::at60filterstatus, id_common >:
    public access::object_traits_impl< ::at60filterstatus, id_pgsql >
  {
  };

  // at60filterstatus
  //
}

#include "at60filterstatus-odb.ixx"

#include <odb/post.hxx>

#endif // AT60FILTERSTATUS_ODB_HXX
