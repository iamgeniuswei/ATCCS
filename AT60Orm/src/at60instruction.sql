/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "at60instruction" CASCADE;

CREATE TABLE "at60instruction" (
  "id" BIGSERIAL NOT NULL PRIMARY KEY,
  "sec" INTEGER NOT NULL,
  "msec" INTEGER NOT NULL,
  "user" INTEGER NOT NULL,
  "device" SMALLINT NOT NULL,
  "sequence" INTEGER NOT NULL,
  "plan" INTEGER NOT NULL,
  "instruction" INTEGER NOT NULL,
  "param" TEXT NOT NULL,
  "result" INTEGER NOT NULL);
