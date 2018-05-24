# ADT-Map---On-Hash-Table
­ADT Map – implementation on hash table, collision by open addressing

Domain:
	M = {m | m is a map with elements e = (k, v), where k is a TKey and v is a TValue}

Representation of the container: hash table, collision by open addressing, linear probing
T: Telem[]
h: Tfunction
m: Integer (representing the length of the array)


Problem statement:
	A parking lot has a capacity of m cars, divided in n areas (named 1, 2, 3, 4, …, n).  Every parked car has a licence plate, and it’s registered when it is parked. The licence plate has the form “SS NN SSS”. In case the owner of the car has forgotten where he parked the car, he can use the application to find the area. The application requests the licence plate and it will display the place where it is parked. After displaying the area, the application considers that the car has left, and it removes the car from the parking lot.

Description of solution:
	A map is suitable for solving the problem because each car has a different key (the licence plate) and an associated value (the number of the area). ...
