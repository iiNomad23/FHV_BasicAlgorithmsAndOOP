package com.company;

/**
 * The class describes a Node with some methods and properties.
 *
 * @author Marco Prescher
 */

public class Node {
    private int value;
    private Node nextNode;

    public Node() {
        this(0);
    }

    public Node(int value) {
        this.value = value;
        this.nextNode = null;
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public Node getNextNode() {
        return nextNode;
    }

    public int getValue() {
        return value;
    }

    public void setNextNode(Node nextNode) {
        this.nextNode = nextNode;
    }

    public void setValue(int value) {
        this.value = value;
    }

    // functions -------------------------------------------------------------------------------------------------------------------
}
