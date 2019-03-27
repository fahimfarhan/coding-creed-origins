import unittest
from start import *

class TestDrivenDevelopment(unittest.TestCase):
    
    def test_starting_out(self):
        self.assertEqual(1, 1)
        self.assertEqual(2,2)
    
    def test_add(self):
        self.assertEqual(add(1,2), 3)
    
    def test_sub(self):
        self.assertEqual( sub(3,1), 2 )

    def test_div(self):
        self.assertEqual(div(6,3),2)
        self.assertEqual(div(7,2),3.5)
    
    def test_multiply(self):
        self.assertEqual(multiply(2,3), 6)

    

def main():
    unittest.main()

if __name__ == "__main__":
    main()