// Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search
// tree with minimal height.
//
// Let A be an array with n elements, since a binary tree with height h can have at most 2^h - 1 elements, we simply
// need to find an x such that n <= 2^x - 1 or x = log_2(n+1). Further, since the array is in increasing order, we know
// EXACTLY what positions each element A[0], A[1], ..., A[n-1] will be in (may be a little difficult to calculate)
// Concrete Example
//
// A = 1 2 3 4 5 7 
// A = 1 2 3 4 5 6 7
// Root = 1 (half go to the left) (half go to the right)
// Left Half: 2 3 4 Right Half: 5 6 7
// Left Root = 2 Right Root = 5
// ...
// Repeat.
// If |A| != 2^x - 1 for some x, just have to be careful with indexing
//
//


// Given an array A = [a0, a1, a2, ...,  an], returns the root of a binary tree such that A = [a0 | a1, a2, ..., a(n/2)
// | a(n/2 + 1), ..., a(n-1)]
//
// Check: If n is even, that is n = 2k
// A' = [a0, a1, a2, ..., a(k-1) | ak, ... a(n-1)] 
// A' = [a0, a1, a2, a3, a4] -> [a0 | a1 a2 | a3 a4] -> [a1 a2] 
// If n is odd
// A' = [a0, a1, a2, a3, a4, a5] -> [a0 | a1 a2 a3 | a4 a5]..checking..
//
//
// Oops root is not first term....want to split down the middle.
// A = [a0 a1 a2 a3 a4 a5 a6] -> [a0 a1 a2 | a3 | a4 a5 a6]
// A = [a0 a1 a2 a3 a4 a5 a6 a7] -> [a0 a1 a2 a3 | a4 | a5 a6 a7] (If always break ties to left)...
//              a4 
//        a2  a3  a5
//      a0  a1   a6
public static Node<T> GenerateBinaryTree<T>(T[] sortedArray) {

    if(sortedArray.length == 0) return null;
    if(sortedArray.length == 1) return new Node<T>(sortedArray[0]);

    Node<T> rootNode = new Node<T>(sortedArray[sortedArray.length / 2);

    rootNode.leftNode = GenerateBinaryTree(Arrays.copyOfRange(sortedArray, 0, sortedArray.length / 2 - 1));
    if(sortedArray.length/2 + 1 <= sortedArray.length)
    rootNode.rightNode = GenerateBinaryTree(Arrays.copyOfRange(sortedArray, sortedArray.length / 2 + 1, sortedArray.length - 1));

    return root;

}

