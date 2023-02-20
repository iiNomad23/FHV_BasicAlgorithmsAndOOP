package com.company.map.items;

import com.company.Player;

/**
 * An apple with an Id to add multiple apples
 *
 * @author Prescher Marco
 */
public class Apple extends Item implements IConsumable {
    private static final String shortDesc = "Beer";
    private static final String longDesc = "Super duper beer";

    public Apple() {
        this(shortDesc, longDesc);
    }

    public Apple(String shortDesc, String longDesc) {
        super(shortDesc, longDesc);
    }

    @Override
    public void consumeBy(Player player) {
        player.removeItem(this.getId());
    }
}
