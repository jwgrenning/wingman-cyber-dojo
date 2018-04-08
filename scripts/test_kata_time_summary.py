import unittest
from kata_time_summary import *


class KataSummaryTest(unittest.TestCase):

  def test_empty_increments_to_csv(self):
    self.assertEqual("", critter_increments_as_csv([]))

  def test_single_increments_to_csv(self):
    increment = [{'colour': 'amber', 'number': 1, 'time': [2018, 1, 7, 18, 9, 34]}]

    expected =\
      "  1, amber, 2018-01-07, 18:09:34,      0,      0.0,      0,      0.0\n"

    self.assertEqual(expected, critter_increments_as_csv(increment))

  def test_multiple_increments_as_csv(self):
    increments = [
      {'colour': 'amber', 'number': 1, 'time': [2018, 1, 7, 10, 20, 30]},
      {'colour': 'red',   'number': 2, 'time': [2018, 1, 7, 10, 30, 30]},
      {'colour': 'green', 'number': 3, 'time': [2018, 1, 7, 11, 00, 31]}]

    expected = (
      "  1, amber, 2018-01-07, 10:20:30,      0,      0.0,      0,      0.0\n" +\
      "  2, red  , 2018-01-07, 10:30:30,    600,     10.0,    600,     10.0\n" +\
      "  3, green, 2018-01-07, 11:00:31,   1801,     30.0,   2401,     40.0\n")
    self.assertEqual(expected, critter_increments_as_csv(increments))

  def test_days_change(self):
    increments = [
      {'colour': 'amber', 'number': 1, 'time': [2018, 1, 7, 23, 59, 00]},
      {'colour': 'red',   'number': 2, 'time': [2018, 1, 8, 00, 01, 01]},
      {'colour': 'green', 'number': 3, 'time': [2018, 1, 8, 10, 01, 01]}]

    expected = \
      "  1, amber, 2018-01-07, 23:59:00,      0,      0.0,      0,      0.0\n" +\
      "  2, red  , 2018-01-08, 00:01:01,    121,      2.0,    121,      2.0\n" +\
      "  3, green, 2018-01-08, 10:01:01,  36000,    600.0,  36121,    602.0\n"
    self.assertEqual(expected, critter_increments_as_csv(increments))

if __name__ == '__main__':
    unittest.main()


