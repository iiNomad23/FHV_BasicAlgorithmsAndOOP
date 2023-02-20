package com.company.enums;

/**
 * Describes the directions that a field can have.
 * Also it provides a function to reverse the direction.
 *
 * @author Prescher Marco
 */
public enum Directions {
    NORTH(0),
    EAST(1),
    SOUTH(2),
    WEST(3);

    private final int Value;

    Directions(int i) {
        Value = i;
    }

    public static Directions getReverse(Directions direction) {
        switch ((direction.getValue() + 2) % 4) {
            case 0:
                return NORTH;
            case 1:
                return EAST;
            case 2:
                return SOUTH;
            case 3:
                return WEST;
            default:
                throw new IllegalArgumentException();
        }
    }

    public int getValue() {
        return Value;
    }
}
