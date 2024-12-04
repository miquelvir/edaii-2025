#!/bin/bash

output=$(clang-format --dry-run -Werror **/*.c 2>&1)

if [[ -n "$output" ]]; then
  echo "$output"
  echo "To fix it, run: make f"
  exit 1
else
  exit 0
fi