// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "at60ccdstatus-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

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
  // at60ccdstatus
  //

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  persist_statement_name[] = "persist_at60ccdstatus";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  find_statement_name[] = "find_at60ccdstatus";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  update_statement_name[] = "update_at60ccdstatus";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  erase_statement_name[] = "erase_at60ccdstatus";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  query_statement_name[] = "query_at60ccdstatus";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  erase_query_statement_name[] = "erase_query_at60ccdstatus";

  const unsigned int access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  persist_statement_types[] =
  {
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
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
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid
  };

  const unsigned int access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  find_statement_types[] =
  {
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  update_statement_types[] =
  {
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int4_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
    pgsql::int2_oid,
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
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::int8_oid
  };

  struct access::object_traits_impl< ::at60ccdstatus, id_pgsql >::extra_statement_cache_type
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

  bool access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // atccsccdstatus base
    //
    if (object_traits_impl< ::atccsccdstatus, id_pgsql >::grow (
          i, t + 0UL))
      grew = true;

    return grew;
  }

  void access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // atccsccdstatus base
    //
    object_traits_impl< ::atccsccdstatus, id_pgsql >::bind (b + n, i, sk);
    n += sk == statement_select ? 47UL : 46UL;
  }

  bool access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // atccsccdstatus base
    //
    if (object_traits_impl< ::atccsccdstatus, id_pgsql >::init (i, o, sk))
      grew = true;

    return grew;
  }

  void access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // atccsccdstatus base
    //
    object_traits_impl< ::atccsccdstatus, id_pgsql >::init (o, i, db);
  }

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::persist_statement[] =
  "INSERT INTO \"at60ccdstatus\" "
  "(\"id\", "
  "\"sec\", "
  "\"msec\", "
  "\"curstatus\", "
  "\"lastStatus\", "
  "\"warning\", "
  "\"error\", "
  "\"errorString\", "
  "\"observeName\", "
  "\"band\", "
  "\"lastTargetName\", "
  "\"observeType\", "
  "\"epoch\", "
  "\"indexOfRSMode\", "
  "\"indexOfTSMode\", "
  "\"indexOfGainMode\", "
  "\"indexOfGain\", "
  "\"readMode\", "
  "\"exposureTriggerMode\", "
  "\"fanOn\", "
  "\"shutterMode\", "
  "\"isFullFrame\", "
  "\"isEM\", "
  "\"isNoiseFilter\", "
  "\"isBaseline\", "
  "\"binX\", "
  "\"binY\", "
  "\"startX\", "
  "\"startY\", "
  "\"imageWidth\", "
  "\"imageHeight\", "
  "\"frameSequence\", "
  "\"frameTotal\", "
  "\"lastExposureTime\", "
  "\"EM\", "
  "\"baseline\", "
  "\"J2000RightAscension\", "
  "\"J2000Declination\", "
  "\"exposureTime\", "
  "\"delayTime\", "
  "\"coolerT\", "
  "\"targetCoolerT\", "
  "\"lastExposureDuration\", "
  "\"bitsOfPixel\", "
  "\"exposurePercent\", "
  "\"pixelScaleX\", "
  "\"pixelScaleY\") "
  "VALUES "
  "(DEFAULT, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16, $17, $18, $19, $20, $21, $22, $23, $24, $25, $26, $27, $28, $29, $30, $31, $32, $33, $34, $35, $36, $37, $38, $39, $40, $41, $42, $43, $44, $45, $46) "
  "RETURNING \"id\"";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::find_statement[] =
  "SELECT "
  "\"at60ccdstatus\".\"id\", "
  "\"at60ccdstatus\".\"sec\", "
  "\"at60ccdstatus\".\"msec\", "
  "\"at60ccdstatus\".\"curstatus\", "
  "\"at60ccdstatus\".\"lastStatus\", "
  "\"at60ccdstatus\".\"warning\", "
  "\"at60ccdstatus\".\"error\", "
  "\"at60ccdstatus\".\"errorString\", "
  "\"at60ccdstatus\".\"observeName\", "
  "\"at60ccdstatus\".\"band\", "
  "\"at60ccdstatus\".\"lastTargetName\", "
  "\"at60ccdstatus\".\"observeType\", "
  "\"at60ccdstatus\".\"epoch\", "
  "\"at60ccdstatus\".\"indexOfRSMode\", "
  "\"at60ccdstatus\".\"indexOfTSMode\", "
  "\"at60ccdstatus\".\"indexOfGainMode\", "
  "\"at60ccdstatus\".\"indexOfGain\", "
  "\"at60ccdstatus\".\"readMode\", "
  "\"at60ccdstatus\".\"exposureTriggerMode\", "
  "\"at60ccdstatus\".\"fanOn\", "
  "\"at60ccdstatus\".\"shutterMode\", "
  "\"at60ccdstatus\".\"isFullFrame\", "
  "\"at60ccdstatus\".\"isEM\", "
  "\"at60ccdstatus\".\"isNoiseFilter\", "
  "\"at60ccdstatus\".\"isBaseline\", "
  "\"at60ccdstatus\".\"binX\", "
  "\"at60ccdstatus\".\"binY\", "
  "\"at60ccdstatus\".\"startX\", "
  "\"at60ccdstatus\".\"startY\", "
  "\"at60ccdstatus\".\"imageWidth\", "
  "\"at60ccdstatus\".\"imageHeight\", "
  "\"at60ccdstatus\".\"frameSequence\", "
  "\"at60ccdstatus\".\"frameTotal\", "
  "\"at60ccdstatus\".\"lastExposureTime\", "
  "\"at60ccdstatus\".\"EM\", "
  "\"at60ccdstatus\".\"baseline\", "
  "\"at60ccdstatus\".\"J2000RightAscension\", "
  "\"at60ccdstatus\".\"J2000Declination\", "
  "\"at60ccdstatus\".\"exposureTime\", "
  "\"at60ccdstatus\".\"delayTime\", "
  "\"at60ccdstatus\".\"coolerT\", "
  "\"at60ccdstatus\".\"targetCoolerT\", "
  "\"at60ccdstatus\".\"lastExposureDuration\", "
  "\"at60ccdstatus\".\"bitsOfPixel\", "
  "\"at60ccdstatus\".\"exposurePercent\", "
  "\"at60ccdstatus\".\"pixelScaleX\", "
  "\"at60ccdstatus\".\"pixelScaleY\" "
  "FROM \"at60ccdstatus\" "
  "WHERE \"at60ccdstatus\".\"id\"=$1";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::update_statement[] =
  "UPDATE \"at60ccdstatus\" "
  "SET "
  "\"sec\"=$1, "
  "\"msec\"=$2, "
  "\"curstatus\"=$3, "
  "\"lastStatus\"=$4, "
  "\"warning\"=$5, "
  "\"error\"=$6, "
  "\"errorString\"=$7, "
  "\"observeName\"=$8, "
  "\"band\"=$9, "
  "\"lastTargetName\"=$10, "
  "\"observeType\"=$11, "
  "\"epoch\"=$12, "
  "\"indexOfRSMode\"=$13, "
  "\"indexOfTSMode\"=$14, "
  "\"indexOfGainMode\"=$15, "
  "\"indexOfGain\"=$16, "
  "\"readMode\"=$17, "
  "\"exposureTriggerMode\"=$18, "
  "\"fanOn\"=$19, "
  "\"shutterMode\"=$20, "
  "\"isFullFrame\"=$21, "
  "\"isEM\"=$22, "
  "\"isNoiseFilter\"=$23, "
  "\"isBaseline\"=$24, "
  "\"binX\"=$25, "
  "\"binY\"=$26, "
  "\"startX\"=$27, "
  "\"startY\"=$28, "
  "\"imageWidth\"=$29, "
  "\"imageHeight\"=$30, "
  "\"frameSequence\"=$31, "
  "\"frameTotal\"=$32, "
  "\"lastExposureTime\"=$33, "
  "\"EM\"=$34, "
  "\"baseline\"=$35, "
  "\"J2000RightAscension\"=$36, "
  "\"J2000Declination\"=$37, "
  "\"exposureTime\"=$38, "
  "\"delayTime\"=$39, "
  "\"coolerT\"=$40, "
  "\"targetCoolerT\"=$41, "
  "\"lastExposureDuration\"=$42, "
  "\"bitsOfPixel\"=$43, "
  "\"exposurePercent\"=$44, "
  "\"pixelScaleX\"=$45, "
  "\"pixelScaleY\"=$46 "
  "WHERE \"id\"=$47";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::erase_statement[] =
  "DELETE FROM \"at60ccdstatus\" "
  "WHERE \"id\"=$1";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::query_statement[] =
  "SELECT "
  "\"at60ccdstatus\".\"id\", "
  "\"at60ccdstatus\".\"sec\", "
  "\"at60ccdstatus\".\"msec\", "
  "\"at60ccdstatus\".\"curstatus\", "
  "\"at60ccdstatus\".\"lastStatus\", "
  "\"at60ccdstatus\".\"warning\", "
  "\"at60ccdstatus\".\"error\", "
  "\"at60ccdstatus\".\"errorString\", "
  "\"at60ccdstatus\".\"observeName\", "
  "\"at60ccdstatus\".\"band\", "
  "\"at60ccdstatus\".\"lastTargetName\", "
  "\"at60ccdstatus\".\"observeType\", "
  "\"at60ccdstatus\".\"epoch\", "
  "\"at60ccdstatus\".\"indexOfRSMode\", "
  "\"at60ccdstatus\".\"indexOfTSMode\", "
  "\"at60ccdstatus\".\"indexOfGainMode\", "
  "\"at60ccdstatus\".\"indexOfGain\", "
  "\"at60ccdstatus\".\"readMode\", "
  "\"at60ccdstatus\".\"exposureTriggerMode\", "
  "\"at60ccdstatus\".\"fanOn\", "
  "\"at60ccdstatus\".\"shutterMode\", "
  "\"at60ccdstatus\".\"isFullFrame\", "
  "\"at60ccdstatus\".\"isEM\", "
  "\"at60ccdstatus\".\"isNoiseFilter\", "
  "\"at60ccdstatus\".\"isBaseline\", "
  "\"at60ccdstatus\".\"binX\", "
  "\"at60ccdstatus\".\"binY\", "
  "\"at60ccdstatus\".\"startX\", "
  "\"at60ccdstatus\".\"startY\", "
  "\"at60ccdstatus\".\"imageWidth\", "
  "\"at60ccdstatus\".\"imageHeight\", "
  "\"at60ccdstatus\".\"frameSequence\", "
  "\"at60ccdstatus\".\"frameTotal\", "
  "\"at60ccdstatus\".\"lastExposureTime\", "
  "\"at60ccdstatus\".\"EM\", "
  "\"at60ccdstatus\".\"baseline\", "
  "\"at60ccdstatus\".\"J2000RightAscension\", "
  "\"at60ccdstatus\".\"J2000Declination\", "
  "\"at60ccdstatus\".\"exposureTime\", "
  "\"at60ccdstatus\".\"delayTime\", "
  "\"at60ccdstatus\".\"coolerT\", "
  "\"at60ccdstatus\".\"targetCoolerT\", "
  "\"at60ccdstatus\".\"lastExposureDuration\", "
  "\"at60ccdstatus\".\"bitsOfPixel\", "
  "\"at60ccdstatus\".\"exposurePercent\", "
  "\"at60ccdstatus\".\"pixelScaleX\", "
  "\"at60ccdstatus\".\"pixelScaleY\" "
  "FROM \"at60ccdstatus\"";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"at60ccdstatus\"";

  const char access::object_traits_impl< ::at60ccdstatus, id_pgsql >::table_name[] =
  "\"at60ccdstatus\"";

  void access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  void access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  void access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  access::object_traits_impl< ::at60ccdstatus, id_pgsql >::pointer_type
  access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  bool access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  bool access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  bool access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  result< access::object_traits_impl< ::at60ccdstatus, id_pgsql >::object_type >
  access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

  unsigned long long access::object_traits_impl< ::at60ccdstatus, id_pgsql >::
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

