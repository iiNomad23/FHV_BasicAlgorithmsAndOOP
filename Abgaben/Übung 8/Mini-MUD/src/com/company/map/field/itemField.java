package com.company.map.field;

import com.company.Player;
import com.company.enums.ActionFunctions;
import com.company.map.items.Item;

import java.util.LinkedList;
import java.util.List;

public class itemField extends Field implements IExecutable, IAccessible {
    private static final String successDesc = "You got ";
    private static final String emptyDesc = "There is nothing to pick up";
    private static final String failDesc = "You can't do this here.";

    private static final String defaultShortDesc = "ItemField";
    private static final String defaultLongDesc = "Legendary item, be careful";

    private final Item item;
    private final List<Player> playerEx;

    public itemField(Item item) {
        this(item, defaultShortDesc, defaultLongDesc);
    }

    public itemField(Item item, String shortDesc, String longDesc) {
        super(shortDesc, longDesc);

        this.item = item;
        this.playerEx = new LinkedList<>();
    }

    private void giveItemTo(Player player) {
        addToInventory(player);
        this.playerEx.add(player);
    }

    private void addToInventory(Player player) {
        if (player.addItem(this.item)) {
            System.out.println(successDesc + this.item.getLongDescription());
        } else {
            System.out.println("Failed to add item to inventory.");
        }
    }

    private boolean gotAlreadyItem(Player enterPlayer) {
        for (Player player : this.playerEx) {
            if (player == enterPlayer) {
                return true;
            }
        }

        return false;
    }

    @Override
    public void execute(Player player, ActionFunctions actionFunctions) {
        if (actionFunctions == ActionFunctions.PICKUP) {
            if (!gotAlreadyItem(player)) {
                giveItemTo(player);
            }
        }
    }

    @Override
    public Field enter(Player player) {
        return this;
    }
}
