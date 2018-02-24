if [ ! -f "start_point_type.json" ] ; then
  echo "Run from the root of the start point"
  exit 1
fi

exercises=""
while read -r line || [[ -n "$line" ]]; do
    echo "Text read from file: $line"
    id=$(echo $line | cut -d',' -f1)
    exercises=$exercises $id
done < "scripts/kata-ids.csv"

echo Exercises: $exercises

KATA_DIR=../kata-capture
mkdir -p $KATA_DIR

for exercise in exercises; do
  dir1=${exercise:0:2}
  dir2=${exercise:2:8}
  docker cp cyber-dojo-storer:/usr/src/cyber-dojo/katas/$dir1/$dir2/ $KATA_DIR
  pushd $KATA_DIR
  rm -rf $exercise
  mv $dir2 $exercise
  popd
done
