package com.company;

/**
 * The class describes a Product with some attributes.
 *
 * @author Prescher Marco
 */
public class Product {
    private final int id;
    private final String name;
    private final double weight;

    public Product(int id, String name, double weight) {
        this.id = id;
        this.name = name;
        this.weight = weight;
    }

    public int getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public double getWeight() {
        return this.weight;
    }
}
