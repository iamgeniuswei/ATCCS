/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "at60focusstatus" CASCADE;

CREATE TABLE "at60focusstatus" (
  "id" BIGSERIAL NOT NULL PRIMARY KEY,
  "sec" INTEGER NOT NULL,
  "msec" INTEGER NOT NULL,
  "curstatus" INTEGER NOT NULL,
  "lastStatus" INTEGER NOT NULL,
  "warning" INTEGER NOT NULL,
  "error" INTEGER NOT NULL,
  "errorString" TEXT NOT NULL,
  "isHomed" SMALLINT NOT NULL,
  "isTCompensation" SMALLINT NOT NULL,
  "position" DOUBLE PRECISION NOT NULL,
  "targetPosition" DOUBLE PRECISION NOT NULL,
  "temperature" DOUBLE PRECISION NOT NULL,
  "TCompenensation" DOUBLE PRECISION NOT NULL);
