package com.company;

import com.company.enums.ActionFunctions;
import com.company.enums.Directions;
import com.company.map.field.Field;
import com.company.map.field.IAccessible;
import com.company.map.field.IExecutable;
import com.company.map.items.IConsumable;
import com.company.map.items.Item;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class Player {
    private static int nextId;

    private final int playerId;
    private final String name;
    private Field position;
    private final List<Item> inventory;

    public Player(String name, Field position) {
        this(name, position, new LinkedList<>());
    }

    public Player(String name, Field position, List<Item> items) {
        this.playerId = nextId++;
        this.name = name;
        this.inventory = items;
        this.position = position;
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public int getPlayerId() {
        return playerId;
    }

    public String getName() {
        return name;
    }

    public Field getPosition() {
        return this.position;
    }

    public List<Item> getInventory() {
        return inventory;
    }

    // functions -------------------------------------------------------------------------------------------------------------------
    public List<Item> getAllItemsFromType(Class type) {
        List<Item> returnList = new LinkedList<>();

        for (Item item : inventory) {
            if (type.isInstance(item)) {
                returnList.add(item);
            }
        }

        return Collections.unmodifiableList(returnList);
    }

    public boolean addItem(Item item) {
        if (!this.itemExist(item.getId())) {
            this.inventory.add(item);

            return true;
        }

        return false;
    }

    public void removeItem(int id) {
        if (this.itemExist(id)) {
            int itemIndex = -1;
            for (int i = 0; i < this.inventory.size(); i++) {
                if (this.inventory.get(i).getId() == id) {
                    itemIndex = i;
                }
            }

            if (itemIndex >= 0) {
                this.inventory.remove(itemIndex);
            } else {
                System.out.println("No item removed.");
            }
        }
    }

    public boolean itemExist(int id) {
        for (Item invItem : this.inventory) {
            if (invItem.getId() == id) {
                return true;
            }
        }

        return false;
    }

    public void move(Directions direction) {
        Map<Directions, IAccessible> possibleWalkDirections = this.position.getPossibleWalkDirections();

        if (possibleWalkDirections.containsKey(direction)) {
            this.position = possibleWalkDirections.get(direction).enter(this);

            System.out.println("Your moved to a " + this.position.getShortDescription() + " - pos nr: " + this.position.getFieldId() + "\n");

            System.out.println("Your neighbors are: ");
            Map<Directions, Field> map = this.position.getNeighbors();

            for (Map.Entry<Directions, Field> entry : map.entrySet()) {
                System.out.println(entry.getKey() + " - " + entry.getValue().getShortDescription());
            }
        } else {
            System.out.println("You walked into a wall.");
        }
    }

    public void consume(Item item) {
        if (item instanceof IConsumable) {
            ((IConsumable) item).consumeBy(this);
        } else {
            System.out.println("Nothing to consume");
        }
    }

    public void execute(ActionFunctions actionFunctions) {
        if (this.position instanceof IExecutable) {
            ((IExecutable) this.position).execute(this, actionFunctions);
        } else {
            System.out.println("Nothing to execute.");
        }
    }
}
