import os
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

def main():
  increments = glob.glob("kata-capture/*/*/increments.json")
  for incr in increments:
    exercise = incr.split("/")[1]
    animal = incr.split("/")[2]
    output_filename = "kata-analysis/" + exercise + "-" + animal
    make_dir_for(output_filename + ".csv")
    output = open(output_filename + ".csv", "w")
    output.write(output_filename + ", signal, date, time, seconds, minutes, total seconds, total minutes\n")
    timing = open(incr, "r")
    lines = critter_increments_as_csv(json.load(timing))
    output.write(lines)
    output.close()

if __name__ == '__main__':
    # if len(sys.argv) != 1:
    #   print "Usage: {0} path match-string {1}".format(sys.argv[0], len(sys.argv))
    #   exit(0)
    main()
