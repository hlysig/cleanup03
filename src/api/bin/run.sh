#!/usr/bin/env bash

BIN_DIR="$(cd "$( dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
ROOT_DIR="$BIN_DIR/.."

cd "$ROOT_DIR/api"
"$ROOT_DIR/.venv/bin/gunicorn" --bind 0.0.0.0:5000 wsgi:app
