public class SLLSet {
    private int size;
    private SLLNode head;

    public SLLSet() {
        size = 0;
        head = null;
    }

    public SLLSet(int[] sortedArray) {
        if (sortedArray == null || sortedArray.length == 0) {
            size = 0;
            head = null;
        }
        else {
            size = sortedArray.length;
            head = new SLLNode(sortedArray[0], null);
            SLLNode current = head;
            for (int i = 1; i < size; i++) {
                current.next = new SLLNode(sortedArray[i], null);
                current = current.next;
            }
        }
    }

    public int getSize() {
        return size;
    }

    public SLLSet copy() {
        if (size == 0) {
            return new SLLSet(); // returns empty copy if set is empty
        }
        SLLSet deepCopy = new SLLSet(); // creates new SLLSet to copy values over to
        deepCopy.size = size;
        deepCopy.head = new SLLNode(head.value, null);
        SLLNode current = head;
        SLLNode deepCopyCurrent = deepCopy.head;
        for (int i = 0; i < size - 1; i++) {
            current = current.next;
            deepCopyCurrent.next = new SLLNode(current.value, null); // copies value from original set to copied set
            deepCopyCurrent = deepCopyCurrent.next;
        }
        return deepCopy;
    }

    public boolean isIn(int v) {
        SLLNode current = head;
        while (current != null) {
            if (current.value == v) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public void add(int v) {
        if (size == 0) { // if empty set, create new set with just v
            head = new SLLNode(v, null);
            size++;
        }
        else {
            SLLNode current = head;
            SLLNode nextNode = null; // to store node after the added element
            if (head.value > v) { // makes v head if less than head value
                nextNode = head;
                head = new SLLNode(v, nextNode);
                size++;
            }
            else {
                while (current.next != null) {
                    if (v == current.next.value) {
                        return; // ends method if v already exists in set
                    }
                    else if (v < current.next.value) {
                        nextNode = current.next; // stores element after v
                        current.next = new SLLNode(v, nextNode); // adds v with next being the stored element
                        size++;
                        return; // ends method after adding v to set
                    }
                    current = current.next;
                }
                current.next = new SLLNode(v, null);
                size++;
            }
        }
    }

    public void remove(int v) {
        if (head == null) {
            return; // ends if set is empty
        }
        if (head.value == v) { // if removed node is head, sets head value to head.next
            head = head.next;
            size--;
        }
        else {
            SLLNode current = head;
            while (current.next != null) {
                if (v == current.next.value) {
                    if (current.next.next == null) { // if node after next is null (next is last node), sets next to null
                        current.next = null;
                        size--;
                        return;
                    }
                    else { // otherwise next node becomes node after
                        current.next = current.next.next;
                        size--;
                        return;
                    }
                }
                current = current.next;
            }
        }

    }

    public SLLSet union(SLLSet s) {
        if (head == null) { // returns copy of s if this set is empty
            return s.copy();
        }
        if (s.head == null) { // returns copy of this set if is empty
            return copy();
        }
        SLLSet unionSet = new SLLSet();
        SLLNode current1 = head;
        SLLNode current2 = s.head;

        // sets head for the union set
        if (current1.value > current2.value) {
            unionSet.head = new SLLNode(current2.value, null);
            current2 = current2.next;
            unionSet.size++;
        }
        else if (current1.value < current2.value) {
            unionSet.head = new SLLNode(current1.value, null);
            current1 = current1.next;
            unionSet.size++;
        }
        else {
            unionSet.head = new SLLNode(current1.value, null);
            current1 = current1.next;
            current2 = current2.next;
            unionSet.size++;
        }

        SLLNode currentUnion = unionSet.head; // sets current for union set to the newly assigned head

        // iterates through both lists while both are not null
        while (current1 != null && current2 != null) { // still ends when one list ends because it cannot compare value to a null object
            if (current1.value == current2.value) { // checks if values are same, adds current value if same and moves both sets to next
                currentUnion.next = new SLLNode(current1.value, null);
                currentUnion = currentUnion.next;
                current1 = current1.next;
                current2 = current2.next;
                unionSet.size++;
            }
            else if (current1.value < current2.value) { // checks if value of current1 is less, adds value of current1 if less and moves current1 to next
                currentUnion.next = new SLLNode(current1.value, null);
                currentUnion = currentUnion.next;
                current1 = current1.next;
                unionSet.size++;
            }
            else { // checks if value of current2 is less, adds value of current2 if less and moves current1 to next
                currentUnion.next = new SLLNode(current2.value, null);
                currentUnion = currentUnion.next;
                current2 = current2.next;
                unionSet.size++;
            }
        }

        // iterates remaining list
        while (current1 != null) {
            currentUnion.next = new SLLNode(current1.value, null);
            currentUnion = currentUnion.next;
            current1 = current1.next;
            unionSet.size++;
        }

        while (current2 != null) {
            currentUnion.next = new SLLNode(current2.value, null);
            currentUnion = currentUnion.next;
            current2 = current2.next;
            unionSet.size++;
        }

        return unionSet;
    }

    public SLLSet intersection(SLLSet s) {
        SLLSet intersect = new SLLSet();
        SLLNode currentIntersect = null;
        SLLNode current1 = head;
        SLLNode current2 = s.head;

        while (current1 != null && current2 != null) { // iterates through list if both are not else (if both are null it'll just go return statement and return empty set)
            if (current1.value == current2.value) { // if same value, adds to list if it is
                if (intersect.head == null) { // if head for intersect does not exist, creates head with current value
                    intersect.head = new SLLNode(current1.value, null);
                    currentIntersect = intersect.head;
                }
                else { // if head does exist, adds new node with current value
                    currentIntersect.next = new SLLNode(current1.value, null);
                    currentIntersect = currentIntersect.next;
                }
                current1 = current1.next;
                current2 = current2.next;
                intersect.size++;
            }
            else if (current1.value < current2.value) { // moves current1 to next if it is less than current2 (intersection only occurs if values are same)
                current1 = current1.next;
            }
            else { // moves current2 to next if it is less than current1
                current2 = current2.next;
            }
        }

        return intersect;
    }

    public SLLSet difference(SLLSet s) {
        SLLSet diffSet = copy();
        SLLNode current = s.head;

        while (current != null) {
            diffSet.remove(current.value); // removes values from s that appear in copy of this set
            current = current.next;
        }

        return diffSet;
    }

    public static SLLSet union(SLLSet[] sArray) {
        SLLSet unionSet = new SLLSet();

        for (SLLSet set : sArray) {
            unionSet = unionSet.union(set);
        }

        return unionSet;
    }

    public String toString() {
        String output = new String();
        SLLNode current = head;
        if (size == 0) {
            return output;
        }
        while (current.next != null) {
            output += current.value + ", ";
            current = current.next;
        }
        output += current.value;
        return output;
    }
}