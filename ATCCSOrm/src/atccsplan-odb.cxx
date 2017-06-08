// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "atccsplan-odb.hxx"

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
  // atccsplan
  //

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::
  persist_statement_name[] = "persist_atccsplan";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::
  find_statement_name[] = "find_atccsplan";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::
  update_statement_name[] = "update_atccsplan";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::
  erase_statement_name[] = "erase_atccsplan";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::
  query_statement_name[] = "query_atccsplan";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::
  erase_query_statement_name[] = "erase_query_atccsplan";

  const unsigned int access::object_traits_impl< ::atccsplan, id_pgsql >::
  persist_statement_types[] =
  {
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid
  };

  const unsigned int access::object_traits_impl< ::atccsplan, id_pgsql >::
  find_statement_types[] =
  {
    pgsql::int4_oid
  };

  const unsigned int access::object_traits_impl< ::atccsplan, id_pgsql >::
  update_statement_types[] =
  {
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::int4_oid
  };

  struct access::object_traits_impl< ::atccsplan, id_pgsql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      pgsql::connection&,
      image_type&,
      id_image_type&,
      pgsql::binding&,
      pgsql::binding&,
      pgsql::native_binding&,
      const unsigned int*)
    {
    }
  };

  access::object_traits_impl< ::atccsplan, id_pgsql >::id_type
  access::object_traits_impl< ::atccsplan, id_pgsql >::
  id (const id_image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::atccsplan, id_pgsql >::id_type
  access::object_traits_impl< ::atccsplan, id_pgsql >::
  id (const image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        id,
        i._id_value,
        i._id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::atccsplan, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // _id
    //
    t[0UL] = 0;

    // _user
    //
    if (t[1UL])
    {
      i._user_value.capacity (i._user_size);
      grew = true;
    }

    // _project
    //
    if (t[2UL])
    {
      i._project_value.capacity (i._project_size);
      grew = true;
    }

    // _target
    //
    if (t[3UL])
    {
      i._target_value.capacity (i._target_size);
      grew = true;
    }

    // _filter
    //
    if (t[4UL])
    {
      i._filter_value.capacity (i._filter_size);
      grew = true;
    }

    // _sec
    //
    t[5UL] = 0;

    // _msec
    //
    t[6UL] = 0;

    // _result
    //
    t[7UL] = 0;

    // _percent
    //
    t[8UL] = 0;

    // _at
    //
    t[9UL] = 0;

    // _type
    //
    t[10UL] = 0;

    // _epoch
    //
    t[11UL] = 0;

    // _exposureCount
    //
    t[12UL] = 0;

    // _gain
    //
    t[13UL] = 0;

    // _bin
    //
    t[14UL] = 0;

    // _readout
    //
    t[15UL] = 0;

    // _exposureTime
    //
    t[16UL] = 0;

    // _rightAscension
    //
    t[17UL] = 0;

    // _declination
    //
    t[18UL] = 0;

    // _delayTime
    //
    t[19UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::atccsplan, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // _id
    //
    if (sk != statement_insert && sk != statement_update)
    {
      b[n].type = pgsql::bind::integer;
      b[n].buffer = &i._id_value;
      b[n].is_null = &i._id_null;
      n++;
    }

    // _user
    //
    b[n].type = pgsql::bind::text;
    b[n].buffer = i._user_value.data ();
    b[n].capacity = i._user_value.capacity ();
    b[n].size = &i._user_size;
    b[n].is_null = &i._user_null;
    n++;

    // _project
    //
    b[n].type = pgsql::bind::text;
    b[n].buffer = i._project_value.data ();
    b[n].capacity = i._project_value.capacity ();
    b[n].size = &i._project_size;
    b[n].is_null = &i._project_null;
    n++;

    // _target
    //
    b[n].type = pgsql::bind::text;
    b[n].buffer = i._target_value.data ();
    b[n].capacity = i._target_value.capacity ();
    b[n].size = &i._target_size;
    b[n].is_null = &i._target_null;
    n++;

    // _filter
    //
    b[n].type = pgsql::bind::text;
    b[n].buffer = i._filter_value.data ();
    b[n].capacity = i._filter_value.capacity ();
    b[n].size = &i._filter_size;
    b[n].is_null = &i._filter_null;
    n++;

    // _sec
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._sec_value;
    b[n].is_null = &i._sec_null;
    n++;

    // _msec
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._msec_value;
    b[n].is_null = &i._msec_null;
    n++;

    // _result
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._result_value;
    b[n].is_null = &i._result_null;
    n++;

    // _percent
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._percent_value;
    b[n].is_null = &i._percent_null;
    n++;

    // _at
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._at_value;
    b[n].is_null = &i._at_null;
    n++;

    // _type
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._type_value;
    b[n].is_null = &i._type_null;
    n++;

    // _epoch
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._epoch_value;
    b[n].is_null = &i._epoch_null;
    n++;

    // _exposureCount
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._exposureCount_value;
    b[n].is_null = &i._exposureCount_null;
    n++;

    // _gain
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._gain_value;
    b[n].is_null = &i._gain_null;
    n++;

    // _bin
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._bin_value;
    b[n].is_null = &i._bin_null;
    n++;

    // _readout
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._readout_value;
    b[n].is_null = &i._readout_null;
    n++;

    // _exposureTime
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._exposureTime_value;
    b[n].is_null = &i._exposureTime_null;
    n++;

    // _rightAscension
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._rightAscension_value;
    b[n].is_null = &i._rightAscension_null;
    n++;

    // _declination
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._declination_value;
    b[n].is_null = &i._declination_null;
    n++;

    // _delayTime
    //
    b[n].type = pgsql::bind::double_;
    b[n].buffer = &i._delayTime_value;
    b[n].is_null = &i._delayTime_null;
    n++;
  }

  void access::object_traits_impl< ::atccsplan, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::atccsplan, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // _user
    //
    {
      ::std::string const& v =
        o._user;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i._user_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i._user_value,
        size,
        is_null,
        v);
      i._user_null = is_null;
      i._user_size = size;
      grew = grew || (cap != i._user_value.capacity ());
    }

    // _project
    //
    {
      ::std::string const& v =
        o._project;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i._project_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i._project_value,
        size,
        is_null,
        v);
      i._project_null = is_null;
      i._project_size = size;
      grew = grew || (cap != i._project_value.capacity ());
    }

    // _target
    //
    {
      ::std::string const& v =
        o._target;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i._target_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i._target_value,
        size,
        is_null,
        v);
      i._target_null = is_null;
      i._target_size = size;
      grew = grew || (cap != i._target_value.capacity ());
    }

    // _filter
    //
    {
      ::std::string const& v =
        o._filter;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i._filter_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i._filter_value,
        size,
        is_null,
        v);
      i._filter_null = is_null;
      i._filter_size = size;
      grew = grew || (cap != i._filter_value.capacity ());
    }

    // _sec
    //
    {
      unsigned int const& v =
        o._sec;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._sec_value, is_null, v);
      i._sec_null = is_null;
    }

    // _msec
    //
    {
      unsigned int const& v =
        o._msec;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._msec_value, is_null, v);
      i._msec_null = is_null;
    }

    // _result
    //
    {
      unsigned int const& v =
        o._result;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._result_value, is_null, v);
      i._result_null = is_null;
    }

    // _percent
    //
    {
      unsigned int const& v =
        o._percent;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._percent_value, is_null, v);
      i._percent_null = is_null;
    }

    // _at
    //
    {
      unsigned int const& v =
        o._at;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._at_value, is_null, v);
      i._at_null = is_null;
    }

    // _type
    //
    {
      unsigned int const& v =
        o._type;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._type_value, is_null, v);
      i._type_null = is_null;
    }

    // _epoch
    //
    {
      unsigned int const& v =
        o._epoch;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._epoch_value, is_null, v);
      i._epoch_null = is_null;
    }

    // _exposureCount
    //
    {
      unsigned int const& v =
        o._exposureCount;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._exposureCount_value, is_null, v);
      i._exposureCount_null = is_null;
    }

    // _gain
    //
    {
      unsigned int const& v =
        o._gain;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._gain_value, is_null, v);
      i._gain_null = is_null;
    }

    // _bin
    //
    {
      unsigned int const& v =
        o._bin;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._bin_value, is_null, v);
      i._bin_null = is_null;
    }

    // _readout
    //
    {
      unsigned int const& v =
        o._readout;

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i._readout_value, is_null, v);
      i._readout_null = is_null;
    }

    // _exposureTime
    //
    {
      double const& v =
        o._exposureTime;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._exposureTime_value, is_null, v);
      i._exposureTime_null = is_null;
    }

    // _rightAscension
    //
    {
      double const& v =
        o._rightAscension;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._rightAscension_value, is_null, v);
      i._rightAscension_null = is_null;
    }

    // _declination
    //
    {
      double const& v =
        o._declination;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._declination_value, is_null, v);
      i._declination_null = is_null;
    }

    // _delayTime
    //
    {
      double const& v =
        o._delayTime;

      bool is_null (false);
      pgsql::value_traits<
          double,
          pgsql::id_double >::set_image (
        i._delayTime_value, is_null, v);
      i._delayTime_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::atccsplan, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // _id
    //
    {
      unsigned int& v =
        o._id;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._id_value,
        i._id_null);
    }

    // _user
    //
    {
      ::std::string& v =
        o._user;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i._user_value,
        i._user_size,
        i._user_null);
    }

    // _project
    //
    {
      ::std::string& v =
        o._project;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i._project_value,
        i._project_size,
        i._project_null);
    }

    // _target
    //
    {
      ::std::string& v =
        o._target;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i._target_value,
        i._target_size,
        i._target_null);
    }

    // _filter
    //
    {
      ::std::string& v =
        o._filter;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i._filter_value,
        i._filter_size,
        i._filter_null);
    }

    // _sec
    //
    {
      unsigned int& v =
        o._sec;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._sec_value,
        i._sec_null);
    }

    // _msec
    //
    {
      unsigned int& v =
        o._msec;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._msec_value,
        i._msec_null);
    }

    // _result
    //
    {
      unsigned int& v =
        o._result;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._result_value,
        i._result_null);
    }

    // _percent
    //
    {
      unsigned int& v =
        o._percent;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._percent_value,
        i._percent_null);
    }

    // _at
    //
    {
      unsigned int& v =
        o._at;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._at_value,
        i._at_null);
    }

    // _type
    //
    {
      unsigned int& v =
        o._type;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._type_value,
        i._type_null);
    }

    // _epoch
    //
    {
      unsigned int& v =
        o._epoch;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._epoch_value,
        i._epoch_null);
    }

    // _exposureCount
    //
    {
      unsigned int& v =
        o._exposureCount;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._exposureCount_value,
        i._exposureCount_null);
    }

    // _gain
    //
    {
      unsigned int& v =
        o._gain;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._gain_value,
        i._gain_null);
    }

    // _bin
    //
    {
      unsigned int& v =
        o._bin;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._bin_value,
        i._bin_null);
    }

    // _readout
    //
    {
      unsigned int& v =
        o._readout;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i._readout_value,
        i._readout_null);
    }

    // _exposureTime
    //
    {
      double& v =
        o._exposureTime;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._exposureTime_value,
        i._exposureTime_null);
    }

    // _rightAscension
    //
    {
      double& v =
        o._rightAscension;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._rightAscension_value,
        i._rightAscension_null);
    }

    // _declination
    //
    {
      double& v =
        o._declination;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._declination_value,
        i._declination_null);
    }

    // _delayTime
    //
    {
      double& v =
        o._delayTime;

      pgsql::value_traits<
          double,
          pgsql::id_double >::set_value (
        v,
        i._delayTime_value,
        i._delayTime_null);
    }
  }

  void access::object_traits_impl< ::atccsplan, id_pgsql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::persist_statement[] =
  "INSERT INTO \"atccsplan\" "
  "(\"id\", "
  "\"user\", "
  "\"project\", "
  "\"target\", "
  "\"filter\", "
  "\"sec\", "
  "\"msec\", "
  "\"result\", "
  "\"percent\", "
  "\"at\", "
  "\"type\", "
  "\"epoch\", "
  "\"exposureCount\", "
  "\"gain\", "
  "\"bin\", "
  "\"readout\", "
  "\"exposureTime\", "
  "\"rightAscension\", "
  "\"declination\", "
  "\"delayTime\") "
  "VALUES "
  "(DEFAULT, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16, $17, $18, $19) "
  "RETURNING \"id\"";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::find_statement[] =
  "SELECT "
  "\"atccsplan\".\"id\", "
  "\"atccsplan\".\"user\", "
  "\"atccsplan\".\"project\", "
  "\"atccsplan\".\"target\", "
  "\"atccsplan\".\"filter\", "
  "\"atccsplan\".\"sec\", "
  "\"atccsplan\".\"msec\", "
  "\"atccsplan\".\"result\", "
  "\"atccsplan\".\"percent\", "
  "\"atccsplan\".\"at\", "
  "\"atccsplan\".\"type\", "
  "\"atccsplan\".\"epoch\", "
  "\"atccsplan\".\"exposureCount\", "
  "\"atccsplan\".\"gain\", "
  "\"atccsplan\".\"bin\", "
  "\"atccsplan\".\"readout\", "
  "\"atccsplan\".\"exposureTime\", "
  "\"atccsplan\".\"rightAscension\", "
  "\"atccsplan\".\"declination\", "
  "\"atccsplan\".\"delayTime\" "
  "FROM \"atccsplan\" "
  "WHERE \"atccsplan\".\"id\"=$1";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::update_statement[] =
  "UPDATE \"atccsplan\" "
  "SET "
  "\"user\"=$1, "
  "\"project\"=$2, "
  "\"target\"=$3, "
  "\"filter\"=$4, "
  "\"sec\"=$5, "
  "\"msec\"=$6, "
  "\"result\"=$7, "
  "\"percent\"=$8, "
  "\"at\"=$9, "
  "\"type\"=$10, "
  "\"epoch\"=$11, "
  "\"exposureCount\"=$12, "
  "\"gain\"=$13, "
  "\"bin\"=$14, "
  "\"readout\"=$15, "
  "\"exposureTime\"=$16, "
  "\"rightAscension\"=$17, "
  "\"declination\"=$18, "
  "\"delayTime\"=$19 "
  "WHERE \"id\"=$20";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::erase_statement[] =
  "DELETE FROM \"atccsplan\" "
  "WHERE \"id\"=$1";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::query_statement[] =
  "SELECT "
  "\"atccsplan\".\"id\", "
  "\"atccsplan\".\"user\", "
  "\"atccsplan\".\"project\", "
  "\"atccsplan\".\"target\", "
  "\"atccsplan\".\"filter\", "
  "\"atccsplan\".\"sec\", "
  "\"atccsplan\".\"msec\", "
  "\"atccsplan\".\"result\", "
  "\"atccsplan\".\"percent\", "
  "\"atccsplan\".\"at\", "
  "\"atccsplan\".\"type\", "
  "\"atccsplan\".\"epoch\", "
  "\"atccsplan\".\"exposureCount\", "
  "\"atccsplan\".\"gain\", "
  "\"atccsplan\".\"bin\", "
  "\"atccsplan\".\"readout\", "
  "\"atccsplan\".\"exposureTime\", "
  "\"atccsplan\".\"rightAscension\", "
  "\"atccsplan\".\"declination\", "
  "\"atccsplan\".\"delayTime\" "
  "FROM \"atccsplan\"";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"atccsplan\"";

  const char access::object_traits_impl< ::atccsplan, id_pgsql >::table_name[] =
  "\"atccsplan\"";

  void access::object_traits_impl< ::atccsplan, id_pgsql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj._id = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::atccsplan, id_pgsql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;
    using pgsql::update_statement;

    callback (db, obj, callback_event::pre_update);

    pgsql::transaction& tr (pgsql::transaction::current ());
    pgsql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj._id);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::atccsplan, id_pgsql >::
  erase (database& db, const id_type& id)
  {
    using namespace pgsql;

    ODB_POTENTIALLY_UNUSED (db);

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::atccsplan, id_pgsql >::pointer_type
  access::object_traits_impl< ::atccsplan, id_pgsql >::
  find (database& db, const id_type& id)
  {
    using namespace pgsql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::atccsplan, id_pgsql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::atccsplan, id_pgsql >::
  reload (database& db, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj._id);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::atccsplan, id_pgsql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace pgsql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::atccsplan, id_pgsql >::object_type >
  access::object_traits_impl< ::atccsplan, id_pgsql >::
  query (database&, const query_base_type& q)
  {
    using namespace pgsql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        sts.connection (),
        query_statement_name,
        text,
        false,
        true,
        q.parameter_types (),
        q.parameter_count (),
        q.parameters_binding (),
        imb));

    st->execute ();
    st->deallocate ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) pgsql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::atccsplan, id_pgsql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      erase_query_statement_name,
      text,
      q.parameter_types (),
      q.parameter_count (),
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
