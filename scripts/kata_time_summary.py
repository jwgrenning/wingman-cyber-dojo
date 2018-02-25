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
  if last == None:
    last = current
  t0 = time_from(last)
  t1 = time_from(current)
  dt = t1 - t0
  return '{: 6d}, {: 8.1f}'.format(dt.seconds, dt.seconds/60)

def critter_increments_as_csv(json_in):
  csv_lines = ""
  last_time = None
  t0 = None
  for incr in json_in:
    time_string = make_time(incr['time'])
    if t0 == None:
      t0 = incr['time']
    csv_lines += "{: 3d}, {:5s}, {}, {}, {}, {}\n".format(
      incr['number'],
      incr['colour'],
      make_date(incr['time']),
      time_string,
      make_duration(last_time, incr['time']),
      make_duration(t0, incr['time']))
    last_time = incr['time']
  return csv_lines

def make_dir_for(filename):
    if not os.path.exists(os.path.dirname(filename)):
        try:
            os.makedirs(os.path.dirname(filename))
        except OSError as exc: # Guard against race condition
            if exc.errno != errno.EEXIST:
                raise

def main(kata_capture_dir, kata_output_dir):
  increments = glob.glob("../" + kata_capture_dir + "/*/*/increments.json")
  for incr in increments:
    timing = open(incr, "r")
    lines = critter_increments_as_csv(json.load(timing))
    exercise = incr.split("/")[2]
    animal = incr.split("/")[3]
    output_filename = kata_output_dir + "/" + exercise + "-" + animal + "-{}".format(lines.count('\n'))
    make_dir_for(output_filename + ".csv")
    output = open(output_filename + ".csv", "w")
    output.write(output_filename + ", signal, date, time, seconds, minutes, total seconds, total minutes\n")
    output.write(lines)
    output.close()

if __name__ == '__main__':
    kata_capture_dir = "kata-capture"
    kata_output_dir = "kata-analysis"
    if len(sys.argv) >= 2:
      kata_capture_dir = sys.argv[1]
    if len(sys.argv) == 3:
      kata_output_dir = sys.argv[2]

    print kata_capture_dir + " " + kata_output_dir
    main(kata_capture_dir, kata_output_dir)
