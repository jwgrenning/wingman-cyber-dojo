# This should be run via source command
get_out=NO
if [ $# != 1 ] ; then
  echo "usage $0 start-point-name"
else
  if [ ! -f "start_point_type.json" ] ; then
    echo "Run from the root of the start point"
  else
    ../cyber-dojo down
    ../cyber-dojo start-point rm $1
    ../cyber-dojo start-point create $1 --dir=${PWD}
    ../cyber-dojo start-point ls
    ../cyber-dojo up --custom=$1
  fi
fi