namespace odb
{
  static bool
  create_schema (database& db, unsigned short pass, bool drop)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (pass);
    ODB_POTENTIALLY_UNUSED (drop);

    if (drop)
    {
      switch (pass)
      {
        case 1:
        {
          return true;
        }
        case 2:
        {
          db.execute ("DROP TABLE IF EXISTS \"at60ccdstatus\" CASCADE");
          return false;
        }
      }
    }
    else
    {
      switch (pass)
      {
        case 1:
        {
          db.execute ("CREATE TABLE \"at60ccdstatus\" (\n"
                      "  \"id\" BIGSERIAL NOT NULL PRIMARY KEY,\n"
                      "  \"sec\" INTEGER NOT NULL,\n"
                      "  \"msec\" INTEGER NOT NULL,\n"
                      "  \"curstatus\" INTEGER NOT NULL,\n"
                      "  \"lastStatus\" INTEGER NOT NULL,\n"
                      "  \"warning\" BIGINT NOT NULL,\n"
                      "  \"error\" BIGINT NOT NULL,\n"
                      "  \"errorString\" TEXT NOT NULL,\n"
                      "  \"observeName\" TEXT NOT NULL,\n"
                      "  \"band\" TEXT NOT NULL,\n"
                      "  \"lastTargetName\" TEXT NOT NULL,\n"
                      "  \"observeType\" SMALLINT NOT NULL,\n"
                      "  \"epoch\" SMALLINT NOT NULL,\n"
                      "  \"indexOfRSMode\" SMALLINT NOT NULL,\n"
                      "  \"indexOfTSMode\" SMALLINT NOT NULL,\n"
                      "  \"indexOfGainMode\" SMALLINT NOT NULL,\n"
                      "  \"indexOfGain\" SMALLINT NOT NULL,\n"
                      "  \"readMode\" SMALLINT NOT NULL,\n"
                      "  \"exposureTriggerMode\" SMALLINT NOT NULL,\n"
                      "  \"fanOn\" SMALLINT NOT NULL,\n"
                      "  \"shutterMode\" SMALLINT NOT NULL,\n"
                      "  \"isFullFrame\" SMALLINT NOT NULL,\n"
                      "  \"isEM\" SMALLINT NOT NULL,\n"
                      "  \"isNoiseFilter\" SMALLINT NOT NULL,\n"
                      "  \"isBaseline\" SMALLINT NOT NULL,\n"
                      "  \"binX\" INTEGER NOT NULL,\n"
                      "  \"binY\" INTEGER NOT NULL,\n"
                      "  \"startX\" INTEGER NOT NULL,\n"
                      "  \"startY\" INTEGER NOT NULL,\n"
                      "  \"imageWidth\" INTEGER NOT NULL,\n"
                      "  \"imageHeight\" INTEGER NOT NULL,\n"
                      "  \"frameSequence\" INTEGER NOT NULL,\n"
                      "  \"frameTotal\" INTEGER NOT NULL,\n"
                      "  \"lastExposureTime\" INTEGER NOT NULL,\n"
                      "  \"EM\" INTEGER NOT NULL,\n"
                      "  \"baseline\" INTEGER NOT NULL,\n"
                      "  \"J2000RightAscension\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"J2000Declination\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"exposureTime\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"delayTime\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"coolerT\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetCoolerT\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"lastExposureDuration\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"bitsOfPixel\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"exposurePercent\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"pixelScaleX\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"pixelScaleY\" DOUBLE PRECISION NOT NULL)");
          return false;
        }
      }
    }

    return false;
  }

  static const schema_catalog_create_entry
  create_schema_entry_ (
    id_pgsql,
    "at60ccdstatus",
    &create_schema);
}

#include <odb/post.hxx>