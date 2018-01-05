#!/bin/bash

if [ $# != 0 ] ; then
  echo "usage: $0"
  exit 1
fi

if [ ! -f "start_point_type.json" ] ; then
  echo "Run from the root of the start point"
  exit 1
fi

enable_initial_test_failure()
{
  sedOptions="-i'' -f"
  if [ "$(uname)" == "Linux" ]; then
    sedOptions="-i"
  fi

  echo "Enable initial test failures"
  # files=$(git status -u *Test.cpp | grep "languages/" | xargs grep -l '//.*FAIL("Start here")')
  files=$(find . -name "*Test.cpp" | xargs grep -l "//.*FAIL")

  for file in $files
  do
      echo "enable initial FAIL in ${file}"
      sed -e's:^// *FAIL:    FAIL:g' $sedOptions $file
  done
}

CYBER_DOJO_COMMAND_LOCATION=..
cp -f grafana.env $CYBER_DOJO_COMMAND_LOCATION

git reset --hard
git pull
enable_initial_test_failure
