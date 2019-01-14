#!/usr/bin/env bash
grep -E -o '[a-zA-Z0-9_\-]+[.]c\s' $1 | sort | uniq