package com.company.map.items;

import com.company.Player;

/**
 * A beer with an Id to add multiple beers
 *
 * @author Prescher Marco
 */
public class Beer extends Item implements IConsumable {
    private static final String shortDesc = "Beer";
    private static final String longDesc = "Super duper beer";

    public Beer() {
        this(shortDesc, longDesc);
    }

    public Beer(String shortDesc, String longDesc) {
        super(shortDesc, longDesc);
    }

    @Override
    public void consumeBy(Player player) {
        player.removeItem(this.getId());
    }
}
