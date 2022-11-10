Name: ???
ID: ???
Email: ???
WorkID: cp264oc-a7
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Question_ID [self-evaluation/total/marker-evaluation] Description

Lab7

T1 Binary trees
T1.1 [4/4/*] Read and test simple binary tree
T2 Expression tree
T2.1 [4/4/*] Read and test expression tree   
T3 Huffman tree
T3.1 [2/2/*] Read and test Huffman tree      

A7

Q1 Basic binary tree and operations
Q1.1 [3/3/*] get_props()                             
Q1.2 [3/3/*] display_preorder/inorder/postorder()    
Q1.3 [3/3/*] iterative_bf_search()                   
Q1.4 [3/3/*] iterative_df_search()                   
Q2 BST for marks data processing
Q2.1 [3/3/*] search()                                
Q2.2 [3/3/*] insert()                                
Q2.3 [3/3/*] extract_smallest_node()                 
Q2.4 [3/3/*] delete()                                
Q2.5 [3/3/*] add_data()                              
Q2.6 [3/3/*] remove_data()                           

Total: [40/40/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the marking testing.  

Q1 output:
$ ./q1
display_tree():
|___A
    |___C
        |___G
        |___F
    |___B
        |___E
        |___D
get_props().count:7
get_props().height:3
display_preorder():A B D E C F G 
display_postorde():D E B F G C A
display_inorder():D B E A F C G

Q2 output:
$ ./q2
count          20
mean           77.9
stddev         12.6
Ali            88.0
Allison        67.7
Bodnar         93.6
Chabot         80.4
Costa          45.1
Dabu           74.4
Eccles         77.8
Giblett        59.1
Hatch          66.5
He             85.7
Koreck         77.4
Lamont         98.1
Myrie          76.7
Parr           92.5
Pereira        80.3
Peters         82.3
Smith          60.1
Suglio         85.7
Sun            67.7
Wang           98.1
search(Smith):Smith 60
search(Moore):Moore 92
search(Wang):NULL
count:20
mean:78
stddev:12
Ali,88.0,A
Allison,67.7,C
Bodnar,93.6,S
Chabot,80.4,A
Costa,45.1,F
Dabu,74.4,B
Eccles,77.8,B
Giblett,59.1,D
Hatch,66.5,C
He,85.7,A
Koreck,77.4,B
Lamont,98.1,S
Moore,92.0,S
Myrie,76.7,B
Parr,92.5,S
Pereira,80.3,A
Peters,82.3,A
Smith,60.1,C
Suglio,85.7,A
Sun,67.7,C


