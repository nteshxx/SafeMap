
### SafeMap

In the wake of recent Chennai Floods, a local programmer having a good knowledge about areas of Chennai has decided to help the Army and various NGOs involved in the rescue process by designing a program which helps the local people and army by letting them know whether they can go safely from an area to another. For the same purpose, he’s decided to code all the areas as integers, for an example:

* Chepauk -> 0
* Marina Beach -> 1
* IIT Madras -> 2
* Chennai Central Railway Station -> 3

Now, considering these areas as Nodes, the programmer creates a “SafeMap”, a graph which portrays all the nodes and connects two nodes by a Directed edge if there is a route to go from one to another. A graphical Picture:


![Screenshot (568)](https://user-images.githubusercontent.com/60145175/116822944-40307780-ab9f-11eb-88d8-fb2ad341ee3d.png)


Here one CAN go from 0 to 2, and 2 to 0, but CANT go from 3 to 2 due to one-sided nature of the  route between 2 and 3. So while writing the code, one should take care of this “one-sided nature”. Now, the programmer decides to implement this in C++, but needs some help from you. The programmer has, however, managed to construct a frame of what needs to be done.


SafeMap :  Class implementation of the diagram shown above. The class SafeMap has a list of adjacent nodes as a member and total number of vertices in it. The function addSafeRoute adds a SafeRoute between 2 given edges. But, the game here is to construct isReachable(int s, int d) function, which returns length of shortest path between 's' and 'd' if  'd' is reachable from 's' otherwise returns -1. The path returned by function should be shortest path for example in the above figure if s=0 and d=2 then path length should be 1 and not 2. The programmer has constructed half of the function and needs your help to make the rest half :

Sample Test Graph

-  SafeMap g(4);
-  g.addSafeRoute(0, 1);
-  g.addSafeRoute(0, 2);
-  g.addSafeRoute(1, 2);
-  g.addSafeRoute(2, 0);
-  g.addSafeRoute(2, 3);


Sample Input       Sample Output
2 3                There is a Safe Path from 2 to 3 and path length is 1
3 2                There is no Safe Path from 3 to 2
0 2                There is a Safe Path from 0 to 2 and path length is 1

Program works for all sorts of graphs possible, not only the above graph.
