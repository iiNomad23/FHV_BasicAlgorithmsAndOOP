package com.company.map.field;

import com.company.Player;
import com.company.map.items.Item;
import com.company.map.items.Key;

import java.util.LinkedList;
import java.util.List;

public class Door extends Field implements IAccessible {
    private static final String defaultShortDesc = "Door";
    private static final String defaultLongDesc = "Door made of wood";

    private final int keyId;
    private final List<Player> playerEx;

    public Door(int keyId) {
        this(keyId, defaultShortDesc, defaultLongDesc);
    }

    public Door(int keyId, List<Player> players) {
        this(keyId, players, defaultShortDesc, defaultLongDesc);
    }

    public Door(int keyId, String shortDesc, String longDesc) {
        super(shortDesc, longDesc);

        this.keyId = keyId;
        this.playerEx = new LinkedList<>();
    }

    public Door(int keyId, List<Player> players, String shortDesc, String longDesc) {
        super(shortDesc, longDesc);

        this.keyId = keyId;
        this.playerEx = players;
    }

    // functions -------------------------------------------------------------------------------------------------------------------
    private void unlockDoor(Player player) {
        this.playerEx.add(player);
    }

    private boolean isUnlockedFor(Player player) {
        return this.playerEx.contains(player);
    }

    @Override
    public Field enter(Player player) {
        if (!isUnlockedFor(player)) {
            for (Item item : player.getAllItemsFromType(Key.class)) {
                if (this.keyId == ((Key) item).getKeyId()) {
                    unlockDoor(player);

                    return this;
                }
            }

            System.out.println("You need a key to open the door.");
            return player.getPosition();
        }

        return this;
    }
}
