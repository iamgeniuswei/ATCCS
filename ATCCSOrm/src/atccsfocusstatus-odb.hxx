// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef ATCCSFOCUSSTATUS_ODB_HXX
#define ATCCSFOCUSSTATUS_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "atccsfocusstatus.h"

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
  // atccsfocusstatus
  //
  template <>
  struct class_traits< ::atccsfocusstatus >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::atccsfocusstatus >
  {
    public:
    typedef ::atccsfocusstatus object_type;
    typedef ::atccsfocusstatus* pointer_type;
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
  // atccsfocusstatus
  //
  template <typename A>
  struct query_columns< ::atccsfocusstatus, id_pgsql, A >:
    query_columns< ::atccspublicstatus, id_pgsql, A >
  {
    // atccspublicstatus
    //
    typedef query_columns< ::atccspublicstatus, id_pgsql, A > atccspublicstatus;

    // isHomed
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        short unsigned int,
        pgsql::id_smallint >::query_type,
      pgsql::id_smallint >
    isHomed_type_;

    static const isHomed_type_ isHomed;

    // isTCompensation
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        short unsigned int,
        pgsql::id_smallint >::query_type,
      pgsql::id_smallint >
    isTCompensation_type_;

    static const isTCompensation_type_ isTCompensation;

    // position
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    position_type_;

    static const position_type_ position;

    // targetPosition
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    targetPosition_type_;

    static const targetPosition_type_ targetPosition;

    // temperature
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    temperature_type_;

    static const temperature_type_ temperature;

    // TCompenensation
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        double,
        pgsql::id_double >::query_type,
      pgsql::id_double >
    TCompenensation_type_;

    static const TCompenensation_type_ TCompenensation;
  };

  template <typename A>
  const typename query_columns< ::atccsfocusstatus, id_pgsql, A >::isHomed_type_
  query_columns< ::atccsfocusstatus, id_pgsql, A >::
  isHomed (A::table_name, "\"isHomed\"", 0);

  template <typename A>
  const typename query_columns< ::atccsfocusstatus, id_pgsql, A >::isTCompensation_type_
  query_columns< ::atccsfocusstatus, id_pgsql, A >::
  isTCompensation (A::table_name, "\"isTCompensation\"", 0);

  template <typename A>
  const typename query_columns< ::atccsfocusstatus, id_pgsql, A >::position_type_
  query_columns< ::atccsfocusstatus, id_pgsql, A >::
  position (A::table_name, "\"position\"", 0);

  template <typename A>
  const typename query_columns< ::atccsfocusstatus, id_pgsql, A >::targetPosition_type_
  query_columns< ::atccsfocusstatus, id_pgsql, A >::
  targetPosition (A::table_name, "\"targetPosition\"", 0);

  template <typename A>
  const typename query_columns< ::atccsfocusstatus, id_pgsql, A >::temperature_type_
  query_columns< ::atccsfocusstatus, id_pgsql, A >::
  temperature (A::table_name, "\"temperature\"", 0);

  template <typename A>
  const typename query_columns< ::atccsfocusstatus, id_pgsql, A >::TCompenensation_type_
  query_columns< ::atccsfocusstatus, id_pgsql, A >::
  TCompenensation (A::table_name, "\"TCompenensation\"", 0);

  template <typename A>
  struct pointer_query_columns< ::atccsfocusstatus, id_pgsql, A >:
    query_columns< ::atccsfocusstatus, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::atccsfocusstatus, id_pgsql >:
    public access::object_traits< ::atccsfocusstatus >
  {
    public:
    typedef object_traits_impl< ::atccspublicstatus, id_pgsql >::id_image_type id_image_type;

    struct image_type: object_traits_impl< ::atccspublicstatus, id_pgsql >::image_type
    {
      // _isHomed
      //
      short _isHomed_value;
      bool _isHomed_null;

      // _isTCompensation
      //
      short _isTCompensation_value;
      bool _isTCompensation_null;

      // _position
      //
      double _position_value;
      bool _position_null;

      // _targetPosition
      //
      double _targetPosition_value;
      bool _targetPosition_null;

      // _temperature
      //
      double _temperature_value;
      bool _temperature_null;

      // _TCompenensation
      //
      double _TCompenensation_value;
      bool _TCompenensation_null;
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

  // atccsfocusstatus
  //
}

#include "atccsfocusstatus-odb.ixx"

#include <odb/post.hxx>

#endif // ATCCSFOCUSSTATUS_ODB_HXX
