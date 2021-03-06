// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "at60gimbalstatus-odb.hxx"

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
  // at60gimbalstatus
  //

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  persist_statement_name[] = "persist_at60gimbalstatus";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  find_statement_name[] = "find_at60gimbalstatus";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  update_statement_name[] = "update_at60gimbalstatus";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  erase_statement_name[] = "erase_at60gimbalstatus";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  query_statement_name[] = "query_at60gimbalstatus";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  erase_query_statement_name[] = "erase_query_at60gimbalstatus";

  const unsigned int access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
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
    pgsql::int2_oid
  };

  const unsigned int access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  find_statement_types[] =
  {
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
    pgsql::float8_oid,
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
    pgsql::int8_oid
  };

  struct access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::extra_statement_cache_type
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

  bool access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // atccsgimbalstatus base
    //
    if (object_traits_impl< ::atccsgimbalstatus, id_pgsql >::grow (
          i, t + 0UL))
      grew = true;

    return grew;
  }

  void access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // atccsgimbalstatus base
    //
    object_traits_impl< ::atccsgimbalstatus, id_pgsql >::bind (b + n, i, sk);
    n += sk == statement_select ? 79UL : 78UL;
  }

  bool access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // atccsgimbalstatus base
    //
    if (object_traits_impl< ::atccsgimbalstatus, id_pgsql >::init (i, o, sk))
      grew = true;

    return grew;
  }

  void access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // atccsgimbalstatus base
    //
    object_traits_impl< ::atccsgimbalstatus, id_pgsql >::init (o, i, db);
  }

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::persist_statement[] =
  "INSERT INTO \"at60gimbalstatus\" "
  "(\"id\", "
  "\"sec\", "
  "\"msec\", "
  "\"curstatus\", "
  "\"lastStatus\", "
  "\"warning\", "
  "\"error\", "
  "\"errorString\", "
  "\"trackObjectName\", "
  "\"siderealTime\", "
  "\"hourAngle\", "
  "\"rightAscension\", "
  "\"declination\", "
  "\"J2000RightAscension\", "
  "\"J2000Declination\", "
  "\"azmiuth\", "
  "\"elevation\", "
  "\"derotatorPositon\", "
  "\"targetRightAscension\", "
  "\"targetDeclination\", "
  "\"targetJ2000RightAscension\", "
  "\"targetJ2000Declination\", "
  "\"targetAzmiuth\", "
  "\"targetElevation\", "
  "\"targetDerotatorPosition\", "
  "\"axis1TrackError\", "
  "\"axis2TrackError\", "
  "\"axis3TrackError\", "
  "\"axis4Angle\", "
  "\"coverPosition\", "
  "\"targetAxis4Angle\", "
  "\"axis1Speed\", "
  "\"axis2Speed\", "
  "\"axis3Speed\", "
  "\"refractionCorrection\", "
  "\"axis1Encoder\", "
  "\"axis2Encoder\", "
  "\"axis3Encoder\", "
  "\"axis1PMCorrection\", "
  "\"axis2PMCorrection\", "
  "\"axis3PMCorrection\", "
  "\"axis1ManualCorrection\", "
  "\"axis2ManualCorrection\", "
  "\"axis3ManualCorrection\", "
  "\"temperature1\", "
  "\"temperature2\", "
  "\"temperature3\", "
  "\"temperature4\", "
  "\"temperature5\", "
  "\"temperature6\", "
  "\"temperature7\", "
  "\"temperature8\", "
  "\"temperature9\", "
  "\"temperature10\", "
  "\"temperature11\", "
  "\"temperature12\", "
  "\"humidity1\", "
  "\"humidity2\", "
  "\"humidity3\", "
  "\"humidity4\", "
  "\"humidity5\", "
  "\"humidity6\", "
  "\"humidity7\", "
  "\"humidity8\", "
  "\"humidity9\", "
  "\"humidity10\", "
  "\"humidity11\", "
  "\"humidity12\", "
  "\"focusTypeIndex\", "
  "\"coverIndex\", "
  "\"targetFocusTypeIndex\", "
  "\"targetCoverIndex\", "
  "\"trackType\", "
  "\"axis3Mode\", "
  "\"pieSide\", "
  "\"targetPieSide\", "
  "\"isAxis1FindHome\", "
  "\"isAxis2FindHome\", "
  "\"isAxis3FindHome\") "
  "VALUES "
  "(DEFAULT, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16, $17, $18, $19, $20, $21, $22, $23, $24, $25, $26, $27, $28, $29, $30, $31, $32, $33, $34, $35, $36, $37, $38, $39, $40, $41, $42, $43, $44, $45, $46, $47, $48, $49, $50, $51, $52, $53, $54, $55, $56, $57, $58, $59, $60, $61, $62, $63, $64, $65, $66, $67, $68, $69, $70, $71, $72, $73, $74, $75, $76, $77, $78) "
  "RETURNING \"id\"";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::find_statement[] =
  "SELECT "
  "\"at60gimbalstatus\".\"id\", "
  "\"at60gimbalstatus\".\"sec\", "
  "\"at60gimbalstatus\".\"msec\", "
  "\"at60gimbalstatus\".\"curstatus\", "
  "\"at60gimbalstatus\".\"lastStatus\", "
  "\"at60gimbalstatus\".\"warning\", "
  "\"at60gimbalstatus\".\"error\", "
  "\"at60gimbalstatus\".\"errorString\", "
  "\"at60gimbalstatus\".\"trackObjectName\", "
  "\"at60gimbalstatus\".\"siderealTime\", "
  "\"at60gimbalstatus\".\"hourAngle\", "
  "\"at60gimbalstatus\".\"rightAscension\", "
  "\"at60gimbalstatus\".\"declination\", "
  "\"at60gimbalstatus\".\"J2000RightAscension\", "
  "\"at60gimbalstatus\".\"J2000Declination\", "
  "\"at60gimbalstatus\".\"azmiuth\", "
  "\"at60gimbalstatus\".\"elevation\", "
  "\"at60gimbalstatus\".\"derotatorPositon\", "
  "\"at60gimbalstatus\".\"targetRightAscension\", "
  "\"at60gimbalstatus\".\"targetDeclination\", "
  "\"at60gimbalstatus\".\"targetJ2000RightAscension\", "
  "\"at60gimbalstatus\".\"targetJ2000Declination\", "
  "\"at60gimbalstatus\".\"targetAzmiuth\", "
  "\"at60gimbalstatus\".\"targetElevation\", "
  "\"at60gimbalstatus\".\"targetDerotatorPosition\", "
  "\"at60gimbalstatus\".\"axis1TrackError\", "
  "\"at60gimbalstatus\".\"axis2TrackError\", "
  "\"at60gimbalstatus\".\"axis3TrackError\", "
  "\"at60gimbalstatus\".\"axis4Angle\", "
  "\"at60gimbalstatus\".\"coverPosition\", "
  "\"at60gimbalstatus\".\"targetAxis4Angle\", "
  "\"at60gimbalstatus\".\"axis1Speed\", "
  "\"at60gimbalstatus\".\"axis2Speed\", "
  "\"at60gimbalstatus\".\"axis3Speed\", "
  "\"at60gimbalstatus\".\"refractionCorrection\", "
  "\"at60gimbalstatus\".\"axis1Encoder\", "
  "\"at60gimbalstatus\".\"axis2Encoder\", "
  "\"at60gimbalstatus\".\"axis3Encoder\", "
  "\"at60gimbalstatus\".\"axis1PMCorrection\", "
  "\"at60gimbalstatus\".\"axis2PMCorrection\", "
  "\"at60gimbalstatus\".\"axis3PMCorrection\", "
  "\"at60gimbalstatus\".\"axis1ManualCorrection\", "
  "\"at60gimbalstatus\".\"axis2ManualCorrection\", "
  "\"at60gimbalstatus\".\"axis3ManualCorrection\", "
  "\"at60gimbalstatus\".\"temperature1\", "
  "\"at60gimbalstatus\".\"temperature2\", "
  "\"at60gimbalstatus\".\"temperature3\", "
  "\"at60gimbalstatus\".\"temperature4\", "
  "\"at60gimbalstatus\".\"temperature5\", "
  "\"at60gimbalstatus\".\"temperature6\", "
  "\"at60gimbalstatus\".\"temperature7\", "
  "\"at60gimbalstatus\".\"temperature8\", "
  "\"at60gimbalstatus\".\"temperature9\", "
  "\"at60gimbalstatus\".\"temperature10\", "
  "\"at60gimbalstatus\".\"temperature11\", "
  "\"at60gimbalstatus\".\"temperature12\", "
  "\"at60gimbalstatus\".\"humidity1\", "
  "\"at60gimbalstatus\".\"humidity2\", "
  "\"at60gimbalstatus\".\"humidity3\", "
  "\"at60gimbalstatus\".\"humidity4\", "
  "\"at60gimbalstatus\".\"humidity5\", "
  "\"at60gimbalstatus\".\"humidity6\", "
  "\"at60gimbalstatus\".\"humidity7\", "
  "\"at60gimbalstatus\".\"humidity8\", "
  "\"at60gimbalstatus\".\"humidity9\", "
  "\"at60gimbalstatus\".\"humidity10\", "
  "\"at60gimbalstatus\".\"humidity11\", "
  "\"at60gimbalstatus\".\"humidity12\", "
  "\"at60gimbalstatus\".\"focusTypeIndex\", "
  "\"at60gimbalstatus\".\"coverIndex\", "
  "\"at60gimbalstatus\".\"targetFocusTypeIndex\", "
  "\"at60gimbalstatus\".\"targetCoverIndex\", "
  "\"at60gimbalstatus\".\"trackType\", "
  "\"at60gimbalstatus\".\"axis3Mode\", "
  "\"at60gimbalstatus\".\"pieSide\", "
  "\"at60gimbalstatus\".\"targetPieSide\", "
  "\"at60gimbalstatus\".\"isAxis1FindHome\", "
  "\"at60gimbalstatus\".\"isAxis2FindHome\", "
  "\"at60gimbalstatus\".\"isAxis3FindHome\" "
  "FROM \"at60gimbalstatus\" "
  "WHERE \"at60gimbalstatus\".\"id\"=$1";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::update_statement[] =
  "UPDATE \"at60gimbalstatus\" "
  "SET "
  "\"sec\"=$1, "
  "\"msec\"=$2, "
  "\"curstatus\"=$3, "
  "\"lastStatus\"=$4, "
  "\"warning\"=$5, "
  "\"error\"=$6, "
  "\"errorString\"=$7, "
  "\"trackObjectName\"=$8, "
  "\"siderealTime\"=$9, "
  "\"hourAngle\"=$10, "
  "\"rightAscension\"=$11, "
  "\"declination\"=$12, "
  "\"J2000RightAscension\"=$13, "
  "\"J2000Declination\"=$14, "
  "\"azmiuth\"=$15, "
  "\"elevation\"=$16, "
  "\"derotatorPositon\"=$17, "
  "\"targetRightAscension\"=$18, "
  "\"targetDeclination\"=$19, "
  "\"targetJ2000RightAscension\"=$20, "
  "\"targetJ2000Declination\"=$21, "
  "\"targetAzmiuth\"=$22, "
  "\"targetElevation\"=$23, "
  "\"targetDerotatorPosition\"=$24, "
  "\"axis1TrackError\"=$25, "
  "\"axis2TrackError\"=$26, "
  "\"axis3TrackError\"=$27, "
  "\"axis4Angle\"=$28, "
  "\"coverPosition\"=$29, "
  "\"targetAxis4Angle\"=$30, "
  "\"axis1Speed\"=$31, "
  "\"axis2Speed\"=$32, "
  "\"axis3Speed\"=$33, "
  "\"refractionCorrection\"=$34, "
  "\"axis1Encoder\"=$35, "
  "\"axis2Encoder\"=$36, "
  "\"axis3Encoder\"=$37, "
  "\"axis1PMCorrection\"=$38, "
  "\"axis2PMCorrection\"=$39, "
  "\"axis3PMCorrection\"=$40, "
  "\"axis1ManualCorrection\"=$41, "
  "\"axis2ManualCorrection\"=$42, "
  "\"axis3ManualCorrection\"=$43, "
  "\"temperature1\"=$44, "
  "\"temperature2\"=$45, "
  "\"temperature3\"=$46, "
  "\"temperature4\"=$47, "
  "\"temperature5\"=$48, "
  "\"temperature6\"=$49, "
  "\"temperature7\"=$50, "
  "\"temperature8\"=$51, "
  "\"temperature9\"=$52, "
  "\"temperature10\"=$53, "
  "\"temperature11\"=$54, "
  "\"temperature12\"=$55, "
  "\"humidity1\"=$56, "
  "\"humidity2\"=$57, "
  "\"humidity3\"=$58, "
  "\"humidity4\"=$59, "
  "\"humidity5\"=$60, "
  "\"humidity6\"=$61, "
  "\"humidity7\"=$62, "
  "\"humidity8\"=$63, "
  "\"humidity9\"=$64, "
  "\"humidity10\"=$65, "
  "\"humidity11\"=$66, "
  "\"humidity12\"=$67, "
  "\"focusTypeIndex\"=$68, "
  "\"coverIndex\"=$69, "
  "\"targetFocusTypeIndex\"=$70, "
  "\"targetCoverIndex\"=$71, "
  "\"trackType\"=$72, "
  "\"axis3Mode\"=$73, "
  "\"pieSide\"=$74, "
  "\"targetPieSide\"=$75, "
  "\"isAxis1FindHome\"=$76, "
  "\"isAxis2FindHome\"=$77, "
  "\"isAxis3FindHome\"=$78 "
  "WHERE \"id\"=$79";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::erase_statement[] =
  "DELETE FROM \"at60gimbalstatus\" "
  "WHERE \"id\"=$1";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::query_statement[] =
  "SELECT "
  "\"at60gimbalstatus\".\"id\", "
  "\"at60gimbalstatus\".\"sec\", "
  "\"at60gimbalstatus\".\"msec\", "
  "\"at60gimbalstatus\".\"curstatus\", "
  "\"at60gimbalstatus\".\"lastStatus\", "
  "\"at60gimbalstatus\".\"warning\", "
  "\"at60gimbalstatus\".\"error\", "
  "\"at60gimbalstatus\".\"errorString\", "
  "\"at60gimbalstatus\".\"trackObjectName\", "
  "\"at60gimbalstatus\".\"siderealTime\", "
  "\"at60gimbalstatus\".\"hourAngle\", "
  "\"at60gimbalstatus\".\"rightAscension\", "
  "\"at60gimbalstatus\".\"declination\", "
  "\"at60gimbalstatus\".\"J2000RightAscension\", "
  "\"at60gimbalstatus\".\"J2000Declination\", "
  "\"at60gimbalstatus\".\"azmiuth\", "
  "\"at60gimbalstatus\".\"elevation\", "
  "\"at60gimbalstatus\".\"derotatorPositon\", "
  "\"at60gimbalstatus\".\"targetRightAscension\", "
  "\"at60gimbalstatus\".\"targetDeclination\", "
  "\"at60gimbalstatus\".\"targetJ2000RightAscension\", "
  "\"at60gimbalstatus\".\"targetJ2000Declination\", "
  "\"at60gimbalstatus\".\"targetAzmiuth\", "
  "\"at60gimbalstatus\".\"targetElevation\", "
  "\"at60gimbalstatus\".\"targetDerotatorPosition\", "
  "\"at60gimbalstatus\".\"axis1TrackError\", "
  "\"at60gimbalstatus\".\"axis2TrackError\", "
  "\"at60gimbalstatus\".\"axis3TrackError\", "
  "\"at60gimbalstatus\".\"axis4Angle\", "
  "\"at60gimbalstatus\".\"coverPosition\", "
  "\"at60gimbalstatus\".\"targetAxis4Angle\", "
  "\"at60gimbalstatus\".\"axis1Speed\", "
  "\"at60gimbalstatus\".\"axis2Speed\", "
  "\"at60gimbalstatus\".\"axis3Speed\", "
  "\"at60gimbalstatus\".\"refractionCorrection\", "
  "\"at60gimbalstatus\".\"axis1Encoder\", "
  "\"at60gimbalstatus\".\"axis2Encoder\", "
  "\"at60gimbalstatus\".\"axis3Encoder\", "
  "\"at60gimbalstatus\".\"axis1PMCorrection\", "
  "\"at60gimbalstatus\".\"axis2PMCorrection\", "
  "\"at60gimbalstatus\".\"axis3PMCorrection\", "
  "\"at60gimbalstatus\".\"axis1ManualCorrection\", "
  "\"at60gimbalstatus\".\"axis2ManualCorrection\", "
  "\"at60gimbalstatus\".\"axis3ManualCorrection\", "
  "\"at60gimbalstatus\".\"temperature1\", "
  "\"at60gimbalstatus\".\"temperature2\", "
  "\"at60gimbalstatus\".\"temperature3\", "
  "\"at60gimbalstatus\".\"temperature4\", "
  "\"at60gimbalstatus\".\"temperature5\", "
  "\"at60gimbalstatus\".\"temperature6\", "
  "\"at60gimbalstatus\".\"temperature7\", "
  "\"at60gimbalstatus\".\"temperature8\", "
  "\"at60gimbalstatus\".\"temperature9\", "
  "\"at60gimbalstatus\".\"temperature10\", "
  "\"at60gimbalstatus\".\"temperature11\", "
  "\"at60gimbalstatus\".\"temperature12\", "
  "\"at60gimbalstatus\".\"humidity1\", "
  "\"at60gimbalstatus\".\"humidity2\", "
  "\"at60gimbalstatus\".\"humidity3\", "
  "\"at60gimbalstatus\".\"humidity4\", "
  "\"at60gimbalstatus\".\"humidity5\", "
  "\"at60gimbalstatus\".\"humidity6\", "
  "\"at60gimbalstatus\".\"humidity7\", "
  "\"at60gimbalstatus\".\"humidity8\", "
  "\"at60gimbalstatus\".\"humidity9\", "
  "\"at60gimbalstatus\".\"humidity10\", "
  "\"at60gimbalstatus\".\"humidity11\", "
  "\"at60gimbalstatus\".\"humidity12\", "
  "\"at60gimbalstatus\".\"focusTypeIndex\", "
  "\"at60gimbalstatus\".\"coverIndex\", "
  "\"at60gimbalstatus\".\"targetFocusTypeIndex\", "
  "\"at60gimbalstatus\".\"targetCoverIndex\", "
  "\"at60gimbalstatus\".\"trackType\", "
  "\"at60gimbalstatus\".\"axis3Mode\", "
  "\"at60gimbalstatus\".\"pieSide\", "
  "\"at60gimbalstatus\".\"targetPieSide\", "
  "\"at60gimbalstatus\".\"isAxis1FindHome\", "
  "\"at60gimbalstatus\".\"isAxis2FindHome\", "
  "\"at60gimbalstatus\".\"isAxis3FindHome\" "
  "FROM \"at60gimbalstatus\"";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"at60gimbalstatus\"";

  const char access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::table_name[] =
  "\"at60gimbalstatus\"";

  void access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  void access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  void access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::pointer_type
  access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  bool access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  bool access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  bool access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  result< access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::object_type >
  access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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

  unsigned long long access::object_traits_impl< ::at60gimbalstatus, id_pgsql >::
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
          db.execute ("DROP TABLE IF EXISTS \"at60gimbalstatus\" CASCADE");
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
          db.execute ("CREATE TABLE \"at60gimbalstatus\" (\n"
                      "  \"id\" BIGSERIAL NOT NULL PRIMARY KEY,\n"
                      "  \"sec\" INTEGER NOT NULL,\n"
                      "  \"msec\" INTEGER NOT NULL,\n"
                      "  \"curstatus\" INTEGER NOT NULL,\n"
                      "  \"lastStatus\" INTEGER NOT NULL,\n"
                      "  \"warning\" BIGINT NOT NULL,\n"
                      "  \"error\" BIGINT NOT NULL,\n"
                      "  \"errorString\" TEXT NOT NULL,\n"
                      "  \"trackObjectName\" TEXT NOT NULL,\n"
                      "  \"siderealTime\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"hourAngle\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"rightAscension\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"declination\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"J2000RightAscension\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"J2000Declination\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"azmiuth\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"elevation\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"derotatorPositon\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetRightAscension\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetDeclination\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetJ2000RightAscension\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetJ2000Declination\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetAzmiuth\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetElevation\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetDerotatorPosition\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis1TrackError\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis2TrackError\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis3TrackError\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis4Angle\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"coverPosition\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"targetAxis4Angle\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis1Speed\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis2Speed\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis3Speed\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"refractionCorrection\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis1Encoder\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis2Encoder\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis3Encoder\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis1PMCorrection\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis2PMCorrection\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis3PMCorrection\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis1ManualCorrection\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis2ManualCorrection\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"axis3ManualCorrection\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature1\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature2\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature3\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature4\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature5\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature6\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature7\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature8\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature9\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature10\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature11\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"temperature12\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity1\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity2\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity3\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity4\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity5\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity6\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity7\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity8\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity9\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity10\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity11\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"humidity12\" DOUBLE PRECISION NOT NULL,\n"
                      "  \"focusTypeIndex\" SMALLINT NOT NULL,\n"
                      "  \"coverIndex\" SMALLINT NOT NULL,\n"
                      "  \"targetFocusTypeIndex\" SMALLINT NOT NULL,\n"
                      "  \"targetCoverIndex\" SMALLINT NOT NULL,\n"
                      "  \"trackType\" SMALLINT NOT NULL,\n"
                      "  \"axis3Mode\" SMALLINT NOT NULL,\n"
                      "  \"pieSide\" SMALLINT NOT NULL,\n"
                      "  \"targetPieSide\" SMALLINT NOT NULL,\n"
                      "  \"isAxis1FindHome\" SMALLINT NOT NULL,\n"
                      "  \"isAxis2FindHome\" SMALLINT NOT NULL,\n"
                      "  \"isAxis3FindHome\" SMALLINT NOT NULL)");
          return false;
        }
      }
    }

    return false;
  }

  static const schema_catalog_create_entry
  create_schema_entry_ (
    id_pgsql,
    "",
    &create_schema);
}

#include <odb/post.hxx>
