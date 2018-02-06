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
