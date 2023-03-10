package heaps;

public class MinHeap {
    private int Heap[];
    int size;
    int maxSize;

    public MinHeap(int maxSize) {
        this.maxSize = maxSize;
        this.size = 0;
        Heap = new int[this.maxSize];
    }

    private int parent(int pos) {
        return (pos - 1) / 2;
    }

    private int leftChild(int pos) {
        return 2 * pos + 1;
    }

    private int rightChild(int pos) {
        return 2 * pos + 2;
    }

    private boolean isLeaf(int pos) {
        if (pos > size / 2 && pos <= size) {
            return true;
        }
        return false;
    }

    private void swap(int pos1, int pos2) {
        int temp = Heap[pos1];
        Heap[pos1] = Heap[pos2];
        Heap[pos2] = temp;
    }

    public void insert(int element) {
        Heap[size] = element;
        int curr = size;
        while (Heap[curr] < Heap[parent(curr)]) {
            swap(curr, parent(curr));
            curr = parent(curr);
        }

        size++;
    }

    public void minHeapify(int pos) {
        if (isLeaf(pos)) {
            return;
        }
        if (Heap[pos] > Heap[leftChild(pos)] || Heap[pos] > Heap[rightChild(pos)]) {
            if (Heap[leftChild(pos)] < Heap[rightChild(pos)]) {
                swap(Heap[pos], Heap[leftChild(pos)]);
                minHeapify(leftChild(pos));
            } else {
                swap(Heap[pos], Heap[rightChild(pos)]);
                minHeapify(rightChild(pos));
            }
        }
    }

    public void display() {
        for (int i = 0; i < size; i++) {
            System.out.println(Heap[i] + " ");
        }
    }

    public int extractMin() {
        int popped = Heap[0];
        Heap[0] = Heap[--size];
        minHeapify(0);
        return popped;
    }

    public static void main(String[] args) {
        int n = 9;
        MinHeap obj = new MinHeap(n);
        obj.insert(5);
        obj.insert(6);
        obj.insert(7);
        obj.insert(8);
        obj.insert(1);
        obj.insert(2);
        obj.insert(3);
        obj.insert(4);

        obj.display();
        // System.out.println(obj.extractMin());

    }

}

// max heap



package heaps;
import java.util.Scanner;
// Java program to implement Max Heap

// Main class
public class MaxHeap {
	private int[] Heap;
	private int size;
	private int maxsize;

	// Constructor to initialize an
	// empty max heap with given maximum
	// capacity
	public MaxHeap(int maxsize)
	{
		// This keyword refers to current instance itself
		this.maxsize = maxsize;
		this.size = 0;
		Heap = new int[this.maxsize];
	}

	// Method 1
	// Returning position of parent
	private int parent(int pos) { return (pos - 1) / 2; }

	// Method 2
	// Returning left children
	private int leftChild(int pos) { return (2 * pos) + 1; }

	// Method 3
	// Returning right children
	private int rightChild(int pos)
	{
		return (2 * pos) + 2;
	}

	// Method 4
	// Returning true of given node is leaf
	private boolean isLeaf(int pos)
	{
		
		if (pos > (size / 2) && pos <= size) {
			return true;
		}
		return false;
	}

	// Method 5
	// Swapping nodes
	private void swap(int fpos, int spos)
	{
		int tmp;
		tmp = Heap[fpos];
		Heap[fpos] = Heap[spos];
		Heap[spos] = tmp;
	}

	// Method 6
	// Recursive function to max heapify given subtree
	private void maxHeapify(int pos)
	{
		if (isLeaf(pos))
			return;

		if (Heap[pos] < Heap[leftChild(pos)]
			|| Heap[pos] < Heap[rightChild(pos)]) {

			if (Heap[leftChild(pos)]
				> Heap[rightChild(pos)]) {
				swap(pos, leftChild(pos));
				maxHeapify(leftChild(pos));
			}
			else {
				swap(pos, rightChild(pos));
				maxHeapify(rightChild(pos));
			}
		}
	}

	// Method 7
	// Inserts a new element to max heap
	public void insert(int element)
	{
		Heap[size] = element;

		// Traverse up and fix violated property
		int current = size;
		while (Heap[current] > Heap[parent(current)]) {
			swap(current, parent(current));
			current = parent(current);
		}
		size++;
	}

	// Method 8
	// To display heap
	public  void print(MaxHeap maxHeap)
	{

		         for(int i=0;i<size;i++)
		         {
		            System.out.println(Heap[i]+" ")  ;       	 
		}
	}

	// Method 9
	// Remove an element from max heap
	public int extractMax()
	{
		int popped = Heap[0];
		Heap[0] = Heap[--size];
		maxHeapify(0);
		return popped;
	}

	// Method 10
	// main dri er method
	public static void main(String[] arg)
	{
		// Display message for better readability
		System.out.println("The Max Heap is ");
int n=9;
		MaxHeap maxHeap = new MaxHeap(n);

		// Inserting nodes
		// Custom inputs
//		int num[]=new int[n];
//		Scanner sc=new Scanner(System.in);
//		for(int i=0;i<n;i++)
//		{
//			System.out.println("Enter a Number");
//			num[i]=sc.nextInt();
//		}
//		for(int i=0;i<n;i++)
//		{
//			maxHeap.insert(num[i]);
//		}
		
		
		
		maxHeap.insert(5);
		maxHeap.insert(3);
		maxHeap.insert(17);
		maxHeap.insert(10);
		maxHeap.insert(84);
		maxHeap.insert(19);
		maxHeap.insert(6);
		maxHeap.insert(22);
		maxHeap.insert(9);

		// Calling maxHeap() as defined above
		maxHeap.print(maxHeap);

		// Print and display the maximum value in heap
		for(int i=0;i<n;i++)
		System.out.println("The max val is "
						+ maxHeap.extractMax());
		
	}
}