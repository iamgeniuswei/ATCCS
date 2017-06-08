# ATCCS
ATCCS is the abbreviation of Astronomical Telescope Central Control System.
## Database Related Design
In ATCCS Project, we use 'ODB' to handle all the database related operation,
so we have to pre-compile data persist class.
The compile order is:
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --generate-query --generate-session ***.h
