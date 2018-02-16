// Given a directed, design an algorithm find out whether there is a route between two nodes
//
// Let a and b be two nodes in a graph, perform a bidirectional search on a and b until,
//  1) Span(a) intersects Span(b) is non-empty, return true
//  2) No new nodes to explore for either Span(a) or Span(b), return false

import java.util.Vector;
import java.util.Stack;

class Node {
    public int element;
    public Node[] children;
}

public class Solution4_1 {
    
    public static void main(String[] args) {}
    
    public static boolean isConnected(Node a,  Node b) {


        // A node n is in Span(X) if and only if there exists a path from X to n; thus, Nodes a and b are connected if and
        // only if a is in the span of B or b is in the span of A
        Vector<Node> SpanA = new Vector<Node>();
        Vector<Node> SpanB = new Vector<Node>();

        // List of nodes incident to an edge of an already visited node (once both of these are empty, no path exists
        // between a and b thus we must return false). A stack ensures we perform DFS
        Stack<Node> CandidateA = new Stack<Node>();
        CandidateA.push(a);
        Stack<Node> CandidateB = new Stack<Node>();
        CandidateB.push(b);
        
        // While there still remains nodes to explore in both trace(A) and trace(B)
        while(!CandidateA.isEmpty() && !CandidateB.isEmpty()) {

            // Visit the next node in the list
            Node tempA = null;
            Node tempB = null;

            if(!CandidateA.isEmpty()) tempA = CandidateA.pop();
            if(!CandidateB.isEmpty()) tempB = CandidateB.pop();

            // If the visited node exists in the other's span, then a is connected to b
            if(SpanA.contains(tempB) || SpanB.contains(tempA)) return true;
            else {

                // Otherwise, add all the neighbors of the visited nodes to the list of Candidate nodes (Assuming we haven't
                // visited it)
                if(tempA != null)
                for(Node n: tempA.children)
                    if(!SpanA.contains(n)) CandidateA.push(n);

                if(tempB != null)
                for(Node n : tempB.children)
                    if(!SpanB.contains(n)) CandidateB.push(n);
            }

        }

        return false;
    }
}
