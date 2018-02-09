if [ -f "start_point_type.json" ] ; then
  echo "Do not run from the root of the start point"
  exit 1
fi

start_point_root=wingman-cyber-dojo
if [ ! -d start_point_root ] ; then
  echo "Run from just above ${start_point_root}"
  exit 1
fi

if [[ $# != 1 || ${#1} -ne 10 ]] ; then
  echo "usage $0 AB12345678"
  exit 1
fi
exercise=$1
mkdir -p kata-capture
dir1=${exercise:0:2}
dir2=${exercise:2:8}
docker cp cyber-dojo-storer:/usr/src/cyber-dojo/katas/$dir1/$dir2/ kata-capture/
pushd kata-capture
rm -rf $exercise
mv $dir2 $exercise
popd
