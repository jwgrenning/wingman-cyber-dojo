if [ ! -f "start_point_type.json" ] ; then
  echo "Run from the root of the start point"
  exit 1
fi

if [[ $# != 1 || ${#1} -ne 10 ]] ; then
  echo "usage $0 AB12345678"
  exit 1
fi
exercise=$1
KATA_DIR=../kata-capture
mkdir -p $KATA_DIR
dir1=${exercise:0:2}
dir2=${exercise:2:8}
docker cp cyber-dojo-storer:/usr/src/cyber-dojo/katas/$dir1/$dir2/ $KATA_DIR
pushd $KATA_DIR
rm -rf $exercise
mv $dir2 $exercise
popd
