#!/bin/bash
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

API_PROJECT_DIR="$SCRIPT_DIR/../src/api"

cd "$API_PROJECT_DIR"
.venv/bin/python api/wsgi.py
