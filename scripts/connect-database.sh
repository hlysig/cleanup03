#!/bin/bash
set -euo pipefail

# A script to facilitate logging onto the current MADS database and exploring it via psql

PGPASSWORD=${MADS_PASS} psql -q -h ${MADS_HOST} -p ${MADS_PORT} -U ${MADS_USER} ${MADS_DB} 
