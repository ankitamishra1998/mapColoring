# mapColoring

1. Clone the repository
2. In the command line, type 'make'
3. In the comman line, type './mapColor'

# Input.txt

1. Each line of this file include the node (the first letter in the line) and its neighbors (the rest of the alphabets).
Ex. In the sample input.txt:
ABC  (A is the node, and B and C are its neighbors)
BACDE (")
CABDF (")
DBCF (")
EBG (")
FCDG (")
GEF (")

# Output

Key: A Values: 1
Key: B Values: 2
Key: C Values: 3
Key: D Values: 1
Key: E Values: 1
Key: F Values: 2
Key: G Values: 3

This result indicates which color (integers in this case) each of the nodes should be assigned in order to ensure that no adjacent nodes have the same color.

