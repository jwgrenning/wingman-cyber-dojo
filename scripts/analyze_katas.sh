
python ./scripts/kata-time_summary.py
def add_run_script():
  return '''
runtest()
{
  id = $1
  animal = $2
  iteration = $3  
  wget  http://research.wingman-sw.com/download_tag/$id/$animal/$iteration
  tar -xf ${id}_${animal}_${iteration}
  cd ${id}/${animal}/${iteration}
  sh make-gcov.sh >user_run.txt
  # copy the makefile and test filename
  sh make-gcov.sh >reference_run.txt
}
'''
