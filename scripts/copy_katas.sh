if [[ $# != 1 || ${#1} -ne 10 ]] ; then
#if [[ $# != 1 ]] ; then
  echo "usage $0 AB12345678"
  exit 1
fi
exercise=$1
dir1=${exercise:0:2}
dir2=${exercise:2:8}
echo docker cp cyber-dojo-storer:/usr/cyber-dojo/$dir1/$dir2