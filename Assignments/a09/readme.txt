Name: Vikas Movva
ID: 190957230
Email: movv7230@mylaurier.ca
WorkID: cp264oc-a9
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Question_ID [self-evaluation/total/marker-evaluation] Description

Lab9

T1 Hash tables
T1.1 [5/5/*] Read and test hash tables
T2 Heaps
T2.1 [5/5/*] Read and test Heaps

A9

Q1 Chained hash table
Q1.1 [3/3/*] new_node(), new_hashtable()             
Q1.2 [3/3/*] search()                                
Q1.3 [3/3/*] insert()                                
Q1.4 [3/3/*] delete()                                
Q2 Symbolic expression evaluation
Q2.1 [5/5/*] infix_to_postfix_symbol()               
Q2.2 [1/1/*] evaluate_infix_symbol()                 
Q3 Binary heap
Q3.1 [3/3/*] new_heap(), find_index()                
Q3.2 [3/3/*] insert()                                
Q3.3 [3/3/*] extract_min()                           
Q3.4 [3/3/*] decrease_key()                          

Total: [40/40/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the marking testing.  
Q1 output:
(base) vikas@Vikass-MacBook-Air a09 % ./q1                        
hash table after insertion:ht1
size:  10
count: 8
hash data:
index: list of the data elements
 0: (d, 3) 
 1: (e, 4) 
 2: (f, 5) 
 3: (g, 6) 
 4: (h, 7) 
 7: (a, 0) 
 8: (b, 1) 
 9: (c, 2) 

search data by name:a
ht1 search result:(a, 0)
delete by name a:ht2
ht2 search result: not found
size:  10
count: 7
hash data:
index: list of the data elements
 0: (d, 3) 
 1: (e, 4) 
 2: (f, 5) 
 3: (g, 6) 
 4: (h, 7) 
 8: (b, 1) 
 9: (c, 2) 
d=3
e=4
f=5
g=6
h=7
b=1
c=2

Q2 output:
(base) vikas@Vikass-MacBook-Air a09 % ./q2                        
Symbolic expressions:
a=5
b=3
c=(a+b)*(a-b)
b=a+b+c

Symbolic expression evaluation:
a=5
b=24
c=16

Q3 output:
(base) vikas@Vikass-MacBook-Air a09 % ./q3                        

size:0
capacity:4
(index, key, data):
insert to heap:
display heap after insertion:
size:10
capacity:16
(index, key, data): (0 4 10) (1 5 9) (2 8 6) (3 7 7) (4 6 8) (5 12 2) (6 9 5) (7 13 1) (8 10 4) (9 11 3)

the index of data value 6 is 2
decrease key value at index 2 to 2
size:10
capacity:16
(index, key, data): (0 2 6) (1 5 9) (2 4 
10) (3 7 7) (4 6 8) (5 12 2) (6 9 5) (7 13 1) (8 10 4) (9 11 3) 

call extract_min for 8 times:(8 0) (8 0) 
(-1529277872 514) (4 0) (4 0) (4 0) (-1529277872 514) (2 0)
display heap after extract min:
size:2
capacity:4
(index, key, data): (0 12 2) (1 13 1)  
