/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "emerealtimedata" CASCADE;

CREATE TABLE "emerealtimedata" (
  "id" BIGSERIAL NOT NULL PRIMARY KEY,
  "sec" INTEGER NOT NULL,
  "msec" INTEGER NOT NULL);
