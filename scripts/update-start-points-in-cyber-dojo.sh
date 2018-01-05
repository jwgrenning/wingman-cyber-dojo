if [ $# != 1 ] ; then
  echo "usage $0 start-point-name"
  exit 1
fi

if [ ! -f "start_point_type.json" ] ; then
  echo "Run from the root of the start point"
  exit 1
fi

../cyber-dojo down
../cyber-dojo start-point rm $1
../cyber-dojo start-point create $1 --dir=${PWD}
../cyber-dojo start-point ls
../cyber-dojo up --custom=$1
