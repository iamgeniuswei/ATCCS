// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "atccsfocusstatus-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/transaction.hxx>
#include <odb/pgsql/connection.hxx>
#include <odb/pgsql/statement.hxx>
#include <odb/pgsql/statement-cache.hxx>
#include <odb/pgsql/simple-object-statements.hxx>
#include <odb/pgsql/container-statements.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/pgsql/simple-object-result.hxx>

namespace odb
{
  // atccsfocusstatus
  //

  bool access::object_traits_impl< ::atccsfocusstatus, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // atccspublicstatus base
    //
    if (object_traits_impl< ::atccspublicstatus, id_pgsql >::grow (
          i, t + 0UL))
      grew = true;

    // _isHomed
    //
    t[8UL] = 0;

    // _isTCompensation
    //
    t[9UL] = 0;

    // _position
    //
    t[10UL] = 0;

    // _targetPosition
    //
    t[11UL] = 0;

    // _temperature
    //
    t[12UL] = 0;

    // _TCompenensation
    //
    t[13UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::atccsfocusstatus, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // atccspublicstatus base
    //
    object_traits_impl< ::atccspublicstatus, id_pgsql >::bind (b + n, i, sk);
    n += sk == statement_select ? 8UL : 7UL;

    // _isHomed
    //
    b[n].type = pgsql::bind::smallint;
    b[n].buffer = &i._isHomed_value;
    b[n].is_null = &i._isHomed_null;
    n++;

    // _isTCompensation
    //
    b[n].type = pgsql::bind::smallint;
    b[n].buffer = &i._isTCompensation_value;
    b[n].is_null = &i._isTCompensation_null;
    n++;

    // _position
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._position_value;
    b[n].is_null = &i._position_null;
    n++;

    // _targetPosition
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._targetPosition_value;
    b[n].is_null = &i._targetPosition_null;
    n++;

    // _temperature
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._temperature_value;
    b[n].is_null = &i._temperature_null;
    n++;

    // _TCompenensation
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._TCompenensation_value;
    b[n].is_null = &i._TCompenensation_null;
    n++;
  }

  bool access::object_traits_impl< ::atccsfocusstatus, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // atccspublicstatus base
    //
    if (object_traits_impl< ::atccspublicstatus, id_pgsql >::init (i, o, sk))
      grew = true;

    // _isHomed
    //
    {
      short unsigned int const& v =
        o._isHomed;

      bool is_null (false);
      pgsql::value_traits<
          short unsigned int,
          pgsql::id_smallint >::set_image (
        i._isHomed_value, is_null, v);
      i._isHomed_null = is_null;
    }

    // _isTCompensation
    //
    {
      short unsigned int const& v =
        o._isTCompensation;

      bool is_null (false);
      pgsql::value_traits<
          short unsigned int,
          pgsql::id_smallint >::set_image (
        i._isTCompensation_value, is_null, v);
      i._isTCompensation_null = is_null;
    }

    // _position
    //
    {
      double const& v =
        o._position;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._position_value, is_null, v);
      i._position_null = is_null;
    }

    // _targetPosition
    //
    {
      double const& v =
        o._targetPosition;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._targetPosition_value, is_null, v);
      i._targetPosition_null = is_null;
    }

    // _temperature
    //
    {
      double const& v =
        o._temperature;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._temperature_value, is_null, v);
      i._temperature_null = is_null;
    }

    // _TCompenensation
    //
    {
      double const& v =
        o._TCompenensation;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._TCompenensation_value, is_null, v);
      i._TCompenensation_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::atccsfocusstatus, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // atccspublicstatus base
    //
    object_traits_impl< ::atccspublicstatus, id_pgsql >::init (o, i, db);

    // _isHomed
    //
    {
      short unsigned int& v =
        o._isHomed;

      pgsql::value_traits<
          short unsigned int,
          pgsql::id_smallint >::set_value (
        v,
        i._isHomed_value,
        i._isHomed_null);
    }

    // _isTCompensation
    //
    {
      short unsigned int& v =
        o._isTCompensation;

      pgsql::value_traits<
          short unsigned int,
          pgsql::id_smallint >::set_value (
        v,
        i._isTCompensation_value,
        i._isTCompensation_null);
    }

    // _position
    //
    {
      double& v =
        o._position;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._position_value,
        i._position_null);
    }

    // _targetPosition
    //
    {
      double& v =
        o._targetPosition;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._targetPosition_value,
        i._targetPosition_null);
    }

    // _temperature
    //
    {
      double& v =
        o._temperature;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._temperature_value,
        i._temperature_null);
    }

    // _TCompenensation
    //
    {
      double& v =
        o._TCompenensation;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._TCompenensation_value,
        i._TCompenensation_null);
    }
  }
}

#include <odb/post.hxx>
