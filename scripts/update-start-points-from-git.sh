#!/bin/bash
CYBER_DOJO_COMMAND_LOCATION=.
if [ $# != 0 ] ; then
  echo "usage: $0"
  exit 1
fi

if [ ! -f "start_point_type.json" ] ; then
  echo "Run from the root of the start point"
  exit 1
fi

CYBER_DOJO_COMMAND_LOCATION=..
cp -f scripts/grafana.env $CYBER_DOJO_COMMAND_LOCATION

git reset --hard
git pull
