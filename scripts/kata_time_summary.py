import glob
import json

def make_date(time):
  return "{:04d}-{:02d}-{:02d}".format(time[0], time[1], time[2])

def make_time(time):
  return "{:02d}:{:02d}:{:02d}".format(time[3], time[4], time[5])

def time_from(seq):
  return seq[3]*60*60 + seq[4]*60 + seq[5]

def make_duration(last, current):
  if last == None:
    last = current
  t0 = time_from(last)
  t1 = time_from(current)
  return '{:d}, {:2.1f}'.format(t1-t0, (t1-t0)/60)

def critter_increments_as_csv(json_in):
  csv_lines = ""
  last_time = None
  t0 = None
  for incr in json_in:
    time_string = make_time(incr['time'])
    if t0 == None:
      t0 = incr['time']
    csv_lines += "{0}, {1}, {2}, {3}, {4}, {5}\n".format(
      incr['number'],
      incr['colour'],
      make_date(incr['time']),
      time_string,
      make_duration(last_time, incr['time']),
      make_duration(t0, incr['time']))
    last_time = incr['time']
  return csv_lines


def main():
  increments = glob.glob("kata-capture/*/*/increments.json")
  for incr in increments:
    exercise = incr.split("/")[1]
    animal = incr.split("/")[2]
    output = open("kata-capture/" + exercise + "/" + animal + ".csv", "w") 
    output.write("N, signal, date, time, seconds, minutes, total seconds, total minutes\n")
    timing = open(incr, "r")
    lines = critter_increments_as_csv(json.load(timing))
    output.write(lines)
    output.close()

if __name__ == '__main__':
    # if len(sys.argv) != 1:
    #   print "Usage: {0} path match-string {1}".format(sys.argv[0], len(sys.argv))
    #   exit(0)
    main()
