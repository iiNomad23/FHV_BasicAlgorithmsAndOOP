package com.company.map.field;

public class Wall extends Field {
    private static final String defaultShortDesc = "Wall";
    private static final String defaultLongDesc = "Wall made of Wood";

    public Wall() {
        this(defaultShortDesc, defaultLongDesc);
    }

    public Wall(String shortDesc, String longDesc) {
        super(shortDesc, longDesc);
    }
}
