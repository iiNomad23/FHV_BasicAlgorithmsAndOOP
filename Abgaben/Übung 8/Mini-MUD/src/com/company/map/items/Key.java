package com.company.map.items;

/**
 * A basic Key with an key ID
 *
 * @author Prescher Marco
 */
public class Key extends Item {
    private static final String shortDesc = "Key";
    private static final String longDesc = "Rusty Key";

    private final int keyId;

    public Key(int keyId) {
        this(keyId, shortDesc, longDesc);
    }

    public Key(int keyId, String shortDesc, String longDesc) {
        super(shortDesc, longDesc);

        this.keyId = keyId;
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public int getKeyId() {
        return keyId;
    }
}
