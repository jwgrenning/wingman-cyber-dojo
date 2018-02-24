if [ ! -f "start_point_type.json" ] ; then
  echo "Run from the root of the start point"
  exit 1
fi

get_kata_ids()
{
  local ids=""
  while read -r line || [[ -n "$line" ]]; do
      id=$(echo $line | cut -d',' -f1)
      ids+=" ${id}"
  done < "scripts/kata-ids.csv"
  echo $ids  
}

KATA_DIR=../${1:kata-capture}
mkdir -p $KATA_DIR

for exercise in $(get_kata_ids); do
  echo "Copy: $exercise"
  dir1=${exercise:0:2}
  dir2=${exercise:2:8}
  docker cp cyber-dojo-storer:/usr/src/cyber-dojo/katas/$dir1/$dir2/ $KATA_DIR
  pushd $KATA_DIR  > /dev/null
  rm -rf $exercise
  mv $dir2 $exercise
  popd > /dev/null
done
