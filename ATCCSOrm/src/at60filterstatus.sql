/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "at60filterstatus" CASCADE;

CREATE TABLE "at60filterstatus" (
  "id" BIGSERIAL NOT NULL PRIMARY KEY,
  "sec" INTEGER NOT NULL,
  "msec" INTEGER NOT NULL,
  "curstatus" INTEGER NOT NULL,
  "lastStatus" INTEGER NOT NULL,
  "warning" INTEGER NOT NULL,
  "error" INTEGER NOT NULL,
  "errorString" TEXT NOT NULL,
  "filterPosition" SMALLINT NOT NULL,
  "targetFilterPosition" SMALLINT NOT NULL,
  "isHomed" SMALLINT NOT NULL);

