// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef ATCCSGUIDESCOPESTATUS_ODB_HXX
#define ATCCSGUIDESCOPESTATUS_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "atccsguidescopestatus.h"

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
  // atccsguidescopestatus
  //
  template <>
  struct class_traits< ::atccsguidescopestatus >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::atccsguidescopestatus >
  {
    public:
    typedef ::atccsguidescopestatus object_type;
    typedef ::atccsguidescopestatus* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef object_traits< ::atccspublicstatus >::id_type id_type;

    static const bool auto_id = object_traits< ::atccspublicstatus >::auto_id;

    static const bool abstract = true;

    static id_type
    id (const object_type&);
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
  // atccsguidescopestatus
  //
  template <typename A>
  struct query_columns< ::atccsguidescopestatus, id_pgsql, A >:
    query_columns< ::atccspublicstatus, id_pgsql, A >
  {
    // atccspublicstatus
    //
    typedef query_columns< ::atccspublicstatus, id_pgsql, A > atccspublicstatus;

    // indexOfCover
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        short unsigned int,
        pgsql::id_smallint >::query_type,
      pgsql::id_smallint >
    indexOfCover_type_;

    static const indexOfCover_type_ indexOfCover;

    // targetIndexeOfCover
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        short unsigned int,
        pgsql::id_smallint >::query_type,
      pgsql::id_smallint >
    targetIndexeOfCover_type_;

    static const targetIndexeOfCover_type_ targetIndexeOfCover;

    // positionOfCover
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    positionOfCover_type_;

    static const positionOfCover_type_ positionOfCover;
  };

  template <typename A>
  const typename query_columns< ::atccsguidescopestatus, id_pgsql, A >::indexOfCover_type_
  query_columns< ::atccsguidescopestatus, id_pgsql, A >::
  indexOfCover (A::table_name, "\"indexOfCover\"", 0);

  template <typename A>
  const typename query_columns< ::atccsguidescopestatus, id_pgsql, A >::targetIndexeOfCover_type_
  query_columns< ::atccsguidescopestatus, id_pgsql, A >::
  targetIndexeOfCover (A::table_name, "\"targetIndexeOfCover\"", 0);

  template <typename A>
  const typename query_columns< ::atccsguidescopestatus, id_pgsql, A >::positionOfCover_type_
  query_columns< ::atccsguidescopestatus, id_pgsql, A >::
  positionOfCover (A::table_name, "\"positionOfCover\"", 0);

  template <typename A>
  struct pointer_query_columns< ::atccsguidescopestatus, id_pgsql, A >:
    query_columns< ::atccsguidescopestatus, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::atccsguidescopestatus, id_pgsql >:
    public access::object_traits< ::atccsguidescopestatus >
  {
    public:
    typedef object_traits_impl< ::atccspublicstatus, id_pgsql >::id_image_type id_image_type;

    struct image_type: object_traits_impl< ::atccspublicstatus, id_pgsql >::image_type
    {
      // _indexOfCover
      //
      short _indexOfCover_value;
      bool _indexOfCover_null;

      // _targetIndexeOfCover
      //
      short _targetIndexeOfCover_value;
      bool _targetIndexeOfCover_null;

      // _positionOfCover
      //
      double _positionOfCover_value;
      bool _positionOfCover_null;
    };

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
  };

  // atccsguidescopestatus
  //
}

#include "atccsguidescopestatus-odb.ixx"

#include <odb/post.hxx>

#endif // ATCCSGUIDESCOPESTATUS_ODB_HXX
