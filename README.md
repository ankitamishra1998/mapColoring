# mapColoring

1. Clone the repository<br />
2. In the command line, type 'make'<br />
3. In the comman line, type './mapColor'<br />

# Input.txt

1. Each line of this file include the node (the first letter in the line) and its neighbors (the rest of the alphabets).<br />
Ex. In the sample input.txt:<br />
ABC  (A is the node, and B and C are its neighbors)<br />
BACDE (")<br />
CABDF (")<br />
DBCF (")<br />
EBG (")<br />
FCDG (")<br />
GEF (")<br />

# Output

Key: A Values: 1<br />
Key: B Values: 2<br />
Key: C Values: 3<br />
Key: D Values: 1<br />
Key: E Values: 1<br />
Key: F Values: 2<br />
Key: G Values: 3<br />

This result indicates which color (integers in this case) each of the nodes should be assigned in order to ensure that no adjacent nodes have the same color.

