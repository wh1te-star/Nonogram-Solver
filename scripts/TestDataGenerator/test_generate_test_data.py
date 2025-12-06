import unittest
from generate_test_data import construct_line_string

class TestGenerateTestData(unittest.TestCase):
    
    def test_calculate_constraints_basic(self):
        hint_set = [3, 2]
        extra_whites = [1, 0, 2]
        expected = ".###.##.."
        
        actual = construct_line_string(hint_set, extra_whites)
        self.assertEqual(actual, expected)

if __name__ == '__main__':
    unittest.main()