package com.company.map.field;

import com.company.Player;

public class Floor extends Field implements IAccessible {
    private static final String defaultShortDesc = "Floor";
    private static final String defaultLongDesc = "Floor made of wood";

    public Floor() {
        this(defaultShortDesc, defaultLongDesc);
    }

    public Floor(String shortDesc, String longDesc) {
        super(shortDesc, longDesc);
    }

    @Override
    public Field enter(Player player) {
        return this;
    }
}
