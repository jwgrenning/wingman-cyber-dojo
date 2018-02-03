import unittest
from kata_time_summary import *

multiple_increments = [
  {'colour': 'amber', 'number': 1, 'time': [2018, 1, 7, 10, 20, 30]},
  {'colour': 'red',   'number': 2, 'time': [2018, 1, 7, 10, 30, 30]},
  {'colour': 'green', 'number': 3, 'time': [2018, 1, 7, 11, 00, 31]}]


class KataSummaryTest(unittest.TestCase):

  def test_empty_increments_as_csv(self):
    self.assertEqual("", critter_increments([]))

  def test_empty_increments_as_csv(self):
    increment = [{'colour': 'amber', 'number': 1, 'time': [2018, 1, 7, 18, 9, 34]}]

    self.assertEqual("1, amber, 2018-01-07, 18:09:34, 0, 0.0, 0, 0.0\n", critter_increments_as_csv(increment))

  def test_multiple_increments_as_csv(self):
    increment = multiple_increments

    expected = \
      "1, amber, 2018-01-07, 10:20:30, 0, 0.0, 0, 0.0\n" +\
      "2, red, 2018-01-07, 10:30:30, 600, 10.0, 600, 10.0\n" +\
      "3, green, 2018-01-07, 11:00:31, 1801, 30.0, 2401, 40.0\n"
    self.assertEqual(expected, critter_increments_as_csv(multiple_increments))

if __name__ == '__main__':
    unittest.main()


'1, amber, 2018-01-07, 10:20:30, 0, 0, 0\n2, red, 2018-01-07, 10:30:30, 600, 10.0, 600, 10.0\n3, green, 2018-01-07, 11:00:31, 1801, 30.0, 2401, 40.0\n'
'1, amber, 2018-01-07, 10:20:30, 0, 0, 0\n2, red, 2018-01-07, 10:30:30, 600, 10.0, 600, 10.0\n3, green, 2018-01-07, 11:00:31, 1801, 30.0, 2401, 40.0\n'


