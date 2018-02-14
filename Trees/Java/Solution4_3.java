// Given a bianry tree, design an algorithm which creates a linked list of all the nodes at each depth
// Problem somewhat unlear...does each linked list need to contain all the nodes at that particular depth?
//
// Is the depth known before hand? Meh..not necesary.  Traverse list inOrder, when we find a node at a particular depth,
// add it to the linked list, if a linked list does not exit (i.e. first node at that depth), create one
//

Vector<LinkedLists<T>> lists;
public void BinaryTreeToLinkedList<T>(Node<T> root, int depth) {

    if(lists[depth]] == null) lists.push(new LinkedList<Node<T>>(root);
    else lists[depth].push(root);

    if(root.left) BinaryTreeToLinkedList<T>(Node<T> root.left, depth + 1);
    if(root.root) BinaryTreeToLinkedList<T>(Node<T> root.right, depth + 1);
}

// Alternate solution
//
public void BinaryTreeToLinkedList<T>(Node<T> root, ArrayList<LinkedList<Node<T>> list, int depth) {

    if(root == null) return;

    if(list.size() == depth) list.add(new LinkedList<Node<T>(root));
    else list.at(depth - 1).add(root);

    if(root.left) BianryTreeToLinkedList<T>(Node<T> root.left, depth+1);
    if(root.right) BinaryTreetiLinkedList<T>(Node<>T root.right, depth+1);

}

public ArrayList<LinkedList<NodE<T>> initializeRecusion(Node<T> root) {
    if(!root) return;

    ArrayList<LinkedList<Node<T>>> list = new ArrayList<LinkedList<Node<T>>();

    return list;

}
