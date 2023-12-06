# PhysicsWallah

## Problem Statement
Implement SortingHat : A school hostel assignment Program
New students join a school and need to be assigned to one of 4 boarding houses. As students come in, they register their roll number, class & food preference. 
There are 2 classes - A and B, and two food preferences - V & NV. There are 4 boarding houses with equal but limited capacity.
The hat follows a first in first out policy with the following rules -
● Queue will be processed based on the time a student registered, first in first out
● Boarding houses for students who prefer V cannot board NV students
● Boarding houses for class A would be separate from boarding houses for class B
● Once all boarding houses are filled up to capacity, no more students can be allocated.
Other rules:
● Roll number is a 4 digit integer unique to each student
● Student can only be registered once, duplicate commands for same student may be ignored

## Solution

Approach: Just take the inputs until we get input as "fin"
set the class limit after taking the init input and dividing it into 4 classes

now just take all the queries as input and make a map which contains 
vectors as value and type of class as a key 

get the class type by adding/concatenating the strings of the class and food types 
Now, push the roll no. of all the students to the particular vector in map according to the key
which we got using the type of food and class

Finally print all the classes
