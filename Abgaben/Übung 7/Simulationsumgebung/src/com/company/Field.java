package com.company;

import com.company.enums.FieldType;

/**
 * The class describes a field in a grid with certain properties.
 *
 * @author Prescher Marco
 */
public class Field {
    private static int width;
    private static int length;
    private FieldType type;

    public Field() {
        this(FieldType.EMPTY);
    }

    public Field(FieldType type) {
        this.type = type;
    }

    public static int getWidth() {
        return Field.width;
    }

    public static int getLength() {
        return Field.length;
    }

    public FieldType getType() {
        return this.type;
    }

    public void setType(FieldType type) {
        this.type = type;
    }

    public static void setDimensions(int width, int length) {
        Field.width = width;
        Field.length = length;
    }
}
