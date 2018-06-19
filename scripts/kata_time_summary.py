import os
import sys
import glob
import json
import datetime

def make_date(time):
  return "{:04d}-{:02d}-{:02d}".format(time[0], time[1], time[2])

def make_time(time):
  return "{:02d}:{:02d}:{:02d}".format(time[3], time[4], time[5])

def time_from(seq):
  return datetime.datetime(seq[0], seq[1], seq[2], seq[3], seq[4], seq[5])

def make_duration(last, current):
  dt = delta_time(last, current)
  return '{: 6d}, {: 8.1f}'.format(dt.seconds, dt.seconds/60.0)

def delta_time(last, current):
  if last == None:
    last = current
  t0 = time_from(last)
  t1 = time_from(current)
  return  t1 - t0

def critter_increments_as_csv(json_in):
  csv_lines = ""
  last_time = None
  t0 = None
  for incr in json_in:
    time_string = make_time(incr['time'])
    if t0 == None:
      t0 = incr['time']

    current_time = incr['time']
    incr_duration = make_duration(last_time, current_time)
    total_duration = make_duration(t0, current_time)
    discontinuity = ''
    dt = delta_time(last_time, current_time).seconds/60.0
    if dt >= 10.0:
      discontinuity = ', {: 8.1f}'.format(dt)
    csv_lines += "{: 3d}, {:5s}, {}, {}, {}, {}{}\n".format(
      incr['number'],
      incr['colour'],
      make_date(incr['time']),
      time_string,
      incr_duration,
      total_duration,
      discontinuity)
    last_time = incr['time']
  return str(csv_lines.count('\n')), csv_lines

def make_dir_for(filename):
    if not os.path.exists(os.path.dirname(filename)):
        try:
            os.makedirs(os.path.dirname(filename))
        except OSError as exc: # Guard against race condition
            if exc.errno != errno.EEXIST:
                raise

def from_increments_filename(incr):
    exercise = incr.split("/")[2]
    kata_id = exercise.split("-")[0]
    language = exercise.split("-")[1]
    animal = incr.split("/")[3]
    return kata_id, exercise, animal, language

def write_kata_analysis(lines, kata_output_dir, exercise, animal, incr_count):
  incr_count = lines.count('\n')
  output_filename = kata_output_dir + "/" + exercise + "-" + animal + "-{}".format(incr_count)
  if incr_count <= 5:
    print "Skipping: " + output_filename
  else:
    make_dir_for(output_filename + ".csv")
    output = open(output_filename + ".csv", "w")
    print 'Writing', output_filename
    output.write(output_filename + ", signal, date, time, seconds, minutes, total seconds, total minutes, discontinuity\n")
    output.write(lines)
    output.write("\nOriginal, kata: http://research.wingman-sw.com/kata/edit/" + exercise[:exercise.find('-')] + "?avatar=" + animal + "\n")
    output.write("Reference tests, \n")
    output.write("Passes tests\n")
    output.write("Fails tests: #\n")
    output.write("Test coverag: #%\n")
    output.write("\n")
    output.close()

TGZ_DIR = './kata-code/'

def tgz_filename(kata_id, animal, incr_count):
  return TGZ_DIR + kata_id + '_' + animal + '_' + incr_count + '.tgz'

def unpacked_dir(kata_id, animal, incr_count):
  return TGZ_DIR + kata_id + '/' + animal + '/' + incr_count

def get_code_tgz(kata_id, animal, incr_count):
  wget_filename = 'http://research.wingman-sw.com/download_tag/' + kata_id + '/' + animal + '/' + incr_count
  print 'Getting: ' + wget_filename
  result = os.system('wget --append-output=wget.log ' + wget_filename)
  if result == 0:
    move_to = tgz_filename(kata_id, animal, incr_count)
    make_dir_for(move_to)
    os.rename(incr_count, move_to)

def unpack_code(kata_id, animal, incr_count):
  packed_filename = tgz_filename(kata_id, animal, incr_count)
  code_dir = unpacked_dir(kata_id, animal, incr_count)
  if os.path.exists(code_dir):
    print 'Directory already exists, NOT unpacking'
  else:
    print packed_filename + ": Unpacking"
    if 0 != os.system('tar -C ' + TGZ_DIR + ' -xf ' + packed_filename):
      print 'Error unpacking: ' + tgz_filename(kata_id, animal, incr_count)
    else:
      print "Adding in files to reference and gcov tesst run"
      os.system('cp scripts/my-tests/make-gcov.sh ' + make_dir)
      os.system('cp scripts/my-tests/AllTests.cpp ' + make_dir)
      os.system('cp scripts/my-tests/reference-makefile-' + language + '.mk ' + ref_make_file)
      os.system('cp scripts/my-tests/CircularBufferTest-' + language + '.cpp ' + make_dir + '/CircularBufferTest-Ref.cpp')

def make_authors_code(kata_id, animal, incr_count, language):
  make_dir = unpacked_dir(kata_id, animal, incr_count)
  ref_make_file = make_dir + '/reference-makefile.mk'
  os.system('(cd ' + make_dir + '; source make-gcov.sh >test_run_reference.txt)')
  os.system('(cd ' + make_dir + '; grep ".*%   CircularBuffer.c" test_run_reference.txt)')
  os.system('(cd ' + make_dir + '; grep "OK (.*)" test_run_reference.txt)')
  os.system('(cd ' + make_dir + '; grep "Errors (.*)" test_run_reference.txt)')


def main(kata_capture_dir, kata_output_dir, kata_id):
  increments = glob.glob("./" + kata_capture_dir + "/" + kata_id + "-C-CppUTest/*/increments.json")
  log = open(kata_id + "-Summary.log", "w")
  for incr in increments:
    timing = open(incr, "r")
    incr_count, lines = critter_increments_as_csv(json.load(timing))
    if int(incr_count) <= 5:
      log.write(incr + ": Skip\n")
      print "\n------ Skipping: only " + incr_count + ' increments in ' + incr
    else:
      log.write(incr + "\n")
      print "\n------ Doing: " + incr
      kata_id, exercise, animal, language = from_increments_filename(incr)
      write_kata_analysis(lines, kata_output_dir, exercise, animal, incr_count)
      get_code_tgz(kata_id, animal, incr_count)
      unpack_code(kata_id, animal, incr_count)
      make_authors_code(kata_id, animal, incr_count, language)

if __name__ == '__main__':
    kata_capture_dir = "kata-capture"
    kata_output_dir = "kata-analysis"
    if len(sys.argv) >= 2:
      kata_capture_dir = sys.argv[1]
    if len(sys.argv) == 3:
      kata_output_dir = sys.argv[2]

    kata_id = '988ACE7E7B'

    print kata_capture_dir + " " + kata_output_dir + kata_id

    main(kata_capture_dir, kata_output_dir, kata_id)
