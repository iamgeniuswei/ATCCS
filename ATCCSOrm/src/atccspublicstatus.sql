/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "ATCCSPublicStatus" CASCADE;

CREATE TABLE "ATCCSPublicStatus" (
  "id" BIGSERIAL NOT NULL PRIMARY KEY,
  "sec" INTEGER NOT NULL,
  "msec" INTEGER NOT NULL,
  "curstatus" INTEGER NOT NULL,
  "lastStatus" INTEGER NOT NULL,
  "warning" INTEGER NOT NULL,
  "error" INTEGER NOT NULL,
  "errorString" TEXT NOT NULL);

