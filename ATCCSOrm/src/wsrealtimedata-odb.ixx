// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // wsrealtimedata
  //

  inline
  access::object_traits< ::wsrealtimedata >::id_type
  access::object_traits< ::wsrealtimedata >::
  id (const object_type& o)
  {
    return object_traits< ::emerealtimedata >::id (o);
  }

  inline
  void access::object_traits< ::wsrealtimedata >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::wsrealtimedata >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

namespace odb
{
  // wsrealtimedata
  //

  inline
  access::object_traits_impl< ::wsrealtimedata, id_pgsql >::id_type
  access::object_traits_impl< ::wsrealtimedata, id_pgsql >::
  id (const id_image_type& i)
  {
    return object_traits_impl< ::emerealtimedata, id_pgsql >::id (i);
  }

  inline
  access::object_traits_impl< ::wsrealtimedata, id_pgsql >::id_type
  access::object_traits_impl< ::wsrealtimedata, id_pgsql >::
  id (const image_type& i)
  {
    return object_traits_impl< ::emerealtimedata, id_pgsql >::id (i);
  }

  inline
  void access::object_traits_impl< ::wsrealtimedata, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    object_traits_impl< ::emerealtimedata, id_pgsql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::wsrealtimedata, id_pgsql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::emerealtimedata, id_pgsql >::init (i, id);
  }

  inline
  void access::object_traits_impl< ::wsrealtimedata, id_pgsql >::
  erase (database& db, const object_type& obj)
  {
    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj));
    callback (db, obj, callback_event::post_erase);
  }

  inline
  void access::object_traits_impl< ::wsrealtimedata, id_pgsql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool)
  {
    ODB_POTENTIALLY_UNUSED (sts);
    ODB_POTENTIALLY_UNUSED (obj);
  }
}

