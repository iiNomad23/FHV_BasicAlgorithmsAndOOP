package com.company.map.field;

import com.company.enums.Directions;

import java.util.Collections;
import java.util.EnumMap;
import java.util.Map;

public class Field {
    private static int nextId;

    private final int fieldId;
    private final String shortDesc;
    private final String longDesc;
    private final Map<Directions, Field> neighbors;

    public Field() {
        this("N/A", "N/A");
    }
    public Field(String shortDesc, String longDesc) {
        this.fieldId = nextId++;
        this.shortDesc = shortDesc;
        this.longDesc = longDesc;
        this.neighbors = new EnumMap<Directions, Field>(Directions.class);
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public int getFieldId() {
        return this.fieldId;
    }

    public String getShortDescription() {
        return this.shortDesc;
    }

    public String getLongDescription() {
        return this.longDesc;
    }

    public Map<Directions, Field> getNeighbors() {
        return neighbors;
    }

    // functions -------------------------------------------------------------------------------------------------------------------
    public void addNeighbor(Directions dir, Field field) {
        this.neighbors.put(dir, field);
        field.neighbors.put(Directions.getReverse(dir), this);
    }

    public Map<Directions, IAccessible> getPossibleWalkDirections() {
        Map<Directions, IAccessible> tempMap = new EnumMap<>(Directions.class);
        this.neighbors.forEach(((directions, field) -> {
            if (field instanceof IAccessible) {
                tempMap.put(directions, (IAccessible) field);
            }
        }));

        return Collections.unmodifiableMap(tempMap);
    }

    public Map<Directions, Field> getAllDirections() {
        return Collections.unmodifiableMap(this.neighbors);
    }
}
