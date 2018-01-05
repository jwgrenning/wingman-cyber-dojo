pushd docker/
./cyber-dojo down
./cyber-dojo up --custom=wingman
a=http://$(docker-machine ip default):3000
echo "Your server is " + $a
open $a
popd
