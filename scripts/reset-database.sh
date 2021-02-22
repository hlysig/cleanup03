#!/bin/bash
set -euo pipefail

# A script to facilitate resetting and initialising the current MADS database using the MADS environment variables

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

#PGPASSWORD=${MADS_PASS} dropdb -h ${MADS_HOST} -p ${MADS_PORT} -U ${MADS_USER} ${MADS_DB}
#PGPASSWORD=${MADS_PASS} createdb -h ${MADS_HOST} -p ${MADS_PORT} -U ${MADS_USER} ${MADS_DB}
PGPASSWORD=${MADS_PASS} psql -q -h ${MADS_HOST} -p ${MADS_PORT} -U ${MADS_USER} ${MADS_DB} < ${SCRIPT_DIR}/../database/schema.sql

