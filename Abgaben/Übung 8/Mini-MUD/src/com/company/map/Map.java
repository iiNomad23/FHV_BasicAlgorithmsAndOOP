package com.company.map;

import com.company.Player;
import com.company.enums.Directions;
import com.company.map.field.Field;

import java.util.LinkedList;
import java.util.List;

public class Map {
    private final String name;
    private final Field[][] fields;
    private final List<Player> players;

    public Map(Field[][] fields, String name) {
        this.fields = fields;
        this.name = name;
        this.players = new LinkedList<>();

        initNeighbors();
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public String getName() {
        return name;
    }

    public Field[][] getFields() {
        return fields;
    }

    public List<Player> getPlayers() {
        return players;
    }

    // functions -------------------------------------------------------------------------------------------------------------------
    private void initNeighbors() {
        for (int i = 0; i < this.fields[0].length; i++) {
            for (int j = 0; j < this.fields.length; j++) {
                try {
                    fields[j][i].addNeighbor(Directions.EAST, fields[j][i + 1]);
                    fields[j][i].addNeighbor(Directions.SOUTH, fields[j + 1][i]);
                } catch (Exception e) {
                    // do nothing -- not a big deal
                }
            }
        }
    }

    public Player getPlayer(int id) {
        for (Player player : this.players) {
            if (player.getPlayerId() == id) {
                return player;
            }
        }

        return null;
    }

    public void addPlayer(String name, Field position) {
        this.players.add(new Player(name, position));
    }

    public void addPlayer(Player player) {
        this.players.add(player);
    }

    public void removePlayer(int id) {
        if (this.playerExist(id)) {
            int playerIndex = -1;
            for (int i = 0; i < this.players.size(); i++) {
                if (this.players.get(i).getPlayerId() == id) {
                    playerIndex = i;
                }
            }

            if (playerIndex >= 0) {
                this.players.remove(playerIndex);
            } else {
                System.out.println("No player removed.");
            }
        }
    }

    public boolean playerExist(int id) {
        for (Player player : this.players) {
            if (player.getPlayerId() == id) {
                return true;
            }
        }

        return false;
    }
}