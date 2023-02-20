package com.company;

public class Main {

    public static void main(String[] args) {
	    SingleLinkedList firstList = new SingleLinkedList();

        firstList.insert(50);
        firstList.insert(40);
	    firstList.insert(30);
	    firstList.insert(20);
	    firstList.insert(10);

	    // insert and delete test
        System.out.println("\nL1-Test - delete:");
        firstList.printList();
        firstList.delete(10);
        System.out.println("L1-Test - Insert after delete:");
        firstList.printList();
        firstList.insert(10);

        System.out.println("\nL1:");
        firstList.printList();


        SingleLinkedList secondList = new SingleLinkedList();

        secondList.insert(70);
        secondList.insert(60);
        secondList.insert(40);
        secondList.insert(30);

        System.out.println("L2:");
        secondList.printList();

        System.out.println("\nMerge L1 and L2...\n");
        SingleLinkedList mergedList = Merger.mergeSortedLists(firstList, secondList);

        System.out.println("L1:");
        firstList.printList();
        System.out.println("L2:");
        secondList.printList();

        System.out.println("Merged List:");
        mergedList.printList();
    }
}
