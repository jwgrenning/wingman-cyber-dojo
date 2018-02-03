if [[ $# != 1 || ${#1} -ne 10 ]] ; then
  echo "usage $0 AB12345678"
  exit 1
fi
exercise=$1
dir1=${exercise:0:2}
dir2=${exercise:2:8}
docker cp cyber-dojo-storer:/usr/src/cyber-dojo/katas/$dir1/$dir2 kata-capture/$exercise