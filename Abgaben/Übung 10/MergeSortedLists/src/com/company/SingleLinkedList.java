package com.company;

/**
 * The class describes a SingleLinkedList with some methods and properties.
 *
 * @author Marco Prescher
 */

public class SingleLinkedList {
    private Node root;

    public SingleLinkedList() {
        this.root = null;
    }

    public SingleLinkedList(Node root) {
        this.root = this.createNode(root.getValue());
        root = root.getNextNode();

        Node nextNode = this.root;
        while (root != null) {
            nextNode.setNextNode(this.createNode(root.getValue()));

            nextNode = nextNode.getNextNode();
            root = root.getNextNode();
        }
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public Node getRoot() {
        return root;
    }

    // functions -------------------------------------------------------------------------------------------------------------------
    public void insert(int value) {
        this.insert(this.createNode(value));
    }

    public void insert(Node newNode) {
        if (this.root == null) {
            this.root = newNode;
        } else {
            Node tempNode = this.root;
            this.root = newNode;
            this.root.setNextNode(tempNode);
        }
    }

    public void insertLast(int value) {
        this.insertLast(this.createNode(value));
    }

    public void insertLast(Node newNode) {
        if (this.root == null) {
            this.root = newNode;
        } else {
            Node lastNode = this.root;

            while (lastNode.getNextNode() != null) {
                lastNode = lastNode.getNextNode();
            }

            lastNode.setNextNode(newNode);
        }
    }

    public Node delete(int value) {
        Node nodeToDelete = this.root;
        Node prevNode = null;

        while (nodeToDelete != null && value != nodeToDelete.getValue()) {
            prevNode = nodeToDelete;
            nodeToDelete = nodeToDelete.getNextNode();
        }

        if (nodeToDelete != null) {
            Node nextNode = nodeToDelete.getNextNode();

            if (prevNode != null) {
                prevNode.setNextNode(nextNode);
            } else {
                this.root = nextNode;
            }

            nodeToDelete.setNextNode(null);
        }

        return nodeToDelete;
    }

    private Node createNode(int value) {
        return new Node(value);
    }

    public void printList() {
        Node currNode = this.root;

        while (currNode != null) {
            System.out.print(currNode.getValue() + " ");
            currNode = currNode.getNextNode();
        }

        System.out.println();
    }
}
