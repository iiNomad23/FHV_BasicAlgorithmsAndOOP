package com.company;

/**
 * The class describes a Merger with some methods to merge e.g. lists.
 *
 * @author Marco Prescher
 */

public class Merger {
    public static SingleLinkedList mergeSortedLists(SingleLinkedList firstList, SingleLinkedList secondList) {
        SingleLinkedList mergedList = new SingleLinkedList();

        if (firstList != null && secondList != null) {
            // copy lists because the merge should not change the original
            firstList = new SingleLinkedList(firstList.getRoot());
            secondList = new SingleLinkedList(secondList.getRoot());

            Node currFirstListNode = firstList.getRoot();
            Node currSecondListNode = secondList.getRoot();

            // second Method comments would just make a new node.
            // If we use it this way we would not need to copy the lists above.
            while(currFirstListNode != null && currSecondListNode != null) {
                int firstVal = currFirstListNode.getValue();
                int secondVal = currSecondListNode.getValue();

                Node firstNextNode = currFirstListNode.getNextNode();
                Node secondNextNode = currSecondListNode.getNextNode();

                if (firstVal < secondVal) {
                    currFirstListNode = firstNextNode;

                    mergedList.insertLast(firstList.delete(firstVal));
                    // second Method - mergedList.insertLast(new Node(firstVal));
                } else if (secondVal < firstVal) {
                    currSecondListNode = secondNextNode;

                    mergedList.insertLast(secondList.delete(secondVal));
                    // second Method - mergedList.insertLast(new Node(secondVal));
                } else {
                    currFirstListNode = firstNextNode;
                    currSecondListNode = secondNextNode;

                    mergedList.insertLast(firstList.delete(firstVal));
                    mergedList.insertLast(secondList.delete(secondVal));

                    // second Method - mergedList.insertLast(new Node(firstVal));
                    // second Method - mergedList.insertLast(new Node(secondVal));
                }
            }

            while (currFirstListNode != null) {
                int val = currFirstListNode.getValue();

                currFirstListNode = currFirstListNode.getNextNode();

                mergedList.insertLast(firstList.delete(val));
                // second Method - mergedList.insertLast(new Node(val));
            }

            while (currSecondListNode != null) {
                int val = currSecondListNode.getValue();

                currSecondListNode =  currSecondListNode.getNextNode();

                mergedList.insertLast(secondList.delete(val));
                // second Method - mergedList.insertLast(new Node(val));
            }
        }

        return mergedList;
    }
}