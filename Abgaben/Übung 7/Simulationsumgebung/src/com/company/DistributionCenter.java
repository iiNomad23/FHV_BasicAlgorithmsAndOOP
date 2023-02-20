package com.company;

import com.company.enums.FieldType;

/**
 * The class describes a field in a grid with certain properties.
 *
 * @author Prescher Marco
 */
public class DistributionCenter {
    private final Field[][] fieldGrid;

    public DistributionCenter(int gridWidth, int gridLength, int fieldWidth, int fieldLength) {
        if (gridLength <= 0 || gridWidth <= 0 || fieldWidth <= 0 || fieldLength <= 0) {
            throw new IllegalArgumentException("Wrong Input");
        }

        this.fieldGrid = new Field[gridWidth][gridLength];
        Field.setDimensions(fieldWidth, fieldLength);

        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridLength; j++) {
                fieldGrid[i][j] = new Field();
            }
        }
    }

    public void setTypeToField(int fieldX, int fieldY, FieldType type) {
        fieldGrid[fieldX][fieldY].setType(type);
    }

    public FieldType getFieldType(int posX, int posY) {
        return fieldGrid[posX][posY].getType();
    }
}
