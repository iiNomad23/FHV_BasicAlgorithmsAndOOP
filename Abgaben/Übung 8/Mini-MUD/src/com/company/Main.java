package com.company;

import com.company.enums.ActionFunctions;
import com.company.enums.Directions;
import com.company.map.Map;
import com.company.map.field.*;
import com.company.map.items.Item;
import com.company.map.items.Key;

import java.util.Scanner;

public class Main {
    private static final Field[][] fields = new Field[10][10];

    public static void main(String[] args) {
        char[][] mapScheme = new char[][]{
                {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
                {'W', 'F', 'F', 'W', 'W', 'W', 'W', 'F', 'F', 'W'},
                {'W', 'I', 'F', 'W', 'I', 'F', 'W', 'F', 'F', 'W'},
                {'W', 'W', 'D', 'W', 'W', 'F', 'W', 'F', 'F', 'W'},
                {'W', 'F', 'F', 'F', 'W', 'F', 'W', 'F', 'F', 'W'},
                {'W', 'F', 'F', 'F', 'W', 'F', 'W', 'F', 'F', 'W'},
                {'W', 'F', 'F', 'F', 'W', 'F', 'W', 'F', 'F', 'W'},
                {'W', 'F', 'F', 'F', 'D', 'F', 'W', 'F', 'F', 'W'},
                {'W', 'I', 'F', 'F', 'W', 'F', 'D', 'F', 'F', 'W'},
                {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        };

        initFields(mapScheme);

        Map map = new Map(fields, "dust_2");

        Scanner sc = new Scanner(System.in);

        System.out.println("Welcome, please enter your name.");
        System.out.print("Name: ");

        String playerName = sc.nextLine();
        Player player = new Player(playerName, fields[1][1]);

        map.addPlayer(player);
        Player playerFromMap = map.getPlayer(player.getPlayerId());

        loop:
        while (true) {
            System.out.println("\nWhat do you want to do?");
            System.out.print("-> ");

            String line = sc.nextLine();
            String action = line.split(" ", 2)[0].replaceAll("\\s","");

            System.out.println();
            switch (action) {
                case "help":
                    System.out.println("Available commands:\ninspect\ntake\nmove\ninventory\nexit");
                    break;

                case "inspect":
                    java.util.Map<Directions, Field> neighborMap = playerFromMap.getPosition().getNeighbors();

                    for (java.util.Map.Entry<Directions, Field> entry : neighborMap.entrySet()) {
                        System.out.println(entry.getKey() + " - " + entry.getValue().getShortDescription());
                    }

                    break;

                case "take":
                    playerFromMap.execute(ActionFunctions.PICKUP);
                    break;

                case "move":
                    String[] splitArr = line.split(" ", 2);
                    if (splitArr.length > 1) {
                        String directionName = line.split(" ", 2)[1].replaceAll("\\s","");

                        switch (directionName) {
                            case "north":
                                playerFromMap.move(Directions.NORTH);
                                break;

                            case "east":
                                playerFromMap.move(Directions.EAST);
                                break;

                            case "south":
                                playerFromMap.move(Directions.SOUTH);
                                break;

                            case "west":
                                playerFromMap.move(Directions.WEST);
                                break;

                            default:
                                System.out.println(directionName + " is not a valid direction");
                        }
                    } else {
                        System.out.println("Please enter a valid direction.");
                    }

                    break;

                case "inventory":
                    for (Item item : playerFromMap.getInventory()) {
                        System.out.println(item.getShortDescription());
                    }
                    break;

                case "exit":
                    break loop;

                default:
                    System.out.println("Invalid command...\n");
                    System.out.println("Available commands:\ninspect\ntake\nmove\ninventory\nexit");
            }
        }
    }

    public static void initFields(char[][] mapScheme) {
        for (int i = 0; i < mapScheme[0].length; i++) {
            for (int j = 0; j < mapScheme.length; j++) {
                switch (mapScheme[j][i]) {
                    case 'W':
                        fields[j][i] = new Wall();
                        break;

                    case 'D':
                        fields[j][i] = new Door(10);
                        break;

                    case 'I':
                        fields[j][i] = new itemField(new Key(10));
                        break;

                    case 'F':
                    default:
                        fields[j][i] = new Floor();
                        break;
                }
            }
        }
    }
}
