package com.company.map.items;

/**
 * The class describes a Product with some attributes.
 *
 * @author Prescher Marco
 */
public class Item {
    private static int nextId;

    private final int itemId;
    private final String shortDesc;
    private final String longDesc;

    public Item(String shortDesc, String longDesc) {
        this.itemId = nextId++;
        this.shortDesc = shortDesc;
        this.longDesc = longDesc;
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public int getId() {
        return this.itemId;
    }

    public String getShortDescription() {
        return this.shortDesc;
    }

    public String getLongDescription() {
        return this.longDesc;
    }
}
